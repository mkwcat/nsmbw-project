#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftObjbgHMove_c : public dActorState_c {
    SIZE_ASSERT(0x9B38);
    VTABLE(0x0060, fBase_c, 0x80967828);
    // 0x80967810 g_profile_AC_LIFT_OBJBG_HMOVE
    // 0x8083A6D0 daLiftObjbgHMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftObjbgHMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x9B38);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8083AF10
     * executeState:    0x8083AF50
     * finalizeState:   0x8083AF40
     */
    sState_Extern(0x8099B2D0, daLiftObjbgHMove_c, NoDisp);

    /*
     * initializeState: 0x8083AFA0
     * executeState:    0x8083AFD0
     * finalizeState:   0x8083AFC0
     */
    sState_Extern(0x8099B310, daLiftObjbgHMove_c, Move);
};

class daLiftObjbgHMoveBig_c : public daLiftObjbgHMove_c {
    SIZE_ASSERT(0x9B38);
    // 0x8096781C g_profile_AC_LIFT_OBJBG_HMOVE_BIG
    // 0x8083A890 daLiftObjbgHMoveBig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftObjbgHMoveBig_c();
};
