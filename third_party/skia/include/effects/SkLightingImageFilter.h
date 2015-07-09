/*
 * Copyright 2012 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkLightingImageFilter_DEFINED
#define SkLightingImageFilter_DEFINED

#include "SkImageFilter.h"
#include "SkColor.h"

class SK_API SkPoint3 {
public:
    SkPoint3() {}
    SkPoint3(float x, float y, float z)
      : fX(x), fY(y), fZ(z) {}
    float dot(const SkPoint3& other) const {
        return SkScalarMul(fX, other.fX)
             + SkScalarMul(fY, other.fY)
             + SkScalarMul(fZ, other.fZ);
    }
    float maxComponent() const {
        return fX > fY ? (fX > fZ ? fX : fZ) : (fY > fZ ? fY : fZ);
    }
    void normalize() {
        // Small epsilon is added to prevent division by 0.
        float scale = SkScalarInvert(SkScalarSqrt(dot(*this)) + SK_ScalarNearlyZero);
        fX = SkScalarMul(fX, scale);
        fY = SkScalarMul(fY, scale);
        fZ = SkScalarMul(fZ, scale);
    }
    SkPoint3 operator*(float scalar) const {
        return SkPoint3(SkScalarMul(fX, scalar),
                        SkScalarMul(fY, scalar),
                        SkScalarMul(fZ, scalar));
    }
    SkPoint3 operator-(const SkPoint3& other) const {
        return SkPoint3(fX - other.fX, fY - other.fY, fZ - other.fZ);
    }
    bool operator==(const SkPoint3& other) const {
        return fX == other.fX && fY == other.fY && fZ == other.fZ;
    }
    float fX, fY, fZ;
};

class SkLight;

class SK_API SkLightingImageFilter : public SkImageFilter {
public:
    static SkImageFilter* CreateDistantLitDiffuse(const SkPoint3& direction,
        SkColor lightColor, float surfaceScale, float kd,
        SkImageFilter* input = NULL, const CropRect* cropRect = NULL);
    static SkImageFilter* CreatePointLitDiffuse(const SkPoint3& location,
        SkColor lightColor, float surfaceScale, float kd,
        SkImageFilter* input = NULL, const CropRect* cropRect = NULL);
    static SkImageFilter* CreateSpotLitDiffuse(const SkPoint3& location,
        const SkPoint3& target, float specularExponent, float cutoffAngle,
        SkColor lightColor, float surfaceScale, float kd,
        SkImageFilter* input = NULL, const CropRect* cropRect = NULL);
    static SkImageFilter* CreateDistantLitSpecular(const SkPoint3& direction,
        SkColor lightColor, float surfaceScale, float ks,
        float shininess, SkImageFilter* input = NULL, const CropRect* cropRect = NULL);
    static SkImageFilter* CreatePointLitSpecular(const SkPoint3& location,
        SkColor lightColor, float surfaceScale, float ks,
        float shininess, SkImageFilter* input = NULL, const CropRect* cropRect = NULL);
    static SkImageFilter* CreateSpotLitSpecular(const SkPoint3& location,
        const SkPoint3& target, float specularExponent, float cutoffAngle,
        SkColor lightColor, float surfaceScale, float ks,
        float shininess, SkImageFilter* input = NULL, const CropRect* cropRect = NULL);
    ~SkLightingImageFilter();

    SK_DECLARE_FLATTENABLE_REGISTRAR_GROUP()

protected:
    SkLightingImageFilter(SkLight* light,
                          float surfaceScale,
                          SkImageFilter* input,
                          const CropRect* cropRect = NULL);
    explicit SkLightingImageFilter(SkFlattenableReadBuffer& buffer);
    virtual void flatten(SkFlattenableWriteBuffer&) const SK_OVERRIDE;
    const SkLight* light() const { return fLight; }
    float surfaceScale() const { return fSurfaceScale; }

private:
    typedef SkImageFilter INHERITED;
    SkLight* fLight;
    float fSurfaceScale;
};

#endif
