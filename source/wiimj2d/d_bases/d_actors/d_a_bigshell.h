#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBigShell_c : public dActorState_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80952840);
    // 0x809527C8 g_profile_AC_BIGSHELL
    // 0x807BE0F0 daBigShell_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBigShell_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BE680
     * executeState:    0x807BE6A0
     * finalizeState:   0x807BE690
     */
    sState_Extern(0x80996300, daBigShell_c, Wait);
};
