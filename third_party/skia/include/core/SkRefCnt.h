
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkRefCnt_DEFINED
#define SkRefCnt_DEFINED

#include "SkThread.h"
#include "SkInstCnt.h"
#include "SkTemplates.h"


class SK_API SkRefCnt : public SkNoncopyable 
{
public:
    SK_DECLARE_INST_COUNT_ROOT(SkRefCntBase)

    SkRefCnt() : fRefCnt(1) {}
    virtual ~SkRefCnt() {
#ifdef SK_DEBUG
        fRefCnt = 0;    // illegal value, to catch us if we reuse after delete
#endif
    }
    int32_t getRefCnt() const { return fRefCnt; }

    bool unique() const {
        bool const unique = (1 == fRefCnt);
        if (unique) {
        }
        return unique;
    }

    void ref() const {
        sk_atomic_inc(&fRefCnt);  // No barrier required.
    }

    void unref() const {
        if (sk_atomic_dec(&fRefCnt) == 1) {   
			sk_membar_acquire__after_atomic_dec();
            internal_dispose();
        }
    }

	void deref()const
	{
		if (sk_atomic_dec(&fRefCnt) == 1) {
			sk_membar_acquire__after_atomic_dec();
			internal_dispose();
		}
	}

protected:

    void internal_dispose_restore_refcnt_to_1() const {
#ifdef SK_DEBUG
        fRefCnt = 1;
#endif
    }

private:

    virtual void internal_dispose() const {
        this->internal_dispose_restore_refcnt_to_1();
        SkDELETE(this);
    }
	
	friend class GrTexture;
    friend class SkWeakRefCnt;

    mutable int32_t fRefCnt;

    typedef SkNoncopyable INHERITED;
};


///////////////////////////////////////////////////////////////////////////////

/** Helper macro to safely assign one SkRefCnt[TS]* to another, checking for
    null in on each side of the assignment, and ensuring that ref() is called
    before unref(), in case the two pointers point to the same object.
 */
#define SkRefCnt_SafeAssign(dst, src)   \
    do {                                \
        if (src) src->ref();            \
        if (dst) dst->unref();          \
        dst = src;                      \
    } while (0)


/** Call obj->ref() and return obj. The obj must not be NULL.
 */
template <typename T> static inline T* SkRef(T* obj) {
    obj->ref();
    return obj;
}

/** Check if the argument is non-null, and if so, call obj->ref() and return obj.
 */
template <typename T> static inline T* SkSafeRef(T* obj) {
    if (obj) {
        obj->ref();
    }
    return obj;
}

/** Check if the argument is non-null, and if so, call obj->unref()
 */
template <typename T> static inline void SkSafeUnref(T* obj) {
    if (obj) {
        obj->unref();
    }
}

template<typename T> static inline void SkSafeSetNull(T*& obj) {
    if (NULL != obj) {
        obj->unref();
        obj = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////////

/**
 *  Utility class that simply unref's its argument in the destructor.
 */
template <typename T> class SkAutoTUnref : SkNoncopyable 
{
public:
    explicit SkAutoTUnref(T* obj = NULL) : fObj(obj) {}
    ~SkAutoTUnref() { SkSafeUnref(fObj); }

    T* get() const { return fObj; }

    T* reset(T* obj) {
        SkSafeUnref(fObj);
        fObj = obj;
        return obj;
    }

    void swap(SkAutoTUnref* other) {
        T* tmp = fObj;
        fObj = other->fObj;
        other->fObj = tmp;
    }


    T* detach() {
        T* obj = fObj;
        fObj = NULL;
        return obj;
    }

    /**
     *  BlockRef<B> is a type which inherits from B, cannot be created,
     *  cannot be deleted, and makes ref and unref private.
     */
    template<typename B> class BlockRef : public B {
    private:
        BlockRef();
        ~BlockRef();
        void ref() const;
        void unref() const;
    };

    /** If T is const, the type returned from operator-> will also be const. */
    typedef typename SkTConstType<BlockRef<T>, SkTIsConst<T>::value>::type BlockRefType;

    /**
     *  SkAutoTUnref assumes ownership of the ref. As a result, it is an error
     *  for the user to ref or unref through SkAutoTUnref. Therefore
     *  SkAutoTUnref::operator-> returns BlockRef<T>*. This prevents use of
     *  skAutoTUnrefInstance->ref() and skAutoTUnrefInstance->unref().
     */
    BlockRefType *operator->() const {
        return static_cast<BlockRefType*>(fObj);
    }
    operator T*() { return fObj; }

private:
    T*  fObj;
};
// Can't use the #define trick below to guard a bare SkAutoTUnref(...) because it's templated. :(

class SkAutoUnref : public SkAutoTUnref<SkRefCnt> {
public:
    SkAutoUnref(SkRefCnt* obj) : SkAutoTUnref<SkRefCnt>(obj) {}
};
#define SkAutoUnref(...) SK_REQUIRE_LOCAL_VAR(SkAutoUnref)

class SkAutoRef : SkNoncopyable {
public:
    SkAutoRef(SkRefCnt* obj) : fObj(obj) { SkSafeRef(obj); }
    ~SkAutoRef() { SkSafeUnref(fObj); }
private:
    SkRefCnt* fObj;
};
#define SkAutoRef(...) SK_REQUIRE_LOCAL_VAR(SkAutoRef)

/** Wrapper class for SkRefCnt pointers. This manages ref/unref of a pointer to
    a SkRefCnt (or subclass) object.
 */
template <typename T> class SkRefPtr {
public:
    SkRefPtr() : fObj(NULL) {}
    SkRefPtr(T* obj) : fObj(obj) { SkSafeRef(fObj); }
    SkRefPtr(const SkRefPtr& o) : fObj(o.fObj) { SkSafeRef(fObj); }
    ~SkRefPtr() { SkSafeUnref(fObj); }

    SkRefPtr& operator=(const SkRefPtr& rp) {
        SkRefCnt_SafeAssign(fObj, rp.fObj);
        return *this;
    }
    SkRefPtr& operator=(T* obj) {
        SkRefCnt_SafeAssign(fObj, obj);
        return *this;
    }

    T* get() const { return fObj; }
    T& operator*() const { return *fObj; }
    T* operator->() const { return fObj; }

    typedef T* SkRefPtr::*unspecified_bool_type;
    operator unspecified_bool_type() const {
        return fObj ? &SkRefPtr::fObj : NULL;
    }

private:
    T* fObj;
};

#endif
