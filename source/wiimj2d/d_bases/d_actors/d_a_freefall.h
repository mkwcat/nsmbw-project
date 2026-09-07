#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFreefall_c : public dActorState_c {
    SIZE_ASSERT(0x470);
    VTABLE(0x060, fBase_c, 0x8095C130);
    // 0x8095C0F8 g_profile_FREEFALL
    // 0x807F70C0 daFreefall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFreefall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x470);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F7660
     * executeState:    0x807F7680
     * finalizeState:   0x807F7670
     */
    sState_Extern(0x80998A30, daFreefall_c, Search);

    /*
     * initializeState: 0x807F7690
     * executeState:    0x807F76B0
     * finalizeState:   0x807F76A0
     */
    sState_Extern(0x80998A70, daFreefall_c, Move);
};
