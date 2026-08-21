// d_dvd.cpp
// NSMBW .text: 0x8008F460 - 0x8008F920

#include "d_dvd.h"

namespace dDvd
{

[[nsmbw(0x8008F110)]]
void create(s32, EGG::Heap*, EGG::Heap*);

[[nsmbw(0x8008F140)]]
loader_c::loader_c();

[[nsmbw(0x8008F170)]]
loader_c::~loader_c();

[[nsmbw(0x8008F1B0)]]
void* loader_c::request(const char* path, u8 direction, EGG::Heap* heap);

[[nsmbw(0x8008F2B0)]]
bool loader_c::remove();

[[nsmbw(0x8008F380)]]
void loader_c::freeHeap();

} // namespace dDvd