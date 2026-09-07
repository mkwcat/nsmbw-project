#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBattleGame_c : public dActorState_c {
    SIZE_ASSERT(0x3E0);
    VTABLE(0x060, fBase_c, 0x80951620);
    // 0x80951610 g_profile_AC_BATTLE_GAME
    // 0x807B91B0 daBattleGame_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBattleGame_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807B9330
     * executeState:    0x807B9350
     * finalizeState:   0x807B9340
     */
    sState_Extern(0x80995F10, daBattleGame_c, DemoStart_Wait);

    /*
     * initializeState: 0x807B93D0
     * executeState:    0x807B9400
     * finalizeState:   0x807B93F0
     */
    sState_Extern(0x80995F50, daBattleGame_c, DemoStart_SoundStartWait);

    /*
     * initializeState: 0x807B94A0
     * executeState:    0x807B94C0
     * finalizeState:   0x807B94B0
     */
    sState_Extern(0x80995F90, daBattleGame_c, DemoStart_SoundEndWait);

    /*
     * initializeState: 0x807B94D0
     * executeState:    0x807B94F0
     * finalizeState:   0x807B94E0
     */
    sState_Extern(0x80995FD0, daBattleGame_c, DemoStart_End);
};
