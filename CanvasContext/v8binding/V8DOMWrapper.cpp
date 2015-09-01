#include "V8DOMWrapper.h"
#include "WrapperTypeInfo.h"

//#include "V8HTMLCollection.h"
//#include "V8HTMLDocument.h"
//#include "V8Window.h"
//#include "bindings/v8/V8Binding.h"
#include "V8ObjectConstructor.h"
#include "V8PerContextData.h"
//#include "bindings/v8/V8ScriptRunner.h"

namespace Canvas2D {

//static v8::Local<v8::Object> wrapInShadowTemplate(v8::Local<v8::Object> wrapper, Node* impl, v8::Isolate* isolate)
//{
//    static int shadowTemplateKey; // This address is used for a key to look up the dom template.
//    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
//    v8::Handle<v8::FunctionTemplate> shadowTemplate = data->existingDOMTemplate(&shadowTemplateKey);
//    if (shadowTemplate.IsEmpty()) {
//        shadowTemplate = v8::FunctionTemplate::New(isolate);
//        if (shadowTemplate.IsEmpty())
//            return v8::Local<v8::Object>();
//        shadowTemplate->SetClassName(v8AtomicString(isolate, "HTMLDocument"));
//        shadowTemplate->Inherit(V8HTMLDocument::domTemplate(isolate));
//        shadowTemplate->InstanceTemplate()->SetInternalFieldCount(V8HTMLDocument::internalFieldCount);
//        data->setDOMTemplate(&shadowTemplateKey, shadowTemplate);
//    }
//
//    v8::Local<v8::Function> shadowConstructor = shadowTemplate->GetFunction();
//    if (shadowConstructor.IsEmpty())
//        return v8::Local<v8::Object>();
//
//    v8::Local<v8::Object> shadow = V8ScriptRunner::instantiateObject(shadowConstructor);
//    if (shadow.IsEmpty())
//        return v8::Local<v8::Object>();
//    shadow->SetPrototype(wrapper);
//    V8DOMWrapper::setNativeInfo(wrapper, &V8HTMLDocument::wrapperTypeInfo, impl);
//    return shadow;
//}

v8::Local<v8::Object> V8DOMWrapper::createWrapper(v8::Handle<v8::Object> creationContext, const WrapperTypeInfo* type, void* impl, v8::Isolate* isolate)
{
    V8WrapperInstantiationScope scope(creationContext, isolate);

    V8PerContextData* perContextData = V8PerContextData::from(scope.context());
    v8::Local<v8::Object> wrapper = perContextData ? perContextData->createWrapperFromCache(type) : V8ObjectConstructor::newInstance(type->domTemplate(isolate)->GetFunction());

    //if ( !wrapper.IsEmpty())
    //    wrapper = wrapInShadowTemplate(wrapper, static_cast<Node*>(impl), isolate);

    return wrapper;
}

bool V8DOMWrapper::isDOMWrapper(v8::Handle<v8::Value> value)
{
    if (value.IsEmpty() || !value->IsObject())
        return false;

    if (v8::Handle<v8::Object>::Cast(value)->InternalFieldCount() < v8DefaultWrapperInternalFieldCount)
        return false;

    v8::Handle<v8::Object> wrapper = v8::Handle<v8::Object>::Cast(value);
    SkASSERT(wrapper->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex));
    SkASSERT(wrapper->GetAlignedPointerFromInternalField(v8DOMWrapperTypeIndex));

    const WrapperTypeInfo* typeInfo = static_cast<const WrapperTypeInfo*>(wrapper->GetAlignedPointerFromInternalField(v8DOMWrapperTypeIndex));
    // FIXME: We should add a more strict way to check if the typeInfo is a typeInfo of some DOM wrapper.
    // Even if it's a typeInfo of Blink, it's not guaranteed that it's a typeInfo of a DOM wrapper.
    return typeInfo->ginEmbedder == kEmbedderBlink;
}

}  // namespace WebCore
