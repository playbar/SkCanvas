
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrGLPath.h"
#include "GrGpuGL.h"


namespace {
inline GLubyte verb_to_gl_path_cmd(SkPath::Verb verb) {
    static const GLubyte gTable[] = {
        GL_MOVE_TO,
        GL_LINE_TO,
        GL_QUADRATIC_CURVE_TO,
        0xFF, // conic
        GL_CUBIC_CURVE_TO,
        GL_CLOSE_PATH,
    };
    GR_STATIC_ASSERT(0 == SkPath::kMove_Verb);
    GR_STATIC_ASSERT(1 == SkPath::kLine_Verb);
    GR_STATIC_ASSERT(2 == SkPath::kQuad_Verb);
    GR_STATIC_ASSERT(4 == SkPath::kCubic_Verb);
    GR_STATIC_ASSERT(5 == SkPath::kClose_Verb);

    return gTable[verb];
}

#ifdef SK_DEBUG
inline int num_pts(SkPath::Verb verb) {
    static const int gTable[] = {
        1, // move
        1, // line
        2, // quad
        2, // conic
        3, // cubic
        0, // close
    };
    GR_STATIC_ASSERT(0 == SkPath::kMove_Verb);
    GR_STATIC_ASSERT(1 == SkPath::kLine_Verb);
    GR_STATIC_ASSERT(2 == SkPath::kQuad_Verb);
    GR_STATIC_ASSERT(4 == SkPath::kCubic_Verb);
    GR_STATIC_ASSERT(5 == SkPath::kClose_Verb);

    return gTable[verb];
}
#endif

inline GLenum join_to_gl_join(SkPaint::Join join) {
    static GLenum gSkJoinsToGrGLJoins[] = {
        GL_MITER_REVERT,
        GL_ROUND,
        GL_BEVEL
    };
    return gSkJoinsToGrGLJoins[join];
    GR_STATIC_ASSERT(0 == SkPaint::kMiter_Join);
    GR_STATIC_ASSERT(1 == SkPaint::kRound_Join);
    GR_STATIC_ASSERT(2 == SkPaint::kBevel_Join);
    GR_STATIC_ASSERT(GR_ARRAY_COUNT(gSkJoinsToGrGLJoins) == SkPaint::kJoinCount);
}

inline GLenum cap_to_gl_cap(SkPaint::Cap cap) {
    static GLenum gSkCapsToGrGLCaps[] = {
        GL_FLAT,
        GL_ROUND_NV,
        GL_SQUARE_NV
    };
    return gSkCapsToGrGLCaps[cap];
    GR_STATIC_ASSERT(0 == SkPaint::kButt_Cap);
    GR_STATIC_ASSERT(1 == SkPaint::kRound_Cap);
    GR_STATIC_ASSERT(2 == SkPaint::kSquare_Cap);
    GR_STATIC_ASSERT(GR_ARRAY_COUNT(gSkCapsToGrGLCaps) == SkPaint::kCapCount);
}

}

static const bool kIsWrapped = false; // The constructor creates the GL path object.

GrGLPath::GrGLPath(GrGpuGL* gpu, const SkPath& path, const SkStrokeRec& stroke)
    : INHERITED(gpu, kIsWrapped, path, stroke) {

    fPathID = glGenPathsNV(1);

    SkSTArray<16, GLubyte, true> pathCommands;
    SkSTArray<16, SkPoint, true> pathPoints;

    int verbCnt = fSkPath.countVerbs();
    int pointCnt = fSkPath.countPoints();
    pathCommands.resize_back(verbCnt);
    pathPoints.resize_back(pointCnt);

    // TODO: Direct access to path points since we could pass them on directly.
    fSkPath.getPoints(&pathPoints[0], pointCnt);
    fSkPath.getVerbs(&pathCommands[0], verbCnt);

    SkDEBUGCODE(int numPts = 0);
    for (int i = 0; i < verbCnt; ++i) {
        SkPath::Verb v = static_cast<SkPath::Verb>(pathCommands[i]);
        pathCommands[i] = verb_to_gl_path_cmd(v);
        SkDEBUGCODE(numPts += num_pts(v));
    }

    glPathCommandsNV(fPathID,
                         verbCnt, &pathCommands[0],
                         2 * pointCnt, GL_FLOAT, &pathPoints[0]);

    if (stroke.needToApply())
	{
        glPathParameterfNV(fPathID, GL_PATH_STROKE_WIDTH_NV, SkScalarToFloat(stroke.getWidth()));
        glPathParameterfNV(fPathID, GL_PATH_MITER_LIMIT_NV, SkScalarToFloat(stroke.getMiter()));
        GLenum join = join_to_gl_join(stroke.getJoin());
        glPathParameteriNV(fPathID, GL_PATH_JOIN_STYLE_NV, join);
        GLenum cap = cap_to_gl_cap(stroke.getCap());
        glPathParameteriNV(fPathID, GL_PATH_INITIAL_END_CAP_NV, cap);
        glPathParameteriNV(fPathID, GL_PATH_TERMINAL_END_CAP_NV, cap);

        // FIXME: try to account for stroking, without rasterizing the stroke.
        fBounds.outset(SkScalarToFloat(stroke.getWidth()), SkScalarToFloat(stroke.getWidth()));
    }
}

GrGLPath::~GrGLPath() {
    this->release();
}

void GrGLPath::onRelease() {
    if (0 != fPathID && !this->isWrapped())
	{
        glDeletePathsNV(fPathID, 1);
        fPathID = 0;
    }

    INHERITED::onRelease();
}

void GrGLPath::onAbandon() {
    fPathID = 0;

    INHERITED::onAbandon();
}
