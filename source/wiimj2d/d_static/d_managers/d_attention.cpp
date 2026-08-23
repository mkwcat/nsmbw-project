// d_attention.cpp
// NSMBW .text: 0x800690F0 - 0x80069500

#include "d_attention.h"

[[nsmbw_data(0x8042A030)]]
dAttention_c* dAttention_c::mspInstance;

[[nsmbw(0x800691B0)]]
void dAttention_c::update();
