// d_multi_manager.cpp
// NSMBW .text: 0x800CE8F0 - 0x800CED00

#include "d_multi_manager.h"

[[address_data(0x8042A290)]]
dMultiMng_c* dMultiMng_c::mspInstance;

// TODO
[[address(0x800CE950)]]
void dMultiMng_c::initStage();

// TODO
[[address(0x800CEAC0)]]
void dMultiMng_c::incCoin(int player);