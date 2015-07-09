/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

//  Inspired by Rob Johnson's most excellent QuickDraw GX sample code

#ifndef SkCamera_DEFINED
#define SkCamera_DEFINED

#include "SkMatrix.h"

class SkCanvas;

typedef float   SkUnitScalar;
#define SK_UnitScalar1          SK_Scalar1
#define SkUnitScalarMul(a, b)   SkScalarMul(a, b)
#define SkUnitScalarDiv(a, b)   SkScalarDiv(a, b)

struct SkUnit3D {
    SkUnitScalar    fX, fY, fZ;

    void set(SkUnitScalar x, SkUnitScalar y, SkUnitScalar z)
    {
        fX = x; fY = y; fZ = z;
    }
    static SkUnitScalar Dot(const SkUnit3D&, const SkUnit3D&);
    static void Cross(const SkUnit3D&, const SkUnit3D&, SkUnit3D* cross);
};

struct SkPoint3D {
    float    fX, fY, fZ;

    void set(float x, float y, float z)
    {
        fX = x; fY = y; fZ = z;
    }
    float    normalize(SkUnit3D*) const;
};
typedef SkPoint3D SkVector3D;

struct SkMatrix3D {
    float    fMat[3][4];

    void reset();

    void setRow(int row, float a, float b, float c, float d = 0)
    {
        fMat[row][0] = a;
        fMat[row][1] = b;
        fMat[row][2] = c;
        fMat[row][3] = d;
    }

    void setRotateX(float deg);
    void setRotateY(float deg);
    void setRotateZ(float deg);
    void setTranslate(float x, float y, float z);

    void preRotateX(float deg);
    void preRotateY(float deg);
    void preRotateZ(float deg);
    void preTranslate(float x, float y, float z);

    void setConcat(const SkMatrix3D& a, const SkMatrix3D& b);
    void mapPoint(const SkPoint3D& src, SkPoint3D* dst) const;
    void mapVector(const SkVector3D& src, SkVector3D* dst) const;

    void mapPoint(SkPoint3D* v) const
    {
        this->mapPoint(*v, v);
    }
    void mapVector(SkVector3D* v) const
    {
        this->mapVector(*v, v);
    }
};

class SkPatch3D {
public:
    SkPatch3D();

    void    reset();
    void    transform(const SkMatrix3D&, SkPatch3D* dst = NULL) const;

    // dot a unit vector with the patch's normal
    float dotWith(float dx, float dy, float dz) const;
    float dotWith(const SkVector3D& v) const
    {
        return this->dotWith(v.fX, v.fY, v.fZ);
    }

    // deprecated, but still here for animator (for now)
    void rotate(float x, float y, float z) {}
    void rotateDegrees(float x, float y, float z) {}

private:
public: // make public for SkDraw3D for now
    SkVector3D  fU, fV;
    SkPoint3D   fOrigin;

    friend class SkCamera3D;
};

class SkCamera3D {
public:
    SkCamera3D();

    void reset();
    void update();
    void patchToMatrix(const SkPatch3D&, SkMatrix* matrix) const;

    SkPoint3D   fLocation;
    SkPoint3D   fAxis;
    SkPoint3D   fZenith;
    SkPoint3D   fObserver;

private:
    mutable SkMatrix    fOrientation;
    mutable bool        fNeedToUpdate;

    void doUpdate() const;
};

class Sk3DView : SkNoncopyable {
public:
    Sk3DView();
    ~Sk3DView();

    void save();
    void restore();

    void translate(float x, float y, float z);
    void rotateX(float deg);
    void rotateY(float deg);
    void rotateZ(float deg);

#ifdef SK_BUILD_FOR_ANDROID
    void setCameraLocation(float x, float y, float z);
    float getCameraLocationX();
    float getCameraLocationY();
    float getCameraLocationZ();
#endif

    void getMatrix(SkMatrix*) const;
    void applyToCanvas(SkCanvas*) const;

    float dotWithNormal(float dx, float dy, float dz) const;

private:
    struct Rec {
        Rec*        fNext;
        SkMatrix3D  fMatrix;
    };
    Rec*        fRec;
    Rec         fInitialRec;
    SkCamera3D  fCamera;
};

#endif
