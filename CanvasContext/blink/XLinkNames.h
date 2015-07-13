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

#ifndef XLinkNames_h
#define XLinkNames_h

#include "dom/QualifiedName.h"
#include "wtf/PassOwnPtr.h"

namespace WebCore {
namespace XLinkNames {

#ifndef X_LINK_NAMES_HIDE_GLOBALS
// Namespace
extern const WTF::AtomicString xlinkNamespaceURI;

// Tags

// Attributes
extern const WebCore::QualifiedName actuateAttr;
extern const WebCore::QualifiedName arcroleAttr;
extern const WebCore::QualifiedName hrefAttr;
extern const WebCore::QualifiedName roleAttr;
extern const WebCore::QualifiedName showAttr;
extern const WebCore::QualifiedName titleAttr;
extern const WebCore::QualifiedName typeAttr;

#endif // X_LINK_NAMES_HIDE_GLOBALS
const unsigned XLinkAttrsCount = 7;
PassOwnPtr<const QualifiedName*[]> getXLinkAttrs();

void init();

} // XLinkNames
} // WebCore

#endif
