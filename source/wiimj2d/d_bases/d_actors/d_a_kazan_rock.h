#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKazanRock_c : public dActorState_c {
    SIZE_ASSERT(0x480);
    VTABLE(0x060, fBase_c, 0x80962768);
    // 0x809626D8 g_profile_KAZAN_ROCK
    // 0x8081EB80 daKazanRock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKazanRock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x480);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8081F5A0
     * executeState:    0x8081F690
     * finalizeState:   0x8081F680
     */
    sState_Extern(0x80999FC8, daKazanRock_c, Fall);

    /*
     * initializeState: 0x8081F7C0
     * executeState:    0x8081F8B0
     * finalizeState:   0x8081F8A0
     */
    sState_Extern(0x8099A008, daKazanRock_c, BigFall);
};
