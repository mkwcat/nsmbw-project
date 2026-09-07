#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFallFire_c : public dActorState_c {
    SIZE_ASSERT(0x5A8);
    VTABLE(0x060, fBase_c, 0x809595C8);
    // 0x80959408 g_profile_FALL_FIRE
    // 0x807E7680 daFallFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFallFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E7E40
     * executeState:    0x807E7E60
     * finalizeState:   0x807E7E50
     */
    sState_Extern(0x80998198, daFallFire_c, Wait);

    /*
     * initializeState: 0x807E7EC0
     * executeState:    0x807E7F30
     * finalizeState:   0x807E7F20
     */
    sState_Extern(0x809981D8, daFallFire_c, Move);

    /*
     * initializeState: 0x807E7F80
     * executeState:    0x807E8000
     * finalizeState:   0x807E7FF0
     */
    sState_Extern(0x80998218, daFallFire_c, Hit);
};
