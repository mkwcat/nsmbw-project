#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daPropBlock_c : public dEn_c {
    SIZE_ASSERT(0x890);
    VTABLE(0x060, fBase_c, 0x809785C0);
    // 0x80978570 g_profile_AC_PROP_BLOCK
    // 0x80893940 daPropBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80893970 */
    daPropBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x890);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80894B00
     * executeState:    0x80894B50
     * finalizeState:   0x80894B40
     */
    sState_Extern(0x8099E498, daPropBlock_c, Wait);

    /*
     * initializeState: 0x80894CF0
     * executeState:    0x80894DA0
     * finalizeState:   0x80894D50
     */
    sState_Extern(0x8099E4D8, daPropBlock_c, Carry);

    /*
     * initializeState: 0x80894F70
     * executeState:    0x808950B0
     * finalizeState:   0x80895070
     */
    sState_Extern(0x8099E518, daPropBlock_c, Throw);

    /*
     * initializeState: 0x80895250
     * executeState:    0x80895300
     * finalizeState:   0x808952F0
     */
    sState_Extern(0x8099E558, daPropBlock_c, Down);
};
