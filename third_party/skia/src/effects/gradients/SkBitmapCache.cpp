
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkBitmapCache.h"

struct SkBitmapCache::Entry {
    Entry*      fPrev;
    Entry*      fNext;

    void*       fBuffer;
    size_t      fSize;
    SkBitmap    fBitmap;

    Entry(const void* buffer, size_t size, const SkBitmap& bm)
            : fPrev(NULL),
              fNext(NULL),
              fBitmap(bm) {
        fBuffer = sk_malloc_throw(size);
        fSize = size;
        memcpy(fBuffer, buffer, size);
    }

    ~Entry() { sk_free(fBuffer); }

    bool equals(const void* buffer, size_t size) const {
        return (fSize == size) && !memcmp(fBuffer, buffer, size);
    }
};

SkBitmapCache::SkBitmapCache(int max) : fMaxEntries(max) {
    fEntryCount = 0;
    fHead = fTail = NULL;
}

SkBitmapCache::~SkBitmapCache() {

    Entry* entry = fHead;
    while (entry) {
        Entry* next = entry->fNext;
        delete entry;
        entry = next;
    }
}

SkBitmapCache::Entry* SkBitmapCache::detach(Entry* entry) const {
    if (entry->fPrev) {
        entry->fPrev->fNext = entry->fNext;
    } else {
        fHead = entry->fNext;
    }
    if (entry->fNext) {
        entry->fNext->fPrev = entry->fPrev;
    } else {
        fTail = entry->fPrev;
    }
    return entry;
}

void SkBitmapCache::attachToHead(Entry* entry) const {
    entry->fPrev = NULL;
    entry->fNext = fHead;
    if (fHead) {
        fHead->fPrev = entry;
    } else {
        fTail = entry;
    }
    fHead = entry;
}

bool SkBitmapCache::find(const void* buffer, size_t size, SkBitmap* bm) const {
    AutoValidate av(this);

    Entry* entry = fHead;
    while (entry) {
        if (entry->equals(buffer, size)) {
            if (bm) {
                *bm = entry->fBitmap;
            }
            // move to the head of our list, so we purge it last
            this->detach(entry);
            this->attachToHead(entry);
            return true;
        }
        entry = entry->fNext;
    }
    return false;
}

void SkBitmapCache::add(const void* buffer, size_t len, const SkBitmap& bm) {
    AutoValidate av(this);

    if (fEntryCount == fMaxEntries) {
        delete this->detach(fTail);
        fEntryCount -= 1;
    }

    Entry* entry = SkNEW_ARGS(Entry, (buffer, len, bm));
    this->attachToHead(entry);
    fEntryCount += 1;
}


