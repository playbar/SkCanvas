/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkAtomics_android_DEFINED
#define SkAtomics_android_DEFINED

/** Android framework atomics. */

#include <asm/atomic.h>
#include <stdint.h>
#include <assert.h>

#define sk_atomic_inc(addr)         android_atomic_inc(addr)
#define sk_atomic_add(addr, inc)    android_atomic_add(inc, addr)
#define sk_atomic_dec(addr)         android_atomic_dec(addr)

static inline __attribute__((always_inline)) void sk_membar_acquire__after_atomic_dec() {
    //HACK: Android is actually using full memory barriers.
    //      Should this change, uncomment below.
    //int dummy;
    //android_atomic_acquire_store(0, &dummy);
}

static inline __attribute__((always_inline)) int32_t sk_atomic_conditional_inc(int32_t* addr) {
    while (true) {
        int32_t value = *addr;
        if (value == 0) {
            return 0;
        }
        assert(false);
        //if (0 == android_atomic_release_cas(value, value + 1, addr)) {
        //    return value;
        //}
    }
}

static inline __attribute__((always_inline)) void sk_membar_acquire__after_atomic_conditional_inc() {
    //HACK: Android is actually using full memory barriers.
    //      Should this change, uncomment below.
    //int dummy;
    //android_atomic_acquire_store(0, &dummy);
}

#endif
