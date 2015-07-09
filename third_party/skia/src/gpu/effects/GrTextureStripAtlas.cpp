
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrTextureStripAtlas.h"
#include "SkPixelRef.h"
#include "SkTSearch.h"
#include "GrTexture.h"

int32_t GrTextureStripAtlas::gCacheCount = 0;

GrTHashTable<GrTextureStripAtlas::AtlasEntry,
                GrTextureStripAtlas::AtlasHashKey, 8>*
                            GrTextureStripAtlas::gAtlasCache = NULL;

GrTHashTable<GrTextureStripAtlas::AtlasEntry, GrTextureStripAtlas::AtlasHashKey, 8>*
GrTextureStripAtlas::GetCache() {

    if (NULL == gAtlasCache) {
        gAtlasCache = SkNEW((GrTHashTable<AtlasEntry, AtlasHashKey, 8>));
    }

    return gAtlasCache;
}

// Remove the specified atlas from the cache
void GrTextureStripAtlas::CleanUp(const GrContext*, void* info) {

    AtlasEntry* entry = static_cast<AtlasEntry*>(info);

    // remove the cache entry
    GetCache()->remove(entry->fKey, entry);

    // remove the actual entry
    SkDELETE(entry);

    if (0 == GetCache()->count()) {
        SkDELETE(gAtlasCache);
        gAtlasCache = NULL;
    }
}

GrTextureStripAtlas* GrTextureStripAtlas::GetAtlas(const GrTextureStripAtlas::Desc& desc) {
    AtlasHashKey key;
    key.setKeyData(desc.asKey());
    AtlasEntry* entry = GetCache()->find(key);
    if (NULL == entry) {
        entry = SkNEW(AtlasEntry);

        entry->fAtlas = SkNEW_ARGS(GrTextureStripAtlas, (desc));
        entry->fKey = key;

        desc.fContext->addCleanUp(CleanUp, entry);

        GetCache()->insert(key, entry);
    }

    return entry->fAtlas;
}

GrTextureStripAtlas::GrTextureStripAtlas(GrTextureStripAtlas::Desc desc)
    : fCacheKey(sk_atomic_inc(&gCacheCount))
    , fLockedRows(0)
    , fDesc(desc)
    , fNumRows(desc.fHeight / desc.fRowHeight)
    , fTexture(NULL)
    , fRows(SkNEW_ARRAY(AtlasRow, fNumRows))
    , fLRUFront(NULL)
    , fLRUBack(NULL) {
    this->initLRU();
}

GrTextureStripAtlas::~GrTextureStripAtlas() {
    SkDELETE_ARRAY(fRows);
}

int GrTextureStripAtlas::lockRow(const SkBitmap& data) {
    if (0 == fLockedRows) {
        this->lockTexture();
    }

    int key = data.getGenerationID();
    int rowNumber = -1;
    int index = this->searchByKey(key);

    if (index >= 0) {
        // We already have the data in a row, so we can just return that row
        AtlasRow* row = fKeyTable[index];
        if (0 == row->fLocks) {
            this->removeFromLRU(row);
        }
        ++row->fLocks;
        ++fLockedRows;

        // Since all the rows are always stored in a contiguous array, we can save the memory
        // required for storing row numbers and just compute it with some pointer arithmetic
        rowNumber = static_cast<int>(row - fRows);
    } else {
        // ~index is the index where we will insert the new key to keep things sorted
        index = ~index;

        // We don't have this data cached, so pick the least recently used row to copy into
        AtlasRow* row = this->getLRU();

        ++fLockedRows;

        if (NULL == row) {
            // force a flush, which should unlock all the rows; then try again
            fDesc.fContext->flush();
            row = this->getLRU();
            if (NULL == row) {
                --fLockedRows;
                return -1;
            }
        }

        this->removeFromLRU(row);

        uint32_t oldKey = row->fKey;

        // If we are writing into a row that already held bitmap data, we need to remove the
        // reference to that genID which is stored in our sorted table of key values.
        if (oldKey != kEmptyAtlasRowKey) {

            // Find the entry in the list; if it's before the index where we plan on adding the new
            // entry, we decrement since it will shift elements ahead of it back by one.
            int oldIndex = this->searchByKey(oldKey);
            if (oldIndex < index) {
                --index;
            }

            fKeyTable.remove(oldIndex);
        }

        row->fKey = key;
        row->fLocks = 1;
        fKeyTable.insert(index, 1, &row);
        rowNumber = static_cast<int>(row - fRows);

        SkAutoLockPixels lock(data);

        // Pass in the kDontFlush flag, since we know we're writing to a part of this texture
        // that is not currently in use
        fDesc.fContext->writeTexturePixels(fTexture,
                                           0,  rowNumber * fDesc.fRowHeight,
                                           fDesc.fWidth, fDesc.fRowHeight,
                                           SkBitmapConfig2GrPixelConfig(data.config()),
                                           data.getPixels(),
                                           data.rowBytes(),
                                           GrContext::kDontFlush_PixelOpsFlag);
    }

    return rowNumber;
}

