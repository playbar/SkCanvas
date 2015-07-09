
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkOperandInterpolator.h"
#include "SkScript.h"

SkOperandInterpolator::SkOperandInterpolator() {
    INHERITED::reset(0, 0);
    fType = SkType_Unknown;
}

SkOperandInterpolator::SkOperandInterpolator(int elemCount, int frameCount,
                                             SkDisplayTypes type)
{
    this->reset(elemCount, frameCount, type);
}

void SkOperandInterpolator::reset(int elemCount, int frameCount, SkDisplayTypes type)
{
//  SkASSERT(type == SkType_String || type == SkType_Float || type == SkType_Int ||
//      type == SkType_Displayable || type == SkType_Drawable);
    INHERITED::reset(elemCount, frameCount);
    fType = type;
    fStorage = sk_malloc_throw((sizeof(SkOperand) * elemCount + sizeof(SkTimeCode)) * frameCount);
    fTimes = (SkTimeCode*) fStorage;
    fValues = (SkOperand*) ((char*) fStorage + sizeof(SkTimeCode) * frameCount);

}

bool SkOperandInterpolator::setKeyFrame(int index, SkMSec time, const SkOperand values[], float blend)
{
    blend = SkScalarPin(blend, 0, SK_Scalar1);

    bool success = ~index == SkTSearch<SkMSec>(&fTimes->fTime, index, time, sizeof(SkTimeCode));
    if (success) {
        SkTimeCode* timeCode = &fTimes[index];
        timeCode->fTime = time;
        timeCode->fBlend[0] = SK_Scalar1 - blend;
        timeCode->fBlend[1] = 0;
        timeCode->fBlend[2] = 0;
        timeCode->fBlend[3] = SK_Scalar1 - blend;
        SkOperand* dst = &fValues[fElemCount * index];
        memcpy(dst, values, fElemCount * sizeof(SkOperand));
    }
    return success;
}

SkInterpolatorBase::Result SkOperandInterpolator::timeToValues(SkMSec time, SkOperand values[]) const
{
    float T;
    int index;
    SkBool exact;
    Result result = timeToT(time, &T, &index, &exact);
    if (values)
    {
        const SkOperand* nextSrc = &fValues[index * fElemCount];

        if (exact)
            memcpy(values, nextSrc, fElemCount * sizeof(float));
        else
        {
            const SkOperand* prevSrc = nextSrc - fElemCount;

            if (fType == SkType_Float || fType == SkType_3D_Point) {
                for (int i = fElemCount - 1; i >= 0; --i)
                    values[i].fScalar = SkScalarInterp(prevSrc[i].fScalar, nextSrc[i].fScalar, T);
            } else if (fType == SkType_Int || fType == SkType_MSec) {
                for (int i = fElemCount - 1; i >= 0; --i) {
                    int32_t a = prevSrc[i].fS32;
                    int32_t b = nextSrc[i].fS32;
                    values[i].fS32 = a + SkScalarRoundToInt((b - a) * T);
                }
            } else
                memcpy(values, prevSrc, sizeof(SkOperand) * fElemCount);
        }
    }
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


