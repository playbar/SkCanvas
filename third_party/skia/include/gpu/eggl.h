#ifndef __EGGL_H__
#define __EGGL_H__

#ifdef WIN32
#include "gl/glew.h"
#elif __ANDROID__
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/glext.h>

#endif



#endif
