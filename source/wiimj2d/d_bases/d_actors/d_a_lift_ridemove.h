#pragma once

#include "d_actor_state.h"
#include "d_rc.h"
#include "s_State.h"

class daLiftRideMove_c : public dActorState_c {
    SIZE_ASSERT(0x590);
    VTABLE(0x060, fBase_c, 0x80968BBC);
    // 0x80968B98 g_profile_AC_LIFT_RIDEMOVE
    // 0x80845940 daLiftRideMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftRideMove_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80845D60 */
    bool isAllPlayerOnLift();

    FILL(0x3D0, 0x508);

    /* 0x508 */ dRideRoll_c mRideRoll;

    FILL(0x568, 0x590);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80845FA0
     * executeState:    0x80846000
     * finalizeState:   0x80845FF0
     */
    sState_Extern(0x8099B828, daLiftRideMove_c, NoDisp);

    /*
     * initializeState: 0x80846050
     * executeState:    0x808460C0
     * finalizeState:   0x808460B0
     */
    sState_Extern(0x8099B868, daLiftRideMove_c, Wait);

    /*
     * initializeState: 0x80846190
     * executeState:    0x80846210
     * finalizeState:   0x80846200
     */
    sState_Extern(0x8099B8A8, daLiftRideMove_c, Move);
};
