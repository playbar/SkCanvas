/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLBufferImpl.h"
#include "GrGpuGL.h"

// GL_STREAM_DRAW triggers an optimization in Chromium's GPU process where a client's vertex buffer
// objects are implemented as client-side-arrays on tile-deferred architectures.

GrGLBufferImpl::GrGLBufferImpl( const Desc& desc, GLenum bufferType)
    : fDesc(desc)
    , fBufferType(bufferType)
    , fLockPtr(NULL) 
{
    if (0 == desc.fID) 
	{
        fCPUData = sk_malloc_flags(desc.fSizeInBytes, SK_MALLOC_THROW);
    } 
	else 
	{
        fCPUData = NULL;
    }
}

void GrGLBufferImpl::release(GrGpuGL* gpu) 
{
    // make sure we've not been abandoned or already released
    if (NULL != fCPUData) 
	{
        sk_free(fCPUData);
        fCPUData = NULL;
    } 
	else if (fDesc.fID && !fDesc.fIsWrapped)
	{
        glDeleteBuffers(1, &fDesc.fID);
        if (GL_ARRAY_BUFFER == fBufferType)
		{
            gpu->notifyVertexBufferDelete(fDesc.fID);
        } 
		else 
		{
            gpu->notifyIndexBufferDelete(fDesc.fID);
        }
        fDesc.fID = 0;
    }
    fLockPtr = NULL;
}

void GrGLBufferImpl::abandon() 
{
    fDesc.fID = 0;
    fLockPtr = NULL;
    sk_free(fCPUData);
    fCPUData = NULL;
}

void GrGLBufferImpl::bind(GrGpuGL* gpu) const
{
    if (GL_ARRAY_BUFFER == fBufferType) {
        gpu->bindVertexBuffer(fDesc.fID);
    } else {
        gpu->bindIndexBufferAndDefaultVertexArray(fDesc.fID);
    }
}

void* GrGLBufferImpl::lock(GrGpuGL* gpu)
{
    if (0 == fDesc.fID)
	{
        fLockPtr = fCPUData;
    } 
	else if (gpu->caps()->bufferLockSupport()) 
	{
        this->bind(gpu);
        // Let driver know it can discard the old data
        glBufferData(fBufferType,
                                (GLsizeiptr) fDesc.fSizeInBytes,
                                NULL,
								fDesc.fDynamic ? GL_STREAM_DRAW : GL_STATIC_DRAW);
		fLockPtr = glMapBuffer(fBufferType, GL_WRITE_ONLY);
    }
    return fLockPtr;
}

void GrGLBufferImpl::unlock(GrGpuGL* gpu) 
{
    if (0 != fDesc.fID) 
	{
        this->bind(gpu);
       glUnmapBuffer(fBufferType);
    }
    fLockPtr = NULL;
}

bool GrGLBufferImpl::isLocked() const 
{
    return NULL != fLockPtr;
}

bool GrGLBufferImpl::updateData(GrGpuGL* gpu, const void* src, size_t srcSizeInBytes) {
    if (srcSizeInBytes > fDesc.fSizeInBytes) 
	{
        return false;
    }
    if (0 == fDesc.fID)
	{
        memcpy(fCPUData, src, srcSizeInBytes);
        return true;
    }
    this->bind(gpu);
	GLenum usage = fDesc.fDynamic ? GL_STREAM_DRAW : GL_STATIC_DRAW;

    // Note that we're cheating on the size here. Currently no methods
    // allow a partial update that preserves contents of non-updated
    // portions of the buffer (lock() does a glBufferData(..size, NULL..))
    bool doSubData = false;

    if (doSubData) 
	{
        // The workaround is to do a glBufferData followed by glBufferSubData.
        // Chromium's command buffer may turn a glBufferSubData where the size
        // exactly matches the buffer size into a glBufferData. So we tack 1
        // extra byte onto the glBufferData.
        glBufferData(fBufferType, srcSizeInBytes + 1, NULL, usage);
        glBufferSubData(fBufferType, 0, srcSizeInBytes, src);
    } 
	else 
	{
        glBufferData(fBufferType, srcSizeInBytes, src, usage);
    }

    return true;
}

