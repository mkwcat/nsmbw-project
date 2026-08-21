// d_flag_ctrl.cpp
// NSMBW .text: 0x800B0EA0 - 0x800B11D0

#include "d_flag_ctrl.h"

[[nsmbw_data(0x8042A210)]]
dFlagCtrl_c* dFlagCtrl_c::m_instance;

[[nsmbw(0x800B0FD0)]]
u16 dFlagCtrl_c::getFlagData(u16 courseNum, float x, float y);

[[nsmbw(0x800B1100)]]
void dFlagCtrl_c::setFlagData(u16 courseNum, float x, float y, u16 data);
