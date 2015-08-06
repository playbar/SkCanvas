LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := zlib

LOCAL_CFLAGS += -DUSE_MMAP\
				-fexceptions
				
LOCAL_C_INCLUDES := $../../skia/third_party/externals/zlib \
				

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)	

#harfbuzz
LOCAL_SRC_FILES	+=  \
					../../../skia/third_party/externals/zlib/adler32.c \
					../../../skia/third_party/externals/zlib/compress.c \
					../../../skia/third_party/externals/zlib/crc32.c \
					../../../skia/third_party/externals/zlib/deflate.c \
					../../../skia/third_party/externals/zlib/gzclose.c \
					../../../skia/third_party/externals/zlib/gzlib.c \
					../../../skia/third_party/externals/zlib/gzread.c \
					../../../skia/third_party/externals/zlib/gzwrite.c \
					../../../skia/third_party/externals/zlib/infback.c \
					../../../skia/third_party/externals/zlib/inftrees.c \
					../../../skia/third_party/externals/zlib/inffast.c \
					../../../skia/third_party/externals/zlib/trees.c \
					../../../skia/third_party/externals/zlib/uncompr.c \
					../../../skia/third_party/externals/zlib/zutil.c \
					
				
#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


