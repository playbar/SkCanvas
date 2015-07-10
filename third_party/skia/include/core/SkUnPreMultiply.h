
/*
 * Copyright 2008 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */





#ifndef SkUnPreMultiply_DEFINED
#define SkUnPreMultiply_DEFINED

#include "SkColor.h"

class SK_API SkUnPreMultiply {
public:
    typedef uint32_t Scale;

    // index this table with alpha [0..255]
	static const Scale* GetScaleTable();

	static Scale GetScale(U8CPU alpha);

	static U8CPU ApplyScale(Scale scale, U8CPU component);

    static SkColor PMColorToColor(SkPMColor c);

private:
    static const uint32_t gTable[256];
};

#endif
