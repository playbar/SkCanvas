/*
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2008 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"
#include "css/CSSImageValue.h"

//#include "FetchInitiatorTypeNames.h"
#include "css/CSSMarkup.h"
//#include "style/StyleFetchedImage.h"
#include "style/StylePendingImage.h"
#include "css/CSSPrimitiveValue.h"
//#include "url/KURL.h"

namespace WebCore {

CSSImageValue::CSSImageValue(const String& rawValue, StyleImage* image)
    : CSSValue(ImageClass)
    , m_relativeURL(rawValue)
    , m_image(image)
    , m_accessedImage(image)
{
}

CSSImageValue::~CSSImageValue()
{
}

StyleImage* CSSImageValue::cachedOrPendingImage()
{
    if (!m_image)
        m_image = StylePendingImage::create(this);

    return m_image.get();
}

//StyleFetchedImage* CSSImageValue::cachedImage(ResourceFetcher* fetcher, const ResourceLoaderOptions& options)
//{
//    ASSERT(fetcher);
//
//    if (!m_accessedImage) {
//        m_accessedImage = true;
//
//        FetchRequest request(ResourceRequest(m_absoluteURL), m_initiatorName.isEmpty() ? FetchInitiatorTypeNames::css : m_initiatorName, options);
//
//        if (options.corsEnabled == IsCORSEnabled)
//            request.setCrossOriginAccessControl(fetcher->document()->securityOrigin(), options.allowCredentials);
//
//        if (ResourcePtr<ImageResource> cachedImage = fetcher->fetchImage(request))
//            m_image = StyleFetchedImage::create(cachedImage.get());
//    }
//
//    return (m_image && m_image->isImageResource()) ? toStyleFetchedImage(m_image) : 0;
//}

bool CSSImageValue::hasFailedOrCanceledSubresources() const
{
	ASSERT(false);
 //   if (!m_image || !m_image->isImageResource())
 //       return false;
	//if (uint32_t* cachedResource = toStyleFetchedImage(m_image)->cachedImage())
 //       return cachedResource->loadFailedOrCanceled();
    return true;
}

bool CSSImageValue::equals(const CSSImageValue& other) const
{
    return m_absoluteURL == other.m_absoluteURL;
}

String CSSImageValue::customCSSText() const
{
    return "url(" + quoteCSSURLIfNeeded(m_absoluteURL) + ")";
}

PassRefPtr<CSSValue> CSSImageValue::cloneForCSSOM() const
{
    // NOTE: We expose CSSImageValues as URI primitive values in CSSOM to maintain old behavior.
    RefPtr<CSSPrimitiveValue> uriValue = CSSPrimitiveValue::create(m_absoluteURL, CSSPrimitiveValue::CSS_URI);
    uriValue->setCSSOMSafe();
    return uriValue.release();
}

bool CSSImageValue::knownToBeOpaque(const RenderObject* renderer) const
{
    return m_image ? m_image->knownToBeOpaque(renderer) : false;
}

//void CSSImageValue::traceAfterDispatch(Visitor* visitor)
//{
//    CSSValue::traceAfterDispatch(visitor);
//}

//void CSSImageValue::reResolveURL(const Document& document)
//{
//    KURL url = document.completeURL(m_relativeURL);
//    if (url == m_absoluteURL)
//        return;
//    m_absoluteURL = url.string();
//    m_accessedImage = false;
//    m_image.clear();
//}

} // namespace WebCore
