LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libruntimecanvas
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := gl_code.cpp \
				   GlesUtil.cpp

LOCAL_LDLIBS    := -llog -lGLESv2

include $(BUILD_STATIC_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))

