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
#include "SkStream.h"
#include "SkBitmap.h"
#include "SkRefCnt.h"
#include "GrGLInterface.h"
#include "SkGradientShader.h"
#include "SkBlurDrawLooper.h"
#include "SkBlurMask.h"
#include "SkTypeface.h"

#include "mylog.h"
#include "GrBackendSurface.h"

#include <string>
#include <cstdlib>

#define LOG_TAG "SkiaApp"


#define IMG_NAME "icon.png"

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
	fCurContext = GrContext::Create(kOpenGL_GrBackend, (GrBackendContext) fCurIntf);
	LOGE("%s, %d, %d", __FUNCTION__, __LINE__, (long)fCurContext );
	GrBackendRenderTarget desc;
//	desc.f = SkScalarRoundToInt(width);
//	desc.fHeight = SkScalarRoundToInt(height);
//	desc.fConfig = kSkia8888_GrPixelConfig;
//	desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
//	desc.fSampleCnt = 1;
//	desc.fStencilBits = 8;
	GLint buffer;
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &buffer);
//	desc.fRenderTargetHandle = buffer;

//	SkSafeUnref(fCurRenderTarget);
//	fCurRenderTarget = fCurContext->wrapBackendRenderTarget(desc);
	LOGE("%s, %d", __FUNCTION__, __LINE__ );

}

void SkiaApp::setFilesDir(const std::string &filesDir){

	SkiaApp::filesDir = filesDir+"/";
	LOGD("%s:filesDir = %s",__func__,SkiaApp::filesDir.c_str());
}

//SkImageDecoder *sk_libpng_dfactory( SkStreamRewindable *stream );

bool SkiaApp::createBitmap(const std::string &src){
	LOGD("%s:src = %s",__func__,src.c_str());
	SkFILEStream stream(src.c_str());

	//SkImageDecoder::DecodeFile(src, &bitmap, SkBitmap::kARGB_8888_Config, SkImageDecoder::kDecodePixels_Mode);

	//SkImageDecoder *coder1 =sk_libpng_dfactory(&stream);
	//delete coder1;
	//coder1 = NULL;
//	SkImageDecoder *coder = SkImageDecoder::Factory(&stream);
//	if(!coder){
//		LOGE("%s:coder is null",__func__);
//		return false;
//	}
//	bool ret = coder->decode(&stream, &bitmap, SkColorType::kRGB_565_SkColorType,SkImageDecoder::kDecodePixels_Mode);
//
    //LOGD("%s:ret = %d,config=%d",__func__,ret,bitmap.getConfig());
	//return ret;
	return true;
}

SkCanvas* SkiaApp::createCanvas()
{
//	LOGD("%s:fCurContext=%d, fCurRenderTarget=%d",__func__,fCurContext, fCurRenderTarget);
//	SkAutoTUnref<SkBaseDevice> device(new SkGpuDevice(fCurContext, fCurRenderTarget));
//	//SkAutoTUnref<SkBaseDevice> device( SkGpuDevice::Create(fCurRenderTarget));
//	return new SkCanvas(device);
    return NULL;
}

static void draw_checks(SkCanvas* canvas, int width, int height) {
    SkPaint paint;
    paint.setColor(SK_ColorRED);
//    canvas->drawRectCoords(SkIntToScalar(0), SkIntToScalar(0), SkIntToScalar(width / 2), SkIntToScalar(height / 2), paint);
//
//	paint.setColor(SK_ColorGREEN);
//    canvas->drawRectCoords(SkIntToScalar(width / 2), SkIntToScalar(0), SkIntToScalar(width), SkIntToScalar(height / 2), paint);
//
//    paint.setColor(SK_ColorBLUE);
//    canvas->drawRectCoords(SkIntToScalar(0), SkIntToScalar(height / 2), SkIntToScalar(width / 2), SkIntToScalar(height), paint);
//
//	paint.setColor(SK_ColorYELLOW);
//    canvas->drawRectCoords(SkIntToScalar(width / 2), SkIntToScalar(height / 2), SkIntToScalar(width), SkIntToScalar(height), paint);
//
}

