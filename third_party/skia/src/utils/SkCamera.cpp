
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkCamera.h"

static float SkScalarDotDiv(int count, const float a[], int step_a,
                               const float b[], int step_b,
                               float denom) {
    float prod = 0;
    for (int i = 0; i < count; i++) {
        prod += a[0] * b[0];
        a += step_a;
        b += step_b;
    }
    return prod / denom;
}

static float SkScalarDot(int count, const float a[], int step_a,
                                       const float b[], int step_b) {
    float prod = 0;
    for (int i = 0; i < count; i++) {
        prod += a[0] * b[0];
        a += step_a;
        b += step_b;
    }
    return prod;
}

///////////////////////////////////////////////////////////////////////////////

SkUnitScalar SkPoint3D::normalize(SkUnit3D* unit) const {
    float mag = sk_float_sqrt(fX*fX + fY*fY + fZ*fZ);
    if (mag) {
        float scale = 1.0f / mag;
        unit->fX = fX * scale;
        unit->fY = fY * scale;
        unit->fZ = fZ * scale;
    } else {
        unit->fX = unit->fY = unit->fZ = 0;
    }
    return mag;
}

SkUnitScalar SkUnit3D::Dot(const SkUnit3D& a, const SkUnit3D& b) {
    return  SkUnitScalarMul(a.fX, b.fX) +
            SkUnitScalarMul(a.fY, b.fY) +
            SkUnitScalarMul(a.fZ, b.fZ);
}

void SkUnit3D::Cross(const SkUnit3D& a, const SkUnit3D& b, SkUnit3D* cross) {

    // use x,y,z, in case &a == cross or &b == cross

    float x = SkUnitScalarMul(a.fY, b.fZ) - SkUnitScalarMul(a.fZ, b.fY);
    float y = SkUnitScalarMul(a.fZ, b.fX) - SkUnitScalarMul(a.fX, b.fY);
    float z = SkUnitScalarMul(a.fX, b.fY) - SkUnitScalarMul(a.fY, b.fX);

    cross->set(x, y, z);
}

///////////////////////////////////////////////////////////////////////////////

SkPatch3D::SkPatch3D() {
    this->reset();
}

void SkPatch3D::reset() {
    fOrigin.set(0, 0, 0);
    fU.set(SK_Scalar1, 0, 0);
    fV.set(0, -SK_Scalar1, 0);
}

void SkPatch3D::transform(const SkMatrix3D& m, SkPatch3D* dst) const {
    if (dst == NULL) {
        dst = (SkPatch3D*)this;
    }
    m.mapVector(fU, &dst->fU);
    m.mapVector(fV, &dst->fV);
    m.mapPoint(fOrigin, &dst->fOrigin);
}

float SkPatch3D::dotWith(float dx, float dy, float dz) const {
    float cx = SkScalarMul(fU.fY, fV.fZ) - SkScalarMul(fU.fZ, fV.fY);
    float cy = SkScalarMul(fU.fZ, fV.fX) - SkScalarMul(fU.fX, fV.fY);
    float cz = SkScalarMul(fU.fX, fV.fY) - SkScalarMul(fU.fY, fV.fX);

    return SkScalarMul(cx, dx) + SkScalarMul(cy, dy) + SkScalarMul(cz, dz);
}

///////////////////////////////////////////////////////////////////////////////

void SkMatrix3D::reset() {
    memset(fMat, 0, sizeof(fMat));
    fMat[0][0] = fMat[1][1] = fMat[2][2] = SK_Scalar1;
}

void SkMatrix3D::setTranslate(float x, float y, float z) {
    memset(fMat, 0, sizeof(fMat));
    fMat[0][0] = x;
    fMat[1][1] = y;
    fMat[2][2] = z;
}

void SkMatrix3D::setRotateX(float degX) {
    float    s, c;

    s = SkScalarSinCos(SkDegreesToRadians(degX), &c);
    this->setRow(0, SK_Scalar1, 0, 0);
    this->setRow(1, 0, c, -s);
    this->setRow(2, 0, s, c);
}

void SkMatrix3D::setRotateY(float degY) {
    float    s, c;

    s = SkScalarSinCos(SkDegreesToRadians(degY), &c);
    this->setRow(0, c, 0, -s);
    this->setRow(1, 0, SK_Scalar1, 0);
    this->setRow(2, s, 0, c);
}

void SkMatrix3D::setRotateZ(float degZ) {
    float    s, c;

    s = SkScalarSinCos(SkDegreesToRadians(degZ), &c);
    this->setRow(0, c, -s, 0);
    this->setRow(1, s, c, 0);
    this->setRow(2, 0, 0, SK_Scalar1);
}

