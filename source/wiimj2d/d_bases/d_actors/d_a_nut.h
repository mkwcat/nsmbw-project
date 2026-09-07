#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daNut_c : public dActorState_c {
    SIZE_ASSERT(0x4C8);
    VTABLE(0x060, fBase_c, 0x80971D00);
    // 0x80971CD8 g_profile_NUT
    // 0x80873200 daNut_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daNut_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80873B50
     * executeState:    0x80873B90
     * finalizeState:   0x80873B80
     */
    sState_Extern(0x8099D260, daNut_c, Wait);

    /*
     * initializeState: 0x80873CF0
     * executeState:    0x80873D10
     * finalizeState:   0x80873D00
     */
    sState_Extern(0x8099D2A0, daNut_c, Move);
};
