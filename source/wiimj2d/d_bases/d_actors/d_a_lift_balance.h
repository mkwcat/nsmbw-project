#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftBalance_c : public dActorState_c {
    SIZE_ASSERT(0x4A0);
    VTABLE(0x060, fBase_c, 0x80966808);
    // 0x809667D8 g_profile_AC_LIFT_BALANCE
    // 0x808349E0 daLiftBalance_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftBalance_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80835200
     * executeState:    0x80835220
     * finalizeState:   0x80835210
     */
    sState_Extern(0x8099AF88, daLiftBalance_c, Wait);

    /*
     * initializeState: 0x80835280
     * executeState:    0x808352A0
     * finalizeState:   0x80835290
     */
    sState_Extern(0x8099AFC8, daLiftBalance_c, Move);

    /*
     * initializeState: 0x80835540
     * executeState:    0x80835560
     * finalizeState:   0x80835550
     */
    sState_Extern(0x8099B008, daLiftBalance_c, End);
};
