/*
 * JniShell.h
 *
 *  Created on: 2015-7-25
 *      Author: jkd2972
 */

#ifndef JNISHELL_H_
#define JNISHELL_H_
#include <jni.h>
#include <GraphicsJNI.h>

namespace egret {

extern "C" {
	jint JNI_OnLoad(JavaVM *vm, void *reserved);

	void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved);
}

class JniShell {
public:
	JniShell();
	virtual ~JniShell();
};

} /* namespace egret */
#endif /* JNISHELL_H_ */
