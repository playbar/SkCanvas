
#ifndef __ANDROID_JNI_HELPER_H__
#define __ANDROID_JNI_HELPER_H__

#include <jni.h>
#include <string>
//#include "platform/CCPlatformMacros.h"



typedef struct JniMethodInfo_
{
    JNIEnv *    env;
    jclass      classID;
    jmethodID   methodID;
} JniMethodInfo;

class  JniHelper
{
public:
    static JavaVM* getJavaVM();
    static void setJavaVM(JavaVM *javaVM);
    static bool getDefEnv(JNIEnv ** env);
    static jclass getClassID(const char *className, JNIEnv *env=0);
    static bool getStaticMethodInfo(JniMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode);
    static bool getMethodInfo(JniMethodInfo &methodinfo, const char *className, const char *methodName, const char *paramCode);
    static std::string jstring2string(jstring str);

private:
    static JavaVM *m_psJavaVM;
};



#endif // __ANDROID_JNI_HELPER_H__
