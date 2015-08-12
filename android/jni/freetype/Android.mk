# this is now the default FreeType build for Android
#

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# compile in ARM mode, since the glyph loader/renderer is a hotspot
# when loading complex pages in the browser
#
LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES:= \
	../../../skia/third_party/freetype/src/base/ftbbox.c \
	../../../skia/third_party/freetype/src/base/ftbitmap.c \
	../../../skia/third_party/freetype/src/base/ftfstype.c \
	../../../skia/third_party/freetype/src/base/ftglyph.c \
	../../../skia/third_party/freetype/src/base/ftlcdfil.c \
	../../../skia/third_party/freetype/src/base/ftstroke.c \
	../../../skia/third_party/freetype/src/base/fttype1.c \
	../../../skia/third_party/freetype/src/base/ftxf86.c \
	../../../skia/third_party/freetype/src/base/ftbase.c \
	../../../skia/third_party/freetype/src/base/ftsystem.c \
	../../../skia/third_party/freetype/src/base/ftinit.c \
	../../../skia/third_party/freetype/src/base/ftgasp.c \
	../../../skia/third_party/freetype/src/gzip/ftgzip.c \
	../../../skia/third_party/freetype/src/raster/raster.c \
	../../../skia/third_party/freetype/src/sfnt/sfnt.c \
	../../../skia/third_party/freetype/src/smooth/smooth.c \
	../../../skia/third_party/freetype/src/autofit/autofit.c \
	../../../skia/third_party/freetype/src/truetype/truetype.c \
	../../../skia/third_party/freetype/src/cff/cff.c \
	../../../skia/third_party/freetype/src/psnames/psnames.c \
	../../../skia/third_party/freetype/src/pshinter/pshinter.c

LOCAL_C_INCLUDES += \
				$../../skia/third_party/freetype/include \

LOCAL_CFLAGS += -W -Wall
LOCAL_CFLAGS += -fPIC -DPIC
LOCAL_CFLAGS += "-DDARWIN_NO_CARBON"
LOCAL_CFLAGS += "-DFT2_BUILD_LIBRARY"

LOCAL_SHARED_LIBRARIES += libpng libz

# the following is for testing only, and should not be used in final builds
# of the product
#LOCAL_CFLAGS += "-DTT_CONFIG_OPTION_BYTECODE_INTERPRETER"

LOCAL_CFLAGS += -O2

LOCAL_MODULE:= freetype

include $(BUILD_STATIC_LIBRARY)
