#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinJugem_c : public daEnCoinMain_c {
    SIZE_ASSERT(0xA00);
    VTABLE(0x060, fBase_c, 0x80AE33A8);
    // 0x80AE3390 g_profile_EN_COIN_JUGEM
    // 0x809E6BE0 daEnCoinJugem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinJugem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0xA00);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E6F00
     * executeState:    0x809E6F20
     * finalizeState:   0x809E6F10
     */
    sState_Extern(0x80B13B08, daEnCoinJugem_c, JugemHold);

    /*
     * initializeState: 0x809E6F50
     * executeState:    0x809E6F70
     * finalizeState:   0x809E6F60
     */
    sState_Extern(0x80B13B48, daEnCoinJugem_c, Jugemthrow);
};
