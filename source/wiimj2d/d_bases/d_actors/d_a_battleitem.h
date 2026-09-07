#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBattleItem_c : public dActorState_c {
    SIZE_ASSERT(0x6F0);
    VTABLE(0x060, fBase_c, 0x80951B60);
    // 0x809519D8 g_profile_AC_BATTLE_ITEM
    // 0x807BA110 daBattleItem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBattleItem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BA6B0
     * executeState:    0x807BA720
     * finalizeState:   0x807BA710
     */
    sState_Extern(0x80996010, daBattleItem_c, UpMove);

    /*
     * initializeState: 0x807BA7B0
     * executeState:    0x807BA7D0
     * finalizeState:   0x807BA7C0
     */
    sState_Extern(0x80996050, daBattleItem_c, Wait);
};
