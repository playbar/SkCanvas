LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := icu

LOCAL_CFLAGS +=  \
				-fshort-wchar	\
				-fexceptions
				
LOCAL_C_INCLUDES :=  \
					$(JNI_H_INCLUDE)  \
					$(LOCAL_PATH)      \
					$../../third_party/libpng \
					$../../third_party/icu/source/common \
					$../../third_party/icu/source/i18n \

#i18n
LOCAL_SRC_FILES	+=  ../../../third_party/icu/source/i18n/anytrans.cpp \
					../../../third_party/icu/source/i18n/astro.cpp \
					../../../third_party/icu/source/i18n/basictz.cpp \
					../../../third_party/icu/source/i18n/bms.cpp \
					../../../third_party/icu/source/i18n/bmsearch.cpp \
					../../../third_party/icu/source/i18n/bocsu.c \
					../../../third_party/icu/source/i18n/brktrans.cpp \
					../../../third_party/icu/source/i18n/buddhcal.cpp \
					../../../third_party/icu/source/i18n/calendar.cpp \
					../../../third_party/icu/source/i18n/casetrn.cpp \
					../../../third_party/icu/source/i18n/cecal.cpp \
					../../../third_party/icu/source/i18n/chnsecal.cpp \
					../../../third_party/icu/source/i18n/choicfmt.cpp \
					../../../third_party/icu/source/i18n/coleitr.cpp \
					../../../third_party/icu/source/i18n/coll.cpp \
					../../../third_party/icu/source/i18n/colldata.cpp \
					../../../third_party/icu/source/i18n/coptccal.cpp \
					../../../third_party/icu/source/i18n/cpdtrans.cpp \
					../../../third_party/icu/source/i18n/csdetect.cpp \
					../../../third_party/icu/source/i18n/csmatch.cpp \
					../../../third_party/icu/source/i18n/csr2022.cpp \
					../../../third_party/icu/source/i18n/csrecog.cpp \
					../../../third_party/icu/source/i18n/csrmbcs.cpp \
					
					
					
				


#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


