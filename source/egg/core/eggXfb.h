#pragma once

namespace EGG {

class Heap;

class Xfb {
    SIZE_ASSERT(0x10);

public:
    [[mkw(0x80244160)]] Xfb(EGG::Heap*);

private:
    u16  mWidth;
    u16  mHeight;
    u8*  mBuffer;
    Xfb* mPrev;
    Xfb* mNext;
};

} // namespace EGG
