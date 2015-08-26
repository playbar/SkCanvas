#ifndef CustomElementBinding_h
#define CustomElementBinding_h

#include "ScopedPersistent.h"
#include "PassOwnPtr.h"

namespace Canvas2D {

struct WrapperTypeInfo;

class CustomElementBinding 
{
public:
    static PassOwnPtr<CustomElementBinding> create(v8::Isolate*, v8::Handle<v8::Object> prototype, const WrapperTypeInfo*);

    ~CustomElementBinding() { }

    v8::Handle<v8::Object> prototype() { return m_prototype.newLocal(m_isolate); }
    const WrapperTypeInfo* wrapperType() { return m_wrapperType; }

private:
    CustomElementBinding(v8::Isolate*, v8::Handle<v8::Object> prototype, const WrapperTypeInfo*);

    v8::Isolate* m_isolate;
    ScopedPersistent<v8::Object> m_prototype;
    const WrapperTypeInfo* m_wrapperType;
};

}

#endif // CustomElementBinding_h
