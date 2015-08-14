#ifndef CanvasPattern_h
#define CanvasPattern_h

#include "Pattern.h"
#include "passrefptr.h"
#include "RefCounted.h"
#include "string"
#include "BitmapImage.h"

namespace WebCore
{

class CanvasPattern : public RefCounted<CanvasPattern> {
public:
    static void parseRepetitionType(const std::string&, bool& repeatX, bool& repeatY );

	static PassRefPtr<CanvasPattern> create(PassRefPtr<BitmapImage> image, bool repeatX, bool repeatY, bool originClean)
    {
        return adoptRef(new CanvasPattern(image, repeatX, repeatY, originClean));
    }

    Pattern* pattern() const { return m_pattern.get(); }

    bool originClean() const { return m_originClean; }
	void deref() {};
private:
	CanvasPattern(PassRefPtr<BitmapImage>, bool repeatX, bool repeatY, bool originClean);

    RefPtr<Pattern> m_pattern;
    bool m_originClean;
};

} // namespace WebCore

#endif
