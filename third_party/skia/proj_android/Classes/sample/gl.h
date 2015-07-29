#ifndef _GL_H_
#define _GL_H_

#ifdef WIN32

#include "GL/glew.h"
#include "glfw3.h"

#elif __ANDROID__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define GL_ES

#ifndef GL_DEPTH24_STENCIL8
#define GL_DEPTH24_STENCIL8 GL_DEPTH24_STENCIL8_OES
#endif

#endif

#ifndef GL_DEPTH24_STENCIL8
#define GL_DEPTH24_STENCIL8 GL_DEPTH24_STENCIL8_OES
#endif

#ifndef CHECK_GL_ERROR_FLAG
#define CHECK_GL_ERROR(op)
#else
#define CHECK_GL_ERROR(op) \
	do{\
		for (GLint error = glGetError(); error; error\
					= glGetError()) {\
				LOGE(">>>>>>>>>>>>>>>>OpenGL error after %s() glError (0x%x)\n" ,op, error);\
		}\
	}while(0);
#endif /*CHECK_GL_ERROR_FLAG */
#define GET_GL_ERROR(error) for(GLint error = glGetError(); error; error= glGetError())
#define LOG_GL_ERROR(message,error) LOGE(">>>>>>>>>>>>>>>>OpenGL error: %s ; glError (0x%x)\n" ,message, error)
#define CHECK_GL_ERROR_FORCE(op) \
	do{\
		for (GLint error = glGetError(); error; error\
					= glGetError()) {\
				LOGE(">>>>>>>>>>>>>>>>OpenGL error after %s() glError (0x%x)\n" ,op, error);\
				}\
		}while(0);
#endif


