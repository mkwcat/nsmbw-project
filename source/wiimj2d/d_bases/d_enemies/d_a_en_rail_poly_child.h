#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnRailPolyChild_c : public dEn_c {
    SIZE_ASSERT(0x730);
    VTABLE(0x060, fBase_c, 0x80B03F10);
    // 0x80B03EE0 g_profile_EN_RAIL_POLY_CHILD
    // 0x80A8E6A0 daEnRailPolyChild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A8E6D0 */
    daEnRailPolyChild_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x730);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A8F430
     * executeState:    0x80A8F450
     * finalizeState:   0x80A8F440
     */
    sState_Extern(0x80B1A4F0, daEnRailPolyChild_c, WaitCtParent);

    /*
     * initializeState: 0x80A8F4F0
     * executeState:    0x80A8F580
     * finalizeState:   0x80A8F570
     */
    sState_Extern(0x80B1A530, daEnRailPolyChild_c, Move);
};
