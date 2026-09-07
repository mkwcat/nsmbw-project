#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinWater_c : public daEnCoinMain_c {
    SIZE_ASSERT(0xAE0);
    VTABLE(0x060, fBase_c, 0x80AE4764);
    // 0x80AE4758 g_profile_EN_COIN_WATER
    // 0x809E88D0 daEnCoinWater_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinWater_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0xAE0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E9060
     * executeState:    0x809E9080
     * finalizeState:   0x809E9070
     */
    sState_Extern(0x80B13C08, daEnCoinWater_c, Wait);
};
