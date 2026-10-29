#pragma once

#include <nw4r/ut/Color.h>

namespace EGG {

class Display {
    SIZE_ASSERT(0x28);

public:
    /* 0x00 */ u8 mFlag;
    /* 0x01 */ u8 FILL(0x01, 0x04);

    [[mkw(0x80219E68)]] Display(u8 param);

    virtual void beginFrame();
    virtual void beginRender();
    virtual void endRender();
    virtual void endFrame();
    virtual u32 getTickPerFrame();

    void setClearColor(
        nw4r::ut::Color color
    ) {
        mClearColor = color;
    }

    nw4r::ut::Color getClearColor() { return mClearColor; }

    /* 0x08 */ u8              mFrameRate;
    /* 0x09 */ volatile u8     mScreenStateFlag;
    /* 0x0C */ u32             mLastRetraceCounter;
    /* 0x10 */ u32             mFrameCounter;
    /* 0x14 */ nw4r::ut::Color mClearColor;
    /* 0x18 */ nw4r::ut::Color mClearZ;
    /* 0x1C */ u32             mLastTick;
    /* 0x20 */ u32             mTickDifferential;
    /* 0x24 */ float           mTickFrequency;
};

} // namespace EGG
