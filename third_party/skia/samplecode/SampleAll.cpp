
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SampleCode.h"
#include "SkBlurMask.h"
#include "SkCanvas.h"
#include "SkView.h"
#include "Sk1DPathEffect.h"
#include "Sk2DPathEffect.h"
#include "SkAvoidXfermode.h"
#include "SkBlurMaskFilter.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkCornerPathEffect.h"
#include "SkDashPathEffect.h"
#include "SkDiscretePathEffect.h"
#include "SkEmbossMaskFilter.h"
#include "SkFlattenableBuffers.h"
#include "SkGradientShader.h"
#include "SkImageDecoder.h"
#include "SkLayerRasterizer.h"
#include "SkMath.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkComposeShader.h"
#include "SkCornerPathEffect.h"
#include "SkPathMeasure.h"
#include "SkPicture.h"
#include "SkRandom.h"
#include "SkTransparentShader.h"
#include "SkTypeface.h"
#include "SkUnitMappers.h"
#include "SkUtils.h"
#include "SkXfermode.h"

#include <math.h>

static inline SkPMColor rgb2gray(SkPMColor c) {
    unsigned r = SkGetPackedR32(c);
    unsigned g = SkGetPackedG32(c);
    unsigned b = SkGetPackedB32(c);

    unsigned x = (r * 5 + g * 7 + b * 4) >> 4;

    return SkPackARGB32(0, x, x, x) | (c & (SK_A32_MASK << SK_A32_SHIFT));
}

class SkGrayScaleColorFilter : public SkColorFilter {
public:
    virtual void filterSpan(const SkPMColor src[], int count,
                            SkPMColor result[]) const SK_OVERRIDE {
        for (int i = 0; i < count; i++)
            result[i] = rgb2gray(src[i]);
    }
};

class SkChannelMaskColorFilter : public SkColorFilter {
public:
    SkChannelMaskColorFilter(U8CPU redMask, U8CPU greenMask, U8CPU blueMask) {
        fMask = SkPackARGB32(0xFF, redMask, greenMask, blueMask);
    }

    virtual void filterSpan(const SkPMColor src[], int count,
                            SkPMColor result[]) const SK_OVERRIDE {
        SkPMColor mask = fMask;
        for (int i = 0; i < count; i++) {
            result[i] = src[i] & mask;
        }
    }

private:
    SkPMColor   fMask;
};

///////////////////////////////////////////////////////////

static void r0(SkLayerRasterizer* rast, SkPaint& p) {
    p.setMaskFilter(SkBlurMaskFilter::Create(SkBlurMaskFilter::kNormal_BlurStyle,
                                             SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(3)),
                                             SkBlurMaskFilter::kNone_BlurFlag))->unref();
    rast->addLayer(p, SkIntToScalar(3), SkIntToScalar(3));

    p.setMaskFilter(NULL);
    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(SK_Scalar1);
    rast->addLayer(p);

    p.setAlpha(0x11);
    p.setStyle(SkPaint::kFill_Style);
    p.setXfermodeMode(SkXfermode::kSrc_Mode);
    rast->addLayer(p);
}

static void r1(SkLayerRasterizer* rast, SkPaint& p) {
    rast->addLayer(p);

    p.setAlpha(0x40);
    p.setXfermodeMode(SkXfermode::kSrc_Mode);
    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(SK_Scalar1*2);
    rast->addLayer(p);
}

static void r2(SkLayerRasterizer* rast, SkPaint& p) {
    p.setStyle(SkPaint::kStrokeAndFill_Style);
    p.setStrokeWidth(SK_Scalar1*4);
    rast->addLayer(p);

    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(SK_Scalar1*3/2);
    p.setXfermodeMode(SkXfermode::kClear_Mode);
    rast->addLayer(p);
}

static void r3(SkLayerRasterizer* rast, SkPaint& p) {
    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(SK_Scalar1*3);
    rast->addLayer(p);

    p.setAlpha(0x20);
    p.setStyle(SkPaint::kFill_Style);
    p.setXfermodeMode(SkXfermode::kSrc_Mode);
    rast->addLayer(p);
}

static void r4(SkLayerRasterizer* rast, SkPaint& p) {
    p.setAlpha(0x60);
    rast->addLayer(p, SkIntToScalar(3), SkIntToScalar(3));

    p.setAlpha(0xFF);
    p.setXfermodeMode(SkXfermode::kClear_Mode);
    rast->addLayer(p, SK_Scalar1*3/2, SK_Scalar1*3/2);

    p.setXfermode(NULL);
    rast->addLayer(p);
}

