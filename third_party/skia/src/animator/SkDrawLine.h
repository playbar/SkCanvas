
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkDrawLine_DEFINED
#define SkDrawLine_DEFINED

#include "SkBoundable.h"
#include "SkMemberInfo.h"

class SkLine : public SkBoundable {
    DECLARE_MEMBER_INFO(Line);
    SkLine();
    virtual bool draw(SkAnimateMaker& );
private:
    float x1;
    float x2;
    float y1;
    float y2;
    typedef SkBoundable INHERITED;
};

#endif // SkDrawLine_DEFINED
