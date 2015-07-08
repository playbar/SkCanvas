/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RuntimeEnabledFeatures_h
#define RuntimeEnabledFeatures_h

#include "platform/PlatformExport.h"

namespace WebCore {

// A class that stores static enablers for all experimental features.

class PLATFORM_EXPORT RuntimeEnabledFeatures {
public:
    static void setStableFeaturesEnabled(bool);
    static void setExperimentalFeaturesEnabled(bool);
    static void setTestFeaturesEnabled(bool);


    static void setApplicationCacheEnabled(bool isEnabled) { isApplicationCacheEnabled = isEnabled; }
    static bool applicationCacheEnabled() { return isApplicationCacheEnabled; }

    static void setAuthorShadowDOMForAnyElementEnabled(bool isEnabled) { isAuthorShadowDOMForAnyElementEnabled = isEnabled; }
    static bool authorShadowDOMForAnyElementEnabled() { return isAuthorShadowDOMForAnyElementEnabled; }

    static void setBatteryStatusEnabled(bool isEnabled) { isBatteryStatusEnabled = isEnabled; }
    static bool batteryStatusEnabled() { return isBatteryStatusEnabled; }

    static void setBeforeLoadEnabled(bool isEnabled) { isBeforeLoadEnabled = isEnabled; }
    static bool beforeLoadEnabled() { return isBeforeLoadEnabled; }

    static void setBleedingEdgeFastPathsEnabled(bool isEnabled) { isBleedingEdgeFastPathsEnabled = isEnabled; }
    static bool bleedingEdgeFastPathsEnabled() { return isBleedingEdgeFastPathsEnabled; }

    static void setClientHintsDprEnabled(bool isEnabled) { isClientHintsDprEnabled = isEnabled; }
    static bool clientHintsDprEnabled() { return isClientHintsDprEnabled; }

    static void setCryptoEnabled(bool isEnabled) { isCryptoEnabled = isEnabled; }
    static bool cryptoEnabled() { return isCryptoEnabled; }

    static void setCSSAnimationUnprefixedEnabled(bool isEnabled) { isCSSAnimationUnprefixedEnabled = isEnabled; }
    static bool cssAnimationUnprefixedEnabled() { return isCSSAnimationUnprefixedEnabled; }

    static void setCSSCompositingEnabled(bool isEnabled) { isCSSCompositingEnabled = isEnabled; }
    static bool cssCompositingEnabled() { return isCSSCompositingEnabled; }

    static void setCSSExclusionsEnabled(bool isEnabled) { isCSSExclusionsEnabled = isEnabled; }
    static bool cssExclusionsEnabled() { return isCSSExclusionsEnabled; }

    static void setCSSGridLayoutEnabled(bool isEnabled) { isCSSGridLayoutEnabled = isEnabled; }
    static bool cssGridLayoutEnabled() { return isCSSGridLayoutEnabled; }

    static void setCSSMaskSourceTypeEnabled(bool isEnabled) { isCSSMaskSourceTypeEnabled = isEnabled; }
    static bool cssMaskSourceTypeEnabled() { return isCSSMaskSourceTypeEnabled; }

    static void setCSSOMSmoothScrollEnabled(bool isEnabled) { isCSSOMSmoothScrollEnabled = isEnabled; }
    static bool cssomSmoothScrollEnabled() { return isCSSOMSmoothScrollEnabled; }

    static void setCSSShapesEnabled(bool isEnabled) { isCSSShapesEnabled = isEnabled; }
    static bool cssShapesEnabled() { return isCSSShapesEnabled; }

    static void setCSSStickyPositionEnabled(bool isEnabled) { isCSSStickyPositionEnabled = isEnabled; }
    static bool cssStickyPositionEnabled() { return isCSSStickyPositionEnabled; }

    static void setCSSTouchActionEnabled(bool isEnabled) { isCSSTouchActionEnabled = isEnabled; }
    static bool cssTouchActionEnabled() { return isCSSTouchActionEnabled; }

    static void setCSSTouchActionDelayEnabled(bool isEnabled) { isCSSTouchActionDelayEnabled = isEnabled; }
    static bool cssTouchActionDelayEnabled() { return isCSSTouchActionDelayEnabled; }

