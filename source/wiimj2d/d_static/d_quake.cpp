// d_quake.cpp
// NSMBW .text: 0x800D8940 - 0x800D91B0

#include "d_quake.h"

[[nsmbw_data(0x8042A2E8)]]
dQuake_c* dQuake_c::m_instance;

[[nsmbw(0x800D8BF0)]]
void dQuake_c::startShock(s8 player, TYPE_SHOCK_e type, int flag, int comboCount, bool grabActive);

[[nsmbw(0x800D8CA0)]]
void dQuake_c::shockMotor(s8 player, TYPE_SHOCK_e type, int flag, bool grabActive);