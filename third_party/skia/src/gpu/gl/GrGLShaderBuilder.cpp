/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gl/GrGLShaderBuilder.h"
#include "gl/GrGLProgram.h"
#include "gl/GrGLUniformHandle.h"
#include "GrCoordTransform.h"
#include "GrDrawEffect.h"
#include "GrGpuGL.h"
#include "GrTexture.h"
#include "SkRTConf.h"
#include "SkTrace.h"

// number of each input/output type in a single allocation block
static const int kVarsPerBlock = 8;

// except FS outputs where we expect 2 at most.
static const int kMaxFSOutputs = 2;

// ES2 FS only guarantees mediump and lowp support
static const GrGLShaderVar::Precision kDefaultFragmentPrecision = GrGLShaderVar::kMedium_Precision;

typedef GrGLUniformManager::UniformHandle UniformHandle;

SK_CONF_DECLARE(bool, c_PrintShaders, "gpu.printShaders", false,
                "Print the source code for all shaders generated.");

///////////////////////////////////////////////////////////////////////////////

namespace {

inline const char* color_attribute_name() { return "aColor"; }
inline const char* coverage_attribute_name() { return "aCoverage"; }
inline const char* declared_color_output_name() { return "fsColorOut"; }
inline const char* dual_source_output_name() { return "dualSourceOut"; }
inline const char* sample_function_name(GrSLType type, GrGLSLGeneration glslGen) {
    if (kVec2f_GrSLType == type) {
        return glslGen >= k130_GrGLSLGeneration ? "texture" : "texture2D";
    } else {
        return glslGen >= k130_GrGLSLGeneration ? "textureProj" : "texture2DProj";
    }
}

void append_texture_lookup(SkString* out,
                           GrGpuGL* gpu,
                           const char* samplerName,
                           const char* coordName,
                           uint32_t configComponentMask,
                           const char* swizzle,
                           GrSLType varyingType = kVec2f_GrSLType) {
    out->appendf("%s(%s, %s)",
                 sample_function_name(varyingType, gpu->glslGeneration()),
                 samplerName,
                 coordName);

    char mangledSwizzle[5];

    // The swizzling occurs using texture params instead of shader-mangling if ARB_texture_swizzle
    // is available.
    if (!gpu->glCaps().textureSwizzleSupport() &&
        (kA_GrColorComponentFlag == configComponentMask)) {
        char alphaChar = gpu->glCaps().textureRedSupport() ? 'r' : 'a';
        int i;
        for (i = 0; '\0' != swizzle[i]; ++i) {
            mangledSwizzle[i] = alphaChar;
        }
        mangledSwizzle[i] ='\0';
        swizzle = mangledSwizzle;
    }
    // For shader prettiness we omit the swizzle rather than appending ".rgba".
    if (memcmp(swizzle, "rgba", 4)) {
        out->appendf(".%s", swizzle);
    }
}

}

static const char kDstCopyColorName[] = "_dstColor";

///////////////////////////////////////////////////////////////////////////////

