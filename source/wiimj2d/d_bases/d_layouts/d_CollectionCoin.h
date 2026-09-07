#pragma once

#include "d_base.h"
#include "s_State.h"

class dCollectionCoinBase_c;
class dCollectionCoinDate_c;
class dModelPlayArrow_c;

class dCollectionCoin_c : public dBase_c {
    SIZE_ASSERT(0xB5C);
    VTABLE(0x060, fBase_c, 0x8093FA70);
    // 0x8093F810 g_profile_COLLECTION_COIN
    // 0x80773F30 dCollectionCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80773F60 */
    dCollectionCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x074);

    /* 0x074 */ dCollectionCoinBase_c* mpColCoinBase[2];
    /* 0x07C */ dCollectionCoinDate_c* mpColCoinDate[24];
    /* 0x0DC */ dModelPlayArrow_c*     mpMdlPlyArrow;

    FILL(0x0E0, 0xB5C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80774D00
     * executeState:    0x80774DC0
     * finalizeState:   0x80774FC0
     */
    sState_Extern(0x80990F30, dCollectionCoin_c, Initial);

    /*
     * initializeState: 0x807750B0
     * executeState:    0x807750D0
     * finalizeState:   0x80775180
     */
    sState_Extern(0x80990F70, dCollectionCoin_c, OnStageSetup);

    /*
     * initializeState: 0x80775190
     * executeState:    0x80775240
     * finalizeState:   0x807752B0
     */
    sState_Extern(0x80990FB0, dCollectionCoin_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x807752C0
     * executeState:    0x807752D0
     * finalizeState:   0x80775370
     */
    sState_Extern(0x80990FF0, dCollectionCoin_c, KeyWait);

    /*
     * initializeState: 0x80775380
     * executeState:    0x80775430
     * finalizeState:   0x807754D0
     */
    sState_Extern(0x80991030, dCollectionCoin_c, WorldChangeWait);

    /*
     * initializeState: 0x807755F0
     * executeState:    0x80775600
     * finalizeState:   0x807756B0
     */
    sState_Extern(0x80991070, dCollectionCoin_c, WorldChangeEndWait);

    /*
     * initializeState: 0x807756C0
     * executeState:    0x80775710
     * finalizeState:   0x80775770
     */
    sState_Extern(0x809910B0, dCollectionCoin_c, ExitAnimeEndWait);
};
