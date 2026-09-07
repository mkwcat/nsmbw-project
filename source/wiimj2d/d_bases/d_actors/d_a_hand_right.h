#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daHandLight_c : public dActorState_c {
    SIZE_ASSERT(0x5D8);
    VTABLE(0x060, fBase_c, 0x8095D190);
    // 0x8095D0F8 g_profile_HAND_RIGHT
    // 0x807FD930 daHandLight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daHandLight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5D8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE4 0x807FE3C0
     * executeState:    VT+0xE8 0x807FE470
     * finalizeState:   VT+0xEC 0x807FE460
     */
    sState_ExternVirtual(0x80998E3C, daHandLight_c, Move);
};
