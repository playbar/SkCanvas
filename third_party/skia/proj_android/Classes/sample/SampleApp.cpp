/*
 * SampleApp.cpp
 *
 *  Created on: 2015-7-25
 *      Author: jkd2972
 */

#include "SampleApp.h"
#include "EGTLog.h"
#include "StdC.h"
#include "gl.h"
#include <SkCanvas.h>
#include <GraphicsJNI.h>
#define LOG_TAG "SampleApp"
namespace egret {

SampleApp * SampleApp::_instance = NULL;
//SkCanvas * canvas;
SampleApp::SampleApp() {
	// TODO Auto-generated constructor stub
	//GrContext * context = GrContext::Create(GrBackend::kOpenGL_GrBackend,NULL);
	//canvas = SkCanvas::NewRasterN32(480,800);

}

SampleApp::~SampleApp() {
	// TODO Auto-generated destructor stub

}

void SampleApp::createNewApp(){
	if(_instance){
		delete _instance;
		_instance= NULL;
	}
	_instance = new SampleApp();
}

SampleApp * SampleApp::getInstance(){
	return _instance;
}

void SampleApp::mainLoop(){
	//LOGD("%s",__func__);
//	glClearColor(1.0f,0,0,1.0f);
//	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

//	canvas->clear(0xffff0000);

//	auto size = canvas->getDeviceSize();
	//LOGD("%s:iszero = %d",__func__,size.isZero());
}

void SampleApp::drawPng(SkCanvas * canvas){
	LOGD("%s:canvas = %d",__func__,canvas);
	if(canvas)
	canvas->clear(0xffff0000);
}

} /* namespace egret */
