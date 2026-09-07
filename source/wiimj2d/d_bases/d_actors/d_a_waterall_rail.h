#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWaterAllRail_c : public dActorState_c {
    SIZE_ASSERT(0x1A4C0);
    VTABLE(0x00060, fBase_c, 0x809808C0);
    // 0x809808B0 g_profile_AC_WATERALL_RAIL
    // 0x808C1760 daWaterAllRail_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterAllRail_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x003D0, 0x1A4C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808C1DA0
     * executeState:    0x808C1DC0
     * finalizeState:   0x808C1DB0
     */
    sState_Extern(0x8099FF50, daWaterAllRail_c, SearchNiceBoat);

    /*
     * initializeState: 0x808C1E30
     * executeState:    0x808C1E50
     * finalizeState:   0x808C1E40
     */
    sState_Extern(0x8099FF90, daWaterAllRail_c, RailMove);

    /*
     * initializeState: 0x808C1ED0
     * executeState:    0x808C1EF0
     * finalizeState:   0x808C1EE0
     */
    sState_Extern(0x8099FFD0, daWaterAllRail_c, RailEnd);
};
