/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrResource_DEFINED
#define GrResource_DEFINED

#include "SkRefCnt.h"
#include "SkTInternalLList.h"

class GrGpu;
class GrContext;
class GrResourceEntry;

/**
 * Base class for the GPU resources created by a GrContext.
 */
class GrResource : public SkRefCnt
{
public:
    SK_DECLARE_INST_COUNT(GrResource)
    void release();
	void abandon();
	bool isValid() const { return NULL != fGpu; }
    virtual size_t sizeInBytes() const = 0;
    const GrContext* getContext() const;
    GrContext* getContext();

    void setCacheEntry(GrResourceEntry* cacheEntry) { fCacheEntry = cacheEntry; }
    GrResourceEntry* getCacheEntry() { return fCacheEntry; }

    void incDeferredRefCount() const 
	{
        ++fDeferredRefCount;
    }

    void decDeferredRefCount() const 
	{
        --fDeferredRefCount;
        if (0 == fDeferredRefCount && this->needsDeferredUnref()) {
            this->unref();
        }
    }

    int getDeferredRefCount() const { return fDeferredRefCount; }

    void setNeedsDeferredUnref() { fFlags |= kDeferredUnref_FlagBit; }

protected:
    GrResource(GrGpu* gpu, bool isWrapped);
    virtual ~GrResource();
    GrGpu* getGpu() const { return fGpu; }

    // Derived classes should always call their parent class' onRelease
    // and onAbandon methods in their overrides.
    virtual void onRelease() {};
    virtual void onAbandon() {};

    bool isInCache() const { return NULL != fCacheEntry; }
    bool isWrapped() const { return kWrapped_FlagBit & fFlags; }
    bool needsDeferredUnref() const { return SkToBool(kDeferredUnref_FlagBit & fFlags); }

private:
#ifdef SK_DEBUG
    friend class GrGpu; // for assert in GrGpu to access getGpu
#endif

    // We're in an internal doubly linked list
    SK_DECLARE_INTERNAL_LLIST_INTERFACE(GrResource);

    GrGpu*              fGpu;               // not reffed. The GrGpu can be deleted while there
                                            // are still live GrResources. It will call
                                            // release() on all such resources in its
                                            // destructor.
    GrResourceEntry*    fCacheEntry;        // NULL if not in cache
    mutable int         fDeferredRefCount;  // How many references in deferred drawing buffers.

    enum Flags
	{
		kWrapped_FlagBit         = 0x1,
        kDeferredUnref_FlagBit  = 0x2,
    };
	uint32_t         fFlags;
    typedef SkRefCnt INHERITED;

};

#endif
