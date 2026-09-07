#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daTorideKokoopaDemo_c : public dActorState_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x8097DB34);
    // 0x8097DB00 g_profile_TORIDE_KOKOOPA_DEMO
    // 0x808B15D0 daTorideKokoopaDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTorideKokoopaDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0EC 0x808B16E0
     * executeState:    VT+0x0F0 0x808B1710
     * finalizeState:   VT+0x0F4 0x808B1700
     */
    sState_ExternVirtual(0x8099F484, daTorideKokoopaDemo_c, BattleStDemo);

    /*
     * initializeState: VT+0x104 0x808B1930
     * executeState:    VT+0x108 0x808B19A0
     * finalizeState:   VT+0x10C 0x808B1990
     */
    sState_ExternVirtual(0x8099F4C4, daTorideKokoopaDemo_c, BattleEdDemo);
};
