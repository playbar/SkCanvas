#ifndef __JSCORE_H__
#define __JSCORE_H__

#include "include/v8.h"
#include <include/libplatform/libplatform.h>
using namespace v8;

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

v8::Local<v8::Context> CreateShellContext(v8::Isolate* isolate);
void RunShell(v8::Local<v8::Context> context);
int RunMain(v8::Isolate* isolate, int argc, char* argv[]);
bool ExecuteString(v8::Isolate* isolate, v8::Local<v8::String> source,
	v8::Local<v8::Value> name, bool print_result,
	bool report_exceptions);
void Print(const v8::FunctionCallbackInfo<v8::Value>& args);
void Read(const v8::FunctionCallbackInfo<v8::Value>& args);
void Load(const v8::FunctionCallbackInfo<v8::Value>& args);
void Quit(const v8::FunctionCallbackInfo<v8::Value>& args);
void Version(const v8::FunctionCallbackInfo<v8::Value>& args);
v8::MaybeLocal<v8::String> ReadFile(v8::Isolate* isolate, const char* name);
void ReportException(v8::Isolate* isolate, v8::TryCatch* handler);

static inline v8::Local<v8::String> v8_str(const char* x) {
	return v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), x);
}



class LocalContext {
public:
	LocalContext(v8::Isolate* isolate,
		v8::ExtensionConfiguration* extensions = 0,
		v8::Handle<v8::ObjectTemplate> global_template =
		v8::Handle<v8::ObjectTemplate>(),
		v8::Handle<v8::Value> global_object = v8::Handle<v8::Value>()) {
		Initialize(isolate, extensions, global_template, global_object);
	}

	virtual ~LocalContext() {
		v8::HandleScope scope(isolate_);
		v8::Local<v8::Context>::New(isolate_, context_)->Exit();
		context_.Reset();
	}

	v8::Context* operator->() {
		return *reinterpret_cast<v8::Context**>(&context_);
	}
	v8::Context* operator*() { return operator->(); }
	bool IsReady() { return !context_.IsEmpty(); }

	v8::Local<v8::Context> local() {
		return v8::Local<v8::Context>::New(isolate_, context_);
	}

private:
	void Initialize(v8::Isolate* isolate,
		v8::ExtensionConfiguration* extensions,
		v8::Handle<v8::ObjectTemplate> global_template,
		v8::Handle<v8::Value> global_object) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Context> context = v8::Context::New(isolate,
			extensions,
			global_template,
			global_object);
		context_.Reset(isolate, context);
		context->Enter();
		// We can't do this later perhaps because of a fatal error.
		isolate_ = isolate;
	}

	v8::Persistent<v8::Context> context_;
	v8::Isolate* isolate_;
};

#endif

