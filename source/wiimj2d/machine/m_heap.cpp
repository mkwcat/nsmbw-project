// m_heap.cpp
// NSMBW .bss: 0x80377F48 - 0x80377F58

#include "m_heap.h"

namespace mHeap {

[[nsmbw_data(0x8042A728)]]
/* static */ EGG::Heap* s_SavedCurrentHeap;

[[nsmbw_data(0x80377F48)]]
EGG::ExpHeap* g_gameHeaps[3];

[[nsmbw_data(0x8042A72C)]]
EGG::ExpHeap* g_archiveHeap;

[[nsmbw_data(0x8042A730)]]
EGG::ExpHeap* g_commandHeap;

[[nsmbw_data(0x8042A734)]]
EGG::ExpHeap* g_dylinkHeap;

[[nsmbw(0x8016E630)]]
EGG::Heap* setCurrentHeap(EGG::Heap* heap);

} // namespace mHeap
