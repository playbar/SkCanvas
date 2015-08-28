#ifndef __CANVASPATTERN_H__
#define __CANVASPATTERN_H__


#include "passrefptr.h"
#include "CanvasPattern.h"
#include "V8Binding.h"
#include "WrapperTypeInfo.h"
#include "include/v8.h"
using namespace v8;
using namespace Canvas2D;

class V8CanvasPattern
{
public:
	static const WrapperTypeInfo wrapperTypeInfo;
	static void derefObject(void*){};
	static v8::Handle<v8::Object> createWrapper(PassRefPtr<CanvasPattern> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate);
	static void installPerContextEnabledProperties(v8::Handle<v8::Object>, CanvasPattern*, v8::Isolate*) { }
	static void installPerContextEnabledMethods(v8::Handle<v8::Object>, v8::Isolate*) { }
	static v8::Handle<v8::FunctionTemplate> domTemplate(v8::Isolate*);
	static inline void* toInternalPointer(CanvasPattern* impl)
	{
		return impl;
	}

	static CanvasPattern* toNative(v8::Handle<v8::Object> object)
	{
		return fromInternalPointer(object->GetAlignedPointerFromInternalField(v8DOMWrapperTypeIndex));
	}
	static inline CanvasPattern* fromInternalPointer(void* object)
	{
		return static_cast<CanvasPattern*>(object);
	}
};

template<class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, PassRefPtr<CanvasGradient> impl)
{
	v8SetReturnValue(callbackInfo, impl.get());
}

template<typename CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, CanvasGradient* impl)
{
	if (!impl) 
	{
		v8SetReturnValueNull(callbackInfo);
		return;
	}
	//v8::Handle<v8::Object> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	v8::Handle<v8::Object> wrapper = V8CanvasGradient::createWrapper(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	v8SetReturnValue(callbackInfo, wrapper);
	return;
}

inline v8::Handle<v8::Value> toV8(CanvasPattern *imp, v8::Handle<v8::Object> createContext, v8::Isolate *isolate)
{
	v8::Handle<v8::Object> wrapper = V8CanvasPattern::createWrapper(imp, createContext, isolate);
	return wrapper;
}

Handle<FunctionTemplate> CanvasPattern_Class(Isolate *isolate);
void setCanvasGradientClass(Local<Object> parent, Isolate *isolate);


#endif

