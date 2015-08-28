#include "V8ImageData.h"
#include "WrapperTypeInfo.h"
#include "DOMDataStore.h"
#include "V8DOMWrapper.h"
#include "ScriptWrappable.h"
#include "V8PerIsolateData.h"
#include "V8ObjectConstructor.h"
#include "JSCore.h"

const WrapperTypeInfo V8ImageData::wrapperTypeInfo =
{
	kEmbedderBlink, 
	V8ImageData::domTemplate,
	V8ImageData::derefObject, 0, 0, 0,
	V8ImageData::installPerContextEnabledMethods, 0,
	WrapperTypeObjectPrototype, false 
};

ImageData* UnwrapCanvasGradient(Local<Object> obj)
{
	Local<External> field = Local<External>::Cast(obj->GetInternalField(0));
	void* ptr = field->Value();
	return static_cast<ImageData*>(ptr);
}

void v8_ImageData_addColorStop(const FunctionCallbackInfo<Value> &args)
{
	//ImageData* imp = V8ImageData::toNative(args.Holder());
	//float offset = static_cast<float>(args[0]->NumberValue());
	//v8::String::Utf8Value str(args[1]);
	//const char* cstr = ToCString(str);
	//imp->addColorStop(offset, cstr);

}

void ImageDataCallBack(const FunctionCallbackInfo<Value> &args)
{

}

v8::Handle<v8::Object> V8ImageData::createWrapper(PassRefPtr<ImageData> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	SkASSERT(impl);
	//SkASSERT(!DOMDataStore::containsWrapper<V8CanvasGradient>(impl.get(), isolate));
	v8::Context::Scope scope(isolate->GetCurrentContext());

	//int argc = 1;
	//Handle<Integer> mval = Integer::NewFromUnsigned(isolate, reinterpret_cast<uintptr_t>(impl.get()));
	//Handle<Value> argv[] = { mval };
	v8::Handle<v8::Object> wrapper = V8ImageData::domTemplate(isolate)->GetFunction()->NewInstance();
	if (wrapper.IsEmpty())
		return wrapper;

	wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, impl.leakRef());

	return wrapper;
}

v8::Handle<v8::FunctionTemplate> V8ImageData::domTemplate(v8::Isolate* isolate)
{
	V8PerIsolateData *data = V8PerIsolateData::from(isolate);
	v8::Local<v8::FunctionTemplate> temp_class = data->existingDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo));
	if (!temp_class.IsEmpty())
	{
		return temp_class;
	}
	temp_class = FunctionTemplate::New(isolate, ImageDataCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_ImageData_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	data->setDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), temp_class);
	return temp_class;
}


Handle<FunctionTemplate> ImageData_Class(Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, ImageDataCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvasgradient"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "addColorStop", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_ImageData_addColorStop));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}

void setImageDataClass(Local<Object> parent, Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = ImageData_Class(isolate);
	parent->Set(String::NewFromUtf8(isolate, "canvasgradient"), temp_class->GetFunction());

}