GrGLShaderBuilder::GrGLShaderBuilder(GrGpuGL* gpu,
                                     GrGLUniformManager& uniformManager,
                                     const GrGLProgramDesc& desc)
    : fGpu(gpu)
    , fUniformManager(uniformManager)
    , fFSFeaturesAddedMask(0)
    , fFSInputs(kVarsPerBlock)
    , fFSOutputs(kMaxFSOutputs)
    , fUniforms(kVarsPerBlock)
    , fSetupFragPosition(false)
    , fHasCustomColorOutput(false)
    , fHasSecondaryOutput(false)
    , fTopLeftFragPosRead(kTopLeftFragPosRead_FragPosKey == desc.getHeader().fFragPosKey) {

    const GrGLProgramDesc::KeyHeader& header = desc.getHeader();

    // Emit code to read the dst copy textue if necessary.
    if (kNoDstRead_DstReadKey != header.fDstReadKey &&
        GrGLCaps::kNone_FBFetchType == fGpu->glCaps().fbFetchType()) {
        bool topDown = SkToBool(kTopLeftOrigin_DstReadKeyBit & header.fDstReadKey);
        const char* dstCopyTopLeftName;
        const char* dstCopyCoordScaleName;
        uint32_t configMask;
        if (SkToBool(kUseAlphaConfig_DstReadKeyBit & header.fDstReadKey)) {
            configMask = kA_GrColorComponentFlag;
        } else {
            configMask = kRGBA_GrColorComponentFlags;
        }
        fDstCopySamplerUniform = this->addUniform(kFragment_Visibility,
                                                  kSampler2D_GrSLType,
                                                  "DstCopySampler");
        fDstCopyTopLeftUniform = this->addUniform(kFragment_Visibility,
                                                  kVec2f_GrSLType,
                                                  "DstCopyUpperLeft",
                                                  &dstCopyTopLeftName);
        fDstCopyScaleUniform     = this->addUniform(kFragment_Visibility,
                                                    kVec2f_GrSLType,
                                                    "DstCopyCoordScale",
                                                    &dstCopyCoordScaleName);
        const char* fragPos = this->fragmentPosition();
        this->fsCodeAppend("\t// Read color from copy of the destination.\n");
        this->fsCodeAppendf("\tvec2 _dstTexCoord = (%s.xy - %s) * %s;\n",
                            fragPos, dstCopyTopLeftName, dstCopyCoordScaleName);
        if (!topDown) {
            this->fsCodeAppend("\t_dstTexCoord.y = 1.0 - _dstTexCoord.y;\n");
        }
        this->fsCodeAppendf("\tvec4 %s = ", kDstCopyColorName);
        append_texture_lookup(&fFSCode,
                              fGpu,
                              this->getUniformCStr(fDstCopySamplerUniform),
                              "_dstTexCoord",
                              configMask,
                              "rgba");
        this->fsCodeAppend(";\n\n");
    }

    if (GrGLProgramDesc::kUniform_ColorInput == header.fColorInput) {
        const char* name;
        fColorUniform = this->addUniform(GrGLShaderBuilder::kFragment_Visibility,
                                         kVec4f_GrSLType, "Color", &name);
        fInputColor = GrGLSLExpr4(name);
    } else if (GrGLProgramDesc::kSolidWhite_ColorInput == header.fColorInput) {
        fInputColor = GrGLSLExpr4(1);
    } else if (GrGLProgramDesc::kTransBlack_ColorInput == header.fColorInput) {
        fInputColor = GrGLSLExpr4(0);
    }

    if (GrGLProgramDesc::kUniform_ColorInput == header.fCoverageInput) {
        const char* name;
        fCoverageUniform = this->addUniform(GrGLShaderBuilder::kFragment_Visibility,
                                            kVec4f_GrSLType, "Coverage", &name);
        fInputCoverage = GrGLSLExpr4(name);
    } else if (GrGLProgramDesc::kSolidWhite_ColorInput == header.fCoverageInput) {
        fInputCoverage = GrGLSLExpr4(1);
    } else if (GrGLProgramDesc::kTransBlack_ColorInput == header.fCoverageInput) {
        fInputCoverage = GrGLSLExpr4(0);
    }

    if (k110_GrGLSLGeneration != fGpu->glslGeneration()) {
        fFSOutputs.push_back().set(kVec4f_GrSLType,
                                   GrGLShaderVar::kOut_TypeModifier,
                                   declared_color_output_name());
        fHasCustomColorOutput = true;
    }
}

bool GrGLShaderBuilder::enableFeature(GLSLFeature feature) {
    switch (feature) {
        case kStandardDerivatives_GLSLFeature:
            if (!fGpu->glCaps().shaderDerivativeSupport()) {
                return false;
            }

            return true;
        default:
            GrCrash("Unexpected GLSLFeature requested.");
            return false;
    }
}

bool GrGLShaderBuilder::enablePrivateFeature(GLSLPrivateFeature feature) {
    switch (feature) {
        case kFragCoordConventions_GLSLPrivateFeature:
            if (!fGpu->glCaps().fragCoordConventionsSupport()) {
                return false;
            }
            if (fGpu->glslGeneration() < k150_GrGLSLGeneration) {
                this->addFSFeature(1 << kFragCoordConventions_GLSLPrivateFeature,
                                   "GL_ARB_fragment_coord_conventions");
            }
            return true;
        case kEXTShaderFramebufferFetch_GLSLPrivateFeature:
            if (GrGLCaps::kEXT_FBFetchType != fGpu->glCaps().fbFetchType()) {
                return false;
            }
            this->addFSFeature(1 << kEXTShaderFramebufferFetch_GLSLPrivateFeature,
                               "GL_EXT_shader_framebuffer_fetch");
            return true;
        case kNVShaderFramebufferFetch_GLSLPrivateFeature:
            if (GrGLCaps::kNV_FBFetchType != fGpu->glCaps().fbFetchType()) {
                return false;
            }
            this->addFSFeature(1 << kNVShaderFramebufferFetch_GLSLPrivateFeature,
                               "GL_NV_shader_framebuffer_fetch");
            return true;
        default:
            GrCrash("Unexpected GLSLPrivateFeature requested.");
            return false;
    }
}

void GrGLShaderBuilder::addFSFeature(uint32_t featureBit, const char* extensionName) {
    if (!(featureBit & fFSFeaturesAddedMask)) {
        fFSExtensions.appendf("#extension %s: require\n", extensionName);
        fFSFeaturesAddedMask |= featureBit;
    }
}

