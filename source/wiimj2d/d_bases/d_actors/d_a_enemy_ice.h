#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEnemyIce_c : public dActorState_c {
    SIZE_ASSERT(0x6B8);
    VTABLE(0x060, fBase_c, 0x80323BD8);
    // 0x80323B60 g_profile_ENEMY_ICE
    // 0x80114C00 daEnemyIce_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnemyIce_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6B8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80115370
     * executeState:    0x80115390
     * finalizeState:   0x80115380
     */
    sState_Extern(0x80375640, daEnemyIce_c, Freeze);

    /*
     * initializeState: 0x801153E0
     * executeState:    0x80115430
     * finalizeState:   0x80115420
     */
    sState_Extern(0x80375680, daEnemyIce_c, Revival);

    /*
     * initializeState: 0x80115440
     * executeState:    0x801154A0
     * finalizeState:   0x80115490
     */
    sState_Extern(0x803756C0, daEnemyIce_c, Melt);

    /*
     * initializeState: 0x80115520
     * executeState:    0x80115570
     * finalizeState:   0x80115560
     */
    sState_Extern(0x80375700, daEnemyIce_c, Break);
};
