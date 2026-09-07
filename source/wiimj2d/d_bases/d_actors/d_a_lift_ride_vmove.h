#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftRideVMove_c : public dActorState_c {
    SIZE_ASSERT(0x5A0);
    VTABLE(0x060, fBase_c, 0x809689AC);
    // 0x80968990 g_profile_AC_LIFT_RIDE_VMOVE
    // 0x80844BF0 daLiftRideVMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftRideVMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80845180
     * executeState:    0x808451F0
     * finalizeState:   0x808451C0
     */
    sState_Extern(0x8099B768, daLiftRideVMove_c, NoDisp);

    /*
     * initializeState: 0x80845260
     * executeState:    0x808452C0
     * finalizeState:   0x808452B0
     */
    sState_Extern(0x8099B7A8, daLiftRideVMove_c, Move);

    /*
     * initializeState: 0x808453A0
     * executeState:    0x808453E0
     * finalizeState:   0x808453D0
     */
    sState_Extern(0x8099B7E8, daLiftRideVMove_c, Fall);
};
