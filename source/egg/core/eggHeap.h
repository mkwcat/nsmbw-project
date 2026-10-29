#pragma once

#include "egg/core/eggAllocator.h"
#include "egg/core/eggDisposer.h"
#include <cstddef>
#include <new>
#include <revolution/mem.h>

namespace EGG {

class Heap : public Disposer {
public:
    static void initialize();

    Heap(MEMiHeapHead* rvlHeap);
    /* VT+0x08 */ virtual ~Heap();

    /* VT+0x0C */ virtual int getHeapKind();
    /* VT+0x10 */ virtual void initAllocator(Allocator* allocator, long align);

    /* VT+0x14 */ [[gnu::malloc]] virtual void* alloc(std::size_t size, long align) = 0;
    [[gnu::malloc]] static void* alloc(std::size_t size, int align, Heap* heap);

    /* VT+0x18 */ virtual void free(void* block) = 0;
    static void free(void* block, EGG::Heap* heap);

    /* VT+0x1C */ virtual void destroy();
    /* VT+0x20 */ virtual std::size_t resizeForMBlock(void* block, std::size_t newSize) = 0;
    /* VT+0x24 */ virtual std::size_t getAllocatableSize(std::size_t align);
    /* VT+0x28 */ virtual std::size_t adjust();
    static Heap* findHeap(MEMiHeapHead* rvlHeap);

    Heap* findParentHeap();
    static Heap* findContainHeap(const void* block);
    void dispose();
    void dump();
    static void dumpAll();
    Heap* becomeCurrentHeap();
    Heap* _becomeCurrentHeapWithoutLock();

public:
    // Static Inline Methods
    // ^^^^^^

    static Heap* getCurrentHeap() { return sCurrentHeap; }

public:
    // Static Variables
    // ^^^^^^

    static Heap* sCurrentHeap;
};

} // namespace EGG

void* operator new(std::size_t size);
// void* operator new(u32 size, void* block); // Moved to <new>
void* operator new(std::size_t size, int align);
void* operator new(std::size_t size, EGG::Heap* heap, int align);
void* operator new[](std::size_t size);
void* operator new[](std::size_t size, int align);
void* operator new[](std::size_t size, EGG::Heap* heap, int align);
