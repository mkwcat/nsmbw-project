#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFloorJrCMgr_c : public dActorMultiState_c {
    SIZE_ASSERT(0x500);
    VTABLE(0x060, fBase_c, 0x8095B4E4);
    // 0x8095B4D8 g_profile_FLOOR_JR_C_MGR
    // 0x807F2D30 daFloorJrCMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807F2D60 */
    daFloorJrCMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x414, 0x500);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F3BB0
     * executeState:    0x807F3BD0
     * finalizeState:   0x807F3BC0
     */
    sState_Extern(0x80998830, daFloorJrCMgr_c, Idle);
};
