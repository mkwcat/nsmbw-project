#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBigMet_c : public dEn_c {
    SIZE_ASSERT(0x798);
    VTABLE(0x060, fBase_c, 0x80AD8920);
    // 0x80AD88F8 g_profile_EN_BIG_MET
    // 0x809B65F0 daEnBigMet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigMet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x798);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809B6D00
     * executeState:    0x809B6D30
     * finalizeState:   0x809B6D20
     */
    sState_Extern(0x80B120F8, daEnBigMet_c, Move);

    /*
     * initializeState: 0x809B6DB0
     * executeState:    0x809B6DE0
     * finalizeState:   0x809B6DD0
     */
    sState_Extern(0x80B12138, daEnBigMet_c, Turn);
};
