#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRemoSlideDoor_c : public dActorState_c {
    SIZE_ASSERT(0x438);
    VTABLE(0x060, fBase_c, 0x80978EC8);
    // 0x80978E90 g_profile_REMO_SLIDE_DOOR
    // 0x80897630 daRemoSlideDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRemoSlideDoor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x438);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808978D0
     * executeState:    0x808978F0
     * finalizeState:   0x808978E0
     */
    sState_Extern(0x8099E758, daRemoSlideDoor_c, OpenReady);

    /*
     * initializeState: 0x80897970
     * executeState:    0x80897990
     * finalizeState:   0x80897980
     */
    sState_Extern(0x8099E798, daRemoSlideDoor_c, Open);

    /*
     * initializeState: 0x80897A40
     * executeState:    0x80897A60
     * finalizeState:   0x80897A50
     */
    sState_Extern(0x8099E7D8, daRemoSlideDoor_c, Close);
};
