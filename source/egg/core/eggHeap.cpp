// eggHeap.cpp
// NSMBW .text: 0x802B8C80 - 0x802B93E0

#include "eggHeap.h"

#include <new>
#include <revolution/os.h>

namespace EGG {

[[nsmbw_data(0x8042B0F0)]] [[mkw_data(0x80386EA0)]]
Heap* Heap::sCurrentHeap;

[[nsmbw(0x802B8C80)]] [[mkw(0x802296A8)]]
void Heap::initialize();

[[nsmbw(0x802B8CC0)]] [[mkw(0x802296E8)]]
Heap::Heap(MEMiHeapHead* rvlHeap);

[[nsmbw(0x802B8D60)]] [[mkw(0x80229780)]]
Heap::~Heap();

[[nsmbw(0x802B8E00)]] [[mkw(0x80229814)]]
void* Heap::alloc(u32 size, int align, Heap* heap);

[[nsmbw(0x802B8FC0)]]
Heap* Heap::findHeap(MEMiHeapHead* rvlHeap);

[[nsmbw(0x802B9060)]] [[mkw(0x80229AD4)]]
Heap* Heap::findParentHeap();

[[nsmbw(0x802B9070)]] [[mkw(0x80229ADC)]]
Heap* Heap::findContainHeap(const void* block);

[[nsmbw(0x802B90B0)]] [[mkw(0x80229B84)]]
void Heap::free(void* block, EGG::Heap* heap);

[[nsmbw(0x802B9150)]] [[mkw(0x80229C5C)]]
void Heap::dispose();

[[nsmbw(0x802B91B0)]]
void Heap::dump();

[[nsmbw(0x802B91C0)]] [[mkw(0x80229CB0)]]
void Heap::dumpAll();

[[nsmbw(0x802B92B0)]] [[mkw(0x80229D74)]]
Heap* Heap::becomeCurrentHeap();

[[nsmbw(0x802B9310)]]
Heap* Heap::_becomeCurrentHeapWithoutLock();

} // namespace EGG

[[nsmbw(0x802B9350)]] [[mkw(0x80229DCC)]]
void* operator new(
    std::size_t size
) {
    void* block = EGG::Heap::alloc(size, 4, nullptr);
    ASSERT(block);
    return block;
}

/* nsmbw(0x802B9360) mkw(0x80224E94) */
// Moved to <new>
// void* operator new(std::size_t  size, void* block);

[[nsmbw(0x802B9370)]] [[mkw(0x80229DD8)]]
void* operator new(
    std::size_t size, int align
) {
    void* block = EGG::Heap::alloc(size, align, nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B9380)]] [[mkw(0x80229DE0)]]
void* operator new(
    std::size_t size, EGG::Heap* heap, int align
) {
    void* block = EGG::Heap::alloc(size, align, heap);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B9390)]] [[mkw(0x80229DF0)]]
void* operator new[](
    std::size_t size
) {
    void* block = EGG::Heap::alloc(size, 4, nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B93A0)]] [[mkw(0x80229DFC)]]
void* operator new[](
    std::size_t size, int align
) {
    void* block = EGG::Heap::alloc(size, align, nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B93B0)]] [[mkw(0x80229E04)]]
void* operator new[](
    std::size_t size, EGG::Heap* heap, int align
) {
    void* block = EGG::Heap::alloc(size, align, heap);
    ASSERT(block);
    return block;
}

void* operator new(
    std::size_t size, std::align_val_t align
) {
    void* block = EGG::Heap::alloc(size, static_cast<int>(align), nullptr);
    ASSERT(block);
    return block;
}

void* operator new[](
    std::size_t size, std::align_val_t align
) {
    void* block = EGG::Heap::alloc(size, static_cast<int>(align), nullptr);
    ASSERT(block);
    return block;
}

[[nsmbw(0x802B93C0)]] [[mkw(0x80229E14)]]
void operator delete(void* block);

[[nsmbw(0x802B93D0)]] [[mkw(0x80229EE0)]]
void operator delete[](void* block);

void operator delete(
    void* block, std::size_t size
) {
    operator delete(block);
}

void operator delete[](
    void* block, std::size_t size
) {
    EGG::Heap::free(block, nullptr);
}

void operator delete(
    void* block, std::size_t size, std::align_val_t align
) {
    EGG::Heap::free(block, nullptr);
}

void operator delete[](
    void* block, std::size_t size, std::align_val_t align
) {
    EGG::Heap::free(block, nullptr);
}
