/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkScalar_DEFINED
#define SkScalar_DEFINED

#include "SkFixed.h"
#include "SkFloatingPoint.h"

typedef float   SkScalar;
/** SK_Scalar1 is defined to be 1.0 represented as an SkScalar
*/
#define SK_Scalar1              (1.0f)
/** SK_Scalar1 is defined to be 1/2 represented as an SkScalar
*/
#define SK_ScalarHalf           (0.5f)
/** SK_ScalarInfinity is defined to be infinity as an SkScalar
*/
#define SK_ScalarInfinity       SK_FloatInfinity
/** SK_ScalarNegativeInfinity is defined to be negative infinity as an SkScalar
*/
#define SK_ScalarNegativeInfinity       SK_FloatNegativeInfinity
/** SK_ScalarMax is defined to be the largest value representable as an SkScalar
*/
#define SK_ScalarMax            (3.402823466e+38f)
/** SK_ScalarMin is defined to be the smallest value representable as an SkScalar
*/
#define SK_ScalarMin            (-SK_ScalarMax)
/** SK_ScalarNaN is defined to be 'Not a Number' as an SkScalar
*/
#define SK_ScalarNaN            SK_FloatNaN
/** SkScalarIsNaN(n) returns true if argument is not a number
*/
static inline bool SkScalarIsNaN(float x) { return x != x; }

/** Returns true if x is not NaN and not infinite */
static inline bool SkScalarIsFinite(float x) {
    // We rely on the following behavior of infinities and nans
    // 0 * finite --> 0
    // 0 * infinity --> NaN
    // 0 * NaN --> NaN
    float prod = x * 0;
    // At this point, prod will either be NaN or 0
    // Therefore we can return (prod == prod) or (0 == prod).
    return prod == prod;
}

/** SkIntToScalar(n) returns its integer argument as an SkScalar
*/
#define SkIntToScalar(n)        ((float)(n))
/** SkFixedToScalar(n) returns its SkFixed argument as an SkScalar
*/
#define SkFixedToScalar(x)      SkFixedToFloat(x)
/** SkScalarToFixed(n) returns its SkScalar argument as an SkFixed
*/
#define SkScalarToFixed(x)      SkFloatToFixed(x)

#define SkScalarToFloat(n)      (n)
#define SkFloatToScalar(n)      (n)
#define SkScalarToDouble(n)      (double)(n)
#define SkDoubleToScalar(n)      (float)(n)

/** SkScalarFraction(x) returns the signed fractional part of the argument
*/
#define SkScalarFraction(x)     sk_float_mod(x, 1.0f)

#define SkScalarFloorToScalar(x)    sk_float_floor(x)
#define SkScalarCeilToScalar(x)     sk_float_ceil(x)
#define SkScalarRoundToScalar(x)    sk_float_floor((x) + 0.5f)

#define SkScalarFloorToInt(x)       sk_float_floor2int(x)
#define SkScalarCeilToInt(x)        sk_float_ceil2int(x)
#define SkScalarRoundToInt(x)       sk_float_round2int(x)
#define SkScalarTruncToInt(x)       static_cast<int>(x)

/** Returns the absolute value of the specified SkScalar
*/
#define SkScalarAbs(x)          sk_float_abs(x)
/** Return x with the sign of y
 */
#define SkScalarCopySign(x, y)  sk_float_copysign(x, y)
/** Returns the value pinned between 0 and max inclusive
*/
inline float SkScalarClampMax(float x, float max) {
    return x < 0 ? 0 : x > max ? max : x;
}
/** Returns the value pinned between min and max inclusive
*/
inline float SkScalarPin(float x, float min, float max) {
    return x < min ? min : x > max ? max : x;
}
/** Returns the specified SkScalar squared (x*x)
*/
inline float SkScalarSquare(float x) { return x * x; }
/** Returns the product of two SkScalars
*/
#define SkScalarMul(a, b)       ((float)(a) * (b))
/** Returns the product of two SkScalars plus a third SkScalar
*/
#define SkScalarMulAdd(a, b, c) ((float)(a) * (b) + (c))
/** Returns the quotient of two SkScalars (a/b)
*/
#define SkScalarDiv(a, b)       ((float)(a) / (b))
/** Returns the mod of two SkScalars (a mod b)
*/
#define SkScalarMod(x,y)        sk_float_mod(x,y)
/** Returns the product of the first two arguments, divided by the third argument
*/
#define SkScalarMulDiv(a, b, c) ((float)(a) * (b) / (c))
/** Returns the multiplicative inverse of the SkScalar (1/x)
*/
#define SkScalarInvert(x)       (SK_Scalar1 / (x))
#define SkScalarFastInvert(x)   (SK_Scalar1 / (x))
/** Returns the square root of the SkScalar
*/
#define SkScalarSqrt(x)         sk_float_sqrt(x)
/** Returns b to the e
*/
#define SkScalarPow(b, e)       sk_float_pow(b, e)
/** Returns the average of two SkScalars (a+b)/2
*/
#define SkScalarAve(a, b)       (((a) + (b)) * 0.5f)
/** Returns one half of the specified SkScalar
*/
#define SkScalarHalf(a)         ((a) * 0.5f)

#define SK_ScalarSqrt2          1.41421356f
#define SK_ScalarPI             3.14159265f
#define SK_ScalarTanPIOver8     0.414213562f
#define SK_ScalarRoot2Over2     0.707106781f

#define SkDegreesToRadians(degrees) ((degrees) * (SK_ScalarPI / 180))
float SkScalarSinCos(float radians, float* cosValue);
#define SkScalarSin(radians)    (float)sk_float_sin(radians)
#define SkScalarCos(radians)    (float)sk_float_cos(radians)
#define SkScalarTan(radians)    (float)sk_float_tan(radians)
#define SkScalarASin(val)   (float)sk_float_asin(val)
#define SkScalarACos(val)   (float)sk_float_acos(val)
#define SkScalarATan2(y, x) (float)sk_float_atan2(y,x)
#define SkScalarExp(x)  (float)sk_float_exp(x)
#define SkScalarLog(x)  (float)sk_float_log(x)

inline float SkMaxScalar(float a, float b) { return a > b ? a : b; }
inline float SkMinScalar(float a, float b) { return a < b ? a : b; }

static inline bool SkScalarIsInt(float x) {
    return x == (float)(int)x;
}

static inline int SkScalarSignAsInt(float x) {
    return x < 0 ? -1 : (x > 0);
}

// Scalar result version of above
static inline float SkScalarSignAsScalar(float x) {
    return x < 0 ? -SK_Scalar1 : ((x > 0) ? SK_Scalar1 : 0);
}

#define SK_ScalarNearlyZero         (SK_Scalar1 / (1 << 12))

static inline bool SkScalarNearlyZero(float x,
                                    float tolerance = SK_ScalarNearlyZero) {
    return SkScalarAbs(x) <= tolerance;
}

static inline bool SkScalarNearlyEqual(float x, float y,
                                     float tolerance = SK_ScalarNearlyZero) {
    return SkScalarAbs(x-y) <= tolerance;
}

static inline float SkScalarInterp(float A, float B, float t) {
    return A + SkScalarMul(B - A, t);
}

float SkScalarInterpFunc(float searchKey, const float keys[],
                            const float values[], int length);

static inline bool SkScalarsEqual(const float a[], const float b[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

#endif
