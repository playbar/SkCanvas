LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := harfbuzz

LOCAL_CFLAGS += \
				-DGL_GLEXT_PROTOTYPES \
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
					$../../third_party/skia/src/sfnt \
					$../../third_party/skia/include/images \
					$../../third_party/freetype2/include/android/freeType2 \
					$../../third_party/freetype2/include/android \
					$../../ \
					$../../skia/config \
					


#harfbuzz
LOCAL_SRC_FILES	+=  ../../../third_party/harfbuzz/src/hb-blob.cc \
					 
					


					



#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


