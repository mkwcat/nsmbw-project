#pragma once

#include "egg/core/eggAllocator.h"
#include "egg/core/eggDisposer.h"
#include <new>
#include <revolution/mem.h>

namespace EGG {

class Heap : public Disposer {
public:
    /* 0x00 VTABLE 0x80350050 */

    /* 0x802B8C80 */
    static void initialize();

    /* 0x802B8CC0 */
    Heap(MEMiHeapHead* rvlHeap);

    /* VT+0x08 0x802B8D60 */
    virtual ~Heap();

    /* VT+0x0C */
    virtual int getHeapKind();

    /* VT+0x10 */
    virtual void initAllocator(Allocator* allocator, s32 align);

    /* VT+0x14 */
    [[gnu::malloc]]
    virtual void* alloc(u32 size, s32 align) = 0;

    /* 0x802B8E00 */
    [[gnu::malloc]]
    static void* alloc(u32 size, s32 align, Heap* heap);

    /* VT+0x18 */
    virtual void free(void* block) = 0;

    /* 0x802B90B0 */
    static void free(void* block, EGG::Heap* heap);

    /* VT+0x1C */
    virtual void destroy();

    /* VT+0x20 */
    virtual u32 resizeForMBlock(void* block, u32 newSize) = 0;

    /* VT+0x24 */
    virtual u32 getAllocatableSize(s32 align);

    /* VT+0x28 */
    virtual u32 adjust();

    /* 0x802B8FC0 */
    static Heap* findHeap(MEMiHeapHead* rvlHeap);

    /* 0x802B9060 */
    Heap* findParentHeap();

    /* 0x802B9070 */
    static Heap* findContainHeap(const void* block);

    /* 0x802B9150 */
    void dispose();

    /* 0x802B91B0 */
    void dump();

    /* 0x802B91C0 */
    static void dumpAll();

    /* 0x802B92B0 */
    Heap* becomeCurrentHeap();

    /* 0x802B9310 */
    Heap* _becomeCurrentHeapWithoutLock();

public:
    // Static Inline Methods
    // ^^^^^^

    static Heap* getCurrentHeap() { return sCurrentHeap; }

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042B0F0 */
    static Heap* sCurrentHeap;
};

} // namespace EGG

/* 0x802B9350 */
void* operator new(u32 size);

/* 0x802B9360 */
// Moved to <new>
// void* operator new(u32 size, void* block);

/* 0x802B9370 */
void* operator new(u32 size, int align);

/* 0x802B9380 */
void* operator new(u32 size, EGG::Heap* heap, int align);

/* 0x802B9390 */
void* operator new[](u32 size);

/* 0x802B93A0 */
void* operator new[](u32 size, int align);

/* 0x802B93B0 */
void* operator new[](u32 size, EGG::Heap* heap, int align);
