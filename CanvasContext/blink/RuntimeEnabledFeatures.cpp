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

#include "config.h"
#include "RuntimeEnabledFeatures.h"

namespace WebCore {


void RuntimeEnabledFeatures::setStableFeaturesEnabled(bool enable)
{
    setApplicationCacheEnabled(enable);
    setCSSTouchActionEnabled(enable);
    setDatabaseEnabled(enable);
    setDeviceMotionEnabled(enable);
    setDeviceOrientationEnabled(enable);
    setEncryptedMediaAnyVersionEnabled(enable);
    setFileSystemEnabled(enable);
    setFontLoadEventsEnabled(enable);
    setGamepadEnabled(enable);
    setHighResolutionTimeInWorkersEnabled(enable);
    setPrefixedEncryptedMediaEnabled(enable);
    setLocalStorageEnabled(enable);
    setMediaEnabled(enable);
    setMediaSourceEnabled(enable);
    setMediaStreamEnabled(enable);
    setNotificationsEnabled(enable);
    setObjectFitPositionEnabled(enable);
    setPagePopupEnabled(enable);
    setPeerConnectionEnabled(enable);
    setQuotaEnabled(enable);
    setScriptedSpeechEnabled(enable);
    setSessionStorageEnabled(enable);
    setShadowDOMEnabled(enable);
    setSharedWorkerEnabled(enable);
    setSpeechInputEnabled(enable);
    setSpeechSynthesisEnabled(enable);
    setSrcsetEnabled(enable);
    setSVGPaintOrderEnabled(enable);
    setTouchEnabled(enable);
    setVideoTrackEnabled(enable);
    setWebAudioEnabled(enable);
    setWebKitMediaSourceEnabled(enable);
    setWOFF2Enabled(enable);
    setXSLTEnabled(enable);
}

void RuntimeEnabledFeatures::setExperimentalFeaturesEnabled(bool enable)
{
    setClientHintsDprEnabled(enable);
    setCryptoEnabled(enable);
    setCSSAnimationUnprefixedEnabled(enable);
    setCSSCompositingEnabled(enable);
    setCSSExclusionsEnabled(enable);
    setCSSGridLayoutEnabled(enable);
    setCSSMaskSourceTypeEnabled(enable);
    setCSSOMSmoothScrollEnabled(enable);
    setCSSShapesEnabled(enable);
    setCSSStickyPositionEnabled(enable);
    setCSSViewportEnabled(enable);
    setCSSWillChangeEnabled(enable);
    setCSS3TextEnabled(enable);
    setCSS3TextDecorationsEnabled(enable);
    setCustomSchemeHandlerEnabled(enable);
    setDialogElementEnabled(enable);
    setEncodingAPIEnabled(enable);
    setEncryptedMediaEnabled(enable);
    setExperimentalContentSecurityPolicyFeaturesEnabled(enable);
    setFileAPIBlobCloseEnabled(enable);
    setFileConstructorEnabled(enable);
    setIMEAPIEnabled(enable);
    setIndexedDBExperimentalEnabled(enable);
    setInputModeAttributeEnabled(enable);
    setMediaSourceExperimentalEnabled(enable);
    setQuotaPromiseEnabled(enable);
    setRegionBasedColumnsEnabled(enable);
    setScreenOrientationEnabled(enable);
    setScrollTopLeftInteropEnabled(enable);
    setServiceWorkerEnabled(enable);
    setStreamEnabled(enable);
    setStyleScopedEnabled(enable);
    setSubpixelFontScalingEnabled(enable);
    setTargetedStyleRecalcEnabled(enable);
    setUserSelectAllEnabled(enable);
    setWebAnimationsAPIEnabled(enable);
    setWebGLDraftExtensionsEnabled(enable);
    setWebVTTRegionsEnabled(enable);
}

void RuntimeEnabledFeatures::setTestFeaturesEnabled(bool enable)
{
    setBatteryStatusEnabled(enable);
    setBeforeLoadEnabled(enable);
    setCSSTouchActionDelayEnabled(enable);
    setExperimentalCanvasFeaturesEnabled(enable);
    setExperimentalWebSocketEnabled(enable);
    setHTMLImportsEnabled(enable);
    setRequestAutocompleteEnabled(enable);
    setWebMIDIEnabled(enable);
}

bool RuntimeEnabledFeatures::isApplicationCacheEnabled = true;
bool RuntimeEnabledFeatures::isAuthorShadowDOMForAnyElementEnabled = false;
bool RuntimeEnabledFeatures::isBatteryStatusEnabled = false;
bool RuntimeEnabledFeatures::isBeforeLoadEnabled = false;
bool RuntimeEnabledFeatures::isBleedingEdgeFastPathsEnabled = false;
bool RuntimeEnabledFeatures::isClientHintsDprEnabled = false;
bool RuntimeEnabledFeatures::isCryptoEnabled = false;
bool RuntimeEnabledFeatures::isCSSAnimationUnprefixedEnabled = false;
bool RuntimeEnabledFeatures::isCSSCompositingEnabled = false;
bool RuntimeEnabledFeatures::isCSSExclusionsEnabled = false;
bool RuntimeEnabledFeatures::isCSSGridLayoutEnabled = false;
bool RuntimeEnabledFeatures::isCSSMaskSourceTypeEnabled = false;
bool RuntimeEnabledFeatures::isCSSOMSmoothScrollEnabled = false;
bool RuntimeEnabledFeatures::isCSSShapesEnabled = false;
bool RuntimeEnabledFeatures::isCSSStickyPositionEnabled = false;
bool RuntimeEnabledFeatures::isCSSTouchActionEnabled = true;
bool RuntimeEnabledFeatures::isCSSTouchActionDelayEnabled = false;
bool RuntimeEnabledFeatures::isCSSViewportEnabled = false;
bool RuntimeEnabledFeatures::isCSSWillChangeEnabled = false;
bool RuntimeEnabledFeatures::isCSS3TextEnabled = false;
bool RuntimeEnabledFeatures::isCSS3TextDecorationsEnabled = false;
bool RuntimeEnabledFeatures::isCustomSchemeHandlerEnabled = false;
bool RuntimeEnabledFeatures::isDatabaseEnabled = true;
bool RuntimeEnabledFeatures::isDeviceMotionEnabled = true;
bool RuntimeEnabledFeatures::isDeviceOrientationEnabled = true;
bool RuntimeEnabledFeatures::isDialogElementEnabled = false;
bool RuntimeEnabledFeatures::isDirectWriteEnabled = false;
bool RuntimeEnabledFeatures::isEncodingAPIEnabled = false;
bool RuntimeEnabledFeatures::isEncryptedMediaEnabled = false;
bool RuntimeEnabledFeatures::isEncryptedMediaAnyVersionEnabled = true;
bool RuntimeEnabledFeatures::isExperimentalCanvasFeaturesEnabled = false;
bool RuntimeEnabledFeatures::isExperimentalContentSecurityPolicyFeaturesEnabled = false;
bool RuntimeEnabledFeatures::isExperimentalWebSocketEnabled = false;
bool RuntimeEnabledFeatures::isFileAPIBlobCloseEnabled = false;
bool RuntimeEnabledFeatures::isFileConstructorEnabled = false;
bool RuntimeEnabledFeatures::isFileSystemEnabled = true;
bool RuntimeEnabledFeatures::isFontLoadEventsEnabled = true;
bool RuntimeEnabledFeatures::isFastTextAutosizingEnabled = false;
bool RuntimeEnabledFeatures::isGamepadEnabled = true;
bool RuntimeEnabledFeatures::isHTMLImportsEnabled = false;
bool RuntimeEnabledFeatures::isHighResolutionTimeInWorkersEnabled = true;
bool RuntimeEnabledFeatures::isIMEAPIEnabled = false;
bool RuntimeEnabledFeatures::isIndexedDBExperimentalEnabled = false;
bool RuntimeEnabledFeatures::isInputModeAttributeEnabled = false;
bool RuntimeEnabledFeatures::isLangAttributeAwareFormControlUIEnabled = false;
bool RuntimeEnabledFeatures::isPrefixedEncryptedMediaEnabled = true;
bool RuntimeEnabledFeatures::isLocalStorageEnabled = true;
bool RuntimeEnabledFeatures::isMediaEnabled = true;
bool RuntimeEnabledFeatures::isMediaSourceEnabled = true;
bool RuntimeEnabledFeatures::isMediaSourceExperimentalEnabled = false;
bool RuntimeEnabledFeatures::isMediaStreamEnabled = true;
bool RuntimeEnabledFeatures::isNavigatorContentUtilsEnabled = false;
bool RuntimeEnabledFeatures::isNotificationsEnabled = true;
bool RuntimeEnabledFeatures::isObjectFitPositionEnabled = true;
bool RuntimeEnabledFeatures::isOrientationEventEnabled = false;
bool RuntimeEnabledFeatures::isOverlayFullscreenVideoEnabled = false;
bool RuntimeEnabledFeatures::isPagePopupEnabled = true;
bool RuntimeEnabledFeatures::isPathOpsSVGClippingEnabled = false;
bool RuntimeEnabledFeatures::isPeerConnectionEnabled = true;
bool RuntimeEnabledFeatures::isQuotaEnabled = true;
bool RuntimeEnabledFeatures::isQuotaPromiseEnabled = false;
bool RuntimeEnabledFeatures::isOverlayScrollbarsEnabled = false;
bool RuntimeEnabledFeatures::isRegionBasedColumnsEnabled = false;
bool RuntimeEnabledFeatures::isRepaintAfterLayoutEnabled = false;
bool RuntimeEnabledFeatures::isRequestAutocompleteEnabled = false;
bool RuntimeEnabledFeatures::isScreenOrientationEnabled = false;
bool RuntimeEnabledFeatures::isScriptedSpeechEnabled = true;
bool RuntimeEnabledFeatures::isScrollTopLeftInteropEnabled = false;
bool RuntimeEnabledFeatures::isServiceWorkerEnabled = false;
bool RuntimeEnabledFeatures::isSessionStorageEnabled = true;
bool RuntimeEnabledFeatures::isShadowDOMEnabled = true;
bool RuntimeEnabledFeatures::isSharedWorkerEnabled = true;
bool RuntimeEnabledFeatures::isSpeechInputEnabled = true;
bool RuntimeEnabledFeatures::isSpeechSynthesisEnabled = true;
bool RuntimeEnabledFeatures::isSrcsetEnabled = true;
bool RuntimeEnabledFeatures::isStreamEnabled = false;
bool RuntimeEnabledFeatures::isStyleScopedEnabled = false;
bool RuntimeEnabledFeatures::isSubpixelFontScalingEnabled = false;
bool RuntimeEnabledFeatures::isSVGPaintOrderEnabled = true;
bool RuntimeEnabledFeatures::isTargetedStyleRecalcEnabled = false;
bool RuntimeEnabledFeatures::isTouchEnabled = true;
bool RuntimeEnabledFeatures::isTouchIconLoadingEnabled = false;
bool RuntimeEnabledFeatures::isUserSelectAllEnabled = false;
bool RuntimeEnabledFeatures::isVideoTrackEnabled = true;
bool RuntimeEnabledFeatures::isWebAnimationsSVGEnabled = false;
bool RuntimeEnabledFeatures::isWebAnimationsAPIEnabled = false;
#if ENABLE(WEB_AUDIO)
bool RuntimeEnabledFeatures::isWebAudioEnabled = true;
#endif
bool RuntimeEnabledFeatures::isWebGLDraftExtensionsEnabled = false;
bool RuntimeEnabledFeatures::isWebMIDIEnabled = false;
bool RuntimeEnabledFeatures::isWebKitMediaSourceEnabled = true;
bool RuntimeEnabledFeatures::isWebVTTRegionsEnabled = false;
bool RuntimeEnabledFeatures::isWOFF2Enabled = true;
bool RuntimeEnabledFeatures::isXSLTEnabled = true;

} // namespace WebCore
