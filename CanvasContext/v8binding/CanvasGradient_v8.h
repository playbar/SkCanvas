#ifndef __CANVASGRADIENT_H__
#define __CANVASGRADIENT_H__

#include "include/v8.h"
using namespace v8;
#include "passrefptr.h"
#include "CanvasGradient.h"
using namespace Canvas2D;

//template<class CallbackInfo>
//inline void v8SetReturnValue(const CallbackInfo& callbackInfo, PassRefPtr<CanvasGradient> impl)
//{
//	v8SetReturnValue(callbackInfo, impl.get());
//}

void setCanvasGradientClass(Local<Object> parent, Isolate *isolate);


#endif

