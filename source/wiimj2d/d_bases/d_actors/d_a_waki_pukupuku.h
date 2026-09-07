#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiPukuPuku_c : public dActorState_c {
    SIZE_ASSERT(0x438);
    VTABLE(0x060, fBase_c, 0x8097EF30);
    // 0x8097EF20 g_profile_AC_WAKI_PUKUPUKU
    // 0x808B9730 daWakiPukuPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiPukuPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x438);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BA0C0
     * executeState:    0x808BA0F0
     * finalizeState:   0x808BA0E0
     */
    sState_Extern(0x8099F850, daWakiPukuPuku_c, NormalWaki);

    /*
     * initializeState: 0x808BA1E0
     * executeState:    0x808BA220
     * finalizeState:   0x808BA210
     */
    sState_Extern(0x8099F890, daWakiPukuPuku_c, SearchWaki);
};
