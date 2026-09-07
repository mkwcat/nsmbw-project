#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRemoDoor_c : public dActorState_c {
    SIZE_ASSERT(0x430);
    VTABLE(0x060, fBase_c, 0x80978A00);
    // 0x809789C8 g_profile_REMO_DOOR
    // 0x808958E0 daRemoDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRemoDoor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x430);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80895BB0
     * executeState:    0x80895BD0
     * finalizeState:   0x80895BC0
     */
    sState_Extern(0x8099E598, daRemoDoor_c, OpenReady);

    /*
     * initializeState: 0x80895C50
     * executeState:    0x80895CB0
     * finalizeState:   0x80895CA0
     */
    sState_Extern(0x8099E5D8, daRemoDoor_c, Open);

    /*
     * initializeState: 0x80895D50
     * executeState:    0x80895DB0
     * finalizeState:   0x80895D60
     */
    sState_Extern(0x8099E618, daRemoDoor_c, Close);
};
