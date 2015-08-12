LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := runtimecanvas

LOCAL_ARM_MODE := arm

LOCAL_CFLAGS    := -Werror \
				-DSK_SUPPORT_GPU

LOCAL_SRC_FILES := gl_code.cpp \
				   GlesUtil.cpp \
				   SkiaApp.cpp \
				   JniShell.cpp \
				   EGTLog.cpp \
				   StdC.cpp
				   
LOCAL_SRC_FILES	+=  \
					../../skia/third_party/externals/zlib/adler32.c \
					../../skia/third_party/externals/zlib/compress.c \
					../../skia/third_party/externals/zlib/crc32.c \
					../../skia/third_party/externals/zlib/deflate.c \
					../../skia/third_party/externals/zlib/gzclose.c \
					../../skia/third_party/externals/zlib/gzlib.c \
					../../skia/third_party/externals/zlib/gzread.c \
					../../skia/third_party/externals/zlib/gzwrite.c \
					../../skia/third_party/externals/zlib/infback.c \
					../../skia/third_party/externals/zlib/inflate.c \
					../../skia/third_party/externals/zlib/inftrees.c \
					../../skia/third_party/externals/zlib/inffast.c \
					../../skia/third_party/externals/zlib/trees.c \
					../../skia/third_party/externals/zlib/uncompr.c \
					../../skia/third_party/externals/zlib/zutil.c \
				  
LOCAL_STATIC_LIBRARIES := skia
LOCAL_STATIC_LIBRARIES += png
LOCAL_STATIC_LIBRARIES += canvascontext2d
LOCAL_STATIC_LIBRARIES += freetype
#LOCAL_STATIC_LIBRARIES += zlib
#LOCAL_STATIC_LIBRARIES += stlport


LOCAL_LDLIBS    := -llog -lGLESv2 -lEGL

#include $(BUILD_STATIC_LIBRARY)

include $(BUILD_SHARED_LIBRARY)


include $(call all-makefiles-under,$(LOCAL_PATH))

$(call import-add-path,$(LOCAL_PATH))



