// eggDvdRipper.cpp
// NSMBW .text: 0x802B8010 - 0x802B8560

#include "eggDvdRipper.h"

namespace EGG {

[[mkw(0x802226D8)]]
u8* DvdRipper::loadToMainRAM(
    const char* fileName, u8* pDst, Heap* pHeap, EAllocDirection allocDirection, u32 offset,
    u32* amountRead, u32* fileSize
);

[[nsmbw(0x802B8010)]]
u8* DvdRipper::loadToMainRAM(
    s32 entryNum, u8* pDst, Heap* pHeap, EAllocDirection allocDirection, u32 offset,
    u32* amountRead, u32* fileSize
);

[[nsmbw(0x802B80C0)]] [[mkw(0x8022277C)]]
u8* DvdRipper::loadToMainRAM(
    DvdFile* file, u8* pDst, Heap* pHeap, EAllocDirection allocDirection, u32 offset,
    u32* amountRead, u32* fileSize
);

[[nsmbw(0x802B8290)]]
u8* DvdRipper::loadToMainRAMDecomp(
    DvdFile* file, StreamDecomp* streamDecomp, u8* pDst, Heap* pHeap,
    EAllocDirection allocDirection, s32 offset, u32 size, u32 maxChunkSize, u32* amountRead,
    u32* fileSize
);

} // namespace EGG
