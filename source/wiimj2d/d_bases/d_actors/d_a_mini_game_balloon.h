#pragma once

#include "d_enemy.h"

class daMiniGameBalloon_c : public dEn_c {
    SIZE_ASSERT(0x858);
    VTABLE(0x060, fBase_c, 0x8096F2D8);
    // 0x8096F220 g_profile_MINI_GAME_BALLOON
    // 0x808638C0 daMiniGameBalloon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMiniGameBalloon_c();

public:
    // Virtual Functions
    // ^^^^^^

    /* 0x80864170 */
    bool hitCallback_Cannon(dCc_c* self, dCc_c* other);

public:
    // Instance Methods
    // ^^^^^^

    void EffectBalloonGet(int playerType, mVec3_c* effPos);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x858);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80863F60
     * executeState:    0x80863F70
     * finalizeState:   0x80863FF0
     */
    sState_Extern(0x8099C9F0, daMiniGameBalloon_c, ShowRuleWait);

    /*
     * initializeState: 0x80864000
     * executeState:    0x80864010
     * finalizeState:   0x80864090
     */
    sState_Extern(0x8099CA30, daMiniGameBalloon_c, Move);

    /*
     * initializeState: 0x808640A0
     * executeState:    0x808640B0
     * finalizeState:   0x808640C0
     */
    sState_Extern(0x8099CA70, daMiniGameBalloon_c, ShowResultWait);
};
