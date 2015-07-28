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
	GrContext * fCurContext;
	GrRenderTarget * fCurRenderTarget;
	SkCanvas * canvas;
public:
	SkiaApp();
	virtual ~SkiaApp();

	void initApp(int width , int height);

	void pauseApp();
	void resumeApp();

	void windowChanged(int width,int height);
	SkCanvas* createCanvas();
};

} /* namespace egret */
#endif /* SKIAAPP_H_ */
