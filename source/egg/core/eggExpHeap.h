#pragma once

#include "egg/prim/eggBitFlag.h"
#include "eggHeap.h"

namespace EGG {

class ExpHeap : public Heap {
public:
    /* 0x802B9840 */
    static u32 getSizeForMBlock(const void* block);

public:
    FILL(0x10, 0x1C);

    /* 0x1C */ TBitFlag<u16> mFlags;
};

} // namespace EGG
