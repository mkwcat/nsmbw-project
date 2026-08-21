// d_effactor_mng.cpp
// NSMBW .text: 0x80092300 - 0x80092C00

#include "d_effactor_mng.h"

[[nsmbw_data(0x8042A1C8)]]
dEffActorMng_c* dEffActorMng_c::m_instance;

[[nsmbw(0x800923D0)]]
void dEffActorMng_c::execute();

[[nsmbw(0x800925F0)]]
bool dEffActorMng_c::createBlockFragEff(mVec3_c&, unsigned long, s8);
