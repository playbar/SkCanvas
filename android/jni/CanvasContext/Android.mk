LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := canvascontext

LOCAL_CFLAGS += -DHAVE_OT \
				-DGL_GLEXT_PROTOTYPES \
				-DHB_NO_UNICODE_FUNCS  \
				-DHB_NO_MT \
				-fshort-wchar	\
				-fexceptions
				
LOCAL_C_INCLUDES :=  \
					$(JNI_H_INCLUDE)  \
					$(LOCAL_PATH)      \
					$../../CanvasContext/blink \
					$../../CanvasContext/css \
					$../../CanvasContext/dom \
					$../../CanvasContext \
					$../../wtf/ \
					$../../wtf/unicode/ \
					$../../third_party/icu/source/common \
					$../../third_party/skia/include/core \
					$../../third_party/skia/include/config \
					$../../third_party/skia/include/utils \
					$../../third_party/skia/include/effects \
					$../../ \
	

#blink				
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/blink/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
					 							

#Canvas				
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/Canvas/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


