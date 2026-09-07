#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBlackPakkun_c : public dEn_c {
    SIZE_ASSERT(0x600);
    VTABLE(0x060, fBase_c, 0x80ADAC68);
    // 0x80ADAC28 g_profile_EN_BLACK_PAKKUN
    // 0x809BE200 daEnBlackPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlackPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x600);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809BE850
     * executeState:    0x809BE870
     * finalizeState:   0x809BE860
     */
    sState_Extern(0x80B12538, daEnBlackPakkun_c, IceWait);

    /*
     * initializeState: 0x809BE980
     * executeState:    0x809BE9A0
     * finalizeState:   0x809BE990
     */
    sState_Extern(0x80B12578, daEnBlackPakkun_c, Move);
};
