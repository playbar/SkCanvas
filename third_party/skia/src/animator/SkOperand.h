
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkOperand_DEFINED
#define SkOperand_DEFINED

#include "SkDisplayType.h"

class SkTypedArray;
class SkDisplayable;
class SkDrawable;
class SkString;

union SkOperand {
//  SkOperand() {}
//  SkOperand(SkScalar scalar) : fScalar(scalar) {}
    SkTypedArray* fArray;
    SkDisplayable* fDisplayable;
    SkDrawable* fDrawable;
    void* fObject;
    int32_t fS32;
    SkMSec fMSec;
    float fScalar;
    SkString* fString;
};

struct SkScriptValue {
    SkOperand fOperand;
    SkDisplayTypes fType;
    SkTypedArray* getArray() {  return fOperand.fArray; }
    SkDisplayable* getDisplayable() { return fOperand.fDisplayable; }
    SkDrawable* getDrawable() { return fOperand.fDrawable; }
    int32_t getS32(SkAnimateMaker* maker)
	{
		return fOperand.fS32;
	}
    SkMSec getMSec() { return fOperand.fMSec; }
    float getScalar() { return fOperand.fScalar; }
    SkString* getString() { return fOperand.fString; }
};

#endif // SkOperand_DEFINED