void GrGLShaderBuilder::nameVariable(SkString* out, char prefix, const char* name) {
    if ('\0' == prefix) {
        *out = name;
    } else {
        out->printf("%c%s", prefix, name);
    }
    if (fCodeStage.inStageCode()) {
        if (out->endsWith('_')) {
            // Names containing "__" are reserved.
            out->append("x");
        }
        out->appendf("_Stage%d", fCodeStage.stageIndex());
    }
}

const char* GrGLShaderBuilder::dstColor() {
    if (fCodeStage.inStageCode()) {
        const GrEffectRef& effect = *fCodeStage.effectStage()->getEffect();
        if (!effect->willReadDstColor()) {
            GrDebugCrash("GrGLEffect asked for dst color but its generating GrEffect "
                         "did not request access.");
            return "";
        }
    }
    static const char kFBFetchColorName[] = "gl_LastFragData[0]";
    GrGLCaps::FBFetchType fetchType = fGpu->glCaps().fbFetchType();
    if (GrGLCaps::kEXT_FBFetchType == fetchType) {
        SkAssertResult(this->enablePrivateFeature(kEXTShaderFramebufferFetch_GLSLPrivateFeature));
        return kFBFetchColorName;
    } else if (GrGLCaps::kNV_FBFetchType == fetchType) {
        SkAssertResult(this->enablePrivateFeature(kNVShaderFramebufferFetch_GLSLPrivateFeature));
        return kFBFetchColorName;
    } else if (fDstCopySamplerUniform.isValid()) {
        return kDstCopyColorName;
    } else {
        return "";
    }
}

void GrGLShaderBuilder::appendTextureLookup(SkString* out,
                                            const GrGLShaderBuilder::TextureSampler& sampler,
                                            const char* coordName,
                                            GrSLType varyingType) const {
    append_texture_lookup(out,
                          fGpu,
                          this->getUniformCStr(sampler.samplerUniform()),
                          coordName,
                          sampler.configComponentMask(),
                          sampler.swizzle(),
                          varyingType);
}

void GrGLShaderBuilder::fsAppendTextureLookup(const GrGLShaderBuilder::TextureSampler& sampler,
                                              const char* coordName,
                                              GrSLType varyingType) {
    this->appendTextureLookup(&fFSCode, sampler, coordName, varyingType);
}

void GrGLShaderBuilder::fsAppendTextureLookupAndModulate(
                                            const char* modulation,
                                            const GrGLShaderBuilder::TextureSampler& sampler,
                                            const char* coordName,
                                            GrSLType varyingType) {
    SkString lookup;
    this->appendTextureLookup(&lookup, sampler, coordName, varyingType);
    fFSCode.append((GrGLSLExpr4(modulation) * GrGLSLExpr4(lookup)).c_str());
}

GrGLShaderBuilder::DstReadKey GrGLShaderBuilder::KeyForDstRead(const GrTexture* dstCopy,
                                                               const GrGLCaps& caps) {
    uint32_t key = kYesDstRead_DstReadKeyBit;
    if (GrGLCaps::kNone_FBFetchType != caps.fbFetchType()) {
        return key;
    }
    if (!caps.textureSwizzleSupport() && GrPixelConfigIsAlphaOnly(dstCopy->config())) {
        // The fact that the config is alpha-only must be considered when generating code.
        key |= kUseAlphaConfig_DstReadKeyBit;
    }
    if (kTopLeft_GrSurfaceOrigin == dstCopy->origin()) {
        key |= kTopLeftOrigin_DstReadKeyBit;
    }
    return static_cast<DstReadKey>(key);
}

GrGLShaderBuilder::FragPosKey GrGLShaderBuilder::KeyForFragmentPosition(const GrRenderTarget* dst,
                                                                        const GrGLCaps&) {
    if (kTopLeft_GrSurfaceOrigin == dst->origin()) {
        return kTopLeftFragPosRead_FragPosKey;
    } else {
        return kBottomLeftFragPosRead_FragPosKey;
    }
}


const GLenum* GrGLShaderBuilder::GetTexParamSwizzle(GrPixelConfig config, const GrGLCaps& caps) {
    if (caps.textureSwizzleSupport() && GrPixelConfigIsAlphaOnly(config)) {
        if (caps.textureRedSupport()) {
            static const GLenum gRedSmear[] = { GL_RED, GL_RED, GL_RED, GL_RED };
            return gRedSmear;
        } else {
            static const GLenum gAlphaSmear[] = { GL_ALPHA, GL_ALPHA,
                                                    GL_ALPHA, GL_ALPHA };
            return gAlphaSmear;
        }
    } else {
        static const GLenum gStraight[] = { GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA };
        return gStraight;
    }
}