void SkMatrix3D::preTranslate(float x, float y, float z) {
    float col[3] = { x, y, z};

    for (int i = 0; i < 3; i++) {
        fMat[i][3] += SkScalarDot(3, &fMat[i][0], 1, col, 1);
    }
}

void SkMatrix3D::preRotateX(float degX) {
    SkMatrix3D m;
    m.setRotateX(degX);
    this->setConcat(*this, m);
}

void SkMatrix3D::preRotateY(float degY) {
    SkMatrix3D m;
    m.setRotateY(degY);
    this->setConcat(*this, m);
}

void SkMatrix3D::preRotateZ(float degZ) {
    SkMatrix3D m;
    m.setRotateZ(degZ);
    this->setConcat(*this, m);
}

void SkMatrix3D::setConcat(const SkMatrix3D& a, const SkMatrix3D& b) {
    SkMatrix3D  tmp;
    SkMatrix3D* c = this;

    if (this == &a || this == &b) {
        c = &tmp;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c->fMat[i][j] = SkScalarDot(3, &a.fMat[i][0], 1, &b.fMat[0][j], 4);
        }
        c->fMat[i][3] = SkScalarDot(3, &a.fMat[i][0], 1,
                                    &b.fMat[0][3], 4) + a.fMat[i][3];
    }

    if (c == &tmp) {
        *this = tmp;
    }
}

void SkMatrix3D::mapPoint(const SkPoint3D& src, SkPoint3D* dst) const {
    float x = SkScalarDot(3, &fMat[0][0], 1, &src.fX, 1) + fMat[0][3];
    float y = SkScalarDot(3, &fMat[1][0], 1, &src.fX, 1) + fMat[1][3];
    float z = SkScalarDot(3, &fMat[2][0], 1, &src.fX, 1) + fMat[2][3];
    dst->set(x, y, z);
}

void SkMatrix3D::mapVector(const SkVector3D& src, SkVector3D* dst) const {
    float x = SkScalarDot(3, &fMat[0][0], 1, &src.fX, 1);
    float y = SkScalarDot(3, &fMat[1][0], 1, &src.fX, 1);
    float z = SkScalarDot(3, &fMat[2][0], 1, &src.fX, 1);
    dst->set(x, y, z);
}

///////////////////////////////////////////////////////////////////////////////

SkCamera3D::SkCamera3D() {
    this->reset();
}

void SkCamera3D::reset() {
    fLocation.set(0, 0, -SkIntToScalar(576));   // 8 inches backward
    fAxis.set(0, 0, SK_Scalar1);                // forward
    fZenith.set(0, -SK_Scalar1, 0);             // up

    fObserver.set(0, 0, fLocation.fZ);

    fNeedToUpdate = true;
}

void SkCamera3D::update() {
    fNeedToUpdate = true;
}

void SkCamera3D::doUpdate() const {
    SkUnit3D    axis, zenith, cross;

    fAxis.normalize(&axis);

    {
        float dot = SkUnit3D::Dot(*SkTCast<const SkUnit3D*>(&fZenith), axis);

        zenith.fX = fZenith.fX - SkUnitScalarMul(dot, axis.fX);
        zenith.fY = fZenith.fY - SkUnitScalarMul(dot, axis.fY);
        zenith.fZ = fZenith.fZ - SkUnitScalarMul(dot, axis.fZ);

        SkTCast<SkPoint3D*>(&zenith)->normalize(&zenith);
    }

    SkUnit3D::Cross(axis, zenith, &cross);

    {
        SkMatrix* orien = &fOrientation;
        float x = fObserver.fX;
        float y = fObserver.fY;
        float z = fObserver.fZ;

        orien->set(SkMatrix::kMScaleX, SkUnitScalarMul(x, axis.fX) - SkUnitScalarMul(z, cross.fX));
        orien->set(SkMatrix::kMSkewX,  SkUnitScalarMul(x, axis.fY) - SkUnitScalarMul(z, cross.fY));
        orien->set(SkMatrix::kMTransX, SkUnitScalarMul(x, axis.fZ) - SkUnitScalarMul(z, cross.fZ));
        orien->set(SkMatrix::kMSkewY,  SkUnitScalarMul(y, axis.fX) - SkUnitScalarMul(z, zenith.fX));
        orien->set(SkMatrix::kMScaleY, SkUnitScalarMul(y, axis.fY) - SkUnitScalarMul(z, zenith.fY));
        orien->set(SkMatrix::kMTransY, SkUnitScalarMul(y, axis.fZ) - SkUnitScalarMul(z, zenith.fZ));
        orien->set(SkMatrix::kMPersp0, axis.fX);
        orien->set(SkMatrix::kMPersp1, axis.fY);
        orien->set(SkMatrix::kMPersp2, axis.fZ);
    }
}

