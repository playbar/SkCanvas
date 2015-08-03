LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := harfbuzz

LOCAL_CFLAGS += -DHAVE_OT \
				-DGL_GLEXT_PROTOTYPES \
				-DHB_NO_UNICODE_FUNCS  \
				-DHB_NO_MT \
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
					$../../third_party/icu/source/common \		

#harfbuzz
LOCAL_SRC_FILES	+=  ../../../third_party/harfbuzz-ng/src/hb-blob.cc \
					../../../third_party/harfbuzz-ng/src/hb-buffer.cc \
					../../../third_party/harfbuzz-ng/src/hb-buffer-serialize.cc \
					../../../third_party/harfbuzz-ng/src/hb-common.cc \
					../../../third_party/harfbuzz-ng/src/hb-face.cc \
					../../../third_party/harfbuzz-ng/src/hb-fallback-shape.cc \
					../../../third_party/harfbuzz-ng/src/hb-font.cc \
					../../../third_party/harfbuzz-ng/src/hb-icu.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-layout.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-map.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-arabic.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-default.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-hangul.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-hebrew.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-indic.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-indic-table.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-myanmar.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-sea.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-thai.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-complex-tibetan.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-fallback.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-shape-normalize.cc \
					../../../third_party/harfbuzz-ng/src/hb-ot-tag.cc \
					../../../third_party/harfbuzz-ng/src/hb-set.cc \
					../../../third_party/harfbuzz-ng/src/hb-shape.cc \
					../../../third_party/harfbuzz-ng/src/hb-shape-plan.cc \
					../../../third_party/harfbuzz-ng/src/hb-shaper.cc \
					../../../third_party/harfbuzz-ng/src/hb-tt-font.cc \
					../../../third_party/harfbuzz-ng/src/hb-unicode.cc \
					../../../third_party/harfbuzz-ng/src/hb-warning.cc
					
				


#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


