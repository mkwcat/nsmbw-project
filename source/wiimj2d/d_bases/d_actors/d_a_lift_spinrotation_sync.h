#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftSpinRotationSync_c : public dActorState_c {
    SIZE_ASSERT(0x708);
    VTABLE(0x060, fBase_c, 0x80969D08);
    // 0x80969CF8 g_profile_AC_LIFT_SPINROTATION_SYNC
    // 0x8084DF20 daLiftSpinRotationSync_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftSpinRotationSync_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x708);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8084E500
     * executeState:    0x8084E520
     * finalizeState:   0x8084E510
     */
    sState_Extern(0x8099BEE8, daLiftSpinRotationSync_c, SearchID);
};
