#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daStand_c : public dActorState_c {
    SIZE_ASSERT(0x518);
    VTABLE(0x060, fBase_c, 0x8097C320);
    // 0x8097C2E0 g_profile_AC_STAND
    // 0x808A9BB0 daStand_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daStand_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x518);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A9F40
     * executeState:    0x808A9F60
     * finalizeState:   0x808A9F50
     */
    sState_Extern(0x8099F168, daStand_c, Wait);
};
