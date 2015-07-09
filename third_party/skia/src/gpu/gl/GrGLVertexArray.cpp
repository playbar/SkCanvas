/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLVertexArray.h"
#include "GrGpuGL.h"

#define GPUGL static_cast<GrGpuGL*>(this->getGpu())

void GrGLAttribArrayState::set(const GrGpuGL* gpu,
                               int index,
                               GrGLVertexBuffer* buffer,
                               GLint size,
                               GLenum type,
                               GLboolean normalized,
                               GLsizei stride,
                               GLvoid* offset) 
{
    AttribArrayState* array = &fAttribArrayStates[index];
    if (!array->fEnableIsValid || !array->fEnabled) 
	{
       glEnableVertexAttribArray(index);
        array->fEnableIsValid = true;
        array->fEnabled = true;
    }
    if (!array->fAttribPointerIsValid ||
        array->fVertexBufferID != buffer->bufferID() ||
        array->fSize != size ||
        array->fNormalized != normalized ||
        array->fStride != stride ||
        array->fOffset != offset) {

        buffer->bind();
		glVertexAttribPointer(index,
			size,
			type,
			normalized,
			stride,
			offset);
		array->fAttribPointerIsValid = true;
        array->fVertexBufferID = buffer->bufferID();
        array->fSize = size;
        array->fNormalized = normalized;
        array->fStride = stride;
        array->fOffset = offset;
    }
}

void GrGLAttribArrayState::setFixedFunctionVertexArray(const GrGpuGL* gpu,
                                                       GrGLVertexBuffer* buffer,
                                                       GLint size,
                                                       GLenum type,
                                                       GLsizei stride,
                                                       GLvoid* offset) {
    AttribArrayState* array = &fFixedFunctionVertexArray;
    if (!array->fEnableIsValid || !array->fEnabled)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
        array->fEnableIsValid = true;
        array->fEnabled = true;
    }
    if (!array->fAttribPointerIsValid ||
        array->fVertexBufferID != buffer->bufferID() ||
        array->fSize != size ||
        array->fStride != stride ||
        array->fOffset != offset) {

        buffer->bind();
        glVertexPointer(size,
			type,
			stride,
			offset);
		array->fAttribPointerIsValid = true;
        array->fVertexBufferID = buffer->bufferID();
        array->fSize = size;
        array->fStride = stride;
        array->fOffset = offset;
    }
}

void GrGLAttribArrayState::disableUnusedArrays(const GrGpuGL* gpu, uint64_t usedMask, bool usingFFVertexArray) {
    int count = fAttribArrayStates.count();
    for (int i = 0; i < count; ++i) {
        if (!(usedMask & 0x1)) {
            if (!fAttribArrayStates[i].fEnableIsValid || fAttribArrayStates[i].fEnabled) 
			{
                glDisableVertexAttribArray(i);
                fAttribArrayStates[i].fEnableIsValid = true;
                fAttribArrayStates[i].fEnabled = false;
            }
        } else {
        }
        // if the count is greater than 64 then this will become 0 and we will disable arrays 64+.
        usedMask >>= 1;
    }

    // Deal with fixed-function vertex arrays.
    if (gpu->glCaps().fixedFunctionSupport()) {
        if (!usingFFVertexArray) {
            if (!fFixedFunctionVertexArray.fEnableIsValid || fFixedFunctionVertexArray.fEnabled) {
                glDisableClientState(GL_VERTEX_ARRAY);
                fFixedFunctionVertexArray.fEnableIsValid = true;
                fFixedFunctionVertexArray.fEnabled = false;
            }
        } else {
        }
        // When we use fixed function vertex processing we always use the vertex array and none of
        // the other arrays.
        if (!fUnusedFixedFunctionArraysDisabled) 
		{
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_SECONDARY_COLOR_ARRAY);
            glDisableClientState(GL_INDEX_ARRAY);
            glDisableClientState(GL_EDGE_FLAG_ARRAY);
            for (int i = 0; i < gpu->glCaps().maxFixedFunctionTextureCoords(); ++i) 
			{
                glClientActiveTexture(GL_TEXTURE0 + i);
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            }
            fUnusedFixedFunctionArraysDisabled = true;
        }
    } else {
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

GrGLVertexArray::GrGLVertexArray(GrGpuGL* gpu, GLint id, int attribCount)
    : GrResource(gpu, false)
    , fID(id)
    , fAttribArrays(attribCount)
    , fIndexBufferIDIsValid(false) {
}

void GrGLVertexArray::onAbandon() {
    fID = 0;
    INHERITED::onAbandon();
}

void GrGLVertexArray::onRelease() {
    if (0 != fID) {
		glDeleteVertexArrays(1, &fID);
        GPUGL->notifyVertexArrayDelete(fID);
        fID = 0;
    }
    INHERITED::onRelease();
}

GrGLAttribArrayState* GrGLVertexArray::bind() {
    if (0 == fID) {
        return NULL;
    }
    GPUGL->bindVertexArray(fID);
    return &fAttribArrays;
}

GrGLAttribArrayState* GrGLVertexArray::bindWithIndexBuffer(const GrGLIndexBuffer* buffer) {
    GrGLAttribArrayState* state = this->bind();
    if (NULL != state && NULL != buffer) {
        GLuint bufferID = buffer->bufferID();
        if (!fIndexBufferIDIsValid || bufferID != fIndexBufferID) 
		{
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
            fIndexBufferIDIsValid = true;
            fIndexBufferID = bufferID;
        }
    }
    return state;
}

void GrGLVertexArray::notifyIndexBufferDelete(GLuint bufferID) {
    if (fIndexBufferIDIsValid && bufferID == fIndexBufferID) {
        fIndexBufferID = 0;
    }
 }

void GrGLVertexArray::invalidateCachedState() {
    fAttribArrays.invalidate();
    fIndexBufferIDIsValid = false;
}
