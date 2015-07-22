/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkInstCnt_DEFINED
#define SkInstCnt_DEFINED


#include "SkTypes.h"

#define SK_DECLARE_INST_COUNT(className) static void AddInstChild() { INHERITED::AddInstChild(); }
#define SK_DECLARE_INST_COUNT_ROOT(className) static void AddInstChild() { }

// Following are deprecated. They are defined only for backwards API compatibility.
#define SK_DECLARE_INST_COUNT_TEMPLATE(className) SK_DECLARE_INST_COUNT(className)
#define SK_DEFINE_INST_COUNT(className)
#define SK_DEFINE_INST_COUNT_TEMPLATE(templateInfo, className)

#endif // SkInstCnt_DEFINED
