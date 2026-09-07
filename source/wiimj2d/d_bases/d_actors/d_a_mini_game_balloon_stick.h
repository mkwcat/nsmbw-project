#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daMiniGameBalloonStick_c : public dEn_c {
    SIZE_ASSERT(0x718);
    VTABLE(0x060, fBase_c, 0x8096F720);
    // 0x8096F690 g_profile_MINI_GAME_BALLOON_STICK
    // 0x80864A80 daMiniGameBalloonStick_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80864AB0 */
    daMiniGameBalloonStick_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x718);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80865190
     * executeState:    0x808651A0
     * finalizeState:   0x808651E0
     */
    sState_Extern(0x8099CAB0, daMiniGameBalloonStick_c, ShowRuleWait);

    /*
     * initializeState: 0x808651F0
     * executeState:    0x80865230
     * finalizeState:   0x80865620
     */
    sState_Extern(0x8099CAF0, daMiniGameBalloonStick_c, Move);

    /*
     * initializeState: 0x80865630
     * executeState:    0x80865640
     * finalizeState:   0x80865650
     */
    sState_Extern(0x8099CB70, daMiniGameBalloonStick_c, ShowResultWait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80865660
     * executeState:    VT+0x17C 0x80865670
     * finalizeState:   VT+0x180 0x808656C0
     */
    sState_ExternVirtual(0x8099CB2C, daMiniGameBalloonStick_c, DieFall);
};
