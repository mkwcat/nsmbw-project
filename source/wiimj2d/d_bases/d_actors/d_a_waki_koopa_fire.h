#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiKoopaFire_c : public dActorState_c {
    SIZE_ASSERT(0x4A8);
    VTABLE(0x060, fBase_c, 0x8097EB48);
    // 0x8097EB38 g_profile_AC_WAKI_KOOPA_FIRE
    // 0x808B79B0 daWakiKoopaFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiKoopaFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4A8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x808B7C70
     * executeState:    VT+0xE4 0x808B7C80
     * finalizeState:   VT+0xE8 0x808B7F10
     */
    sState_ExternVirtual(0x8099F70C, daWakiKoopaFire_c, Wait);

    /*
     * initializeState: VT+0xEC 0x808B7F20
     * executeState:    VT+0xF0 0x808B8380
     * finalizeState:   VT+0xF4 0x808B8620
     */
    sState_ExternVirtual(0x8099F74C, daWakiKoopaFire_c, Gush);
};
