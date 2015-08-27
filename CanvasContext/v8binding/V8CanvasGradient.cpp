#include "V8CanvasGradient.h"
#include "WrapperTypeInfo.h"
#include "DOMDataStore.h"
#include "V8DOMWrapper.h"
#include "ScriptWrappable.h"
#include "V8PerIsolateData.h"
#include "V8ObjectConstructor.h"
#include "JSCore.h"

const WrapperTypeInfo V8CanvasGradient::wrapperTypeInfo =
{
	kEmbedderBlink, 
	V8CanvasGradient::domTemplate,
	V8CanvasGradient::derefObject, 0, 0, 0,
	V8CanvasGradient::installPerContextEnabledMethods, 0, 
	WrapperTypeObjectPrototype, false 
};

CanvasGradient* UnwrapCanvasGradient(Local<Object> obj)
{
	Local<External> field = Local<External>::Cast(obj->GetInternalField(0));
	void* ptr = field->Value();
	return static_cast<CanvasGradient*>(ptr);
}

void v8_CanvasGradient_addColorStop(const FunctionCallbackInfo<Value> &args)
{
	CanvasGradient* imp = V8CanvasGradient::toNative(args.Holder());
	float offset = static_cast<float>(args[0]->NumberValue());
	v8::String::Utf8Value str(args[1]);
	const char* cstr = ToCString(str);
	imp->addColorStop(offset, cstr);

}

void CanvasGradientCallBack(const FunctionCallbackInfo<Value> &args)
{

}

v8::Handle<v8::Object> V8CanvasGradient::createWrapper(PassRefPtr<CanvasGradient> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	SkASSERT(impl);
	//SkASSERT(!DOMDataStore::containsWrapper<V8CanvasGradient>(impl.get(), isolate));
	v8::Context::Scope scope(isolate->GetCurrentContext());

	int argc = 1;
	Handle<Integer> mval = Integer::NewFromUnsigned(isolate, reinterpret_cast<uintptr_t>(impl.get()));
	Handle<Value> argv[] = { mval };
	v8::Handle<v8::Object> wrapper = V8CanvasGradient::domTemplate(isolate)->GetFunction()->NewInstance(argc, argv);
	if (wrapper.IsEmpty())
		return wrapper;

	wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, impl.leakRef());

	return wrapper;
}

//void v8SetReturnValue(const v8::FunctionCallbackInfo<v8::Value> &args, CanvasGradient*impl)
//{
//	Isolate *isolate = args.GetIsolate();
//	int argc = 1;
//	Handle<Integer> mval = Integer::NewFromUnsigned(isolate, reinterpret_cast<uintptr_t>(impl));
//	Handle<Value> argv[] = { mval };
//	//v8::Handle<v8::Object> wrapper = V8ObjectConstructor::newInstance(V8CanvasGradient::domTemplate(isolate)->GetFunction(), argc, argv );
//	v8::Handle<v8::Object> wrapper = V8CanvasGradient::domTemplate(isolate)->GetFunction()->NewInstance(argc, argv);
//
//	wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, impl);
//}

v8::Handle<v8::FunctionTemplate> V8CanvasGradient::domTemplate(v8::Isolate* isolate)
{
	V8PerIsolateData *data = V8PerIsolateData::from(isolate);
	v8::Local<v8::FunctionTemplate> result = data->existingDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo));
	if ( !result.IsEmpty())
	{
		return result;
	}
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, CanvasGradientCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasGradient_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	data->setDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), temp_class);
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
