// d_cc.cpp
// NSMBW .text: 0x8008C200 - 0x8008DC80

#include "d_cc.h"

[[nsmbw(0x8008C200)]]
dCc_c::dCc_c();

/* VT+0x8 */
[[nsmbw(0x8008C260)]]
dCc_c::~dCc_c();

[[nsmbw(0x8008C330)]]
void dCc_c::entry();

[[nsmbw(0x8008C380)]]
void dCc_c::release();

[[nsmbw(0x8008C3E0)]]
void dCc_c::set(dActor_c* actor, sCcDatNewF* collInfo);

[[nsmbw(0x8008C9E0)]]
void dCc_c::execute();