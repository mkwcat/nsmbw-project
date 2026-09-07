#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daCopyRight_c : public dActorState_c {
    SIZE_ASSERT(0x430);
    VTABLE(0x060, fBase_c, 0x80952BD8);
    // 0x80952B98 g_profile_AC_COPYRIGHT
    // 0x807BF760 daCopyRight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCopyRight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x430);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BFA70
     * executeState:    0x807BFA90
     * finalizeState:   0x807BFA80
     */
    sState_Extern(0x809965E0, daCopyRight_c, Wait);
};