GrGLUniformManager::UniformHandle GrGLShaderBuilder::addUniformArray(uint32_t visibility,
                                                                     GrSLType type,
                                                                     const char* name,
                                                                     int count,
                                                                     const char** outName) {
    SkDEBUGCODE(static const uint32_t kVisibilityMask = kVertex_Visibility | kFragment_Visibility);

    BuilderUniform& uni = fUniforms.push_back();
    UniformHandle h = GrGLUniformManager::UniformHandle::CreateFromUniformIndex(fUniforms.count() - 1);
    SkDEBUGCODE(UniformHandle h2 =)
    fUniformManager.appendUniform(type, count);
    // We expect the uniform manager to initially have no uniforms and that all uniforms are added
    // by this function. Therefore, the handles should match.
    uni.fVariable.setType(type);
    uni.fVariable.setTypeModifier(GrGLShaderVar::kUniform_TypeModifier);
    this->nameVariable(uni.fVariable.accessName(), 'u', name);
    uni.fVariable.setArrayCount(count);
    uni.fVisibility = visibility;

    // If it is visible in both the VS and FS, the precision must match.
    // We declare a default FS precision, but not a default VS. So set the var
    // to use the default FS precision.
    if ((kVertex_Visibility | kFragment_Visibility) == visibility) {
        // the fragment and vertex precisions must match
        uni.fVariable.setPrecision(kDefaultFragmentPrecision);
    }

    if (NULL != outName) {
        *outName = uni.fVariable.c_str();
    }

    return h;
}

SkString GrGLShaderBuilder::ensureFSCoords2D(const TransformedCoordsArray& coords, int index) {
    if (kVec3f_GrSLType != coords[index].type()) {
        return coords[index].getName();
    }

    SkString coords2D("coords2D");
    if (0 != index) {
        coords2D.appendf("_%i", index);
    }
    this->fsCodeAppendf("\tvec2 %s = %s.xy / %s.z;",
                        coords2D.c_str(), coords[index].c_str(), coords[index].c_str());
    return coords2D;
}

const char* GrGLShaderBuilder::fragmentPosition() {
    if (fCodeStage.inStageCode()) {
        const GrEffectRef& effect = *fCodeStage.effectStage()->getEffect();
        if (!effect->willReadFragmentPosition()) {
            GrDebugCrash("GrGLEffect asked for frag position but its generating GrEffect "
                         "did not request access.");
            return "";
        }
    }
    if (fTopLeftFragPosRead) {
        if (!fSetupFragPosition) {
            fFSInputs.push_back().set(kVec4f_GrSLType,
                                      GrGLShaderVar::kIn_TypeModifier,
                                      "gl_FragCoord",
                                      GrGLShaderVar::kDefault_Precision);
            fSetupFragPosition = true;
        }
        return "gl_FragCoord";
    } else if (fGpu->glCaps().fragCoordConventionsSupport()) {
        if (!fSetupFragPosition) {
            SkAssertResult(this->enablePrivateFeature(kFragCoordConventions_GLSLPrivateFeature));
            fFSInputs.push_back().set(kVec4f_GrSLType,
                                      GrGLShaderVar::kIn_TypeModifier,
                                      "gl_FragCoord",
                                      GrGLShaderVar::kDefault_Precision,
                                      GrGLShaderVar::kUpperLeft_Origin);
            fSetupFragPosition = true;
        }
        return "gl_FragCoord";
    } else {
        static const char* kCoordName = "fragCoordYDown";
        if (!fSetupFragPosition) {
            // temporarily change the stage index because we're inserting non-stage code.
            CodeStage::AutoStageRestore csar(&fCodeStage, NULL);

            const char* rtHeightName;

            fRTHeightUniform = this->addUniform(kFragment_Visibility,
                                                kFloat_GrSLType,
                                                "RTHeight",
                                                &rtHeightName);

            this->fFSCode.prependf("\tvec4 %s = vec4(gl_FragCoord.x, %s - gl_FragCoord.y, gl_FragCoord.zw);\n",
                                   kCoordName, rtHeightName);
            fSetupFragPosition = true;
        }
        return kCoordName;
    }
}

void GrGLShaderBuilder::fsEmitFunction(GrSLType returnType,
                                       const char* name,
                                       int argCnt,
                                       const GrGLShaderVar* args,
                                       const char* body,
                                       SkString* outName) {
    fFSFunctions.append(GrGLSLTypeString(returnType));
    this->nameVariable(outName, '\0', name);
    fFSFunctions.appendf(" %s", outName->c_str());
    fFSFunctions.append("(");
    for (int i = 0; i < argCnt; ++i) {
        args[i].appendDecl(this->ctxInfo(), &fFSFunctions);
        if (i < argCnt - 1) {
            fFSFunctions.append(", ");
        }
    }
    fFSFunctions.append(") {\n");
    fFSFunctions.append(body);
    fFSFunctions.append("}\n\n");
}

