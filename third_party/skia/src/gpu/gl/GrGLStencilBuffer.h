/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef GrGLStencilBuffer_DEFINED
#define GrGLStencilBuffer_DEFINED

#include "GrStencilBuffer.h"
#include "gl/glew.h"

class GrGLStencilBuffer : public GrStencilBuffer
{
public:
    static const GLenum kUnknownInternalFormat = ~0U;
    static const GLuint kUnknownBitCount = ~0U;
    struct Format {
        GLenum  fInternalFormat;
        GLuint  fStencilBits;
        GLuint  fTotalBits;
        bool      fPacked;
    };

    GrGLStencilBuffer(GrGpu* gpu,
                      bool isWrapped,
                      GLint rbid,
                      int width, int height,
                      int sampleCnt,
                      const Format& format)
        : GrStencilBuffer(gpu, isWrapped, width, height, format.fStencilBits, sampleCnt)
        , fFormat(format)
        , fRenderbufferID(rbid) {
    }

    virtual ~GrGLStencilBuffer();

    virtual size_t sizeInBytes() const SK_OVERRIDE;

    GLuint renderbufferID() const {
        return fRenderbufferID;
    }

    const Format& format() const { return fFormat; }

protected:
    // overrides of GrResource
    virtual void onRelease() SK_OVERRIDE;
    virtual void onAbandon() SK_OVERRIDE;

private:
    Format fFormat;
    // may be zero for external SBs associated with external RTs
    // (we don't require the client to give us the id, just tell
    // us how many bits of stencil there are).
    GLuint fRenderbufferID;

    typedef GrStencilBuffer INHERITED;
};

#endif
