/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef GrGLContext_DEFINED
#define GrGLContext_DEFINED

#include "GrGLCaps.h"
#include "gl/glew.h"
#include "GrGLSL.h"
#include "GrGLUtil.h"

#include "SkString.h"

/**
 * Encapsulates information about an OpenGL context including the OpenGL
 * version, the GrGLBinding type of the context, and GLSL version.
 */
class GrGLContextInfo 
{
public:
    /**
     * Default constructor
     */
    GrGLContextInfo() {
        fGLCaps.reset(SkNEW(GrGLCaps));
        this->reset();
    }

    /**
     * Copies a GrGLContextInfo
     */
    GrGLContextInfo& operator= (const GrGLContextInfo& ctxInfo);

    /**
     * Initializes a GrGLContextInfo from a GLinterface and the currently
     * bound OpenGL context accessible by the GLinterface.
     */
    bool initialize();
    bool isInitialized() const;

    GrGLBinding binding() const { return fBindingInUse; }
    uint32_t version() const { return fGLVersion; }
    GrGLSLGeneration glslGeneration() const { return fGLSLGeneration; }
    /** Is this a mesa-based driver. Does not mean it is the osmesa software rasterizer. */
    bool isMesa() const { return fIsMesa; }
    /** Are we running inside Chromium (using the command buffer)? We make some different tradeoffs
        about what errors to check for because queries are synchronous. We should probably expose
        this as an option for clients other than Chromium. */
    bool isChromium() const { return fIsChromium; }
    const GrGLCaps* caps() const { return fGLCaps.get(); }
    GrGLCaps* caps() { return fGLCaps; }

    /**
     * Reset the information
     */
    void reset();

private:

    GrGLBinding             fBindingInUse;
	bool					bBindingInUse;
    uint32_t             fGLVersion;
    GrGLSLGeneration        fGLSLGeneration;
    bool                    fIsMesa;
    bool                    fIsChromium;
    SkAutoTUnref<GrGLCaps>  fGLCaps;
};

/**
 * Encapsulates the GLinterface used to make GL calls plus information
 * about the context (via GrGLContextInfo).
 */
class GrGLContext 
{
public:
    /**
     * Default constructor
     */
	GrGLContext();

	/**
     * Copies a GrGLContext
     */
    GrGLContext(const GrGLContext& ctx);

    ~GrGLContext() {  }

    /**
     * Copies a GrGLContext
     */
    GrGLContext& operator= (const GrGLContext& ctx);

    /**
     * Initializes a GrGLContext from a GLinterface and the currently
     * bound OpenGL context accessible by the GLinterface.
     */
    bool initialize();
    bool isInitialized() const { return fInfo.isInitialized(); }

    const GrGLContextInfo& info() const { return fInfo; }
    GrGLContextInfo& info() { return fInfo; }

private:
    void reset();
    GrGLContextInfo      fInfo;
};

#endif
