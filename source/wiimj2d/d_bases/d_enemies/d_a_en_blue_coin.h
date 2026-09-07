#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnBlueCoin_c : public daEnCoinMain_c {
    SIZE_ASSERT(0x940);
    VTABLE(0x060, fBase_c, 0x80ADD1DC);
    // 0x80ADD1A0 g_profile_EN_BLUE_COIN
    // 0x809C7D40 daEnBlueCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlueCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0x940);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C8520
     * executeState:    0x809C8540
     * finalizeState:   0x809C8530
     */
    sState_Extern(0x80B129C8, daEnBlueCoin_c, Wait);

    /*
     * initializeState: 0x809C85F0
     * executeState:    0x809C86C0
     * finalizeState:   0x809C86B0
     */
    sState_Extern(0x80B12A08, daEnBlueCoin_c, DemoUp);
};
