// d_allocator.cpp
// NSMBW .text: 0x80069020 - 0x800690F0

#include "d_allocator.h"

[[nsmbw(0x80069020)]]
dHeapAllocator_c::dHeapAllocator_c();

[[nsmbw(0x800690C0)]]
void dHeapAllocator_c::createFrmHeap(std::size_t size, EGG::Heap* heap, const char*, std::size_t);

[[nsmbw(0x800690E0)]]
void dHeapAllocator_c::adjustFrmHeap();
