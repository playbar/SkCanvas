#ifndef __V8BITMAPIMAGE_H__
#define __V8BITMAPIMAGE_H__

#include "passrefptr.h"
#include "BitmapImage.h"
#include "V8Binding.h"
#include "WrapperTypeInfo.h"
#include "include/v8.h"
using namespace v8;
using namespace Canvas2D;

class V8BitmapImage
{
public:
	static const WrapperTypeInfo wrapperTypeInfo;
	static void derefObject(void*){};
	static v8::Handle<v8::Object> createWrapper(PassRefPtr<BitmapImage> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate);
	static void installPerContextEnabledProperties(v8::Handle<v8::Object>, BitmapImage*, v8::Isolate*) { }
	static void installPerContextEnabledMethods(v8::Handle<v8::Object>, v8::Isolate*) { }
	static v8::Handle<v8::FunctionTemplate> domTemplate(v8::Isolate*);
	static inline void* toInternalPointer(BitmapImage* impl)
	{
		return impl;
	}

	static BitmapImage* toNative(v8::Handle<v8::Object> object)
	{
		return fromInternalPointer(object->GetAlignedPointerFromInternalField(v8DOMWrapperTypeIndex));
	}
	static BitmapImage *toNative(v8::Handle<v8::Value> value)
	{
		return fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex));
	}
	static inline BitmapImage* fromInternalPointer(void* object)
	{
		return static_cast<BitmapImage*>(object);
	}
};

//template<class CallbackInfo>
//inline void v8SetReturnValue(const CallbackInfo& callbackInfo, PassRefPtr<BitmapImage> impl)
//{
//	v8SetReturnValue(callbackInfo, impl.get());
//}

template<typename CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, BitmapImage* impl)
{
	if (!impl)
	{
		v8SetReturnValueNull(callbackInfo);
		return;
	}
	//v8::Handle<v8::Object> wrapper = wrap(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	v8::Handle<v8::Object> wrapper = V8BitmapImage::createWrapper(impl, callbackInfo.Holder(), callbackInfo.GetIsolate());
	v8SetReturnValue(callbackInfo, wrapper);
	return;
}

inline v8::Handle<v8::Value> toV8(BitmapImage *imp, v8::Handle<v8::Object> createContext, v8::Isolate *isolate)
{
	v8::Handle<v8::Object> wrapper = V8BitmapImage::createWrapper(imp, createContext, isolate);
	return wrapper;
}

Handle<FunctionTemplate> BitmapImage_Class(Isolate *isolate);
void setBitmapImageClass(Local<Object> parent, Isolate *isolate);



#endif

