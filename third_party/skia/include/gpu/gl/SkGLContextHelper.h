
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkGLContextHelper_DEFINED
#define SkGLContextHelper_DEFINED

#include "gl/glew.h"
#include "SkRefCnt.h"

/**
 * Create an offscreen opengl context with an RGBA8 / 8bit stencil FBO.
 * Provides a GLinterface struct of function pointers for the context.
 */

class SkGLContextHelper : public SkRefCnt {
public:
    SK_DECLARE_INST_COUNT(SkGLContextHelper)

    SkGLContextHelper();
    virtual ~SkGLContextHelper();

    /**
     * Initializes the context and makes it current.
     */
    bool init(const int width, const int height);

    int getFBOID() const { return fFBO; }

    virtual void makeCurrent() const = 0;

    /**
     * The primary purpose of this function it to provide a means of scheduling
     * work on the GPU (since all of the subclasses create primary buffers for
     * testing that are small and not meant to be rendered to the screen).
     *
     * If the drawing surface provided by the platform is double buffered this
     * call will cause the platform to swap which buffer is currently being
     * targeted.  If the current surface does not include a back buffer, this
     * call has no effect.
     */
    virtual void swapBuffers() const = 0;

protected:
    /**
     * Subclass should destroy the underlying GL context.
     */
	virtual void createGLContext() = 0;
    virtual void destroyGLContext() = 0;

private:
    GLuint fFBO;
    GLuint fColorBufferID;
    GLuint fDepthStencilBufferID;

    typedef SkRefCnt INHERITED;
};

/**
 * Helper macros for using the GL context through the GLinterface. Example:
 * SK_GL(glCtx, GenTextures(1, &texID));
 */
#define SK_GL(ctx, X) (ctx).gl()->f ## X;    \
                      SkASSERT(GL_NO_ERROR == (ctx).gl()->fGetError())
#define SK_GL_RET(ctx, RET, X) (RET) = (ctx).gl()->f ## X;    \
                  SkASSERT(GL_NO_ERROR == (ctx).gl()->fGetError())
#define SK_GL_NOERRCHECK(ctx, X) (ctx).gl()->f ## X
#define SK_GL_RET_NOERRCHECK(ctx, RET, X) (RET) = (ctx).gl()->f ## X

#endif
