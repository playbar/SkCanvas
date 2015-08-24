#include "V8GlobalFun.h"
#include "JSCore.h"
#include "SkTypes.h"

void v8_console_log(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	HandleScope handleScope( v8::Isolate::GetCurrent());
	if ( args.Length() < 1)
	{

	}

	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	SkDebugf(cstr);
	return;
}

void infoAA(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	int i = 0;
	i++;
}


void V8SetGlobalFun(Local<Object> parent)
{
	Isolate *isolate = v8::Isolate::GetCurrent();
	v8::Local<ObjectTemplate> console = v8::ObjectTemplate::New();
	console->Set(String::NewFromUtf8(isolate, "log", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_console_log));
	
	parent->Set(String::NewFromUtf8(isolate, "console"), console->NewInstance());
	//////////////////////////////////////////////////////////////////////////

	v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
	global->Set(v8::String::NewFromUtf8(isolate, "info", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, infoAA));
	parent->Set(String::NewFromUtf8(isolate, "egret"), global->NewInstance());
	return;
}

