#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoinAngle_c : public daEnCoinMain_c {
    SIZE_ASSERT(0xAF8);
    VTABLE(0x060, fBase_c, 0x80AE260C);
    // 0x80AE2600 g_profile_EN_COIN_ANGLE
    // 0x809E4E20 daEnCoinAngle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoinAngle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0xAF8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E5840
     * executeState:    0x809E5860
     * finalizeState:   0x809E5850
     */
    sState_Extern(0x80B13A08, daEnCoinAngle_c, SearchID);

    /*
     * initializeState: 0x809E58C0
     * executeState:    0x809E5960
     * finalizeState:   0x809E5950
     */
    sState_Extern(0x80B13A48, daEnCoinAngle_c, WaitDown);
};
