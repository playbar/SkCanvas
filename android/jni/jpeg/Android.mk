LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := jpeg

LOCAL_CFLAGS += \
				-fexceptions
				
LOCAL_C_INCLUDES := $../../skia/third_party/externals/libjpeg \
					$../../skia/third_party/externals/zlib \
				

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)	

#libpng
LOCAL_SRC_FILES	+=  ../../../skia/third_party/externals/libjpeg/jcapimin.c \
					../../../skia/third_party/externals/libjpeg/jcapistd.c \
					../../../skia/third_party/externals/libjpeg/jccoefct.c \
					../../../skia/third_party/externals/libjpeg/jccolor.c \
					../../../skia/third_party/externals/libjpeg/jcdctmgr.c \
					../../../skia/third_party/externals/libjpeg/jchuff.c \
					../../../skia/third_party/externals/libjpeg/jcinit.c \
					../../../skia/third_party/externals/libjpeg/jcmainct.c \
					../../../skia/third_party/externals/libjpeg/jcmarker.c \
					../../../skia/third_party/externals/libjpeg/jcmaster.c \
					../../../skia/third_party/externals/libjpeg/jcomapi.c \
					../../../skia/third_party/externals/libjpeg/jcparam.c \
					../../../skia/third_party/externals/libjpeg/jcphuff.c \
					../../../skia/third_party/externals/libjpeg/jcprepct.c \
					../../../skia/third_party/externals/libjpeg/jcsample.c \
					../../../skia/third_party/externals/libjpeg/jdapimin.c \
					../../../skia/third_party/externals/libjpeg/jdapistd.c \
					../../../skia/third_party/externals/libjpeg/jdatadst.c \
					../../../skia/third_party/externals/libjpeg/jdatasrc.c \
					../../../skia/third_party/externals/libjpeg/jdcoefct.c \
					../../../skia/third_party/externals/libjpeg/jdcolor.c \
					../../../skia/third_party/externals/libjpeg/jddctmgr.c \
					../../../skia/third_party/externals/libjpeg/jdhuff.c \
					../../../skia/third_party/externals/libjpeg/jdinput.c \
					../../../skia/third_party/externals/libjpeg/jdmainct.c \
					../../../skia/third_party/externals/libjpeg/jdmarker.c \
					../../../skia/third_party/externals/libjpeg/jdmerge.c \
					../../../skia/third_party/externals/libjpeg/jdpostct.c \
					../../../skia/third_party/externals/libjpeg/jdsample.c \
					../../../skia/third_party/externals/libjpeg/jerror.c \
					../../../skia/third_party/externals/libjpeg/jfdctint.c \
					../../../skia/third_party/externals/libjpeg/jidctflt.c \
					../../../skia/third_party/externals/libjpeg/jidctfst.c \
					../../../skia/third_party/externals/libjpeg/jidctint.c \
					../../../skia/third_party/externals/libjpeg/jidctred.c \
					../../../skia/third_party/externals/libjpeg/jmemmgr.c \
					../../../skia/third_party/externals/libjpeg/jmemnobs.c \
					../../../skia/third_party/externals/libjpeg/jquant1.c \
					../../../skia/third_party/externals/libjpeg/jquant2.c \
					../../../skia/third_party/externals/libjpeg/jsimd_none.c \
					../../../skia/third_party/externals/libjpeg/jutils.c \

			
				
#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


