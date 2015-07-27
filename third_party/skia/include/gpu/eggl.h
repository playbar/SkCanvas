#ifndef __EGGL_H__
#define __EGGL_H__

#ifdef WIN32
#include "gl/glew.h"
#elif __ANDROID__
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#define GL_DEPTH24_STENCIL8 GL_DEPTH24_STENCIL8_OES
#define GL_STENCIL_INDEX4	GL_STENCIL_INDEX4_OES
#define GL_DEPTH_STENCIL	GL_DEPTH_STENCIL_OES
#define glBindVertexArray	glBindVertexArrayOES
#define GL_RED				0x1903
#define GL_GREEN			0x1904
#define GL_BLUE				0x1905
#endif



#endif
