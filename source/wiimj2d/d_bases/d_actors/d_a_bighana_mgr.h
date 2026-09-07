#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBigHanaMgr_c : public dActorState_c {
    SIZE_ASSERT(0x3E0);
    VTABLE(0x060, fBase_c, 0x809529A8);
    // 0x80952998 g_profile_BIGHANA_MGR
    // 0x807BEA10 daBigHanaMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBigHanaMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BEF70
     * executeState:    0x807BEF90
     * finalizeState:   0x807BEF80
     */
    sState_Extern(0x80996520, daBigHanaMgr_c, Wait);

    /*
     * initializeState: 0x807BEFE0
     * executeState:    0x807BF000
     * finalizeState:   0x807BEFF0
     */
    sState_Extern(0x80996560, daBigHanaMgr_c, None);

    /*
     * initializeState: 0x807BF010
     * executeState:    0x807BF0E0
     * finalizeState:   0x807BF0D0
     */
    sState_Extern(0x809965A0, daBigHanaMgr_c, Waki);
};