    static void setCSSViewportEnabled(bool isEnabled) { isCSSViewportEnabled = isEnabled; }
    static bool cssViewportEnabled() { return isCSSViewportEnabled; }

    static void setCSSWillChangeEnabled(bool isEnabled) { isCSSWillChangeEnabled = isEnabled; }
    static bool cssWillChangeEnabled() { return isCSSWillChangeEnabled; }

    static void setCSS3TextEnabled(bool isEnabled) { isCSS3TextEnabled = isEnabled; }
    static bool css3TextEnabled() { return isCSS3TextEnabled; }

    static void setCSS3TextDecorationsEnabled(bool isEnabled) { isCSS3TextDecorationsEnabled = isEnabled; }
    static bool css3TextDecorationsEnabled() { return isCSS3TextDecorationsEnabled; }

    static void setCustomSchemeHandlerEnabled(bool isEnabled) { isCustomSchemeHandlerEnabled = isEnabled; }
    static bool customSchemeHandlerEnabled() { return isCustomSchemeHandlerEnabled && isNavigatorContentUtilsEnabled; }

    static void setDatabaseEnabled(bool isEnabled) { isDatabaseEnabled = isEnabled; }
    static bool databaseEnabled() { return isDatabaseEnabled; }

    static void setDeviceMotionEnabled(bool isEnabled) { isDeviceMotionEnabled = isEnabled; }
    static bool deviceMotionEnabled() { return isDeviceMotionEnabled; }

    static void setDeviceOrientationEnabled(bool isEnabled) { isDeviceOrientationEnabled = isEnabled; }
    static bool deviceOrientationEnabled() { return isDeviceOrientationEnabled; }

    static void setDialogElementEnabled(bool isEnabled) { isDialogElementEnabled = isEnabled; }
    static bool dialogElementEnabled() { return isDialogElementEnabled; }

    static void setDirectWriteEnabled(bool isEnabled) { isDirectWriteEnabled = isEnabled; }
    static bool directWriteEnabled() { return isDirectWriteEnabled; }

    static void setEncodingAPIEnabled(bool isEnabled) { isEncodingAPIEnabled = isEnabled; }
    static bool encodingAPIEnabled() { return isEncodingAPIEnabled; }

    static void setEncryptedMediaEnabled(bool isEnabled) { isEncryptedMediaEnabled = isEnabled; }
    static bool encryptedMediaEnabled() { return isEncryptedMediaEnabled; }

    static void setEncryptedMediaAnyVersionEnabled(bool isEnabled) { isEncryptedMediaAnyVersionEnabled = isEnabled; }
    static bool encryptedMediaAnyVersionEnabled() { return isEncryptedMediaAnyVersionEnabled; }

    static void setExperimentalCanvasFeaturesEnabled(bool isEnabled) { isExperimentalCanvasFeaturesEnabled = isEnabled; }
    static bool experimentalCanvasFeaturesEnabled() { return isExperimentalCanvasFeaturesEnabled; }

    static void setExperimentalContentSecurityPolicyFeaturesEnabled(bool isEnabled) { isExperimentalContentSecurityPolicyFeaturesEnabled = isEnabled; }
    static bool experimentalContentSecurityPolicyFeaturesEnabled() { return isExperimentalContentSecurityPolicyFeaturesEnabled; }

    static void setExperimentalWebSocketEnabled(bool isEnabled) { isExperimentalWebSocketEnabled = isEnabled; }
    static bool experimentalWebSocketEnabled() { return isExperimentalWebSocketEnabled; }

    static void setFileAPIBlobCloseEnabled(bool isEnabled) { isFileAPIBlobCloseEnabled = isEnabled; }
    static bool fileAPIBlobCloseEnabled() { return isFileAPIBlobCloseEnabled; }

    static void setFileConstructorEnabled(bool isEnabled) { isFileConstructorEnabled = isEnabled; }
    static bool fileConstructorEnabled() { return isFileConstructorEnabled; }

    static void setFileSystemEnabled(bool isEnabled) { isFileSystemEnabled = isEnabled; }
    static bool fileSystemEnabled() { return isFileSystemEnabled; }

