#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiAnkoh_c : public dActorState_c {
    SIZE_ASSERT(0x578);
    VTABLE(0x060, fBase_c, 0x8097E260);
    // 0x8097E250 g_profile_WAKI_ANKOH
    // 0x808B3880 daWakiAnkoh_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiAnkoh_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x578);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808B4860
     * executeState:    0x808B4880
     * finalizeState:   0x808B4870
     */
    sState_Extern(0x8099F520, daWakiAnkoh_c, Ready);

    /*
     * initializeState: 0x808B4890
     * executeState:    0x808B48E0
     * finalizeState:   0x808B48D0
     */
    sState_Extern(0x8099F560, daWakiAnkoh_c, Waki);

    /*
     * initializeState: 0x808B4970
     * executeState:    0x808B4990
     * finalizeState:   0x808B4980
     */
    sState_Extern(0x8099F5A0, daWakiAnkoh_c, Wait);
};
