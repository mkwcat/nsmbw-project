#pragma once

#include "d_info.h"
#include "d_scene.h"

class dScRestartCrsin_c : public dScene_c {
    SIZE_ASSERT(0x74);
    VTABLE(0x60, fBase_c, 0x8098D3D8);
    // 0x8098D3D0 g_profile_RESTART_CRSIN
    // 0x80923970 dScRestartCrsin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x809239A0 */
    dScRestartCrsin_c();

public:
    // Static Methods
    // ^^^^^^

    /* 0x801018E0 */
    static void startTitle(u8 isDemo, bool);

    /* 0x801019D0 */
    static void reStartPeachCastle();

public:
    // Static Variables
    // ^^^^^^

    /* 0x80374060 */ static dInfo_c::StartGameInfo_s m_startGameInfo;
};