void SkiaApp::initApp(int width , int height){
	//width = 480;
	//height = 800;
//	windowChanged(width,height);
//	//createBitmap(filesDir+IMG_NAME);
//
//	bitmap.allocN32Pixels(64, 64);
//	SkCanvas canvasTmp(bitmap);
//	draw_checks(&canvasTmp, 64, 64);
//
//	canvas = createCanvas();
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
		paint.setColor(0xffff00ff);
		paint.setStrokeWidth( 10 );
		paint.setStyle( SkPaint::kStroke_Style );
//		canvas->drawColor( 0xff00ffff);
		canvas->drawLine(0,0,100,100,paint);
//		canvas->drawText("test", 4, 200, 100, paint );
		canvas->drawCircle( 200, 200, 100, paint);
//		SkPath path;
//		path.moveTo( 100, 100);
//		path.lineTo( 100, 200);
//		path.lineTo( 200, 200);
//		canvas->drawPath( path, paint );
//		SkRect r;
//		r.set( 0, 0, 200, 200);
//		r.offset(100, 100);
//		//canvas->drawRect( r, paint );
//		canvas->drawArc( r, 0, 90, true, paint );
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
//		SkPaint paint;
//		paint.setColor(0xffff0000);
//		paint.setStrokeWidth( 10);
//		canvas->drawColor( 0xff00ffff);
//		canvas->drawLine(0,0,100,100,paint);

		SkPaint bitmappaint;

		for( int i = 0; i < 1500; i++ )
		{
			int fx = rand();
			int fy = rand();

			canvas->drawBitmap(bitmap, fx % 480, fy % 800,&bitmappaint);
		}
		//canvas->drawArc()
		//canvas->drawColor( 0xff00ffff);
		//glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
		//glClear( GL_COLOR_BUFFER_BIT );

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
	paint.setStrokeWidth(SkScalarHalf(SkIntToScalar(20)));
	//paint.setStyle(SkPaint::kFill_Style);

	SkPoint p = SkPoint::Make(0,0);
	SkPoint q = SkPoint::Make(0,100);
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


//    SkRect r = { 0, 0, SkIntToScalar(170), SkIntToScalar(170) };
//    SkShader* shader1 = SkGradientShader::CreateLinear(
//                       pts, data.fColors, data.fPos,data.fCount,
//                       SkShader::kMirror_TileMode);
//    paint.setShader(shader1)->unref();
//
//    canvas->drawRect(r, paint);
//
//
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
//	canvas->restore();
	return;
}

static void setup(SkPaint* paint, SkColor c, SkScalar strokeWidth) {
    paint->setColor(c);
    if (strokeWidth < 0) {
        paint->setStyle(SkPaint::kFill_Style);
    } else {
        paint->setStyle(SkPaint::kStroke_Style);
        paint->setStrokeWidth(strokeWidth);
    }
}

