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

static inline v8::Local<v8::String> v8_str(const char* x) {
	return v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), x);
}


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

}

JSEngine::~JSEngine()
{

}


void JSEngine::init()
{
	V8::InitializeICU();
	mPlatform = v8::platform::CreateDefaultPlatform();
	V8::InitializePlatform(mPlatform);
	V8::Initialize();

	// Create a new Isolate and make it the current one.

	create_params.array_buffer_allocator = &allocator;
	mIsolate = Isolate::New(create_params);
	Isolate::Scope isolate_scope(mIsolate);
	// Create a stack-allocated handle scope.
	HandleScope handle_scope(mIsolate);
	Local<Context> context = CreateShellContext(mIsolate);
	mContext.Reset(mIsolate, context);
	//Local<Context> context = Local<Context>::New(isolate, mContext);
	
	Context::Scope context_scope(context);
	// Create a string containing the JavaScript source code.
	//Local<String> source =
	//	String::NewFromUtf8(mIsolate, "'Hello' + ', World!'",
	//	NewStringType::kNormal).ToLocalChecked();

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
	mIsolate->Dispose();
	V8::Dispose();
	V8::ShutdownPlatform();
	delete mPlatform;
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


// Reads a file into a v8 string.
MaybeLocal<String> JSEngine::ReadFile(Isolate* isolate, const std::string& name)
{
	FILE* file = fopen(name.c_str(), "rb");
	if (file == NULL) return MaybeLocal<String>();

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	rewind(file);

	char* chars = new char[size + 1];
	chars[size] = '\0';
	for (size_t i = 0; i < size;) {
		i += fread(&chars[i], 1, size - i, file);
		if (ferror(file)) {
			fclose(file);
			return MaybeLocal<String>();
		}
	}
	fclose(file);
	MaybeLocal<String> result = String::NewFromUtf8(
		isolate, chars, NewStringType::kNormal, static_cast<int>(size));
	delete[] chars;
	return result;
}