namespace {

inline void append_default_precision_qualifier(GrGLShaderVar::Precision p,
                                               SkString* str) {
    // Desktop GLSL has added precision qualifiers but they don't do anything.
    {
        switch (p) {
            case GrGLShaderVar::kHigh_Precision:
                str->append("precision highp float;\n");
                break;
            case GrGLShaderVar::kMedium_Precision:
                str->append("precision mediump float;\n");
                break;
            case GrGLShaderVar::kLow_Precision:
                str->append("precision lowp float;\n");
                break;
            case GrGLShaderVar::kDefault_Precision:
                GrCrash("Default precision now allowed.");
            default:
                GrCrash("Unknown precision value.");
        }
    }
}
}

void GrGLShaderBuilder::appendDecls(const VarArray& vars, SkString* out) const {
    for (int i = 0; i < vars.count(); ++i) {
        vars[i].appendDecl(this->ctxInfo(), out);
        out->append(";\n");
    }
}

void GrGLShaderBuilder::appendUniformDecls(ShaderVisibility visibility,
                                           SkString* out) const {
    for (int i = 0; i < fUniforms.count(); ++i) {
        if (fUniforms[i].fVisibility & visibility) {
            fUniforms[i].fVariable.appendDecl(this->ctxInfo(), out);
            out->append(";\n");
        }
    }
}

void GrGLShaderBuilder::createAndEmitEffects(GrGLProgramEffectsBuilder* programEffectsBuilder,
                                             const GrEffectStage* effectStages[],
                                             const EffectKey effectKeys[],
                                             int effectCnt,
                                             GrGLSLExpr4* fsInOutColor) {
    bool effectEmitted = false;

    GrGLSLExpr4 inColor = *fsInOutColor;
    GrGLSLExpr4 outColor;

    for (int e = 0; e < effectCnt; ++e) {
        const GrEffectStage& stage = *effectStages[e];

        CodeStage::AutoStageRestore csar(&fCodeStage, &stage);

        if (inColor.isZeros()) {
            SkString inColorName;

            // Effects have no way to communicate zeros, they treat an empty string as ones.
            this->nameVariable(&inColorName, '\0', "input");
            this->fsCodeAppendf("\tvec4 %s = %s;\n", inColorName.c_str(), inColor.c_str());
            inColor = inColorName;
        }

        // create var to hold stage result
        SkString outColorName;
        this->nameVariable(&outColorName, '\0', "output");
        this->fsCodeAppendf("\tvec4 %s;\n", outColorName.c_str());
        outColor = outColorName;


        programEffectsBuilder->emitEffect(stage,
                                          effectKeys[e],
                                          outColor.c_str(),
                                          inColor.isOnes() ? NULL : inColor.c_str(),
                                          fCodeStage.stageIndex());

        inColor = outColor;
        effectEmitted = true;
    }

    if (effectEmitted) {
        *fsInOutColor = outColor;
    }
}

const char* GrGLShaderBuilder::getColorOutputName() const
{
    return fHasCustomColorOutput ? declared_color_output_name() : "gl_FragColor";
}

const char* GrGLShaderBuilder::enableSecondaryOutput() {
    if (!fHasSecondaryOutput) {
        fFSOutputs.push_back().set(kVec4f_GrSLType,
                                   GrGLShaderVar::kOut_TypeModifier,
                                   dual_source_output_name());
        fHasSecondaryOutput = true;
    }
    return dual_source_output_name();
}


bool GrGLShaderBuilder::finish(GLuint* outProgramId) 
{
    SK_TRACE_EVENT0("GrGLShaderBuilder::finish");

    GLuint programId = 0;
    programId = glCreateProgram();
    if (!programId) {
        return false;
    }

    if (!this->compileAndAttachShaders(programId)) 
	{
        glDeleteProgram(programId);
        return false;
    }

    this->bindProgramLocations(programId);
    if (fUniformManager.isUsingBindUniform()) {
      fUniformManager.getUniformLocations(programId, fUniforms);
    }

    glLinkProgram(programId);

    // Calling GetProgramiv is expensive in Chromium. Assume success in release builds.
    bool checkLinked = !fGpu->ctxInfo().isChromium();
#ifdef SK_DEBUG
    checkLinked = true;
#endif
    if (checkLinked) {
        GLint linked = 0;
        glGetProgramiv(programId, GL_LINK_STATUS, &linked);
        if (!linked) {
            GLint infoLen = 0;
			glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLen);
            SkAutoMalloc log(sizeof(char)*(infoLen+1));  // outside if for debugger
            if (infoLen > 0) {
                // retrieve length even though we don't need it to workaround
                // bug in chrome cmd buffer param validation.
                GLsizei length = 0;
                glGetProgramInfoLog(programId,
                                          infoLen+1,
                                          &length,
                                          (char*)log.get());
                GrPrintf((char*)log.get());
            }
            glDeleteProgram(programId);
            return false;
        }
    }

    if (!fUniformManager.isUsingBindUniform())
	{
      fUniformManager.getUniformLocations(programId, fUniforms);
    }
    *outProgramId = programId;
    return true;
}

