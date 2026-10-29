#pragma once

namespace EGG {

class Xfb;

class XfbManager {
    SIZE_ASSERT(0x10);

public:
    constexpr XfbManager()
        : mHead(nullptr)
        , mTail(nullptr)
        , mCopied(nullptr)
        , mShow(nullptr) {}

    [[mkw(0x80244200)]] void attach(Xfb* pXfb);

private:
    Xfb *mHead, *mTail, *mCopied, *mShow;
};

} // namespace EGG
