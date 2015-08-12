#ifndef Gradient_h
#define Gradient_h

#include "SkPoint.h"
#include "passrefptr.h"
#include "RefCounted.h"
#include "RefPtr.h"
#include "graphicstypes.h"
#include "AffineTransform.h"
#include "vector"

class SkShader;

namespace WebCore 
{

class Color;
class FloatRect;
class IntSize;

class Gradient : public RefCounted<Gradient> {
public:
    static Gradient *create(const SkPoint& p0, const SkPoint& p1)
    {
        return (new Gradient(p0, p1));
    }
    static Gradient *create(const SkPoint& p0, float r0, const SkPoint& p1, float r1, float aspectRatio = 1)
    {
        return (new Gradient(p0, r0, p1, r1, aspectRatio));
    }
    ~Gradient();

    struct ColorStop {
        float stop;
        float red;
        float green;
        float blue;
        float alpha;

        ColorStop() : stop(0), red(0), green(0), blue(0), alpha(0) { }
        ColorStop(float s, float r, float g, float b, float a) : stop(s), red(r), green(g), blue(b), alpha(a) { }
    };
    void addColorStop(const ColorStop&);
    void addColorStop(float, const Color&);

    bool hasAlpha() const;
    bool shaderChanged() const { return !m_gradient; }

    bool isRadial() const { return m_radial; }
    bool isZeroSize() const { return m_p0.fX == m_p1.fX && m_p0.y() == m_p1.y() && (!m_radial || m_r0 == m_r1); }

	const SkPoint& p0() const { return m_p0; }
	const SkPoint& p1() const { return m_p1; }

    void setP0(const SkPoint& p)
    {
        if (m_p0 == p)
            return;

        m_p0 = p;
    }

    void setP1(const SkPoint& p)
    {
        if (m_p1 == p)
            return;

        m_p1 = p;
    }

    float startRadius() const { return m_r0; }
    float endRadius() const { return m_r1; }

    void setStartRadius(float r)
    {
        if (m_r0 == r)
            return;

        m_r0 = r;
    }

    void setEndRadius(float r)
    {
        if (m_r1 == r)
            return;

        m_r1 = r;
    }

    float aspectRatio() const { return m_aspectRatio; }

    SkShader* shader();

    void setStopsSorted(bool s) { m_stopsSorted = s; }

    void setDrawsInPMColorSpace(bool drawInPMColorSpace);

    void setSpreadMethod(GradientSpreadMethod);
    GradientSpreadMethod spreadMethod() { return m_spreadMethod; }
    void setGradientSpaceTransform(const AffineTransform& gradientSpaceTransformation);
    AffineTransform gradientSpaceTransform() { return m_gradientSpaceTransformation; }

private:
    Gradient(const SkPoint& p0, const SkPoint& p1);
    Gradient(const SkPoint& p0, float r0, const SkPoint& p1, float r1, float aspectRatio);

    void destroyShader();

    void sortStopsIfNecessary();

    SkPoint m_p0;
    SkPoint m_p1;
    float m_r0;
    float m_r1;
    float m_aspectRatio; // For elliptical gradient, width / height.
    mutable std::vector<ColorStop> m_stops;
    bool m_radial;
    mutable bool m_stopsSorted;
    bool m_drawInPMColorSpace;
    GradientSpreadMethod m_spreadMethod;
    AffineTransform m_gradientSpaceTransformation;
    RefPtr<SkShader> m_gradient;

};

} // namespace WebCore

#endif
