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

#ifdef SKIP_STATIC_CONSTRUCTORS_ON_GCC
#define HTML_NAMES_HIDE_GLOBALS 1
#else
#define QNAME_DEFAULT_CONSTRUCTOR 1
#endif

#include "HTMLNames.h"

#include "wtf/StaticConstructors.h"

namespace WebCore {
namespace HTMLNames {

using namespace WebCore;

DEFINE_GLOBAL(AtomicString, xhtmlNamespaceURI)

// Tags
DEFINE_GLOBAL(QualifiedName, abbrTag)
DEFINE_GLOBAL(QualifiedName, acronymTag)
DEFINE_GLOBAL(QualifiedName, addressTag)
DEFINE_GLOBAL(QualifiedName, articleTag)
DEFINE_GLOBAL(QualifiedName, asideTag)
DEFINE_GLOBAL(QualifiedName, bTag)
DEFINE_GLOBAL(QualifiedName, basefontTag)
DEFINE_GLOBAL(QualifiedName, bdoTag)
DEFINE_GLOBAL(QualifiedName, bgsoundTag)
DEFINE_GLOBAL(QualifiedName, bigTag)
DEFINE_GLOBAL(QualifiedName, centerTag)
DEFINE_GLOBAL(QualifiedName, citeTag)
DEFINE_GLOBAL(QualifiedName, codeTag)
DEFINE_GLOBAL(QualifiedName, commandTag)
DEFINE_GLOBAL(QualifiedName, ddTag)
DEFINE_GLOBAL(QualifiedName, dfnTag)
DEFINE_GLOBAL(QualifiedName, dtTag)
DEFINE_GLOBAL(QualifiedName, emTag)
DEFINE_GLOBAL(QualifiedName, figcaptionTag)
DEFINE_GLOBAL(QualifiedName, figureTag)
DEFINE_GLOBAL(QualifiedName, footerTag)
DEFINE_GLOBAL(QualifiedName, headerTag)
DEFINE_GLOBAL(QualifiedName, hgroupTag)
DEFINE_GLOBAL(QualifiedName, iTag)
DEFINE_GLOBAL(QualifiedName, kbdTag)
DEFINE_GLOBAL(QualifiedName, layerTag)
DEFINE_GLOBAL(QualifiedName, mainTag)
DEFINE_GLOBAL(QualifiedName, markTag)
DEFINE_GLOBAL(QualifiedName, navTag)
DEFINE_GLOBAL(QualifiedName, nobrTag)
DEFINE_GLOBAL(QualifiedName, noframesTag)
DEFINE_GLOBAL(QualifiedName, nolayerTag)
DEFINE_GLOBAL(QualifiedName, plaintextTag)
DEFINE_GLOBAL(QualifiedName, rpTag)
DEFINE_GLOBAL(QualifiedName, sTag)
DEFINE_GLOBAL(QualifiedName, sampTag)
DEFINE_GLOBAL(QualifiedName, sectionTag)
DEFINE_GLOBAL(QualifiedName, smallTag)
DEFINE_GLOBAL(QualifiedName, strikeTag)
DEFINE_GLOBAL(QualifiedName, strongTag)
DEFINE_GLOBAL(QualifiedName, subTag)
DEFINE_GLOBAL(QualifiedName, supTag)
DEFINE_GLOBAL(QualifiedName, ttTag)
DEFINE_GLOBAL(QualifiedName, uTag)
DEFINE_GLOBAL(QualifiedName, varTag)
DEFINE_GLOBAL(QualifiedName, aTag)
DEFINE_GLOBAL(QualifiedName, areaTag)
DEFINE_GLOBAL(QualifiedName, audioTag)
DEFINE_GLOBAL(QualifiedName, brTag)
DEFINE_GLOBAL(QualifiedName, baseTag)
DEFINE_GLOBAL(QualifiedName, bodyTag)
DEFINE_GLOBAL(QualifiedName, canvasTag)
DEFINE_GLOBAL(QualifiedName, contentTag)
DEFINE_GLOBAL(QualifiedName, dlTag)
DEFINE_GLOBAL(QualifiedName, datalistTag)
DEFINE_GLOBAL(QualifiedName, detailsTag)
DEFINE_GLOBAL(QualifiedName, dirTag)
DEFINE_GLOBAL(QualifiedName, divTag)
DEFINE_GLOBAL(QualifiedName, fontTag)
DEFINE_GLOBAL(QualifiedName, formTag)
DEFINE_GLOBAL(QualifiedName, frameTag)
DEFINE_GLOBAL(QualifiedName, framesetTag)
DEFINE_GLOBAL(QualifiedName, hrTag)
DEFINE_GLOBAL(QualifiedName, headTag)
DEFINE_GLOBAL(QualifiedName, h1Tag)
DEFINE_GLOBAL(QualifiedName, h2Tag)
DEFINE_GLOBAL(QualifiedName, h3Tag)
DEFINE_GLOBAL(QualifiedName, h4Tag)
DEFINE_GLOBAL(QualifiedName, h5Tag)
DEFINE_GLOBAL(QualifiedName, h6Tag)
DEFINE_GLOBAL(QualifiedName, htmlTag)
DEFINE_GLOBAL(QualifiedName, iframeTag)
DEFINE_GLOBAL(QualifiedName, liTag)
DEFINE_GLOBAL(QualifiedName, labelTag)
DEFINE_GLOBAL(QualifiedName, legendTag)
DEFINE_GLOBAL(QualifiedName, mapTag)
DEFINE_GLOBAL(QualifiedName, marqueeTag)
DEFINE_GLOBAL(QualifiedName, menuTag)
DEFINE_GLOBAL(QualifiedName, metaTag)
DEFINE_GLOBAL(QualifiedName, meterTag)
DEFINE_GLOBAL(QualifiedName, delTag)
DEFINE_GLOBAL(QualifiedName, insTag)
DEFINE_GLOBAL(QualifiedName, olTag)
DEFINE_GLOBAL(QualifiedName, optgroupTag)
DEFINE_GLOBAL(QualifiedName, optionTag)
DEFINE_GLOBAL(QualifiedName, pTag)
DEFINE_GLOBAL(QualifiedName, paramTag)
DEFINE_GLOBAL(QualifiedName, preTag)
DEFINE_GLOBAL(QualifiedName, listingTag)
DEFINE_GLOBAL(QualifiedName, xmpTag)
DEFINE_GLOBAL(QualifiedName, progressTag)
DEFINE_GLOBAL(QualifiedName, blockquoteTag)
DEFINE_GLOBAL(QualifiedName, qTag)
DEFINE_GLOBAL(QualifiedName, shadowTag)
DEFINE_GLOBAL(QualifiedName, sourceTag)
DEFINE_GLOBAL(QualifiedName, spanTag)
DEFINE_GLOBAL(QualifiedName, captionTag)
DEFINE_GLOBAL(QualifiedName, tdTag)
DEFINE_GLOBAL(QualifiedName, thTag)
DEFINE_GLOBAL(QualifiedName, colTag)
DEFINE_GLOBAL(QualifiedName, colgroupTag)
DEFINE_GLOBAL(QualifiedName, tableTag)
DEFINE_GLOBAL(QualifiedName, trTag)
DEFINE_GLOBAL(QualifiedName, tbodyTag)
DEFINE_GLOBAL(QualifiedName, tfootTag)
DEFINE_GLOBAL(QualifiedName, theadTag)
DEFINE_GLOBAL(QualifiedName, templateTag)
DEFINE_GLOBAL(QualifiedName, titleTag)
DEFINE_GLOBAL(QualifiedName, trackTag)
DEFINE_GLOBAL(QualifiedName, ulTag)
DEFINE_GLOBAL(QualifiedName, imageTag)
DEFINE_GLOBAL(QualifiedName, videoTag)
DEFINE_GLOBAL(QualifiedName, dialogTag)
DEFINE_GLOBAL(QualifiedName, buttonTag)
DEFINE_GLOBAL(QualifiedName, fieldsetTag)
DEFINE_GLOBAL(QualifiedName, imgTag)
DEFINE_GLOBAL(QualifiedName, keygenTag)
DEFINE_GLOBAL(QualifiedName, outputTag)
DEFINE_GLOBAL(QualifiedName, selectTag)
DEFINE_GLOBAL(QualifiedName, textareaTag)
DEFINE_GLOBAL(QualifiedName, appletTag)
DEFINE_GLOBAL(QualifiedName, embedTag)
DEFINE_GLOBAL(QualifiedName, linkTag)
DEFINE_GLOBAL(QualifiedName, scriptTag)
DEFINE_GLOBAL(QualifiedName, styleTag)
DEFINE_GLOBAL(QualifiedName, inputTag)
DEFINE_GLOBAL(QualifiedName, objectTag)
DEFINE_GLOBAL(QualifiedName, bdiTag)
DEFINE_GLOBAL(QualifiedName, noembedTag)
DEFINE_GLOBAL(QualifiedName, noscriptTag)
DEFINE_GLOBAL(QualifiedName, rtTag)
DEFINE_GLOBAL(QualifiedName, rubyTag)
DEFINE_GLOBAL(QualifiedName, summaryTag)
DEFINE_GLOBAL(QualifiedName, wbrTag)


PassOwnPtr<const QualifiedName*[]> getHTMLTags()
{
    OwnPtr<const QualifiedName*[]> tags = adoptArrayPtr(new const QualifiedName*[HTMLTagsCount]);
    tags[0] = reinterpret_cast<const QualifiedName*>(&abbrTag);
    tags[1] = reinterpret_cast<const QualifiedName*>(&acronymTag);
    tags[2] = reinterpret_cast<const QualifiedName*>(&addressTag);
    tags[3] = reinterpret_cast<const QualifiedName*>(&articleTag);
    tags[4] = reinterpret_cast<const QualifiedName*>(&asideTag);
    tags[5] = reinterpret_cast<const QualifiedName*>(&bTag);
    tags[6] = reinterpret_cast<const QualifiedName*>(&basefontTag);
    tags[7] = reinterpret_cast<const QualifiedName*>(&bdoTag);
    tags[8] = reinterpret_cast<const QualifiedName*>(&bgsoundTag);
    tags[9] = reinterpret_cast<const QualifiedName*>(&bigTag);
    tags[10] = reinterpret_cast<const QualifiedName*>(&centerTag);
    tags[11] = reinterpret_cast<const QualifiedName*>(&citeTag);
    tags[12] = reinterpret_cast<const QualifiedName*>(&codeTag);
    tags[13] = reinterpret_cast<const QualifiedName*>(&commandTag);
    tags[14] = reinterpret_cast<const QualifiedName*>(&ddTag);
    tags[15] = reinterpret_cast<const QualifiedName*>(&dfnTag);
    tags[16] = reinterpret_cast<const QualifiedName*>(&dtTag);
    tags[17] = reinterpret_cast<const QualifiedName*>(&emTag);
    tags[18] = reinterpret_cast<const QualifiedName*>(&figcaptionTag);
    tags[19] = reinterpret_cast<const QualifiedName*>(&figureTag);
    tags[20] = reinterpret_cast<const QualifiedName*>(&footerTag);
    tags[21] = reinterpret_cast<const QualifiedName*>(&headerTag);
    tags[22] = reinterpret_cast<const QualifiedName*>(&hgroupTag);
    tags[23] = reinterpret_cast<const QualifiedName*>(&iTag);
    tags[24] = reinterpret_cast<const QualifiedName*>(&kbdTag);
    tags[25] = reinterpret_cast<const QualifiedName*>(&layerTag);
    tags[26] = reinterpret_cast<const QualifiedName*>(&mainTag);
    tags[27] = reinterpret_cast<const QualifiedName*>(&markTag);
    tags[28] = reinterpret_cast<const QualifiedName*>(&navTag);
    tags[29] = reinterpret_cast<const QualifiedName*>(&nobrTag);
    tags[30] = reinterpret_cast<const QualifiedName*>(&noframesTag);
    tags[31] = reinterpret_cast<const QualifiedName*>(&nolayerTag);
    tags[32] = reinterpret_cast<const QualifiedName*>(&plaintextTag);
    tags[33] = reinterpret_cast<const QualifiedName*>(&rpTag);
    tags[34] = reinterpret_cast<const QualifiedName*>(&sTag);
    tags[35] = reinterpret_cast<const QualifiedName*>(&sampTag);
    tags[36] = reinterpret_cast<const QualifiedName*>(&sectionTag);
    tags[37] = reinterpret_cast<const QualifiedName*>(&smallTag);
    tags[38] = reinterpret_cast<const QualifiedName*>(&strikeTag);
    tags[39] = reinterpret_cast<const QualifiedName*>(&strongTag);
    tags[40] = reinterpret_cast<const QualifiedName*>(&subTag);
    tags[41] = reinterpret_cast<const QualifiedName*>(&supTag);
    tags[42] = reinterpret_cast<const QualifiedName*>(&ttTag);
    tags[43] = reinterpret_cast<const QualifiedName*>(&uTag);
    tags[44] = reinterpret_cast<const QualifiedName*>(&varTag);
    tags[45] = reinterpret_cast<const QualifiedName*>(&aTag);
    tags[46] = reinterpret_cast<const QualifiedName*>(&areaTag);
    tags[47] = reinterpret_cast<const QualifiedName*>(&audioTag);
    tags[48] = reinterpret_cast<const QualifiedName*>(&brTag);
    tags[49] = reinterpret_cast<const QualifiedName*>(&baseTag);
    tags[50] = reinterpret_cast<const QualifiedName*>(&bodyTag);
    tags[51] = reinterpret_cast<const QualifiedName*>(&canvasTag);
    tags[52] = reinterpret_cast<const QualifiedName*>(&contentTag);
    tags[53] = reinterpret_cast<const QualifiedName*>(&dlTag);
    tags[54] = reinterpret_cast<const QualifiedName*>(&datalistTag);
    tags[55] = reinterpret_cast<const QualifiedName*>(&detailsTag);
    tags[56] = reinterpret_cast<const QualifiedName*>(&dirTag);
    tags[57] = reinterpret_cast<const QualifiedName*>(&divTag);
    tags[58] = reinterpret_cast<const QualifiedName*>(&fontTag);
    tags[59] = reinterpret_cast<const QualifiedName*>(&formTag);
    tags[60] = reinterpret_cast<const QualifiedName*>(&frameTag);
    tags[61] = reinterpret_cast<const QualifiedName*>(&framesetTag);
    tags[62] = reinterpret_cast<const QualifiedName*>(&hrTag);
    tags[63] = reinterpret_cast<const QualifiedName*>(&headTag);
    tags[64] = reinterpret_cast<const QualifiedName*>(&h1Tag);
    tags[65] = reinterpret_cast<const QualifiedName*>(&h2Tag);
    tags[66] = reinterpret_cast<const QualifiedName*>(&h3Tag);
    tags[67] = reinterpret_cast<const QualifiedName*>(&h4Tag);
    tags[68] = reinterpret_cast<const QualifiedName*>(&h5Tag);
    tags[69] = reinterpret_cast<const QualifiedName*>(&h6Tag);
    tags[70] = reinterpret_cast<const QualifiedName*>(&htmlTag);
    tags[71] = reinterpret_cast<const QualifiedName*>(&iframeTag);
    tags[72] = reinterpret_cast<const QualifiedName*>(&liTag);
    tags[73] = reinterpret_cast<const QualifiedName*>(&labelTag);
    tags[74] = reinterpret_cast<const QualifiedName*>(&legendTag);
    tags[75] = reinterpret_cast<const QualifiedName*>(&mapTag);
    tags[76] = reinterpret_cast<const QualifiedName*>(&marqueeTag);
    tags[77] = reinterpret_cast<const QualifiedName*>(&menuTag);
    tags[78] = reinterpret_cast<const QualifiedName*>(&metaTag);
    tags[79] = reinterpret_cast<const QualifiedName*>(&meterTag);
    tags[80] = reinterpret_cast<const QualifiedName*>(&delTag);
    tags[81] = reinterpret_cast<const QualifiedName*>(&insTag);
    tags[82] = reinterpret_cast<const QualifiedName*>(&olTag);
    tags[83] = reinterpret_cast<const QualifiedName*>(&optgroupTag);
    tags[84] = reinterpret_cast<const QualifiedName*>(&optionTag);
    tags[85] = reinterpret_cast<const QualifiedName*>(&pTag);
    tags[86] = reinterpret_cast<const QualifiedName*>(&paramTag);
    tags[87] = reinterpret_cast<const QualifiedName*>(&preTag);
    tags[88] = reinterpret_cast<const QualifiedName*>(&listingTag);
    tags[89] = reinterpret_cast<const QualifiedName*>(&xmpTag);
    tags[90] = reinterpret_cast<const QualifiedName*>(&progressTag);
    tags[91] = reinterpret_cast<const QualifiedName*>(&blockquoteTag);
    tags[92] = reinterpret_cast<const QualifiedName*>(&qTag);
    tags[93] = reinterpret_cast<const QualifiedName*>(&shadowTag);
    tags[94] = reinterpret_cast<const QualifiedName*>(&sourceTag);
    tags[95] = reinterpret_cast<const QualifiedName*>(&spanTag);
    tags[96] = reinterpret_cast<const QualifiedName*>(&captionTag);
    tags[97] = reinterpret_cast<const QualifiedName*>(&tdTag);
    tags[98] = reinterpret_cast<const QualifiedName*>(&thTag);
    tags[99] = reinterpret_cast<const QualifiedName*>(&colTag);
    tags[100] = reinterpret_cast<const QualifiedName*>(&colgroupTag);
    tags[101] = reinterpret_cast<const QualifiedName*>(&tableTag);
    tags[102] = reinterpret_cast<const QualifiedName*>(&trTag);
    tags[103] = reinterpret_cast<const QualifiedName*>(&tbodyTag);
    tags[104] = reinterpret_cast<const QualifiedName*>(&tfootTag);
    tags[105] = reinterpret_cast<const QualifiedName*>(&theadTag);
    tags[106] = reinterpret_cast<const QualifiedName*>(&templateTag);
    tags[107] = reinterpret_cast<const QualifiedName*>(&titleTag);
    tags[108] = reinterpret_cast<const QualifiedName*>(&trackTag);
    tags[109] = reinterpret_cast<const QualifiedName*>(&ulTag);
    tags[110] = reinterpret_cast<const QualifiedName*>(&imageTag);
    tags[111] = reinterpret_cast<const QualifiedName*>(&videoTag);
    tags[112] = reinterpret_cast<const QualifiedName*>(&dialogTag);
    tags[113] = reinterpret_cast<const QualifiedName*>(&buttonTag);
    tags[114] = reinterpret_cast<const QualifiedName*>(&fieldsetTag);
    tags[115] = reinterpret_cast<const QualifiedName*>(&imgTag);
    tags[116] = reinterpret_cast<const QualifiedName*>(&keygenTag);
    tags[117] = reinterpret_cast<const QualifiedName*>(&outputTag);
    tags[118] = reinterpret_cast<const QualifiedName*>(&selectTag);
    tags[119] = reinterpret_cast<const QualifiedName*>(&textareaTag);
    tags[120] = reinterpret_cast<const QualifiedName*>(&appletTag);
    tags[121] = reinterpret_cast<const QualifiedName*>(&embedTag);
    tags[122] = reinterpret_cast<const QualifiedName*>(&linkTag);
    tags[123] = reinterpret_cast<const QualifiedName*>(&scriptTag);
    tags[124] = reinterpret_cast<const QualifiedName*>(&styleTag);
    tags[125] = reinterpret_cast<const QualifiedName*>(&inputTag);
    tags[126] = reinterpret_cast<const QualifiedName*>(&objectTag);
    tags[127] = reinterpret_cast<const QualifiedName*>(&bdiTag);
    tags[128] = reinterpret_cast<const QualifiedName*>(&noembedTag);
    tags[129] = reinterpret_cast<const QualifiedName*>(&noscriptTag);
    tags[130] = reinterpret_cast<const QualifiedName*>(&rtTag);
    tags[131] = reinterpret_cast<const QualifiedName*>(&rubyTag);
    tags[132] = reinterpret_cast<const QualifiedName*>(&summaryTag);
    tags[133] = reinterpret_cast<const QualifiedName*>(&wbrTag);
    return tags.release();
}

// Attributes
DEFINE_GLOBAL(QualifiedName, abbrAttr)
DEFINE_GLOBAL(QualifiedName, acceptAttr)
DEFINE_GLOBAL(QualifiedName, accept_charsetAttr)
DEFINE_GLOBAL(QualifiedName, accesskeyAttr)
DEFINE_GLOBAL(QualifiedName, actionAttr)
DEFINE_GLOBAL(QualifiedName, alignAttr)
DEFINE_GLOBAL(QualifiedName, alinkAttr)
DEFINE_GLOBAL(QualifiedName, allowfullscreenAttr)
DEFINE_GLOBAL(QualifiedName, altAttr)
DEFINE_GLOBAL(QualifiedName, archiveAttr)
DEFINE_GLOBAL(QualifiedName, aria_activedescendantAttr)
DEFINE_GLOBAL(QualifiedName, aria_atomicAttr)
DEFINE_GLOBAL(QualifiedName, aria_busyAttr)
DEFINE_GLOBAL(QualifiedName, aria_checkedAttr)
DEFINE_GLOBAL(QualifiedName, aria_controlsAttr)
DEFINE_GLOBAL(QualifiedName, aria_describedbyAttr)
DEFINE_GLOBAL(QualifiedName, aria_disabledAttr)
DEFINE_GLOBAL(QualifiedName, aria_dropeffectAttr)
DEFINE_GLOBAL(QualifiedName, aria_expandedAttr)
DEFINE_GLOBAL(QualifiedName, aria_flowtoAttr)
DEFINE_GLOBAL(QualifiedName, aria_grabbedAttr)
DEFINE_GLOBAL(QualifiedName, aria_haspopupAttr)
DEFINE_GLOBAL(QualifiedName, aria_helpAttr)
DEFINE_GLOBAL(QualifiedName, aria_hiddenAttr)
DEFINE_GLOBAL(QualifiedName, aria_invalidAttr)
DEFINE_GLOBAL(QualifiedName, aria_labelAttr)
DEFINE_GLOBAL(QualifiedName, aria_labeledbyAttr)
DEFINE_GLOBAL(QualifiedName, aria_labelledbyAttr)
DEFINE_GLOBAL(QualifiedName, aria_levelAttr)
DEFINE_GLOBAL(QualifiedName, aria_liveAttr)
DEFINE_GLOBAL(QualifiedName, aria_multilineAttr)
DEFINE_GLOBAL(QualifiedName, aria_multiselectableAttr)
DEFINE_GLOBAL(QualifiedName, aria_orientationAttr)
DEFINE_GLOBAL(QualifiedName, aria_ownsAttr)
DEFINE_GLOBAL(QualifiedName, aria_posinsetAttr)
DEFINE_GLOBAL(QualifiedName, aria_pressedAttr)
DEFINE_GLOBAL(QualifiedName, aria_readonlyAttr)
DEFINE_GLOBAL(QualifiedName, aria_relevantAttr)
DEFINE_GLOBAL(QualifiedName, aria_requiredAttr)
DEFINE_GLOBAL(QualifiedName, aria_selectedAttr)
DEFINE_GLOBAL(QualifiedName, aria_setsizeAttr)
DEFINE_GLOBAL(QualifiedName, aria_sortAttr)
DEFINE_GLOBAL(QualifiedName, aria_valuemaxAttr)
DEFINE_GLOBAL(QualifiedName, aria_valueminAttr)
DEFINE_GLOBAL(QualifiedName, aria_valuenowAttr)
DEFINE_GLOBAL(QualifiedName, aria_valuetextAttr)
DEFINE_GLOBAL(QualifiedName, asyncAttr)
DEFINE_GLOBAL(QualifiedName, autocompleteAttr)
DEFINE_GLOBAL(QualifiedName, autofocusAttr)
DEFINE_GLOBAL(QualifiedName, autoplayAttr)
DEFINE_GLOBAL(QualifiedName, axisAttr)
DEFINE_GLOBAL(QualifiedName, backgroundAttr)
DEFINE_GLOBAL(QualifiedName, behaviorAttr)
DEFINE_GLOBAL(QualifiedName, bgcolorAttr)
DEFINE_GLOBAL(QualifiedName, bgpropertiesAttr)
DEFINE_GLOBAL(QualifiedName, borderAttr)
DEFINE_GLOBAL(QualifiedName, bordercolorAttr)
DEFINE_GLOBAL(QualifiedName, captureAttr)
DEFINE_GLOBAL(QualifiedName, cellborderAttr)
DEFINE_GLOBAL(QualifiedName, cellpaddingAttr)
DEFINE_GLOBAL(QualifiedName, cellspacingAttr)
DEFINE_GLOBAL(QualifiedName, challengeAttr)
DEFINE_GLOBAL(QualifiedName, charAttr)
DEFINE_GLOBAL(QualifiedName, charoffAttr)
DEFINE_GLOBAL(QualifiedName, charsetAttr)
DEFINE_GLOBAL(QualifiedName, checkedAttr)
DEFINE_GLOBAL(QualifiedName, citeAttr)
DEFINE_GLOBAL(QualifiedName, classAttr)
DEFINE_GLOBAL(QualifiedName, classidAttr)
DEFINE_GLOBAL(QualifiedName, clearAttr)
DEFINE_GLOBAL(QualifiedName, codeAttr)
DEFINE_GLOBAL(QualifiedName, codebaseAttr)
DEFINE_GLOBAL(QualifiedName, codetypeAttr)
DEFINE_GLOBAL(QualifiedName, colorAttr)
DEFINE_GLOBAL(QualifiedName, colsAttr)
DEFINE_GLOBAL(QualifiedName, colspanAttr)
DEFINE_GLOBAL(QualifiedName, compactAttr)
DEFINE_GLOBAL(QualifiedName, compositeAttr)
DEFINE_GLOBAL(QualifiedName, contentAttr)
DEFINE_GLOBAL(QualifiedName, contenteditableAttr)
DEFINE_GLOBAL(QualifiedName, controlsAttr)
DEFINE_GLOBAL(QualifiedName, coordsAttr)
DEFINE_GLOBAL(QualifiedName, crossoriginAttr)
DEFINE_GLOBAL(QualifiedName, dataAttr)
DEFINE_GLOBAL(QualifiedName, datetimeAttr)
DEFINE_GLOBAL(QualifiedName, declareAttr)
DEFINE_GLOBAL(QualifiedName, defaultAttr)
DEFINE_GLOBAL(QualifiedName, deferAttr)
DEFINE_GLOBAL(QualifiedName, dirAttr)
DEFINE_GLOBAL(QualifiedName, directionAttr)
DEFINE_GLOBAL(QualifiedName, dirnameAttr)
DEFINE_GLOBAL(QualifiedName, disabledAttr)
DEFINE_GLOBAL(QualifiedName, dispositionAttr)
DEFINE_GLOBAL(QualifiedName, downloadAttr)
DEFINE_GLOBAL(QualifiedName, draggableAttr)
DEFINE_GLOBAL(QualifiedName, enctypeAttr)
DEFINE_GLOBAL(QualifiedName, endAttr)
DEFINE_GLOBAL(QualifiedName, eventAttr)
DEFINE_GLOBAL(QualifiedName, expandedAttr)
DEFINE_GLOBAL(QualifiedName, faceAttr)
DEFINE_GLOBAL(QualifiedName, focusedAttr)
DEFINE_GLOBAL(QualifiedName, forAttr)
DEFINE_GLOBAL(QualifiedName, formAttr)
DEFINE_GLOBAL(QualifiedName, formactionAttr)
DEFINE_GLOBAL(QualifiedName, formenctypeAttr)
DEFINE_GLOBAL(QualifiedName, formmethodAttr)
DEFINE_GLOBAL(QualifiedName, formnovalidateAttr)
DEFINE_GLOBAL(QualifiedName, formtargetAttr)
DEFINE_GLOBAL(QualifiedName, frameAttr)
DEFINE_GLOBAL(QualifiedName, frameborderAttr)
DEFINE_GLOBAL(QualifiedName, headersAttr)
DEFINE_GLOBAL(QualifiedName, heightAttr)
DEFINE_GLOBAL(QualifiedName, hiddenAttr)
DEFINE_GLOBAL(QualifiedName, highAttr)
DEFINE_GLOBAL(QualifiedName, hrefAttr)
DEFINE_GLOBAL(QualifiedName, hreflangAttr)
DEFINE_GLOBAL(QualifiedName, hspaceAttr)
DEFINE_GLOBAL(QualifiedName, http_equivAttr)
DEFINE_GLOBAL(QualifiedName, idAttr)
DEFINE_GLOBAL(QualifiedName, incrementalAttr)
DEFINE_GLOBAL(QualifiedName, indeterminateAttr)
DEFINE_GLOBAL(QualifiedName, inputmodeAttr)
DEFINE_GLOBAL(QualifiedName, isAttr)
DEFINE_GLOBAL(QualifiedName, ismapAttr)
DEFINE_GLOBAL(QualifiedName, itemidAttr)
DEFINE_GLOBAL(QualifiedName, itempropAttr)
DEFINE_GLOBAL(QualifiedName, itemrefAttr)
DEFINE_GLOBAL(QualifiedName, itemscopeAttr)
DEFINE_GLOBAL(QualifiedName, itemtypeAttr)
DEFINE_GLOBAL(QualifiedName, keytypeAttr)
DEFINE_GLOBAL(QualifiedName, kindAttr)
DEFINE_GLOBAL(QualifiedName, labelAttr)
DEFINE_GLOBAL(QualifiedName, langAttr)
DEFINE_GLOBAL(QualifiedName, languageAttr)
DEFINE_GLOBAL(QualifiedName, leftmarginAttr)
DEFINE_GLOBAL(QualifiedName, linkAttr)
DEFINE_GLOBAL(QualifiedName, listAttr)
DEFINE_GLOBAL(QualifiedName, longdescAttr)
DEFINE_GLOBAL(QualifiedName, loopAttr)
DEFINE_GLOBAL(QualifiedName, loopendAttr)
DEFINE_GLOBAL(QualifiedName, loopstartAttr)
DEFINE_GLOBAL(QualifiedName, lowAttr)
DEFINE_GLOBAL(QualifiedName, lowsrcAttr)
DEFINE_GLOBAL(QualifiedName, manifestAttr)
DEFINE_GLOBAL(QualifiedName, marginheightAttr)
DEFINE_GLOBAL(QualifiedName, marginwidthAttr)
DEFINE_GLOBAL(QualifiedName, maxAttr)
DEFINE_GLOBAL(QualifiedName, maxlengthAttr)
DEFINE_GLOBAL(QualifiedName, mayscriptAttr)
DEFINE_GLOBAL(QualifiedName, mediaAttr)
DEFINE_GLOBAL(QualifiedName, mediagroupAttr)
DEFINE_GLOBAL(QualifiedName, methodAttr)
DEFINE_GLOBAL(QualifiedName, minAttr)
DEFINE_GLOBAL(QualifiedName, multipleAttr)
DEFINE_GLOBAL(QualifiedName, mutedAttr)
DEFINE_GLOBAL(QualifiedName, nameAttr)
DEFINE_GLOBAL(QualifiedName, nohrefAttr)
DEFINE_GLOBAL(QualifiedName, nonceAttr)
DEFINE_GLOBAL(QualifiedName, noresizeAttr)
DEFINE_GLOBAL(QualifiedName, noshadeAttr)
DEFINE_GLOBAL(QualifiedName, novalidateAttr)
DEFINE_GLOBAL(QualifiedName, nowrapAttr)
DEFINE_GLOBAL(QualifiedName, objectAttr)
DEFINE_GLOBAL(QualifiedName, onabortAttr)
DEFINE_GLOBAL(QualifiedName, onanimationendAttr)
DEFINE_GLOBAL(QualifiedName, onanimationiterationAttr)
DEFINE_GLOBAL(QualifiedName, onanimationstartAttr)
DEFINE_GLOBAL(QualifiedName, onautocompleteAttr)
DEFINE_GLOBAL(QualifiedName, onautocompleteerrorAttr)
DEFINE_GLOBAL(QualifiedName, onbeforecopyAttr)
DEFINE_GLOBAL(QualifiedName, onbeforecutAttr)
DEFINE_GLOBAL(QualifiedName, onbeforeloadAttr)
DEFINE_GLOBAL(QualifiedName, onbeforepasteAttr)
DEFINE_GLOBAL(QualifiedName, onbeforeunloadAttr)
DEFINE_GLOBAL(QualifiedName, onblurAttr)
DEFINE_GLOBAL(QualifiedName, oncancelAttr)
DEFINE_GLOBAL(QualifiedName, oncanplayAttr)
DEFINE_GLOBAL(QualifiedName, oncanplaythroughAttr)
DEFINE_GLOBAL(QualifiedName, onchangeAttr)
DEFINE_GLOBAL(QualifiedName, onclickAttr)
DEFINE_GLOBAL(QualifiedName, oncloseAttr)
DEFINE_GLOBAL(QualifiedName, oncontextmenuAttr)
DEFINE_GLOBAL(QualifiedName, oncopyAttr)
DEFINE_GLOBAL(QualifiedName, oncuechangeAttr)
DEFINE_GLOBAL(QualifiedName, oncutAttr)
DEFINE_GLOBAL(QualifiedName, ondblclickAttr)
DEFINE_GLOBAL(QualifiedName, ondragAttr)
DEFINE_GLOBAL(QualifiedName, ondragendAttr)
DEFINE_GLOBAL(QualifiedName, ondragenterAttr)
DEFINE_GLOBAL(QualifiedName, ondragleaveAttr)
DEFINE_GLOBAL(QualifiedName, ondragoverAttr)
DEFINE_GLOBAL(QualifiedName, ondragstartAttr)
DEFINE_GLOBAL(QualifiedName, ondropAttr)
DEFINE_GLOBAL(QualifiedName, ondurationchangeAttr)
DEFINE_GLOBAL(QualifiedName, onemptiedAttr)
DEFINE_GLOBAL(QualifiedName, onendedAttr)
DEFINE_GLOBAL(QualifiedName, onerrorAttr)
DEFINE_GLOBAL(QualifiedName, onfocusAttr)
DEFINE_GLOBAL(QualifiedName, onfocusinAttr)
DEFINE_GLOBAL(QualifiedName, onfocusoutAttr)
DEFINE_GLOBAL(QualifiedName, onhashchangeAttr)
DEFINE_GLOBAL(QualifiedName, oninputAttr)
DEFINE_GLOBAL(QualifiedName, oninvalidAttr)
DEFINE_GLOBAL(QualifiedName, onkeydownAttr)
DEFINE_GLOBAL(QualifiedName, onkeypressAttr)
DEFINE_GLOBAL(QualifiedName, onkeyupAttr)
DEFINE_GLOBAL(QualifiedName, onloadAttr)
DEFINE_GLOBAL(QualifiedName, onloadeddataAttr)
DEFINE_GLOBAL(QualifiedName, onloadedmetadataAttr)
DEFINE_GLOBAL(QualifiedName, onloadstartAttr)
DEFINE_GLOBAL(QualifiedName, onmessageAttr)
DEFINE_GLOBAL(QualifiedName, onmousedownAttr)
DEFINE_GLOBAL(QualifiedName, onmouseenterAttr)
DEFINE_GLOBAL(QualifiedName, onmouseleaveAttr)
DEFINE_GLOBAL(QualifiedName, onmousemoveAttr)
DEFINE_GLOBAL(QualifiedName, onmouseoutAttr)
DEFINE_GLOBAL(QualifiedName, onmouseoverAttr)
DEFINE_GLOBAL(QualifiedName, onmouseupAttr)
DEFINE_GLOBAL(QualifiedName, onmousewheelAttr)
DEFINE_GLOBAL(QualifiedName, onofflineAttr)
DEFINE_GLOBAL(QualifiedName, ononlineAttr)
DEFINE_GLOBAL(QualifiedName, onorientationchangeAttr)
DEFINE_GLOBAL(QualifiedName, onpagehideAttr)
DEFINE_GLOBAL(QualifiedName, onpageshowAttr)
DEFINE_GLOBAL(QualifiedName, onpasteAttr)
DEFINE_GLOBAL(QualifiedName, onpauseAttr)
DEFINE_GLOBAL(QualifiedName, onplayAttr)
DEFINE_GLOBAL(QualifiedName, onplayingAttr)
DEFINE_GLOBAL(QualifiedName, onpopstateAttr)
DEFINE_GLOBAL(QualifiedName, onprogressAttr)
DEFINE_GLOBAL(QualifiedName, onratechangeAttr)
DEFINE_GLOBAL(QualifiedName, onresetAttr)
DEFINE_GLOBAL(QualifiedName, onresizeAttr)
DEFINE_GLOBAL(QualifiedName, onscrollAttr)
DEFINE_GLOBAL(QualifiedName, onsearchAttr)
DEFINE_GLOBAL(QualifiedName, onseekedAttr)
DEFINE_GLOBAL(QualifiedName, onseekingAttr)
DEFINE_GLOBAL(QualifiedName, onselectAttr)
DEFINE_GLOBAL(QualifiedName, onselectionchangeAttr)
DEFINE_GLOBAL(QualifiedName, onselectstartAttr)
DEFINE_GLOBAL(QualifiedName, onshowAttr)
DEFINE_GLOBAL(QualifiedName, onstalledAttr)
DEFINE_GLOBAL(QualifiedName, onstorageAttr)
DEFINE_GLOBAL(QualifiedName, onsubmitAttr)
DEFINE_GLOBAL(QualifiedName, onsuspendAttr)
DEFINE_GLOBAL(QualifiedName, ontimeupdateAttr)
DEFINE_GLOBAL(QualifiedName, ontouchcancelAttr)
DEFINE_GLOBAL(QualifiedName, ontouchendAttr)
DEFINE_GLOBAL(QualifiedName, ontouchmoveAttr)
DEFINE_GLOBAL(QualifiedName, ontouchstartAttr)
DEFINE_GLOBAL(QualifiedName, ontransitionendAttr)
DEFINE_GLOBAL(QualifiedName, onunloadAttr)
DEFINE_GLOBAL(QualifiedName, onvolumechangeAttr)
DEFINE_GLOBAL(QualifiedName, onwaitingAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitanimationendAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitanimationiterationAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitanimationstartAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitfullscreenchangeAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitfullscreenerrorAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitkeyaddedAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitkeyerrorAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitkeymessageAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitneedkeyAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitsourcecloseAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitsourceendedAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitsourceopenAttr)
DEFINE_GLOBAL(QualifiedName, onwebkitspeechchangeAttr)
DEFINE_GLOBAL(QualifiedName, onwebkittransitionendAttr)
DEFINE_GLOBAL(QualifiedName, onwheelAttr)
DEFINE_GLOBAL(QualifiedName, openAttr)
DEFINE_GLOBAL(QualifiedName, optimumAttr)
DEFINE_GLOBAL(QualifiedName, patternAttr)
DEFINE_GLOBAL(QualifiedName, pingAttr)
DEFINE_GLOBAL(QualifiedName, placeholderAttr)
DEFINE_GLOBAL(QualifiedName, playcountAttr)
DEFINE_GLOBAL(QualifiedName, pluginspageAttr)
DEFINE_GLOBAL(QualifiedName, pluginurlAttr)
DEFINE_GLOBAL(QualifiedName, posterAttr)
DEFINE_GLOBAL(QualifiedName, precisionAttr)
DEFINE_GLOBAL(QualifiedName, preloadAttr)
DEFINE_GLOBAL(QualifiedName, primaryAttr)
DEFINE_GLOBAL(QualifiedName, profileAttr)
DEFINE_GLOBAL(QualifiedName, progressAttr)
DEFINE_GLOBAL(QualifiedName, promptAttr)
DEFINE_GLOBAL(QualifiedName, pseudoAttr)
DEFINE_GLOBAL(QualifiedName, readonlyAttr)
DEFINE_GLOBAL(QualifiedName, relAttr)
DEFINE_GLOBAL(QualifiedName, requiredAttr)
DEFINE_GLOBAL(QualifiedName, reset_style_inheritanceAttr)
DEFINE_GLOBAL(QualifiedName, resultsAttr)
DEFINE_GLOBAL(QualifiedName, revAttr)
DEFINE_GLOBAL(QualifiedName, reversedAttr)
DEFINE_GLOBAL(QualifiedName, roleAttr)
DEFINE_GLOBAL(QualifiedName, rowsAttr)
DEFINE_GLOBAL(QualifiedName, rowspanAttr)
DEFINE_GLOBAL(QualifiedName, rulesAttr)
DEFINE_GLOBAL(QualifiedName, sandboxAttr)
DEFINE_GLOBAL(QualifiedName, schemeAttr)
DEFINE_GLOBAL(QualifiedName, scopeAttr)
DEFINE_GLOBAL(QualifiedName, scopedAttr)
DEFINE_GLOBAL(QualifiedName, scrollamountAttr)
DEFINE_GLOBAL(QualifiedName, scrolldelayAttr)
DEFINE_GLOBAL(QualifiedName, scrollingAttr)
DEFINE_GLOBAL(QualifiedName, selectAttr)
DEFINE_GLOBAL(QualifiedName, selectedAttr)
DEFINE_GLOBAL(QualifiedName, shapeAttr)
DEFINE_GLOBAL(QualifiedName, sizeAttr)
DEFINE_GLOBAL(QualifiedName, sizesAttr)
DEFINE_GLOBAL(QualifiedName, sortableAttr)
DEFINE_GLOBAL(QualifiedName, sortdirectionAttr)
DEFINE_GLOBAL(QualifiedName, spanAttr)
DEFINE_GLOBAL(QualifiedName, spellcheckAttr)
DEFINE_GLOBAL(QualifiedName, srcAttr)
DEFINE_GLOBAL(QualifiedName, srcdocAttr)
DEFINE_GLOBAL(QualifiedName, srclangAttr)
DEFINE_GLOBAL(QualifiedName, srcsetAttr)
DEFINE_GLOBAL(QualifiedName, standbyAttr)
DEFINE_GLOBAL(QualifiedName, startAttr)
DEFINE_GLOBAL(QualifiedName, stepAttr)
DEFINE_GLOBAL(QualifiedName, styleAttr)
DEFINE_GLOBAL(QualifiedName, summaryAttr)
DEFINE_GLOBAL(QualifiedName, tabindexAttr)
DEFINE_GLOBAL(QualifiedName, tableborderAttr)
DEFINE_GLOBAL(QualifiedName, targetAttr)
DEFINE_GLOBAL(QualifiedName, textAttr)
DEFINE_GLOBAL(QualifiedName, titleAttr)
DEFINE_GLOBAL(QualifiedName, topAttr)
DEFINE_GLOBAL(QualifiedName, topmarginAttr)
DEFINE_GLOBAL(QualifiedName, translateAttr)
DEFINE_GLOBAL(QualifiedName, truespeedAttr)
DEFINE_GLOBAL(QualifiedName, typeAttr)
DEFINE_GLOBAL(QualifiedName, usemapAttr)
DEFINE_GLOBAL(QualifiedName, valignAttr)
DEFINE_GLOBAL(QualifiedName, valueAttr)
DEFINE_GLOBAL(QualifiedName, valuetypeAttr)
DEFINE_GLOBAL(QualifiedName, versionAttr)
DEFINE_GLOBAL(QualifiedName, vlinkAttr)
DEFINE_GLOBAL(QualifiedName, vspaceAttr)
DEFINE_GLOBAL(QualifiedName, webkitallowfullscreenAttr)
DEFINE_GLOBAL(QualifiedName, webkitdirectoryAttr)
DEFINE_GLOBAL(QualifiedName, webkitdropzoneAttr)
DEFINE_GLOBAL(QualifiedName, widthAttr)
DEFINE_GLOBAL(QualifiedName, wrapAttr)
DEFINE_GLOBAL(QualifiedName, webkitgrammarAttr)
DEFINE_GLOBAL(QualifiedName, webkitspeechAttr)

PassOwnPtr<const QualifiedName*[]> getHTMLAttrs()
{
    OwnPtr<const QualifiedName*[]> attrs = adoptArrayPtr(new const QualifiedName*[HTMLAttrsCount]);
    attrs[0] = reinterpret_cast<const WebCore::QualifiedName*>(&abbrAttr);
    attrs[1] = reinterpret_cast<const WebCore::QualifiedName*>(&acceptAttr);
    attrs[2] = reinterpret_cast<const WebCore::QualifiedName*>(&accept_charsetAttr);
    attrs[3] = reinterpret_cast<const WebCore::QualifiedName*>(&accesskeyAttr);
    attrs[4] = reinterpret_cast<const WebCore::QualifiedName*>(&actionAttr);
    attrs[5] = reinterpret_cast<const WebCore::QualifiedName*>(&alignAttr);
    attrs[6] = reinterpret_cast<const WebCore::QualifiedName*>(&alinkAttr);
    attrs[7] = reinterpret_cast<const WebCore::QualifiedName*>(&allowfullscreenAttr);
    attrs[8] = reinterpret_cast<const WebCore::QualifiedName*>(&altAttr);
    attrs[9] = reinterpret_cast<const WebCore::QualifiedName*>(&archiveAttr);
    attrs[10] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_activedescendantAttr);
    attrs[11] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_atomicAttr);
    attrs[12] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_busyAttr);
    attrs[13] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_checkedAttr);
    attrs[14] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_controlsAttr);
    attrs[15] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_describedbyAttr);
    attrs[16] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_disabledAttr);
    attrs[17] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_dropeffectAttr);
    attrs[18] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_expandedAttr);
    attrs[19] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_flowtoAttr);
    attrs[20] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_grabbedAttr);
    attrs[21] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_haspopupAttr);
    attrs[22] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_helpAttr);
    attrs[23] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_hiddenAttr);
    attrs[24] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_invalidAttr);
    attrs[25] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_labelAttr);
    attrs[26] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_labeledbyAttr);
    attrs[27] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_labelledbyAttr);
    attrs[28] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_levelAttr);
    attrs[29] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_liveAttr);
    attrs[30] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_multilineAttr);
    attrs[31] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_multiselectableAttr);
    attrs[32] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_orientationAttr);
    attrs[33] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_ownsAttr);
    attrs[34] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_posinsetAttr);
    attrs[35] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_pressedAttr);
    attrs[36] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_readonlyAttr);
    attrs[37] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_relevantAttr);
    attrs[38] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_requiredAttr);
    attrs[39] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_selectedAttr);
    attrs[40] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_setsizeAttr);
    attrs[41] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_sortAttr);
    attrs[42] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_valuemaxAttr);
    attrs[43] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_valueminAttr);
    attrs[44] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_valuenowAttr);
    attrs[45] = reinterpret_cast<const WebCore::QualifiedName*>(&aria_valuetextAttr);
    attrs[46] = reinterpret_cast<const WebCore::QualifiedName*>(&asyncAttr);
    attrs[47] = reinterpret_cast<const WebCore::QualifiedName*>(&autocompleteAttr);
    attrs[48] = reinterpret_cast<const WebCore::QualifiedName*>(&autofocusAttr);
    attrs[49] = reinterpret_cast<const WebCore::QualifiedName*>(&autoplayAttr);
    attrs[50] = reinterpret_cast<const WebCore::QualifiedName*>(&axisAttr);
    attrs[51] = reinterpret_cast<const WebCore::QualifiedName*>(&backgroundAttr);
    attrs[52] = reinterpret_cast<const WebCore::QualifiedName*>(&behaviorAttr);
    attrs[53] = reinterpret_cast<const WebCore::QualifiedName*>(&bgcolorAttr);
    attrs[54] = reinterpret_cast<const WebCore::QualifiedName*>(&bgpropertiesAttr);
    attrs[55] = reinterpret_cast<const WebCore::QualifiedName*>(&borderAttr);
    attrs[56] = reinterpret_cast<const WebCore::QualifiedName*>(&bordercolorAttr);
    attrs[57] = reinterpret_cast<const WebCore::QualifiedName*>(&captureAttr);
    attrs[58] = reinterpret_cast<const WebCore::QualifiedName*>(&cellborderAttr);
    attrs[59] = reinterpret_cast<const WebCore::QualifiedName*>(&cellpaddingAttr);
    attrs[60] = reinterpret_cast<const WebCore::QualifiedName*>(&cellspacingAttr);
    attrs[61] = reinterpret_cast<const WebCore::QualifiedName*>(&challengeAttr);
    attrs[62] = reinterpret_cast<const WebCore::QualifiedName*>(&charAttr);
    attrs[63] = reinterpret_cast<const WebCore::QualifiedName*>(&charoffAttr);
    attrs[64] = reinterpret_cast<const WebCore::QualifiedName*>(&charsetAttr);
    attrs[65] = reinterpret_cast<const WebCore::QualifiedName*>(&checkedAttr);
    attrs[66] = reinterpret_cast<const WebCore::QualifiedName*>(&citeAttr);
    attrs[67] = reinterpret_cast<const WebCore::QualifiedName*>(&classAttr);
    attrs[68] = reinterpret_cast<const WebCore::QualifiedName*>(&classidAttr);
    attrs[69] = reinterpret_cast<const WebCore::QualifiedName*>(&clearAttr);
    attrs[70] = reinterpret_cast<const WebCore::QualifiedName*>(&codeAttr);
    attrs[71] = reinterpret_cast<const WebCore::QualifiedName*>(&codebaseAttr);
    attrs[72] = reinterpret_cast<const WebCore::QualifiedName*>(&codetypeAttr);
    attrs[73] = reinterpret_cast<const WebCore::QualifiedName*>(&colorAttr);
    attrs[74] = reinterpret_cast<const WebCore::QualifiedName*>(&colsAttr);
    attrs[75] = reinterpret_cast<const WebCore::QualifiedName*>(&colspanAttr);
    attrs[76] = reinterpret_cast<const WebCore::QualifiedName*>(&compactAttr);
    attrs[77] = reinterpret_cast<const WebCore::QualifiedName*>(&compositeAttr);
    attrs[78] = reinterpret_cast<const WebCore::QualifiedName*>(&contentAttr);
    attrs[79] = reinterpret_cast<const WebCore::QualifiedName*>(&contenteditableAttr);
    attrs[80] = reinterpret_cast<const WebCore::QualifiedName*>(&controlsAttr);
    attrs[81] = reinterpret_cast<const WebCore::QualifiedName*>(&coordsAttr);
    attrs[82] = reinterpret_cast<const WebCore::QualifiedName*>(&crossoriginAttr);
    attrs[83] = reinterpret_cast<const WebCore::QualifiedName*>(&dataAttr);
    attrs[84] = reinterpret_cast<const WebCore::QualifiedName*>(&datetimeAttr);
    attrs[85] = reinterpret_cast<const WebCore::QualifiedName*>(&declareAttr);
    attrs[86] = reinterpret_cast<const WebCore::QualifiedName*>(&defaultAttr);
    attrs[87] = reinterpret_cast<const WebCore::QualifiedName*>(&deferAttr);
    attrs[88] = reinterpret_cast<const WebCore::QualifiedName*>(&dirAttr);
    attrs[89] = reinterpret_cast<const WebCore::QualifiedName*>(&directionAttr);
    attrs[90] = reinterpret_cast<const WebCore::QualifiedName*>(&dirnameAttr);
    attrs[91] = reinterpret_cast<const WebCore::QualifiedName*>(&disabledAttr);
    attrs[92] = reinterpret_cast<const WebCore::QualifiedName*>(&dispositionAttr);
    attrs[93] = reinterpret_cast<const WebCore::QualifiedName*>(&downloadAttr);
    attrs[94] = reinterpret_cast<const WebCore::QualifiedName*>(&draggableAttr);
    attrs[95] = reinterpret_cast<const WebCore::QualifiedName*>(&enctypeAttr);
    attrs[96] = reinterpret_cast<const WebCore::QualifiedName*>(&endAttr);
    attrs[97] = reinterpret_cast<const WebCore::QualifiedName*>(&eventAttr);
    attrs[98] = reinterpret_cast<const WebCore::QualifiedName*>(&expandedAttr);
    attrs[99] = reinterpret_cast<const WebCore::QualifiedName*>(&faceAttr);
    attrs[100] = reinterpret_cast<const WebCore::QualifiedName*>(&focusedAttr);
    attrs[101] = reinterpret_cast<const WebCore::QualifiedName*>(&forAttr);
    attrs[102] = reinterpret_cast<const WebCore::QualifiedName*>(&formAttr);
    attrs[103] = reinterpret_cast<const WebCore::QualifiedName*>(&formactionAttr);
    attrs[104] = reinterpret_cast<const WebCore::QualifiedName*>(&formenctypeAttr);
    attrs[105] = reinterpret_cast<const WebCore::QualifiedName*>(&formmethodAttr);
    attrs[106] = reinterpret_cast<const WebCore::QualifiedName*>(&formnovalidateAttr);
    attrs[107] = reinterpret_cast<const WebCore::QualifiedName*>(&formtargetAttr);
    attrs[108] = reinterpret_cast<const WebCore::QualifiedName*>(&frameAttr);
    attrs[109] = reinterpret_cast<const WebCore::QualifiedName*>(&frameborderAttr);
    attrs[110] = reinterpret_cast<const WebCore::QualifiedName*>(&headersAttr);
    attrs[111] = reinterpret_cast<const WebCore::QualifiedName*>(&heightAttr);
    attrs[112] = reinterpret_cast<const WebCore::QualifiedName*>(&hiddenAttr);
    attrs[113] = reinterpret_cast<const WebCore::QualifiedName*>(&highAttr);
    attrs[114] = reinterpret_cast<const WebCore::QualifiedName*>(&hrefAttr);
    attrs[115] = reinterpret_cast<const WebCore::QualifiedName*>(&hreflangAttr);
    attrs[116] = reinterpret_cast<const WebCore::QualifiedName*>(&hspaceAttr);
    attrs[117] = reinterpret_cast<const WebCore::QualifiedName*>(&http_equivAttr);
    attrs[118] = reinterpret_cast<const WebCore::QualifiedName*>(&idAttr);
    attrs[119] = reinterpret_cast<const WebCore::QualifiedName*>(&incrementalAttr);
    attrs[120] = reinterpret_cast<const WebCore::QualifiedName*>(&indeterminateAttr);
    attrs[121] = reinterpret_cast<const WebCore::QualifiedName*>(&inputmodeAttr);
    attrs[122] = reinterpret_cast<const WebCore::QualifiedName*>(&isAttr);
    attrs[123] = reinterpret_cast<const WebCore::QualifiedName*>(&ismapAttr);
    attrs[124] = reinterpret_cast<const WebCore::QualifiedName*>(&itemidAttr);
    attrs[125] = reinterpret_cast<const WebCore::QualifiedName*>(&itempropAttr);
    attrs[126] = reinterpret_cast<const WebCore::QualifiedName*>(&itemrefAttr);
    attrs[127] = reinterpret_cast<const WebCore::QualifiedName*>(&itemscopeAttr);
    attrs[128] = reinterpret_cast<const WebCore::QualifiedName*>(&itemtypeAttr);
    attrs[129] = reinterpret_cast<const WebCore::QualifiedName*>(&keytypeAttr);
    attrs[130] = reinterpret_cast<const WebCore::QualifiedName*>(&kindAttr);
    attrs[131] = reinterpret_cast<const WebCore::QualifiedName*>(&labelAttr);
    attrs[132] = reinterpret_cast<const WebCore::QualifiedName*>(&langAttr);
    attrs[133] = reinterpret_cast<const WebCore::QualifiedName*>(&languageAttr);
    attrs[134] = reinterpret_cast<const WebCore::QualifiedName*>(&leftmarginAttr);
    attrs[135] = reinterpret_cast<const WebCore::QualifiedName*>(&linkAttr);
    attrs[136] = reinterpret_cast<const WebCore::QualifiedName*>(&listAttr);
    attrs[137] = reinterpret_cast<const WebCore::QualifiedName*>(&longdescAttr);
    attrs[138] = reinterpret_cast<const WebCore::QualifiedName*>(&loopAttr);
    attrs[139] = reinterpret_cast<const WebCore::QualifiedName*>(&loopendAttr);
    attrs[140] = reinterpret_cast<const WebCore::QualifiedName*>(&loopstartAttr);
    attrs[141] = reinterpret_cast<const WebCore::QualifiedName*>(&lowAttr);
    attrs[142] = reinterpret_cast<const WebCore::QualifiedName*>(&lowsrcAttr);
    attrs[143] = reinterpret_cast<const WebCore::QualifiedName*>(&manifestAttr);
    attrs[144] = reinterpret_cast<const WebCore::QualifiedName*>(&marginheightAttr);
    attrs[145] = reinterpret_cast<const WebCore::QualifiedName*>(&marginwidthAttr);
    attrs[146] = reinterpret_cast<const WebCore::QualifiedName*>(&maxAttr);
    attrs[147] = reinterpret_cast<const WebCore::QualifiedName*>(&maxlengthAttr);
    attrs[148] = reinterpret_cast<const WebCore::QualifiedName*>(&mayscriptAttr);
    attrs[149] = reinterpret_cast<const WebCore::QualifiedName*>(&mediaAttr);
    attrs[150] = reinterpret_cast<const WebCore::QualifiedName*>(&mediagroupAttr);
    attrs[151] = reinterpret_cast<const WebCore::QualifiedName*>(&methodAttr);
    attrs[152] = reinterpret_cast<const WebCore::QualifiedName*>(&minAttr);
    attrs[153] = reinterpret_cast<const WebCore::QualifiedName*>(&multipleAttr);
    attrs[154] = reinterpret_cast<const WebCore::QualifiedName*>(&mutedAttr);
    attrs[155] = reinterpret_cast<const WebCore::QualifiedName*>(&nameAttr);
    attrs[156] = reinterpret_cast<const WebCore::QualifiedName*>(&nohrefAttr);
    attrs[157] = reinterpret_cast<const WebCore::QualifiedName*>(&nonceAttr);
    attrs[158] = reinterpret_cast<const WebCore::QualifiedName*>(&noresizeAttr);
    attrs[159] = reinterpret_cast<const WebCore::QualifiedName*>(&noshadeAttr);
    attrs[160] = reinterpret_cast<const WebCore::QualifiedName*>(&novalidateAttr);
    attrs[161] = reinterpret_cast<const WebCore::QualifiedName*>(&nowrapAttr);
    attrs[162] = reinterpret_cast<const WebCore::QualifiedName*>(&objectAttr);
    attrs[163] = reinterpret_cast<const WebCore::QualifiedName*>(&onabortAttr);
    attrs[164] = reinterpret_cast<const WebCore::QualifiedName*>(&onanimationendAttr);
    attrs[165] = reinterpret_cast<const WebCore::QualifiedName*>(&onanimationiterationAttr);
    attrs[166] = reinterpret_cast<const WebCore::QualifiedName*>(&onanimationstartAttr);
    attrs[167] = reinterpret_cast<const WebCore::QualifiedName*>(&onautocompleteAttr);
    attrs[168] = reinterpret_cast<const WebCore::QualifiedName*>(&onautocompleteerrorAttr);
    attrs[169] = reinterpret_cast<const WebCore::QualifiedName*>(&onbeforecopyAttr);
    attrs[170] = reinterpret_cast<const WebCore::QualifiedName*>(&onbeforecutAttr);
    attrs[171] = reinterpret_cast<const WebCore::QualifiedName*>(&onbeforeloadAttr);
    attrs[172] = reinterpret_cast<const WebCore::QualifiedName*>(&onbeforepasteAttr);
    attrs[173] = reinterpret_cast<const WebCore::QualifiedName*>(&onbeforeunloadAttr);
    attrs[174] = reinterpret_cast<const WebCore::QualifiedName*>(&onblurAttr);
    attrs[175] = reinterpret_cast<const WebCore::QualifiedName*>(&oncancelAttr);
    attrs[176] = reinterpret_cast<const WebCore::QualifiedName*>(&oncanplayAttr);
    attrs[177] = reinterpret_cast<const WebCore::QualifiedName*>(&oncanplaythroughAttr);
    attrs[178] = reinterpret_cast<const WebCore::QualifiedName*>(&onchangeAttr);
    attrs[179] = reinterpret_cast<const WebCore::QualifiedName*>(&onclickAttr);
    attrs[180] = reinterpret_cast<const WebCore::QualifiedName*>(&oncloseAttr);
    attrs[181] = reinterpret_cast<const WebCore::QualifiedName*>(&oncontextmenuAttr);
    attrs[182] = reinterpret_cast<const WebCore::QualifiedName*>(&oncopyAttr);
    attrs[183] = reinterpret_cast<const WebCore::QualifiedName*>(&oncuechangeAttr);
    attrs[184] = reinterpret_cast<const WebCore::QualifiedName*>(&oncutAttr);
    attrs[185] = reinterpret_cast<const WebCore::QualifiedName*>(&ondblclickAttr);
    attrs[186] = reinterpret_cast<const WebCore::QualifiedName*>(&ondragAttr);
    attrs[187] = reinterpret_cast<const WebCore::QualifiedName*>(&ondragendAttr);
    attrs[188] = reinterpret_cast<const WebCore::QualifiedName*>(&ondragenterAttr);
    attrs[189] = reinterpret_cast<const WebCore::QualifiedName*>(&ondragleaveAttr);
    attrs[190] = reinterpret_cast<const WebCore::QualifiedName*>(&ondragoverAttr);
    attrs[191] = reinterpret_cast<const WebCore::QualifiedName*>(&ondragstartAttr);
    attrs[192] = reinterpret_cast<const WebCore::QualifiedName*>(&ondropAttr);
    attrs[193] = reinterpret_cast<const WebCore::QualifiedName*>(&ondurationchangeAttr);
    attrs[194] = reinterpret_cast<const WebCore::QualifiedName*>(&onemptiedAttr);
    attrs[195] = reinterpret_cast<const WebCore::QualifiedName*>(&onendedAttr);
    attrs[196] = reinterpret_cast<const WebCore::QualifiedName*>(&onerrorAttr);
    attrs[197] = reinterpret_cast<const WebCore::QualifiedName*>(&onfocusAttr);
    attrs[198] = reinterpret_cast<const WebCore::QualifiedName*>(&onfocusinAttr);
    attrs[199] = reinterpret_cast<const WebCore::QualifiedName*>(&onfocusoutAttr);
    attrs[200] = reinterpret_cast<const WebCore::QualifiedName*>(&onhashchangeAttr);
    attrs[201] = reinterpret_cast<const WebCore::QualifiedName*>(&oninputAttr);
    attrs[202] = reinterpret_cast<const WebCore::QualifiedName*>(&oninvalidAttr);
    attrs[203] = reinterpret_cast<const WebCore::QualifiedName*>(&onkeydownAttr);
    attrs[204] = reinterpret_cast<const WebCore::QualifiedName*>(&onkeypressAttr);
    attrs[205] = reinterpret_cast<const WebCore::QualifiedName*>(&onkeyupAttr);
    attrs[206] = reinterpret_cast<const WebCore::QualifiedName*>(&onloadAttr);
    attrs[207] = reinterpret_cast<const WebCore::QualifiedName*>(&onloadeddataAttr);
    attrs[208] = reinterpret_cast<const WebCore::QualifiedName*>(&onloadedmetadataAttr);
    attrs[209] = reinterpret_cast<const WebCore::QualifiedName*>(&onloadstartAttr);
    attrs[210] = reinterpret_cast<const WebCore::QualifiedName*>(&onmessageAttr);
    attrs[211] = reinterpret_cast<const WebCore::QualifiedName*>(&onmousedownAttr);
    attrs[212] = reinterpret_cast<const WebCore::QualifiedName*>(&onmouseenterAttr);
    attrs[213] = reinterpret_cast<const WebCore::QualifiedName*>(&onmouseleaveAttr);
    attrs[214] = reinterpret_cast<const WebCore::QualifiedName*>(&onmousemoveAttr);
    attrs[215] = reinterpret_cast<const WebCore::QualifiedName*>(&onmouseoutAttr);
    attrs[216] = reinterpret_cast<const WebCore::QualifiedName*>(&onmouseoverAttr);
    attrs[217] = reinterpret_cast<const WebCore::QualifiedName*>(&onmouseupAttr);
    attrs[218] = reinterpret_cast<const WebCore::QualifiedName*>(&onmousewheelAttr);
    attrs[219] = reinterpret_cast<const WebCore::QualifiedName*>(&onofflineAttr);
    attrs[220] = reinterpret_cast<const WebCore::QualifiedName*>(&ononlineAttr);
    attrs[221] = reinterpret_cast<const WebCore::QualifiedName*>(&onorientationchangeAttr);
    attrs[222] = reinterpret_cast<const WebCore::QualifiedName*>(&onpagehideAttr);
    attrs[223] = reinterpret_cast<const WebCore::QualifiedName*>(&onpageshowAttr);
    attrs[224] = reinterpret_cast<const WebCore::QualifiedName*>(&onpasteAttr);
    attrs[225] = reinterpret_cast<const WebCore::QualifiedName*>(&onpauseAttr);
    attrs[226] = reinterpret_cast<const WebCore::QualifiedName*>(&onplayAttr);
    attrs[227] = reinterpret_cast<const WebCore::QualifiedName*>(&onplayingAttr);
    attrs[228] = reinterpret_cast<const WebCore::QualifiedName*>(&onpopstateAttr);
    attrs[229] = reinterpret_cast<const WebCore::QualifiedName*>(&onprogressAttr);
    attrs[230] = reinterpret_cast<const WebCore::QualifiedName*>(&onratechangeAttr);
    attrs[231] = reinterpret_cast<const WebCore::QualifiedName*>(&onresetAttr);
    attrs[232] = reinterpret_cast<const WebCore::QualifiedName*>(&onresizeAttr);
    attrs[233] = reinterpret_cast<const WebCore::QualifiedName*>(&onscrollAttr);
    attrs[234] = reinterpret_cast<const WebCore::QualifiedName*>(&onsearchAttr);
    attrs[235] = reinterpret_cast<const WebCore::QualifiedName*>(&onseekedAttr);
    attrs[236] = reinterpret_cast<const WebCore::QualifiedName*>(&onseekingAttr);
    attrs[237] = reinterpret_cast<const WebCore::QualifiedName*>(&onselectAttr);
    attrs[238] = reinterpret_cast<const WebCore::QualifiedName*>(&onselectionchangeAttr);
    attrs[239] = reinterpret_cast<const WebCore::QualifiedName*>(&onselectstartAttr);
    attrs[240] = reinterpret_cast<const WebCore::QualifiedName*>(&onshowAttr);
    attrs[241] = reinterpret_cast<const WebCore::QualifiedName*>(&onstalledAttr);
    attrs[242] = reinterpret_cast<const WebCore::QualifiedName*>(&onstorageAttr);
    attrs[243] = reinterpret_cast<const WebCore::QualifiedName*>(&onsubmitAttr);
    attrs[244] = reinterpret_cast<const WebCore::QualifiedName*>(&onsuspendAttr);
    attrs[245] = reinterpret_cast<const WebCore::QualifiedName*>(&ontimeupdateAttr);
    attrs[246] = reinterpret_cast<const WebCore::QualifiedName*>(&ontouchcancelAttr);
    attrs[247] = reinterpret_cast<const WebCore::QualifiedName*>(&ontouchendAttr);
    attrs[248] = reinterpret_cast<const WebCore::QualifiedName*>(&ontouchmoveAttr);
    attrs[249] = reinterpret_cast<const WebCore::QualifiedName*>(&ontouchstartAttr);
    attrs[250] = reinterpret_cast<const WebCore::QualifiedName*>(&ontransitionendAttr);
    attrs[251] = reinterpret_cast<const WebCore::QualifiedName*>(&onunloadAttr);
    attrs[252] = reinterpret_cast<const WebCore::QualifiedName*>(&onvolumechangeAttr);
    attrs[253] = reinterpret_cast<const WebCore::QualifiedName*>(&onwaitingAttr);
    attrs[254] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitanimationendAttr);
    attrs[255] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitanimationiterationAttr);
    attrs[256] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitanimationstartAttr);
    attrs[257] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitfullscreenchangeAttr);
    attrs[258] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitfullscreenerrorAttr);
    attrs[259] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitkeyaddedAttr);
    attrs[260] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitkeyerrorAttr);
    attrs[261] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitkeymessageAttr);
    attrs[262] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitneedkeyAttr);
    attrs[263] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitsourcecloseAttr);
    attrs[264] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitsourceendedAttr);
    attrs[265] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitsourceopenAttr);
    attrs[266] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkitspeechchangeAttr);
    attrs[267] = reinterpret_cast<const WebCore::QualifiedName*>(&onwebkittransitionendAttr);
    attrs[268] = reinterpret_cast<const WebCore::QualifiedName*>(&onwheelAttr);
    attrs[269] = reinterpret_cast<const WebCore::QualifiedName*>(&openAttr);
    attrs[270] = reinterpret_cast<const WebCore::QualifiedName*>(&optimumAttr);
    attrs[271] = reinterpret_cast<const WebCore::QualifiedName*>(&patternAttr);
    attrs[272] = reinterpret_cast<const WebCore::QualifiedName*>(&pingAttr);
    attrs[273] = reinterpret_cast<const WebCore::QualifiedName*>(&placeholderAttr);
    attrs[274] = reinterpret_cast<const WebCore::QualifiedName*>(&playcountAttr);
    attrs[275] = reinterpret_cast<const WebCore::QualifiedName*>(&pluginspageAttr);
    attrs[276] = reinterpret_cast<const WebCore::QualifiedName*>(&pluginurlAttr);
    attrs[277] = reinterpret_cast<const WebCore::QualifiedName*>(&posterAttr);
    attrs[278] = reinterpret_cast<const WebCore::QualifiedName*>(&precisionAttr);
    attrs[279] = reinterpret_cast<const WebCore::QualifiedName*>(&preloadAttr);
    attrs[280] = reinterpret_cast<const WebCore::QualifiedName*>(&primaryAttr);
    attrs[281] = reinterpret_cast<const WebCore::QualifiedName*>(&profileAttr);
    attrs[282] = reinterpret_cast<const WebCore::QualifiedName*>(&progressAttr);
    attrs[283] = reinterpret_cast<const WebCore::QualifiedName*>(&promptAttr);
    attrs[284] = reinterpret_cast<const WebCore::QualifiedName*>(&pseudoAttr);
    attrs[285] = reinterpret_cast<const WebCore::QualifiedName*>(&readonlyAttr);
    attrs[286] = reinterpret_cast<const WebCore::QualifiedName*>(&relAttr);
    attrs[287] = reinterpret_cast<const WebCore::QualifiedName*>(&requiredAttr);
    attrs[288] = reinterpret_cast<const WebCore::QualifiedName*>(&reset_style_inheritanceAttr);
    attrs[289] = reinterpret_cast<const WebCore::QualifiedName*>(&resultsAttr);
    attrs[290] = reinterpret_cast<const WebCore::QualifiedName*>(&revAttr);
    attrs[291] = reinterpret_cast<const WebCore::QualifiedName*>(&reversedAttr);
    attrs[292] = reinterpret_cast<const WebCore::QualifiedName*>(&roleAttr);
    attrs[293] = reinterpret_cast<const WebCore::QualifiedName*>(&rowsAttr);
    attrs[294] = reinterpret_cast<const WebCore::QualifiedName*>(&rowspanAttr);
    attrs[295] = reinterpret_cast<const WebCore::QualifiedName*>(&rulesAttr);
    attrs[296] = reinterpret_cast<const WebCore::QualifiedName*>(&sandboxAttr);
    attrs[297] = reinterpret_cast<const WebCore::QualifiedName*>(&schemeAttr);
    attrs[298] = reinterpret_cast<const WebCore::QualifiedName*>(&scopeAttr);
    attrs[299] = reinterpret_cast<const WebCore::QualifiedName*>(&scopedAttr);
    attrs[300] = reinterpret_cast<const WebCore::QualifiedName*>(&scrollamountAttr);
    attrs[301] = reinterpret_cast<const WebCore::QualifiedName*>(&scrolldelayAttr);
    attrs[302] = reinterpret_cast<const WebCore::QualifiedName*>(&scrollingAttr);
    attrs[303] = reinterpret_cast<const WebCore::QualifiedName*>(&selectAttr);
    attrs[304] = reinterpret_cast<const WebCore::QualifiedName*>(&selectedAttr);
    attrs[305] = reinterpret_cast<const WebCore::QualifiedName*>(&shapeAttr);
    attrs[306] = reinterpret_cast<const WebCore::QualifiedName*>(&sizeAttr);
    attrs[307] = reinterpret_cast<const WebCore::QualifiedName*>(&sizesAttr);
    attrs[308] = reinterpret_cast<const WebCore::QualifiedName*>(&sortableAttr);
    attrs[309] = reinterpret_cast<const WebCore::QualifiedName*>(&sortdirectionAttr);
    attrs[310] = reinterpret_cast<const WebCore::QualifiedName*>(&spanAttr);
    attrs[311] = reinterpret_cast<const WebCore::QualifiedName*>(&spellcheckAttr);
    attrs[312] = reinterpret_cast<const WebCore::QualifiedName*>(&srcAttr);
    attrs[313] = reinterpret_cast<const WebCore::QualifiedName*>(&srcdocAttr);
    attrs[314] = reinterpret_cast<const WebCore::QualifiedName*>(&srclangAttr);
    attrs[315] = reinterpret_cast<const WebCore::QualifiedName*>(&srcsetAttr);
    attrs[316] = reinterpret_cast<const WebCore::QualifiedName*>(&standbyAttr);
    attrs[317] = reinterpret_cast<const WebCore::QualifiedName*>(&startAttr);
    attrs[318] = reinterpret_cast<const WebCore::QualifiedName*>(&stepAttr);
    attrs[319] = reinterpret_cast<const WebCore::QualifiedName*>(&styleAttr);
    attrs[320] = reinterpret_cast<const WebCore::QualifiedName*>(&summaryAttr);
    attrs[321] = reinterpret_cast<const WebCore::QualifiedName*>(&tabindexAttr);
    attrs[322] = reinterpret_cast<const WebCore::QualifiedName*>(&tableborderAttr);
    attrs[323] = reinterpret_cast<const WebCore::QualifiedName*>(&targetAttr);
    attrs[324] = reinterpret_cast<const WebCore::QualifiedName*>(&textAttr);
    attrs[325] = reinterpret_cast<const WebCore::QualifiedName*>(&titleAttr);
    attrs[326] = reinterpret_cast<const WebCore::QualifiedName*>(&topAttr);
    attrs[327] = reinterpret_cast<const WebCore::QualifiedName*>(&topmarginAttr);
    attrs[328] = reinterpret_cast<const WebCore::QualifiedName*>(&translateAttr);
    attrs[329] = reinterpret_cast<const WebCore::QualifiedName*>(&truespeedAttr);
    attrs[330] = reinterpret_cast<const WebCore::QualifiedName*>(&typeAttr);
    attrs[331] = reinterpret_cast<const WebCore::QualifiedName*>(&usemapAttr);
    attrs[332] = reinterpret_cast<const WebCore::QualifiedName*>(&valignAttr);
    attrs[333] = reinterpret_cast<const WebCore::QualifiedName*>(&valueAttr);
    attrs[334] = reinterpret_cast<const WebCore::QualifiedName*>(&valuetypeAttr);
    attrs[335] = reinterpret_cast<const WebCore::QualifiedName*>(&versionAttr);
    attrs[336] = reinterpret_cast<const WebCore::QualifiedName*>(&vlinkAttr);
    attrs[337] = reinterpret_cast<const WebCore::QualifiedName*>(&vspaceAttr);
    attrs[338] = reinterpret_cast<const WebCore::QualifiedName*>(&webkitallowfullscreenAttr);
    attrs[339] = reinterpret_cast<const WebCore::QualifiedName*>(&webkitdirectoryAttr);
    attrs[340] = reinterpret_cast<const WebCore::QualifiedName*>(&webkitdropzoneAttr);
    attrs[341] = reinterpret_cast<const WebCore::QualifiedName*>(&widthAttr);
    attrs[342] = reinterpret_cast<const WebCore::QualifiedName*>(&wrapAttr);
    attrs[343] = reinterpret_cast<const WebCore::QualifiedName*>(&webkitgrammarAttr);
    attrs[344] = reinterpret_cast<const WebCore::QualifiedName*>(&webkitspeechAttr);
    return attrs.release();
}