void SkCamera3D::patchToMatrix(const SkPatch3D& quilt, SkMatrix* matrix) const {
    if (fNeedToUpdate) {
        this->doUpdate();
        fNeedToUpdate = false;
    }

    const float* mapPtr = (const float*)(const void*)&fOrientation;
    const float* patchPtr;
    SkPoint3D       diff;
    float        dot;

    diff.fX = quilt.fOrigin.fX - fLocation.fX;
    diff.fY = quilt.fOrigin.fY - fLocation.fY;
    diff.fZ = quilt.fOrigin.fZ - fLocation.fZ;

    dot = SkUnit3D::Dot(*SkTCast<const SkUnit3D*>(&diff),
                        *SkTCast<const SkUnit3D*>(SkTCast<const float*>(&fOrientation) + 6));

    patchPtr = (const float*)&quilt;
    matrix->set(SkMatrix::kMScaleX, SkScalarDotDiv(3, patchPtr, 1, mapPtr, 1, dot));
    matrix->set(SkMatrix::kMSkewY,  SkScalarDotDiv(3, patchPtr, 1, mapPtr+3, 1, dot));
    matrix->set(SkMatrix::kMPersp0, SkScalarDotDiv(3, patchPtr, 1, mapPtr+6, 1, dot));

    patchPtr += 3;
    matrix->set(SkMatrix::kMSkewX,  SkScalarDotDiv(3, patchPtr, 1, mapPtr, 1, dot));
    matrix->set(SkMatrix::kMScaleY, SkScalarDotDiv(3, patchPtr, 1, mapPtr+3, 1, dot));
    matrix->set(SkMatrix::kMPersp1, SkScalarDotDiv(3, patchPtr, 1, mapPtr+6, 1, dot));

    patchPtr = (const float*)(const void*)&diff;
    matrix->set(SkMatrix::kMTransX, SkScalarDotDiv(3, patchPtr, 1, mapPtr, 1, dot));
    matrix->set(SkMatrix::kMTransY, SkScalarDotDiv(3, patchPtr, 1, mapPtr+3, 1, dot));
    matrix->set(SkMatrix::kMPersp2, SK_UnitScalar1);
}

///////////////////////////////////////////////////////////////////////////////

Sk3DView::Sk3DView() {
    fInitialRec.fMatrix.reset();
    fRec = &fInitialRec;
}

Sk3DView::~Sk3DView() {
    Rec* rec = fRec;
    while (rec != &fInitialRec) {
        Rec* next = rec->fNext;
        SkDELETE(rec);
        rec = next;
    }
}

void Sk3DView::save() {
    Rec* rec = SkNEW(Rec);
    rec->fNext = fRec;
    rec->fMatrix = fRec->fMatrix;
    fRec = rec;
}

void Sk3DView::restore() {
    Rec* next = fRec->fNext;
    SkDELETE(fRec);
    fRec = next;
}

#ifdef SK_BUILD_FOR_ANDROID
void Sk3DView::setCameraLocation(float x, float y, float z) {
    // the camera location is passed in inches, set in pt
    float lz = z * 72.0f;
    fCamera.fLocation.set(x * 72.0f, y * 72.0f, lz);
    fCamera.fObserver.set(0, 0, lz);
    fCamera.update();

}

float Sk3DView::getCameraLocationX() {
    return fCamera.fLocation.fX / 72.0f;
}

float Sk3DView::getCameraLocationY() {
    return fCamera.fLocation.fY / 72.0f;
}

float Sk3DView::getCameraLocationZ() {
    return fCamera.fLocation.fZ / 72.0f;
}
#endif

void Sk3DView::translate(float x, float y, float z) {
    fRec->fMatrix.preTranslate(x, y, z);
}

void Sk3DView::rotateX(float deg) {
    fRec->fMatrix.preRotateX(deg);
}

void Sk3DView::rotateY(float deg) {
    fRec->fMatrix.preRotateY(deg);
}

void Sk3DView::rotateZ(float deg) {
    fRec->fMatrix.preRotateZ(deg);
}

float Sk3DView::dotWithNormal(float x, float y, float z) const {
    SkPatch3D   patch;
    patch.transform(fRec->fMatrix);
    return patch.dotWith(x, y, z);
}

void Sk3DView::getMatrix(SkMatrix* matrix) const {
    if (matrix != NULL) {
        SkPatch3D   patch;
        patch.transform(fRec->fMatrix);
        fCamera.patchToMatrix(patch, matrix);
    }
}

#include "SkCanvas.h"

void Sk3DView::applyToCanvas(SkCanvas* canvas) const {
    SkMatrix    matrix;

    this->getMatrix(&matrix);
    canvas->concat(matrix);
}
