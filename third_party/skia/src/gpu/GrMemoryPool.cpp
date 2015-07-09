/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrMemoryPool.h"

GrMemoryPool::GrMemoryPool(size_t preallocSize, size_t minAllocSize) {
    SkDEBUGCODE(fAllocationCnt = 0);

    minAllocSize = GrMax<size_t>(minAllocSize, 1 << 10);
    fMinAllocSize = GrSizeAlignUp(minAllocSize + kPerAllocPad, kAlignment),
    fPreallocSize = GrSizeAlignUp(preallocSize + kPerAllocPad, kAlignment);
    fPreallocSize = GrMax(fPreallocSize, fMinAllocSize);

    fHead = CreateBlock(fPreallocSize);
    fTail = fHead;
    fHead->fNext = NULL;
    fHead->fPrev = NULL;
};

GrMemoryPool::~GrMemoryPool() {
    DeleteBlock(fHead);
};

void* GrMemoryPool::allocate(size_t size) {
    size = GrSizeAlignUp(size, kAlignment);
    size += kPerAllocPad;
    if (fTail->fFreeSize < size) {
        size_t blockSize = size;
        blockSize = GrMax<size_t>(blockSize, fMinAllocSize);
        BlockHeader* block = CreateBlock(blockSize);

        block->fPrev = fTail;
        block->fNext = NULL;
        fTail->fNext = block;
        fTail = block;
    }
    intptr_t ptr = fTail->fCurrPtr;
    // We stash a pointer to the block header, just before the allocated space,
    // so that we can decrement the live count on delete in constant time.
    *reinterpret_cast<BlockHeader**>(ptr) = fTail;
    ptr += kPerAllocPad;
    fTail->fPrevPtr = fTail->fCurrPtr;
    fTail->fCurrPtr += size;
    fTail->fFreeSize -= size;
    fTail->fLiveCount += 1;
    SkDEBUGCODE(++fAllocationCnt);
    return reinterpret_cast<void*>(ptr);
}

void GrMemoryPool::release(void* p) {
    intptr_t ptr = reinterpret_cast<intptr_t>(p) - kPerAllocPad;
    BlockHeader* block = *reinterpret_cast<BlockHeader**>(ptr);
    if (1 == block->fLiveCount) {
        // the head block is special, it is reset rather than deleted
        if (fHead == block) {
            fHead->fCurrPtr = reinterpret_cast<intptr_t>(fHead) +
                                kHeaderSize;
            fHead->fLiveCount = 0;
            fHead->fFreeSize = fPreallocSize;
        } else {
            BlockHeader* prev = block->fPrev;
            BlockHeader* next = block->fNext;
            prev->fNext = next;
            if (next) {
                next->fPrev = prev;
            } else {
                fTail = prev;
            }
            DeleteBlock(block);
        }
    } else {
        --block->fLiveCount;
        // Trivial reclaim: if we're releasing the most recent allocation, reuse it
        if (block->fPrevPtr == ptr) {
            block->fFreeSize += (block->fCurrPtr - block->fPrevPtr);
            block->fCurrPtr = block->fPrevPtr;
        }
    }
    SkDEBUGCODE(--fAllocationCnt);
}

GrMemoryPool::BlockHeader* GrMemoryPool::CreateBlock(size_t size) {
    BlockHeader* block =
        reinterpret_cast<BlockHeader*>(sk_malloc_throw(size + kHeaderSize));
    // we assume malloc gives us aligned memory
    block->fLiveCount = 0;
    block->fFreeSize = size;
    block->fCurrPtr = reinterpret_cast<intptr_t>(block) + kHeaderSize;
    block->fPrevPtr = 0; // gcc warns on assigning NULL to an intptr_t.
    return block;
}

void GrMemoryPool::DeleteBlock(BlockHeader* block) {
    sk_free(block);
}