    static void setFontLoadEventsEnabled(bool isEnabled) { isFontLoadEventsEnabled = isEnabled; }
    static bool fontLoadEventsEnabled() { return isFontLoadEventsEnabled; }

    static void setFastTextAutosizingEnabled(bool isEnabled) { isFastTextAutosizingEnabled = isEnabled; }
    static bool fastTextAutosizingEnabled() { return isFastTextAutosizingEnabled; }

    static void setGamepadEnabled(bool isEnabled) { isGamepadEnabled = isEnabled; }
    static bool gamepadEnabled() { return isGamepadEnabled; }

    static void setHTMLImportsEnabled(bool isEnabled) { isHTMLImportsEnabled = isEnabled; }
    static bool htmlImportsEnabled() { return isHTMLImportsEnabled; }

    static void setHighResolutionTimeInWorkersEnabled(bool isEnabled) { isHighResolutionTimeInWorkersEnabled = isEnabled; }
    static bool highResolutionTimeInWorkersEnabled() { return isHighResolutionTimeInWorkersEnabled; }

    static void setIMEAPIEnabled(bool isEnabled) { isIMEAPIEnabled = isEnabled; }
    static bool imeAPIEnabled() { return isIMEAPIEnabled; }

    static void setIndexedDBExperimentalEnabled(bool isEnabled) { isIndexedDBExperimentalEnabled = isEnabled; }
    static bool indexedDBExperimentalEnabled() { return isIndexedDBExperimentalEnabled; }

    static void setInputModeAttributeEnabled(bool isEnabled) { isInputModeAttributeEnabled = isEnabled; }
    static bool inputModeAttributeEnabled() { return isInputModeAttributeEnabled; }

    static void setLangAttributeAwareFormControlUIEnabled(bool isEnabled) { isLangAttributeAwareFormControlUIEnabled = isEnabled; }
    static bool langAttributeAwareFormControlUIEnabled() { return isLangAttributeAwareFormControlUIEnabled; }

    static void setPrefixedEncryptedMediaEnabled(bool isEnabled) { isPrefixedEncryptedMediaEnabled = isEnabled; }
    static bool prefixedEncryptedMediaEnabled() { return isPrefixedEncryptedMediaEnabled; }

    static void setLocalStorageEnabled(bool isEnabled) { isLocalStorageEnabled = isEnabled; }
    static bool localStorageEnabled() { return isLocalStorageEnabled; }

    static void setMediaEnabled(bool isEnabled) { isMediaEnabled = isEnabled; }
    static bool mediaEnabled() { return isMediaEnabled; }

    static void setMediaSourceEnabled(bool isEnabled) { isMediaSourceEnabled = isEnabled; }
    static bool mediaSourceEnabled() { return isMediaSourceEnabled; }

    static void setMediaSourceExperimentalEnabled(bool isEnabled) { isMediaSourceExperimentalEnabled = isEnabled; }
    static bool mediaSourceExperimentalEnabled() { return isMediaSourceExperimentalEnabled && isMediaSourceEnabled; }

    static void setMediaStreamEnabled(bool isEnabled) { isMediaStreamEnabled = isEnabled; }
    static bool mediaStreamEnabled() { return isMediaStreamEnabled; }

    static void setNavigatorContentUtilsEnabled(bool isEnabled) { isNavigatorContentUtilsEnabled = isEnabled; }
    static bool navigatorContentUtilsEnabled() { return isNavigatorContentUtilsEnabled; }

    static void setNotificationsEnabled(bool isEnabled) { isNotificationsEnabled = isEnabled; }
    static bool notificationsEnabled() { return isNotificationsEnabled; }

    static void setObjectFitPositionEnabled(bool isEnabled) { isObjectFitPositionEnabled = isEnabled; }
    static bool objectFitPositionEnabled() { return isObjectFitPositionEnabled; }

    static void setOrientationEventEnabled(bool isEnabled) { isOrientationEventEnabled = isEnabled; }
    static bool orientationEventEnabled() { return isOrientationEventEnabled; }

    static void setOverlayFullscreenVideoEnabled(bool isEnabled) { isOverlayFullscreenVideoEnabled = isEnabled; }
    static bool overlayFullscreenVideoEnabled() { return isOverlayFullscreenVideoEnabled; }

