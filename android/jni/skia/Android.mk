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
					$../../third_party/libpng \
					$../../third_party/skia/include/core   \
					$../../third_party/skia/src/core \
					$../../third_party/skia/src/image \
					$../../third_party/skia/include/utils \
					$../../third_party/skia/include \
					$../../third_party/skia/src/gpu \
					$../../third_party/skia/include/gpu \
					$../../third_party/skia/include/pathops \
					$../../third_party/skia/include/ports \
					$../../third_party/skia/include/effects \
					$../../third_party/skia/src/opts \
					$../../third_party/skia/include/images \
					$../../ \
					$../../skia/config \
					


#LOCAL_SRC_FILES += \
#		../../../third_party/skia/src/core/*.cpp \
		
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/core/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	
			
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/effects/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	
					 			
			
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/effects/gradients/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	

#--todo
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/gpu/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	
			
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/image/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	

	

#images
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/images/SkImageDecoder.cpp \
					../../../third_party/skia/src/images/SkImageDecoder_FactoryDefault.cpp \
					../../../third_party/skia/src/images/SkImageDecoder_FactoryRegistrar.cpp \
					../../../third_party/skia/src/images/SkImageDecoder_libpng.cpp \
					../../../third_party/skia/src/images/SkImageEncoder.cpp \
					../../../third_party/skia/src/images/SkImageEncoder_Factory.cpp \
					../../../third_party/skia/src/images/SkImageRef.cpp \
					../../../third_party/skia/src/images/SkImageRef_GlobalPool.cpp \
					../../../third_party/skia/src/images/SkImageRefPool.cpp \
					../../../third_party/skia/src/images/SkImages.cpp \
					../../../third_party/skia/src/images/SkScaledBitmapSampler.cpp \
					
#lazy
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/lazy/SkCachingPixelRef.cpp \
					../../../third_party/skia/src/lazy/SkDiscardableMemoryPool.cpp \					

#opts 
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/opts/opts_check_SSE2.cpp \

				 
#base android
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../../src/base/android/*.cpp)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)				
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/images/Error.cp \



#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


