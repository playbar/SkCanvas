#ifndef Color_h
#define Color_h

#include "AnimationUtilities.h"
#include "string"

namespace WebCore 
{

class Color;

typedef unsigned RGBA32;

 RGBA32 makeRGB(int r, int g, int b);
 RGBA32 makeRGBA(int r, int g, int b, int a);

 RGBA32 colorWithOverrideAlpha(RGBA32 color, float overrideAlpha);
 RGBA32 makeRGBA32FromFloats(float r, float g, float b, float a);
 RGBA32 makeRGBAFromHSLA(double h, double s, double l, double a);
 RGBA32 makeRGBAFromCMYKA(float c, float m, float y, float k, float a);

 int differenceSquared(const Color&, const Color&);

inline int redChannel(RGBA32 color) { return (color >> 16) & 0xFF; }
inline int greenChannel(RGBA32 color) { return (color >> 8) & 0xFF; }
inline int blueChannel(RGBA32 color) { return color & 0xFF; }
inline int alphaChannel(RGBA32 color) { return (color >> 24) & 0xFF; }

struct NamedColor {
    const char* name;
    unsigned ARGBValue;
};

inline const NamedColor* findColor(register const char* str, register unsigned len)
{
	return NULL;
}

class Color {
public:
    Color() : m_color(Color::transparent) { }
    Color(RGBA32 color) : m_color(color) { }
    Color(int r, int g, int b) : m_color(makeRGB(r, g, b)) { }
    Color(int r, int g, int b, int a) : m_color(makeRGBA(r, g, b, a)) { }
    // Color is currently limited to 32bit RGBA, perhaps some day we'll support better colors
    Color(float r, float g, float b, float a) : m_color(makeRGBA32FromFloats(r, g, b, a)) { }
    // Creates a new color from the specific CMYK and alpha values.
    Color(float c, float m, float y, float k, float a) : m_color(makeRGBAFromCMYKA(c, m, y, k, a)) { }

    static Color createUnchecked(int r, int g, int b)
    {
        RGBA32 color = 0xFF000000 | r << 16 | g << 8 | b;
        return Color(color);
    }
    static Color createUnchecked(int r, int g, int b, int a)
    {
        RGBA32 color = a << 24 | r << 16 | g << 8 | b;
        return Color(color);
    }

    // Returns the color serialized according to HTML5
    std::string serialized() const;

    // Returns the color serialized according to CSSOM
    std::string serializedAsCSSComponentValue() const;

    // Returns the color serialized as either #RRGGBB or #RRGGBBAA
    // The latter format is not a valid CSS color, and should only be seen in DRT dumps.
	std::string nameForRenderTreeAsText() const;

    // Returns whether parsing succeeded. The resulting Color is arbitrary
    // if parsing fails.
	bool setFromString(const std::string&);
	bool setNamedColor(const std::string&);

    bool hasAlpha() const { return alpha() < 255; }

    int red() const { return redChannel(m_color); }
    int green() const { return greenChannel(m_color); }
    int blue() const { return blueChannel(m_color); }
    int alpha() const { return alphaChannel(m_color); }

    RGBA32 rgb() const { return m_color; } // Preserve the alpha.
    void setRGB(int r, int g, int b) { m_color = makeRGB(r, g, b); }
    void setRGB(RGBA32 rgb) { m_color = rgb; }
    void getRGBA(float& r, float& g, float& b, float& a) const;
    void getRGBA(double& r, double& g, double& b, double& a) const;
    void getHSL(double& h, double& s, double& l) const;

    Color light() const;
    Color dark() const;

    Color combineWithAlpha(float otherAlpha) const;

    // This is an implementation of Porter-Duff's "source-over" equation
    Color blend(const Color&) const;
    Color blendWithWhite() const;

	static bool parseHexColor(const std::string&, RGBA32&);
    static bool parseHexColor(const char*, unsigned, RGBA32&);

    static const RGBA32 black = 0xFF000000;
    static const RGBA32 white = 0xFFFFFFFF;
    static const RGBA32 darkGray = 0xFF808080;
    static const RGBA32 gray = 0xFFA0A0A0;
    static const RGBA32 lightGray = 0xFFC0C0C0;
    static const RGBA32 transparent = 0x00000000;

private:
    RGBA32 m_color;
};

inline bool operator==(const Color& a, const Color& b)
{
    return a.rgb() == b.rgb();
}

inline bool operator!=(const Color& a, const Color& b)
{
    return !(a == b);
}

 Color colorFromPremultipliedARGB(RGBA32);
 RGBA32 premultipliedARGBFromColor(const Color&);

inline Color blend(const Color& from, const Color& to, double progress, bool blendPremultiplied = true)
{
    if (blendPremultiplied) {
        // Contrary to the name, RGBA32 actually stores ARGB, so we can initialize Color directly from premultipliedARGBFromColor().
        // Also, premultipliedARGBFromColor() bails on zero alpha, so special-case that.
        Color premultFrom = from.alpha() ? premultipliedARGBFromColor(from) : 0;
        Color premultTo = to.alpha() ? premultipliedARGBFromColor(to) : 0;

        Color premultBlended(blend(premultFrom.red(), premultTo.red(), progress),
                             blend(premultFrom.green(), premultTo.green(), progress),
                             blend(premultFrom.blue(), premultTo.blue(), progress),
                             blend(premultFrom.alpha(), premultTo.alpha(), progress));

        return Color(colorFromPremultipliedARGB(premultBlended.rgb()));
    }

    return Color(blend(from.red(), to.red(), progress),
                 blend(from.green(), to.green(), progress),
                 blend(from.blue(), to.blue(), progress),
                 blend(from.alpha(), to.alpha(), progress));
}
} // namespace WebCore

#endif // Color_h
