
/*
 * Copyright 2007 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkPictureFlat.h"
#include "SkPicturePlayback.h"
#include "SkPictureRecord.h"

#include "SkBitmapDevice.h"
#include "SkCanvas.h"
#include "SkChunkAlloc.h"
#include "SkPicture.h"
#include "SkRegion.h"
#include "SkStream.h"
#include "SkTDArray.h"
#include "SkTSearch.h"
#include "SkTime.h"

#include "SkReader32.h"
#include "SkWriter32.h"
#include "SkRTree.h"
#include "SkBBoxHierarchyRecord.h"

#define DUMP_BUFFER_SIZE 65536

//#define ENABLE_TIME_DRAW    // dumps milliseconds for each draw

///////////////////////////////////////////////////////////////////////////////

SkPicture::SkPicture() {
    fRecord = NULL;
    fPlayback = NULL;
    fWidth = fHeight = 0;
}

SkPicture::SkPicture(const SkPicture& src) : INHERITED() {
    fWidth = src.fWidth;
    fHeight = src.fHeight;
    fRecord = NULL;

    /*  We want to copy the src's playback. However, if that hasn't been built
        yet, we need to fake a call to endRecording() without actually calling
        it (since it is destructive, and we don't want to change src).
     */
    if (src.fPlayback) {
        fPlayback = SkNEW_ARGS(SkPicturePlayback, (*src.fPlayback));
    } else if (src.fRecord) {
        // here we do a fake src.endRecording()
        fPlayback = SkNEW_ARGS(SkPicturePlayback, (*src.fRecord));
    } else {
        fPlayback = NULL;
    }
}

SkPicture::~SkPicture() {
    SkSafeUnref(fRecord);
    SkDELETE(fPlayback);
}

void SkPicture::swap(SkPicture& other) {
    SkTSwap(fRecord, other.fRecord);
    SkTSwap(fPlayback, other.fPlayback);
    SkTSwap(fWidth, other.fWidth);
    SkTSwap(fHeight, other.fHeight);
}

SkPicture* SkPicture::clone() const {
    SkPicture* clonedPicture = SkNEW(SkPicture);
    clone(clonedPicture, 1);
    return clonedPicture;
}

