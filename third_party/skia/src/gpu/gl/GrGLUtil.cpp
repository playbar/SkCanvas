/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "GrGLUtil.h"
#include "SkMatrix.h"
#include "gl/glew.h"
#include "GrConfig.h"
#include <stdio.h>

void GrGLClearErr() 
{
    while (GL_NO_ERROR != glGetError()) {}
}

namespace {
const char *get_error_string(uint32_t err) {
    switch (err) {
    case GL_NO_ERROR:
        return "";
    case GL_INVALID_ENUM:
        return "Invalid Enum";
    case GL_INVALID_VALUE:
        return "Invalid Value";
    case GL_INVALID_OPERATION:
        return "Invalid Operation";
    case GL_OUT_OF_MEMORY:
        return "Out of Memory";
    case GL_CONTEXT_LOST:
        return "Context Lost";
    }
    return "Unknown";
}
}

void GrGLCheckErr( const char* location, const char* call)
{
    uint32_t err = glGetError( );
    if (GL_NO_ERROR != err) {
        GrPrintf("---- glGetError 0x%x(%s)", err, get_error_string(err));
        if (NULL != location) {
            GrPrintf(" at\n\t%s", location);
        }
        if (NULL != call) {
            GrPrintf("\n\t\t%s", call);
        }
        GrPrintf("\n");
    }
}

namespace {
// Mesa uses a non-standard version string of format: 1.4 Mesa <mesa_major>.<mesa_minor>.
// The mapping of from mesa version to GL version came from here: http://www.mesa3d.org/intro.html
bool get_gl_version_for_mesa(int mesaMajorVersion, int* major, int* minor) {
    switch (mesaMajorVersion) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            *major = 1;
            *minor = mesaMajorVersion - 1;
            return true;
        case 7:
            *major = 2;
            *minor = 1;
            return true;
        case 8:
            *major = 3;
            *minor = 0;
            return true;
        case 9:
            *major = 3;
            *minor = 1;
            return true;
        default:
            return false;
    }
}
}

///////////////////////////////////////////////////////////////////////////////

#if GL_LOG_CALLS
    bool gLogCallsGL = !!(GL_LOG_CALLS_START);
#endif

#if GL_CHECK_ERROR
    bool gCheckErrorGL = !!(GL_CHECK_ERROR_START);
#endif

///////////////////////////////////////////////////////////////////////////////

GrGLBinding GrGLGetBindingInUseFromString(const char* versionString)
{
	return kDesktop_GrGLBinding;
	return kES_GrGLBinding;
}

bool GrGLIsMesaFromVersionString(const char* versionString) {
    int major, minor, mesaMajor, mesaMinor;
    int n = sscanf(versionString, "%d.%d Mesa %d.%d", &major, &minor, &mesaMajor, &mesaMinor);
    return 4 == n;
}

bool GrGLIsChromiumFromRendererString(const char* rendererString) {
    return 0 == strcmp(rendererString, "Chromium");
}

uint32_t GrGLGetVersionFromString(const char* versionString) {
    if (NULL == versionString) {
        return 0;
    }

    int major, minor;

    // check for mesa
    int mesaMajor, mesaMinor;
    int n = sscanf(versionString, "%d.%d Mesa %d.%d", &major, &minor, &mesaMajor, &mesaMinor);
    if (4 == n) {
        if (get_gl_version_for_mesa(mesaMajor, &major, &minor)) {
            return GL_VER(major, minor);
        } else {
            return 0;
        }
    }

    n = sscanf(versionString, "%d.%d", &major, &minor);
    if (2 == n) {
        return GL_VER(major, minor);
    }

    char profile[2];
    n = sscanf(versionString, "OpenGL ES-%c%c %d.%d", profile, profile+1,
               &major, &minor);
    if (4 == n) {
        return GL_VER(major, minor);
    }

    n = sscanf(versionString, "OpenGL ES %d.%d", &major, &minor);
    if (2 == n) {
        return GL_VER(major, minor);
    }

    return 0;
}

uint32_t GrGLGetGLSLVersionFromString(const char* versionString) {
    if (NULL == versionString) {
        return 0;
    }

    int major, minor;

    int n = sscanf(versionString, "%d.%d", &major, &minor);
    if (2 == n) {
        return GR_GLSL_VER(major, minor);
    }

    n = sscanf(versionString, "OpenGL ES GLSL ES %d.%d", &major, &minor);
    if (2 == n) {
        return GR_GLSL_VER(major, minor);
    }

#ifdef SK_BUILD_FOR_ANDROID
    // android hack until the gpu vender updates their drivers
    n = sscanf(versionString, "OpenGL ES GLSL %d.%d", &major, &minor);
    if (2 == n) {
        return GR_GLSL_VER(major, minor);
    }
#endif

    return 0;
}

GrGLBinding GrGLGetBindingInUse()
{
    const GLubyte* v;
    v = glGetString(GL_VERSION);
    return GrGLGetBindingInUseFromString((const char*) v);
}

uint32_t GrGLGetVersion()
{
    const GLubyte* v;
    v = glGetString(GL_VERSION);
    return GrGLGetVersionFromString((const char*) v);
}

uint32_t GrGLGetGLSLVersion()
{
    const GLubyte* v;
    v =glGetString(GL_SHADING_LANGUAGE_VERSION);
    return GrGLGetGLSLVersionFromString((const char*) v);
}

template<> void GrGLGetMatrix<3>(GLfloat* dest, const SkMatrix& src)
{
    // Col 0
    dest[0] = SkScalarToFloat(src[SkMatrix::kMScaleX]);
    dest[1] = SkScalarToFloat(src[SkMatrix::kMSkewY]);
    dest[2] = SkScalarToFloat(src[SkMatrix::kMPersp0]);

    // Col 1
    dest[3] = SkScalarToFloat(src[SkMatrix::kMSkewX]);
    dest[4] = SkScalarToFloat(src[SkMatrix::kMScaleY]);
    dest[5] = SkScalarToFloat(src[SkMatrix::kMPersp1]);

    // Col 2
    dest[6] = SkScalarToFloat(src[SkMatrix::kMTransX]);
    dest[7] = SkScalarToFloat(src[SkMatrix::kMTransY]);
    dest[8] = SkScalarToFloat(src[SkMatrix::kMPersp2]);
}

template<> void GrGLGetMatrix<4>(GLfloat* dest, const SkMatrix& src) {
    // Col 0
    dest[0]  = SkScalarToFloat(src[SkMatrix::kMScaleX]);
    dest[1]  = SkScalarToFloat(src[SkMatrix::kMSkewY]);
    dest[2]  = 0;
    dest[3]  = SkScalarToFloat(src[SkMatrix::kMPersp0]);

    // Col 1
    dest[4]  = SkScalarToFloat(src[SkMatrix::kMSkewX]);
    dest[5]  = SkScalarToFloat(src[SkMatrix::kMScaleY]);
    dest[6]  = 0;
    dest[7]  = SkScalarToFloat(src[SkMatrix::kMPersp1]);

    // Col 2
    dest[8]  = 0;
    dest[9]  = 0;
    dest[10] = 1;
    dest[11] = 0;

    // Col 3
    dest[12] = SkScalarToFloat(src[SkMatrix::kMTransX]);
    dest[13] = SkScalarToFloat(src[SkMatrix::kMTransY]);
    dest[14] = 0;
    dest[15] = SkScalarToFloat(src[SkMatrix::kMPersp2]);
}
