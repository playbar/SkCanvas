
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkBitmap_DEFINED
#define SkBitmap_DEFINED

#include "Sk64.h"
#include "SkColor.h"
#include "SkColorTable.h"
#include "SkImageInfo.h"
#include "SkPoint.h"
#include "SkRefCnt.h"

struct SkIRect;
struct SkRect;
class SkPaint;
class SkPixelRef;
class SkRegion;
class SkString;

class GrTexture;

class SK_API SkBitmap 
{
public:
    class SK_API Allocator;

    enum Config 
	{
        kNo_Config,         //!< bitmap has not been configured
        kA8_Config,         //!< 8-bits per pixel, with only alpha specified (0 is transparent, 0xFF is opaque)
        kIndex8_Config,     //!< 8-bits per pixel, using SkColorTable to specify the colors
        kRGB_565_Config,    //!< 16-bits per pixel, (see SkColorPriv.h for packing)
        kARGB_4444_Config,  //!< 16-bits per pixel, (see SkColorPriv.h for packing)
        kARGB_8888_Config,  //!< 32-bits per pixel, (see SkColorPriv.h for packing)
		kConfigCount,
    };

    SkBitmap();

    SkBitmap(const SkBitmap& src);

    ~SkBitmap();
 
    SkBitmap& operator=(const SkBitmap& src);

    void swap(SkBitmap& other);

	bool empty() const;
	bool isNull() const;
	Config  config() const;

	SK_ATTR_DEPRECATED("use config()");
    Config  getConfig() const;

	int width() const;
	int height() const;
	size_t rowBytes() const;
	int shiftPerPixel() const;
	int bytesPerPixel() const;
	int rowBytesAsPixels() const;
	SkAlphaType alphaType() const;
    bool setAlphaType(SkAlphaType);
	void* getPixels() const;
	size_t getSize() const;
    size_t getSafeSize() const ;
	Sk64 getSize64() const;
    Sk64 getSafeSize64() const ;
    bool isImmutable() const;
    void setImmutable();
	bool isOpaque() const;
    bool isVolatile() const;
    void setIsVolatile(bool);
    void reset();
    static size_t ComputeRowBytes(Config c, int width);
    static int ComputeBytesPerPixel(Config c);
	static int ComputeShiftPerPixel(Config c);

    static Sk64 ComputeSize64(Config, int width, int height);
    static size_t ComputeSize(Config, int width, int height);
    static bool ComputeIsOpaque(const SkBitmap&);
    void getBounds(SkRect* bounds) const;
    void getBounds(SkIRect* bounds) const;
    bool setConfig(Config, int width, int height, size_t rowBytes, SkAlphaType);

	bool setConfig(Config config, int width, int height, size_t rowBytes = 0);
    bool setConfig(const SkImageInfo& info, size_t rowBytes = 0);
    bool asImageInfo(SkImageInfo* info) const;
    void setPixels(void* p, SkColorTable* ctable = NULL);
    bool copyPixelsTo(void* const dst, size_t dstSize, size_t dstRowBytes = 0,
                      bool preserveDstPad = false) const;
	bool allocPixels(SkColorTable* ctable = NULL);
    bool allocPixels(Allocator* allocator, SkColorTable* ctable);
	SkPixelRef* pixelRef() const;
	size_t pixelRefOffset() const;
    SkPixelRef* setPixelRef(SkPixelRef* pr, size_t offset = 0);
    void lockPixels() const;
    void unlockPixels() const;
    bool lockPixelsAreWritable() const;
	bool readyToDraw() const;
    GrTexture* getTexture() const;
    SkColorTable* getColorTable() const { return fColorTable; }
    uint32_t getGenerationID() const;
    void notifyPixelsChanged() const;
    void eraseColor(SkColor c) const
	{
        this->eraseARGB(SkColorGetA(c), SkColorGetR(c), SkColorGetG(c),
                        SkColorGetB(c));
    }
    void eraseARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b) const;

    SK_ATTR_DEPRECATED("use eraseARGB or eraseColor")
    void eraseRGB(U8CPU r, U8CPU g, U8CPU b) const 
	{
        this->eraseARGB(0xFF, r, g, b);
    }
    void eraseArea(const SkIRect& area, SkColor c) const;
    bool scrollRect(const SkIRect* subset, int dx, int dy,
                    SkRegion* inval = NULL) const;

    SkColor getColor(int x, int y) const;
    void* getAddr(int x, int y) const;
    inline uint32_t* getAddr32(int x, int y) const;
    inline uint16_t* getAddr16(int x, int y) const;

    inline uint8_t* getAddr8(int x, int y) const;

    inline SkPMColor getIndex8Color(int x, int y) const;

    bool extractSubset(SkBitmap* dst, const SkIRect& subset) const;

    bool copyTo(SkBitmap* dst, Config c, Allocator* allocator = NULL) const;

    bool deepCopyTo(SkBitmap* dst, Config c) const;
 
    bool canCopyTo(Config newConfig) const;

    SK_ATTR_DEPRECATED("use setFilterLevel on SkPaint")
    void buildMipMap(bool forceRebuild = false);

	bool extractAlpha(SkBitmap* dst) const;
	bool extractAlpha(SkBitmap* dst, const SkPaint* paint, SkIPoint* offset) const;
    bool extractAlpha(SkBitmap* dst, const SkPaint* paint, Allocator* allocator, SkIPoint* offset) const;

    void flatten(SkFlattenableWriteBuffer&) const;
    void unflatten(SkFlattenableReadBuffer&);

    class Allocator : public SkRefCnt
	{
    public:
        SK_DECLARE_INST_COUNT(Allocator)

        virtual bool allocPixelRef(SkBitmap*, SkColorTable*) = 0;
    private:
        typedef SkRefCnt INHERITED;
    };

    class HeapAllocator : public Allocator 
	{
    public:
        virtual bool allocPixelRef(SkBitmap*, SkColorTable*);
    };


    SkDEVCODE(void toString(SkString* str) const;)

