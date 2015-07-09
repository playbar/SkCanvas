
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkOperand2_DEFINED
#define SkOperand2_DEFINED

#include "SkScalar.h"

class SkOpArray;
class SkString;

union SkOperand2 {
    enum OpType {
        kNoType,
        kS32 = 1,
        kScalar = 2,
        kString = 4,
        kArray = 8,
        kObject = 16
    };
    SkOpArray* fArray;
    void* fObject;
    size_t fReference;
    int32_t fS32;
    float fScalar;
    SkString* fString;
};

struct SkScriptValue2 {
    enum IsConstant {
        kConstant,
        kVariable
    };
    enum IsWritten {
        kUnwritten,
        kWritten
    };
    SkOperand2 fOperand;
    SkOperand2::OpType fType : 8;
    IsConstant fIsConstant : 8;
    IsWritten fIsWritten : 8;
    SkOpArray* getArray() { return fOperand.fArray; }
    void* getObject() { return fOperand.fObject; }
    int32_t getS32() { return fOperand.fS32; }
    float getScalar() { return fOperand.fScalar; }
    SkString* getString() { return fOperand.fString; }
	bool isConstant() const { return fIsConstant == kConstant; }
};

#endif // SkOperand2_DEFINED
