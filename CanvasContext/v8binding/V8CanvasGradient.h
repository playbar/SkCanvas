#ifndef __CANVASGRADIENT_H__
#define __CANVASGRADIENT_H__


#include "passrefptr.h"
#include "CanvasGradient.h"
#include "V8Binding.h"
#include "WrapperTypeInfo.h"
#include "include/v8.h"
using namespace v8;
using namespace Canvas2D;

class V8CanvasGradient
{
public:
	static const WrapperTypeInfo wrapperTypeInfo;
	static void derefObject(void*){};
	static v8::Handle<v8::Object> createWrapper(PassRefPtr<CanvasGradient> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate);
	static void installPerContextEnabledProperties(v8::Handle<v8::Object>, CanvasGradient*, v8::Isolate*) { }
	static void installPerContextEnabledMethods(v8::Handle<v8::Object>, v8::Isolate*) { }
	static v8::Handle<v8::FunctionTemplate> domTemplate(v8::Isolate*);
	static inline void* toInternalPointer(CanvasGradient* impl)
	{
		return impl;
	}

	static CanvasGradient* toNative(v8::Handle<v8::Object> object)
	{
		return fromInternalPointer(object->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex));
	}
	static inline CanvasGradient* fromInternalPointer(void* object)
	{
		return static_cast<CanvasGradient*>(object);
	}
};

Handle<FunctionTemplate> CanvasGradient_Class(Isolate *isolate);
void setCanvasGradientClass(Local<Object> parent, Isolate *isolate);

//void v8SetReturnValue(const v8::FunctionCallbackInfo<v8::Value> &args, CanvasGradient*impl);

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
	v8::Handle<v8::Object> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	
	v8SetReturnValue(callbackInfo, wrapper);
}

inline v8::Handle<v8::Object> wrap(CanvasGradient* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	SkASSERT(impl);
	return V8CanvasGradient::createWrapper(impl, creationContext, isolate);
}



#endif

