#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinVolt_c : public daEnCoinMain_c {
    SIZE_ASSERT(0xAE8);
    VTABLE(0x060, fBase_c, 0x80AE40E4);
    // 0x80AE40D8 g_profile_EN_COIN_VOLT
    // 0x809E7DA0 daEnCoinVolt_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinVolt_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0xAE8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E8400
     * executeState:    0x809E8420
     * finalizeState:   0x809E8410
     */
    sState_Extern(0x80B13BC8, daEnCoinVolt_c, SearchID);
};
