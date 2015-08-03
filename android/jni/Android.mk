LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := runtimecanvas

LOCAL_ARM_MODE := arm

LOCAL_CFLAGS    := -Werror

LOCAL_SRC_FILES := gl_code.cpp \
				   GlesUtil.cpp \
				   SkiaApp.cpp \
				   JniShell.cpp \
				   EGTLog.cpp \
				   StdC.cpp
				  

LOCAL_STATIC_LIBRARIES := skia
LOCAL_STATIC_LIBRARIES += canvascontext
LOCAL_STATIC_LIBRARIES += wtf
LOCAL_STATIC_LIBRARIES += harfbuzz
LOCAL_STATIC_LIBRARIES += icu
LOCAL_STATIC_LIBRARIES += stlport


LOCAL_LDLIBS    := -llog -lGLESv2 -lEGL

#include $(BUILD_STATIC_LIBRARY)

include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))

