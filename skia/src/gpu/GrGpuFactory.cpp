
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

GrGpu* GrGpu::Create(GrBackend backend, GrBackendContext backendContext, GrContext* context) {

    const GrGLInterface* glInterface = NULL;
    SkAutoTUnref<const GrGLInterface> glInterfaceUnref;

    SkDebugf("%s, %d, %d", __FUNCTION__, __LINE__ , (int)backend );
    //if (kOpenGL_GrBackend == backend)
    {
        glInterface = reinterpret_cast<const GrGLInterface*>(backendContext);
        if (NULL == glInterface) {
            glInterface = GrGLDefaultInterface();
            // By calling GrGLDefaultInterface we've taken a ref on the
            // returned object. We only want to hold that ref until after
            // the GrGpu is constructed and has taken ownership.
            glInterfaceUnref.reset(glInterface);
        }
        if (NULL == glInterface) {
#ifdef SK_DEBUG
            GrPrintf("No GL interface provided!\n");
#endif
            return NULL;
        }
        SkDebugf("%s, %d, %d", __FUNCTION__, __LINE__, (int)glInterface );
        GrGLContext ctx(glInterface);
        if (ctx.isInitialized())
        {
            return SkNEW_ARGS(GrGpuGL, (ctx, context));
        }
        SkDebugf("%s, %d", __FUNCTION__, __LINE__ );
    }
    SkDebugf("%s, %d", __FUNCTION__, __LINE__ );
    return NULL;
}