void init()
{
    // Use placement new to initialize the globals.
    AtomicString xhtmlNS("http://www.w3.org/1999/xhtml", AtomicString::ConstructFromLiteral);

    // Namespace
    new ((void*)&xhtmlNamespaceURI) AtomicString(xhtmlNS);
    StringImpl* aImpl = StringImpl::createStatic("a", 1, 9778235);
    StringImpl* abbrImpl = StringImpl::createStatic("abbr", 4, 650525);
    StringImpl* acceptImpl = StringImpl::createStatic("accept", 6, 4839857);
    StringImpl* accept_charsetImpl = StringImpl::createStatic("accept-charset", 14, 5192676);
    StringImpl* accesskeyImpl = StringImpl::createStatic("accesskey", 9, 15931860);
    StringImpl* acronymImpl = StringImpl::createStatic("acronym", 7, 5486176);
    StringImpl* actionImpl = StringImpl::createStatic("action", 6, 14878034);
    StringImpl* addressImpl = StringImpl::createStatic("address", 7, 10008206);
    StringImpl* alignImpl = StringImpl::createStatic("align", 5, 10094397);
    StringImpl* alinkImpl = StringImpl::createStatic("alink", 5, 2408650);
    StringImpl* allowfullscreenImpl = StringImpl::createStatic("allowfullscreen", 15, 16375700);
    StringImpl* altImpl = StringImpl::createStatic("alt", 3, 15335609);
    StringImpl* appletImpl = StringImpl::createStatic("applet", 6, 7823075);
    StringImpl* archiveImpl = StringImpl::createStatic("archive", 7, 13839011);
    StringImpl* areaImpl = StringImpl::createStatic("area", 4, 7355486);
    StringImpl* aria_activedescendantImpl = StringImpl::createStatic("aria-activedescendant", 21, 13338511);
    StringImpl* aria_atomicImpl = StringImpl::createStatic("aria-atomic", 11, 12819054);
    StringImpl* aria_busyImpl = StringImpl::createStatic("aria-busy", 9, 75863);
    StringImpl* aria_checkedImpl = StringImpl::createStatic("aria-checked", 12, 1517039);
    StringImpl* aria_controlsImpl = StringImpl::createStatic("aria-controls", 13, 5490937);
    StringImpl* aria_describedbyImpl = StringImpl::createStatic("aria-describedby", 16, 5549123);
    StringImpl* aria_disabledImpl = StringImpl::createStatic("aria-disabled", 13, 1389455);
    StringImpl* aria_dropeffectImpl = StringImpl::createStatic("aria-dropeffect", 15, 6009141);
    StringImpl* aria_expandedImpl = StringImpl::createStatic("aria-expanded", 13, 6946219);
    StringImpl* aria_flowtoImpl = StringImpl::createStatic("aria-flowto", 11, 12186959);
    StringImpl* aria_grabbedImpl = StringImpl::createStatic("aria-grabbed", 12, 5310651);
    StringImpl* aria_haspopupImpl = StringImpl::createStatic("aria-haspopup", 13, 7196359);
    StringImpl* aria_helpImpl = StringImpl::createStatic("aria-help", 9, 12225580);
    StringImpl* aria_hiddenImpl = StringImpl::createStatic("aria-hidden", 11, 7981896);
    StringImpl* aria_invalidImpl = StringImpl::createStatic("aria-invalid", 12, 3505375);
    StringImpl* aria_labelImpl = StringImpl::createStatic("aria-label", 10, 561329);
    StringImpl* aria_labeledbyImpl = StringImpl::createStatic("aria-labeledby", 14, 5436988);
    StringImpl* aria_labelledbyImpl = StringImpl::createStatic("aria-labelledby", 15, 5412329);
    StringImpl* aria_levelImpl = StringImpl::createStatic("aria-level", 10, 8886396);
    StringImpl* aria_liveImpl = StringImpl::createStatic("aria-live", 9, 2064917);
    StringImpl* aria_multilineImpl = StringImpl::createStatic("aria-multiline", 14, 13431022);
    StringImpl* aria_multiselectableImpl = StringImpl::createStatic("aria-multiselectable", 20, 14347206);
    StringImpl* aria_orientationImpl = StringImpl::createStatic("aria-orientation", 16, 11685540);
    StringImpl* aria_ownsImpl = StringImpl::createStatic("aria-owns", 9, 15671106);
    StringImpl* aria_posinsetImpl = StringImpl::createStatic("aria-posinset", 13, 14818088);
    StringImpl* aria_pressedImpl = StringImpl::createStatic("aria-pressed", 12, 8024627);
    StringImpl* aria_readonlyImpl = StringImpl::createStatic("aria-readonly", 13, 1588657);
    StringImpl* aria_relevantImpl = StringImpl::createStatic("aria-relevant", 13, 16457375);
    StringImpl* aria_requiredImpl = StringImpl::createStatic("aria-required", 13, 10656135);
    StringImpl* aria_selectedImpl = StringImpl::createStatic("aria-selected", 13, 16608989);
    StringImpl* aria_setsizeImpl = StringImpl::createStatic("aria-setsize", 12, 13328899);
    StringImpl* aria_sortImpl = StringImpl::createStatic("aria-sort", 9, 15568337);
    StringImpl* aria_valuemaxImpl = StringImpl::createStatic("aria-valuemax", 13, 15306660);
    StringImpl* aria_valueminImpl = StringImpl::createStatic("aria-valuemin", 13, 2814091);
    StringImpl* aria_valuenowImpl = StringImpl::createStatic("aria-valuenow", 13, 10189949);
    StringImpl* aria_valuetextImpl = StringImpl::createStatic("aria-valuetext", 14, 14438832);
    StringImpl* articleImpl = StringImpl::createStatic("article", 7, 2968800);
    StringImpl* asideImpl = StringImpl::createStatic("aside", 5, 10128566);
    StringImpl* asyncImpl = StringImpl::createStatic("async", 5, 2556481);
    StringImpl* audioImpl = StringImpl::createStatic("audio", 5, 2129307);
    StringImpl* autocompleteImpl = StringImpl::createStatic("autocomplete", 12, 14667434);
    StringImpl* autofocusImpl = StringImpl::createStatic("autofocus", 9, 16282013);
    StringImpl* autoplayImpl = StringImpl::createStatic("autoplay", 8, 12002525);
    StringImpl* axisImpl = StringImpl::createStatic("axis", 4, 14347904);
    StringImpl* bImpl = StringImpl::createStatic("b", 1, 7170995);
    StringImpl* backgroundImpl = StringImpl::createStatic("background", 10, 8107606);
    StringImpl* baseImpl = StringImpl::createStatic("base", 4, 4376626);
    StringImpl* basefontImpl = StringImpl::createStatic("basefont", 8, 5439393);
    StringImpl* bdiImpl = StringImpl::createStatic("bdi", 3, 14809812);
    StringImpl* bdoImpl = StringImpl::createStatic("bdo", 3, 9906743);
    StringImpl* behaviorImpl = StringImpl::createStatic("behavior", 8, 11804611);
    StringImpl* bgcolorImpl = StringImpl::createStatic("bgcolor", 7, 11074228);
    StringImpl* bgpropertiesImpl = StringImpl::createStatic("bgproperties", 12, 15013629);
    StringImpl* bgsoundImpl = StringImpl::createStatic("bgsound", 7, 9424179);
    StringImpl* bigImpl = StringImpl::createStatic("big", 3, 2330122);
    StringImpl* blockquoteImpl = StringImpl::createStatic("blockquote", 10, 6047050);
    StringImpl* bodyImpl = StringImpl::createStatic("body", 4, 4862692);
    StringImpl* borderImpl = StringImpl::createStatic("border", 6, 4389816);
    StringImpl* bordercolorImpl = StringImpl::createStatic("bordercolor", 11, 12757423);
    StringImpl* brImpl = StringImpl::createStatic("br", 2, 5574895);
    StringImpl* buttonImpl = StringImpl::createStatic("button", 6, 679691);
    StringImpl* canvasImpl = StringImpl::createStatic("canvas", 6, 10973550);
    StringImpl* captionImpl = StringImpl::createStatic("caption", 7, 2437650);
    StringImpl* captureImpl = StringImpl::createStatic("capture", 7, 9991654);
    StringImpl* cellborderImpl = StringImpl::createStatic("cellborder", 10, 8324519);
    StringImpl* cellpaddingImpl = StringImpl::createStatic("cellpadding", 11, 3763331);
    StringImpl* cellspacingImpl = StringImpl::createStatic("cellspacing", 11, 7849745);
    StringImpl* centerImpl = StringImpl::createStatic("center", 6, 909285);
    StringImpl* challengeImpl = StringImpl::createStatic("challenge", 9, 12755365);
    StringImpl* charImpl = StringImpl::createStatic("char", 4, 12296599);
    StringImpl* charoffImpl = StringImpl::createStatic("charoff", 7, 5577617);
    StringImpl* charsetImpl = StringImpl::createStatic("charset", 7, 14273970);
    StringImpl* checkedImpl = StringImpl::createStatic("checked", 7, 10213523);
    StringImpl* citeImpl = StringImpl::createStatic("cite", 4, 3704129);
    StringImpl* classImpl = StringImpl::createStatic("class", 5, 1023741);
    StringImpl* classidImpl = StringImpl::createStatic("classid", 7, 1789995);
    StringImpl* clearImpl = StringImpl::createStatic("clear", 5, 12832795);
    StringImpl* codeImpl = StringImpl::createStatic("code", 4, 11588001);
    StringImpl* codebaseImpl = StringImpl::createStatic("codebase", 8, 3375722);
    StringImpl* codetypeImpl = StringImpl::createStatic("codetype", 8, 7482920);
    StringImpl* colImpl = StringImpl::createStatic("col", 3, 12850806);
    StringImpl* colgroupImpl = StringImpl::createStatic("colgroup", 8, 3733719);
    StringImpl* colorImpl = StringImpl::createStatic("color", 5, 2734929);
    StringImpl* colsImpl = StringImpl::createStatic("cols", 4, 4921975);
    StringImpl* colspanImpl = StringImpl::createStatic("colspan", 7, 9715319);
    StringImpl* commandImpl = StringImpl::createStatic("command", 7, 2099501);
    StringImpl* compactImpl = StringImpl::createStatic("compact", 7, 369367);
    StringImpl* compositeImpl = StringImpl::createStatic("composite", 9, 9206665);
    StringImpl* contentImpl = StringImpl::createStatic("content", 7, 6894765);
    StringImpl* contenteditableImpl = StringImpl::createStatic("contenteditable", 15, 1577657);
    StringImpl* controlsImpl = StringImpl::createStatic("controls", 8, 3696819);
    StringImpl* coordsImpl = StringImpl::createStatic("coords", 6, 14288829);
    StringImpl* crossoriginImpl = StringImpl::createStatic("crossorigin", 11, 15142862);
    StringImpl* dataImpl = StringImpl::createStatic("data", 4, 5273875);
    StringImpl* datalistImpl = StringImpl::createStatic("datalist", 8, 7058973);
    StringImpl* datetimeImpl = StringImpl::createStatic("datetime", 8, 12167257);
    StringImpl* ddImpl = StringImpl::createStatic("dd", 2, 16480447);
    StringImpl* declareImpl = StringImpl::createStatic("declare", 7, 13440114);
    StringImpl* defaultImpl = StringImpl::createStatic("default", 7, 6674383);
    StringImpl* deferImpl = StringImpl::createStatic("defer", 5, 13832204);
    StringImpl* delImpl = StringImpl::createStatic("del", 3, 2501459);
    StringImpl* detailsImpl = StringImpl::createStatic("details", 7, 4653180);
    StringImpl* dfnImpl = StringImpl::createStatic("dfn", 3, 5168569);
    StringImpl* dialogImpl = StringImpl::createStatic("dialog", 6, 1232842);
    StringImpl* dirImpl = StringImpl::createStatic("dir", 3, 5122803);
    StringImpl* directionImpl = StringImpl::createStatic("direction", 9, 16092904);
    StringImpl* dirnameImpl = StringImpl::createStatic("dirname", 7, 9899348);
    StringImpl* disabledImpl = StringImpl::createStatic("disabled", 8, 12237545);
    StringImpl* dispositionImpl = StringImpl::createStatic("disposition", 11, 8748813);
    StringImpl* divImpl = StringImpl::createStatic("div", 3, 9762591);
    StringImpl* dlImpl = StringImpl::createStatic("dl", 2, 5117854);
    StringImpl* downloadImpl = StringImpl::createStatic("download", 8, 1050544);
    StringImpl* draggableImpl = StringImpl::createStatic("draggable", 9, 9281278);
    StringImpl* dtImpl = StringImpl::createStatic("dt", 2, 8177126);
    StringImpl* emImpl = StringImpl::createStatic("em", 2, 2724661);
    StringImpl* embedImpl = StringImpl::createStatic("embed", 5, 855371);
    StringImpl* enctypeImpl = StringImpl::createStatic("enctype", 7, 11388071);
    StringImpl* endImpl = StringImpl::createStatic("end", 3, 1590106);
    StringImpl* eventImpl = StringImpl::createStatic("event", 5, 4205160);
    StringImpl* expandedImpl = StringImpl::createStatic("expanded", 8, 13934961);
    StringImpl* faceImpl = StringImpl::createStatic("face", 4, 12427611);
    StringImpl* fieldsetImpl = StringImpl::createStatic("fieldset", 8, 37097);
    StringImpl* figcaptionImpl = StringImpl::createStatic("figcaption", 10, 13388641);
    StringImpl* figureImpl = StringImpl::createStatic("figure", 6, 13776479);
    StringImpl* focusedImpl = StringImpl::createStatic("focused", 7, 6735095);
    StringImpl* fontImpl = StringImpl::createStatic("font", 4, 4588695);
    StringImpl* footerImpl = StringImpl::createStatic("footer", 6, 13359933);
    StringImpl* forImpl = StringImpl::createStatic("for", 3, 4145292);
    StringImpl* formImpl = StringImpl::createStatic("form", 4, 10060301);
    StringImpl* formactionImpl = StringImpl::createStatic("formaction", 10, 12667227);
    StringImpl* formenctypeImpl = StringImpl::createStatic("formenctype", 11, 6334991);
    StringImpl* formmethodImpl = StringImpl::createStatic("formmethod", 10, 7653832);
    StringImpl* formnovalidateImpl = StringImpl::createStatic("formnovalidate", 14, 5722173);
    StringImpl* formtargetImpl = StringImpl::createStatic("formtarget", 10, 15594141);
    StringImpl* frameImpl = StringImpl::createStatic("frame", 5, 3408403);
    StringImpl* frameborderImpl = StringImpl::createStatic("frameborder", 11, 6035536);
    StringImpl* framesetImpl = StringImpl::createStatic("frameset", 8, 11229107);
    StringImpl* h1Impl = StringImpl::createStatic("h1", 2, 3953979);
    StringImpl* h2Impl = StringImpl::createStatic("h2", 2, 9378819);
    StringImpl* h3Impl = StringImpl::createStatic("h3", 2, 1803164);
    StringImpl* h4Impl = StringImpl::createStatic("h4", 2, 15343268);
    StringImpl* h5Impl = StringImpl::createStatic("h5", 2, 8065295);
    StringImpl* h6Impl = StringImpl::createStatic("h6", 2, 9566891);
    StringImpl* headImpl = StringImpl::createStatic("head", 4, 11457121);
    StringImpl* headerImpl = StringImpl::createStatic("header", 6, 5896178);
    StringImpl* headersImpl = StringImpl::createStatic("headers", 7, 2627673);
    StringImpl* heightImpl = StringImpl::createStatic("height", 6, 6697833);
    StringImpl* hgroupImpl = StringImpl::createStatic("hgroup", 6, 8927907);
    StringImpl* hiddenImpl = StringImpl::createStatic("hidden", 6, 12930326);
    StringImpl* highImpl = StringImpl::createStatic("high", 4, 11748844);
    StringImpl* hrImpl = StringImpl::createStatic("hr", 2, 7182703);
    StringImpl* hrefImpl = StringImpl::createStatic("href", 4, 5797448);
    StringImpl* hreflangImpl = StringImpl::createStatic("hreflang", 8, 12582042);
    StringImpl* hspaceImpl = StringImpl::createStatic("hspace", 6, 4182216);
    StringImpl* htmlImpl = StringImpl::createStatic("html", 4, 7123128);
    StringImpl* http_equivImpl = StringImpl::createStatic("http-equiv", 10, 12415310);
    StringImpl* iImpl = StringImpl::createStatic("i", 1, 16149244);
    StringImpl* idImpl = StringImpl::createStatic("id", 2, 6145549);
    StringImpl* iframeImpl = StringImpl::createStatic("iframe", 6, 16643553);
    StringImpl* imageImpl = StringImpl::createStatic("image", 5, 10287573);
    StringImpl* imgImpl = StringImpl::createStatic("img", 3, 11398162);
    StringImpl* incrementalImpl = StringImpl::createStatic("incremental", 11, 9277578);
    StringImpl* indeterminateImpl = StringImpl::createStatic("indeterminate", 13, 10969764);
    StringImpl* inputImpl = StringImpl::createStatic("input", 5, 10365436);
    StringImpl* inputmodeImpl = StringImpl::createStatic("inputmode", 9, 2781876);
    StringImpl* insImpl = StringImpl::createStatic("ins", 3, 939786);
    StringImpl* isImpl = StringImpl::createStatic("is", 2, 15617733);
    StringImpl* ismapImpl = StringImpl::createStatic("ismap", 5, 6887213);
    StringImpl* itemidImpl = StringImpl::createStatic("itemid", 6, 12624379);
    StringImpl* itempropImpl = StringImpl::createStatic("itemprop", 8, 6187843);
    StringImpl* itemrefImpl = StringImpl::createStatic("itemref", 7, 2718931);
    StringImpl* itemscopeImpl = StringImpl::createStatic("itemscope", 9, 247653);
    StringImpl* itemtypeImpl = StringImpl::createStatic("itemtype", 8, 16502055);
    StringImpl* kbdImpl = StringImpl::createStatic("kbd", 3, 8554610);
    StringImpl* keygenImpl = StringImpl::createStatic("keygen", 6, 5603105);
    StringImpl* keytypeImpl = StringImpl::createStatic("keytype", 7, 13164152);
    StringImpl* kindImpl = StringImpl::createStatic("kind", 4, 7022868);
    StringImpl* labelImpl = StringImpl::createStatic("label", 5, 15092473);
    StringImpl* langImpl = StringImpl::createStatic("lang", 4, 3702417);
    StringImpl* languageImpl = StringImpl::createStatic("language", 8, 4109061);
    StringImpl* layerImpl = StringImpl::createStatic("layer", 5, 16475212);
    StringImpl* leftmarginImpl = StringImpl::createStatic("leftmargin", 10, 10359506);
    StringImpl* legendImpl = StringImpl::createStatic("legend", 6, 16417202);
    StringImpl* liImpl = StringImpl::createStatic("li", 2, 11097939);
    StringImpl* linkImpl = StringImpl::createStatic("link", 4, 7010491);
    StringImpl* listImpl = StringImpl::createStatic("list", 4, 15078159);
    StringImpl* listingImpl = StringImpl::createStatic("listing", 7, 15674586);
    StringImpl* longdescImpl = StringImpl::createStatic("longdesc", 8, 2363416);
    StringImpl* loopImpl = StringImpl::createStatic("loop", 4, 12741482);
    StringImpl* loopendImpl = StringImpl::createStatic("loopend", 7, 987820);
    StringImpl* loopstartImpl = StringImpl::createStatic("loopstart", 9, 15595454);
    StringImpl* lowImpl = StringImpl::createStatic("low", 3, 9523344);
    StringImpl* lowsrcImpl = StringImpl::createStatic("lowsrc", 6, 8943146);
    StringImpl* mainImpl = StringImpl::createStatic("main", 4, 13501767);
    StringImpl* manifestImpl = StringImpl::createStatic("manifest", 8, 3853375);
    StringImpl* mapImpl = StringImpl::createStatic("map", 3, 16519384);
    StringImpl* marginheightImpl = StringImpl::createStatic("marginheight", 12, 14117911);
    StringImpl* marginwidthImpl = StringImpl::createStatic("marginwidth", 11, 5458369);
    StringImpl* markImpl = StringImpl::createStatic("mark", 4, 16508213);
    StringImpl* marqueeImpl = StringImpl::createStatic("marquee", 7, 1416619);
    StringImpl* maxImpl = StringImpl::createStatic("max", 3, 3449166);
    StringImpl* maxlengthImpl = StringImpl::createStatic("maxlength", 9, 5985164);
    StringImpl* mayscriptImpl = StringImpl::createStatic("mayscript", 9, 9718095);
    StringImpl* mediaImpl = StringImpl::createStatic("media", 5, 13905581);
    StringImpl* mediagroupImpl = StringImpl::createStatic("mediagroup", 10, 13605962);
    StringImpl* menuImpl = StringImpl::createStatic("menu", 4, 13428288);
    StringImpl* metaImpl = StringImpl::createStatic("meta", 4, 14067019);
    StringImpl* meterImpl = StringImpl::createStatic("meter", 5, 5815470);
    StringImpl* methodImpl = StringImpl::createStatic("method", 6, 14679268);
    StringImpl* minImpl = StringImpl::createStatic("min", 3, 2196278);
    StringImpl* multipleImpl = StringImpl::createStatic("multiple", 8, 6185486);
    StringImpl* mutedImpl = StringImpl::createStatic("muted", 5, 11680767);
    StringImpl* nameImpl = StringImpl::createStatic("name", 4, 8774809);
    StringImpl* navImpl = StringImpl::createStatic("nav", 3, 15269619);
    StringImpl* nobrImpl = StringImpl::createStatic("nobr", 4, 419763);
    StringImpl* noembedImpl = StringImpl::createStatic("noembed", 7, 11476379);
    StringImpl* noframesImpl = StringImpl::createStatic("noframes", 8, 13751064);
    StringImpl* nohrefImpl = StringImpl::createStatic("nohref", 6, 2672291);
    StringImpl* nolayerImpl = StringImpl::createStatic("nolayer", 7, 10430133);
    StringImpl* nonceImpl = StringImpl::createStatic("nonce", 5, 12597381);
    StringImpl* noresizeImpl = StringImpl::createStatic("noresize", 8, 11098542);
    StringImpl* noscriptImpl = StringImpl::createStatic("noscript", 8, 10168152);
    StringImpl* noshadeImpl = StringImpl::createStatic("noshade", 7, 12172860);
    StringImpl* novalidateImpl = StringImpl::createStatic("novalidate", 10, 5146510);
    StringImpl* nowrapImpl = StringImpl::createStatic("nowrap", 6, 15804466);
    StringImpl* objectImpl = StringImpl::createStatic("object", 6, 6907086);
    StringImpl* olImpl = StringImpl::createStatic("ol", 2, 6672076);
    StringImpl* onabortImpl = StringImpl::createStatic("onabort", 7, 9017557);
    StringImpl* onanimationendImpl = StringImpl::createStatic("onanimationend", 14, 15950082);
    StringImpl* onanimationiterationImpl = StringImpl::createStatic("onanimationiteration", 20, 6837014);
    StringImpl* onanimationstartImpl = StringImpl::createStatic("onanimationstart", 16, 3893294);
    StringImpl* onautocompleteImpl = StringImpl::createStatic("onautocomplete", 14, 6917578);
    StringImpl* onautocompleteerrorImpl = StringImpl::createStatic("onautocompleteerror", 19, 8480614);
    StringImpl* onbeforecopyImpl = StringImpl::createStatic("onbeforecopy", 12, 10445229);
    StringImpl* onbeforecutImpl = StringImpl::createStatic("onbeforecut", 11, 7604779);
    StringImpl* onbeforeloadImpl = StringImpl::createStatic("onbeforeload", 12, 7335060);
    StringImpl* onbeforepasteImpl = StringImpl::createStatic("onbeforepaste", 13, 10932396);
    StringImpl* onbeforeunloadImpl = StringImpl::createStatic("onbeforeunload", 14, 10408067);
    StringImpl* onblurImpl = StringImpl::createStatic("onblur", 6, 10264279);
    StringImpl* oncancelImpl = StringImpl::createStatic("oncancel", 8, 1433968);
    StringImpl* oncanplayImpl = StringImpl::createStatic("oncanplay", 9, 11894364);
    StringImpl* oncanplaythroughImpl = StringImpl::createStatic("oncanplaythrough", 16, 9632525);
    StringImpl* onchangeImpl = StringImpl::createStatic("onchange", 8, 1588214);
    StringImpl* onclickImpl = StringImpl::createStatic("onclick", 7, 668060);
    StringImpl* oncloseImpl = StringImpl::createStatic("onclose", 7, 76675);
    StringImpl* oncontextmenuImpl = StringImpl::createStatic("oncontextmenu", 13, 10957436);
    StringImpl* oncopyImpl = StringImpl::createStatic("oncopy", 6, 3498124);
    StringImpl* oncuechangeImpl = StringImpl::createStatic("oncuechange", 11, 8858494);
    StringImpl* oncutImpl = StringImpl::createStatic("oncut", 5, 530518);
    StringImpl* ondblclickImpl = StringImpl::createStatic("ondblclick", 10, 9484479);
    StringImpl* ondragImpl = StringImpl::createStatic("ondrag", 6, 7755023);
    StringImpl* ondragendImpl = StringImpl::createStatic("ondragend", 9, 12737756);
    StringImpl* ondragenterImpl = StringImpl::createStatic("ondragenter", 11, 7625423);
    StringImpl* ondragleaveImpl = StringImpl::createStatic("ondragleave", 11, 2163828);
    StringImpl* ondragoverImpl = StringImpl::createStatic("ondragover", 10, 7621126);
    StringImpl* ondragstartImpl = StringImpl::createStatic("ondragstart", 11, 7563418);
    StringImpl* ondropImpl = StringImpl::createStatic("ondrop", 6, 5167850);
    StringImpl* ondurationchangeImpl = StringImpl::createStatic("ondurationchange", 16, 3875418);
    StringImpl* onemptiedImpl = StringImpl::createStatic("onemptied", 9, 7216733);
    StringImpl* onendedImpl = StringImpl::createStatic("onended", 7, 4168741);
    StringImpl* onerrorImpl = StringImpl::createStatic("onerror", 7, 2658286);
    StringImpl* onfocusImpl = StringImpl::createStatic("onfocus", 7, 11484753);
    StringImpl* onfocusinImpl = StringImpl::createStatic("onfocusin", 9, 2970475);
    StringImpl* onfocusoutImpl = StringImpl::createStatic("onfocusout", 10, 4459422);
    StringImpl* onhashchangeImpl = StringImpl::createStatic("onhashchange", 12, 897163);
    StringImpl* oninputImpl = StringImpl::createStatic("oninput", 7, 7945347);
    StringImpl* oninvalidImpl = StringImpl::createStatic("oninvalid", 9, 15155464);
    StringImpl* onkeydownImpl = StringImpl::createStatic("onkeydown", 9, 917683);
    StringImpl* onkeypressImpl = StringImpl::createStatic("onkeypress", 10, 10628960);
    StringImpl* onkeyupImpl = StringImpl::createStatic("onkeyup", 7, 7098679);
    StringImpl* onloadImpl = StringImpl::createStatic("onload", 6, 1245164);
    StringImpl* onloadeddataImpl = StringImpl::createStatic("onloadeddata", 12, 6667087);
    StringImpl* onloadedmetadataImpl = StringImpl::createStatic("onloadedmetadata", 16, 11435152);
    StringImpl* onloadstartImpl = StringImpl::createStatic("onloadstart", 11, 11661007);
    StringImpl* onmessageImpl = StringImpl::createStatic("onmessage", 9, 15511252);
    StringImpl* onmousedownImpl = StringImpl::createStatic("onmousedown", 11, 10902312);
    StringImpl* onmouseenterImpl = StringImpl::createStatic("onmouseenter", 12, 12011136);
    StringImpl* onmouseleaveImpl = StringImpl::createStatic("onmouseleave", 12, 9750696);
    StringImpl* onmousemoveImpl = StringImpl::createStatic("onmousemove", 11, 13128910);
    StringImpl* onmouseoutImpl = StringImpl::createStatic("onmouseout", 10, 3672358);
    StringImpl* onmouseoverImpl = StringImpl::createStatic("onmouseover", 11, 5456314);
    StringImpl* onmouseupImpl = StringImpl::createStatic("onmouseup", 9, 8932826);
    StringImpl* onmousewheelImpl = StringImpl::createStatic("onmousewheel", 12, 8230218);
    StringImpl* onofflineImpl = StringImpl::createStatic("onoffline", 9, 8780424);
    StringImpl* ononlineImpl = StringImpl::createStatic("ononline", 8, 6361718);
    StringImpl* onorientationchangeImpl = StringImpl::createStatic("onorientationchange", 19, 4305565);
    StringImpl* onpagehideImpl = StringImpl::createStatic("onpagehide", 10, 11684100);
    StringImpl* onpageshowImpl = StringImpl::createStatic("onpageshow", 10, 2047001);
    StringImpl* onpasteImpl = StringImpl::createStatic("onpaste", 7, 8282984);
    StringImpl* onpauseImpl = StringImpl::createStatic("onpause", 7, 9216789);
    StringImpl* onplayImpl = StringImpl::createStatic("onplay", 6, 4469333);
    StringImpl* onplayingImpl = StringImpl::createStatic("onplaying", 9, 6622660);
    StringImpl* onpopstateImpl = StringImpl::createStatic("onpopstate", 10, 5473424);
    StringImpl* onprogressImpl = StringImpl::createStatic("onprogress", 10, 11307581);
    StringImpl* onratechangeImpl = StringImpl::createStatic("onratechange", 12, 8724969);
    StringImpl* onresetImpl = StringImpl::createStatic("onreset", 7, 871509);
    StringImpl* onresizeImpl = StringImpl::createStatic("onresize", 8, 6999701);
    StringImpl* onscrollImpl = StringImpl::createStatic("onscroll", 8, 11456051);
    StringImpl* onsearchImpl = StringImpl::createStatic("onsearch", 8, 13779639);
    StringImpl* onseekedImpl = StringImpl::createStatic("onseeked", 8, 15270585);
    StringImpl* onseekingImpl = StringImpl::createStatic("onseeking", 9, 1397795);
    StringImpl* onselectImpl = StringImpl::createStatic("onselect", 8, 10837779);
    StringImpl* onselectionchangeImpl = StringImpl::createStatic("onselectionchange", 17, 2738107);
    StringImpl* onselectstartImpl = StringImpl::createStatic("onselectstart", 13, 4928924);
    StringImpl* onshowImpl = StringImpl::createStatic("onshow", 6, 15330334);
    StringImpl* onstalledImpl = StringImpl::createStatic("onstalled", 9, 366130);
    StringImpl* onstorageImpl = StringImpl::createStatic("onstorage", 9, 3472742);
    StringImpl* onsubmitImpl = StringImpl::createStatic("onsubmit", 8, 10895898);
    StringImpl* onsuspendImpl = StringImpl::createStatic("onsuspend", 9, 3306534);
    StringImpl* ontimeupdateImpl = StringImpl::createStatic("ontimeupdate", 12, 15260240);
    StringImpl* ontouchcancelImpl = StringImpl::createStatic("ontouchcancel", 13, 11977340);
    StringImpl* ontouchendImpl = StringImpl::createStatic("ontouchend", 10, 14649050);
    StringImpl* ontouchmoveImpl = StringImpl::createStatic("ontouchmove", 11, 3062696);
    StringImpl* ontouchstartImpl = StringImpl::createStatic("ontouchstart", 12, 15650339);
    StringImpl* ontransitionendImpl = StringImpl::createStatic("ontransitionend", 15, 14486006);
    StringImpl* onunloadImpl = StringImpl::createStatic("onunload", 8, 265474);
    StringImpl* onvolumechangeImpl = StringImpl::createStatic("onvolumechange", 14, 1227173);
    StringImpl* onwaitingImpl = StringImpl::createStatic("onwaiting", 9, 14930497);
    StringImpl* onwebkitanimationendImpl = StringImpl::createStatic("onwebkitanimationend", 20, 4247475);
    StringImpl* onwebkitanimationiterationImpl = StringImpl::createStatic("onwebkitanimationiteration", 26, 2350168);
    StringImpl* onwebkitanimationstartImpl = StringImpl::createStatic("onwebkitanimationstart", 22, 1438902);
    StringImpl* onwebkitfullscreenchangeImpl = StringImpl::createStatic("onwebkitfullscreenchange", 24, 4583393);
    StringImpl* onwebkitfullscreenerrorImpl = StringImpl::createStatic("onwebkitfullscreenerror", 23, 16488541);
    StringImpl* onwebkitkeyaddedImpl = StringImpl::createStatic("onwebkitkeyadded", 16, 5334111);
    StringImpl* onwebkitkeyerrorImpl = StringImpl::createStatic("onwebkitkeyerror", 16, 11199297);
    StringImpl* onwebkitkeymessageImpl = StringImpl::createStatic("onwebkitkeymessage", 18, 13202216);
    StringImpl* onwebkitneedkeyImpl = StringImpl::createStatic("onwebkitneedkey", 15, 859938);
    StringImpl* onwebkitsourcecloseImpl = StringImpl::createStatic("onwebkitsourceclose", 19, 10042583);
    StringImpl* onwebkitsourceendedImpl = StringImpl::createStatic("onwebkitsourceended", 19, 12655944);
    StringImpl* onwebkitsourceopenImpl = StringImpl::createStatic("onwebkitsourceopen", 18, 11118609);
    StringImpl* onwebkitspeechchangeImpl = StringImpl::createStatic("onwebkitspeechchange", 20, 13223170);
    StringImpl* onwebkittransitionendImpl = StringImpl::createStatic("onwebkittransitionend", 21, 3568476);
    StringImpl* onwheelImpl = StringImpl::createStatic("onwheel", 7, 3280514);
    StringImpl* openImpl = StringImpl::createStatic("open", 4, 13703631);
    StringImpl* optgroupImpl = StringImpl::createStatic("optgroup", 8, 10180907);
    StringImpl* optimumImpl = StringImpl::createStatic("optimum", 7, 3350287);
    StringImpl* optionImpl = StringImpl::createStatic("option", 6, 2998548);
    StringImpl* outputImpl = StringImpl::createStatic("output", 6, 15319621);
    StringImpl* pImpl = StringImpl::createStatic("p", 1, 587733);
    StringImpl* paramImpl = StringImpl::createStatic("param", 5, 15210019);
    StringImpl* patternImpl = StringImpl::createStatic("pattern", 7, 16283150);
    StringImpl* pingImpl = StringImpl::createStatic("ping", 4, 9193756);
    StringImpl* placeholderImpl = StringImpl::createStatic("placeholder", 11, 6132349);
    StringImpl* plaintextImpl = StringImpl::createStatic("plaintext", 9, 2551274);
    StringImpl* playcountImpl = StringImpl::createStatic("playcount", 9, 16731673);
    StringImpl* pluginspageImpl = StringImpl::createStatic("pluginspage", 11, 13244573);
    StringImpl* pluginurlImpl = StringImpl::createStatic("pluginurl", 9, 13481259);
    StringImpl* posterImpl = StringImpl::createStatic("poster", 6, 2570443);
    StringImpl* preImpl = StringImpl::createStatic("pre", 3, 16061734);
    StringImpl* precisionImpl = StringImpl::createStatic("precision", 9, 2942017);
    StringImpl* preloadImpl = StringImpl::createStatic("preload", 7, 11887554);
    StringImpl* primaryImpl = StringImpl::createStatic("primary", 7, 421132);
    StringImpl* profileImpl = StringImpl::createStatic("profile", 7, 10479533);
    StringImpl* progressImpl = StringImpl::createStatic("progress", 8, 11461517);
    StringImpl* promptImpl = StringImpl::createStatic("prompt", 6, 3532635);
    StringImpl* pseudoImpl = StringImpl::createStatic("pseudo", 6, 6923620);
    StringImpl* qImpl = StringImpl::createStatic("q", 1, 12607837);
    StringImpl* readonlyImpl = StringImpl::createStatic("readonly", 8, 4471832);
    StringImpl* relImpl = StringImpl::createStatic("rel", 3, 8963158);
    StringImpl* requiredImpl = StringImpl::createStatic("required", 8, 4894573);
    StringImpl* reset_style_inheritanceImpl = StringImpl::createStatic("reset-style-inheritance", 23, 10447532);
    StringImpl* resultsImpl = StringImpl::createStatic("results", 7, 972036);
    StringImpl* revImpl = StringImpl::createStatic("rev", 3, 12217053);
    StringImpl* reversedImpl = StringImpl::createStatic("reversed", 8, 15723650);
    StringImpl* roleImpl = StringImpl::createStatic("role", 4, 16084934);
    StringImpl* rowsImpl = StringImpl::createStatic("rows", 4, 11770835);
    StringImpl* rowspanImpl = StringImpl::createStatic("rowspan", 7, 13630419);
    StringImpl* rpImpl = StringImpl::createStatic("rp", 2, 4502666);
    StringImpl* rtImpl = StringImpl::createStatic("rt", 2, 8494892);
    StringImpl* rubyImpl = StringImpl::createStatic("ruby", 4, 12793227);
    StringImpl* rulesImpl = StringImpl::createStatic("rules", 5, 8604373);
    StringImpl* sImpl = StringImpl::createStatic("s", 1, 11249530);
    StringImpl* sampImpl = StringImpl::createStatic("samp", 4, 3617274);
    StringImpl* sandboxImpl = StringImpl::createStatic("sandbox", 7, 3448190);
    StringImpl* schemeImpl = StringImpl::createStatic("scheme", 6, 3952063);
    StringImpl* scopeImpl = StringImpl::createStatic("scope", 5, 5624816);
    StringImpl* scopedImpl = StringImpl::createStatic("scoped", 6, 8814668);
    StringImpl* scriptImpl = StringImpl::createStatic("script", 6, 7137273);
    StringImpl* scrollamountImpl = StringImpl::createStatic("scrollamount", 12, 8309213);
    StringImpl* scrolldelayImpl = StringImpl::createStatic("scrolldelay", 11, 15755012);
    StringImpl* scrollingImpl = StringImpl::createStatic("scrolling", 9, 4321742);
    StringImpl* sectionImpl = StringImpl::createStatic("section", 7, 8056235);
    StringImpl* selectImpl = StringImpl::createStatic("select", 6, 210571);
    StringImpl* selectedImpl = StringImpl::createStatic("selected", 8, 15762609);
    StringImpl* shadowImpl = StringImpl::createStatic("shadow", 6, 1972219);
    StringImpl* shapeImpl = StringImpl::createStatic("shape", 5, 15210140);
    StringImpl* sizeImpl = StringImpl::createStatic("size", 4, 12715024);
    StringImpl* sizesImpl = StringImpl::createStatic("sizes", 5, 6795010);
    StringImpl* smallImpl = StringImpl::createStatic("small", 5, 14362904);
    StringImpl* sortableImpl = StringImpl::createStatic("sortable", 8, 6619850);
    StringImpl* sortdirectionImpl = StringImpl::createStatic("sortdirection", 13, 7163200);
    StringImpl* sourceImpl = StringImpl::createStatic("source", 6, 341674);
    StringImpl* spanImpl = StringImpl::createStatic("span", 4, 11168892);
    StringImpl* spellcheckImpl = StringImpl::createStatic("spellcheck", 10, 4108424);
    StringImpl* srcImpl = StringImpl::createStatic("src", 3, 11517827);
    StringImpl* srcdocImpl = StringImpl::createStatic("srcdoc", 6, 15297056);
    StringImpl* srclangImpl = StringImpl::createStatic("srclang", 7, 13402710);
    StringImpl* srcsetImpl = StringImpl::createStatic("srcset", 6, 6236095);
    StringImpl* standbyImpl = StringImpl::createStatic("standby", 7, 8394231);
    StringImpl* startImpl = StringImpl::createStatic("start", 5, 1021290);
    StringImpl* stepImpl = StringImpl::createStatic("step", 4, 5337026);
    StringImpl* strikeImpl = StringImpl::createStatic("strike", 6, 15072495);
    StringImpl* strongImpl = StringImpl::createStatic("strong", 6, 13282129);
    StringImpl* styleImpl = StringImpl::createStatic("style", 5, 10993676);
    StringImpl* subImpl = StringImpl::createStatic("sub", 3, 15782866);
    StringImpl* summaryImpl = StringImpl::createStatic("summary", 7, 1148260);
    StringImpl* supImpl = StringImpl::createStatic("sup", 3, 8741418);
    StringImpl* tabindexImpl = StringImpl::createStatic("tabindex", 8, 10415591);
    StringImpl* tableImpl = StringImpl::createStatic("table", 5, 8181317);
    StringImpl* tableborderImpl = StringImpl::createStatic("tableborder", 11, 4105225);
    StringImpl* targetImpl = StringImpl::createStatic("target", 6, 1752822);
    StringImpl* tbodyImpl = StringImpl::createStatic("tbody", 5, 14028375);
    StringImpl* tdImpl = StringImpl::createStatic("td", 2, 10309076);
    StringImpl* templateImpl = StringImpl::createStatic("template", 8, 12693000);
    StringImpl* textImpl = StringImpl::createStatic("text", 4, 2784654);
    StringImpl* textareaImpl = StringImpl::createStatic("textarea", 8, 10510497);
    StringImpl* tfootImpl = StringImpl::createStatic("tfoot", 5, 13009441);
    StringImpl* thImpl = StringImpl::createStatic("th", 2, 3915297);
    StringImpl* theadImpl = StringImpl::createStatic("thead", 5, 13349519);
    StringImpl* titleImpl = StringImpl::createStatic("title", 5, 2337488);
    StringImpl* topImpl = StringImpl::createStatic("top", 3, 14467303);
    StringImpl* topmarginImpl = StringImpl::createStatic("topmargin", 9, 10843382);
    StringImpl* trImpl = StringImpl::createStatic("tr", 2, 16624306);
    StringImpl* trackImpl = StringImpl::createStatic("track", 5, 10988706);
    StringImpl* translateImpl = StringImpl::createStatic("translate", 9, 9982484);
    StringImpl* truespeedImpl = StringImpl::createStatic("truespeed", 9, 11732619);
    StringImpl* ttImpl = StringImpl::createStatic("tt", 2, 9170852);
    StringImpl* typeImpl = StringImpl::createStatic("type", 4, 1916283);
    StringImpl* uImpl = StringImpl::createStatic("u", 1, 13317144);
    StringImpl* ulImpl = StringImpl::createStatic("ul", 2, 12324505);
    StringImpl* usemapImpl = StringImpl::createStatic("usemap", 6, 16643238);
    StringImpl* valignImpl = StringImpl::createStatic("valign", 6, 8345445);
    StringImpl* valueImpl = StringImpl::createStatic("value", 5, 10871467);
    StringImpl* valuetypeImpl = StringImpl::createStatic("valuetype", 9, 4808367);
    StringImpl* varImpl = StringImpl::createStatic("var", 3, 9573901);
    StringImpl* versionImpl = StringImpl::createStatic("version", 7, 8128447);
    StringImpl* videoImpl = StringImpl::createStatic("video", 5, 16765639);
    StringImpl* vlinkImpl = StringImpl::createStatic("vlink", 5, 12743618);
    StringImpl* vspaceImpl = StringImpl::createStatic("vspace", 6, 9862276);
    StringImpl* wbrImpl = StringImpl::createStatic("wbr", 3, 8290101);
    StringImpl* webkitallowfullscreenImpl = StringImpl::createStatic("webkitallowfullscreen", 21, 1373167);
    StringImpl* webkitdirectoryImpl = StringImpl::createStatic("webkitdirectory", 15, 1344740);
    StringImpl* webkitdropzoneImpl = StringImpl::createStatic("webkitdropzone", 14, 5315147);
    StringImpl* widthImpl = StringImpl::createStatic("width", 5, 12902275);
    StringImpl* wrapImpl = StringImpl::createStatic("wrap", 4, 7601899);
    StringImpl* webkitgrammarImpl = StringImpl::createStatic("x-webkit-grammar", 16, 3776340);
    StringImpl* webkitspeechImpl = StringImpl::createStatic("x-webkit-speech", 15, 7275232);
    StringImpl* xmpImpl = StringImpl::createStatic("xmp", 3, 8764488);

    // Tags
    createQualifiedName((void*)&abbrTag, abbrImpl, xhtmlNS);
    createQualifiedName((void*)&acronymTag, acronymImpl, xhtmlNS);
    createQualifiedName((void*)&addressTag, addressImpl, xhtmlNS);
    createQualifiedName((void*)&articleTag, articleImpl, xhtmlNS);
    createQualifiedName((void*)&asideTag, asideImpl, xhtmlNS);
    createQualifiedName((void*)&bTag, bImpl, xhtmlNS);
    createQualifiedName((void*)&basefontTag, basefontImpl, xhtmlNS);
    createQualifiedName((void*)&bdoTag, bdoImpl, xhtmlNS);
    createQualifiedName((void*)&bgsoundTag, bgsoundImpl, xhtmlNS);
    createQualifiedName((void*)&bigTag, bigImpl, xhtmlNS);
    createQualifiedName((void*)&centerTag, centerImpl, xhtmlNS);
    createQualifiedName((void*)&citeTag, citeImpl, xhtmlNS);
    createQualifiedName((void*)&codeTag, codeImpl, xhtmlNS);
    createQualifiedName((void*)&commandTag, commandImpl, xhtmlNS);
    createQualifiedName((void*)&ddTag, ddImpl, xhtmlNS);
    createQualifiedName((void*)&dfnTag, dfnImpl, xhtmlNS);
    createQualifiedName((void*)&dtTag, dtImpl, xhtmlNS);
    createQualifiedName((void*)&emTag, emImpl, xhtmlNS);
    createQualifiedName((void*)&figcaptionTag, figcaptionImpl, xhtmlNS);
    createQualifiedName((void*)&figureTag, figureImpl, xhtmlNS);
    createQualifiedName((void*)&footerTag, footerImpl, xhtmlNS);
    createQualifiedName((void*)&headerTag, headerImpl, xhtmlNS);
    createQualifiedName((void*)&hgroupTag, hgroupImpl, xhtmlNS);
    createQualifiedName((void*)&iTag, iImpl, xhtmlNS);
    createQualifiedName((void*)&kbdTag, kbdImpl, xhtmlNS);
    createQualifiedName((void*)&layerTag, layerImpl, xhtmlNS);
    createQualifiedName((void*)&mainTag, mainImpl, xhtmlNS);
    createQualifiedName((void*)&markTag, markImpl, xhtmlNS);
    createQualifiedName((void*)&navTag, navImpl, xhtmlNS);
    createQualifiedName((void*)&nobrTag, nobrImpl, xhtmlNS);
    createQualifiedName((void*)&noframesTag, noframesImpl, xhtmlNS);
    createQualifiedName((void*)&nolayerTag, nolayerImpl, xhtmlNS);
    createQualifiedName((void*)&plaintextTag, plaintextImpl, xhtmlNS);
    createQualifiedName((void*)&rpTag, rpImpl, xhtmlNS);
    createQualifiedName((void*)&sTag, sImpl, xhtmlNS);
    createQualifiedName((void*)&sampTag, sampImpl, xhtmlNS);
    createQualifiedName((void*)&sectionTag, sectionImpl, xhtmlNS);
    createQualifiedName((void*)&smallTag, smallImpl, xhtmlNS);
    createQualifiedName((void*)&strikeTag, strikeImpl, xhtmlNS);
    createQualifiedName((void*)&strongTag, strongImpl, xhtmlNS);
    createQualifiedName((void*)&subTag, subImpl, xhtmlNS);
    createQualifiedName((void*)&supTag, supImpl, xhtmlNS);
    createQualifiedName((void*)&ttTag, ttImpl, xhtmlNS);
    createQualifiedName((void*)&uTag, uImpl, xhtmlNS);
    createQualifiedName((void*)&varTag, varImpl, xhtmlNS);
    createQualifiedName((void*)&aTag, aImpl, xhtmlNS);
    createQualifiedName((void*)&areaTag, areaImpl, xhtmlNS);
    createQualifiedName((void*)&audioTag, audioImpl, xhtmlNS);
    createQualifiedName((void*)&brTag, brImpl, xhtmlNS);
    createQualifiedName((void*)&baseTag, baseImpl, xhtmlNS);
    createQualifiedName((void*)&bodyTag, bodyImpl, xhtmlNS);
    createQualifiedName((void*)&canvasTag, canvasImpl, xhtmlNS);
    createQualifiedName((void*)&contentTag, contentImpl, xhtmlNS);
    createQualifiedName((void*)&dlTag, dlImpl, xhtmlNS);
    createQualifiedName((void*)&datalistTag, datalistImpl, xhtmlNS);
    createQualifiedName((void*)&detailsTag, detailsImpl, xhtmlNS);
    createQualifiedName((void*)&dirTag, dirImpl, xhtmlNS);
    createQualifiedName((void*)&divTag, divImpl, xhtmlNS);
    createQualifiedName((void*)&fontTag, fontImpl, xhtmlNS);
    createQualifiedName((void*)&formTag, formImpl, xhtmlNS);
    createQualifiedName((void*)&frameTag, frameImpl, xhtmlNS);
    createQualifiedName((void*)&framesetTag, framesetImpl, xhtmlNS);
    createQualifiedName((void*)&hrTag, hrImpl, xhtmlNS);
    createQualifiedName((void*)&headTag, headImpl, xhtmlNS);
    createQualifiedName((void*)&h1Tag, h1Impl, xhtmlNS);
    createQualifiedName((void*)&h2Tag, h2Impl, xhtmlNS);
    createQualifiedName((void*)&h3Tag, h3Impl, xhtmlNS);
    createQualifiedName((void*)&h4Tag, h4Impl, xhtmlNS);
    createQualifiedName((void*)&h5Tag, h5Impl, xhtmlNS);
    createQualifiedName((void*)&h6Tag, h6Impl, xhtmlNS);
    createQualifiedName((void*)&htmlTag, htmlImpl, xhtmlNS);
    createQualifiedName((void*)&iframeTag, iframeImpl, xhtmlNS);
    createQualifiedName((void*)&liTag, liImpl, xhtmlNS);
    createQualifiedName((void*)&labelTag, labelImpl, xhtmlNS);
    createQualifiedName((void*)&legendTag, legendImpl, xhtmlNS);
    createQualifiedName((void*)&mapTag, mapImpl, xhtmlNS);
    createQualifiedName((void*)&marqueeTag, marqueeImpl, xhtmlNS);
    createQualifiedName((void*)&menuTag, menuImpl, xhtmlNS);
    createQualifiedName((void*)&metaTag, metaImpl, xhtmlNS);
    createQualifiedName((void*)&meterTag, meterImpl, xhtmlNS);
    createQualifiedName((void*)&delTag, delImpl, xhtmlNS);
    createQualifiedName((void*)&insTag, insImpl, xhtmlNS);
    createQualifiedName((void*)&olTag, olImpl, xhtmlNS);
    createQualifiedName((void*)&optgroupTag, optgroupImpl, xhtmlNS);
    createQualifiedName((void*)&optionTag, optionImpl, xhtmlNS);
    createQualifiedName((void*)&pTag, pImpl, xhtmlNS);
    createQualifiedName((void*)&paramTag, paramImpl, xhtmlNS);
    createQualifiedName((void*)&preTag, preImpl, xhtmlNS);
    createQualifiedName((void*)&listingTag, listingImpl, xhtmlNS);
    createQualifiedName((void*)&xmpTag, xmpImpl, xhtmlNS);
    createQualifiedName((void*)&progressTag, progressImpl, xhtmlNS);
    createQualifiedName((void*)&blockquoteTag, blockquoteImpl, xhtmlNS);
    createQualifiedName((void*)&qTag, qImpl, xhtmlNS);
    createQualifiedName((void*)&shadowTag, shadowImpl, xhtmlNS);
    createQualifiedName((void*)&sourceTag, sourceImpl, xhtmlNS);
    createQualifiedName((void*)&spanTag, spanImpl, xhtmlNS);
    createQualifiedName((void*)&captionTag, captionImpl, xhtmlNS);
    createQualifiedName((void*)&tdTag, tdImpl, xhtmlNS);
    createQualifiedName((void*)&thTag, thImpl, xhtmlNS);
    createQualifiedName((void*)&colTag, colImpl, xhtmlNS);
    createQualifiedName((void*)&colgroupTag, colgroupImpl, xhtmlNS);
    createQualifiedName((void*)&tableTag, tableImpl, xhtmlNS);
    createQualifiedName((void*)&trTag, trImpl, xhtmlNS);
    createQualifiedName((void*)&tbodyTag, tbodyImpl, xhtmlNS);
    createQualifiedName((void*)&tfootTag, tfootImpl, xhtmlNS);
    createQualifiedName((void*)&theadTag, theadImpl, xhtmlNS);
    createQualifiedName((void*)&templateTag, templateImpl, xhtmlNS);
    createQualifiedName((void*)&titleTag, titleImpl, xhtmlNS);
    createQualifiedName((void*)&trackTag, trackImpl, xhtmlNS);
    createQualifiedName((void*)&ulTag, ulImpl, xhtmlNS);
    createQualifiedName((void*)&imageTag, imageImpl, xhtmlNS);
    createQualifiedName((void*)&videoTag, videoImpl, xhtmlNS);
    createQualifiedName((void*)&dialogTag, dialogImpl, xhtmlNS);
    createQualifiedName((void*)&buttonTag, buttonImpl, xhtmlNS);
    createQualifiedName((void*)&fieldsetTag, fieldsetImpl, xhtmlNS);
    createQualifiedName((void*)&imgTag, imgImpl, xhtmlNS);
    createQualifiedName((void*)&keygenTag, keygenImpl, xhtmlNS);
    createQualifiedName((void*)&outputTag, outputImpl, xhtmlNS);
    createQualifiedName((void*)&selectTag, selectImpl, xhtmlNS);
    createQualifiedName((void*)&textareaTag, textareaImpl, xhtmlNS);
    createQualifiedName((void*)&appletTag, appletImpl, xhtmlNS);
    createQualifiedName((void*)&embedTag, embedImpl, xhtmlNS);
    createQualifiedName((void*)&linkTag, linkImpl, xhtmlNS);
    createQualifiedName((void*)&scriptTag, scriptImpl, xhtmlNS);
    createQualifiedName((void*)&styleTag, styleImpl, xhtmlNS);
    createQualifiedName((void*)&inputTag, inputImpl, xhtmlNS);
    createQualifiedName((void*)&objectTag, objectImpl, xhtmlNS);
    createQualifiedName((void*)&bdiTag, bdiImpl, xhtmlNS);
    createQualifiedName((void*)&noembedTag, noembedImpl, xhtmlNS);
    createQualifiedName((void*)&noscriptTag, noscriptImpl, xhtmlNS);
    createQualifiedName((void*)&rtTag, rtImpl, xhtmlNS);
    createQualifiedName((void*)&rubyTag, rubyImpl, xhtmlNS);
    createQualifiedName((void*)&summaryTag, summaryImpl, xhtmlNS);
    createQualifiedName((void*)&wbrTag, wbrImpl, xhtmlNS);

    // Attrs
    createQualifiedName((void*)&abbrAttr, abbrImpl);
    createQualifiedName((void*)&acceptAttr, acceptImpl);
    createQualifiedName((void*)&accept_charsetAttr, accept_charsetImpl);
    createQualifiedName((void*)&accesskeyAttr, accesskeyImpl);
    createQualifiedName((void*)&actionAttr, actionImpl);
    createQualifiedName((void*)&alignAttr, alignImpl);
    createQualifiedName((void*)&alinkAttr, alinkImpl);
    createQualifiedName((void*)&allowfullscreenAttr, allowfullscreenImpl);
    createQualifiedName((void*)&altAttr, altImpl);
    createQualifiedName((void*)&archiveAttr, archiveImpl);
    createQualifiedName((void*)&aria_activedescendantAttr, aria_activedescendantImpl);
    createQualifiedName((void*)&aria_atomicAttr, aria_atomicImpl);
    createQualifiedName((void*)&aria_busyAttr, aria_busyImpl);
    createQualifiedName((void*)&aria_checkedAttr, aria_checkedImpl);
    createQualifiedName((void*)&aria_controlsAttr, aria_controlsImpl);
    createQualifiedName((void*)&aria_describedbyAttr, aria_describedbyImpl);
    createQualifiedName((void*)&aria_disabledAttr, aria_disabledImpl);
    createQualifiedName((void*)&aria_dropeffectAttr, aria_dropeffectImpl);
    createQualifiedName((void*)&aria_expandedAttr, aria_expandedImpl);
    createQualifiedName((void*)&aria_flowtoAttr, aria_flowtoImpl);
    createQualifiedName((void*)&aria_grabbedAttr, aria_grabbedImpl);
    createQualifiedName((void*)&aria_haspopupAttr, aria_haspopupImpl);
    createQualifiedName((void*)&aria_helpAttr, aria_helpImpl);
    createQualifiedName((void*)&aria_hiddenAttr, aria_hiddenImpl);
    createQualifiedName((void*)&aria_invalidAttr, aria_invalidImpl);
    createQualifiedName((void*)&aria_labelAttr, aria_labelImpl);
    createQualifiedName((void*)&aria_labeledbyAttr, aria_labeledbyImpl);
    createQualifiedName((void*)&aria_labelledbyAttr, aria_labelledbyImpl);
    createQualifiedName((void*)&aria_levelAttr, aria_levelImpl);
    createQualifiedName((void*)&aria_liveAttr, aria_liveImpl);
    createQualifiedName((void*)&aria_multilineAttr, aria_multilineImpl);
    createQualifiedName((void*)&aria_multiselectableAttr, aria_multiselectableImpl);
    createQualifiedName((void*)&aria_orientationAttr, aria_orientationImpl);
    createQualifiedName((void*)&aria_ownsAttr, aria_ownsImpl);
    createQualifiedName((void*)&aria_posinsetAttr, aria_posinsetImpl);
    createQualifiedName((void*)&aria_pressedAttr, aria_pressedImpl);
    createQualifiedName((void*)&aria_readonlyAttr, aria_readonlyImpl);
    createQualifiedName((void*)&aria_relevantAttr, aria_relevantImpl);
    createQualifiedName((void*)&aria_requiredAttr, aria_requiredImpl);
    createQualifiedName((void*)&aria_selectedAttr, aria_selectedImpl);
    createQualifiedName((void*)&aria_setsizeAttr, aria_setsizeImpl);
    createQualifiedName((void*)&aria_sortAttr, aria_sortImpl);
    createQualifiedName((void*)&aria_valuemaxAttr, aria_valuemaxImpl);
    createQualifiedName((void*)&aria_valueminAttr, aria_valueminImpl);
    createQualifiedName((void*)&aria_valuenowAttr, aria_valuenowImpl);
    createQualifiedName((void*)&aria_valuetextAttr, aria_valuetextImpl);
    createQualifiedName((void*)&asyncAttr, asyncImpl);
    createQualifiedName((void*)&autocompleteAttr, autocompleteImpl);
    createQualifiedName((void*)&autofocusAttr, autofocusImpl);
    createQualifiedName((void*)&autoplayAttr, autoplayImpl);
    createQualifiedName((void*)&axisAttr, axisImpl);
    createQualifiedName((void*)&backgroundAttr, backgroundImpl);
    createQualifiedName((void*)&behaviorAttr, behaviorImpl);
    createQualifiedName((void*)&bgcolorAttr, bgcolorImpl);
    createQualifiedName((void*)&bgpropertiesAttr, bgpropertiesImpl);
    createQualifiedName((void*)&borderAttr, borderImpl);
    createQualifiedName((void*)&bordercolorAttr, bordercolorImpl);
    createQualifiedName((void*)&captureAttr, captureImpl);
    createQualifiedName((void*)&cellborderAttr, cellborderImpl);
    createQualifiedName((void*)&cellpaddingAttr, cellpaddingImpl);
    createQualifiedName((void*)&cellspacingAttr, cellspacingImpl);
    createQualifiedName((void*)&challengeAttr, challengeImpl);
    createQualifiedName((void*)&charAttr, charImpl);
    createQualifiedName((void*)&charoffAttr, charoffImpl);
    createQualifiedName((void*)&charsetAttr, charsetImpl);
    createQualifiedName((void*)&checkedAttr, checkedImpl);
    createQualifiedName((void*)&citeAttr, citeImpl);
    createQualifiedName((void*)&classAttr, classImpl);
    createQualifiedName((void*)&classidAttr, classidImpl);
    createQualifiedName((void*)&clearAttr, clearImpl);
    createQualifiedName((void*)&codeAttr, codeImpl);
    createQualifiedName((void*)&codebaseAttr, codebaseImpl);
    createQualifiedName((void*)&codetypeAttr, codetypeImpl);
    createQualifiedName((void*)&colorAttr, colorImpl);
    createQualifiedName((void*)&colsAttr, colsImpl);
    createQualifiedName((void*)&colspanAttr, colspanImpl);
    createQualifiedName((void*)&compactAttr, compactImpl);
    createQualifiedName((void*)&compositeAttr, compositeImpl);
    createQualifiedName((void*)&contentAttr, contentImpl);
    createQualifiedName((void*)&contenteditableAttr, contenteditableImpl);
    createQualifiedName((void*)&controlsAttr, controlsImpl);
    createQualifiedName((void*)&coordsAttr, coordsImpl);
    createQualifiedName((void*)&crossoriginAttr, crossoriginImpl);
    createQualifiedName((void*)&dataAttr, dataImpl);
    createQualifiedName((void*)&datetimeAttr, datetimeImpl);
    createQualifiedName((void*)&declareAttr, declareImpl);
    createQualifiedName((void*)&defaultAttr, defaultImpl);
    createQualifiedName((void*)&deferAttr, deferImpl);
    createQualifiedName((void*)&dirAttr, dirImpl);
    createQualifiedName((void*)&directionAttr, directionImpl);
    createQualifiedName((void*)&dirnameAttr, dirnameImpl);
    createQualifiedName((void*)&disabledAttr, disabledImpl);
    createQualifiedName((void*)&dispositionAttr, dispositionImpl);
    createQualifiedName((void*)&downloadAttr, downloadImpl);
    createQualifiedName((void*)&draggableAttr, draggableImpl);
    createQualifiedName((void*)&enctypeAttr, enctypeImpl);
    createQualifiedName((void*)&endAttr, endImpl);
    createQualifiedName((void*)&eventAttr, eventImpl);
    createQualifiedName((void*)&expandedAttr, expandedImpl);
    createQualifiedName((void*)&faceAttr, faceImpl);
    createQualifiedName((void*)&focusedAttr, focusedImpl);
    createQualifiedName((void*)&forAttr, forImpl);
    createQualifiedName((void*)&formAttr, formImpl);
    createQualifiedName((void*)&formactionAttr, formactionImpl);
    createQualifiedName((void*)&formenctypeAttr, formenctypeImpl);
    createQualifiedName((void*)&formmethodAttr, formmethodImpl);
    createQualifiedName((void*)&formnovalidateAttr, formnovalidateImpl);
    createQualifiedName((void*)&formtargetAttr, formtargetImpl);
    createQualifiedName((void*)&frameAttr, frameImpl);
    createQualifiedName((void*)&frameborderAttr, frameborderImpl);
    createQualifiedName((void*)&headersAttr, headersImpl);
    createQualifiedName((void*)&heightAttr, heightImpl);
    createQualifiedName((void*)&hiddenAttr, hiddenImpl);
    createQualifiedName((void*)&highAttr, highImpl);
    createQualifiedName((void*)&hrefAttr, hrefImpl);
    createQualifiedName((void*)&hreflangAttr, hreflangImpl);
    createQualifiedName((void*)&hspaceAttr, hspaceImpl);
    createQualifiedName((void*)&http_equivAttr, http_equivImpl);
    createQualifiedName((void*)&idAttr, idImpl);
    createQualifiedName((void*)&incrementalAttr, incrementalImpl);
    createQualifiedName((void*)&indeterminateAttr, indeterminateImpl);
    createQualifiedName((void*)&inputmodeAttr, inputmodeImpl);
    createQualifiedName((void*)&isAttr, isImpl);
    createQualifiedName((void*)&ismapAttr, ismapImpl);
    createQualifiedName((void*)&itemidAttr, itemidImpl);
    createQualifiedName((void*)&itempropAttr, itempropImpl);
    createQualifiedName((void*)&itemrefAttr, itemrefImpl);
    createQualifiedName((void*)&itemscopeAttr, itemscopeImpl);
    createQualifiedName((void*)&itemtypeAttr, itemtypeImpl);
    createQualifiedName((void*)&keytypeAttr, keytypeImpl);
    createQualifiedName((void*)&kindAttr, kindImpl);
    createQualifiedName((void*)&labelAttr, labelImpl);
    createQualifiedName((void*)&langAttr, langImpl);
    createQualifiedName((void*)&languageAttr, languageImpl);
    createQualifiedName((void*)&leftmarginAttr, leftmarginImpl);
    createQualifiedName((void*)&linkAttr, linkImpl);
    createQualifiedName((void*)&listAttr, listImpl);
    createQualifiedName((void*)&longdescAttr, longdescImpl);
    createQualifiedName((void*)&loopAttr, loopImpl);
    createQualifiedName((void*)&loopendAttr, loopendImpl);
    createQualifiedName((void*)&loopstartAttr, loopstartImpl);
    createQualifiedName((void*)&lowAttr, lowImpl);
    createQualifiedName((void*)&lowsrcAttr, lowsrcImpl);
    createQualifiedName((void*)&manifestAttr, manifestImpl);
    createQualifiedName((void*)&marginheightAttr, marginheightImpl);
    createQualifiedName((void*)&marginwidthAttr, marginwidthImpl);
    createQualifiedName((void*)&maxAttr, maxImpl);
    createQualifiedName((void*)&maxlengthAttr, maxlengthImpl);
    createQualifiedName((void*)&mayscriptAttr, mayscriptImpl);
    createQualifiedName((void*)&mediaAttr, mediaImpl);
    createQualifiedName((void*)&mediagroupAttr, mediagroupImpl);
    createQualifiedName((void*)&methodAttr, methodImpl);
    createQualifiedName((void*)&minAttr, minImpl);
    createQualifiedName((void*)&multipleAttr, multipleImpl);
    createQualifiedName((void*)&mutedAttr, mutedImpl);
    createQualifiedName((void*)&nameAttr, nameImpl);
    createQualifiedName((void*)&nohrefAttr, nohrefImpl);
    createQualifiedName((void*)&nonceAttr, nonceImpl);
    createQualifiedName((void*)&noresizeAttr, noresizeImpl);
    createQualifiedName((void*)&noshadeAttr, noshadeImpl);
    createQualifiedName((void*)&novalidateAttr, novalidateImpl);
    createQualifiedName((void*)&nowrapAttr, nowrapImpl);
    createQualifiedName((void*)&objectAttr, objectImpl);
    createQualifiedName((void*)&onabortAttr, onabortImpl);
    createQualifiedName((void*)&onanimationendAttr, onanimationendImpl);
    createQualifiedName((void*)&onanimationiterationAttr, onanimationiterationImpl);
    createQualifiedName((void*)&onanimationstartAttr, onanimationstartImpl);
    createQualifiedName((void*)&onautocompleteAttr, onautocompleteImpl);
    createQualifiedName((void*)&onautocompleteerrorAttr, onautocompleteerrorImpl);
    createQualifiedName((void*)&onbeforecopyAttr, onbeforecopyImpl);
    createQualifiedName((void*)&onbeforecutAttr, onbeforecutImpl);
    createQualifiedName((void*)&onbeforeloadAttr, onbeforeloadImpl);
    createQualifiedName((void*)&onbeforepasteAttr, onbeforepasteImpl);
    createQualifiedName((void*)&onbeforeunloadAttr, onbeforeunloadImpl);
    createQualifiedName((void*)&onblurAttr, onblurImpl);
    createQualifiedName((void*)&oncancelAttr, oncancelImpl);
    createQualifiedName((void*)&oncanplayAttr, oncanplayImpl);
    createQualifiedName((void*)&oncanplaythroughAttr, oncanplaythroughImpl);
    createQualifiedName((void*)&onchangeAttr, onchangeImpl);
    createQualifiedName((void*)&onclickAttr, onclickImpl);
    createQualifiedName((void*)&oncloseAttr, oncloseImpl);
    createQualifiedName((void*)&oncontextmenuAttr, oncontextmenuImpl);
    createQualifiedName((void*)&oncopyAttr, oncopyImpl);
    createQualifiedName((void*)&oncuechangeAttr, oncuechangeImpl);
    createQualifiedName((void*)&oncutAttr, oncutImpl);
    createQualifiedName((void*)&ondblclickAttr, ondblclickImpl);
    createQualifiedName((void*)&ondragAttr, ondragImpl);
    createQualifiedName((void*)&ondragendAttr, ondragendImpl);
    createQualifiedName((void*)&ondragenterAttr, ondragenterImpl);
    createQualifiedName((void*)&ondragleaveAttr, ondragleaveImpl);
    createQualifiedName((void*)&ondragoverAttr, ondragoverImpl);
    createQualifiedName((void*)&ondragstartAttr, ondragstartImpl);
    createQualifiedName((void*)&ondropAttr, ondropImpl);
    createQualifiedName((void*)&ondurationchangeAttr, ondurationchangeImpl);
    createQualifiedName((void*)&onemptiedAttr, onemptiedImpl);
    createQualifiedName((void*)&onendedAttr, onendedImpl);
    createQualifiedName((void*)&onerrorAttr, onerrorImpl);
    createQualifiedName((void*)&onfocusAttr, onfocusImpl);
    createQualifiedName((void*)&onfocusinAttr, onfocusinImpl);
    createQualifiedName((void*)&onfocusoutAttr, onfocusoutImpl);
    createQualifiedName((void*)&onhashchangeAttr, onhashchangeImpl);
    createQualifiedName((void*)&oninputAttr, oninputImpl);
    createQualifiedName((void*)&oninvalidAttr, oninvalidImpl);
    createQualifiedName((void*)&onkeydownAttr, onkeydownImpl);
    createQualifiedName((void*)&onkeypressAttr, onkeypressImpl);
    createQualifiedName((void*)&onkeyupAttr, onkeyupImpl);
    createQualifiedName((void*)&onloadAttr, onloadImpl);
    createQualifiedName((void*)&onloadeddataAttr, onloadeddataImpl);
    createQualifiedName((void*)&onloadedmetadataAttr, onloadedmetadataImpl);
    createQualifiedName((void*)&onloadstartAttr, onloadstartImpl);
    createQualifiedName((void*)&onmessageAttr, onmessageImpl);
    createQualifiedName((void*)&onmousedownAttr, onmousedownImpl);
    createQualifiedName((void*)&onmouseenterAttr, onmouseenterImpl);
    createQualifiedName((void*)&onmouseleaveAttr, onmouseleaveImpl);
    createQualifiedName((void*)&onmousemoveAttr, onmousemoveImpl);
    createQualifiedName((void*)&onmouseoutAttr, onmouseoutImpl);
    createQualifiedName((void*)&onmouseoverAttr, onmouseoverImpl);
    createQualifiedName((void*)&onmouseupAttr, onmouseupImpl);
    createQualifiedName((void*)&onmousewheelAttr, onmousewheelImpl);
    createQualifiedName((void*)&onofflineAttr, onofflineImpl);
    createQualifiedName((void*)&ononlineAttr, ononlineImpl);
    createQualifiedName((void*)&onorientationchangeAttr, onorientationchangeImpl);
    createQualifiedName((void*)&onpagehideAttr, onpagehideImpl);
    createQualifiedName((void*)&onpageshowAttr, onpageshowImpl);
    createQualifiedName((void*)&onpasteAttr, onpasteImpl);
    createQualifiedName((void*)&onpauseAttr, onpauseImpl);
    createQualifiedName((void*)&onplayAttr, onplayImpl);
    createQualifiedName((void*)&onplayingAttr, onplayingImpl);
    createQualifiedName((void*)&onpopstateAttr, onpopstateImpl);
    createQualifiedName((void*)&onprogressAttr, onprogressImpl);
    createQualifiedName((void*)&onratechangeAttr, onratechangeImpl);
    createQualifiedName((void*)&onresetAttr, onresetImpl);
    createQualifiedName((void*)&onresizeAttr, onresizeImpl);
    createQualifiedName((void*)&onscrollAttr, onscrollImpl);
    createQualifiedName((void*)&onsearchAttr, onsearchImpl);
    createQualifiedName((void*)&onseekedAttr, onseekedImpl);
    createQualifiedName((void*)&onseekingAttr, onseekingImpl);
    createQualifiedName((void*)&onselectAttr, onselectImpl);
    createQualifiedName((void*)&onselectionchangeAttr, onselectionchangeImpl);
    createQualifiedName((void*)&onselectstartAttr, onselectstartImpl);
    createQualifiedName((void*)&onshowAttr, onshowImpl);
    createQualifiedName((void*)&onstalledAttr, onstalledImpl);
    createQualifiedName((void*)&onstorageAttr, onstorageImpl);
    createQualifiedName((void*)&onsubmitAttr, onsubmitImpl);
    createQualifiedName((void*)&onsuspendAttr, onsuspendImpl);
    createQualifiedName((void*)&ontimeupdateAttr, ontimeupdateImpl);
    createQualifiedName((void*)&ontouchcancelAttr, ontouchcancelImpl);
    createQualifiedName((void*)&ontouchendAttr, ontouchendImpl);
    createQualifiedName((void*)&ontouchmoveAttr, ontouchmoveImpl);
    createQualifiedName((void*)&ontouchstartAttr, ontouchstartImpl);
    createQualifiedName((void*)&ontransitionendAttr, ontransitionendImpl);
    createQualifiedName((void*)&onunloadAttr, onunloadImpl);
    createQualifiedName((void*)&onvolumechangeAttr, onvolumechangeImpl);
    createQualifiedName((void*)&onwaitingAttr, onwaitingImpl);
    createQualifiedName((void*)&onwebkitanimationendAttr, onwebkitanimationendImpl);
    createQualifiedName((void*)&onwebkitanimationiterationAttr, onwebkitanimationiterationImpl);
    createQualifiedName((void*)&onwebkitanimationstartAttr, onwebkitanimationstartImpl);
    createQualifiedName((void*)&onwebkitfullscreenchangeAttr, onwebkitfullscreenchangeImpl);
    createQualifiedName((void*)&onwebkitfullscreenerrorAttr, onwebkitfullscreenerrorImpl);
    createQualifiedName((void*)&onwebkitkeyaddedAttr, onwebkitkeyaddedImpl);
    createQualifiedName((void*)&onwebkitkeyerrorAttr, onwebkitkeyerrorImpl);
    createQualifiedName((void*)&onwebkitkeymessageAttr, onwebkitkeymessageImpl);
    createQualifiedName((void*)&onwebkitneedkeyAttr, onwebkitneedkeyImpl);
    createQualifiedName((void*)&onwebkitsourcecloseAttr, onwebkitsourcecloseImpl);
    createQualifiedName((void*)&onwebkitsourceendedAttr, onwebkitsourceendedImpl);
    createQualifiedName((void*)&onwebkitsourceopenAttr, onwebkitsourceopenImpl);
    createQualifiedName((void*)&onwebkitspeechchangeAttr, onwebkitspeechchangeImpl);
    createQualifiedName((void*)&onwebkittransitionendAttr, onwebkittransitionendImpl);
    createQualifiedName((void*)&onwheelAttr, onwheelImpl);
    createQualifiedName((void*)&openAttr, openImpl);
    createQualifiedName((void*)&optimumAttr, optimumImpl);
    createQualifiedName((void*)&patternAttr, patternImpl);
    createQualifiedName((void*)&pingAttr, pingImpl);
    createQualifiedName((void*)&placeholderAttr, placeholderImpl);
    createQualifiedName((void*)&playcountAttr, playcountImpl);
    createQualifiedName((void*)&pluginspageAttr, pluginspageImpl);
    createQualifiedName((void*)&pluginurlAttr, pluginurlImpl);
    createQualifiedName((void*)&posterAttr, posterImpl);
    createQualifiedName((void*)&precisionAttr, precisionImpl);
    createQualifiedName((void*)&preloadAttr, preloadImpl);
    createQualifiedName((void*)&primaryAttr, primaryImpl);
    createQualifiedName((void*)&profileAttr, profileImpl);
    createQualifiedName((void*)&progressAttr, progressImpl);
    createQualifiedName((void*)&promptAttr, promptImpl);
    createQualifiedName((void*)&pseudoAttr, pseudoImpl);
    createQualifiedName((void*)&readonlyAttr, readonlyImpl);
    createQualifiedName((void*)&relAttr, relImpl);
    createQualifiedName((void*)&requiredAttr, requiredImpl);
    createQualifiedName((void*)&reset_style_inheritanceAttr, reset_style_inheritanceImpl);
    createQualifiedName((void*)&resultsAttr, resultsImpl);
    createQualifiedName((void*)&revAttr, revImpl);
    createQualifiedName((void*)&reversedAttr, reversedImpl);
    createQualifiedName((void*)&roleAttr, roleImpl);
    createQualifiedName((void*)&rowsAttr, rowsImpl);
    createQualifiedName((void*)&rowspanAttr, rowspanImpl);
    createQualifiedName((void*)&rulesAttr, rulesImpl);
    createQualifiedName((void*)&sandboxAttr, sandboxImpl);
    createQualifiedName((void*)&schemeAttr, schemeImpl);
    createQualifiedName((void*)&scopeAttr, scopeImpl);
    createQualifiedName((void*)&scopedAttr, scopedImpl);
    createQualifiedName((void*)&scrollamountAttr, scrollamountImpl);
    createQualifiedName((void*)&scrolldelayAttr, scrolldelayImpl);
    createQualifiedName((void*)&scrollingAttr, scrollingImpl);
    createQualifiedName((void*)&selectAttr, selectImpl);
    createQualifiedName((void*)&selectedAttr, selectedImpl);
    createQualifiedName((void*)&shapeAttr, shapeImpl);
    createQualifiedName((void*)&sizeAttr, sizeImpl);
    createQualifiedName((void*)&sizesAttr, sizesImpl);
    createQualifiedName((void*)&sortableAttr, sortableImpl);
    createQualifiedName((void*)&sortdirectionAttr, sortdirectionImpl);
    createQualifiedName((void*)&spanAttr, spanImpl);
    createQualifiedName((void*)&spellcheckAttr, spellcheckImpl);
    createQualifiedName((void*)&srcAttr, srcImpl);
    createQualifiedName((void*)&srcdocAttr, srcdocImpl);
    createQualifiedName((void*)&srclangAttr, srclangImpl);
    createQualifiedName((void*)&srcsetAttr, srcsetImpl);
    createQualifiedName((void*)&standbyAttr, standbyImpl);
    createQualifiedName((void*)&startAttr, startImpl);
    createQualifiedName((void*)&stepAttr, stepImpl);
    createQualifiedName((void*)&styleAttr, styleImpl);
    createQualifiedName((void*)&summaryAttr, summaryImpl);
    createQualifiedName((void*)&tabindexAttr, tabindexImpl);
    createQualifiedName((void*)&tableborderAttr, tableborderImpl);
    createQualifiedName((void*)&targetAttr, targetImpl);
    createQualifiedName((void*)&textAttr, textImpl);
    createQualifiedName((void*)&titleAttr, titleImpl);
    createQualifiedName((void*)&topAttr, topImpl);
    createQualifiedName((void*)&topmarginAttr, topmarginImpl);
    createQualifiedName((void*)&translateAttr, translateImpl);
    createQualifiedName((void*)&truespeedAttr, truespeedImpl);
    createQualifiedName((void*)&typeAttr, typeImpl);
    createQualifiedName((void*)&usemapAttr, usemapImpl);
    createQualifiedName((void*)&valignAttr, valignImpl);
    createQualifiedName((void*)&valueAttr, valueImpl);
    createQualifiedName((void*)&valuetypeAttr, valuetypeImpl);
    createQualifiedName((void*)&versionAttr, versionImpl);
    createQualifiedName((void*)&vlinkAttr, vlinkImpl);
    createQualifiedName((void*)&vspaceAttr, vspaceImpl);
    createQualifiedName((void*)&webkitallowfullscreenAttr, webkitallowfullscreenImpl);
    createQualifiedName((void*)&webkitdirectoryAttr, webkitdirectoryImpl);
    createQualifiedName((void*)&webkitdropzoneAttr, webkitdropzoneImpl);
    createQualifiedName((void*)&widthAttr, widthImpl);
    createQualifiedName((void*)&wrapAttr, wrapImpl);
    createQualifiedName((void*)&webkitgrammarAttr, webkitgrammarImpl);
    createQualifiedName((void*)&webkitspeechAttr, webkitspeechImpl);
}

} // HTML
} // WebCore
