#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnJugem_c : public dEn_c {
    SIZE_ASSERT(0x728);
    VTABLE(0x060, fBase_c, 0x80AF35D8);
    // 0x80AF3570 g_profile_EN_JUGEM
    // 0x80A342E0 daEnJugem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJugem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x728);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A350F0
     * executeState:    0x80A35260
     * finalizeState:   0x80A35250
     */
    sState_Extern(0x80B16E58, daEnJugem_c, EntryBlock);

    /*
     * initializeState: 0x80A353B0
     * executeState:    0x80A354A0
     * finalizeState:   0x80A35490
     */
    sState_Extern(0x80B16E98, daEnJugem_c, EntryJugem);

    /*
     * initializeState: 0x80A35650
     * executeState:    0x80A356F0
     * finalizeState:   0x80A356E0
     */
    sState_Extern(0x80B16ED8, daEnJugem_c, Move);

    /*
     * initializeState: 0x80A35830
     * executeState:    0x80A35860
     * finalizeState:   0x80A35850
     */
    sState_Extern(0x80B16F18, daEnJugem_c, Escape);

    /*
     * initializeState: 0x80A35910
     * executeState:    0x80A35940
     * finalizeState:   0x80A35930
     */
    sState_Extern(0x80B16F58, daEnJugem_c, CloudWait);

    /*
     * initializeState: 0x80A35AB0
     * executeState:    0x80A35BE0
     * finalizeState:   0x80A35B70
     */
    sState_Extern(0x80B16F98, daEnJugem_c, CloudMove);
};

class daEnJugemCoin_c : public daEnJugem_c {
    SIZE_ASSERT(0x728);
    // 0x80AF357C g_profile_EN_JUGEM_COIN
    // 0x80A343B0 daEnJugemCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJugemCoin_c();
};