void GrTextureStripAtlas::unlockRow(int row) {
    --fRows[row].fLocks;
    --fLockedRows;
    if (0 == fRows[row].fLocks) {
        this->appendLRU(fRows + row);
    }
    if (0 == fLockedRows) {
        this->unlockTexture();
    }
}

GrTextureStripAtlas::AtlasRow* GrTextureStripAtlas::getLRU() {
    // Front is least-recently-used
    AtlasRow* row = fLRUFront;
    return row;
}

void GrTextureStripAtlas::lockTexture() {
    GrTextureParams params;
    GrTextureDesc texDesc;
    texDesc.fWidth = fDesc.fWidth;
    texDesc.fHeight = fDesc.fHeight;
    texDesc.fConfig = fDesc.fConfig;

    static const uint8_t gTextureStripAtlasDomain = GrCacheID::GenerateDomain();
    GrCacheID::Key key;
    *key.fData32 = fCacheKey;
    memset(key.fData32 + 1, 0, sizeof(key) - sizeof(uint32_t));
    GrCacheID cacheID(gTextureStripAtlasDomain, key);

    fTexture = fDesc.fContext->findAndRefTexture(texDesc, cacheID, &params);
    if (NULL == fTexture) {
        fTexture = fDesc.fContext->createTexture(&params, texDesc, cacheID, NULL, 0);
        // This is a new texture, so all of our cache info is now invalid
        this->initLRU();
        fKeyTable.rewind();
    }
}

void GrTextureStripAtlas::unlockTexture() {
    fTexture->unref();
    fTexture = NULL;
    fDesc.fContext->purgeCache();
}

void GrTextureStripAtlas::initLRU() {
    fLRUFront = NULL;
    fLRUBack = NULL;
    // Initially all the rows are in the LRU list
    for (int i = 0; i < fNumRows; ++i) {
        fRows[i].fKey = kEmptyAtlasRowKey;
        fRows[i].fNext = NULL;
        fRows[i].fPrev = NULL;
        this->appendLRU(fRows + i);
    }
}

void GrTextureStripAtlas::appendLRU(AtlasRow* row) {
    if (NULL == fLRUFront && NULL == fLRUBack) {
        fLRUFront = row;
        fLRUBack = row;
    } else {
        row->fPrev = fLRUBack;
        fLRUBack->fNext = row;
        fLRUBack = row;
    }
}

void GrTextureStripAtlas::removeFromLRU(AtlasRow* row) {
    if (NULL != row->fNext && NULL != row->fPrev) {
        row->fPrev->fNext = row->fNext;
        row->fNext->fPrev = row->fPrev;
    } else {
        if (NULL == row->fNext) {
            fLRUBack = row->fPrev;
            if (fLRUBack) {
                fLRUBack->fNext = NULL;
            }
        }
        if (NULL == row->fPrev) {
            fLRUFront = row->fNext;
            if (fLRUFront) {
                fLRUFront->fPrev = NULL;
            }
        }
    }
    row->fNext = NULL;
    row->fPrev = NULL;
}

int GrTextureStripAtlas::searchByKey(uint32_t key) {
    AtlasRow target;
    target.fKey = key;
    return SkTSearch<const AtlasRow,
                     GrTextureStripAtlas::KeyLess>((const AtlasRow**)fKeyTable.begin(),
                                                   fKeyTable.count(),
                                                   &target,
                                                   sizeof(AtlasRow*));
}

