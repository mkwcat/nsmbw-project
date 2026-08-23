// d_s_crsin_static.cpp
// NSMBW .sbss: 0x8042A490 - 0x8042A498

#include "d_s_crsin.h"

[[nsmbw_data(0x8042A490)]]
bool dScCrsin_c::m_isDispOff;

[[nsmbw_data(0x8042A494)]]
dScCrsin_c* dScCrsin_c::m_instance;
