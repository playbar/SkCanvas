#ifndef V8ObjectConstructor_h
#define V8ObjectConstructor_h

#include "V8PerIsolateData.h"

#include <include/v8.h>

namespace Canvas2D
{

class Document;

class ConstructorMode {
public:
    enum Mode {
        WrapExistingObject,
        CreateNewObject
    };

    ConstructorMode()
    {
        V8PerIsolateData* data = V8PerIsolateData::current();
        m_previous = data->m_constructorMode;
        data->m_constructorMode = WrapExistingObject;
    }

    ~ConstructorMode()
    {
        V8PerIsolateData* data = V8PerIsolateData::current();
        data->m_constructorMode = m_previous;
    }

    static bool current() { return V8PerIsolateData::current()->m_constructorMode; }

private:
    bool m_previous;
};

class V8ObjectConstructor {
public:
    static v8::Local<v8::Object> newInstance(v8::Handle<v8::Function>);
    static v8::Local<v8::Object> newInstance(v8::Handle<v8::ObjectTemplate>);
    static v8::Local<v8::Object> newInstance(v8::Handle<v8::Function>, int, v8::Handle<v8::Value> argv[]);
    //static v8::Local<v8::Object> newInstanceInDocument(v8::Handle<v8::Function>, int, v8::Handle<v8::Value> argv[], Document*);

    static void isValidConstructorMode(const v8::FunctionCallbackInfo<v8::Value>&);
};

} // namespace WebCore

#endif // V8ObjectConstructor_h