void SkiaApp::TestShadow( SkCanvas *canvas )
{
	SkRect fRect;
    fRect.set(SkIntToScalar(10), SkIntToScalar(10),
              SkIntToScalar(30), SkIntToScalar(30));
//    SkPath fCirclePath;
//    fCirclePath.addCircle(SkIntToScalar(20), SkIntToScalar(20), SkIntToScalar(10) );
//	SkBlurDrawLooper* shadowLoopers[5];
//	    shadowLoopers[0] =
//	        SkBlurDrawLooper::Create(SK_ColorBLUE,
//	                                 SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(10)),
//	                                 SkIntToScalar(5), SkIntToScalar(10),
//	                                 SkBlurDrawLooper::kIgnoreTransform_BlurFlag |
//	                                 SkBlurDrawLooper::kOverrideColor_BlurFlag |
//	                                 SkBlurDrawLooper::kHighQuality_BlurFlag);
//	    SkAutoUnref aurL0(shadowLoopers[0]);
//	    shadowLoopers[1] =
//	        SkBlurDrawLooper::Create(SK_ColorBLUE,
//	                                 SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(10)),
//	                                 SkIntToScalar(5), SkIntToScalar(10),
//	                                 SkBlurDrawLooper::kIgnoreTransform_BlurFlag |
//	                                 SkBlurDrawLooper::kOverrideColor_BlurFlag);
//	    SkAutoUnref aurL1(shadowLoopers[1]);
//	    shadowLoopers[2] =
//	        SkBlurDrawLooper::Create(SK_ColorBLACK,
//	                                 SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(5)),
//	                                 SkIntToScalar(5),
//	                                 SkIntToScalar(10),
//	                                 SkBlurDrawLooper::kIgnoreTransform_BlurFlag |
//	                                 SkBlurDrawLooper::kHighQuality_BlurFlag);
//	    SkAutoUnref aurL2(shadowLoopers[2]);
//	    shadowLoopers[3] =
//	        SkBlurDrawLooper::Create(0x7FFF0000,
//	                                 SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(5)),
//	                                 SkIntToScalar(-5), SkIntToScalar(-10),
//	                                 SkBlurDrawLooper::kIgnoreTransform_BlurFlag |
//	                                 SkBlurDrawLooper::kOverrideColor_BlurFlag |
//	                                 SkBlurDrawLooper::kHighQuality_BlurFlag);
//	    SkAutoUnref aurL3(shadowLoopers[3]);
//	    shadowLoopers[4] =
//	        SkBlurDrawLooper::Create(SK_ColorBLACK, SkIntToScalar(0),
//	                                 SkIntToScalar(5), SkIntToScalar(5),
//	                                 SkBlurDrawLooper::kIgnoreTransform_BlurFlag |
//	                                 SkBlurDrawLooper::kOverrideColor_BlurFlag |
//	                                 SkBlurDrawLooper::kHighQuality_BlurFlag);
//	    SkAutoUnref aurL4(shadowLoopers[4]);
//
//	    static const struct {
//	        SkColor fColor;
//	        SkScalar fStrokeWidth;
//	    } gRec[] = {
//	        { SK_ColorRED,      -SK_Scalar1 },
//	        { SK_ColorGREEN,    SkIntToScalar(4) },
//	        { SK_ColorBLUE,     SkIntToScalar(0)},
//	    };
//
//	    SkPaint paint;
//	    SkRect rect = SkRect::MakeXYWH( 0, 0, 100, 100 );
//	    canvas->save();
//	    canvas->clipRect( rect );
//	    paint.setAntiAlias(true);
//	    for (size_t i = 0; i < SK_ARRAY_COUNT(shadowLoopers); ++i) {
//	        SkAutoCanvasRestore acr(canvas, true);
//
//	        paint.setLooper(shadowLoopers[i]);
//
//	        canvas->translate(SkIntToScalar((unsigned int)i*40), SkIntToScalar(0));
//	        setup(&paint, gRec[0].fColor, gRec[0].fStrokeWidth);
//	        canvas->drawRect(fRect, paint);
//
//	        canvas->translate(SkIntToScalar(0), SkIntToScalar(40));
//	        setup(&paint, gRec[1].fColor, gRec[1].fStrokeWidth);
//	        canvas->drawPath(fCirclePath, paint);
//
//	        canvas->translate(SkIntToScalar(0), SkIntToScalar(40));
//	        setup(&paint, gRec[2].fColor, gRec[2].fStrokeWidth);
//	        canvas->drawPath(fCirclePath, paint);
//	    }
//	    canvas->restore();
}

void SkiaApp::TestScale(SkCanvas *canvas )
{
	canvas->scale(SkIntToScalar(3)/2, SkIntToScalar(3)/2);

	const SkScalar w = 480;
	const SkScalar h = SkIntToScalar(800);
	SkRect r = { -w, -h, w*2, h*2 };

	static const SkShader::TileMode gModes[] = {
			SkShader::kClamp_TileMode, SkShader::kRepeat_TileMode, SkShader::kMirror_TileMode
	};
	static const char* gModeNames[] = {
			"Clamp", "Repeat", "Mirror"
	};

	SkScalar y = SkIntToScalar(24);
	SkScalar x = SkIntToScalar(66);

	SkPaint p;
	p.setAntiAlias(true);
	p.setTextAlign(SkPaint::kCenter_Align);

	for (size_t kx = 0; kx < SK_ARRAY_COUNT(gModes); kx++) {
		SkString str(gModeNames[kx]);
		canvas->drawText(str.c_str(), str.size(), x + r.width()/2, y, p);
		x += r.width() * 4 / 3;
	}

	y += SkIntToScalar(16) + h;
	p.setTextAlign(SkPaint::kRight_Align);

	for (size_t ky = 0; ky < SK_ARRAY_COUNT(gModes); ky++) {
		x = SkIntToScalar(16) + w;

		SkString str(gModeNames[ky]);
		canvas->drawText(str.c_str(), str.size(), x, y + h/2, p);

		x += SkIntToScalar(50);
		for (size_t kx = 0; kx < SK_ARRAY_COUNT(gModes); kx++) {
			SkPaint paint;
			//paint.setShader(fProc(gModes[kx], gModes[ky]))->unref();

			canvas->save();
			canvas->translate(x, y);
			canvas->drawRect(r, paint);
			canvas->restore();

			x += r.width() * 4 / 3;
		}
		y += r.height() * 4 / 3;
	}

}

