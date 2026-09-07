#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnOP_c : public dEn_c {
    SIZE_ASSERT(0x4C30);
    VTABLE(0x0060, fBase_c, 0x80AFEEF0);
    // 0x80AFEEC0 g_profile_EN_OBJ_POL
    // 0x80A77BE0 daEnOP_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnOP_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x4C30);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A788B0
     * executeState:    0x80A788D0
     * finalizeState:   0x80A788C0
     */
    sState_Extern(0x80B195D0, daEnOP_c, Still);

    /*
     * initializeState: 0x80A788E0
     * executeState:    0x80A78970
     * finalizeState:   0x80A78950
     */
    sState_Extern(0x80B19610, daEnOP_c, Vanish);

    /*
     * initializeState: 0x80A78AB0
     * executeState:    0x80A78AD0
     * finalizeState:   0x80A78AC0
     */
    sState_Extern(0x80B19650, daEnOP_c, MoveNormal);
};
