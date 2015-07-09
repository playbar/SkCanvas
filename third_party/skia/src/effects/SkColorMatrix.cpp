
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkColorMatrix.h"
#include "SkFlattenableBuffers.h"

#define kRScale     0
#define kGScale     6
#define kBScale     12
#define kAScale     18

void SkColorMatrix::setIdentity() {
    memset(fMat, 0, sizeof(fMat));
    fMat[kRScale] = fMat[kGScale] = fMat[kBScale] = fMat[kAScale] = SK_Scalar1;
}

void SkColorMatrix::setScale(float rScale, float gScale, float bScale,
                             float aScale) {
    memset(fMat, 0, sizeof(fMat));
    fMat[kRScale] = rScale;
    fMat[kGScale] = gScale;
    fMat[kBScale] = bScale;
    fMat[kAScale] = aScale;
}

///////////////////////////////////////////////////////////////////////////////

void SkColorMatrix::setRotate(Axis axis, float degrees) {
    float S, C;

    S = SkScalarSinCos(SkDegreesToRadians(degrees), &C);

    this->setSinCos(axis, S, C);
}

void SkColorMatrix::setSinCos(Axis axis, float sine, float cosine) {

    static const uint8_t gRotateIndex[] = {
        6, 7, 11, 12,
        0, 10, 2, 12,
        0, 1,  5,  6,
    };
    const uint8_t* index = gRotateIndex + axis * 4;

    this->setIdentity();
    fMat[index[0]] = cosine;
    fMat[index[1]] = sine;
    fMat[index[2]] = -sine;
    fMat[index[3]] = cosine;
}

void SkColorMatrix::preRotate(Axis axis, float degrees) {
    SkColorMatrix tmp;
    tmp.setRotate(axis, degrees);
    this->preConcat(tmp);
}

void SkColorMatrix::postRotate(Axis axis, float degrees) {
    SkColorMatrix tmp;
    tmp.setRotate(axis, degrees);
    this->postConcat(tmp);
}

///////////////////////////////////////////////////////////////////////////////

void SkColorMatrix::setConcat(const SkColorMatrix& matA,
                              const SkColorMatrix& matB) {
    float    tmp[20];
    float*   result = fMat;

    if (&matA == this || &matB == this) {
        result = tmp;
    }

    const float* a = matA.fMat;
    const float* b = matB.fMat;

    int index = 0;
    for (int j = 0; j < 20; j += 5) {
        for (int i = 0; i < 4; i++) {
            result[index++] =   SkScalarMul(a[j + 0], b[i + 0]) +
                                SkScalarMul(a[j + 1], b[i + 5]) +
                                SkScalarMul(a[j + 2], b[i + 10]) +
                                SkScalarMul(a[j + 3], b[i + 15]);
        }
        result[index++] =   SkScalarMul(a[j + 0], b[4]) +
                            SkScalarMul(a[j + 1], b[9]) +
                            SkScalarMul(a[j + 2], b[14]) +
                            SkScalarMul(a[j + 3], b[19]) +
                            a[j + 4];
    }

    if (fMat != result) {
        memcpy(fMat, result, sizeof(fMat));
    }
}

///////////////////////////////////////////////////////////////////////////////

static void setrow(float row[], float r, float g, float b) {
    row[0] = r;
    row[1] = g;
    row[2] = b;
}

static const float kHueR = 0.213f;
static const float kHueG = 0.715f;
static const float kHueB = 0.072f;

void SkColorMatrix::setSaturation(float sat) {
    memset(fMat, 0, sizeof(fMat));

    const float R = SkScalarMul(kHueR, SK_Scalar1 - sat);
    const float G = SkScalarMul(kHueG, SK_Scalar1 - sat);
    const float B = SkScalarMul(kHueB, SK_Scalar1 - sat);

    setrow(fMat +  0, R + sat, G, B);
    setrow(fMat +  5, R, G + sat, B);
    setrow(fMat + 10, R, G, B + sat);
    fMat[18] = SK_Scalar1;
}

static const float kR2Y = 0.299f;
static const float kG2Y = 0.587f;
static const float kB2Y = 0.114f;

static const float kR2U = -0.16874f;
static const float kG2U = -0.33126f;
static const float kB2U = 0.5f;

static const float kR2V = 0.5f;
static const float kG2V = -0.41869f;
static const float kB2V = -0.08131f;

void SkColorMatrix::setRGB2YUV() {
    memset(fMat, 0, sizeof(fMat));

    setrow(fMat +  0, kR2Y, kG2Y, kB2Y);
    setrow(fMat +  5, kR2U, kG2U, kB2U);
    setrow(fMat + 10, kR2V, kG2V, kB2V);
    fMat[18] = SK_Scalar1;
}

static const float kV2R = 1.402f;
static const float kU2G = -0.34414f;
static const float kV2G = -0.71414f;
static const float kU2B = 1.772f;

void SkColorMatrix::setYUV2RGB() {
    memset(fMat, 0, sizeof(fMat));

    setrow(fMat +  0, SK_Scalar1, 0, kV2R);
    setrow(fMat +  5, SK_Scalar1, kU2G, kV2G);
    setrow(fMat + 10, SK_Scalar1, kU2B, 0);
    fMat[18] = SK_Scalar1;
}
