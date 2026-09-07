#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnGreenCoin_c : public dEn_c {
    SIZE_ASSERT(0x630);
    VTABLE(0x060, fBase_c, 0x80AECDB0);
    // 0x80AECD48 g_profile_EN_GREENCOIN
    // 0x80A0E700 daEnGreenCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGreenCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x630);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A0EF70
     * executeState:    0x80A0EF90
     * finalizeState:   0x80A0EF80
     */
    sState_Extern(0x80B15690, daEnGreenCoin_c, Wait);

    /*
     * initializeState: 0x80A0F060
     * executeState:    0x80A0F080
     * finalizeState:   0x80A0F070
     */
    sState_Extern(0x80B156D0, daEnGreenCoin_c, Move);
};
