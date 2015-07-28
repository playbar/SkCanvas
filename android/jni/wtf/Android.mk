LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := wtf

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
					$../../third_party/icu/source/common \
					$../../third_party/icu/source/i18n \
					$../../third_party/stlport \
					$../../wtf/dtoa \
					$../../wtf \
					$../../ \		

#dtoa
LOCAL_SRC_FILES	+=  ../../../wtf/dtoa/bignum.cc \
					../../../wtf/dtoa/bignum-dtoa.cc \
					../../../wtf/dtoa/cached-powers.cc \
					../../../wtf/dtoa/diy-fp.cc \
					../../../wtf/dtoa/double-conversion.cc \
					../../../wtf/dtoa/fast-dtoa.cc \
					../../../wtf/dtoa/fixed-dtoa.cc \
					../../../wtf/dtoa/strtod.cc \
					
#text 
LOCAL_SRC_FILES	+=  ../../../wtf/text/AtomicString.cpp \
					../../../wtf/text/Base64.cpp \
					../../../wtf/text/CString.cpp \
					../../../wtf/text/StringBuilder.cpp \
					../../../wtf/text/StringImpl.cpp \
					../../../wtf/text/StringStatics.cpp \
					../../../wtf/text/TextCodec.cpp \
					../../../wtf/text/TextCodecICU.cpp \
					../../../wtf/text/TextCodecLatin1.cpp \
					../../../wtf/text/TextCodecUserDefined.cpp \
					../../../wtf/text/TextCodecUTF8.cpp \
					../../../wtf/text/TextCodecUTF16.cpp \
					../../../wtf/text/TextEncoding.cpp \
					../../../wtf/text/TextEncodingRegistry.cpp \
					../../../wtf/text/TextPosition.cpp \
					../../../wtf/text/WTFString.cpp \
					
#unicode 
LOCAL_SRC_FILES += 	../../../wtf/unicode/icu/CollatorICU.cpp\
					../../../wtf/unicode/WTFUTF8.cpp \
					
#wtf
LOCAL_SRC_FILES += 	../../../wtf/ArrayBuffer.cpp \
					../../../wtf/ArrayBufferBuilder.cpp \
					../../../wtf/ArrayBufferContents.cpp \
					

				
					

				


#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


