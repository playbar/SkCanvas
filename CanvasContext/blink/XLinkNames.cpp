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
#define X_LINK_NAMES_HIDE_GLOBALS 1
#else
#define QNAME_DEFAULT_CONSTRUCTOR 1
#endif

#include "XLinkNames.h"

#include "wtf/StaticConstructors.h"

namespace WebCore {
namespace XLinkNames {

using namespace WebCore;

DEFINE_GLOBAL(AtomicString, xlinkNamespaceURI)

// Attributes
DEFINE_GLOBAL(QualifiedName, actuateAttr)
DEFINE_GLOBAL(QualifiedName, arcroleAttr)
DEFINE_GLOBAL(QualifiedName, hrefAttr)
DEFINE_GLOBAL(QualifiedName, roleAttr)
DEFINE_GLOBAL(QualifiedName, showAttr)
DEFINE_GLOBAL(QualifiedName, titleAttr)
DEFINE_GLOBAL(QualifiedName, typeAttr)

PassOwnPtr<const QualifiedName*[]> getXLinkAttrs()
{
    OwnPtr<const QualifiedName*[]> attrs = adoptArrayPtr(new const QualifiedName*[XLinkAttrsCount]);
    attrs[0] = reinterpret_cast<const WebCore::QualifiedName*>(&actuateAttr);
    attrs[1] = reinterpret_cast<const WebCore::QualifiedName*>(&arcroleAttr);
    attrs[2] = reinterpret_cast<const WebCore::QualifiedName*>(&hrefAttr);
    attrs[3] = reinterpret_cast<const WebCore::QualifiedName*>(&roleAttr);
    attrs[4] = reinterpret_cast<const WebCore::QualifiedName*>(&showAttr);
    attrs[5] = reinterpret_cast<const WebCore::QualifiedName*>(&titleAttr);
    attrs[6] = reinterpret_cast<const WebCore::QualifiedName*>(&typeAttr);
    return attrs.release();
}

void init()
{
    // Use placement new to initialize the globals.
    AtomicString xlinkNS("http://www.w3.org/1999/xlink", AtomicString::ConstructFromLiteral);

    // Namespace
    new ((void*)&xlinkNamespaceURI) AtomicString(xlinkNS);
    StringImpl* actuateImpl = StringImpl::createStatic("actuate", 7, 5578769);
    StringImpl* arcroleImpl = StringImpl::createStatic("arcrole", 7, 11561565);
    StringImpl* hrefImpl = StringImpl::createStatic("href", 4, 5797448);
    StringImpl* roleImpl = StringImpl::createStatic("role", 4, 16084934);
    StringImpl* showImpl = StringImpl::createStatic("show", 4, 3191658);
    StringImpl* titleImpl = StringImpl::createStatic("title", 5, 2337488);
    StringImpl* typeImpl = StringImpl::createStatic("type", 4, 1916283);

    // Tags

    // Attrs
    createQualifiedName((void*)&actuateAttr, actuateImpl, xlinkNS);
    createQualifiedName((void*)&arcroleAttr, arcroleImpl, xlinkNS);
    createQualifiedName((void*)&hrefAttr, hrefImpl, xlinkNS);
    createQualifiedName((void*)&roleAttr, roleImpl, xlinkNS);
    createQualifiedName((void*)&showAttr, showImpl, xlinkNS);
    createQualifiedName((void*)&titleAttr, titleImpl, xlinkNS);
    createQualifiedName((void*)&typeAttr, typeImpl, xlinkNS);
}

} // XLink
} // WebCore
