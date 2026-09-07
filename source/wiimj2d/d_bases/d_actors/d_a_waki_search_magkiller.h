#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiSearchMagKiller_c : public dActorState_c {
    SIZE_ASSERT(0x3D8);
    VTABLE(0x060, fBase_c, 0x8097F0F0);
    // 0x8097F0E0 g_profile_AC_WAKI_SEARCH_MAGKILLER
    // 0x808BA840 daWakiSearchMagKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiSearchMagKiller_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BAA00
     * executeState:    0x808BAA20
     * finalizeState:   0x808BAA10
     */
    sState_Extern(0x8099F8D0, daWakiSearchMagKiller_c, Wait);
};
