#pragma once

struct MEMAllocator;
struct MEMiHeapHead;

typedef void* (*MEMAllocatorAllocFunc)(struct MEMAllocator* allocator, u32 size);
typedef void (*MEMAllocatorFreeFunc)(struct MEMAllocator* allocator, void* block);

struct MEMAllocatorFuncs {
    SIZE_ASSERT(0x8);
    /* 0x0 */ MEMAllocatorAllocFunc allocFunc;
    /* 0x4 */ MEMAllocatorFreeFunc freeFunc;
};

struct MEMAllocator {
    SIZE_ASSERT(0x10);
    /* 0x00 */ const MEMAllocatorFuncs* funcs;
    /* 0x04 */ void* heap;
    /* 0x08 */ u32 heapParam1;
    /* 0x0C */ u32 heapParam2;
};

void* MEMAllocFromAllocator(MEMAllocator* allocator, u32 size);
void MEMFreeToAllocator(MEMAllocator* allocator, void* block);

void MEMInitAllocatorForExpHeap(MEMAllocator* allocator, struct MEMiHeapHead* heap, s32 align);
void MEMInitAllocatorForFrmHeap(MEMAllocator* allocator, struct MEMiHeapHead* heap, s32 align);
