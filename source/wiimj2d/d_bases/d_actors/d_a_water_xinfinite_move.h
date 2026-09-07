#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWaterXinfinitMove_c : public dActorState_c {
    SIZE_ASSERT(0x1A4C8);
    VTABLE(0x00060, fBase_c, 0x80980630);
    // 0x80980620 g_profile_AC_WATER_XINFINITE_MOVE
    // 0x808C0850 daWaterXinfinitMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterXinfinitMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x003D0, 0x1A4C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808C0F40
     * executeState:    0x808C0F60
     * finalizeState:   0x808C0F50
     */
    sState_Extern(0x8099FE90, daWaterXinfinitMove_c, SwitchWait);

    /*
     * initializeState: 0x808C1030
     * executeState:    0x808C1060
     * finalizeState:   0x808C1050
     */
    sState_Extern(0x8099FED0, daWaterXinfinitMove_c, SwitchMove);

    /*
     * initializeState: 0x808C1180
     * executeState:    0x808C11A0
     * finalizeState:   0x808C1190
     */
    sState_Extern(0x8099FF10, daWaterXinfinitMove_c, Move);
};
