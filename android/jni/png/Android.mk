LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := png

LOCAL_CFLAGS += \
				-fexceptions
				
LOCAL_C_INCLUDES := $../../skia/third_party/externals/libpng \
					$../../skia/third_party/externals/zlib \
				

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)	

#libpng
LOCAL_SRC_FILES	+=  ../../../skia/third_party/externals/libpng/png.c \
					../../../skia/third_party/externals/libpng/pngerror.c \
					../../../skia/third_party/externals/libpng/pngget.c \
					../../../skia/third_party/externals/libpng/pngmem.c \
					../../../skia/third_party/externals/libpng/pngpread.c \
					../../../skia/third_party/externals/libpng/pngread.c \
					../../../skia/third_party/externals/libpng/pngrio.c \
					../../../skia/third_party/externals/libpng/pngrtran.c \
					../../../skia/third_party/externals/libpng/pngrutil.c \
					../../../skia/third_party/externals/libpng/pngset.c \
					../../../skia/third_party/externals/libpng/pngtrans.c \
					../../../skia/third_party/externals/libpng/pngwio.c \
					../../../skia/third_party/externals/libpng/pngwrite.c \
					../../../skia/third_party/externals/libpng/pngwtran.c \
					../../../skia/third_party/externals/libpng/pngwutil.c \

			
				
#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


