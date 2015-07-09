
/*
* Copyright 2013 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/
#include "gl/SkGLContextHelper.h"
#include "GrGLUtil.h"

SkGLContextHelper::SkGLContextHelper()
	: fFBO(0)
	, fColorBufferID(0)
	, fDepthStencilBufferID(0)
{
}

SkGLContextHelper::~SkGLContextHelper()
{
	// TODO: determine why DeleteFramebuffers is generating a GL error in tests
	glDeleteFramebuffers(1, &fFBO);
	glDeleteRenderbuffers(1, &fColorBufferID);
	glDeleteRenderbuffers(1, &fDepthStencilBufferID);

}

bool SkGLContextHelper::init(int width, int height)
{
	destroyGLContext();
	createGLContext();
	GrGLBinding bindingInUse = GrGLGetBindingInUse();

	// clear any existing GL erorrs
	GLenum error;
	do {
		error = glGetError();
	} while (GL_NO_ERROR != error);

	glGenFramebuffers(1, &fFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, fFBO);
	glGenRenderbuffers(1, &fColorBufferID);
	glBindRenderbuffer(GL_RENDERBUFFER, fColorBufferID);
	if (kES_GrGLBinding == bindingInUse)
	{
		glRenderbufferStorage(GL_RENDERBUFFER,
			GL_RGBA8,
			width, height);
	}
	else {
		glRenderbufferStorage(GL_RENDERBUFFER,
			GL_RGBA,
			width, height);
	}

	glFramebufferRenderbuffer(GL_FRAMEBUFFER,
		GL_COLOR_ATTACHMENT0,
		GL_RENDERBUFFER,
		fColorBufferID);
	glGenRenderbuffers(1, &fDepthStencilBufferID);
	glBindRenderbuffer(GL_RENDERBUFFER, fDepthStencilBufferID);

	// Some drivers that support packed depth stencil will only succeed
	// in binding a packed format an FBO. However, we can't rely on packed
	// depth stencil being available.
	bool supportsPackedDepthStencil = true;

	if (supportsPackedDepthStencil)
	{
		// ES2 requires sized internal formats for RenderbufferStorage
		// On Desktop we let the driver decide.
		GLenum format = kES_GrGLBinding == bindingInUse ?
		GL_DEPTH24_STENCIL8 :
							GL_DEPTH_STENCIL;
		glRenderbufferStorage(GL_RENDERBUFFER,
			format,
			width, height);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER,
			GL_DEPTH_ATTACHMENT,
			GL_RENDERBUFFER,
			fDepthStencilBufferID);
	}
	else {
		GLenum format = kES_GrGLBinding == bindingInUse ?
		GL_STENCIL_INDEX8 :
						  GL_STENCIL_INDEX;
		glRenderbufferStorage(GL_RENDERBUFFER,
			format,
			width, height);
	}
	glFramebufferRenderbuffer(GL_FRAMEBUFFER,
		GL_STENCIL_ATTACHMENT,
		GL_RENDERBUFFER,
		fDepthStencilBufferID);
	glViewport(0, 0, width, height);
	glClearStencil(0);
	glClear(GL_STENCIL_BUFFER_BIT);

	error = glGetError();
	GLenum status;
	status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

	if (GL_FRAMEBUFFER_COMPLETE != status ||
		GL_NO_ERROR != error)
	{
		fFBO = 0;
		fColorBufferID = 0;
		fDepthStencilBufferID = 0;

		this->destroyGLContext();
		return false;
	}
	else {
		return true;
	}
	return false;
}
