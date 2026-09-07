#pragma once

#include "d_base.h"
#include "s_State.h"

class dCollectionCoinDate_c : public dBase_c {
    SIZE_ASSERT(0x28C);
    VTABLE(0x060, fBase_c, 0x80940110);
    // 0x8093FFE8 g_profile_COLLECTION_COIN_DATE
    // 0x80776570 dCollectionCoinDate_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807765A0 */
    dCollectionCoinDate_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x28C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80776ED0
     * executeState:    0x80776EE0
     * finalizeState:   0x80776F40
     */
    sState_Extern(0x80991100, dCollectionCoinDate_c, OnStageSetup);

    /*
     * initializeState: 0x80776F50
     * executeState:    0x80776F60
     * finalizeState:   0x80776FD0
     */
    sState_Extern(0x80991140, dCollectionCoinDate_c, NowDisp);

    /*
     * initializeState: 0x80776FE0
     * executeState:    0x80776FF0
     * finalizeState:   0x80777010
     */
    sState_Extern(0x80991180, dCollectionCoinDate_c, Exit);
};
