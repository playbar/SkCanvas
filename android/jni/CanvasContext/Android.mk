LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := canvascontext2d

LOCAL_CFLAGS += -DUSE_MMAP\
				-fexceptions
				
LOCAL_C_INCLUDES := $../../CanvasContext/Canvas2D \
					$../../CanvasContext/geometry \
					$../../CanvasContext/utils \
					$../../skia/include/utils \
					$../../skia/include/core \
					$../../skia/include/config \
					$../../skia/include/effects \
				

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)	

#harfbuzz
LOCAL_SRC_FILES	+=  \
					../../../CanvasContext/utils/AffineTransform.cpp \
					../../../CanvasContext/utils/TypeTraits.cpp \
					../../../CanvasContext/utils/TransformationMatrix.cpp \
					../../../CanvasContext/utils/SkiaUtils.cpp \
					../../../CanvasContext/geometry/FloatPoint.cpp \
					../../../CanvasContext/geometry/FloatPoint3D.cpp \
					../../../CanvasContext/geometry/FloatQuad.cpp \
					../../../CanvasContext/geometry/FloatRect.cpp \
					../../../CanvasContext/geometry/FloatSize.cpp \
					../../../CanvasContext/geometry/IntRect.cpp \
					../../../CanvasContext/geometry/LayoutRect.cpp \
					../../../CanvasContext/geometry/RoundedRect.cpp \
					../../../CanvasContext/Canvas2D/BitmapImage.cpp \
					../../../CanvasContext/Canvas2D/CanvasContext2D.cpp \
					../../../CanvasContext/Canvas2D/CanvasGradient.cpp \
					../../../CanvasContext/Canvas2D/CanvasPattern.cpp \
					../../../CanvasContext/Canvas2D/CanvasStyle.cpp \
					../../../CanvasContext/Canvas2D/Color.cpp \
					../../../CanvasContext/Canvas2D/ColorData.cpp \
					../../../CanvasContext/Canvas2D/CSSParserMode.cpp \
					../../../CanvasContext/Canvas2D/CSSValueKeywords.cpp \
					../../../CanvasContext/Canvas2D/FontDescription.cpp \
					../../../CanvasContext/Canvas2D/DrawLooperBuilder.cpp \
					../../../CanvasContext/Canvas2D/Gradient.cpp \
					../../../CanvasContext/Canvas2D/GraphicsTypes.cpp \
					../../../CanvasContext/Canvas2D/ImageData.cpp \
					../../../CanvasContext/Canvas2D/Pattern.cpp 
				
					

					
				
#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)


