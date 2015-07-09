/*
 * Copyright 2007 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkColorMatrix_DEFINED
#define SkColorMatrix_DEFINED

#include "SkScalar.h"

class SK_API SkColorMatrix {
public:
    float    fMat[20];

    void setIdentity();
    void setScale(float rScale, float gScale, float bScale,
                  float aScale = SK_Scalar1);
    void preScale(float rScale, float gScale, float bScale,
                  float aScale = SK_Scalar1);
    void postScale(float rScale, float gScale, float bScale,
                   float aScale = SK_Scalar1);

    enum Axis {
        kR_Axis = 0,
        kG_Axis = 1,
        kB_Axis = 2
    };
    void setRotate(Axis, float degrees);
    void setSinCos(Axis, float sine, float cosine);
    void preRotate(Axis, float degrees);
    void postRotate(Axis, float degrees);

    void setConcat(const SkColorMatrix& a, const SkColorMatrix& b);
    void preConcat(const SkColorMatrix& mat) { this->setConcat(*this, mat); }
    void postConcat(const SkColorMatrix& mat) { this->setConcat(mat, *this); }

    void setSaturation(float sat);
    void setRGB2YUV();
    void setYUV2RGB();

    bool operator==(const SkColorMatrix& other) const {
        return 0 == memcmp(fMat, other.fMat, sizeof(fMat));
    }

    bool operator!=(const SkColorMatrix& other) const { return !((*this) == other); }
};

#endif
