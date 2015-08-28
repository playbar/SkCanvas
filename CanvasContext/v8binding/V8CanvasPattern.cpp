#include "V8CanvasPattern.h"
#include "WrapperTypeInfo.h"
#include "DOMDataStore.h"
#include "V8DOMWrapper.h"
#include "ScriptWrappable.h"
#include "V8PerIsolateData.h"
#include "V8ObjectConstructor.h"
#include "JSCore.h"

const WrapperTypeInfo V8CanvasPattern::wrapperTypeInfo =
{
	kEmbedderBlink, 
	V8CanvasPattern::domTemplate,
	V8CanvasPattern::derefObject, 0, 0, 0,
	V8CanvasPattern::installPerContextEnabledMethods, 0,
	WrapperTypeObjectPrototype, false 
};

CanvasPattern* UnwrapCanvasGradient(Local<Object> obj)
{
	Local<External> field = Local<External>::Cast(obj->GetInternalField(0));
	void* ptr = field->Value();
	return static_cast<CanvasPattern*>(ptr);
}

//void v8_CanvasGradient_addColorStop(const FunctionCallbackInfo<Value> &args)
//{
//	CanvasGradient* imp = V8CanvasGradient::toNative(args.Holder());
//	float offset = static_cast<float>(args[0]->NumberValue());
//	v8::String::Utf8Value str(args[1]);
//	const char* cstr = ToCString(str);
//	imp->addColorStop(offset, cstr);
//
//}

void CanvasGradientCallBack(const FunctionCallbackInfo<Value> &args)
{

}

v8::Handle<v8::Object> V8CanvasPattern::createWrapper(PassRefPtr<CanvasPattern> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	SkASSERT(impl);
	v8::Context::Scope scope(isolate->GetCurrentContext());
	v8::Handle<v8::Object> wrapper = V8CanvasPattern::domTemplate(isolate)->GetFunction()->NewInstance();
	if (wrapper.IsEmpty())
		return wrapper;

	wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, impl.leakRef());

	return wrapper;
}

v8::Handle<v8::FunctionTemplate> V8CanvasPattern::domTemplate(v8::Isolate* isolate)
{
	V8PerIsolateData *data = V8PerIsolateData::from(isolate);
	v8::Local<v8::FunctionTemplate> temp_class = data->existingDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo));
	if (!temp_class.IsEmpty())
	{
		return temp_class;
	}
	temp_class = FunctionTemplate::New(isolate, CanvasGradientCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	//temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasGradient_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	data->setDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), temp_class);
	return temp_class;
}


Handle<FunctionTemplate> CanvasPattern_Class(Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, CanvasGradientCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasGradient_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}

void setCanvasPatternClass(Local<Object> parent, Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = CanvasPattern_Class(isolate);
	parent->Set(String::NewFromUtf8(isolate, "canvasgradient"), temp_class->GetFunction());

}
