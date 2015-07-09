
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkCubicInterval_DEFINED
#define SkCubicInterval_DEFINED

#include "SkPoint.h"

float SkEvalCubicInterval(float x1, float y1,
                             float x2, float y2,
                             float unitX);

static inline float SkEvalCubicInterval(const SkPoint pts[2], float x) {
    return SkEvalCubicInterval(pts[0].fX, pts[0].fY,
                               pts[1].fX, pts[1].fY, x);
}

#endif
