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
					$../../third_party/harfbuzz-ng/src   \			

#harfbuzz
LOCAL_SRC_FILES	+=  ../../../third_party/harfbuzz-ng/src/hb-blob.cc \
					../../../third_party/harfbuzz-ng/src/hb-buffer.cc \
					../../../third_party/harfbuzz-ng/src/hb-buffer-serialize.cc \
					../../../third_party/harfbuzz-ng/src/hb-common.cc \
					../../../third_party/harfbuzz-ng/src/hb-face.cc \
					../../../third_party/harfbuzz-ng/src/hb-fallback-shape.cc \
					../../../third_party/harfbuzz-ng/src/hb-font.cc \
					
					 
					


					



#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


