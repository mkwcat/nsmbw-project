#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daSlipPenguin2Glasses_c : public dActorState_c {
    SIZE_ASSERT(0x460);
    VTABLE(0x060, fBase_c, 0x8097BB10);
    // 0x8097BAD0 g_profile_SLIP_PENGUIN2_GLASSES
    // 0x808A7970 daSlipPenguin2Glasses_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daSlipPenguin2Glasses_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x460);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A7C70
     * executeState:    0x808A7C90
     * finalizeState:   0x808A7C80
     */
    sState_Extern(0x8099F028, daSlipPenguin2Glasses_c, Hold);

    /*
     * initializeState: 0x808A7CA0
     * executeState:    0x808A7D60
     * finalizeState:   0x808A7D50
     */
    sState_Extern(0x8099F068, daSlipPenguin2Glasses_c, Release);
};
