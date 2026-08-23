// eggScreen.cpp
// NSMBW .text: 0x802D0D90 - 0x802D2060

#include "eggScreen.h"

namespace EGG {

[[nsmbw(0x8042B1E8)]]
Screen::TVMode Screen::sTVMode;

[[nsmbw(0x80350820)]]
Screen::TVModeInfo Screen::sTVModeInfo[TVMode::TV_MODE_MAX];

[[nsmbw(0x802D0FB0)]]
Screen::Screen();

/* VT+0x0C */
[[nsmbw(0x802D1230)]]
void Screen::SetProjectionGX() const;

} // namespace EGG
