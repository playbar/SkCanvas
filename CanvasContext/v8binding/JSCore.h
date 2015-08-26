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

#ifndef snprintf
#  define snprintf _snprintf
#endif

#define EGRET_ROOT "egret"
#define EGRET_MAIN "egtMain"
#define EGRET_MAINLOOP "executeMainLoop"
#define UPDATE_GAME_SCOPE "updateGameScope"
#define UPDATE_GAME_NAME "updateGameName"

#ifndef EGRET_RUNTIME
#	define GAME_LOADER "C:/tmp/egret-game/launcher/native_loader.js"
#else
#	define GAME_LOADER "launcher/runtime_loader.js"
#endif /* EGRET_RUNTIME */


#define BEGIN_SCOPE HandleScope handle_scope( v8::Isolate::GetCurrent())
#define CHECK_ARGUMENTS(X) \
		if( args.Length() < X) {\
			SkDebugf("%s: Number of arguments isn't less than %d", __FUNCTION__, X); \
			return;\
		}

#define BEGIN_SCOPE_WHITH_ARGS( X ) \
		BEGIN_SCOPE; \
		CHECK_ARGUMENTS( X );

#define V8TRYCATCH_VOID(type, var, value)  \
    type var;                              \
    {                                      \
        v8::TryCatch block;                \
        var = (value);                     \
        if (UNLIKELY(block.HasCaught())) { \
            block.ReThrow();               \
            return;                        \
		}                                  \
    }


v8::Local<v8::Context> CreateShellContext(v8::Isolate* isolate);
bool ExecuteString(v8::Isolate* isolate, v8::Local<v8::String> source,
	v8::Local<v8::Value> name, bool print_result,
	bool report_exceptions);
bool RunJavaScript(const char *fileName);
void Print(const v8::FunctionCallbackInfo<v8::Value>& args);
void Read(const v8::FunctionCallbackInfo<v8::Value>& args);
void Load(const v8::FunctionCallbackInfo<v8::Value>& args);
void Quit(const v8::FunctionCallbackInfo<v8::Value>& args);
void Version(const v8::FunctionCallbackInfo<v8::Value>& args);
void V8_Require(const v8::FunctionCallbackInfo<v8::Value> &args);

v8::MaybeLocal<v8::String> ReadFile(v8::Isolate* isolate, const char* name);
void ReportException(v8::Isolate* isolate, v8::TryCatch* handler);

static inline v8::Local<v8::Value> v8_num(double x) {
	return v8::Number::New(v8::Isolate::GetCurrent(), x);
}

static inline v8::Local<v8::String> v8_str(const char* x) {
	return v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), x);
}

const char* ToCString(const v8::String::Utf8Value& value);

void ReportException(TryCatch& try_catch);


inline char* strnstr(const char* buffer, const char* target, size_t bufferLength)
{
	size_t targetLength = strlen(target);
	if (targetLength == 0)
		return const_cast<char*>(buffer);
	for (const char* start = buffer; *start && start + targetLength <= buffer + bufferLength; start++) {
		if (*start == *target && strncmp(start + 1, target + 1, targetLength - 1) == 0)
			return const_cast<char*>(start);
	}
	return 0;
}

//void CreateSkCanvas(int w, int h);

#endif

