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
#define XML_NAMES_HIDE_GLOBALS 1
#else
#define QNAME_DEFAULT_CONSTRUCTOR 1
#endif

#include "XMLNames.h"

#include "wtf/StaticConstructors.h"

namespace WebCore {
namespace XMLNames {

using namespace WebCore;

DEFINE_GLOBAL(AtomicString, xmlNamespaceURI)

// Attributes
DEFINE_GLOBAL(QualifiedName, baseAttr)
DEFINE_GLOBAL(QualifiedName, langAttr)
DEFINE_GLOBAL(QualifiedName, spaceAttr)

PassOwnPtr<const QualifiedName*[]> getXMLAttrs()
{
    OwnPtr<const QualifiedName*[]> attrs = adoptArrayPtr(new const QualifiedName*[XMLAttrsCount]);
    attrs[0] = reinterpret_cast<const WebCore::QualifiedName*>(&baseAttr);
    attrs[1] = reinterpret_cast<const WebCore::QualifiedName*>(&langAttr);
    attrs[2] = reinterpret_cast<const WebCore::QualifiedName*>(&spaceAttr);
    return attrs.release();
}

void init()
{
    // Use placement new to initialize the globals.
    AtomicString xmlNS("http://www.w3.org/XML/1998/namespace", AtomicString::ConstructFromLiteral);

    // Namespace
    new ((void*)&xmlNamespaceURI) AtomicString(xmlNS);
    StringImpl* baseImpl = StringImpl::createStatic("base", 4, 4376626);
    StringImpl* langImpl = StringImpl::createStatic("lang", 4, 3702417);
    StringImpl* spaceImpl = StringImpl::createStatic("space", 5, 531440);

    // Tags

    // Attrs
    createQualifiedName((void*)&baseAttr, baseImpl, xmlNS);
    createQualifiedName((void*)&langAttr, langImpl, xmlNS);
    createQualifiedName((void*)&spaceAttr, spaceImpl, xmlNS);
}

} // XML
} // WebCore
