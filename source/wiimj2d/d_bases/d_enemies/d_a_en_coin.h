#pragma once

#include "d_a_en_coin_main.h"
#include "s_State.h"

class daEnCoin_c : public daEnCoinMain_c {
    SIZE_ASSERT(0xAC8);
    VTABLE(0x060, fBase_c, 0x80AE1B74);
    // 0x80AE1B28 g_profile_EN_COIN
    // 0x809E09C0 daEnCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x8D0, 0xAC8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809E2800
     * executeState:    0x809E2820
     * finalizeState:   0x809E2810
     */
    sState_Extern(0x80B13608, daEnCoin_c, Move);

    /*
     * initializeState: 0x809E28C0
     * executeState:    0x809E2960
     * finalizeState:   0x809E2950
     */
    sState_Extern(0x80B13648, daEnCoin_c, WaitDown);

    /*
     * initializeState: 0x809E2A10
     * executeState:    0x809E2B60
     * finalizeState:   0x809E2B50
     */
    sState_Extern(0x80B13688, daEnCoin_c, Jump);

    /*
     * initializeState: 0x809E2BD0
     * executeState:    0x809E2C90
     * finalizeState:   0x809E2C80
     */
    sState_Extern(0x80B136C8, daEnCoin_c, Down);

    /*
     * initializeState: 0x809E2E70
     * executeState:    0x809E2EC0
     * finalizeState:   0x809E2EB0
     */
    sState_Extern(0x80B13708, daEnCoin_c, SwimDown);

    /*
     * initializeState: 0x809E2F30
     * executeState:    0x809E3030
     * finalizeState:   0x809E3020
     */
    sState_Extern(0x80B13748, daEnCoin_c, Swim);

    /*
     * initializeState: 0x809E3120
     * executeState:    0x809E3140
     * finalizeState:   0x809E3130
     */
    sState_Extern(0x80B13788, daEnCoin_c, FiveBlockWait);

    /*
     * initializeState: 0x809E31A0
     * executeState:    0x809E31D0
     * finalizeState:   0x809E31C0
     */
    sState_Extern(0x80B137C8, daEnCoin_c, FiveBlockMove);

    /*
     * initializeState: 0x809E3270
     * executeState:    0x809E32D0
     * finalizeState:   0x809E32C0
     */
    sState_Extern(0x80B13808, daEnCoin_c, DemoUp);

    /*
     * initializeState: 0x809E33E0
     * executeState:    0x809E3470
     * finalizeState:   0x809E3460
     */
    sState_Extern(0x80B13848, daEnCoin_c, EggBlock);

    /*
     * initializeState: 0x809E3520
     * executeState:    0x809E3670
     * finalizeState:   0x809E3660
     */
    sState_Extern(0x80B13888, daEnCoin_c, BlockJump);

    /*
     * initializeState: 0x809E3700
     * executeState:    0x809E3840
     * finalizeState:   0x809E3830
     */
    sState_Extern(0x80B138C8, daEnCoin_c, BlockDownJump);

    /*
     * initializeState: 0x809E3910
     * executeState:    0x809E3940
     * finalizeState:   0x809E3930
     */
    sState_Extern(0x80B13908, daEnCoin_c, WaterStream);

    /*
     * initializeState: 0x809E3A10
     * executeState:    0x809E3A30
     * finalizeState:   0x809E3A20
     */
    sState_Extern(0x80B13948, daEnCoin_c, IceWait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x809E38E0
     * executeState:    VT+0x1E8 0x809E3900
     * finalizeState:   VT+0x1EC 0x809E38F0
     */
    sState_ExternVirtual(0x80B13984, daEnCoin_c, EatOut);

    /*
     * initializeState: VT+0x1B4 0x809E3BA0
     * executeState:    VT+0x1B8 0x809E3BC0
     * finalizeState:   VT+0x1BC 0x809E3BB0
     */
    sState_ExternVirtual(0x80B139C4, daEnCoin_c, DieGoal);
};
