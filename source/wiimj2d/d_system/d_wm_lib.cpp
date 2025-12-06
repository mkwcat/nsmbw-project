// d_wm_lib.cpp
// NSMBW .text: 0x800F9380 - 0x800FD6A0

#include "d_wm_lib.h"

namespace dWmLib
{

[[address_data(0x8031D6B4)]]
float sc_0x8031D6B4;

[[address(0x800F9640)]]
STAGE_e GetCourseNoFromPointName(const char*);

[[address(0x800F9950)]]
STAGE_TYPE_e GetCourseTypeFromCourseNo(int);

[[address(0x800FBAF0)]]
void procCourseClear(bool isSecretExit, bool isSuperGuide, WORLD_e world, STAGE_e stage);

[[address(0x800FBE40)]]
void procCourseGameOver(bool keepKinokoMessageState);

[[address(0x800FCAD0)]]
bool IsSingleEntry();

[[address(0x800FCEC0)]]
void ClearKinopioChukan();

[[address(0x800FD1C0)]]
void RestoreKinopioHelpGameInfo();

} // namespace dWmLib