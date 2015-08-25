#include "CanvasGradient_v8.h"

void v8_CanvasGradient_addColorStop(const FunctionCallbackInfo<Value> &args)
{

}

void CanvasGradientCallBack(const FunctionCallbackInfo<Value> &args)
{

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