// Compiles a GL shader, attaches it to a program, and releases the shader's reference.
// (That way there's no need to hang on to the GL shader id and delete it later.)
static bool attach_shader(const GrGLContext& glCtx,
                          GLuint programId,
                          GLenum type,
                          const SkString& shaderSrc)
{
    GLuint shaderId;
    shaderId = glCreateShader(type);
    if (0 == shaderId) {
        return false;
    }

    const GLchar* sourceStr = shaderSrc.c_str();
    GLint sourceLength = static_cast<GLint>(shaderSrc.size());
    glShaderSource(shaderId, 1, &sourceStr, &sourceLength);
    glCompileShader(shaderId);

    // Calling GetShaderiv in Chromium is quite expensive. Assume success in release builds.
    bool checkCompiled = !glCtx.info().isChromium();
#ifdef SK_DEBUG
    checkCompiled = true;
#endif
    if (checkCompiled) {
        GLint compiled = 0;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled);

        if (!compiled) {
            GLint infoLen = 0;
			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLen);
            SkAutoMalloc log(sizeof(char)*(infoLen+1)); // outside if for debugger
            if (infoLen > 0) {
                // retrieve length even though we don't need it to workaround bug in Chromium cmd
                // buffer param validation.
                GLsizei length = 0;
                glGetShaderInfoLog(shaderId, infoLen+1,
                                                 &length, (char*)log.get());
                GrPrintf(shaderSrc.c_str());
                GrPrintf("\n%s", log.get());
            }
            glDeleteShader(shaderId);
            return false;
        }
    }
    if (c_PrintShaders)
	{
        GrPrintf(shaderSrc.c_str());
        GrPrintf("\n");
    }

    glAttachShader(programId, shaderId);
    glDeleteShader(shaderId);
    return true;
}

bool GrGLShaderBuilder::compileAndAttachShaders(GLuint programId) const {
    SkString fragShaderSrc(GrGetGLSLVersionDecl(this->ctxInfo()));
    fragShaderSrc.append(fFSExtensions);
    append_default_precision_qualifier(kDefaultFragmentPrecision,
                                       &fragShaderSrc);
    this->appendUniformDecls(kFragment_Visibility, &fragShaderSrc);
    this->appendDecls(fFSInputs, &fragShaderSrc);
    // We shouldn't have declared outputs on 1.10
    this->appendDecls(fFSOutputs, &fragShaderSrc);
    fragShaderSrc.append(fFSFunctions);
    fragShaderSrc.append("void main() {\n");
    fragShaderSrc.append(fFSCode);
    fragShaderSrc.append("}\n");
    if (!attach_shader(fGpu->glContext(), programId, GL_FRAGMENT_SHADER, fragShaderSrc)) {
        return false;
    }

    return true;
}

void GrGLShaderBuilder::bindProgramLocations(GLuint programId) const {
    //if (fHasCustomColorOutput) {
    //    glBindFragDataLocation(programId, 0, declared_color_output_name());
    //}
    //if (fHasSecondaryOutput) {
    //    glBindFragDataLocationIndexed(programId, 0, 1, dual_source_output_name());
    //}
}

const GrGLContextInfo& GrGLShaderBuilder::ctxInfo() const {
    return fGpu->ctxInfo();
}

////////////////////////////////////////////////////////////////////////////////

