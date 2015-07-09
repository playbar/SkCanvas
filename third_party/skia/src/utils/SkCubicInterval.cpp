
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkCubicInterval.h"

static float eval_cubic(float c1, float c2, float c3,
                           float t) {
    return SkScalarMul(SkScalarMul(SkScalarMul(c3, t) + c2, t) + c1, t);
}

static float find_cubic_t(float c1, float c2, float c3,
                             float targetX) {
    float minT = 0;
    float maxT = SK_Scalar1;
    float t;

    for (;;) {
        t = SkScalarAve(minT, maxT);
        float x = eval_cubic(c1, c2, c3, t);
        if (SkScalarNearlyZero(x - targetX)) {
            break;
        }
        // subdivide the range and try again
        if (x < targetX) {
            minT = t;
        } else {
            maxT = t;
        }
    }
    return t;
}

/*
    a(1-t)^3 + 3bt(1-t)^2 + 3ct^2(1-t) + dt^3
    a: [0, 0]
    d: [1, 1]

    3bt - 6bt^2 + 3bt^3 + 3ct^2 - 3ct^3 + t^3
    C1 = t^1: 3b
    C2 = t^2: 3c - 6b
    C3 = t^3: 3b - 3c + 1

    ((C3*t + C2)*t + C1)*t
 */
float SkEvalCubicInterval(float x1, float y1,
                             float x2, float y2,
                             float unitX) {
    x1 = SkScalarPin(x1, 0, SK_Scalar1);
    x2 = SkScalarPin(x2, 0, SK_Scalar1);
    unitX = SkScalarPin(unitX, 0, SK_Scalar1);

    // First compute our coefficients in X
    x1 *= 3;
    x2 *= 3;

    // now search for t given unitX
    float t = find_cubic_t(x1, x2 - 2*x1, x1 - x2 + SK_Scalar1, unitX);

    // now evaluate the cubic in Y
    y1 *= 3;
    y2 *= 3;
    return eval_cubic(y1, y2 - 2*y1, y1 - y2 + SK_Scalar1, t);
}