static const char* gColorTypeNames[] = {
    "unknown",
    "A8",
    "565",
    "4444",
    "8888",
    "8888",
    "Index8",
};

static const SkColorType gColorTypes[] = {
    kRGB_565_SkColorType,
    kARGB_4444_SkColorType,
    kN32_SkColorType,
};

#define NUM_CONFIGS SK_ARRAY_COUNT(gColorTypes)

void SkiaApp::TestCopyBitmap( SkCanvas *canvas )
{
//	SkBitmap    fDst[NUM_CONFIGS];
//	SkPaint paint;
//	SkScalar horizMargin = 10;
//	SkScalar vertMargin = 10;
//
//	SkBitmap src;
//	src.allocN32Pixels(40, 40);
//	SkCanvas canvasTmp(src);
//
//	draw_checks(&canvasTmp, 40, 40);
//
//	for (unsigned i = 0; i < NUM_CONFIGS; ++i) {
//		src.copyTo(&fDst[i], gColorTypes[i]);
//	}
//
//
//	canvas->drawBitmap(fDst[0], 40, 0, &paint);

//	canvas->clear(0xFFDDDDDD);
//	paint.setAntiAlias(true);
//	SkScalar width = SkIntToScalar(40);
//	SkScalar height = SkIntToScalar(40);
//	if (paint.getFontSpacing() > height) {
//		height = paint.getFontSpacing();
//	}
//	for (unsigned i = 0; i < NUM_CONFIGS; i++) {
//		const char* name = gColorTypeNames[src.colorType()];
//		SkScalar textWidth = paint.measureText(name, strlen(name));
//		if (textWidth > width) {
//			width = textWidth;
//		}
//	}
//	SkScalar horizOffset = width + horizMargin;
//	SkScalar vertOffset = height + vertMargin;
//	canvas->translate(SkIntToScalar(20), SkIntToScalar(20));
//
//	for (unsigned i = 0; i < NUM_CONFIGS; i++) {
//		canvas->save();
//		// Draw destination config name
//		const char* name = gColorTypeNames[fDst[i].colorType()];
//		SkScalar textWidth = paint.measureText(name, strlen(name));
//		SkScalar x = (width - textWidth) / SkScalar(2);
//		SkScalar y = paint.getFontSpacing() / SkScalar(2);
//		//canvas->drawText(name, strlen(name), x, y, paint);
//
//		// Draw destination bitmap
//		canvas->translate(0, vertOffset);
//		x = (width - 40) / SkScalar(2);
//		canvas->drawBitmap(fDst[i], x, 0, &paint);
//		canvas->restore();
//
//		canvas->translate(horizOffset, 0);
//	}
}

void SkiaApp::TestFill( SkCanvas *canvas)
{
//	PassOwnPtr<CanvasContext2D>ctx = CanvasContext2D::create( canvas );
//	ctx->rect( 5, 5, 50, 50 );
//	ctx->setFillColor( "blue");
//	ctx->fill();
}

void SkiaApp::TestAddColorStop( SkCanvas *canvas )
{
//	PassOwnPtr<CanvasContext2D>ctx = CanvasContext2D::create( canvas );
//	PassRefPtr<CanvasGradient> grd = ctx->createLinearGradient( 0, 0, 170, 0 );
//	grd->addColorStop( 0, "black");
//	grd->addColorStop( 0.3, "magenta");
//	grd->addColorStop( 0.5, "blue");
//	grd->addColorStop( 0.6, "green");
//	grd->addColorStop( 0.8, "yellow");
//	grd->addColorStop( 1, "red");
//	RefPtr< CanvasStyle> style = CanvasStyle::createFromGradient( grd );
//	ctx->setFillStyle( style );
//	ctx->fillRect( 10, 10, 150, 100 );
	return;
}

