#pragma once

#include <nw4r/snd/SoundHeap.h>

namespace EGG {

class SoundHeapMgr {
public:
    FILL(0x0, 0x4);
    /* 0x4 */ nw4r::snd::SoundHeap mHeap;
};

} // namespace EGG
