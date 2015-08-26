#ifndef V8Binding_h
#define V8Binding_h

#include "SkTypes.h"
#include "include/v8.h"
using namespace v8;

template<typename CallbackInfo>
inline void v8SetReturnValueNull(const CallbackInfo& info)
{
	info.GetReturnValue().SetNull();
}

template<typename CallbackInfo, typename V>
inline void v8SetReturnValue(const CallbackInfo& info, V v)
{
	info.GetReturnValue().Set(v);
}

inline v8::Handle<v8::String> v8AtomicString(v8::Isolate* isolate, const char* str)
{
	SkASSERT(isolate);
	return v8::String::NewFromUtf8(isolate, str, v8::String::kInternalizedString, strlen(str));
}

inline v8::Handle<v8::String> v8String(v8::Isolate* isolate, const std::string& string)
{
	if (string.empty())
		return v8::String::Empty(isolate);
	return V8PerIsolateData::from(isolate)->stringCache()->v8ExternalString(string.impl(), isolate);
}

#endif // V8Binding_h
