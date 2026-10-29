// eggExpHeap.cpp
// NSMBW .text: 0x802B93E0 - 0x802B98C0

#include "eggExpHeap.h"

namespace EGG {

[[mkw(0x80226A1C)]]
ExpHeap* ExpHeap::create(void*, u32, u16);

[[mkw(0x80226AC8)]]
ExpHeap* ExpHeap::create(u32, Heap*, u16);

[[nsmbw(0x802B9840)]]
u32 ExpHeap::getSizeForMBlock(const void* block);

} // namespace EGG
