
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "GrTypes.h"

#include "gl/GrGLConfig.h"

#include "GrGpu.h"
#include "gl/GrGpuGL.h"

GrGpu* GrGpu::Create( GrContext* context)
{

	GrGLContext ctx;
	if (ctx.isInitialized())
	{
		return new GrGpuGL(ctx, context);
	}
    return NULL;
}
