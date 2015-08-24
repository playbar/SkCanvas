#include "JSEngine.h"
#include "JSCore.h"
#include "SkTypes.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map"

#include <include/v8.h>
#include <include/libplatform/libplatform.h>
using namespace v8;

#define UPDATE_GAME_SCOPE "updateGameScope"
#define UPDATE_GAME_NAME "updateGameName"


#define EGRET_GAME_ROOT "egret-game"
#ifndef EGRET_RUNTIME
#	define GAME_LOADER "C:/tmp/egret-game/launcher/shellTest.js"
#else
#	define GAME_LOADER "launcher/runtime_loader.js"
#endif /* EGRET_RUNTIME */

static std::map<std::string, Local<String> > stringMap;
typedef std::map<std::string, Local<String> >::iterator mspit;


Local<String> getString(const char *name) {
	mspit it = stringMap.find(name);
	if (it != stringMap.end()) {
		return it->second;
	}
	stringMap[name] = v8_str(name);// Persistent<String>::New(String::New(name));
	return stringMap[name];
}

void clearStringMap(void)
{
	stringMap.clear();
}

const char * toCString(const String::Utf8Value& value)
{
	return *value ? *value : "<string conversion failed>";
}

JSEngine::JSEngine()
{
	V8::InitializeICU();
	mPlatform = v8::platform::CreateDefaultPlatform();
	V8::InitializePlatform(mPlatform);
	V8::Initialize();
}

JSEngine::~JSEngine()
{
	V8::Dispose();
	V8::ShutdownPlatform();
	delete mPlatform;
}


void JSEngine::init()
{

	// Create a new Isolate and make it the current one.

	create_params.array_buffer_allocator = &allocator;
	mIsolate = Isolate::New(create_params);
	Isolate::Scope isolate_scope(mIsolate);
	// Create a stack-allocated handle scope.
	HandleScope handle_scope(mIsolate);
	//LocalContext localConext(mIsolate);
	//Local<Context> context = localConext.local();
	//Local<Context> context = Context::New(mIsolate, NULL, v8::Handle<v8::ObjectTemplate>());
	Local<Context> context = CreateShellContext(mIsolate);
	mContext.Reset(mIsolate, context);
	context->Enter();
	//mContext.Reset(mIsolate, context);
	Local<Object > global = context->Global();

	setGlobalFun(global);
	Local<Value> val = context->Global()->Get(v8_str("egret"));
	Local<v8::Object> native = Local<Object>::Cast(val);
	setClassInterface(native);
	
	//Local<v8::Object> native = Local<Object>::Cast(context->Global()->Get(v8_str("egret")));
	
	

	Context::Scope context_scope(context);

	v8::Local<v8::String> file_name =
		v8::String::NewFromUtf8(mIsolate, GAME_LOADER, v8::NewStringType::kNormal)
		.ToLocalChecked();
	v8::Local<v8::String> source;
	if (!ReadFile(mIsolate, GAME_LOADER).ToLocal(&source)) 
	{
		fprintf(stderr, "Error reading '%s'\n", GAME_LOADER);
		return;
	}
	if (!ExecuteString(mIsolate, source, file_name, true, true))
		return;


}

void JSEngine::uninit()
{
	v8::Local<v8::Context>::New(mIsolate, mContext)->Exit();
	mContext.Reset();

	mIsolate->Dispose();
}

void JSEngine::update()
{

}

void JSEngine::render()
{

}

void JSEngine::SetNativeObject()
{

}

void JSEngine::setOnUpdateGame(Handle<Value> update, Handle<Value> owner)
{
	if (update->IsFunction() && owner->IsObject()) 
	{
		Local<Context> context = Local<Context>::New(mIsolate, mContext);
		HandleScope handle_scope(mIsolate);
		Local<Object> global = context->Global();
		Local<Object> gameScope = owner->ToObject();
		gameScope->Set(getString(UPDATE_GAME_NAME), update);
		global->Set(getString(UPDATE_GAME_SCOPE), gameScope);
		canUpdateGame = true;
	}
}

