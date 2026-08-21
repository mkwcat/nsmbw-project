// d_actor_mng.cpp
// NSMBW .text: 0x80066380 - 0x80066FB0

#include "d_actor_mng.h"

[[nsmbw_data(0x8042A020)]]
dActorMng_c* dActorMng_c::m_instance;

[[nsmbw(0x80066540)]]
bool dActorMng_c::envAllWaterCheck();

[[nsmbw(0x80066EC0)]]
void dActorMng_c::finalUpdate();

[[nsmbw(0x80066F70)]]
void dActorMng_c::execute();
