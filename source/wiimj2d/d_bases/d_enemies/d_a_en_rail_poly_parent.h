#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEnRailPolyParent_c : public dActorState_c {
    SIZE_ASSERT(0x408);
    VTABLE(0x060, fBase_c, 0x80B04848);
    // 0x80B04838 g_profile_EN_RAIL_POLY_PARENT
    // 0x80A90830 daEnRailPolyParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRailPolyParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x408);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A90EA0
     * executeState:    0x80A90EC0
     * finalizeState:   0x80A90EB0
     */
    sState_Extern(0x80B1A570, daEnRailPolyParent_c, RailMoveWait);

    /*
     * initializeState: 0x80A90980
     * executeState:    0x80A909E0
     * finalizeState:   0x80A909D0
     */
    sState_Extern(0x80B1A5B0, daEnRailPolyParent_c, RailMove);

    /*
     * initializeState: 0x80A90F10
     * executeState:    0x80A90F40
     * finalizeState:   0x80A90F30
     */
    sState_Extern(0x80B1A5F0, daEnRailPolyParent_c, RailMoveEnd);

    /*
     * initializeState: 0x80A90F50
     * executeState:    0x80A90F90
     * finalizeState:   0x80A90F80
     */
    sState_Extern(0x80B1A630, daEnRailPolyParent_c, Drop);
};
