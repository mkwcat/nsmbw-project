#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBlockLight_c : public dActorState_c {
    SIZE_ASSERT(0x598);
    VTABLE(0x060, fBase_c, 0x80952F20);
    // 0x80952EF0 g_profile_BLOCK_LIGHT
    // 0x807C0180 daBlockLight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBlockLight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x598);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE4 0x807C0810
     * executeState:    VT+0xE8 0x807C0860
     * finalizeState:   VT+0xEC 0x807C0850
     */
    sState_ExternVirtual(0x8099661C, daBlockLight_c, Move);
};
