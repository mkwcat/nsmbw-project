// d_WarningManager.cpp
// NSMBW .text: 0x8010D270 - 0x8010F080

#include "d_WarningManager.h"

[[nsmbw_data(0x8042A5B8)]]
dWarningManager_c* dWarningManager_c::m_instance;

[[nsmbw_data(0x8042A5C0)]]
s32 dWarningManager_c::m_WarningForbid;

[[nsmbw(0x8010E710)]]
void dWarningManager_c::onControllerCut(int player);
