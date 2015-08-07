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
#include "SkStream.h"
#include "SkImageDecoder.h"
#include "SkBitmap.h"
#include "SkRefCnt.h"
#include "GrGLInterface.h"
#include "SkGradientShader.h"

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
	//SkAutoTUnref<const GrGLInterface> glInterface;
	//glInterface.reset( GrGLCreateNativeInterface() );
	//LOGE("%s, %d", __FUNCTION__, __LINE__ );
	//const GrGLInterface *fCurIntf = GrGLInterfaceRemoveNVPR( glInterface.get());
	//LOGE("%s, %d", __FUNCTION__, __LINE__ );
	const GrGLInterface *fCurIntf = GrGLCreateNativeInterface();
	fCurContext = GrContext::Create( (GrBackendContext) fCurIntf);
	LOGE("%s, %d, %d", __FUNCTION__, __LINE__, (int)fCurContext );
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
	LOGE("%s, %d", __FUNCTION__, __LINE__ );

}

void SkiaApp::setFilesDir(const std::string &filesDir){

	SkiaApp::filesDir = filesDir+"/";
	LOGD("%s:filesDir = %s",__func__,SkiaApp::filesDir.c_str());
}

bool SkiaApp::createBitmap(const std::string &src){
	LOGD("%s:src = %s",__func__,src.c_str());
	SkFILEStream stream(src.c_str());
	//SkImageDecoder::DecodeFile(src, &bitmap, SkBitmap::kARGB_8888_Config, SkImageDecoder::kDecodePixels_Mode);

	//SkImageDecoder *coder =CreatePNGImageDecoder();
	//delete coder;
	//coder = NULL;
	SkImageDecoder *coder = SkImageDecoder::Factory(&stream);
	if(!coder){
		LOGE("%s:coder is null",__func__);
		return false;
	}
	//bool ret = coder->decode(&stream, &bitmap, SkBitmap::kARGB_8888_Config,SkImageDecoder::kDecodePixels_Mode);
	//LOGD("%s:ret = %d,config=%d",__func__,ret,bitmap.getConfig());
	//return ret;
	return true;
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

	if(canvas){
		//LOGD("%s:",__func__);
		//canvas->drawColor(0xff00ff00,SkXfermode::Mode::kColor_Mode);
		SkPaint paint;
		paint.setColor(0xffff0000);
		paint.setStrokeWidth( 10 );
		paint.setStyle( SkPaint::kStroke_Style );
		//canvas->drawColor( 0xff00ffff);
		//canvas->drawLine(0,0,100,100,paint);
		//canvas->drawText("test", 4, 200, 100, paint );
		//canvas->drawCircle( 200, 200, 100, paint);
		SkPath path;
		path.moveTo( 100, 100);
		path.lineTo( 100, 200);
		path.lineTo( 200, 200);
		canvas->drawPath( path, paint );
		SkRect r;
		r.set( 0, 0, 200, 200);
		r.offset(100, 100);
		//canvas->drawRect( r, paint );
		canvas->drawArc( r, 0, 90, true, paint );
		//canvas->drawColor( 0xff00ffff);
		//glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
		//glClear( GL_COLOR_BUFFER_BIT );

	}
}

void SkiaApp::TestArc(SkCanvas *canvas )
{

}

void SkiaApp::TestDrawImage(SkCanvas *canvas )
{
	//SkMatrix mat;
	//mat.setAll( 1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0 );
	//canvas->concat( mat );
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

struct GradData {
    int             fCount;
    const SkColor*  fColors;
    const SkScalar* fPos;
};

void SkiaApp::TestFillStyle( SkCanvas *canvas )
{
	SkMatrix mat;
	mat.setAll( 1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0 );
	canvas->concat( mat );
	canvas->save();
	 SkPaint paint;
	paint.setAntiAlias(true);
	paint.setStyle(SkPaint::kStroke_Style);
	paint.setStrokeWidth(SkScalarHalf(SkIntToScalar(3)));
	paint.setStyle(SkPaint::kFill_Style);

	SkPoint p = SkPoint::Make(0,0);
	SkPoint q = SkPoint::Make(100,100);
	SkPoint pts[] = {p, q};

	SkScalar t, temp, x, y;
	SkColor gColors[] = {
		SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK
	};
	t =   2;
	temp = 1;
	SkScalar step = SK_ScalarPI / (10);
	SkScalar angle = t * step;
	x =  SkScalarSinCos(angle, &y);
	SkScalar colorPositions[] = { 0.0f, (float)(0.1 + x), (float)(0.4 + y), (float)(0.9 - x + y), 1.0};
	GradData data = { 5, gColors, colorPositions };


    SkRect r = { 0, 0, SkIntToScalar(200), SkIntToScalar(200) };
    SkShader* shader1 = SkGradientShader::CreateLinear(
                       pts, data.fColors, data.fPos,data.fCount,
                       SkShader::kMirror_TileMode);
    paint.setShader(shader1)->unref();

    canvas->drawRect(r, paint);


//	SkPoint s = SkPoint::Make(100,100);
//	SkShader* shader2 = SkGradientShader::CreateRadial(
//					   s, 100, data.fColors, data.fPos, data.fCount,
//					   SkShader::kMirror_TileMode);
//	paint.setShader(shader2)->unref();
//	canvas->translate(250, 0);
//	canvas->drawRect(r, paint);
//
//	SkShader* shader3 = SkGradientShader::CreateTwoPointRadial(
//					   p, 0, q, 100, data.fColors, data.fPos, data.fCount,
//					   SkShader::kMirror_TileMode);
//	paint.setShader(shader3)->unref();
//	canvas->translate(0, 250);
//	canvas->drawRect(r, paint);
//
//	SkShader* shader4 = SkGradientShader::CreateSweep(
//						100, 100, data.fColors, data.fPos, data.fCount);
//
//	paint.setShader(shader4)->unref();
//	canvas->translate(-250, 0);
//	canvas->drawRect(r, paint);
	canvas->restore();
	return;
}

void SkiaApp::mainLoop(){
	//canvas = createCanvas();
	canvas->drawColor(0xff000000);
	//TestArc( canvas );
	TestFillStyle( canvas );
	fCurContext->flush();
}

} /* namespace egret */
