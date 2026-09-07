#pragma once

#include "d_base.h"
#include "s_State.h"

class dGameOver_c : public dBase_c {
    SIZE_ASSERT(0x37C);
    VTABLE(0x060, fBase_c, 0x80945158);
    // 0x80944E70 g_profile_GAME_OVER
    // 0x80788510 dGameOver_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80788540 */
    dGameOver_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x37C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80788CA0
     * executeState:    0x80788CB0
     * finalizeState:   0x80788D30
     */
    sState_Extern(0x80992A40, dGameOver_c, FadeInEndWait);

    /*
     * initializeState: 0x80788D50
     * executeState:    0x80788DA0
     * finalizeState:   0x80788E00
     */
    sState_Extern(0x80992A80, dGameOver_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x80788E10
     * executeState:    0x80788E50
     * finalizeState:   0x80788E80
     */
    sState_Extern(0x80992AC0, dGameOver_c, DispEndWait);

    /*
     * initializeState: 0x80788E90
     * executeState:    0x80788EA0
     * finalizeState:   0x80788F10
     */
    sState_Extern(0x80992B00, dGameOver_c, ExitAnimeEndWait);
};
