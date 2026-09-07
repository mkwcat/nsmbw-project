#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnRailPoly_c : public dEn_c {
    SIZE_ASSERT(0x718);
    VTABLE(0x060, fBase_c, 0x80B04ABC);
    // 0x80B04A90 g_profile_EN_RAIL_POLYGON
    // 0x80A914F0 daEnRailPoly_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRailPoly_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x718);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A91D70
     * executeState:    0x80A91DD0
     * finalizeState:   0x80A91DC0
     */
    sState_Extern(0x80B1A670, daEnRailPoly_c, RailMove);

    /*
     * initializeState: 0x80A92270
     * executeState:    0x80A922A0
     * finalizeState:   0x80A92290
     */
    sState_Extern(0x80B1A6B0, daEnRailPoly_c, RailMoveEnd);

    /*
     * initializeState: 0x80A922B0
     * executeState:    0x80A922F0
     * finalizeState:   0x80A922E0
     */
    sState_Extern(0x80B1A6F0, daEnRailPoly_c, Drop);
};
