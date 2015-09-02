#include "CustomElementBinding.h"
#include "SkTypes.h"
#include "include/v8.h"

namespace Canvas2D
{

PassOwnPtr<CustomElementBinding> CustomElementBinding::create(v8::Isolate* isolate, v8::Handle<v8::Object> prototype, const WrapperTypeInfo* wrapperType)
{
    return adoptPtr(new CustomElementBinding(isolate, prototype, wrapperType));
}

CustomElementBinding::CustomElementBinding(v8::Isolate* isolate, v8::Handle<v8::Object> prototype, const WrapperTypeInfo* wrapperType)
    : m_isolate(isolate)
    , m_prototype(isolate, prototype)
    , m_wrapperType(wrapperType)
{
    SkASSERT(!m_prototype.isEmpty());
    SkASSERT(m_wrapperType);
}

} // namespace WebCore
