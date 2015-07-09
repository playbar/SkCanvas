
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkRegionPriv_DEFINED
#define SkRegionPriv_DEFINED

#include "SkRegion.h"
#include "SkThread.h"

//SkDEBUGCODE(extern int32_t gRgnAllocCounter;)

#ifdef SK_DEBUG
// Given the first interval (just past the interval-count), compute the
// interval count, by search for the x-sentinel
//
static int compute_intervalcount(const SkRegion::RunType runs[]) {
    const SkRegion::RunType* curr = runs;
    while (*curr < SkRegion::kRunTypeSentinel) {
        curr += 2;
    }
    return (curr - runs) >> 1;
}
#endif

struct SkRegion::RunHead {
private:

public:
    int32_t fRefCnt;
    int32_t fRunCount;

    /**
     *  Number of spans with different Y values. This does not count the initial
     *  Top value, nor does it count the final Y-Sentinel value. In the logical
     *  case of a rectangle, this would return 1, and an empty region would
     *  return 0.
     */
    int getYSpanCount() const {
        return fYSpanCount;
    }

    /**
     *  Number of intervals in the entire region. This equals the number of
     *  rects that would be returned by the Iterator. In the logical case of
     *  a rect, this would return 1, and an empty region would return 0.
     */
    int getIntervalCount() const {
        return fIntervalCount;
    }

    static RunHead* Alloc(int count) {
        //SkDEBUGCODE(sk_atomic_inc(&gRgnAllocCounter);)
        //SkDEBUGF(("************** gRgnAllocCounter::alloc %d\n", gRgnAllocCounter));

        RunHead* head = (RunHead*)sk_malloc_throw(sizeof(RunHead) + count * sizeof(RunType));
        head->fRefCnt = 1;
        head->fRunCount = count;
        // these must be filled in later, otherwise we will be invalid
        head->fYSpanCount = 0;
        head->fIntervalCount = 0;
        return head;
    }

    static RunHead* Alloc(int count, int yspancount, int intervalCount) {

        RunHead* head = Alloc(count);
        head->fYSpanCount = yspancount;
        head->fIntervalCount = intervalCount;
        return head;
    }

    SkRegion::RunType* writable_runs() {
        return (SkRegion::RunType*)(this + 1);
    }

    const SkRegion::RunType* readonly_runs() const {
        return (const SkRegion::RunType*)(this + 1);
    }

    RunHead* ensureWritable() {
        RunHead* writable = this;
        if (fRefCnt > 1) {
            // We need to alloc & copy the current region before we call
            // sk_atomic_dec because it could be freed in the meantime,
            // otherwise.
            writable = Alloc(fRunCount, fYSpanCount, fIntervalCount);
            memcpy(writable->writable_runs(), this->readonly_runs(),
                   fRunCount * sizeof(RunType));

            // fRefCount might have changed since we last checked.
            // If we own the last reference at this point, we need to
            // free the memory.
            if (sk_atomic_dec(&fRefCnt) == 1) {
                sk_free(this);
            }
        }
        return writable;
    }

    /**
     *  Given a scanline (including its Bottom value at runs[0]), return the next
     *  scanline. Asserts that there is one (i.e. runs[0] < Sentinel)
     */
    static SkRegion::RunType* SkipEntireScanline(const SkRegion::RunType runs[]) {
        // we are not the Y Sentinel
        const int intervals = runs[1];

        // skip the entire line [B N [L R] S]
        runs += 1 + 1 + intervals * 2 + 1;
        return const_cast<SkRegion::RunType*>(runs);
    }


    /**
     *  Return the scanline that contains the Y value. This requires that the Y
     *  value is already known to be contained within the bounds of the region,
     *  and so this routine never returns NULL.
     *
     *  It returns the beginning of the scanline, starting with its Bottom value.
     */
    SkRegion::RunType* findScanline(int y) const {
        const RunType* runs = this->readonly_runs();

        // if the top-check fails, we didn't do a quick check on the bounds

        runs += 1;  // skip top-Y
        for (;;) {
            int bottom = runs[0];
            // If we hit this, we've walked off the region, and our bounds check
            // failed.
            if (y < bottom) {
                break;
            }
            runs = SkipEntireScanline(runs);
        }
        return const_cast<SkRegion::RunType*>(runs);
    }

    // Copy src runs into us, computing interval counts and bounds along the way
    void computeRunBounds(SkIRect* bounds) {
        RunType* runs = this->writable_runs();
        bounds->fTop = *runs++;

        int bot;
        int ySpanCount = 0;
        int intervalCount = 0;
        int left = SK_MaxS32;
        int rite = SK_MinS32;

        do {
            bot = *runs++;
            ySpanCount += 1;

            const int intervals = *runs++;

            if (intervals > 0) {
                RunType L = runs[0];
                if (left > L) {
                    left = L;
                }

                runs += intervals * 2;
                RunType R = runs[-1];
                if (rite < R) {
                    rite = R;
                }

                intervalCount += intervals;
            }
            runs += 1;  // skip x-sentinel

            // test Y-sentinel
        } while (SkRegion::kRunTypeSentinel > *runs);

        fYSpanCount = ySpanCount;
        fIntervalCount = intervalCount;

        bounds->fLeft = left;
        bounds->fRight = rite;
        bounds->fBottom = bot;
    }

private:
    int32_t fYSpanCount;
    int32_t fIntervalCount;
};

#endif
