// d_switchflag_mng.cpp
// NSMBW .text: 0x800E3BD0 - 0x800E46E0

#include "d_switchflag_mng.h"

[[nsmbw_data(0x8042A358)]]
dSwitchFlagMng_c* dSwitchFlagMng_c::m_instance;

[[nsmbw(0x800E4100)]]
void dSwitchFlagMng_c::execute();
