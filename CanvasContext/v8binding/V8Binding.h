#ifndef V8Binding_h
#define V8Binding_h

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

#endif // V8Binding_h
