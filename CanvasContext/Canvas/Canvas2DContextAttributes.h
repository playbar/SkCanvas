#ifndef Canvas2DContextAttributes_h
#define Canvas2DContextAttributes_h

#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"

namespace WebCore {

class Canvas2DContextAttributes : public RefCounted<Canvas2DContextAttributes>{
public:
    virtual ~Canvas2DContextAttributes();

    // Create a new attributes object
    static PassRefPtr<Canvas2DContextAttributes> create();

    // Whether or not the drawing buffer has an alpha channel; default=true
    bool alpha() const;
    void setAlpha(bool);

protected:
    Canvas2DContextAttributes();

    bool m_alpha;
};

} // namespace WebCore

#endif // Canvas2DContextAttributes_h
