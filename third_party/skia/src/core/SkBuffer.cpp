
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#include "SkBuffer.h"

////////////////////////////////////////////////////////////////////////////////////////

void SkRBuffer::readNoSizeCheck(void* buffer, size_t size)
{
    if (buffer)
        memcpy(buffer, fPos, size);
    fPos += size;
}

const void* SkRBuffer::skip(size_t size)
{
    const void* result = fPos;
    readNoSizeCheck(NULL, size);
    return result;
}

size_t SkRBuffer::skipToAlign4()
{
    size_t pos = this->pos();
    size_t n = SkAlign4(pos) - pos;
    fPos += n;
    return n;
}

bool SkRBufferWithSizeCheck::read(void* buffer, size_t size) {
    fError = fError || (fPos + size > fStop);
    if (!fError && (size > 0)) {
        readNoSizeCheck(buffer, size);
    }
    return !fError;
}

void* SkWBuffer::skip(size_t size)
{
    void* result = fPos;
    writeNoSizeCheck(NULL, size);
    return fData == NULL ? NULL : result;
}

void SkWBuffer::writeNoSizeCheck(const void* buffer, size_t size)
{
    if (fData && buffer)
        memcpy(fPos, buffer, size);
    fPos += size;
}

size_t SkWBuffer::padToAlign4()
{
    size_t pos = this->pos();
    size_t n = SkAlign4(pos) - pos;

    if (n && fData)
    {
        char* p = fPos;
        char* stop = p + n;
        do {
            *p++ = 0;
        } while (p < stop);
    }
    fPos += n;
    return n;
}

