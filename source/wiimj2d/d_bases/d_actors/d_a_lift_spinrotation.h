#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftSpinRotation_c : public dActorState_c {
    SIZE_ASSERT(0x700);
    VTABLE(0x060, fBase_c, 0x80969AA8);
    // 0x80969A28 g_profile_AC_LIFT_SPINROTATION
    // 0x8084C300 daLiftSpinRotation_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftSpinRotation_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x700);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8084D320
     * executeState:    0x8084D340
     * finalizeState:   0x8084D330
     */
    sState_Extern(0x8099BDE8, daLiftSpinRotation_c, Wait);

    /*
     * initializeState: 0x8084D3C0
     * executeState:    0x8084D430
     * finalizeState:   0x8084D420
     */
    sState_Extern(0x8099BE28, daLiftSpinRotation_c, OrderMove);

    /*
     * initializeState: 0x8084D5D0
     * executeState:    0x8084D5F0
     * finalizeState:   0x8084D5E0
     */
    sState_Extern(0x8099BE68, daLiftSpinRotation_c, OrderWait);

    /*
     * initializeState: 0x8084D6D0
     * executeState:    0x8084D790
     * finalizeState:   0x8084D780
     */
    sState_Extern(0x8099BEA8, daLiftSpinRotation_c, ReverseMove);
};
