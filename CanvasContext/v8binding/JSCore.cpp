#include "JSCore.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <include/v8.h>
#include <include/libplatform/libplatform.h>
using namespace v8;


JSCore::JSCore()
{

}

JSCore::~JSCore()
{

}


void JSCore::init()
{
	V8::InitializeICU();
	platform = v8::platform::CreateDefaultPlatform();
	V8::InitializePlatform(platform);
	V8::Initialize();

	// Create a new Isolate and make it the current one.

	create_params.array_buffer_allocator = &allocator;
	isolate = Isolate::New(create_params);
	Isolate::Scope isolate_scope(isolate);
	// Create a stack-allocated handle scope.
	HandleScope handle_scope(isolate);
	Local<Context> context = Context::New(isolate);
	mContext.Reset(isolate, context);
}

void JSCore::uninit()
{
	isolate->Dispose();
	V8::Dispose();
	V8::ShutdownPlatform();
	delete platform;
}

void JSCore::update()
{
	Isolate::Scope isolate_scope(isolate);
	HandleScope handle_scope(isolate);

	Local<Context> context =Local<Context>::New(isolate, mContext);
	Context::Scope context_scope(context);

	// Create a string containing the JavaScript source code.
	Local<String> source =
		String::NewFromUtf8(isolate, "'Hello' + ', World!'",
		NewStringType::kNormal).ToLocalChecked();

	// Compile the source code.
	Local<Script> script = Script::Compile(context, source).ToLocalChecked();

	// Run the script to get the result.
	Local<Value> result = script->Run(context).ToLocalChecked();

	// Convert the result to an UTF8 string and print it.
	String::Utf8Value utf8(result);

}

void JSCore::render()
{

}

void JSCore::SetNativeObject()
{

}

