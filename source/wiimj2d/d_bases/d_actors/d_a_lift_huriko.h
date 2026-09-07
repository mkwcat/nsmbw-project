#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftHuriko_c : public dActorState_c {
    SIZE_ASSERT(0x550);
    VTABLE(0x060, fBase_c, 0x80967290);
    // 0x809671E0 g_profile_LIFT_HURIKO
    // 0x80838020 daLiftHuriko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftHuriko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x550);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80838EA0
     * executeState:    0x80838EC0
     * finalizeState:   0x80838EB0
     */
    sState_Extern(0x8099B190, daLiftHuriko_c, Search);

    /*
     * initializeState: 0x80838ED0
     * executeState:    0x80838EF0
     * finalizeState:   0x80838EE0
     */
    sState_Extern(0x8099B1D0, daLiftHuriko_c, Move);
};
