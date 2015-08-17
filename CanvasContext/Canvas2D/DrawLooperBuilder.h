#ifndef DrawLooperBuilder_h
#define DrawLooperBuilder_h

#include "SkLayerDrawLooper.h"
#include "Noncopyable.h"
#include "PassOwnPtr.h"
#include "passrefptr.h"

class SkDrawLooper;

namespace WebCore 
{

class Color;
class FloatSize;

class DrawLooperBuilder {
    // Implementing the copy constructor properly would require writing code to
    // copy the underlying SkLayerDrawLooper::Builder.
    WTF_MAKE_NONCOPYABLE(DrawLooperBuilder);

public:
    enum ShadowTransformMode {
        ShadowRespectsTransforms,
        ShadowIgnoresTransforms
    };
    enum ShadowAlphaMode {
        ShadowRespectsAlpha,
        ShadowIgnoresAlpha
    };

    DrawLooperBuilder();
    ~DrawLooperBuilder();

    static PassOwnPtr<DrawLooperBuilder> create();

    // Creates the SkDrawLooper and passes ownership to the caller. The builder
    // should not be used any more after calling this method.
    PassRefPtr<SkDrawLooper> detachDrawLooper();

    void addUnmodifiedContent();
    void addShadow(const FloatSize& offset, float blur, const Color&,
        ShadowTransformMode = ShadowRespectsTransforms,
        ShadowAlphaMode = ShadowRespectsAlpha);

private:
    SkLayerDrawLooper::Builder m_skDrawLooperBuilder;
};

} // namespace WebCore

#endif // DrawLooperBuilder_h
