#pragma once

#include <machine/m_vec.h>

class sRangeDataF {
public:
    sRangeDataF() {}

    sRangeDataF(
        float t, float b, float l, float r
    ) {
        set(t, b, l, r);
    }

    sRangeDataF(
        const sRangeDataF& b
    ) {
        set(b.mOffset.x, b.mOffset.y, b.mSize.x, b.mSize.y);
    }

    void set(
        float t, float b, float l, float r
    ) {
        mOffset = {t, b};
        mSize   = {l, r};
    }

    mVec2_c getSize() const { return mSize; }

    mVec2_c mOffset, mSize;
};