private:
    struct MipMap;
    mutable MipMap* fMipMap;

    mutable SkPixelRef* fPixelRef;
    mutable size_t      fPixelRefOffset;
    mutable int         fPixelLockCount;
    // either user-specified (in which case it is not treated as mutable)
    // or a cache of the returned value from fPixelRef->lockPixels()
    mutable void*       fPixels;
    mutable SkColorTable* fColorTable;    // only meaningful for kIndex8

    enum Flags 
	{
        kImageIsOpaque_Flag     = 0x01,
        kImageIsVolatile_Flag   = 0x02,
        kImageIsImmutable_Flag  = 0x04,
    };

    uint32_t    fRowBytes;
    uint32_t    fWidth;
    uint32_t    fHeight;
    uint8_t     fConfig;
    uint8_t     fAlphaType;
    uint8_t     fFlags;
    uint8_t     fBytesPerPixel; // based on config

    void internalErase(const SkIRect&, U8CPU a, U8CPU r, U8CPU g, U8CPU b)const;

    static Sk64 ComputeSafeSize64(Config   config,
                                  uint32_t width,
                                  uint32_t height,
                                  size_t   rowBytes);
    static size_t ComputeSafeSize(Config   config,
                                  uint32_t width,
                                  uint32_t height,
                                  size_t   rowBytes);
    void freePixels();
    void updatePixelsFromRef() const;

    static SkFixed ComputeMipLevel(SkFixed sx, SkFixed dy);

    int extractMipLevel(SkBitmap* dst, SkFixed sx, SkFixed sy);
    bool hasMipMap() const;
    void freeMipMap();

    friend struct SkBitmapProcState;
};

class SkAutoLockPixels : public SkNoncopyable 
{
public:
    SkAutoLockPixels(const SkBitmap& bm, bool doLock = true) : fBitmap(bm) 
	{
        fDidLock = doLock;
        if (doLock) {
            bm.lockPixels();
        }
    }
    ~SkAutoLockPixels()
	{
        if (fDidLock) {
            fBitmap.unlockPixels();
        }
    }

private:
    const SkBitmap& fBitmap;
    bool            fDidLock;
};

class SkAutoLockColors : public SkNoncopyable
{
public:
    SkAutoLockColors() : fCTable(NULL), fColors(NULL) {}

    explicit SkAutoLockColors(const SkBitmap& bm) {
        fCTable = bm.getColorTable();
        fColors = fCTable ? fCTable->lockColors() : NULL;
    }
  
    explicit SkAutoLockColors(SkColorTable* ctable) {
        fCTable = ctable;
        fColors = ctable ? ctable->lockColors() : NULL;
    }
    ~SkAutoLockColors() {
        if (fCTable) {
            fCTable->unlockColors();
        }
    }

    const SkPMColor* colors() const { return fColors; }

    const SkPMColor* lockColors(SkColorTable* ctable) {
        if (fCTable) {
            fCTable->unlockColors();
        }
        fCTable = ctable;
        fColors = ctable ? ctable->lockColors() : NULL;
        return fColors;
    }

    const SkPMColor* lockColors(const SkBitmap& bm) {
        return this->lockColors(bm.getColorTable());
    }

private:
    SkColorTable*    fCTable;
    const SkPMColor* fColors;
};
#define SkAutoLockColors(...) SK_REQUIRE_LOCAL_VAR(SkAutoLockColors)

///////////////////////////////////////////////////////////////////////////////

inline uint32_t* SkBitmap::getAddr32(int x, int y) const {
    return (uint32_t*)((char*)fPixels + y * fRowBytes + (x << 2));
}

inline uint16_t* SkBitmap::getAddr16(int x, int y) const {
    return (uint16_t*)((char*)fPixels + y * fRowBytes + (x << 1));
}

inline uint8_t* SkBitmap::getAddr8(int x, int y) const {
    return (uint8_t*)fPixels + y * fRowBytes + x;
}

inline SkPMColor SkBitmap::getIndex8Color(int x, int y) const {
    return (*fColorTable)[*((const uint8_t*)fPixels + y * fRowBytes + x)];
}

#endif
