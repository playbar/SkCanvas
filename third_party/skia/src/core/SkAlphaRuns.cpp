
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkAntiRun.h"
#include "SkUtils.h"

void SkAlphaRuns::reset(int width) {

#ifdef SK_DEBUG
    sk_memset16((uint16_t*)fRuns, (uint16_t)(-42), width);
#endif
    fRuns[0] = SkToS16(width);
    fRuns[width] = 0;
    fAlpha[0] = 0;

    SkDEBUGCODE(fWidth = width;)
}