GrGLFullShaderBuilder::GrGLFullShaderBuilder(GrGpuGL* gpu,
                                             GrGLUniformManager& uniformManager,
                                             const GrGLProgramDesc& desc)
    : INHERITED(gpu, uniformManager, desc)
    , fDesc(desc)
    , fVSAttrs(kVarsPerBlock)
    , fVSOutputs(kVarsPerBlock)
    , fGSInputs(kVarsPerBlock)
    , fGSOutputs(kVarsPerBlock) {

    const GrGLProgramDesc::KeyHeader& header = fDesc.getHeader();

    fPositionVar = &fVSAttrs.push_back();
    fPositionVar->set(kVec2f_GrSLType, GrGLShaderVar::kAttribute_TypeModifier, "aPosition");
    if (-1 != header.fLocalCoordAttributeIndex) {
        fLocalCoordsVar = &fVSAttrs.push_back();
        fLocalCoordsVar->set(kVec2f_GrSLType,
                             GrGLShaderVar::kAttribute_TypeModifier,
                             "aLocalCoords");
    } else {
        fLocalCoordsVar = fPositionVar;
    }

    const char* viewMName;
    fViewMatrixUniform = this->addUniform(GrGLShaderBuilder::kVertex_Visibility,
                                          kMat33f_GrSLType, "ViewM", &viewMName);

    this->vsCodeAppendf("\tvec3 pos3 = %s * vec3(%s, 1);\n"
                        "\tgl_Position = vec4(pos3.xy, 0, pos3.z);\n",
                        viewMName, fPositionVar->c_str());

    // we output point size in the GS if present
    if (header.fEmitsPointSize
#if GL_EXPERIMENTAL_GS
        && !header.fExperimentalGS
#endif
        ) {
        this->vsCodeAppend("\tgl_PointSize = 1.0;\n");
    }

    if (GrGLProgramDesc::kAttribute_ColorInput == header.fColorInput) {
        this->addAttribute(kVec4f_GrSLType, color_attribute_name());
        const char *vsName, *fsName;
        this->addVarying(kVec4f_GrSLType, "Color", &vsName, &fsName);
        this->vsCodeAppendf("\t%s = %s;\n", vsName, color_attribute_name());
        this->setInputColor(fsName);
    }

    if (GrGLProgramDesc::kAttribute_ColorInput == header.fCoverageInput) {
        this->addAttribute(kVec4f_GrSLType, coverage_attribute_name());
        const char *vsName, *fsName;
        this->addVarying(kVec4f_GrSLType, "Coverage", &vsName, &fsName);
        this->vsCodeAppendf("\t%s = %s;\n", vsName, coverage_attribute_name());
        this->setInputCoverage(fsName);
    }
}

bool GrGLFullShaderBuilder::addAttribute(GrSLType type, const char* name) {
    for (int i = 0; i < fVSAttrs.count(); ++i) {
        const GrGLShaderVar& attr = fVSAttrs[i];
        // if attribute already added, don't add it again
        if (attr.getName().equals(name)) {
            return false;
        }
    }
    fVSAttrs.push_back().set(type,
                             GrGLShaderVar::kAttribute_TypeModifier,
                             name);
    return true;
}

bool GrGLFullShaderBuilder::addEffectAttribute(int attributeIndex,
                                               GrSLType type,
                                               const SkString& name) {
    if (!this->addAttribute(type, name.c_str())) {
        return false;
    }

    fEffectAttributes.push_back().set(attributeIndex, name);
    return true;
}

void GrGLFullShaderBuilder::addVarying(GrSLType type,
                                       const char* name,
                                       const char** vsOutName,
                                       const char** fsInName) {
    fVSOutputs.push_back();
    fVSOutputs.back().setType(type);
    fVSOutputs.back().setTypeModifier(GrGLShaderVar::kVaryingOut_TypeModifier);
    this->nameVariable(fVSOutputs.back().accessName(), 'v', name);

    if (vsOutName) {
        *vsOutName = fVSOutputs.back().getName().c_str();
    }
    // input to FS comes either from VS or GS
    const SkString* fsName;
#if GL_EXPERIMENTAL_GS
    if (fDesc.getHeader().fExperimentalGS) {
        // if we have a GS take each varying in as an array
        // and output as non-array.
        fGSInputs.push_back();
        fGSInputs.back().setType(type);
        fGSInputs.back().setTypeModifier(GrGLShaderVar::kVaryingIn_TypeModifier);
        fGSInputs.back().setUnsizedArray();
        *fGSInputs.back().accessName() = fVSOutputs.back().getName();
        fGSOutputs.push_back();
        fGSOutputs.back().setType(type);
        fGSOutputs.back().setTypeModifier(GrGLShaderVar::kVaryingOut_TypeModifier);
        this->nameVariable(fGSOutputs.back().accessName(), 'g', name);
        fsName = fGSOutputs.back().accessName();
    } else
#endif
    {
        fsName = fVSOutputs.back().accessName();
    }
    this->fsInputAppend().set(type, GrGLShaderVar::kVaryingIn_TypeModifier, *fsName);
    if (fsInName) {
        *fsInName = fsName->c_str();
    }
}

const SkString* GrGLFullShaderBuilder::getEffectAttributeName(int attributeIndex) const {
    const AttributePair* attribEnd = fEffectAttributes.end();
    for (const AttributePair* attrib = fEffectAttributes.begin(); attrib != attribEnd; ++attrib) {
        if (attrib->fIndex == attributeIndex) {
            return &attrib->fName;
        }
    }

    return NULL;
}

GrGLProgramEffects* GrGLFullShaderBuilder::createAndEmitEffects(
        const GrEffectStage* effectStages[],
        const EffectKey effectKeys[],
        int effectCnt,
        GrGLSLExpr4* inOutFSColor) {

    GrGLVertexProgramEffectsBuilder programEffectsBuilder(this, effectCnt);
    this->INHERITED::createAndEmitEffects(&programEffectsBuilder,
                                          effectStages,
                                          effectKeys,
                                          effectCnt,
                                          inOutFSColor);
    return programEffectsBuilder.finish();
}

