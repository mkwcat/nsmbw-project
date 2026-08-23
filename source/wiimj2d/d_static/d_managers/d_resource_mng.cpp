// d_resource_mng.cpp
// NSMBW .text: 0x800DF770 - 0x800DF950
// NSMBW .sbss: 0x8042A318 - 0x8042A31C

#include "d_resource_mng.h"

[[nsmbw_data(0x8042A318)]]
dResMng_c* dResMng_c::m_instance;

[[nsmbw(0x800DF8C0)]]
void dResMng_c::setRes(const char* dir, const char** files, int count, EGG::Heap* heap);
