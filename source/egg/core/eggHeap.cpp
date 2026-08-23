// eggHeap.cpp
// NSMBW .text: 0x802B8C80 - 0x802B93E0

#include "eggHeap.h"

#include <new>
#include <revolution/os.h>

namespace EGG {

[[nsmbw(0x8042B0F0)]]
Heap* Heap::sCurrentHeap;

[[nsmbw(0x802B8C80)]]
void Heap::initialize();

[[nsmbw(0x802B8CC0)]]
Heap::Heap(MEMiHeapHead* rvlHeap);

[[nsmbw(0x802B8D60)]]
Heap::~Heap();

[[nsmbw(0x802B8E00)]]
void* Heap::alloc(u32 size, s32 align, Heap* heap);

[[nsmbw(0x802B8FC0)]]
Heap* Heap::findHeap(MEMiHeapHead* rvlHeap);

[[nsmbw(0x802B9060)]]
Heap* Heap::findParentHeap();

[[nsmbw(0x802B9070)]]
Heap* Heap::findContainHeap(const void* block);

[[nsmbw(0x802B90B0)]]
void Heap::free(void* block, EGG::Heap* heap);

[[nsmbw(0x802B9150)]]
void Heap::dispose();

[[nsmbw(0x802B91B0)]]
void Heap::dump();

[[nsmbw(0x802B91C0)]]
void Heap::dumpAll();

[[nsmbw(0x802B92B0)]]
Heap* Heap::becomeCurrentHeap();

[[nsmbw(0x802B9310)]]
Heap* Heap::_becomeCurrentHeapWithoutLock();

} // namespace EGG

[[nsmbw(0x802B9350)]]
void* operator new(
    u32 size
) {
    void* block = EGG::Heap::alloc(size, 4, nullptr);
    ASSERT(block);
    return block;
}

/* 0x802B9360 */
// Moved to <new>
// void* operator new(u32 size, void* block);

[[nsmbw(0x802B9370)]]
void* operator new(
    u32 size, int align
) {
    void* block = EGG::Heap::alloc(size, align, nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B9380)]]
void* operator new(
    u32 size, EGG::Heap* heap, int align
) {
    void* block = EGG::Heap::alloc(size, align, heap);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B9390)]]
void* operator new[](
    u32 size
) {
    void* block = EGG::Heap::alloc(size, 4, nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B93A0)]]
void* operator new[](
    u32 size, int align
) {
    void* block = EGG::Heap::alloc(size, align, nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B93B0)]]
void* operator new[](
    u32 size, EGG::Heap* heap, int align
) {
    void* block = EGG::Heap::alloc(size, align, heap);
    ASSERT(block);
    return block;
}

void* operator new(
    u32 size, std::align_val_t align
) {
    void* block = EGG::Heap::alloc(size, static_cast<int>(align), nullptr);
    ASSERT(block);
    return block;
}

void* operator new[](
    u32 size, std::align_val_t align
) {
    void* block = EGG::Heap::alloc(size, static_cast<int>(align), nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B93C0)]]
void operator delete(void* block);

[[nsmbw(0x802B93D0)]]
void operator delete[](void* block);

void operator delete(
    void* block, u32 size
) {
    operator delete(block);
}

void operator delete[](
    void* block, u32 size
) {
    EGG::Heap::free(block, nullptr);
}

void operator delete(
    void* block, u32 size, std::align_val_t align
) {
    EGG::Heap::free(block, nullptr);
}

void operator delete[](
    void* block, u32 size, std::align_val_t align
) {
    EGG::Heap::free(block, nullptr);
}
