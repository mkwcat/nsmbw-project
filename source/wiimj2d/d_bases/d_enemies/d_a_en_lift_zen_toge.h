#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnLiftZenToge_c : public dEn_c {
    SIZE_ASSERT(0x6B0);
    VTABLE(0x060, fBase_c, 0x80AF9FA8);
    // 0x80AF9C00 g_profile_LIFT_ZEN_TOGE
    // 0x80A5E160 daEnLiftZenToge_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLiftZenToge_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6B0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A5E910
     * executeState:    0x80A5E930
     * finalizeState:   0x80A5E920
     */
    sState_Extern(0x80B18538, daEnLiftZenToge_c, Still);

    /*
     * initializeState: 0x80A5E940
     * executeState:    0x80A5E960
     * finalizeState:   0x80A5E950
     */
    sState_Extern(0x80B18578, daEnLiftZenToge_c, MoveNormal);
};
