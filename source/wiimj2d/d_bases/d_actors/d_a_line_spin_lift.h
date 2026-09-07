#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLineSpinLift_c : public dActorState_c {
    SIZE_ASSERT(0x700);
    VTABLE(0x060, fBase_c, 0x8096B94C);
    // 0x8096B928 g_profile_LINE_SPIN_LIFT
    // 0x808581A0 daLineSpinLift_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLineSpinLift_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x700);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80858BA0
     * executeState:    0x80858BC0
     * finalizeState:   0x80858BB0
     */
    sState_Extern(0x8099C508, daLineSpinLift_c, Fall);

    /*
     * initializeState: 0x80858C60
     * executeState:    0x80858C80
     * finalizeState:   0x80858C70
     */
    sState_Extern(0x8099C548, daLineSpinLift_c, Wait);

    /*
     * initializeState: 0x80858D10
     * executeState:    0x80858D30
     * finalizeState:   0x80858D20
     */
    sState_Extern(0x8099C588, daLineSpinLift_c, Move);
};
