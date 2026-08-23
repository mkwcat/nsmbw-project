#pragma once

#include "egg/core/eggHeap.h"

namespace EGG {

template <typename T>
class TBuffer {
    /* 0x00 VTABLE */

private:
    TBuffer(
        const TBuffer<T>& other
    ) {
        mSize   = other.mSize;
        mBuffer = other.mBuffer;
    }

public:
    TBuffer move() {
        TBuffer<T> buffer = *this;

        mSize             = 0;
        mBuffer           = nullptr;

        return buffer;
    }

    /* VT+0x08 */
    virtual ~TBuffer() {
        if (mBuffer != nullptr) {
            delete[] mBuffer;
            mBuffer = nullptr;
        }
    }

    /* VT+0x0C */
    virtual void allocate(int n, int = 0);

    /* VT+0x10 */
    virtual void allocate(int n, Heap* heap, int = 0);

    /* VT+0x14 */
    virtual void onAllocate(
        Heap*
    ) {
        return;
    }

    /* VT+0x18 */
    virtual void errRangeOver() { return; }

public:
    /* 0x04 */ s32 mSize;
    /* 0x08 */ T*  mBuffer;

public:
    inline TBuffer()
        : mSize(0)
        , mBuffer(nullptr) {}

    inline bool isRangeValid(
        int i
    ) {
        return (i >= 0 && i < mSize);
    }

    inline void checkRange(
        int i
    ) {
        if (!isRangeValid(i)) {
            errRangeOver();
        }
    }

    inline T& operator()(
        int i
    ) {
        checkRange(i);
        return mBuffer[i];
    }

    inline s32 getSize() { return mSize; }
};

template <typename T>
void TBuffer<T>::allocate(
    int n, int
) {
    mSize   = n;
    mBuffer = new T[n];
    onAllocate(nullptr);
}

template <typename T>
void TBuffer<T>::allocate(
    int n, Heap* heap, int
) {
    mSize = n;
    if (heap == nullptr) {
        heap = Heap::sCurrentHeap;
    }
    mBuffer = new (heap, 4) T[mSize];
    onAllocate(heap);
}

} // namespace EGG
