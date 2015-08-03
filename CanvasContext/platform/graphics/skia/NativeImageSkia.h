#ifndef NativeImageSkia_h
#define NativeImageSkia_h

#include "SkBitmap.h"
#include "SkRect.h"
#include "SkSize.h"
#include "SkXfermode.h"
#include "platform/PlatformExport.h"
#include "platform/geometry/IntSize.h"
#include "platform/graphics/graphicstypes.h"
#include "wtf/Forward.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"

class SkMatrix;
class SkPaint;

namespace WebCore
{

class FloatPoint;
class FloatRect;
class FloatSize;
class GraphicsContext;

// Used by computeResamplingMode to tell how bitmaps should be resampled.
enum ResamplingMode 
{
    // Nearest neighbor resampling. Used when we detect that the page is
    // trying to make a pattern by stretching a small bitmap very large.
    NoResampling,

    // Default skia resampling. Used for large growing of images where high
    // quality resampling doesn't get us very much except a slowdown.
    LinearResampling,

    // High quality resampling.
    AwesomeResampling,
};

// This object is used as the "native image" in our port. When WebKit uses
// PassNativeImagePtr / NativeImagePtr, it is a smart pointer to this type.
// It has an SkBitmap, and also stores a cached resized image.
class PLATFORM_EXPORT NativeImageSkia : public RefCounted<NativeImageSkia> {
public:
    static PassRefPtr<NativeImageSkia> create()
    {
        return adoptRef(new NativeImageSkia());
    }
 
    static PassRefPtr<NativeImageSkia> create(const SkBitmap& bitmap)
    {
        return adoptRef(new NativeImageSkia(bitmap));
    }
 
    PassRefPtr<NativeImageSkia> clone() const
    {
        return adoptRef(new NativeImageSkia(m_image, m_resizedImage, m_cachedImageInfo, m_resizeRequests));
    }

    ~NativeImageSkia();

    int decodedSize() const;
    void setDataComplete() { m_image.setImmutable(); }

    // Returns true if the entire image has been decoded.
    bool isDataComplete() const { return m_image.isImmutable(); }

    // Get reference to the internal SkBitmap representing this image.
    const SkBitmap& bitmap() const { return m_image; }
    SkBitmap& bitmap() { return m_image; }

    // We can keep a resized version of the bitmap cached on this object.
    // This function will return true if there is a cached version of the given
    // scale and subset.
    bool hasResizedBitmap(const SkISize& scaledImageSize, const SkIRect& scaledImageSubset) const;

    SkBitmap resizedBitmap(const SkISize& scaledImageSize, const SkIRect& scaledImageSubset) const;

    void draw(GraphicsContext*, const SkRect& srcRect, const SkRect& destRect, PassRefPtr<SkXfermode>) const;
    void drawPattern(
        GraphicsContext*,
        const FloatRect& srcRect,
        const FloatSize& scale,
        const FloatPoint& phase,
        CompositeOperator,
        const FloatRect& destRect,
        blink::WebBlendMode,
        const IntSize& repeatSpacing) const;

private:
    NativeImageSkia();

    NativeImageSkia(const SkBitmap&);

    // ImageResourceInfo is used to uniquely identify cached or requested image
    // resizes.
    // Image resize is identified by the scaled image size and scaled image subset.
    struct ImageResourceInfo
	{
        SkISize scaledImageSize;
        SkIRect scaledImageSubset;

        ImageResourceInfo();

        bool isEqual(const SkISize& otherScaledImageSize, const SkIRect& otherScaledImageSubset) const;
        void set(const SkISize& otherScaledImageSize, const SkIRect& otherScaledImageSubset);
        SkIRect rectInSubset(const SkIRect& otherScaledImageRect);
    };

    NativeImageSkia(const SkBitmap& image, const SkBitmap& resizedImage, const ImageResourceInfo&, int resizeRequests);

	bool shouldCacheResampling(const SkISize& scaledImageSize, const SkIRect& scaledImageSubset) const;

    ResamplingMode computeResamplingMode(const SkMatrix&, float srcWidth, float srcHeight, float destWidth, float destHeight) const;
    SkBitmap extractScaledImageFragment(const SkRect& srcRect, float scaleX, float scaleY, SkRect* scaledSrcRect) const;
    void drawResampledBitmap(GraphicsContext*, SkPaint&, const SkRect& srcRect, const SkRect& destRect) const;

    // The original image.
    SkBitmap m_image;

    // The cached bitmap fragment. This is a subset of the scaled version of
    // |m_image|. empty() returns true if there is no cached image.
    mutable SkBitmap m_resizedImage;

    // References how many times that the image size has been requested for
    // the last size.
    //
    // Every time we get a call to shouldCacheResampling, if it matches the
    // m_cachedImageInfo, we'll increment the counter, and if not, we'll reset
    // the counter and save the dimensions.
    //
    // This allows us to see if many requests have been made for the same
    // resized image, we know that we should probably cache it, even if all of
    // those requests individually are small and would not otherwise be cached.
    //
    // We also track scaling information and destination subset for the scaled
    // image. See comments for ImageResourceInfo.
    mutable ImageResourceInfo m_cachedImageInfo;
    mutable int m_resizeRequests;
};

}
#endif  // NativeImageSkia_h