void SkiaApp::TestArcTo( SkCanvas *canvas )
{
//	PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create( canvas );
//	ctx->beginPath();
//	ctx->setStrokeColor( "green");
//	ctx->setLineWidth( 8 );
//	ctx->moveTo( 20, 20 );
//	ctx->lineTo( 100, 20 );
//	ctx->arcTo( 150, 20, 150, 70, 50 );
//	ctx->lineTo( 150, 120 );
//	ctx->stroke();
}

void SkiaApp::TestText( SkCanvas *canvas )
{
	//SkTypeface *font = SkTypeface::CreateFromFile("DroidSansFallbackFull.ttf");
//	SkDebugf("%s, %d --------->begin", __FILENAME__, __LINE__ );
//	SkTypeface *font = SkTypeface::CreateFromName( "Droid Sans", SkTypeface::kNormal );
//	SkDebugf("%s, %d----->end", __FILENAME__, __LINE__ );
//	SkPaint paint;
//	paint.setAntiAlias( true );
//	paint.setColor( 0xFF008000);
//	if( font )
//	{
//		SkDebugf("%s, %d faceType is not null", __FILENAME__, __LINE__ );
//		paint.setTypeface( font );
//	}
//	else
//	{
//		SkDebugf("%s, %d, %d", __FILENAME__, __LINE__, (int)font );
//	}
//	paint.setTextSize( 50 );
//	paint.setStyle( SkPaint::kStroke_Style );
//	paint.setStrokeWidth( 2 );
//	canvas->drawLine( 10, 10, 100, 10, paint );
//	paint.setColor( 0xffff0000);
//
//	std::string str = "ab12音乐er";
//	canvas->drawText( str.c_str(), str.length() , 10, 400, paint );
//	canvas->drawText( "test", 4, 10, 200, paint );
}

void SkiaApp::TestGetImageData( SkCanvas *canvas)
{
//	if(canvas){
//		SkPaint paint;
//		paint.setStrokeWidth( 2);
//		paint.setStyle( SkPaint::kStroke_Style );
//		paint.setColor( 0xFF00FF00 );
//		SkPath path;
//		path.moveTo( 10, 10 );
//		path.lineTo( 50, 50 );
//		canvas->drawBitmap(bitmap, 10, 10,&paint);
//		canvas->drawPath( path, paint );
//
//		SkBitmap dstBmp;
//		SkImageInfo info = SkImageInfo::MakeN32Premul( 64, 64  );
//		dstBmp.allocPixels( info );
//		canvas->readPixels(&dstBmp, 10, 10);
//		canvas->writePixels( dstBmp, 100, 200 );
//
//	}
}

void SkiaApp::TestCreateRadialGradient( SkCanvas *canvas )
{

}

void SkiaApp::TestShadowOffset( SkCanvas *canvas )
{
    canvas->drawColor(SK_ColorWHITE);
    SkPaint paint;
    paint.setStyle(SkPaint::kFill_Style);
    paint.setAntiAlias(true);
    paint.setStrokeWidth(4);
    paint.setColor(0xffFE938C);

    SkRect rect = SkRect::MakeXYWH(10, 10, 100, 160);
    canvas->drawRect(rect, paint);

    SkRRect oval;
    oval.setOval(rect);
    oval.offset(40, 80);
    paint.setColor(0xffE6B89C);
    canvas->drawRRect(oval, paint);

    paint.setColor(0xff9CAFB7);
    canvas->drawCircle(180, 50, 25, paint);

    rect.offset(80, 50);
    paint.setColor(0xff4281A4);
    paint.setStyle(SkPaint::kStroke_Style);
    canvas->drawRoundRect(rect, 10, 10, paint);

}

void SkiaApp::TestDrawRect(SkCanvas *canvas)
{
	SkPaint strokePaint;
	strokePaint.setStyle(SkPaint::kStroke_Style);
	strokePaint.setAntiAlias(true);
	strokePaint.setStrokeWidth( 20);
	strokePaint.setColor(0xff00ffff);
	SkRect r = SkRect::MakeXYWH(800, 800, 100, 100);
	canvas->drawRect(r, strokePaint );
	return;
}




void SkiaApp::mainLoop(){
//	canvas->drawColor(0xffffffff);
//    TestFillStyle(canvas);
//	canvas->drawCircle( 200, 200, 100, fillPaint);
//    draw_checks(canvas, 640, 640);
//	fCurContext->flush();

}

