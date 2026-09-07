#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBossKameckDemo_c : public dActorState_c {
    SIZE_ASSERT(0x3E8);
    VTABLE(0x060, fBase_c, 0x80954040);
    // 0x80954010 g_profile_BOSS_KAMECK_DEMO
    // 0x807C7EF0 daBossKameckDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBossKameckDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0EC 0x807C8020
     * executeState:    VT+0x0F0 0x807C8040
     * finalizeState:   VT+0x0F4 0x807C82E0
     */
    sState_ExternVirtual(0x80996B5C, daBossKameckDemo_c, BattleStDemo);

    /*
     * initializeState: VT+0x104 0x807C82F0
     * executeState:    VT+0x108 0x807C8360
     * finalizeState:   VT+0x10C 0x807C8540
     */
    sState_ExternVirtual(0x80996B9C, daBossKameckDemo_c, BattleEdDemo);
};
