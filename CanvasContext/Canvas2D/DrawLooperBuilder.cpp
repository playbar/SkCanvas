#include "DrawLooperBuilder.h"

#include "FloatSize.h"
#include "Color.h"
#include "SkColor.h"
#include "SkColorFilter.h"
#include "SkDrawLooper.h"
#include "SkPaint.h"
#include "SkXfermode.h"
#include "SkBlurMaskFilter.h"
#include "RefPtr.h"

namespace Canvas2D {

DrawLooperBuilder::DrawLooperBuilder() { }

DrawLooperBuilder::~DrawLooperBuilder() { }

PassOwnPtr<DrawLooperBuilder> DrawLooperBuilder::create()
{
    return adoptPtr(new DrawLooperBuilder);
}

PassRefPtr<SkDrawLooper> DrawLooperBuilder::detachDrawLooper()
{
    return adoptRef(m_skDrawLooperBuilder.detachLooper());
}

void DrawLooperBuilder::addUnmodifiedContent()
{
    SkLayerDrawLooper::LayerInfo info;
    m_skDrawLooperBuilder.addLayerOnTop(info);
}

// This replicates the old skia behavior when it used to take radius for blur. Now it takes sigma.
static SkScalar RadiusToSigma(SkScalar radius)
{
    SkASSERT(radius > 0);
    return 0.57735f * radius + 0.5f;
}

void DrawLooperBuilder::addShadow(const FloatSize& offset, float blur, const Color& color,
    ShadowTransformMode shadowTransformMode, ShadowAlphaMode shadowAlphaMode)
{
    // Detect when there's no effective shadow.
    if (!color.alpha())
        return;

    SkColor skColor = color.rgb();

    SkLayerDrawLooper::LayerInfo info;

    switch (shadowAlphaMode) {
    case ShadowRespectsAlpha:
        info.fColorMode = SkXfermode::kDst_Mode;
        break;
    case ShadowIgnoresAlpha:
        info.fColorMode = SkXfermode::kSrc_Mode;
        break;
    default:
		break;
    }

    if (blur)
        info.fPaintBits |= SkLayerDrawLooper::kMaskFilter_Bit; // our blur
    info.fPaintBits |= SkLayerDrawLooper::kColorFilter_Bit;
    info.fOffset.set(offset.width(), offset.height());
    info.fPostTranslate = (shadowTransformMode == ShadowIgnoresTransforms);

    SkPaint* paint = m_skDrawLooperBuilder.addLayerOnTop(info);

    if (blur) {
        const SkScalar sigma = RadiusToSigma(blur / 2);
        uint32_t mfFlags = SkBlurMaskFilter::kHighQuality_BlurFlag;
        if (shadowTransformMode == ShadowIgnoresTransforms)
            mfFlags |= SkBlurMaskFilter::kIgnoreTransform_BlurFlag;
        RefPtr<SkMaskFilter> mf = adoptRef(SkBlurMaskFilter::Create(kNormal_SkBlurStyle, sigma, mfFlags));
        paint->setMaskFilter(mf.get());
    }

    RefPtr<SkColorFilter> cf = adoptRef(SkColorFilter::CreateModeFilter(skColor, SkXfermode::kSrcIn_Mode));
    paint->setColorFilter(cf.get());
}

} // namespace WebCore
