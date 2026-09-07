#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinJump_c : public daEnCoinMain_c {
    SIZE_ASSERT(0x8E8);
    VTABLE(0x060, fBase_c, 0x80AE3A6C);
    // 0x80AE3A60 g_profile_EN_COIN_JUMP
    // 0x809E74D0 daEnCoinJump_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinJump_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0x8E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E7840
     * executeState:    0x809E7940
     * finalizeState:   0x809E7930
     */
    sState_Extern(0x80B13B88, daEnCoinJump_c, Jump);
};
