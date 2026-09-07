#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinWind_c : public daEnCoinMain_c {
    SIZE_ASSERT(0xAE8);
    VTABLE(0x060, fBase_c, 0x80AE4DDC);
    // 0x80AE4DD0 g_profile_EN_COIN_WIND
    // 0x809E9510 daEnCoinWind_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinWind_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0xAE8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E9940
     * executeState:    0x809E9960
     * finalizeState:   0x809E9950
     */
    sState_Extern(0x80B13C68, daEnCoinWind_c, WindMove);

    /*
     * initializeState: 0x809E99B0
     * executeState:    0x809E9A90
     * finalizeState:   0x809E9A80
     */
    sState_Extern(0x80B13CA8, daEnCoinWind_c, PowDown);
};
