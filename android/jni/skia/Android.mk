LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := skia

LOCAL_CFLAGS += -DSK_BUILD_FOR_ANDROID_FRAMEWORK\
				-D_ARGB_PIXEL_  \
				-fshort-wchar	\
				-fexceptions
				
LOCAL_C_INCLUDES :=  \
					$(JNI_H_INCLUDE)  \
					$(MY_ANDROID_SOURCE)/frameworks/base/include \
					$(MY_ANDROID_SOURCE)/system/core/include \
					$(MY_ANDROID_SOURCE)/external/astl/include \
					$(MY_ANDROID_SOURCE)/hardware/libhardware/include \
					$(LOCAL_PATH)      \
					$../../third_party/skia/include/core   \
					$../../third_party/skia/src/image \
					$../../third_party/skia/include/utils \
					$../../third_party/skia/include \
					$../../third_party/skia/src/gpu \
					$../../third_party/skia/include/gpu \
					$../../ \
					$../../skia/config \
					


#LOCAL_SRC_FILES += \
#		../../../third_party/skia/src/core/*.cpp \
		
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/core/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
					 
#base android
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../../src/base/android/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)				
LOCAL_SRC_FILES	+=  /../../../../src/base/android/GGBase.cpp \
					/../../../../src/base/android/BwImageDecode.cpp	\
					/../../../../src/base/android/MultiStringUtil.cpp \
					/../../../../src/base/android/port_impl.cpp \
					/../../../../src/base/android/string_comp.cpp \
					/../../../../src/base/android/XFile.cpp	\



					
LOCAL_SRC_FILES +=  /../../../../dependency/gdx2d/gdx2d.c \
					/../../../../dependency/gdx2d/StbImage.c \
					

#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


