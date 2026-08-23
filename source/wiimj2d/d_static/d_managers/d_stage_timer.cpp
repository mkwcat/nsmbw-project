// d_stage_timer.cpp
// NSMBW .text: 0x800E38E0 - 0x800E3BA0

#include "d_stage_timer.h"

[[nsmbw_data(0x8042A350)]]
dStageTimer_c* dStageTimer_c::m_instance;

[[nsmbw(0x800E3A00)]]
void dStageTimer_c::setTimer(short timer);

[[nsmbw(0x800E3A20)]]
void dStageTimer_c::execute();
