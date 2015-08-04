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
#include "CanvasRenderingContext2D.h"
#include "EGTLog.h"
using namespace WebCore;
using namespace WTF;
#include "SkStream.h"
#include "SkImageDecoder.h"
#include "SkBitmap.h"

#include <string>
#define LOG_TAG "SkiaApp"

namespace egret {

#define IMG_NAME "egret_icon.png"

SkiaApp * SkiaApp::_instance = NULL;
std::string SkiaApp::filesDir;
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

	glViewport(0,0,width,height);
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

void SkiaApp::setFilesDir(const std::string &filesDir){

	SkiaApp::filesDir = filesDir+"/";
	LOGD("%s:filesDir = %s",__func__,SkiaApp::filesDir.c_str());
}

bool SkiaApp::createBitmap(const std::string &src){
	LOGD("%s:src = %s",__func__,src.c_str());
	SkFILEStream stream(src.c_str());
	//SkImageDecoder::DecodeFile(src, &bitmap, SkBitmap::kARGB_8888_Config, SkImageDecoder::kDecodePixels_Mode);

	SkImageDecoder *coder =CreatePNGImageDecoder();
	delete coder;
	coder = NULL;
	coder = SkImageDecoder::Factory(&stream);
	if(!coder){
		LOGE("%s:coder is null",__func__);
		return false;
	}
	bool ret = coder->decode(&stream, &bitmap, SkBitmap::kARGB_8888_Config,SkImageDecoder::kDecodePixels_Mode);
	LOGD("%s:ret = %d,config=%d",__func__,ret,bitmap.getConfig());
	return ret;
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
	//createBitmap(filesDir+IMG_NAME);
	canvas = createCanvas();
}

void SkiaApp::pauseApp(){

}

void SkiaApp::resumeApp(){

}

void SkiaApp::DrawTest(SkCanvas *canvas )
{
	SkMatrix mat;
	mat.setAll( 1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0 );
	canvas->concat( mat );
	if(canvas){
		//LOGD("%s:",__func__);
		//canvas->drawColor(0xff00ff00,SkXfermode::Mode::kColor_Mode);
		SkPaint paint;
		paint.setColor(0xffff0000);
		paint.setStrokeWidth( 10);
		canvas->drawColor( 0xff00ffff);
		canvas->drawLine(0,0,100,100,paint);
		canvas->drawText("test", 4, 200, 100, paint );
		//canvas->drawArc()
		//canvas->drawColor( 0xff00ffff);
		//glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
		//glClear( GL_COLOR_BUFFER_BIT );

	}
}

void SkiaApp::TestArc(SkCanvas *canvas )
{
	PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create( canvas, NULL, false );
	ctx->beginPath();
	ctx->setLineWidth( 5);
	ctx->setStrokeColor("#ff00ff");
	//ctx->arc( 100, 75, 50, 0, 2 * M_PI, false );
	ctx->moveTo( 100, 100);
	ctx->bezierCurveTo( 20, 100, 200, 100, 200, 20);
	//ctx->lineTo( 200, 100);
	//ctx->rect( 50, 50, 150, 80);
	ctx->fill();
}

void SkiaApp::TestDrawImage(SkCanvas *canvas )
{
	SkMatrix mat;
	mat.setAll( 1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0 );
	canvas->concat( mat );
	if(canvas){
		//LOGD("%s:",__func__);
		//canvas->drawColor(0xff00ff00,SkXfermode::Mode::kColor_Mode);
		SkPaint paint;
		paint.setColor(0xffff0000);
		paint.setStrokeWidth( 10);
		canvas->drawColor( 0xff00ffff);
		canvas->drawLine(0,0,100,100,paint);

		SkPaint bitmappaint;
		canvas->drawBitmap(bitmap,200,400,&bitmappaint);
		//canvas->drawArc()
		//canvas->drawColor( 0xff00ffff);
		//glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
		//glClear( GL_COLOR_BUFFER_BIT );
		fCurContext->flush();
	}
}

void SkiaApp::mainLoop(){
	//canvas = createCanvas();
	canvas->drawColor(0xff000000);
	TestArc( canvas );
	fCurContext->flush();
}

} /* namespace egret */
