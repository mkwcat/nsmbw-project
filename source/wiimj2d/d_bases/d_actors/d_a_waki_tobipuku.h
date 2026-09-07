#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiTobiPuku_c : public dActorState_c {
    SIZE_ASSERT(0x3E0);
    VTABLE(0x060, fBase_c, 0x8097F358);
    // 0x8097F348 g_profile_AC_WAKI_TOBIPUKU
    // 0x808BAED0 daWakiTobiPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiTobiPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BB390
     * executeState:    0x808BB3B0
     * finalizeState:   0x808BB3A0
     */
    sState_Extern(0x8099F918, daWakiTobiPuku_c, NormalWaki);
};
