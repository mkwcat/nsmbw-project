#pragma once

#include <revolution/mem.h>

namespace EGG {

class Heap;

class Allocator : public MEMAllocator {
    SIZE_ASSERT(0x1C);

public:
    Allocator(Heap* heap, s32 align);

public:
    /* VT+0x08 */ virtual ~Allocator();
    /* VT+0x0C */ virtual void* alloc(u32 size);
    /* VT+0x10 */ virtual void free(void* block);

    inline MEMAllocator* getHandle() { return static_cast<MEMAllocator*>(this); }

    /* 0x14 */ Heap* mHeap;
    /* 0x18 */ s32   align;
};

} // namespace EGG