void JSEngine::reportException(TryCatch& try_catch)
{
	HandleScope handle_scope(mIsolate);
	String::Utf8Value exception(try_catch.Exception());
	const char* exception_string = toCString(exception);
	Handle<Message> message = try_catch.Message();

	if (!message.IsEmpty()) {
		String::Utf8Value filename(message->GetScriptResourceName());
		const char* filename_string = toCString(filename);
		int linenum = message->GetLineNumber();
		String::Utf8Value sourceline(message->GetSourceLine());
		SkDebugf("%s:%d : %s", filename_string, linenum, exception_string);
	}

}

Handle<Value> JSEngine::callFunction(Handle<Function> func, Handle<Object> scope, int argc, Handle<Value> *argv)
{
	TryCatch tryCatch;
	Handle<Value> result = func->Call(scope, argc, argv);
	if (tryCatch.HasCaught()) {
		reportException(tryCatch);
	}
	return result;
}

Handle<Value> JSEngine::onFunction(const char *root, const char *name, int argc, Handle<Value> argv[])
{
	Local<Context> context = Local<Context>::New(mIsolate, mContext);
	Context::Scope context_scope(context);
	context->Enter();

	Handle<Object> scope = context->Global();
	if (scope.IsEmpty()) {
		SkDebugf("%s: %s is undefined", __FUNCTION__, root);
	}
	Local<Function> func = Local<Function>::Cast(scope->Get(getString(name)));
	if (func.IsEmpty()) {
		SkDebugf("%s: %s.%s is undefined", __FUNCTION__, root, name);
	}
	return callFunction(func, scope, argc, argv);
}

static void v8_Log(const v8::FunctionCallbackInfo<v8::Value> & args)
{
	if ( args.Length() < 1 )
	{
		return;
	}
	HandleScope scope(args.GetIsolate());
	Local<Value> arg = args[0];
	String::Utf8Value value(arg);
	std::string str = *value;
}

Handle<ObjectTemplate> JSEngine::setGlobalFunctions()
{
	Handle<ObjectTemplate> result = ObjectTemplate::New(mIsolate);
	result->Set(String::NewFromUtf8(mIsolate, "log", NewStringType::kNormal).ToLocalChecked(), Function::New(mIsolate, v8_Log));
	
	return result;
}

void infoAA(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	int i = 0;
	i++;
}

void JSEngine::setGlobalFun( Local<Object> parent )
{
	v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(mIsolate);
	global->Set(
		v8::String::NewFromUtf8(mIsolate, "info", v8::NewStringType::kNormal).ToLocalChecked(),
		v8::FunctionTemplate::New(mIsolate, infoAA));

	parent->Set(String::NewFromUtf8(mIsolate,"egret"), global->NewInstance());
	return;
}

void testAAA(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	int i = 0;
	i++;
}


void JSEngine::setClassInterface(Local<Object> parent)
{
	//HandleScope handle_scope(mIsolate);
	Local<Context> context = Local<Context>::New(v8::Isolate::GetCurrent(), mContext);
	//context->Enter();
	//v8::Context::Scope scope(context);
	//Local<v8::Object> native = Local<Object>::Cast(parent->Get(v8_str("egret")));
	v8::Local<v8::FunctionTemplate> testclass = v8::FunctionTemplate::New(v8::Isolate::GetCurrent());
	testclass->SetClassName(String::NewFromUtf8(mIsolate,"test"));
	Handle<ObjectTemplate> temp_proto = testclass->PrototypeTemplate();
	temp_proto->Set(v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), "testAAA", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(v8::Isolate::GetCurrent(), testAAA));
	Handle<ObjectTemplate> test_inst = testclass->InstanceTemplate();
	test_inst->SetInternalFieldCount(1);

	parent->Set(context, String::NewFromUtf8(v8::Isolate::GetCurrent(), "test"), testclass->GetFunction());
	return;
}

