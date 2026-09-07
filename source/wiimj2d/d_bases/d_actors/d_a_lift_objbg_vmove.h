#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftObjbgVMove_c : public dActorState_c {
    SIZE_ASSERT(0x9B18);
    VTABLE(0x0060, fBase_c, 0x80967A44);
    // 0x80967A38 g_profile_AC_LIFT_OBJBG_VMOVE
    // 0x8083B4E0 daLiftObjbgVMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftObjbgVMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x9B18);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8083BA20
     * executeState:    0x8083BA60
     * finalizeState:   0x8083BA50
     */
    sState_Extern(0x8099B350, daLiftObjbgVMove_c, NoDisp);

    /*
     * initializeState: 0x8083BAB0
     * executeState:    0x8083BB30
     * finalizeState:   0x8083BB10
     */
    sState_Extern(0x8099B390, daLiftObjbgVMove_c, Move);
};
