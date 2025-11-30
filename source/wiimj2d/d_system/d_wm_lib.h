#pragma once

#include "d_system/d_mj2d_game.h"

namespace dWmLib
{

/* 0x800FBAF0 @unofficial */
void procCourseClear(bool isSecretExit, bool isSuperGuide, WORLD_e world, STAGE_e stage);

/* 0x800FBE40 */
void procCourseGameOver(bool keepKinokoMessageState);

/* 0x800FCAD0 */
bool IsSingleEntry();

/* 0x800FCEC0 */
void ClearKinopioChukan();

/* 0x800FD1C0 */
void RestoreKinopioHelpGameInfo();

/* 0x8031D6B4 */ extern float sc_0x8031D6B4;

} // namespace dWmLib