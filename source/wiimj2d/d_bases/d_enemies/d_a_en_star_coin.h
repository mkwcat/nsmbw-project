#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnStarCoin_c : public dEn_c {
    SIZE_ASSERT(0x6E0);
    VTABLE(0x060, fBase_c, 0x80B09670);
    // 0x80B095F0 g_profile_EN_STAR_COIN
    // 0x80AA96F0 daEnStarCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnStarCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AAA960
     * executeState:    0x80AAA980
     * finalizeState:   0x80AAA970
     */
    sState_Extern(0x80B1B5A8, daEnStarCoin_c, SearchID);

    /*
     * initializeState: 0x80AAA9F0
     * executeState:    0x80AAAA10
     * finalizeState:   0x80AAAA00
     */
    sState_Extern(0x80B1B5E8, daEnStarCoin_c, GetWait);

    /*
     * initializeState: 0x80AAAB10
     * executeState:    0x80AAAB70
     * finalizeState:   0x80AAAB60
     */
    sState_Extern(0x80B1B628, daEnStarCoin_c, DemoDown);

    /*
     * initializeState: 0x80AAACC0
     * executeState:    0x80AAAD50
     * finalizeState:   0x80AAAD40
     */
    sState_Extern(0x80B1B668, daEnStarCoin_c, WaitDown);
};

class daEnStarCoinLine_c : public daEnStarCoin_c {
    SIZE_ASSERT(0x6E0);
    // 0x80B095FC g_profile_EN_STAR_COIN_LINE
    // 0x80AA9760 daEnStarCoinLine_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnStarCoinLine_c();
};

class daEnStarCoinVolt_c : public daEnStarCoin_c {
    SIZE_ASSERT(0x6E0);
    // 0x80B09608 g_profile_EN_STAR_COIN_VOLT
    // 0x80AA97D0 daEnStarCoinVolt_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnStarCoinVolt_c();
};
