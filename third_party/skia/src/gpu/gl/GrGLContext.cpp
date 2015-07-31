/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLContext.h"

////////////////////////////////////////////////////////////////////////////////
GrGLContextInfo& GrGLContextInfo::operator= (const GrGLContextInfo& ctxInfo)
{
    fGLVersion = ctxInfo.fGLVersion;
    fGLSLGeneration = ctxInfo.fGLSLGeneration;
    fIsMesa = ctxInfo.fIsMesa;
    fIsChromium = ctxInfo.fIsChromium;
    *fGLCaps = *ctxInfo.fGLCaps.get();
    return *this;
}

bool GrGLContextInfo::initialize()
{
    this->reset();
    // We haven't validated the GLinterface yet, so check for GetString
    // function pointer
	const GLubyte* verUByte;
	verUByte = glGetString(GL_VERSION);
	const char* ver = reinterpret_cast<const char*>(verUByte);

	const GLubyte* rendererUByte;
	rendererUByte = glGetString(GL_RENDERER);

	const char* renderer = reinterpret_cast<const char*>(rendererUByte);

	fGLVersion = GrGLGetVersionFromString(ver);

	fIsMesa = GrGLIsMesaFromVersionString(ver);

	fIsChromium = GrGLIsChromiumFromRendererString(renderer);

	fGLCaps->init(*this);
	return true;

}

void GrGLContextInfo::reset()
{
	bBindingInUse = false;
    fGLVersion = GL_VER(0, 0);
    fGLSLGeneration = static_cast<GrGLSLGeneration>(0);
    fIsMesa = false;
    fIsChromium = false;
    fGLCaps->reset();
}

////////////////////////////////////////////////////////////////////////////////
GrGLContext::GrGLContext() {
    this->initialize();
}

GrGLContext::GrGLContext(const GrGLContext& ctx) {
    *this = ctx;
}

GrGLContext& GrGLContext::operator = (const GrGLContext& ctx) {
    fInfo = ctx.fInfo;
    return *this;
}

void GrGLContext::reset() {
    fInfo.reset();
}

bool GrGLContext::initialize()
{
    if (fInfo.initialize()) 
	{
		return true;
    }
    return false;
}
