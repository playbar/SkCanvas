/*
 * SkiaApp.h
 *
 *  Created on: 2015-7-28
 *      Author: jkd2972
 */

#ifndef SKIAAPP_H_
#define SKIAAPP_H_
#include "GrContext.h"
namespace egret {

class SkiaApp {
protected:
	static SkiaApp * _instance;
	GrContext * fCurContext;
	GrRenderTarget * fCurRenderTarget;
	SkCanvas * canvas;
public:
	SkiaApp();
	virtual ~SkiaApp();

	static SkiaApp * createSkiaApp();

	static SkiaApp * getSkiaApp();

	void initApp(int width , int height);

	void pauseApp();
	void resumeApp();

	void mainLoop();

	void windowChanged(int width,int height);
	SkCanvas* createCanvas();
};

} /* namespace egret */
#endif /* SKIAAPP_H_ */
