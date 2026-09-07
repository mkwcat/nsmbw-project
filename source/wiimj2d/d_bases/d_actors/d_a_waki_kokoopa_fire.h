#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiKokoopaFire_c : public dActorState_c {
    SIZE_ASSERT(0x420);
    VTABLE(0x060, fBase_c, 0x8097E9D8);
    // 0x8097E9A8 g_profile_WAKI_KOKOOPA_FIRE
    // 0x808B6800 daWakiKokoopaFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiKokoopaFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x420);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808B75C0
     * executeState:    0x808B75E0
     * finalizeState:   0x808B75D0
     */
    sState_Extern(0x8099F6D0, daWakiKokoopaFire_c, Waki);
};
