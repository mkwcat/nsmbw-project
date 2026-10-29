#pragma once

#include "egg/prim/eggBitFlag.h"
#include "eggHeap.h"

namespace EGG {

class ExpHeap : public Heap {
public:
    static ExpHeap* create(void*, u32, u16);
    static ExpHeap* create(u32, Heap*, u16);

    static u32 getSizeForMBlock(const void* block);

public:
    u8                       FILL(0x10, 0x1C);

    /* 0x1C */ TBitFlag<u16> mFlags;
};

} // namespace EGG
