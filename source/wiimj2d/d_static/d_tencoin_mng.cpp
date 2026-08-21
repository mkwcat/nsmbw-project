// d_tencoin_mng.cpp
// NSMBW .text: 0x800E75D0 - 0x800E78D0

#include "d_tencoin_mng.h"

[[nsmbw_data(0x8042A3B0)]]
dTenCoinMng_c* dTenCoinMng_c::m_instance;

[[nsmbw(0x800E7640)]]
void dTenCoinMng_c::execute();
