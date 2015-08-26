#include "CanvasPattern.h"

namespace Canvas2D {

void CanvasPattern::parseRepetitionType(const std::string& type, bool& repeatX, bool& repeatY)
{
    if (type.empty() || type == "repeat") {
        repeatX = true;
        repeatY = true;
        return;
    }
    if (type == "no-repeat") {
        repeatX = false;
        repeatY = false;
        return;
    }
    if (type == "repeat-x") {
        repeatX = true;
        repeatY = false;
        return;
    }
    if (type == "repeat-y") {
        repeatX = false;
        repeatY = true;
        return;
    }
}

CanvasPattern::CanvasPattern(PassRefPtr<BitmapImage> image, bool repeatX, bool repeatY, bool originClean)
    :m_originClean(originClean)
{
	m_pattern = (Pattern::create(image, repeatX, repeatY));
}

}
