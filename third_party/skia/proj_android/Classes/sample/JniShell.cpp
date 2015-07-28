/*
 * JniShell.cpp
 *
 *  Created on: 2015-7-25
 *      Author: jkd2972
 */
#include "org_egret_egretskialib_JniShell.h"
#include "JniShell.h"
#include "EGTLog.h"
#include "EGTJniHelper.h"
#include "SampleApp.h"


#define LOG_TAG "JniShell"

namespace egret {






JniShell::JniShell() {
	// TODO Auto-generated constructor stub

}

JniShell::~JniShell() {
	// TODO Auto-generated destructor stub
}

#ifdef __cplusplus
extern "C" {
#endif

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
	LOGI("JNI_OnLoad ---------------------");

	JniHelper::setJavaVM(vm);

	return JNI_VERSION_1_4;
}

void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
	LOGI("JNI_OnUnoad ---------------------");
}

/*
 * Class:     org_egret_egretskialib_JniShell
 * Method:    mainLoop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_egret_egretskialib_JniShell_nativeMainLoop
  (JNIEnv * env, jclass obj){
	if(SampleApp::getInstance()){
		SampleApp::getInstance()->mainLoop();
	}
}

/*
 * Class:     org_egret_egretskialib_JniShell
 * Method:    pauseApp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_egret_egretskialib_JniShell_nativeInit
(JNIEnv * env, jclass obj, jint width, jint height){
	LOGD("%s:size(%d,%d)",__func__,width,height);
	SampleApp::createNewApp();
}

/*
 * Class:     org_egret_egretskialib_JniShell
 * Method:    resumeApp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_egret_egretskialib_JniShell_nativeResumeApp
  (JNIEnv * env, jclass obj){
	LOGD("%s",__func__);
}

static jfieldID getFieldIDCheck(JNIEnv* env, jclass clazz,
	                                const char fieldname[], const char type[])
	{
	    jfieldID id = env->GetFieldID(clazz, fieldname, type);
	    SkASSERT(id);
	    return id;
	}

static jclass make_globalref(JNIEnv* env, const char classname[])
{
    jclass c = env->FindClass(classname);

    return (jclass)env->NewGlobalRef(c);
}
/*
 * Class:     org_egret_egretskialib_JniShell
 * Method:    drawPng
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_org_egret_egretskialib_JniShell_drawPng
  (JNIEnv * env, jclass obj, jobject jobj_canvas){

	jclass gCanvas_class = make_globalref(env , "android/graphics/Canvas");
	if(!gCanvas_class)
		return;
	bool isIns = env->IsInstanceOf(jobj_canvas, gCanvas_class);

	//SkCanvas * canvas = GraphicsJNI::getNativeCanvas(env,jobj_canvas);
	jfieldID gCanvas_nativeInstanceID = getFieldIDCheck(env, gCanvas_class, "mNativeCanvas", "I");
	if(!gCanvas_nativeInstanceID)
		return;
	SkCanvas * canvas = (SkCanvas*)env->GetIntField(jobj_canvas, gCanvas_nativeInstanceID);
	LOGD("%s:gCanvas_nativeInstanceID = %d,jobj_canvas = %d,canvas = %d",__func__,gCanvas_nativeInstanceID,jobj_canvas,canvas);
	SampleApp::drawPng(canvas);

	env->DeleteLocalRef(jobj_canvas);
	env->DeleteLocalRef(obj);

}

#ifdef __cplusplus
}
#endif

} /* namespace egret */
