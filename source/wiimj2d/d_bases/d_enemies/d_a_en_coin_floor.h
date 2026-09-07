#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinFloor_c : public daEnCoinMain_c {
    SIZE_ASSERT(0x918);
    VTABLE(0x060, fBase_c, 0x80AE2CD4);
    // 0x80AE2CC8 g_profile_EN_COIN_FLOOR
    // 0x809E5F70 daEnCoinFloor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinFloor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0x918);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E6620
     * executeState:    0x809E6640
     * finalizeState:   0x809E6630
     */
    sState_Extern(0x80B13A88, daEnCoinFloor_c, FloorSearch);

    /*
     * initializeState: 0x809E66C0
     * executeState:    0x809E66E0
     * finalizeState:   0x809E66D0
     */
    sState_Extern(0x80B13AC8, daEnCoinFloor_c, AngleMove);
};
