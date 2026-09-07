#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEnPukuPukuParent_c : public dActorState_c {
    SIZE_ASSERT(0x838);
    VTABLE(0x060, fBase_c, 0x80B03D80);
    // 0x80B03D70 g_profile_EN_PUKUPUKU_PARENT
    // 0x80A8D5B0 daEnPukuPukuParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPukuPukuParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x838);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A8E0D0
     * executeState:    0x80A8E0F0
     * finalizeState:   0x80A8E0E0
     */
    sState_Extern(0x80B1A4B0, daEnPukuPukuParent_c, Move);
};
