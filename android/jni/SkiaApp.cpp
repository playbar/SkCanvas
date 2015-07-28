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
namespace egret {

SkiaApp::SkiaApp():
		fCurContext(NULL),
		fCurRenderTarget(NULL){
	// TODO Auto-generated constructor stub

}

SkiaApp::~SkiaApp() {
	// TODO Auto-generated destructor stub
}

void SkiaApp::windowChanged(int width,int height){
	if (fCurContext) {

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
}

SkCanvas* SkiaApp::createCanvas()
{
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

} /* namespace egret */
