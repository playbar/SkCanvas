#include "V8BitmapImage.h"
#include "WrapperTypeInfo.h"
#include "DOMDataStore.h"
#include "V8DOMWrapper.h"
#include "ScriptWrappable.h"
#include "V8PerIsolateData.h"
#include "V8ObjectConstructor.h"
#include "JSCore.h"

const WrapperTypeInfo V8BitmapImage::wrapperTypeInfo =
{
	kEmbedderBlink,
	V8BitmapImage::domTemplate,
	V8BitmapImage::derefObject, 0, 0, 0,
	V8BitmapImage::installPerContextEnabledMethods, 0,
	WrapperTypeObjectPrototype, false
};

BitmapImage* UnwrapBitmapImage(Local<Object> obj)
{
	Local<External> field = Local<External>::Cast(obj->GetInternalField(0));
	void* ptr = field->Value();
	return static_cast<BitmapImage*>(ptr);
}

void v8_BitmapImage_src(const FunctionCallbackInfo<Value> &args)
{
	BitmapImage* imp = UnwrapBitmapImage(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	imp->src( cstr);

}

void BitmapImageCallBack(const FunctionCallbackInfo<Value> &args)
{
	BitmapImage* pImage = new BitmapImage();
	Local<Object> object = args.This();
	Local<External> map_ptr = External::New(Isolate::GetCurrent(), pImage);
	object->SetInternalField(0, map_ptr);
}

v8::Handle<v8::Object> V8BitmapImage::createWrapper(PassRefPtr<BitmapImage> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	SkASSERT(impl);
	v8::Context::Scope scope(isolate->GetCurrentContext());
	v8::Handle<v8::Object> wrapper = V8BitmapImage::domTemplate(isolate)->GetFunction()->NewInstance();
	if (wrapper.IsEmpty())
		return wrapper;

	wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, impl.leakRef());

	return wrapper;
}

v8::Handle<v8::FunctionTemplate> V8BitmapImage::domTemplate(v8::Isolate* isolate)
{
	V8PerIsolateData *data = V8PerIsolateData::from(isolate);
	v8::Local<v8::FunctionTemplate> temp_class = data->existingDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo));
	if (!temp_class.IsEmpty())
	{
		return temp_class;
	}
	temp_class = FunctionTemplate::New(isolate, BitmapImageCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "Image"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "src", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_BitmapImage_src));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	data->setDOMTemplate(const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), temp_class);
	return temp_class;
}


Handle<FunctionTemplate> BitmapImage_Class(Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, BitmapImageCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "Image"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "src", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_BitmapImage_src));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}

void setBitmapImageClass(Local<Object> parent, Isolate *isolate)
{
	Handle<FunctionTemplate> temp_class = BitmapImage_Class(isolate);
	parent->Set(String::NewFromUtf8(isolate, "Image"), temp_class->GetFunction());

}
