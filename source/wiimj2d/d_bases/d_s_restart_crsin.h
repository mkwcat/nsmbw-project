#pragma once

#include "d_static/d_info.h"
#include "d_static/d_scene.h"

class dScRestartCrsin_c : public dScene_c {
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
