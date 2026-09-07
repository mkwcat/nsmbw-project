#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEnGuraRock_c : public dActorState_c {
    SIZE_ASSERT(0x488);
    VTABLE(0x060, fBase_c, 0x80AED150);
    // 0x80AED108 g_profile_EN_GURA_ROCK
    // 0x80A0F4E0 daEnGuraRock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGuraRock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x488);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A0FBC0
     * executeState:    0x80A0FBE0
     * finalizeState:   0x80A0FBD0
     */
    sState_Extern(0x80B15730, daEnGuraRock_c, Wait);

    /*
     * initializeState: 0x80A0FCD0
     * executeState:    0x80A0FCF0
     * finalizeState:   0x80A0FCE0
     */
    sState_Extern(0x80B15770, daEnGuraRock_c, Fall);

    /*
     * initializeState: 0x80A0FD60
     * executeState:    0x80A0FD80
     * finalizeState:   0x80A0FD70
     */
    sState_Extern(0x80B157B0, daEnGuraRock_c, Still);
};
