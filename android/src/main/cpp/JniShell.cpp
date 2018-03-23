/*
 * JniShell.cpp
 *
 *  Created on: 2015-7-28
 *      Author: jkd2972
 */

#include "JniShell.h"
#include "com_android_gl2jni_JniShell.h"
#include "SkiaApp.h"
namespace egret {

#ifdef __cplusplus
extern "C" {
#endif
#define DELETE_LOCAL_CLASS_REF() (env->DeleteLocalRef(obj))

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    initApp
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_initApp
  (JNIEnv * env, jclass obj, jint width, jint height){

	SkiaApp::createSkiaApp()->initApp(width,height);

	DELETE_LOCAL_CLASS_REF();
}

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    pauseApp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_pauseApp
  (JNIEnv * env, jclass obj){

	DELETE_LOCAL_CLASS_REF();
}

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    resumeApp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_resumeApp
  (JNIEnv * env, jclass obj){

	DELETE_LOCAL_CLASS_REF();
}

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    mainLoop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_mainLoop
  (JNIEnv * env, jclass obj){
	if(SkiaApp::getSkiaApp()){
		SkiaApp::getSkiaApp()->mainLoop();
	}
	DELETE_LOCAL_CLASS_REF();
}


/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    setFilesDir
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_setFilesDir
  (JNIEnv * env, jclass obj, jstring jstr){

	const char * fileDir = env->GetStringUTFChars(jstr , NULL);
	const std::string dir(fileDir);
	SkiaApp::setFilesDir(dir);
	env->ReleaseStringUTFChars(jstr,fileDir);
	DELETE_LOCAL_CLASS_REF();
}

#ifdef __cplusplus
}
#endif


JniShell::JniShell() {
	// TODO Auto-generated constructor stub

}

JniShell::~JniShell() {
	// TODO Auto-generated destructor stub
}

} /* namespace egret */