static void r5(SkLayerRasterizer* rast, SkPaint& p) {
    rast->addLayer(p);

    p.setPathEffect(new SkDiscretePathEffect(SK_Scalar1*4, SK_Scalar1*3))->unref();
    p.setXfermodeMode(SkXfermode::kSrcOut_Mode);
    rast->addLayer(p);
}

static void r6(SkLayerRasterizer* rast, SkPaint& p) {
    rast->addLayer(p);

    p.setAntiAlias(false);
    SkLayerRasterizer* rast2 = new SkLayerRasterizer;
    r5(rast2, p);
    p.setRasterizer(rast2)->unref();
    p.setXfermodeMode(SkXfermode::kClear_Mode);
    rast->addLayer(p);
}

class Dot2DPathEffect : public Sk2DPathEffect {
public:
    Dot2DPathEffect(float radius, const SkMatrix& matrix)
        : Sk2DPathEffect(matrix), fRadius(radius) {}

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(Dot2DPathEffect)

protected:
    virtual void next(const SkPoint& loc, int u, int v, SkPath* dst) const SK_OVERRIDE {
        dst->addCircle(loc.fX, loc.fY, fRadius);
    }

    Dot2DPathEffect(SkFlattenableReadBuffer& buffer) : INHERITED(buffer) {
        fRadius = buffer.readScalar();
    }
    virtual void flatten(SkFlattenableWriteBuffer& buffer) const SK_OVERRIDE {
        this->INHERITED::flatten(buffer);
        buffer.writeScalar(fRadius);
    }

private:
    float fRadius;

    typedef Sk2DPathEffect INHERITED;
};

static void r7(SkLayerRasterizer* rast, SkPaint& p) {
    SkMatrix    lattice;
    lattice.setScale(SK_Scalar1*6, SK_Scalar1*6, 0, 0);
    lattice.postSkew(SK_Scalar1/3, 0, 0, 0);
    p.setPathEffect(new Dot2DPathEffect(SK_Scalar1*4, lattice))->unref();
    rast->addLayer(p);
}

static void r8(SkLayerRasterizer* rast, SkPaint& p) {
    rast->addLayer(p);

    SkMatrix    lattice;
    lattice.setScale(SK_Scalar1*6, SK_Scalar1*6, 0, 0);
    lattice.postSkew(SK_Scalar1/3, 0, 0, 0);
    p.setPathEffect(new Dot2DPathEffect(SK_Scalar1*2, lattice))->unref();
    p.setXfermodeMode(SkXfermode::kClear_Mode);
    rast->addLayer(p);

    p.setPathEffect(NULL);
    p.setXfermode(NULL);
    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(SK_Scalar1);
    rast->addLayer(p);
}

static void r9(SkLayerRasterizer* rast, SkPaint& p) {
    rast->addLayer(p);

    SkMatrix    lattice;
    lattice.setScale(SK_Scalar1, SK_Scalar1*6, 0, 0);
    lattice.postRotate(SkIntToScalar(30), 0, 0);
    p.setPathEffect(new SkLine2DPathEffect(SK_Scalar1*2, lattice))->unref();
    p.setXfermodeMode(SkXfermode::kClear_Mode);
    rast->addLayer(p);

    p.setPathEffect(NULL);
    p.setXfermode(NULL);
    p.setStyle(SkPaint::kStroke_Style);
    p.setStrokeWidth(SK_Scalar1);
    rast->addLayer(p);
}

typedef void (*raster_proc)(SkLayerRasterizer*, SkPaint&);

static const raster_proc gRastProcs[] = {
    r0, r1, r2, r3, r4, r5, r6, r7, r8, r9
};

static const struct {
    SkColor fMul, fAdd;
} gLightingColors[] = {
    { 0x808080, 0x800000 }, // general case
    { 0x707070, 0x707070 }, // no-pin case
    { 0xFFFFFF, 0x800000 }, // just-add case
    { 0x808080, 0x000000 }, // just-mul case
    { 0xFFFFFF, 0x000000 }  // identity case
};

static void apply_shader(SkPaint* paint, int index) {
    raster_proc proc = gRastProcs[index];
    if (proc) {
        SkPaint p;
        SkLayerRasterizer*  rast = new SkLayerRasterizer;

        p.setAntiAlias(true);
        proc(rast, p);
        paint->setRasterizer(rast)->unref();
    }

#if 1
    float dir[] = { SK_Scalar1, SK_Scalar1, SK_Scalar1 };
    paint->setMaskFilter(SkBlurMaskFilter::CreateEmboss(
                SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(3)), dir,
                SK_Scalar1/4, SkIntToScalar(4)))->unref();
    paint->setColor(SK_ColorBLUE);
#endif
}