    static void setPagePopupEnabled(bool isEnabled) { isPagePopupEnabled = isEnabled; }
    static bool pagePopupEnabled() { return isPagePopupEnabled; }

    static void setPathOpsSVGClippingEnabled(bool isEnabled) { isPathOpsSVGClippingEnabled = isEnabled; }
    static bool pathOpsSVGClippingEnabled() { return isPathOpsSVGClippingEnabled; }

    static void setPeerConnectionEnabled(bool isEnabled) { isPeerConnectionEnabled = isEnabled; }
    static bool peerConnectionEnabled() { return isPeerConnectionEnabled && isMediaStreamEnabled; }

    static void setQuotaEnabled(bool isEnabled) { isQuotaEnabled = isEnabled; }
    static bool quotaEnabled() { return isQuotaEnabled; }

    static void setQuotaPromiseEnabled(bool isEnabled) { isQuotaPromiseEnabled = isEnabled; }
    static bool quotaPromiseEnabled() { return isQuotaPromiseEnabled; }

    static void setOverlayScrollbarsEnabled(bool isEnabled) { isOverlayScrollbarsEnabled = isEnabled; }
    static bool overlayScrollbarsEnabled() { return isOverlayScrollbarsEnabled; }

    static void setRegionBasedColumnsEnabled(bool isEnabled) { isRegionBasedColumnsEnabled = isEnabled; }
    static bool regionBasedColumnsEnabled() { return isRegionBasedColumnsEnabled; }

    static void setRepaintAfterLayoutEnabled(bool isEnabled) { isRepaintAfterLayoutEnabled = isEnabled; }
    static bool repaintAfterLayoutEnabled() { return isRepaintAfterLayoutEnabled; }

    static void setRequestAutocompleteEnabled(bool isEnabled) { isRequestAutocompleteEnabled = isEnabled; }
    static bool requestAutocompleteEnabled() { return isRequestAutocompleteEnabled; }

    static void setScreenOrientationEnabled(bool isEnabled) { isScreenOrientationEnabled = isEnabled; }
    static bool screenOrientationEnabled() { return isScreenOrientationEnabled; }

    static void setScriptedSpeechEnabled(bool isEnabled) { isScriptedSpeechEnabled = isEnabled; }
    static bool scriptedSpeechEnabled() { return isScriptedSpeechEnabled; }

    static void setScrollTopLeftInteropEnabled(bool isEnabled) { isScrollTopLeftInteropEnabled = isEnabled; }
    static bool scrollTopLeftInteropEnabled() { return isScrollTopLeftInteropEnabled; }

    static void setServiceWorkerEnabled(bool isEnabled) { isServiceWorkerEnabled = isEnabled; }
    static bool serviceWorkerEnabled() { return isServiceWorkerEnabled; }

    static void setSessionStorageEnabled(bool isEnabled) { isSessionStorageEnabled = isEnabled; }
    static bool sessionStorageEnabled() { return isSessionStorageEnabled; }

    static void setShadowDOMEnabled(bool isEnabled) { isShadowDOMEnabled = isEnabled; }
    static bool shadowDOMEnabled() { return isShadowDOMEnabled; }

    static void setSharedWorkerEnabled(bool isEnabled) { isSharedWorkerEnabled = isEnabled; }
    static bool sharedWorkerEnabled() { return isSharedWorkerEnabled; }

    static void setSpeechInputEnabled(bool isEnabled) { isSpeechInputEnabled = isEnabled; }
    static bool speechInputEnabled() { return isSpeechInputEnabled; }

    static void setSpeechSynthesisEnabled(bool isEnabled) { isSpeechSynthesisEnabled = isEnabled; }
    static bool speechSynthesisEnabled() { return isSpeechSynthesisEnabled; }

    static void setSrcsetEnabled(bool isEnabled) { isSrcsetEnabled = isEnabled; }
    static bool srcsetEnabled() { return isSrcsetEnabled; }

    static void setStreamEnabled(bool isEnabled) { isStreamEnabled = isEnabled; }
    static bool streamEnabled() { return isStreamEnabled; }

