
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

 #ifndef SkTwoPointConicalGradient_DEFINED
 #define SkTwoPointConicalGradient_DEFINED

#include "SkGradientShaderPriv.h"

struct TwoPtRadial {
    enum {
        kDontDrawT  = 0x80000000
    };

    float   fCenterX, fCenterY;
    float   fDCenterX, fDCenterY;
    float   fRadius;
    float   fDRadius;
    float   fA;
    float   fRadius2;
    float   fRDR;

    void init(const SkPoint& center0, float rad0,
              const SkPoint& center1, float rad1);

    // used by setup and nextT
    float   fRelX, fRelY, fIncX, fIncY;
    float   fB, fDB;

    void setup(float fx, float fy, float dfx, float dfy);
    SkFixed nextT();

    static bool DontDrawT(SkFixed t) {
        return kDontDrawT == (uint32_t)t;
    }
};


class SkTwoPointConicalGradient : public SkGradientShaderBase {
    TwoPtRadial fRec;
    void init();

public:
    SkTwoPointConicalGradient(const SkPoint& start, float startRadius,
                              const SkPoint& end, float endRadius,
                              const Descriptor&);

    virtual void shadeSpan(int x, int y, SkPMColor* dstCParam,
                           int count) SK_OVERRIDE;
    virtual bool setContext(const SkBitmap& device,
                            const SkPaint& paint,
                            const SkMatrix& matrix) SK_OVERRIDE;

    virtual BitmapType asABitmap(SkBitmap* bitmap,
                                 SkMatrix* matrix,
                                 TileMode* xy) const;
    virtual SkShader::GradientType asAGradient(GradientInfo* info) const  SK_OVERRIDE;
    virtual GrEffectRef* asNewEffect(GrContext* context, const SkPaint& paint) const SK_OVERRIDE;
    virtual bool isOpaque() const SK_OVERRIDE;

    float getCenterX1() const { return SkPoint::Distance(fCenter1, fCenter2); }
    float getStartRadius() const { return fRadius1; }
    float getDiffRadius() const { return fRadius2 - fRadius1; }

    SK_DEVELOPER_TO_STRING()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkTwoPointConicalGradient)

protected:
    SkTwoPointConicalGradient(SkFlattenableReadBuffer& buffer);
    virtual void flatten(SkFlattenableWriteBuffer& buffer) const SK_OVERRIDE;

private:
    typedef SkGradientShaderBase INHERITED;
    const SkPoint fCenter1;
    const SkPoint fCenter2;
    const float fRadius1;
    const float fRadius2;
};

#endif
