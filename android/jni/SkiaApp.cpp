/*
 * SkiaApp.cpp
 *
 *  Created on: 2015-7-28
 *      Author: jkd2972
 */

#include "SkiaApp.h"

#include "GrTypes.h"
#include <GLES2/gl2.h>
#include "SkRefCnt.h"
#include "SkGpuDevice.h"
#include "EGTLog.h"
#define LOG_TAG "SkiaApp"
namespace egret {
SkiaApp * SkiaApp::_instance = NULL;
SkiaApp::SkiaApp():
		fCurContext(NULL),
		fCurRenderTarget(NULL){
	// TODO Auto-generated constructor stub

}

SkiaApp::~SkiaApp() {
	// TODO Auto-generated destructor stub
}

SkiaApp * SkiaApp::createSkiaApp(){
	if(_instance){
		delete _instance;
	}
	_instance = new SkiaApp();
	return _instance;
}

SkiaApp * SkiaApp::getSkiaApp(){
	return _instance;
}

void SkiaApp::windowChanged(int width,int height){
	LOGD("%s:(%d,%d)",__func__,width,height);

	//glViewport(0,0,width,height);
		fCurContext = GrContext::Create();
			GrBackendRenderTargetDesc desc;
			desc.fWidth = SkScalarRoundToInt(width);
			desc.fHeight = SkScalarRoundToInt(height);
			desc.fConfig = kSkia8888_GrPixelConfig;
			desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
			desc.fSampleCnt = 1;
			desc.fStencilBits = 8;
			GLint buffer;
			glGetIntegerv(GL_FRAMEBUFFER_BINDING, &buffer);
			desc.fRenderTargetHandle = buffer;

			SkSafeUnref(fCurRenderTarget);
			fCurRenderTarget = fCurContext->wrapBackendRenderTarget(desc);

}

SkCanvas* SkiaApp::createCanvas()
{
	LOGD("%s:fCurContext=%d, fCurRenderTarget=%d",__func__,fCurContext, fCurRenderTarget);
	SkAutoTUnref<SkBaseDevice> device(new SkGpuDevice(fCurContext, fCurRenderTarget));
	//SkAutoTUnref<SkBaseDevice> device( SkGpuDevice::Create(fCurRenderTarget));
	return new SkCanvas(device);
}

void SkiaApp::initApp(int width , int height){
	windowChanged(width,height);
	canvas = createCanvas();
}

void SkiaApp::pauseApp(){

}

void SkiaApp::resumeApp(){

}

void SkiaApp::mainLoop(){
	//canvas = createCanvas();
	if(canvas){
		//LOGD("%s:",__func__);
		//canvas->drawColor(0xff00ff00,SkXfermode::Mode::kColor_Mode);
		SkPaint paint;
		paint.setColor(0xffff0000);
		canvas->drawLine(0,0,100,300,paint);
		canvas->drawColor( 0xff00ffff);
		//glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
		//glClear( GL_COLOR_BUFFER_BIT );
		fCurContext->flush();
	}
}

} /* namespace egret */
