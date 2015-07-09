/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gl/GrGLShaderBuilder.h"
#include "gl/GrGLProgram.h"
#include "gl/GrGLUniformHandle.h"
#include "gl/GrGpuGL.h"
#include "SkMatrix.h"
#include <assert.h>

GrGLUniformManager::GrGLUniformManager(GrGpuGL* gpu) : fGpu(gpu) 
{
	fUsingBindUniform = false;
	//assert(false);
	//fUsingBindUniform = fGpu->glInterface()->BindUniformLocation != NULL;
}

GrGLUniformManager::UniformHandle GrGLUniformManager::appendUniform(GrSLType type, int arrayCount) {
    int idx = fUniforms.count();
    Uniform& uni = fUniforms.push_back();
    uni.fArrayCount = arrayCount;
    uni.fType = type;
    uni.fVSLocation = kUnusedUniform;
    uni.fFSLocation = kUnusedUniform;
    return GrGLUniformManager::UniformHandle::CreateFromUniformIndex(idx);
}

void GrGLUniformManager::setSampler(UniformHandle u, GLint texUnit) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    // FIXME: We still insert a single sampler uniform for every stage. If the shader does not
    // reference the sampler then the compiler may have optimized it out. Uncomment this assert
    // once stages insert their own samplers.
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform1i(uni.fFSLocation, texUnit);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) 
	{
        glUniform1i(uni.fVSLocation, texUnit);
    }
}

void GrGLUniformManager::set1f(UniformHandle u, GLfloat v0) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation)
	{
        glUniform1f(uni.fFSLocation, v0);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform1f(uni.fVSLocation, v0);
    }
}

void GrGLUniformManager::set1fv(UniformHandle u,
                                int arrayCount,
                                const GLfloat v[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    // This assert fires in some instances of the two-pt gradient for its VSParams.
    // Once the uniform manager is responsible for inserting the duplicate uniform
    // arrays in VS and FS driver bug workaround, this can be enabled.
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform1fv(uni.fFSLocation, arrayCount, v);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform1fv(uni.fVSLocation, arrayCount, v);
    }
}

void GrGLUniformManager::set2f(UniformHandle u, GLfloat v0, GLfloat v1) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform2f(uni.fFSLocation, v0, v1);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform2f(uni.fVSLocation, v0, v1);
    }
}

void GrGLUniformManager::set2fv(UniformHandle u,
                                int arrayCount,
                                const GLfloat v[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform2fv(uni.fFSLocation, arrayCount, v);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform2fv(uni.fVSLocation, arrayCount, v);
    }
}

void GrGLUniformManager::set3f(UniformHandle u, GLfloat v0, GLfloat v1, GLfloat v2) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform3f(uni.fFSLocation, v0, v1, v2);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform3f(uni.fVSLocation, v0, v1, v2);
    }
}

void GrGLUniformManager::set3fv(UniformHandle u,
                                int arrayCount,
                                const GLfloat v[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation)
	{
		glUniform3fv(uni.fFSLocation, arrayCount, v);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform3fv(uni.fVSLocation, arrayCount, v);
    }
}

void GrGLUniformManager::set4f(UniformHandle u,
                               GLfloat v0,
                               GLfloat v1,
                               GLfloat v2,
                               GLfloat v3) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform4f(uni.fFSLocation, v0, v1, v2, v3);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform4f(uni.fVSLocation, v0, v1, v2, v3);
    }
}

void GrGLUniformManager::set4fv(UniformHandle u,
                                int arrayCount,
                                const GLfloat v[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
        glUniform4fv(uni.fFSLocation, arrayCount, v);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniform4fv(uni.fVSLocation, arrayCount, v);
    }
}

void GrGLUniformManager::setMatrix3f(UniformHandle u, const GLfloat matrix[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    // TODO: Re-enable this assert once texture matrices aren't forced on all effects
    if (kUnusedUniform != uni.fFSLocation) {
        glUniformMatrix3fv(uni.fFSLocation, 1, false, matrix);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
        glUniformMatrix3fv(uni.fVSLocation, 1, false, matrix);
    }
}

void GrGLUniformManager::setMatrix4f(UniformHandle u, const GLfloat matrix[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
		glUniformMatrix4fv(uni.fFSLocation, 1, false, matrix);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) 
	{
        glUniformMatrix4fv(uni.fVSLocation, 1, false, matrix);
    }
}

void GrGLUniformManager::setMatrix3fv(UniformHandle u,
                                      int arrayCount,
                                      const GLfloat matrices[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
		glUniformMatrix3fv(uni.fFSLocation, arrayCount, false, matrices);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {  
		glUniformMatrix3fv(uni.fVSLocation, arrayCount, false, matrices);
    }
}

void GrGLUniformManager::setMatrix4fv(UniformHandle u,
                                      int arrayCount,
                                      const GLfloat matrices[]) const {
    const Uniform& uni = fUniforms[u.toUniformIndex()];
    if (kUnusedUniform != uni.fFSLocation) {
		glUniformMatrix4fv(uni.fFSLocation, arrayCount, false, matrices);
    }
    if (kUnusedUniform != uni.fVSLocation && uni.fVSLocation != uni.fFSLocation) {
		glUniformMatrix4fv(uni.fVSLocation, arrayCount, false, matrices);
    }
}

void GrGLUniformManager::setSkMatrix(UniformHandle u, const SkMatrix& matrix) const {
    GLfloat mt[] = {
        matrix.get(SkMatrix::kMScaleX),
        matrix.get(SkMatrix::kMSkewY),
        matrix.get(SkMatrix::kMPersp0),
        matrix.get(SkMatrix::kMSkewX),
        matrix.get(SkMatrix::kMScaleY),
        matrix.get(SkMatrix::kMPersp1),
        matrix.get(SkMatrix::kMTransX),
        matrix.get(SkMatrix::kMTransY),
        matrix.get(SkMatrix::kMPersp2),
    };
    this->setMatrix3f(u, mt);
}


void GrGLUniformManager::getUniformLocations(GLuint programID, const BuilderUniformArray& uniforms) {
    int count = fUniforms.count();
    for (int i = 0; i < count; ++i) {
        GLint location;
        // TODO: Move the Xoom uniform array in both FS and VS bug workaround here.
		location = glGetUniformLocation(programID, uniforms[i].fVariable.c_str());
        
        if (GrGLShaderBuilder::kVertex_Visibility & uniforms[i].fVisibility) {
            fUniforms[i].fVSLocation = location;
        }
        if (GrGLShaderBuilder::kFragment_Visibility & uniforms[i].fVisibility) {
            fUniforms[i].fFSLocation = location;
        }
    }
}

const GrGLUniformManager::BuilderUniform&
GrGLUniformManager::getBuilderUniform(const BuilderUniformArray& array, UniformHandle handle) const {
    return array[handle.toUniformIndex()];
}
