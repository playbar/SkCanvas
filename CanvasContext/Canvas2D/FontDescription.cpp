

#include "FontDescription.h"
#include "string"
#include "HashTools.h"
#include "CSSValueKeywords.h"

namespace WebCore {

	static const std::string cssValue[]
	{
		"normal",
		"italic",
		"oblique",
		"small-caps",
		"blod",
		"bolder",
		"lighter",
		"100",
		"200",
		"300",
		"400",
		"500",
		"600",
		"700",
		"800",
		"900"
	};

struct SameSizeAsFontDescription {
    float sizes[4];
    // FXIME: Make them fit into one word.
    int bitfields;
    int bitfields2 : 8;
};

bool FontDescription::s_useSubpixelTextPositioning = false;

FontWeight FontDescription::lighterWeight(void) const
{
    switch (m_weight) {
        case FontWeight100:
        case FontWeight200:
        case FontWeight300:
        case FontWeight400:
        case FontWeight500:
            return FontWeight100;

        case FontWeight600:
        case FontWeight700:
            return FontWeight400;

        case FontWeight800:
        case FontWeight900:
            return FontWeight700;
    }
    return FontWeightNormal;
}

FontWeight FontDescription::bolderWeight(void) const
{
    switch (m_weight) {
        case FontWeight100:
        case FontWeight200:
        case FontWeight300:
            return FontWeight400;

        case FontWeight400:
        case FontWeight500:
            return FontWeight700;

        case FontWeight600:
        case FontWeight700:
        case FontWeight800:
        case FontWeight900:
            return FontWeight900;
    }
    return FontWeightNormal;
}



FontDescription FontDescription::makeNormalFeatureSettings() const
{
    FontDescription normalDescription(*this);
    return normalDescription;
}

void FontDescription::parseFontDes(const std::string &newFont)
{
	//int ispace = newFont
	std::string::size_type pos = 0;
	int size = newFont.size();
	for (int i = 0; i < size; i++ )
	{
		pos = newFont.find(" ", i);
		if ( pos < size )
		{
			std::string s = newFont.substr(i, pos - i);
			const Value *val = findValue(s.c_str(), s.length());
			if (val)
			{
				switch (val->id)
				{
				case CSSValueOblique:
					// FIXME: oblique is the same as italic for the moment...
				case CSSValueItalic:
					m_italic = FontStyleItalic;
					break;
				case CSSValueSmallCaps:
					s_variant = FontVariantSmallCaps;
					break;
				case CSSValueBold:
					m_weight = FontWeightBold;
					break;
				case CSSValue900:
					m_weight = FontWeight900;
					break;;
				case CSSValue800:
					m_weight = FontWeight800;
					break;
				case CSSValue700:
					m_weight = FontWeight700;
					break;
				case CSSValue600:
					m_weight = FontWeight600;
					break;
				case CSSValue500:
					m_weight = FontWeight500;
					break;
				case CSSValue400:
					m_weight = FontWeight400;
					break;
				case CSSValue300:
					m_weight = FontWeight300;
					break;
				case CSSValue200:
					m_weight = FontWeight200;
					break;
				case CSSValue100:
					m_weight = FontWeight100;
					break;
				default:
					break;
				}
			}
			else
			{
				std::string::size_type pos1 = s.find("px");
				if ( pos1 != std::string::npos )
				{
					s = s.substr(0, s.length() - 2);
					float fsize = atof(s.c_str());
					m_specifiedSize = fsize;
					m_computedSize = fsize;
				}
				else
				{
					m_fontName = s;
				}
			}
			i = pos;
		}
		else
		{
			m_fontName = newFont.substr(newFont.rfind(" ") + 1);
		}
	}

	//const Value *val = findValue(newFont.c_str(), newFont.length());
	//int i = val->nameOffset;
	//i += 0;
	return;
}










} // namespace WebCore