bool GrGLFullShaderBuilder::compileAndAttachShaders(GLuint programId) const {
    const GrGLContext& glCtx = this->gpu()->glContext();
    SkString vertShaderSrc(GrGetGLSLVersionDecl(this->ctxInfo()));
    this->appendUniformDecls(kVertex_Visibility, &vertShaderSrc);
    this->appendDecls(fVSAttrs, &vertShaderSrc);
    this->appendDecls(fVSOutputs, &vertShaderSrc);
    vertShaderSrc.append("void main() {\n");
    vertShaderSrc.append(fVSCode);
    vertShaderSrc.append("}\n");
    if (!attach_shader(glCtx, programId, GL_VERTEX_SHADER, vertShaderSrc)) {
        return false;
    }

#if GL_EXPERIMENTAL_GS
    if (fDesc.getHeader().fExperimentalGS) {
        SkString geomShaderSrc(GrGetGLSLVersionDecl(this->ctxInfo()));
        geomShaderSrc.append("layout(triangles) in;\n"
                             "layout(triangle_strip, max_vertices = 6) out;\n");
        this->appendDecls(fGSInputs, &geomShaderSrc);
        this->appendDecls(fGSOutputs, &geomShaderSrc);
        geomShaderSrc.append("void main() {\n");
        geomShaderSrc.append("\tfor (int i = 0; i < 3; ++i) {\n"
                             "\t\tgl_Position = gl_in[i].gl_Position;\n");
        if (fDesc.getHeader().fEmitsPointSize) {
            geomShaderSrc.append("\t\tgl_PointSize = 1.0;\n");
        }
        for (int i = 0; i < fGSInputs.count(); ++i) {
            geomShaderSrc.appendf("\t\t%s = %s[i];\n",
                                  fGSOutputs[i].getName().c_str(),
                                  fGSInputs[i].getName().c_str());
        }
        geomShaderSrc.append("\t\tEmitVertex();\n"
                             "\t}\n"
                             "\tEndPrimitive();\n");
        geomShaderSrc.append("}\n");
        if (!attach_shader(glCtx, programId, GL_GEOMETRY_SHADER, geomShaderSrc)) {
            return false;
        }
    }
#endif

    return this->INHERITED::compileAndAttachShaders(programId);
}

void GrGLFullShaderBuilder::bindProgramLocations(GLuint programId) const {
    this->INHERITED::bindProgramLocations(programId);

    const GrGLProgramDesc::KeyHeader& header = fDesc.getHeader();

    // Bind the attrib locations to same values for all shaders
    glBindAttribLocation(programId,
                               header.fPositionAttributeIndex,
                               fPositionVar->c_str());
    if (-1 != header.fLocalCoordAttributeIndex) 
	{
        glBindAttribLocation(programId,
                                   header.fLocalCoordAttributeIndex,
                                   fLocalCoordsVar->c_str());
    }
    if (-1 != header.fColorAttributeIndex) {
        glBindAttribLocation(programId,
                                   header.fColorAttributeIndex,
                                   color_attribute_name());
    }
    if (-1 != header.fCoverageAttributeIndex) {
        glBindAttribLocation(programId,
                                   header.fCoverageAttributeIndex,
                                   coverage_attribute_name());
    }

    const AttributePair* attribEnd = fEffectAttributes.end();
    for (const AttributePair* attrib = fEffectAttributes.begin(); attrib != attribEnd; ++attrib) {
         glBindAttribLocation(programId, attrib->fIndex, attrib->fName.c_str());
    }
}

////////////////////////////////////////////////////////////////////////////////

GrGLFragmentOnlyShaderBuilder::GrGLFragmentOnlyShaderBuilder(GrGpuGL* gpu,
                                                             GrGLUniformManager& uniformManager,
                                                             const GrGLProgramDesc& desc)
    : INHERITED(gpu, uniformManager, desc)
    , fNumTexCoordSets(0) {

}

int GrGLFragmentOnlyShaderBuilder::addTexCoordSets(int count) {
    int firstFreeCoordSet = fNumTexCoordSets;
    fNumTexCoordSets += count;
    return firstFreeCoordSet;
}

GrGLProgramEffects* GrGLFragmentOnlyShaderBuilder::createAndEmitEffects(
        const GrEffectStage* effectStages[],
        const EffectKey effectKeys[],
        int effectCnt,
        GrGLSLExpr4* inOutFSColor) {

    GrGLTexGenProgramEffectsBuilder texGenEffectsBuilder(this, effectCnt);
    this->INHERITED::createAndEmitEffects(&texGenEffectsBuilder,
                                          effectStages,
                                          effectKeys,
                                          effectCnt,
                                          inOutFSColor);
    return texGenEffectsBuilder.finish();
}
