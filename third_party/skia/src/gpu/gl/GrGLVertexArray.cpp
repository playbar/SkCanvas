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
                                                       GLvoid* offset)
{
//    AttribArrayState* array = &fFixedFunctionVertexArray;
//    if (!array->fAttribPointerIsValid ||
//        array->fVertexBufferID != buffer->bufferID() ||
//        array->fSize != size ||
//        array->fStride != stride ||
//        array->fOffset != offset) {
//
//        buffer->bind();
//        glVertexPointer(size,
//			type,
//			stride,
//			offset);
//		array->fAttribPointerIsValid = true;
//        array->fVertexBufferID = buffer->bufferID();
//        array->fSize = size;
//        array->fStride = stride;
//        array->fOffset = offset;
//    }
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
