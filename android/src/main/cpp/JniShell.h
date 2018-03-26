/*
 * JniShell.h
 *
 *  Created on: 2015-7-28
 *      Author: jkd2972
 */

#ifndef JNISHELL_H_
#define JNISHELL_H_
#include <jni.h>


#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    setFilesDir
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_setFilesDir
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    initApp
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_initApp
(JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    pauseApp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_pauseApp
(JNIEnv *, jclass);

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    resumeApp
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_resumeApp
(JNIEnv *, jclass);

/*
 * Class:     com_android_gl2jni_JniShell
 * Method:    mainLoop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_android_gl2jni_JniShell_mainLoop
(JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif


#endif /* JNISHELL_H_ */
