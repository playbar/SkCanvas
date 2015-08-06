LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := skia

LOCAL_CFLAGS += \
				-DSK_BUILD_FOR_ANDROID \
				-D_ARGB_PIXEL_  \
				-DSK_SUPPORT_GPU \
				-DSK_IGNORE_ETC1_SUPPORT \
				-DGL_GLEXT_PROTOTYPES \
				-fexceptions
#				-fshort-wchar	
#				-DGL_GLEXT_PROTOTYPES
				
LOCAL_LDLIBS    := -llog -lGLESv2 -lEGL -lz

				
LOCAL_C_INCLUDES := $../../skia/include/core \
					$../../skia/src/core \
					$../../skia/src/image \
					$../../skia/include/utils \
					$../../skia/include \
					$../../skia/src/gpu \
					$../../skia/include/gpu \
					$../../skia/include/pathops \
					$../../skia/include/ports \
					$../../skia/include/effects \
					$../../skia/include/config \
					$../../skia/include/gpu/gl \
					$../../skia/src/opts \
					$../../skia/src/sfnt \
					$../../skia/src/utils \
					$../../skia/include/images \
					$../../skia/third_party/externals/libpng \
					$../../skia/third_party/freetype/include \
					$../../ \
					
					
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

##core
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/core/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
			
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/effects/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
					 			
			
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/effects/gradients/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#--todo
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/gpu/effects/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/gpu/gl/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)

LOCAL_SRC_FILES +=  ../../../skia/src/gpu/gl/android/GrGLCreateNativeInterface_android.cpp \
					../../../skia/src/gpu/gl/android/SkNativeGLContext_android.cpp 

MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/gpu/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)
			
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/image/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

	
#images
LOCAL_SRC_FILES	+=  ../../../skia/src/images/SkImageDecoder.cpp \
					../../../skia/src/images/SkImageDecoder_FactoryDefault.cpp \
					../../../skia/src/images/SkImageDecoder_FactoryRegistrar.cpp \
					../../../skia/src/images/SkImageEncoder.cpp \
					../../../skia/src/images/SkImageEncoder_Factory.cpp \
					../../../skia/src/images/SkScaledBitmapSampler.cpp 
					#../../../skia/src/images/SkImageDecoder_libpng.cpp \
					
#lazy
LOCAL_SRC_FILES	+=  ../../../skia/src/lazy/SkCachingPixelRef.cpp \
					../../../skia/src/lazy/SkDiscardableMemoryPool.cpp \
					../../../skia/src/lazy/SkDiscardablePixelRef.cpp \

#opts 
LOCAL_SRC_FILES	+=  ../../../skia/src/opts/SkBitmapProcState_opts_none.cpp \
					../../../skia/src/opts/SkBlitRow_opts_none.cpp \
					../../../skia/src/opts/SkBlurImage_opts_none.cpp \
					../../../skia/src/opts/SkMorphology_opts_none.cpp \
					../../../skia/src/opts/SkUtils_opts_none.cpp \
					../../../skia/src/opts/SkXfermode_opts_none.cpp \
					../../../skia/src/opts/SkBlitMask_opts_none.cpp
					

#pathops
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../skia/src/pathops/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#ports
LOCAL_SRC_FILES	+=  ../../../skia/src/ports/SkFontHost_none.cpp \
					../../../skia/src/ports/SkOSFile_none.cpp \
					../../../skia/src/ports/SkOSFile_stdio.cpp \
					../../../skia/src/ports/SkTLS_none.cpp \
					../../../skia/src/ports/SkMemory_malloc.cpp \
					../../../skia/src/ports/SkDebug_android.cpp \
					../../../skia/src/ports/SkGlobalInitialization_default.cpp
					#../../../skia/src/ports/SkFontConfigInterface_android.cpp \

#sfnt
LOCAL_SRC_FILES	+=  ../../../skia/src/sfnt/SkOTTable_name.cpp \
					../../../skia/src/sfnt/SkOTUtils.cpp \
					

#utils
LOCAL_SRC_FILES	+=  ../../../skia/src/utils/SkBase64.cpp \
					../../../skia/src/utils/SkBitSet.cpp \
					../../../skia/src/utils/SkCanvasStack.cpp \
					../../../skia/src/utils/SkCanvasStateUtils.cpp \
					../../../skia/src/utils/SkInterpolator.cpp \
					../../../skia/src/utils/SkMatrix44.cpp \
					../../../skia/src/utils/SkNullCanvas.cpp \
					../../../skia/src/utils/SkNWayCanvas.cpp \
					../../../skia/src/utils/SkParse.cpp \
					../../../skia/src/utils/SkParseColor.cpp \
					../../../skia/src/utils/SkPictureUtils.cpp \
					../../../skia/src/utils/SkProxyCanvas.cpp \
					../../../skia/src/utils/SkRTConf.cpp \
					../../../skia/src/utils/SkDashPath.cpp \
					../../../skia/src/utils/SkEventTracer.cpp \
					../../../skia/src/utils/SkTextureCompressor.cpp \
					

#png
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/libpng/*.c)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	


#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)
$(call import-add-path,$(LOCAL_PATH)/..)

#$(call import-module,../../android/jni/png/prebuilt/android)