void SkPicture::clone(SkPicture* pictures, int count) const {
    SkPictCopyInfo copyInfo;

    for (int i = 0; i < count; i++) {
        SkPicture* clone = &pictures[i];

        clone->fWidth = fWidth;
        clone->fHeight = fHeight;
        clone->fRecord = NULL;

        if (NULL != clone->fRecord) {
            clone->fRecord->unref();
            clone->fRecord = NULL;
        }
        SkDELETE(clone->fPlayback);

        /*  We want to copy the src's playback. However, if that hasn't been built
            yet, we need to fake a call to endRecording() without actually calling
            it (since it is destructive, and we don't want to change src).
         */
        if (fPlayback) {
            clone->fPlayback = SkNEW_ARGS(SkPicturePlayback, (*fPlayback, &copyInfo));
        } else if (fRecord) {
            // here we do a fake src.endRecording()
            clone->fPlayback = SkNEW_ARGS(SkPicturePlayback, (*fRecord, true));
        } else {
            clone->fPlayback = NULL;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

SkCanvas* SkPicture::beginRecording(int width, int height,
                                    uint32_t recordingFlags) {
    if (fPlayback) {
        SkDELETE(fPlayback);
        fPlayback = NULL;
    }

    if (NULL != fRecord) {
        fRecord->unref();
        fRecord = NULL;
    }

    SkBitmap bm;
    bm.setConfig(SkBitmap::kNo_Config, width, height);
    SkAutoTUnref<SkBaseDevice> dev(SkNEW_ARGS(SkBitmapDevice, (bm)));

    // Must be set before calling createBBoxHierarchy
    fWidth = width;
    fHeight = height;

    if (recordingFlags & kOptimizeForClippedPlayback_RecordingFlag) {
        SkBBoxHierarchy* tree = this->createBBoxHierarchy();
        fRecord = SkNEW_ARGS(SkBBoxHierarchyRecord, (recordingFlags, tree, dev));
        tree->unref();
    } else {
        fRecord = SkNEW_ARGS(SkPictureRecord, (recordingFlags, dev));
    }
    fRecord->beginRecording();

    return fRecord;
}

SkBBoxHierarchy* SkPicture::createBBoxHierarchy() const {
    // These values were empirically determined to produce reasonable
    // performance in most cases.
    static const int kRTreeMinChildren = 6;
    static const int kRTreeMaxChildren = 11;

    float aspectRatio = SkScalarDiv(SkIntToScalar(fWidth),
                                       SkIntToScalar(fHeight));
    bool sortDraws = false;  // Do not sort draw calls when bulk loading.

    return SkRTree::Create(kRTreeMinChildren, kRTreeMaxChildren,
                           aspectRatio, sortDraws);
}

SkCanvas* SkPicture::getRecordingCanvas() const {
    // will be null if we are not recording
    return fRecord;
}

void SkPicture::endRecording() {
    if (NULL == fPlayback) {
        if (NULL != fRecord) {
            fRecord->endRecording();
            fPlayback = SkNEW_ARGS(SkPicturePlayback, (*fRecord));
            fRecord->unref();
            fRecord = NULL;
        }
    }
}

void SkPicture::draw(SkCanvas* surface, SkDrawPictureCallback* callback) {
    this->endRecording();
    if (fPlayback) {
        fPlayback->draw(*surface, callback);
    }
}

///////////////////////////////////////////////////////////////////////////////

#include "SkStream.h"

static const char kMagic[] = { 's', 'k', 'i', 'a', 'p', 'i', 'c', 't' };

bool SkPicture::StreamIsSKP(SkStream* stream, SkPictInfo* pInfo) {
    if (NULL == stream) {
        return false;
    }

    // Check magic bytes.
    char magic[sizeof(kMagic)];
    stream->read(magic, sizeof(kMagic));
    if (0 != memcmp(magic, kMagic, sizeof(kMagic))) {
        return false;
    }

    SkPictInfo info;
    if (!stream->read(&info, sizeof(SkPictInfo))) {
        return false;
    }

    if (PICTURE_VERSION != info.fVersion
#ifndef DELETE_THIS_CODE_WHEN_SKPS_ARE_REBUILT_AT_V16_AND_ALL_OTHER_INSTANCES_TOO
        // V16 is backwards compatible with V15
        && PRIOR_PICTURE_VERSION != info.fVersion  // TODO: remove when .skps regenerated
#endif
        ) {
        return false;
    }

    if (pInfo != NULL) {
        *pInfo = info;
    }
    return true;
}

SkPicture::SkPicture(SkPicturePlayback* playback, int width, int height)
    : fPlayback(playback)
    , fRecord(NULL)
    , fWidth(width)
    , fHeight(height) {}

SkPicture* SkPicture::CreateFromStream(SkStream* stream, InstallPixelRefProc proc) {
    SkPictInfo info;

    if (!StreamIsSKP(stream, &info)) {
        return NULL;
    }

    SkPicturePlayback* playback;
    // Check to see if there is a playback to recreate.
    if (stream->readBool()) {
        playback = SkPicturePlayback::CreateFromStream(stream, info, proc);
        if (NULL == playback) {
            return NULL;
        }
    } else {
        playback = NULL;
    }

    return SkNEW_ARGS(SkPicture, (playback, info.fWidth, info.fHeight));
}

void SkPicture::serialize(SkWStream* stream, EncodeBitmap encoder) const {
    SkPicturePlayback* playback = fPlayback;

    if (NULL == playback && fRecord) {
        playback = SkNEW_ARGS(SkPicturePlayback, (*fRecord));
    }

    SkPictInfo info;

    info.fVersion = PICTURE_VERSION;
    info.fWidth = fWidth;
    info.fHeight = fHeight;
    info.fFlags = SkPictInfo::kCrossProcess_Flag;
    // TODO: remove this flag, since we're always float (now)
    info.fFlags |= SkPictInfo::kScalarIsFloat_Flag;

    if (8 == sizeof(void*)) {
        info.fFlags |= SkPictInfo::kPtrIs64Bit_Flag;
    }

    // Write 8 magic bytes to ID this file format.
    stream->write(kMagic, sizeof(kMagic));

    stream->write(&info, sizeof(info));
    if (playback) {
        stream->writeBool(true);
        playback->serialize(stream, encoder);
        // delete playback if it is a local version (i.e. cons'd up just now)
        if (playback != fPlayback) {
            SkDELETE(playback);
        }
    } else {
        stream->writeBool(false);
    }
}

bool SkPicture::willPlayBackBitmaps() const {
    if (!fPlayback) return false;
    return fPlayback->containsBitmaps();
}

#ifdef SK_BUILD_FOR_ANDROID
void SkPicture::abortPlayback() {
    if (NULL == fPlayback) {
        return;
    }
    fPlayback->abort();
}
#endif
