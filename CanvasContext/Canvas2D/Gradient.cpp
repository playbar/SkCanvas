#include "Gradient.h"

#include "FloatRect.h"
#include "color.h"
#include "SkColorShader.h"
#include "SkShader.h"
#include "SkGradientShader.h"
#include "SkiaUtils.h"

namespace WebCore {

Gradient::Gradient(const SkPoint& p0, const SkPoint& p1)
    : m_p0(p0)
    , m_p1(p1)
    , m_r0(0)
    , m_r1(0)
    , m_aspectRatio(1)
    , m_radial(false)
    , m_stopsSorted(false)
    , m_drawInPMColorSpace(false)
    , m_spreadMethod(SpreadMethodPad)
{
}

Gradient::Gradient(const SkPoint& p0, float r0, const SkPoint& p1, float r1, float aspectRatio)
    : m_p0(p0)
    , m_p1(p1)
    , m_r0(r0)
    , m_r1(r1)
    , m_aspectRatio(aspectRatio)
    , m_radial(true)
    , m_stopsSorted(false)
    , m_drawInPMColorSpace(false)
    , m_spreadMethod(SpreadMethodPad)
{
}

Gradient::~Gradient()
{
}

void Gradient::addColorStop(float value, const Color& color)
{
    float r;
    float g;
    float b;
    float a;
    color.getRGBA(r, g, b, a);
    m_stops.push_back(ColorStop(value, r, g, b, a));

    m_stopsSorted = false;
    m_gradient.clear();
}

void Gradient::addColorStop(const Gradient::ColorStop& stop)
{
    m_stops.push_back(stop);

    m_stopsSorted = false;
    m_gradient.clear();
}

static inline bool compareStops(const Gradient::ColorStop& a, const Gradient::ColorStop& b)
{
    return a.stop < b.stop;
}

void Gradient::sortStopsIfNecessary()
{
    if (m_stopsSorted)
        return;

    m_stopsSorted = true;

    if (!m_stops.size())
        return;

    std::stable_sort(m_stops.begin(), m_stops.end(), compareStops);
}

bool Gradient::hasAlpha() const
{
    for (size_t i = 0; i < m_stops.size(); i++) {
        if (m_stops[i].alpha < 1)
            return true;
    }

    return false;
}

void Gradient::setSpreadMethod(GradientSpreadMethod spreadMethod)
{
    // FIXME: Should it become necessary, allow calls to this method after m_gradient has been set.

    if (m_spreadMethod == spreadMethod)
        return;

    m_spreadMethod = spreadMethod;
}

void Gradient::setDrawsInPMColorSpace(bool drawInPMColorSpace)
{
    if (drawInPMColorSpace == m_drawInPMColorSpace)
        return;

    m_drawInPMColorSpace = drawInPMColorSpace;
    m_gradient.clear();
}

void Gradient::setGradientSpaceTransform(const AffineTransform& gradientSpaceTransformation)
{
    if (m_gradientSpaceTransformation == gradientSpaceTransformation)
        return;

    m_gradientSpaceTransformation = gradientSpaceTransformation;
    if (m_gradient)
        m_gradient->setLocalMatrix(affineTransformToSkMatrix(m_gradientSpaceTransformation));
}

static inline U8CPU F2B(float x)
{
    return static_cast<int>(x * 255);
}

static SkColor makeSkColor(float a, float r, float g, float b)
{
    return SkColorSetARGB(F2B(a), F2B(r), F2B(g), F2B(b));
}

// Determine the total number of stops needed, including pseudo-stops at the
// ends as necessary.
static size_t totalStopsNeeded(const Gradient::ColorStop* stopData, size_t count)
{
    // N.B.: The tests in this function should kept in sync with the ones in
    // fillStops(), or badness happens.
    const Gradient::ColorStop* stop = stopData;
    size_t countUsed = count;
    if (count < 1 || stop->stop > 0.0)
        countUsed++;
    stop += count - 1;
    if (count < 1 || stop->stop < 1.0)
        countUsed++;
    return countUsed;
}

// Collect sorted stop position and color information into the pos and colors
// buffers, ensuring stops at both 0.0 and 1.0. The buffers must be large
// enough to hold information for all stops, including the new endpoints if
// stops at 0.0 and 1.0 aren't already included.
static void fillStops(const Gradient::ColorStop* stopData,
    size_t count, SkScalar* pos, SkColor* colors)
{
    const Gradient::ColorStop* stop = stopData;
    size_t start = 0;
    if (count < 1) {
        // A gradient with no stops must be transparent black.
        pos[0] = WebCoreFloatToSkScalar(0.0);
        colors[0] = makeSkColor(0.0, 0.0, 0.0, 0.0);
        start = 1;
    } else if (stop->stop > 0.0) {
        // Copy the first stop to 0.0. The first stop position may have a slight
        // rounding error, but we don't care in this float comparison, since
        // 0.0 comes through cleanly and people aren't likely to want a gradient
        // with a stop at (0 + epsilon).
        pos[0] = WebCoreFloatToSkScalar(0.0);
        colors[0] = makeSkColor(stop->alpha, stop->red, stop->green, stop->blue);
        start = 1;
    }

    for (size_t i = start; i < start + count; i++) {
        pos[i] = WebCoreFloatToSkScalar(stop->stop);
        colors[i] = makeSkColor(stop->alpha, stop->red, stop->green, stop->blue);
        ++stop;
    }

    // Copy the last stop to 1.0 if needed. See comment above about this float
    // comparison.
    if (count < 1 || (--stop)->stop < 1.0) {
        pos[start + count] = WebCoreFloatToSkScalar(1.0);
        colors[start + count] = colors[start + count - 1];
    }
}

SkShader* Gradient::shader()
{
    if (m_gradient)
        return m_gradient.get();

    sortStopsIfNecessary();

    //size_t countUsed = totalStopsNeeded(m_stops.data(), m_stops.size());

    const Gradient::ColorStop *dat = &(m_stops[0]);
    size_t countUsed = totalStopsNeeded(dat, m_stops.size());
    // FIXME: Why is all this manual pointer math needed?!
    SkAutoMalloc storage(countUsed * (sizeof(SkColor) + sizeof(SkScalar)));
    SkColor* colors = (SkColor*)storage.get();
    SkScalar* pos = (SkScalar*)(colors + countUsed);

    fillStops(dat, m_stops.size(), pos, colors);

    SkShader::TileMode tile = SkShader::kClamp_TileMode;
    switch (m_spreadMethod) {
    case SpreadMethodReflect:
        tile = SkShader::kMirror_TileMode;
        break;
    case SpreadMethodRepeat:
        tile = SkShader::kRepeat_TileMode;
        break;
    case SpreadMethodPad:
        tile = SkShader::kClamp_TileMode;
        break;
    }

    uint32_t shouldDrawInPMColorSpace = m_drawInPMColorSpace ? SkGradientShader::kInterpolateColorsInPremul_Flag : 0;
    if (m_radial) {
        // Since the two-point radial gradient is slower than the plain radial,
        // only use it if we have to.
        if (m_p0 == m_p1 && m_r0 <= 0.0f) {
			m_gradient = (SkGradientShader::CreateRadial(m_p1, m_r1, colors, pos, static_cast<int>(countUsed), tile, 0, shouldDrawInPMColorSpace, NULL));
        } else {
            // The radii we give to Skia must be positive. If we're given a
            // negative radius, ask for zero instead.
            SkScalar radius0 = m_r0 >= 0.0f ? WebCoreFloatToSkScalar(m_r0) : 0;
            SkScalar radius1 = m_r1 >= 0.0f ? WebCoreFloatToSkScalar(m_r1) : 0;
            m_gradient = (SkGradientShader::CreateTwoPointConical(m_p0, radius0, m_p1, radius1, colors, pos, static_cast<int>(countUsed), tile, 0, shouldDrawInPMColorSpace, NULL));
        }

        if (aspectRatio() != 1) {
            // CSS3 elliptical gradients: apply the elliptical scaling at the
            // gradient center point.
            m_gradientSpaceTransformation.translate(m_p0.fX, m_p0.fY);
            m_gradientSpaceTransformation.scale(1, 1 / aspectRatio());
            m_gradientSpaceTransformation.translate(-m_p0.fX, -m_p0.fY);
        }
    } 
	else
	{
        SkPoint pts[2] = { m_p0, m_p1 };
        m_gradient = (SkGradientShader::CreateLinear(pts, colors, pos, static_cast<int>(countUsed), tile, 0, shouldDrawInPMColorSpace, NULL ));
    }

    if (!m_gradient) {
        // use last color, since our "geometry" was degenerate (e.g. radius==0)
        m_gradient = (new SkColorShader(colors[countUsed - 1]));
    } else {
        m_gradient->setLocalMatrix(affineTransformToSkMatrix(m_gradientSpaceTransformation));
    }
    return m_gradient.get();
}

} //namespace
