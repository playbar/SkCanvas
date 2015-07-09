
/*
 * Copyright 2010 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkDevice_DEFINED
#define SkDevice_DEFINED

#include "SkRefCnt.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkColor.h"
#include "SkDeviceProperties.h"

class SkClipStack;
class SkDraw;
struct SkIRect;
class SkMatrix;
class SkMetaData;
class SkRegion;

class GrRenderTarget;

class SK_API SkBaseDevice : public SkRefCnt {
public:
    SK_DECLARE_INST_COUNT(SkBaseDevice)
    SkBaseDevice();
    SkBaseDevice(const SkDeviceProperties& deviceProperties);
    virtual ~SkBaseDevice();

    SkBaseDevice* createCompatibleDevice(SkBitmap::Config config,
                                         int width, int height,
                                         bool isOpaque);

    SkMetaData& getMetaData();

    enum Capabilities
	{
        kGL_Capability     = 0x1,  //!< mask indicating GL support
        kVector_Capability = 0x2,  //!< mask indicating a vector representation
        kAll_Capabilities  = 0x3
    };
    virtual uint32_t getDeviceCapabilities() = 0;
    virtual int width() const = 0;
    virtual int height() const = 0;
    virtual const SkDeviceProperties& getDeviceProperties() const {
        return fLeakyProperties;
    }

    void getGlobalBounds(SkIRect* bounds) const
	{
        const SkIPoint& origin = this->getOrigin();
        bounds->setXYWH(origin.x(), origin.y(), this->width(), this->height());
    }

    virtual bool isOpaque() const = 0;
    SK_ATTR_DEPRECATED("want to hide configness of the device -- don't use")
    virtual SkBitmap::Config config() const = 0;

    const SkBitmap& accessBitmap(bool changePixels);

    virtual void writePixels(const SkBitmap& bitmap, int x, int y,
                             SkCanvas::Config8888 config8888 = SkCanvas::kNative_Premul_Config8888) = 0;
  
    virtual GrRenderTarget* accessRenderTarget() = 0;
    const SkIPoint& getOrigin() const { return fOrigin; }
    virtual void onAttachToCanvas(SkCanvas*) {
        this->lockPixels();
    };

    virtual void onDetachFromCanvas()
	{
        this->unlockPixels();
    };

protected:
    enum Usage 
	{
       kGeneral_Usage,
       kSaveLayer_Usage  // <! internal use only
    };

    struct TextFlags 
	{
        uint32_t            fFlags;     // SkPaint::getFlags()
        SkPaint::Hinting    fHinting;
    };

    virtual bool filterTextFlags(const SkPaint& paint, TextFlags*) = 0;
     virtual void setMatrixClip(const SkMatrix&, const SkRegion&,
                                const SkClipStack&) {};
    virtual void clear(SkColor color) = 0;
    void eraseColor(SkColor eraseColor) { this->clear(eraseColor); }

    virtual void drawPaint(const SkDraw&, const SkPaint& paint) = 0;
    virtual void drawPoints(const SkDraw&, SkCanvas::PointMode mode, size_t count,
                            const SkPoint[], const SkPaint& paint) = 0;
    virtual void drawRect(const SkDraw&, const SkRect& r,
                          const SkPaint& paint) = 0;
    virtual void drawOval(const SkDraw&, const SkRect& oval,
                          const SkPaint& paint) = 0;
    virtual void drawRRect(const SkDraw&, const SkRRect& rr,
                           const SkPaint& paint) = 0;

    virtual void drawPath(const SkDraw&, const SkPath& path,
                          const SkPaint& paint,
                          const SkMatrix* prePathMatrix = NULL,
                          bool pathIsMutable = false) = 0;
    virtual void drawBitmap(const SkDraw&, const SkBitmap& bitmap,
                            const SkMatrix& matrix, const SkPaint& paint) = 0;
    virtual void drawSprite(const SkDraw&, const SkBitmap& bitmap,
                            int x, int y, const SkPaint& paint) = 0;

    virtual void drawBitmapRect(const SkDraw&, const SkBitmap&,
                                const SkRect* srcOrNull, const SkRect& dst,
                                const SkPaint& paint,
                                SkCanvas::DrawBitmapRectFlags flags) = 0;

    virtual void drawText(const SkDraw&, const void* text, size_t len,
                          float x, float y, const SkPaint& paint) = 0;
    virtual void drawPosText(const SkDraw&, const void* text, size_t len,
                             const float pos[], float constY,
                             int scalarsPerPos, const SkPaint& paint) = 0;
    virtual void drawTextOnPath(const SkDraw&, const void* text, size_t len,
                                const SkPath& path, const SkMatrix* matrix,
                                const SkPaint& paint) = 0;
    virtual void drawVertices(const SkDraw&, SkCanvas::VertexMode, int vertexCount,
                              const SkPoint verts[], const SkPoint texs[],
                              const SkColor colors[], SkXfermode* xmode,
                              const uint16_t indices[], int indexCount,
                              const SkPaint& paint) = 0;

    virtual void drawDevice(const SkDraw&, SkBaseDevice*, int x, int y,
                            const SkPaint&) = 0;

    virtual void drawPosTextOnPath(const SkDraw&, const void* text, size_t len,
                                   const SkPoint pos[], const SkPaint&,
                                   const SkPath&, const SkMatrix*) {}

    bool readPixels(SkBitmap* bitmap,
                    int x, int y,
                    SkCanvas::Config8888 config8888);

    virtual const SkBitmap& onAccessBitmap() = 0;
    virtual bool onReadPixels(const SkBitmap& bitmap,
                              int x, int y,
                              SkCanvas::Config8888 config8888) = 0;
    virtual void lockPixels() = 0;
    virtual void unlockPixels() = 0;
    virtual bool allowImageFilter(SkImageFilter*) = 0;
    virtual bool canHandleImageFilter(SkImageFilter*) = 0;
    virtual bool filterImage(SkImageFilter*, const SkBitmap&, const SkMatrix&,
                             SkBitmap* result, SkIPoint* offset) = 0;

    static const SkCanvas::Config8888 kPMColorAlias;

protected:
    /**
     *  Leaky properties are those which the device should be applying but it isn't.
     *  These properties will be applied by the draw, when and as it can.
     *  If the device does handle a property, that property should be set to the identity value
     *  for that property, effectively making it non-leaky.
     */
    SkDeviceProperties fLeakyProperties;

private:
    friend class SkCanvas;
    friend struct DeviceCM; //for setMatrixClip
    friend class SkDraw;
    friend class SkDrawIter;
    friend class SkDeviceFilteredPaint;
    friend class SkDeviceImageFilterProxy;

    friend class SkSurface_Raster;

    // used to change the backend's pixels (and possibly config/rowbytes)
    // but cannot change the width/height, so there should be no change to
    // any clip information.
    // TODO: move to SkBitmapDevice
    virtual void replaceBitmapBackendForRasterSurface(const SkBitmap&) = 0;

    void setOrigin(int x, int y) { fOrigin.set(x, y); }
    SkBaseDevice* createCompatibleDeviceForSaveLayer(SkBitmap::Config config,
                                                     int width, int height,
                                                     bool isOpaque);

    virtual SkBaseDevice* onCreateCompatibleDevice(SkBitmap::Config config,
                                                   int width, int height,
                                                   bool isOpaque,
                                                   Usage usage) = 0;

    virtual void flush() = 0;

    SkIPoint    fOrigin;
    SkMetaData* fMetaData;

    typedef SkRefCnt INHERITED;
};

#endif
