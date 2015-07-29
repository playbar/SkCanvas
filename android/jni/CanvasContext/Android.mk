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
					$../../third_party/skia/include/pathops \
					$../../third_party/skia/src/core \
					$../../ \
	

#blink				
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/blink/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
					 							

#Canvas				
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/Canvas/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

##css		
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/css/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#css/resolver		
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/css/resolver/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#dom	
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/dom/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform	
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-font	
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/font/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-geometry	
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/geometry/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-graphics	
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/graphics/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-graphics-skia	
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/graphics/skia/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-image-decoders
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/image-decoders/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-text
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/text/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#platform-transforms
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/platform/transforms/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#style
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../CanvasContext/style/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


