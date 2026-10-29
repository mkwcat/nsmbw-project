#pragma once

#include "eggDisplay.h"

namespace EGG {

class AsyncDisplay : public Display {
    SIZE_ASSERT(0x88);

public:
    [[mkw(0x8020FD18)]] AsyncDisplay(u8 param);

    void clearEFB();

    [[mkw(0x8020FD8C)]] void startSyncNTSC(u8 param);

    u8 FILL(0x28, 0x88);
};

} // namespace EGG