    static void setStyleScopedEnabled(bool isEnabled) { isStyleScopedEnabled = isEnabled; }
    static bool styleScopedEnabled() { return isStyleScopedEnabled; }

    static void setSubpixelFontScalingEnabled(bool isEnabled) { isSubpixelFontScalingEnabled = isEnabled; }
    static bool subpixelFontScalingEnabled() { return isSubpixelFontScalingEnabled; }

    static void setSVGPaintOrderEnabled(bool isEnabled) { isSVGPaintOrderEnabled = isEnabled; }
    static bool svgPaintOrderEnabled() { return isSVGPaintOrderEnabled; }

    static void setTargetedStyleRecalcEnabled(bool isEnabled) { isTargetedStyleRecalcEnabled = isEnabled; }
    static bool targetedStyleRecalcEnabled() { return isTargetedStyleRecalcEnabled; }

    static void setTouchEnabled(bool isEnabled) { isTouchEnabled = isEnabled; }
    static bool touchEnabled() { return isTouchEnabled; }

    static void setTouchIconLoadingEnabled(bool isEnabled) { isTouchIconLoadingEnabled = isEnabled; }
    static bool touchIconLoadingEnabled() { return isTouchIconLoadingEnabled; }

    static void setUserSelectAllEnabled(bool isEnabled) { isUserSelectAllEnabled = isEnabled; }
    static bool userSelectAllEnabled() { return isUserSelectAllEnabled; }

    static void setVideoTrackEnabled(bool isEnabled) { isVideoTrackEnabled = isEnabled; }
    static bool videoTrackEnabled() { return isVideoTrackEnabled && isMediaEnabled; }

    static void setWebAnimationsSVGEnabled(bool isEnabled) { isWebAnimationsSVGEnabled = isEnabled; }
    static bool webAnimationsSVGEnabled() { return isWebAnimationsSVGEnabled; }

    static void setWebAnimationsAPIEnabled(bool isEnabled) { isWebAnimationsAPIEnabled = isEnabled; }
    static bool webAnimationsAPIEnabled() { return isWebAnimationsAPIEnabled; }

#if ENABLE(WEB_AUDIO)
    static void setWebAudioEnabled(bool isEnabled) { isWebAudioEnabled = isEnabled; }
    static bool webAudioEnabled() { return isWebAudioEnabled; }
#else
    static void setWebAudioEnabled(bool) { }
    static bool webAudioEnabled() { return false; }
#endif

    static void setWebGLDraftExtensionsEnabled(bool isEnabled) { isWebGLDraftExtensionsEnabled = isEnabled; }
    static bool webGLDraftExtensionsEnabled() { return isWebGLDraftExtensionsEnabled; }

    static void setWebMIDIEnabled(bool isEnabled) { isWebMIDIEnabled = isEnabled; }
    static bool webMIDIEnabled() { return isWebMIDIEnabled; }

    static void setWebKitMediaSourceEnabled(bool isEnabled) { isWebKitMediaSourceEnabled = isEnabled; }
    static bool webKitMediaSourceEnabled() { return isWebKitMediaSourceEnabled; }

    static void setWebVTTRegionsEnabled(bool isEnabled) { isWebVTTRegionsEnabled = isEnabled; }
    static bool webVTTRegionsEnabled() { return isWebVTTRegionsEnabled && isVideoTrackEnabled; }

    static void setWOFF2Enabled(bool isEnabled) { isWOFF2Enabled = isEnabled; }
    static bool woff2Enabled() { return isWOFF2Enabled; }

    static void setXSLTEnabled(bool isEnabled) { isXSLTEnabled = isEnabled; }
    static bool xsltEnabled() { return isXSLTEnabled; }


private:
    RuntimeEnabledFeatures() { }

