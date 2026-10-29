#pragma once

#include "eggDvdFile.h"
#include "eggHeap.h"
#include "eggStreamDecomp.h"

namespace EGG::DvdRipper {

enum EAllocDirection {
    ALLOC_DIR_TOP    = 1,
    ALLOC_DIR_BOTTOM = 2,
};

u8* loadToMainRAM(
    const char* fileName, u8* pDst, Heap* pHeap, EAllocDirection allocDirection, u32 offset,
    u32* amountRead, u32* fileSize
);

u8* loadToMainRAM(
    s32 entryNum, u8* pDst, Heap* pHeap, EAllocDirection allocDirection, u32 offset,
    u32* amountRead, u32* fileSize
);

u8* loadToMainRAM(
    DvdFile* file, u8* pDst, Heap* pHeap, EAllocDirection allocDirection, u32 offset,
    u32* amountRead, u32* fileSize
);

u8* loadToMainRAMDecomp(
    DvdFile* file, StreamDecomp* streamDecomp, u8* pDst, Heap* pHeap,
    EAllocDirection allocDirection, s32 offset, u32 size, u32 maxChunkSize, u32* amountRead,
    u32* fileSize
);

} // namespace EGG::DvdRipper
