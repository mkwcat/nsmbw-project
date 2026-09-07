#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFreezer_c : public dActorState_c {
    SIZE_ASSERT(0xDA8);
    VTABLE(0x060, fBase_c, 0x8095C2F8);
    // 0x8095C2C8 g_profile_AC_FREEZER
    // 0x807F7A90 daFreezer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFreezer_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xDA8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F81B0
     * executeState:    0x807F81D0
     * finalizeState:   0x807F81C0
     */
    sState_Extern(0x80998AB0, daFreezer_c, Wait);

    /*
     * initializeState: 0x807F81E0
     * executeState:    0x807F82C0
     * finalizeState:   0x807F82B0
     */
    sState_Extern(0x80998AF0, daFreezer_c, Melt);
};
