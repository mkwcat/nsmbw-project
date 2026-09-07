#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnChochinAnkoh_c : public dEn_c {
    SIZE_ASSERT(0x6E0);
    VTABLE(0x060, fBase_c, 0x80AE01F8);
    // 0x80AE01A0 g_profile_EN_CHOCHIN_ANKOH
    // 0x809D5BB0 daEnChochinAnkoh_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnChochinAnkoh_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809D67C0
     * executeState:    0x809D6870
     * finalizeState:   0x809D6860
     */
    sState_Extern(0x80B130F8, daEnChochinAnkoh_c, Swim);

    /*
     * initializeState: 0x809D6910
     * executeState:    0x809D6A60
     * finalizeState:   0x809D6A50
     */
    sState_Extern(0x80B13138, daEnChochinAnkoh_c, LrSwim);

    /*
     * initializeState: 0x809D6B50
     * executeState:    0x809D6B90
     * finalizeState:   0x809D6B80
     */
    sState_Extern(0x80B13178, daEnChochinAnkoh_c, LrTurnSwim);

    /*
     * initializeState: 0x809D6C30
     * executeState:    0x809D6CA0
     * finalizeState:   0x809D6C90
     */
    sState_Extern(0x80B131B8, daEnChochinAnkoh_c, Wait);
};
