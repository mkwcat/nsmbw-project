#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daIceCube_c : public dActorState_c {
    SIZE_ASSERT(0xDA0);
    VTABLE(0x060, fBase_c, 0x8095D858);
    // 0x8095D828 g_profile_ICECUBE
    // 0x807FFFA0 daIceCube_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIceCube_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xDA0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80800700
     * executeState:    0x80800760
     * finalizeState:   0x80800750
     */
    sState_Extern(0x80998FD0, daIceCube_c, Wait);

    /*
     * initializeState: 0x80800770
     * executeState:    0x80800810
     * finalizeState:   0x80800800
     */
    sState_Extern(0x80999010, daIceCube_c, Melt);
};
