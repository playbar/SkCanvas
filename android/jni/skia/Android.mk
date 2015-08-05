LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm

LOCAL_MODULE := skia

LOCAL_CFLAGS += \
				-DSK_BUILD_FOR_ANDROID \
				-D_ARGB_PIXEL_  \
				-DSK_SUPPORT_GPU \
				-fexceptions
#				-fshort-wchar	
#				-DGL_GLEXT_PROTOTYPES
				
LOCAL_LDLIBS    := -llog -lGLESv2 -ljnigraphics -lEGL -lz
LOCAL_EXPORT_LDLIBS :=-lz

				
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
					$../../skia/src/opts \
					$../../skia/src/sfnt \
					$../../skia/include/images \
					$../../freetype2/include/android/freetype2 \
					$../../freetype2/include/android \
					$../../ \
					$../../skia/config \
					$../../android/jni \
#					$../../third_party\libpng \
#					$../../../third_party/zlib \
#					$../../../third_party/zlib/google \
#					$../../../third_party/zlib/contrib/minizip
					
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := SkUserConfig_android.cpp \
				   ../../../skia/ext/SkMemory_new_handler.cpp

MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/core/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
			
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/effects/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	
					 			
			
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/effects/gradients/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#--todo
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/gpu/effects/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/gpu/gl/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)

MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/gpu/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)
			
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/image/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

	

#images
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/images/SkImageDecoder.cpp \
					../../../third_party/skia/src/images/SkImageDecoder_FactoryDefault.cpp \
					../../../third_party/skia/src/images/SkImageDecoder_FactoryRegistrar.cpp \
					../../../third_party/skia/src/images/SkImageDecoder_libpng.cpp \
					../../../third_party/skia/src/images/SkImageEncoder.cpp \
					../../../third_party/skia/src/images/SkImageEncoder_Factory.cpp \
					../../../third_party/skia/src/images/SkImageRef.cpp \
					../../../third_party/skia/src/images/SkImageRef_GlobalPool.cpp \
					../../../third_party/skia/src/images/SkImageRefPool.cpp \
					../../../third_party/skia/src/images/SkImages.cpp \
					../../../third_party/skia/src/images/SkScaledBitmapSampler.cpp \
					../../../third_party/skia/src/images/SkImageRef_ashmem.cpp
					
#lazy
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/lazy/SkCachingPixelRef.cpp \
					../../../third_party/skia/src/lazy/SkDiscardableMemoryPool.cpp \
					../../../third_party/skia/src/lazy/SkDiscardablePixelRef.cpp \

#opts 
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/opts/SkBitmapProcState_opts_none.cpp \
					../../../third_party/skia/src/opts/SkBlitRow_opts_none.cpp \
					../../../third_party/skia/src/opts/SkBlurImage_opts_none.cpp \
					../../../third_party/skia/src/opts/SkMorphology_opts_none.cpp \
					../../../third_party/skia/src/opts/SkUtils_opts_none.cpp \
					../../../third_party/skia/src/opts/SkXfermode_opts_none.cpp \
					../../../third_party/skia/src/opts/SkBlitMask_opts_none.cpp
					

#pathops
MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/skia/src/pathops/*.cpp)
MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += $(MY_FILES)	

#ports
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/ports/SkFontHost_none.cpp \
					../../../third_party/skia/src/ports/SkOSFile_none.cpp \
					../../../third_party/skia/src/ports/SkOSFile_stdio.cpp \
					../../../third_party/skia/src/ports/SkFontHost_FreeType.cpp \
					../../../third_party/skia/src/ports/SkFontHost_FreeType_common.cpp \
					../../../third_party/skia/src/ports/SkFontHost_fontconfig.cpp \
					../../../third_party/skia/src/ports/SkFontConfigInterface_android.cpp \
					../../../third_party/skia/src/ports/SkTLS_none.cpp \
					../../../third_party/skia/src/ports/SkGlobalInitialization_default.cpp

#sfnt
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/sfnt/SkOTTable_name.cpp \
					../../../third_party/skia/src/sfnt/SkOTUtils.cpp \
					

#utils
LOCAL_SRC_FILES	+=  ../../../third_party/skia/src/utils/SkBase64.cpp \
					../../../third_party/skia/src/utils/SkBitSet.cpp \
					../../../third_party/skia/src/utils/SkCanvasStack.cpp \
					../../../third_party/skia/src/utils/SkCanvasStateUtils.cpp \
					../../../third_party/skia/src/utils/SkInterpolator.cpp \
					../../../third_party/skia/src/utils/SkMatrix44.cpp \
					../../../third_party/skia/src/utils/SkNullCanvas.cpp \
					../../../third_party/skia/src/utils/SkNWayCanvas.cpp \
					../../../third_party/skia/src/utils/SkParse.cpp \
					../../../third_party/skia/src/utils/SkParseColor.cpp \
					../../../third_party/skia/src/utils/SkPictureUtils.cpp \
					../../../third_party/skia/src/utils/SkProxyCanvas.cpp \
					../../../third_party/skia/src/utils/SkRTConf.cpp\
					../../../third_party/skia/src/utils/android/ashmem.cpp

#png
#MY_FILES := $(wildcard $(LOCAL_PATH)/../../../third_party/libpng/*.c)
#MY_FILES := $(MY_FILES:$(LOCAL_PATH)/%=%)
#LOCAL_SRC_FILES += $(MY_FILES)	


#LOCAL_LDLIBS := $(MY_LIBRARY)

include $(BUILD_STATIC_LIBRARY)
$(call import-add-path,$(LOCAL_PATH)/..)
$(call import-module,../../android/jni/png/prebuilt/android)