    static bool isApplicationCacheEnabled;
    static bool isAuthorShadowDOMForAnyElementEnabled;
    static bool isBatteryStatusEnabled;
    static bool isBeforeLoadEnabled;
    static bool isBleedingEdgeFastPathsEnabled;
    static bool isClientHintsDprEnabled;
    static bool isCryptoEnabled;
    static bool isCSSAnimationUnprefixedEnabled;
    static bool isCSSCompositingEnabled;
    static bool isCSSExclusionsEnabled;
    static bool isCSSGridLayoutEnabled;
    static bool isCSSMaskSourceTypeEnabled;
    static bool isCSSOMSmoothScrollEnabled;
    static bool isCSSShapesEnabled;
    static bool isCSSStickyPositionEnabled;
    static bool isCSSTouchActionEnabled;
    static bool isCSSTouchActionDelayEnabled;
    static bool isCSSViewportEnabled;
    static bool isCSSWillChangeEnabled;
    static bool isCSS3TextEnabled;
    static bool isCSS3TextDecorationsEnabled;
    static bool isCustomSchemeHandlerEnabled;
    static bool isDatabaseEnabled;
    static bool isDeviceMotionEnabled;
    static bool isDeviceOrientationEnabled;
    static bool isDialogElementEnabled;
    static bool isDirectWriteEnabled;
    static bool isEncodingAPIEnabled;
    static bool isEncryptedMediaEnabled;
    static bool isEncryptedMediaAnyVersionEnabled;
    static bool isExperimentalCanvasFeaturesEnabled;
    static bool isExperimentalContentSecurityPolicyFeaturesEnabled;
    static bool isExperimentalWebSocketEnabled;
    static bool isFileAPIBlobCloseEnabled;
    static bool isFileConstructorEnabled;
    static bool isFileSystemEnabled;
    static bool isFontLoadEventsEnabled;
    static bool isFastTextAutosizingEnabled;
    static bool isGamepadEnabled;
    static bool isHTMLImportsEnabled;
    static bool isHighResolutionTimeInWorkersEnabled;
    static bool isIMEAPIEnabled;
    static bool isIndexedDBExperimentalEnabled;
    static bool isInputModeAttributeEnabled;
    static bool isLangAttributeAwareFormControlUIEnabled;
    static bool isPrefixedEncryptedMediaEnabled;
    static bool isLocalStorageEnabled;
    static bool isMediaEnabled;
    static bool isMediaSourceEnabled;
    static bool isMediaSourceExperimentalEnabled;
    static bool isMediaStreamEnabled;
    static bool isNavigatorContentUtilsEnabled;
    static bool isNotificationsEnabled;
    static bool isObjectFitPositionEnabled;
    static bool isOrientationEventEnabled;
    static bool isOverlayFullscreenVideoEnabled;
    static bool isPagePopupEnabled;
    static bool isPathOpsSVGClippingEnabled;
    static bool isPeerConnectionEnabled;
    static bool isQuotaEnabled;
    static bool isQuotaPromiseEnabled;
    static bool isOverlayScrollbarsEnabled;
    static bool isRegionBasedColumnsEnabled;
    static bool isRepaintAfterLayoutEnabled;
    static bool isRequestAutocompleteEnabled;
    static bool isScreenOrientationEnabled;
    static bool isScriptedSpeechEnabled;
    static bool isScrollTopLeftInteropEnabled;
    static bool isServiceWorkerEnabled;
    static bool isSessionStorageEnabled;
    static bool isShadowDOMEnabled;
    static bool isSharedWorkerEnabled;
    static bool isSpeechInputEnabled;
    static bool isSpeechSynthesisEnabled;
    static bool isSrcsetEnabled;
    static bool isStreamEnabled;
    static bool isStyleScopedEnabled;
    static bool isSubpixelFontScalingEnabled;
    static bool isSVGPaintOrderEnabled;
    static bool isTargetedStyleRecalcEnabled;
    static bool isTouchEnabled;
    static bool isTouchIconLoadingEnabled;
    static bool isUserSelectAllEnabled;
    static bool isVideoTrackEnabled;
    static bool isWebAnimationsSVGEnabled;
    static bool isWebAnimationsAPIEnabled;
#if ENABLE(WEB_AUDIO)
    static bool isWebAudioEnabled;
#endif
    static bool isWebGLDraftExtensionsEnabled;
    static bool isWebMIDIEnabled;
    static bool isWebKitMediaSourceEnabled;
    static bool isWebVTTRegionsEnabled;
    static bool isWOFF2Enabled;
    static bool isXSLTEnabled;
};

} // namespace WebCore

#endif // RuntimeEnabledFeatures_h
