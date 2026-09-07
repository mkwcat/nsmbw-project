#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEndingMain_c : public dActorState_c {
    SIZE_ASSERT(0x418);
    VTABLE(0x060, fBase_c, 0x8098A4A0);
    // 0x8098A360 g_profile_AC_ENDING_MAIN
    // 0x80912C60 daEndingMain_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEndingMain_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x418);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80913160
     * executeState:    0x809131A0
     * finalizeState:   0x80913190
     */
    sState_Extern(0x809A1160, daEndingMain_c, DemoStart_Wait);

    /*
     * initializeState: 0x80913220
     * executeState:    0x80913240
     * finalizeState:   0x80913230
     */
    sState_Extern(0x809A11A0, daEndingMain_c, BlockCreate);

    /*
     * initializeState: 0x809132D0
     * executeState:    0x809132F0
     * finalizeState:   0x809132E0
     */
    sState_Extern(0x809A11E0, daEndingMain_c, FadeStartCheck);

    /*
     * initializeState: 0x80913320
     * executeState:    0x80913340
     * finalizeState:   0x80913330
     */
    sState_Extern(0x809A1220, daEndingMain_c, FadeStart);

    /*
     * initializeState: 0x809133C0
     * executeState:    0x809133E0
     * finalizeState:   0x809133D0
     */
    sState_Extern(0x809A1260, daEndingMain_c, FadeEnd);
};
