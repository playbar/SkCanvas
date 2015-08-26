#include "V8CanvasGradient.h"
#include "WrapperTypeInfo.h"
#include "DOMDataStore.h"
#include "V8DOMWrapper.h"
#include "ScriptWrappable.h"

const WrapperTypeInfo V8CanvasGradient::wrapperTypeInfo =
{
	kEmbedderBlink, 
	V8CanvasGradient::domTemplate,
	V8CanvasGradient::derefObject, 0, 0, 0,
	V8CanvasGradient::installPerContextEnabledMethods, 0, 
	WrapperTypeObjectPrototype, false 
};

void v8_CanvasGradient_addColorStop(const FunctionCallbackInfo<Value> &args)
{

}

void CanvasGradientCallBack(const FunctionCallbackInfo<Value> &args)
{

}

v8::Handle<v8::Object> V8CanvasGradient::createWrapper(PassRefPtr<CanvasGradient> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	SkASSERT(impl);
	//SkASSERT(!DOMDataStore::containsWrapper<V8CanvasGradient>(impl.get(), isolate));

	v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
	if (wrapper.IsEmpty())
		return wrapper;

	installPerContextEnabledProperties(wrapper, impl.get(), isolate);
	V8DOMWrapper::associateObjectWithWrapper<V8CanvasGradient>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
	return wrapper;
}

v8::Handle<v8::FunctionTemplate> V8CanvasGradient::domTemplate(v8::Isolate* isolate)
{
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, CanvasGradientCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasGradient_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}


Handle<FunctionTemplate> CanvasGradient_Class(Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, CanvasGradientCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasGradient_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}

void setCanvasGradientClass(Local<Object> parent, Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = CanvasGradient_Class(isolate);
	parent->Set(String::NewFromUtf8(isolate, "canvasgradient"), temp_class->GetFunction());

}
