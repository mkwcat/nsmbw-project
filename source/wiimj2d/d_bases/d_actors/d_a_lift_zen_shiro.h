#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftZenShiro_c : public dActorState_c {
    SIZE_ASSERT(0x598);
    VTABLE(0x060, fBase_c, 0x8096AC00);
    // 0x8096AB50 g_profile_LIFT_ZEN_SHIRO
    // 0x80853140 daLiftZenShiro_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftZenShiro_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x598);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80853A90
     * executeState:    0x80853AD0
     * finalizeState:   0x80853AC0
     */
    sState_Extern(0x8099C150, daLiftZenShiro_c, Searchparent);

    /*
     * initializeState: 0x80853B50
     * executeState:    0x80853BB0
     * finalizeState:   0x80853BA0
     */
    sState_Extern(0x8099C190, daLiftZenShiro_c, Move);

    /*
     * initializeState: 0x80853CC0
     * executeState:    0x80853D20
     * finalizeState:   0x80853D10
     */
    sState_Extern(0x8099C1D0, daLiftZenShiro_c, Vanish);
};
