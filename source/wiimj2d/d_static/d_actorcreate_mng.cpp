// d_actorcreate_mng.cpp
// NSMBW .text: 0x80068040 - 0x80069020

#include "d_actorcreate_mng.h"

[[nsmbw_data(0x8042A028)]]
dActorCreateMng_c* dActorCreateMng_c::m_instance;

[[nsmbw(0x80068620)]]
void dActorCreateMng_c::execute();
