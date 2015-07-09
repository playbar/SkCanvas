/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrGLUtil_DEFINED
#define GrGLUtil_DEFINED

#include "SkRefCnt.h"
#include "gl/glew.h"

class SkMatrix;

////////////////////////////////////////////////////////////////////////////////

/**
 * The Vendor and Renderer enum values are lazily updated as required.
 */

enum GrGLBinding 
{
    kNone_GrGLBinding = 0x0,

    kDesktop_GrGLBinding = 0x01,
    kES_GrGLBinding = 0x02,  // ES2+ only
};

/* Path Rendering */
// commands
#define GL_CLOSE_PATH                                    0x00
#define GL_MOVE_TO                                       0x02
#define GL_RELATIVE_MOVE_TO                              0x03
#define GL_LINE_TO                                       0x04
#define GL_RELATIVE_LINE_TO                              0x05
#define GL_HORIZONTAL_LINE_TO                            0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO                   0x07
#define GL_VERTICAL_LINE_TO                              0x08
#define GL_RELATIVE_VERTICAL_LINE_TO                     0x09
#define GL_QUADRATIC_CURVE_TO                            0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO                   0x0B
#define GL_CUBIC_CURVE_TO                                0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO                       0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO                     0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO            0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO                         0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO                0x11
#define GL_SMALL_CCW_ARC_TO                              0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO                     0x13
#define GL_SMALL_CW_ARC_TO                               0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO                      0x15
#define GL_LARGE_CCW_ARC_TO                              0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO                     0x17
#define GL_LARGE_CW_ARC_TO                               0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO                      0x19
#define GL_CIRCULAR_CCW_ARC_TO                           0xF8
#define GL_CIRCULAR_CW_ARC_TO                            0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO                       0xFC
#define GL_ARC_TO                                        0xFE
#define GL_RELATIVE_ARC_TO                               0xFF

// cap/dash values
/*      GL_FLAT */
#define GL_SQUARE                                        0x90A3
#define GL_ROUND                                         0x90A4
#define GL_TRIANGULAR                                    0x90A5

// join values
/*      GL_NONE */
/*      GL_ROUND_NV  */
#define GL_BEVEL                                         0x90A6
#define GL_MITER_REVERT                                  0x90A7
#define GL_MITER_TRUNCATE                                0x90A8
#define GL_UNPACK_FLIP_Y                  0x9240
#define GL_PACK_REVERSE_ROW_ORDER         0x93A4
#define GL_PALETTE8_RGBA8                 0x8B96
#define GL_TEXTURE_USAGE                  0x93A2
#define GL_FRAMEBUFFER_ATTACHMENT         0x93A3
#define GL_BGRA8                          0x93A1


#define GL_VER(major, minor) ((static_cast<int>(major) << 16) | \
                                 static_cast<int>(minor))
#define GR_GLSL_VER(major, minor) ((static_cast<int>(major) << 16) | \
                                   static_cast<int>(minor))

////////////////////////////////////////////////////////////////////////////////


/**
 * Helpers for glGetString()
 */

// these variants assume caller already has a string from glGetString()
uint32_t GrGLGetVersionFromString(const char* versionString);
GrGLBinding GrGLGetBindingInUseFromString(const char* versionString);
uint32_t GrGLGetGLSLVersionFromString(const char* versionString);
bool GrGLIsMesaFromVersionString(const char* versionString);
bool GrGLIsChromiumFromRendererString(const char* rendererString);

// these variants call glGetString()
GrGLBinding GrGLGetBindingInUse();
uint32_t GrGLGetVersion();
uint32_t GrGLGetGLSLVersion();

/**
 * Helpers for glGetError()
 */

void GrGLCheckErr(const char* location,
                  const char* call);

void GrGLClearErr();

/**
 * Helper for converting SkMatrix to a column-major GL float array
 */
template<int MatrixSize> void GrGLGetMatrix(GLfloat* dest, const SkMatrix& src);

////////////////////////////////////////////////////////////////////////////////

/**
 * Macros for using GLinterface to make GL calls
 */

#endif
