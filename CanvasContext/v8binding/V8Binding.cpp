#include "V8Binding.h"

v8::Local<v8::Object> createWrapper(v8::Handle<v8::Object> creationContext, const WrapperTypeInfo* type, void* impl, v8::Isolate* isolate)
{
	V8WrapperInstantiationScope scope(creationContext, isolate);

	V8PerContextData* perContextData = V8PerContextData::from(scope.context());
	v8::Local<v8::Object> wrapper = perContextData ? perContextData->createWrapperFromCache(type) : V8ObjectConstructor::newInstance(type->domTemplate(isolate)->GetFunction());

	if (type == &V8HTMLDocument::wrapperTypeInfo && !wrapper.IsEmpty())
		wrapper = wrapInShadowTemplate(wrapper, static_cast<Node*>(impl), isolate);

	return wrapper;
}

