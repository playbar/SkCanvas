/*
 * SampleApp.h
 *
 *  Created on: 2015-7-25
 *      Author: jkd2972
 */

#ifndef SAMPLEAPP_H_
#define SAMPLEAPP_H_
#include <jni.h>
#include <SKCanvas.h>
namespace egret {

class SampleApp {
private:
	static SampleApp * _instance;
public:
	SampleApp();
	virtual ~SampleApp();

	static void createNewApp();

	static SampleApp * getInstance();

	static void drawPng(SkCanvas * canvas);

	void mainLoop();
};

} /* namespace egret */
#endif /* SAMPLEAPP_H_ */
