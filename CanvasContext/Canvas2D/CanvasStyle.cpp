#include "CanvasStyle.h"
#include "CanvasGradient.h"
#include "CanvasPattern.h"
#include "PassRefPtr.h"
#include "CanvasContext2D.h"
#include "Color.h"
#include <ctype.h>
#include <string.h>

namespace WebCore {

#ifdef __ANDROID__

int stricmp(const char* dst, const char* src)
{
	int f, l;

    do
    {
        if ( ((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z') )
            f -= 'A' - 'a';
        if ( ((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z') )
            l -= 'A' - 'a';
    }
    while ( f && (f == l) );

    return(f - l);
//	return strnicmp(lhs, rhs, 0);
}

#endif

enum ColorParseResult { ParsedRGBA, ParsedCurrentColor, ParsedSystemColor, ParseFailed };

static ColorParseResult parseColor(RGBA32& parsedColor, const std::string& colorString)
{
	if (stricmp(colorString.c_str(), "currentcolor" ) == 0)
	{
		return ParsedCurrentColor;
	}
	unsigned int ilen = colorString.length();
    if ( ilen >= 3 )
    {
		if ( colorString[0] == '#')
		{
			if (Color::parseHexColor(colorString.c_str() + 1, ilen - 1, parsedColor));
			{
				return ParsedRGBA;
			}
		}
		else
		{
			if (Color::parseHexColor(colorString, parsedColor ))
			{
				return ParsedRGBA;
			}
		}
    }
	Color tc;
	if (!tc.setNamedColor(colorString))
	{
		return ParseFailed;
	}
	parsedColor = tc.rgb();
	return ParsedRGBA;
}

RGBA32 currentColor()
{
	SkASSERT(false);
    RGBA32 rgba = Color::black;
    //BisonCSSParser::parseColor(rgba, canvas->inlineStyle()->getPropertyValue(CSSPropertyColor));
    return rgba;
}

bool parseColorOrCurrentColor(RGBA32& parsedColor, const std::string& colorString )
{
    ColorParseResult parseResult = parseColor(parsedColor, colorString);
    switch (parseResult) {
    case ParsedRGBA:
    case ParsedSystemColor:
        return true;
    case ParsedCurrentColor:
        parsedColor = currentColor();
        return true;
    case ParseFailed:
        return false;
    default:
        return false;
    }
}

CanvasStyle::CanvasStyle(Type type, float overrideAlpha)
    : m_type(type)
    , m_overrideAlpha(overrideAlpha)
{
}

CanvasStyle::CanvasStyle(RGBA32 rgba)
    : m_type(RGBA)
    , m_rgba(rgba)
{
}

CanvasStyle::CanvasStyle(float grayLevel, float alpha)
    : m_type(RGBA)
    , m_rgba(makeRGBA32FromFloats(grayLevel, grayLevel, grayLevel, alpha))
{
}

CanvasStyle::CanvasStyle(float r, float g, float b, float a)
    : m_type(RGBA)
    , m_rgba(makeRGBA32FromFloats(r, g, b, a))
{
}

CanvasStyle::CanvasStyle(float c, float m, float y, float k, float a)
    : m_type(CMYKA)
    , m_rgba(makeRGBAFromCMYKA(c, m, y, k, a))
    , m_cmyka(c, m, y, k, a)
{
}

CanvasStyle::CanvasStyle(PassRefPtr<CanvasGradient> gradient)
    : m_type(Gradient)
{
	m_gradient = gradient;
}

CanvasStyle::CanvasStyle(PassRefPtr<CanvasPattern> pattern)
    : m_type(ImagePattern)
{
	m_pattern = (pattern);
}

PassRefPtr<CanvasStyle> CanvasStyle::createFromString(const std::string& color)
{
    RGBA32 rgba;
    ColorParseResult parseResult = parseColor(rgba, color);
    switch (parseResult) {
    case ParsedRGBA:
    case ParsedSystemColor:
        return adoptRef(new CanvasStyle(rgba));
    case ParsedCurrentColor:
        return adoptRef(new CanvasStyle(CurrentColor));
    case ParseFailed:
        return nullptr;
    default:
        return nullptr;
    }
}

PassRefPtr<CanvasStyle> CanvasStyle::createFromStringWithOverrideAlpha(const std::string& color, float alpha)
{
    RGBA32 rgba;
    ColorParseResult parseResult = parseColor(rgba, color);
    switch (parseResult) {
    case ParsedRGBA:
        return adoptRef(new CanvasStyle(colorWithOverrideAlpha(rgba, alpha)));
    case ParsedCurrentColor:
        return adoptRef(new CanvasStyle(CurrentColorWithOverrideAlpha, alpha));
    case ParseFailed:
        return nullptr;
    default:
        return nullptr;
    }
}

PassRefPtr<CanvasStyle> CanvasStyle::createFromGradient(PassRefPtr<CanvasGradient> gradient)
{
    if (!gradient)
        return nullptr;
    return adoptRef(new CanvasStyle(gradient));
}

PassRefPtr<CanvasStyle> CanvasStyle::createFromPattern(PassRefPtr<CanvasPattern> pattern)
{
    if (!pattern)
        return nullptr;
    return adoptRef(new CanvasStyle(pattern));
}

bool CanvasStyle::isEquivalentColor(const CanvasStyle& other) const
{
    if (m_type != other.m_type)
        return false;

    switch (m_type) {
    case RGBA:
        return m_rgba == other.m_rgba;
    case CMYKA:
        return m_cmyka.c == other.m_cmyka.c
            && m_cmyka.m == other.m_cmyka.m
            && m_cmyka.y == other.m_cmyka.y
            && m_cmyka.k == other.m_cmyka.k
            && m_cmyka.a == other.m_cmyka.a;
    case Gradient:
    case ImagePattern:
    case CurrentColor:
    case CurrentColorWithOverrideAlpha:
        return false;
    }

    return false;
}

bool CanvasStyle::isEquivalentRGBA(float r, float g, float b, float a) const
{
    if (m_type != RGBA)
        return false;

    return m_rgba == makeRGBA32FromFloats(r, g, b, a);
}

bool CanvasStyle::isEquivalentCMYKA(float c, float m, float y, float k, float a) const
{
    if (m_type != CMYKA)
        return false;

    return c == m_cmyka.c
        && m == m_cmyka.m
        && y == m_cmyka.y
        && k == m_cmyka.k
        && a == m_cmyka.a;
}

void CanvasStyle::applyStrokeColor(CanvasContext2D* context)
{
    if (!context)
        return;
    switch (m_type) {
    case RGBA:
        context->setStrokeColor(m_rgba);
        break;
    case CMYKA: {
        // FIXME: Do this through platform-independent GraphicsContext API.
        // We'll need a fancier Color abstraction to support CMYKA correctly
        context->setStrokeColor(m_rgba);
        break;
    }
				SkASSERT(false);
    //case Gradient:
    //    context->setStrokeGradient(canvasGradient()->gradient());
    //    break;
    //case ImagePattern:
    //    context->setStrokePattern(canvasPattern()->pattern());
    //    break;
    case CurrentColor:
    case CurrentColorWithOverrideAlpha:
        break;
    }
}

void CanvasStyle::applyFillColor(CanvasContext2D* context)
{
    if (!context)
        return;
    switch (m_type) {
    case RGBA:
        context->setFillColor(m_rgba);
        break;
    case CMYKA: {
        // FIXME: Do this through platform-independent GraphicsContext API.
        // We'll need a fancier Color abstraction to support CMYKA correctly
        context->setFillColor(m_rgba);
        break;
    }
				SkASSERT(false);
	//case Gradient:
	//	context->setFillGradient(canvasGradient()->gradient());
	//	break;
	//case ImagePattern:
	//	context->setFillPattern(canvasPattern()->pattern());
	//	break;

    case CurrentColor:
    case CurrentColorWithOverrideAlpha:
        break;
    }
}

}
