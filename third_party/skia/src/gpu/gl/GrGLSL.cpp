/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLSL.h"
#include "GrGLShaderVar.h"
#include "SkString.h"

GrGLSLGeneration GrGetGLSLGeneration(GrGLBinding binding) 
{
    switch (binding) {
        case kDesktop_GrGLBinding:
			return k150_GrGLSLGeneration;
        case kES_GrGLBinding:
            // version 1.00 of ES GLSL based on ver 1.20 of desktop GLSL
            return k110_GrGLSLGeneration;
        default:
            GrCrash("Unknown GL Binding");
            return k110_GrGLSLGeneration; // suppress warning
    }
}

const char* GrGetGLSLVersionDecl(const GrGLContextInfo& info) {
	return "#version 150 compatibility\n";
}

namespace {
    void append_tabs(SkString* outAppend, int tabCnt) {
        static const char kTabs[] = "\t\t\t\t\t\t\t\t";
        while (tabCnt) {
            int cnt = GrMin((int)GR_ARRAY_COUNT(kTabs), tabCnt);
            outAppend->append(kTabs, cnt);
            tabCnt -= cnt;
        }
    }
}

void GrGLSLMulVarBy4f(SkString* outAppend,
                      unsigned tabCnt,
                      const char* vec4VarName,
                      const GrGLSLExpr4& mulFactor) {
    if (mulFactor.isOnes()) {
        *outAppend = SkString();
    }

    append_tabs(outAppend, tabCnt);

    if (mulFactor.isZeros()) {
        outAppend->appendf("%s = vec4(0);\n", vec4VarName);
    } else {
        outAppend->appendf("%s *= %s;\n", vec4VarName, mulFactor.c_str());
    }
}
