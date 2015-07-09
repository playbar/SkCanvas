/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrTypesPriv_DEFINED
#define GrTypesPriv_DEFINED

#include "GrTypes.h"
#include "SkTArray.h"

/**
 * Types of shader-language-specific boxed variables we can create. (Currently only GrGLShaderVars,
 * but should be applicable to other shader languages.)
 */
enum GrSLType 
{
    kVoid_GrSLType,
    kFloat_GrSLType,
    kVec2f_GrSLType,
    kVec3f_GrSLType,
    kVec4f_GrSLType,
    kMat33f_GrSLType,
    kMat44f_GrSLType,
    kSampler2D_GrSLType,
    kLast_GrSLType = kSampler2D_GrSLType,
	kGrSLTypeCount
};

/**
 * Gets the vector size of the SLType. Returns -1 for void, matrices, and samplers.
 */
static inline int GrSLTypeVectorCount(GrSLType type) 
{
    static const int kCounts[] = { -1, 1, 2, 3, 4, -1, -1, -1 };
    return kCounts[type];

    GR_STATIC_ASSERT(0 == kVoid_GrSLType);
    GR_STATIC_ASSERT(1 == kFloat_GrSLType);
    GR_STATIC_ASSERT(2 == kVec2f_GrSLType);
    GR_STATIC_ASSERT(3 == kVec3f_GrSLType);
    GR_STATIC_ASSERT(4 == kVec4f_GrSLType);
    GR_STATIC_ASSERT(5 == kMat33f_GrSLType);
    GR_STATIC_ASSERT(6 == kMat44f_GrSLType);
    GR_STATIC_ASSERT(7 == kSampler2D_GrSLType);
    GR_STATIC_ASSERT(GR_ARRAY_COUNT(kCounts) == kGrSLTypeCount);
}

/** Return the type enum for a vector of floats of length n (1..4),
 e.g. 1 -> kFloat_GrSLType, 2 -> kVec2_GrSLType, ... */
static inline GrSLType GrSLFloatVectorType(int count)
{
    return (GrSLType)(count);

    GR_STATIC_ASSERT(kFloat_GrSLType == 1);
    GR_STATIC_ASSERT(kVec2f_GrSLType == 2);
    GR_STATIC_ASSERT(kVec3f_GrSLType == 3);
    GR_STATIC_ASSERT(kVec4f_GrSLType == 4);
}

/**
 * Types used to describe format of vertices in arrays.
  */
enum GrVertexAttribType 
{
    kFloat_GrVertexAttribType = 0,
    kVec2f_GrVertexAttribType,
    kVec3f_GrVertexAttribType,
    kVec4f_GrVertexAttribType,
    kVec4ub_GrVertexAttribType,   // vector of 4 unsigned bytes, e.g. colors
    kLast_GrVertexAttribType = kVec4ub_GrVertexAttribType,
	kGrVertexAttribTypeCount
};

/**
 * Returns the vector size of the type.
 */
static inline int GrVertexAttribTypeVectorCount(GrVertexAttribType type)
{
	static const int kCounts[] = { 1, 2, 3, 4, 4 };
	return kCounts[type];

}

/**
 * Returns the size of the attrib type in bytes.
 */
static inline size_t GrVertexAttribTypeSize(GrVertexAttribType type)
{
    static const size_t kSizes[] = 
	{
        sizeof(float),          // kFloat_GrVertexAttribType
        2*sizeof(float),        // kVec2f_GrVertexAttribType
        3*sizeof(float),        // kVec3f_GrVertexAttribType
        4*sizeof(float),        // kVec4f_GrVertexAttribType
        4*sizeof(char)          // kVec4ub_GrVertexAttribType
    };
    return kSizes[type];

}

/**
 * Semantic bindings for vertex attributes. kEffect means that the attribute is input to a GrEffect.
 * Each binding other than kEffect may not appear more than once in the current set of attributes.
 * kPosition must be appear for exactly one attribute.
 */
enum GrVertexAttribBinding 
{
    kPosition_GrVertexAttribBinding,    // required, must have vector count of 2
    kLocalCoord_GrVertexAttribBinding,  // must have vector count of 2
    kColor_GrVertexAttribBinding,       // must have vector count of 4
    kCoverage_GrVertexAttribBinding,    // must have vector count of 4

    kLastFixedFunction_GrVertexAttribBinding = kCoverage_GrVertexAttribBinding,

    kEffect_GrVertexAttribBinding,      // vector length must agree with
                                        // GrEffect::vertexAttribType() for each effect input to
                                        // which the attribute is mapped by GrDrawState::setEffect()
    kLast_GrVertexAttribBinding = kEffect_GrVertexAttribBinding,
	kGrVertexAttribBindingCnt
};

static const int kGrFixedFunctionVertexAttribBindingCnt = kLastFixedFunction_GrVertexAttribBinding + 1;

static inline int GrFixedFunctionVertexAttribVectorCount(GrVertexAttribBinding binding)
{
    static const int kVecCounts[] = { 2, 2, 4, 4 };
    return kVecCounts[binding];
}

struct GrVertexAttrib 
{
    inline void set(GrVertexAttribType type, size_t offset, GrVertexAttribBinding binding) {
        fType = type;
        fOffset = offset;
        fBinding = binding;
    }
    bool operator==(const GrVertexAttrib& other) const 
	{
        return fType == other.fType && fOffset == other.fOffset && fBinding == other.fBinding;
    };
    bool operator!=(const GrVertexAttrib& other) const { return !(*this == other); }

    GrVertexAttribType      fType;
    size_t                  fOffset;
    GrVertexAttribBinding   fBinding;
};

template <int N> class GrVertexAttribArray : public SkSTArray<N, GrVertexAttrib, true> {};

#endif
