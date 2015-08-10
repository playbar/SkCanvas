#ifndef CanvasStyle_h
#define CanvasStyle_h

#include "Color.h"
#include "RefCounted.h"
#include "PassRefPtr.h"
#include "RefPtr.h"
#include "string"

namespace WebCore {

    class CanvasGradient;
    class CanvasPattern;
    class GraphicsContext;

	class CanvasStyle : public RefCounted<CanvasStyle> {
    public:
        static PassRefPtr<CanvasStyle> createFromRGBA(RGBA32 rgba) { return adoptRef(new CanvasStyle(rgba)); }
        static PassRefPtr<CanvasStyle> createFromString(const std::string& color);
        static PassRefPtr<CanvasStyle> createFromStringWithOverrideAlpha(const std::string& color, float alpha);
        static PassRefPtr<CanvasStyle> createFromGrayLevelWithAlpha(float grayLevel, float alpha) { return adoptRef(new CanvasStyle(grayLevel, alpha)); }
        static PassRefPtr<CanvasStyle> createFromRGBAChannels(float r, float g, float b, float a) { return adoptRef(new CanvasStyle(r, g, b, a)); }
        static PassRefPtr<CanvasStyle> createFromCMYKAChannels(float c, float m, float y, float k, float a) { return adoptRef(new CanvasStyle(c, m, y, k, a)); }
        static PassRefPtr<CanvasStyle> createFromGradient(PassRefPtr<CanvasGradient>);
        static PassRefPtr<CanvasStyle> createFromPattern(PassRefPtr<CanvasPattern>);

        bool isCurrentColor() const { return m_type == CurrentColor || m_type == CurrentColorWithOverrideAlpha; }
        bool hasOverrideAlpha() const { return m_type == CurrentColorWithOverrideAlpha; }
        float overrideAlpha() const { return m_overrideAlpha; }

		std::string color() const { return Color(m_rgba).serialized(); }
        CanvasGradient* canvasGradient() const { return m_gradient.get(); }
        CanvasPattern* canvasPattern() const { return m_pattern.get(); }

        void applyFillColor(GraphicsContext*);
        void applyStrokeColor(GraphicsContext*);

        bool isEquivalentColor(const CanvasStyle&) const;
        bool isEquivalentRGBA(float r, float g, float b, float a) const;
        bool isEquivalentCMYKA(float c, float m, float y, float k, float a) const;

		void deref() {}

    private:
        enum Type { RGBA, CMYKA, Gradient, ImagePattern, CurrentColor, CurrentColorWithOverrideAlpha };

        CanvasStyle(Type, float overrideAlpha = 0);
        CanvasStyle(RGBA32 rgba);
        CanvasStyle(float grayLevel, float alpha);
        CanvasStyle(float r, float g, float b, float a);
        CanvasStyle(float c, float m, float y, float k, float a);
        CanvasStyle(PassRefPtr<CanvasGradient>);
        CanvasStyle(PassRefPtr<CanvasPattern>);

        Type m_type;

        union {
            RGBA32 m_rgba;
            float m_overrideAlpha;
        };

        RefPtr<CanvasGradient> m_gradient;
        RefPtr<CanvasPattern> m_pattern;

        struct CMYKAValues {
            CMYKAValues() : c(0), m(0), y(0), k(0), a(0) { }
            CMYKAValues(float cyan, float magenta, float yellow, float black, float alpha) : c(cyan), m(magenta), y(yellow), k(black), a(alpha) { }
            float c;
            float m;
            float y;
            float k;
            float a;
        } m_cmyka;
    };

    RGBA32 currentColor();
    bool parseColorOrCurrentColor(RGBA32& parsedColor, const std::string& colorString );

} // namespace WebCore

#endif
