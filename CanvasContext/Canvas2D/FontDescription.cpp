

#include "FontDescription.h"


namespace WebCore {

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










} // namespace WebCore
