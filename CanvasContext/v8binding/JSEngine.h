#ifndef __LOCALCONTEXT_H__
#define  __LOCALCONTEXT_H__

#include "memory.h"
#include "stdlib.h"
#include "string"
#include "include/v8.h"
using namespace v8;

class ShellArrayBufferAllocator : public v8::ArrayBuffer::Allocator {
public:
	virtual void* Allocate(size_t length) {
		void* data = AllocateUninitialized(length);
		return data == NULL ? data : memset(data, 0, length);
	}
	virtual void* AllocateUninitialized(size_t length) { return malloc(length); }
	virtual void Free(void* data, size_t) { free(data); }
};

class ArrayBufferAllocator : public v8::ArrayBuffer::Allocator {
public:
	virtual void* Allocate(size_t length) {
		void* data = AllocateUninitialized(length);
		return data == NULL ? data : memset(data, 0, length);
	}
	virtual void* AllocateUninitialized(size_t length) { return malloc(length); }
	virtual void Free(void* data, size_t) { free(data); }
};

class JSEngine
{
public:
	JSEngine();
	~JSEngine();
public:
	void init();
	void uninit();
	void update();
	void render();
	void SetNativeObject();

	void setOnUpdateGame(Handle<Value> update, Handle<Value> owner);
	Handle<Value> callFunction(Handle<Function> func, Handle<Object> scope, int argc, Handle<Value> *argv);
	Handle<Value> onFunction(const char *root, const char *name, int argc, Handle<Value> argv[]);
	void setGlobalFun(Local<Object> parent );
	void setClassInterface(Local<Object> parent);
public:
	Handle<ObjectTemplate> setGlobalFunctions();

public:
	v8::Platform* mPlatform;
	v8::Isolate* mIsolate;
	v8::Persistent<v8::Context> mContext;
	bool canUpdateGame;

	ArrayBufferAllocator allocator;
	v8::Isolate::CreateParams create_params;

};

#endif

