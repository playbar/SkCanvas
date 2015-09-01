#ifndef __CANVASGRADIENT_H__
#define __CANVASGRADIENT_H__


#include "passrefptr.h"
#include "ImageData.h"
#include "V8Binding.h"
#include "WrapperTypeInfo.h"
#include "include/v8.h"
using namespace v8;
using namespace Canvas2D;

class V8ImageData
{
public:
	static const WrapperTypeInfo wrapperTypeInfo;
	static void derefObject(void*){};
	static v8::Handle<v8::Object> createWrapper(PassRefPtr<ImageData> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate);
	static void installPerContextEnabledProperties(v8::Handle<v8::Object>, ImageData *, v8::Isolate*) { }
	static void installPerContextEnabledMethods(v8::Handle<v8::Object>, v8::Isolate*) { }
	static v8::Handle<v8::FunctionTemplate> domTemplate(v8::Isolate*);
	static inline void* toInternalPointer(ImageData * impl)
	{
		return impl;
	}

	static ImageData * toNative(v8::Handle<v8::Object> object)
	{
		return fromInternalPointer(object->GetAlignedPointerFromInternalField(v8DOMWrapperTypeIndex));
	}
	static ImageData *toNative(v8::Handle<v8::Value> value)
	{
		return fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex));
	}
	static inline ImageData * fromInternalPointer(void* object)
	{
		return static_cast<ImageData *>(object);
	}
};

//template<class CallbackInfo>
//inline void v8SetReturnValue(const CallbackInfo& callbackInfo, PassRefPtr<ImageData> impl)
//{
//	v8SetReturnValue(callbackInfo, impl.get());
//}

template<typename CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, ImageData* impl)
{
	if (!impl) 
	{
		v8SetReturnValueNull(callbackInfo);
		return;
	}
	//v8::Handle<v8::Object> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	v8::Handle<v8::Object> wrapper = V8ImageData::createWrapper(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	v8SetReturnValue(callbackInfo, wrapper);
	return;
}

inline v8::Handle<v8::Value> toV8(ImageData  *imp, v8::Handle<v8::Object> createContext, v8::Isolate *isolate)
{
	v8::Handle<v8::Object> wrapper = V8ImageData::createWrapper(imp, createContext, isolate);
	return wrapper;
}

Handle<FunctionTemplate> ImageData_Class(Isolate *isolate);
void setImageDataClass(Local<Object> parent, Isolate *isolate);


#endif

