#ifndef SkiaUtils_h
#define SkiaUtils_h

#include "SkMatrix.h"
#include "SkPath.h"
#include "SkXfermode.h"
#include "FloatRect.h"
#include "Color.h"
#include "graphicstypes.h"
#include "AffineTransform.h"
#include "MathExtras.h"
#include "PassRefPtr.h"

class SkCanvas;
class SkRegion;

namespace WebCore {

class GraphicsContext;

PassRefPtr<SkXfermode> WebCoreCompositeToSkiaComposite(CompositeOperator, WebBlendMode = WebBlendModeNormal);

// move this guy into SkColor.h
SkColor SkPMColorToColor(SkPMColor);

// Skia has problems when passed infinite, etc floats, filter them to 0.
inline SkScalar WebCoreFloatToSkScalar(float f)
{
    return (std::isfinite(f) ? f : 0);
}

inline SkScalar WebCoreDoubleToSkScalar(double d)
{
    return (std::isfinite(d) ? d : 0);
}

inline SkRect WebCoreFloatRectToSKRect(const FloatRect& rect)
{
    return SkRect::MakeLTRB((rect.x()), (rect.y()),
        (rect.maxX()), (rect.maxY()));
}

inline bool WebCoreFloatNearlyEqual(float a, float b)
{
    return SkScalarNearlyEqual(WebCoreFloatToSkScalar(a), WebCoreFloatToSkScalar(b));
}

// Determine if a given WebKit point is contained in a path
bool  SkPathContainsPoint(const SkPath&, const FloatPoint&, SkPath::FillType);

SkMatrix  affineTransformToSkMatrix(const AffineTransform&);

}  // namespace WebCore

#endif  // SkiaUtils_h
