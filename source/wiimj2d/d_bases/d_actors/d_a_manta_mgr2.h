#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daMantaMgr2_c : public dActorState_c {
    SIZE_ASSERT(0x7E0);
    VTABLE(0x060, fBase_c, 0x8096C830);
    // 0x8096C820 g_profile_MANTA_MGR2
    // 0x8085FA10 daMantaMgr2_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMantaMgr2_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x7E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8085FFF0
     * executeState:    0x80860010
     * finalizeState:   0x80860000
     */
    sState_Extern(0x8099C8B0, daMantaMgr2_c, Ready);

    /*
     * initializeState: 0x80860090
     * executeState:    0x808600B0
     * finalizeState:   0x808600A0
     */
    sState_Extern(0x8099C8F0, daMantaMgr2_c, Run);
};
