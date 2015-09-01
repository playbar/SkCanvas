#include "V8ObjectConstructor.h"

#include "V8Binding.h"
#include "V8ScriptRunner.h"

namespace Canvas2D
{

v8::Local<v8::Object> V8ObjectConstructor::newInstance(v8::Handle<v8::Function> function)
{
    if (function.IsEmpty())
        return v8::Local<v8::Object>();
    ConstructorMode constructorMode;
    return V8ScriptRunner::instantiateObject(function);
}

v8::Local<v8::Object> V8ObjectConstructor::newInstance(v8::Handle<v8::ObjectTemplate> objectTemplate)
{
    if (objectTemplate.IsEmpty())
        return v8::Local<v8::Object>();
    ConstructorMode constructorMode;
    return V8ScriptRunner::instantiateObject(objectTemplate);
}

v8::Local<v8::Object> V8ObjectConstructor::newInstance(v8::Handle<v8::Function> function, int argc, v8::Handle<v8::Value> argv[])
{
    if (function.IsEmpty())
        return v8::Local<v8::Object>();
    ConstructorMode constructorMode;
    return V8ScriptRunner::instantiateObject(function, argc, argv);
}

//v8::Local<v8::Object> V8ObjectConstructor::newInstanceInDocument(v8::Handle<v8::Function> function, int argc, v8::Handle<v8::Value> argv[], Document* document)
//{
//    if (function.IsEmpty())
//        return v8::Local<v8::Object>();
//    return V8ScriptRunner::instantiateObjectInDocument(function, document, argc, argv);
//}

//void V8ObjectConstructor::isValidConstructorMode(const v8::FunctionCallbackInfo<v8::Value>& info)
//{
//    if (ConstructorMode::current() == ConstructorMode::CreateNewObject) {
//        return;
//    }
//    v8SetReturnValue(info, info.This());
//}

} // namespace WebCore
