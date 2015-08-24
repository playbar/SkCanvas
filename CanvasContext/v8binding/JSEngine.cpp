#include "JSEngine.h"
#include "JSCore.h"
#include "SkTypes.h"
#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map"
#include "JSCore.h"
#include "V8GlobalFun.h"

#include <include/v8.h>
#include <include/libplatform/libplatform.h>
using namespace v8;

#define UPDATE_GAME_SCOPE "updateGameScope"
#define UPDATE_GAME_NAME "updateGameName"
#define EGRET_GAME_ROOT "egret-game"
#ifndef EGRET_RUNTIME
#	define GAME_LOADER "C:/tmp/egret-game/launcher/native_loader.js"
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

JSEngine::JSEngine()
{
	V8::InitializeICU();
	mPlatform = v8::platform::CreateDefaultPlatform();
	V8::InitializePlatform(mPlatform);
	V8::Initialize();
	create_params.array_buffer_allocator = &allocator;
	mIsolate = Isolate::New(create_params);
}

JSEngine::~JSEngine()
{
	V8::Dispose();
	V8::ShutdownPlatform();
	delete mPlatform;
}


void JSEngine::init()
{
	Isolate::Scope isolate_scope(mIsolate);
	HandleScope handle_scope(mIsolate);
	Local<Context> context = CreateShellContext(mIsolate);
	mContext.Reset(mIsolate, context);
	context->Enter();
	Local<Object > global = context->Global();
	V8SetGlobalFun(global);

	Local<v8::Object> native = Local<Object>::Cast(context->Global()->Get(v8_str("egret")));
	setClassInterface(native);
	
	RunJavaScript(GAME_LOADER);

	onFunction("egret", "egtMain", 0, NULL);
	//Local<Value> val = Local<Value>::New(mIsolate, String::NewFromUtf8(mIsolate, "egtMain"));
	//Local<Function> func = Local<Function>::Cast(native->Get( val));
	//callFunction(func, native, 0, NULL);
}

void JSEngine::uninit()
{
	v8::Local<v8::Context>::New(mIsolate, mContext)->Exit();
	mContext.Reset();
	mIsolate->Dispose();
}

void JSEngine::update(float elapsedTime )
{
	Isolate::Scope isolate_scope(mIsolate);
	HandleScope handle_scope(mIsolate);
	Local<Context> context = Local<Context>::New(mIsolate, mContext);
	context->Enter();	
	
	Handle<Value> argv[] = { v8_num(elapsedTime) };
	onFunction("egret", "executeMainLoop", 1, argv );
}

void JSEngine::render(float elapsedTime)
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


Handle<Value> JSEngine::callFunction(Handle<Function> func, Handle<Object> scope, int argc, Handle<Value> *argv)
{
	TryCatch tryCatch;
	Handle<Value> result = func->Call(scope, argc, argv);
	if (tryCatch.HasCaught()) {
		ReportException(tryCatch);
	}
	return result;
}

Handle<Value> JSEngine::onFunction(const char *root, const char *name, int argc, Handle<Value> argv[])
{
	Local<Context> context = Local<Context>::New(mIsolate, mContext);
	Context::Scope context_scope(context);
	context->Enter();

	Local<Value> val = Local<Value>::New(mIsolate, String::NewFromUtf8(mIsolate, root));
	Handle<Object> scope = context->Global()->Get(val)->ToObject();
	if (scope.IsEmpty()) {
		SkDebugf("%s: %s is undefined", __FUNCTION__, root);
	}
	Local<Value> valName = Local<Value>::New(mIsolate, String::NewFromUtf8(mIsolate, name));
	Local<Function> func = Local<Function>::Cast(scope->Get(valName));
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

