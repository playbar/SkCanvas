/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef GrSurface_DEFINED
#define GrSurface_DEFINED

#include "GrTypes.h"
#include "GrResource.h"
#include "SkRect.h"

class GrTexture;
class GrRenderTarget;
struct SkImageInfo;

class GrSurface : public GrResource
{
public:
    SK_DECLARE_INST_COUNT(GrSurface);
	int width() const { return fDesc.fWidth; }
    int height() const { return fDesc.fHeight; }
    void getBoundsRect(SkRect* rect) const { rect->setWH(SkIntToScalar(this->width()),
                                                         SkIntToScalar(this->height())); }

    GrSurfaceOrigin origin() const 
	{
        return fDesc.fOrigin;
    }
    GrPixelConfig config() const { return fDesc.fConfig; }

    const GrTextureDesc& desc() const { return fDesc; }

    void asImageInfo(SkImageInfo*) const;
    virtual GrTexture* asTexture() = 0;
    virtual const GrTexture* asTexture() const = 0;

    virtual GrRenderTarget* asRenderTarget() = 0;
    virtual const GrRenderTarget* asRenderTarget() const = 0;

    /**
     * Checks whether this GrSurface refers to the same GPU object as other. This
     * catches the case where a GrTexture and GrRenderTarget refer to the same
     * GPU memory.
     */
    bool isSameAs(const GrSurface* other) const 
	{
        const GrRenderTarget* thisRT = this->asRenderTarget();
        if (NULL != thisRT) {
            return thisRT == other->asRenderTarget();
        } else {
            const GrTexture* thisTex = this->asTexture();
            return thisTex == other->asTexture();
        }
    }

    /**
     * Reads a rectangle of pixels from the surface.
     * @param left          left edge of the rectangle to read (inclusive)
     * @param top           top edge of the rectangle to read (inclusive)
     * @param width         width of rectangle to read in pixels.
     * @param height        height of rectangle to read in pixels.
     * @param config        the pixel config of the destination buffer
     * @param buffer        memory to read the rectangle into.
     * @param rowBytes      number of bytes between consecutive rows. Zero means rows are tightly
     *                      packed.
     * @param pixelOpsFlags See the GrContext::PixelOpsFlags enum.
     *
     * @return true if the read succeeded, false if not. The read can fail because of an unsupported
     *              pixel config.
     */
    virtual bool readPixels(int left, int top, int width, int height,
                            GrPixelConfig config,
                            void* buffer,
                            size_t rowBytes = 0,
                            uint32_t pixelOpsFlags = 0) = 0;

    /**
     * Copy the src pixels [buffer, rowbytes, pixelconfig] into the surface at the specified
     * rectangle.
     * @param left          left edge of the rectangle to write (inclusive)
     * @param top           top edge of the rectangle to write (inclusive)
     * @param width         width of rectangle to write in pixels.
     * @param height        height of rectangle to write in pixels.
     * @param config        the pixel config of the source buffer
     * @param buffer        memory to read the rectangle from.
     * @param rowBytes      number of bytes between consecutive rows. Zero means rows are tightly
     *                      packed.
     * @param pixelOpsFlags See the GrContext::PixelOpsFlags enum.
     */
    virtual void writePixels(int left, int top, int width, int height,
                             GrPixelConfig config,
                             const void* buffer,
                             size_t rowBytes = 0,
                             uint32_t pixelOpsFlags = 0) = 0;

    /**
     * Write the contents of the surface to a PNG. Returns true if successful.
     * @param filename      Full path to desired file
     */
    bool savePixels(const char* filename);

protected:
    GrSurface(GrGpu* gpu, bool isWrapped, const GrTextureDesc& desc)
    : INHERITED(gpu, isWrapped)
    , fDesc(desc) 
	{
    }

    GrTextureDesc fDesc;

private:
    typedef GrResource INHERITED;
};

#endif // GrSurface_DEFINED
