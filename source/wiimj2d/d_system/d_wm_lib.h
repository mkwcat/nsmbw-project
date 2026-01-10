#pragma once

#include "d_system/d_mj2d_game.h"
#include "d_system/d_game_key.h"

enum class STAGE_TYPE_e {
    NORMAL = 0,
    GHOST = 1,
    TOWER = 2,
    CASTLE = 3,
    TOAD = 4,
    ENEMY = 5,
    WARP = 6,
    STAGE_37 = 7, // @unused
    DOOMSHIP = 8,
    HOME = 9,
    PEACH = 10,
    INVALID = 11,
};

namespace dWmLib
{

/* 0x800F9640 */
STAGE_e GetCourseNoFromPointName(const char*);

/* 0x800F9950 */
STAGE_TYPE_e GetCourseTypeFromCourseNo(int);

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

/* 0x800FD4A0 */
dGameKeyCore_c::Type_e isYokoCon(int controllerNo);

/* 0x8031D6B4 */ extern float sc_0x8031D6B4;

} // namespace dWmLib