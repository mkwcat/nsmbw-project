#pragma once

#include "d_a_en_blockmain.h"

class daEnObjCoinBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x74C);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x74C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80037340
     * executeState:    0x80037360
     * finalizeState:   0x80037350
     */
    sState_Extern(0x80353AF0, daEnObjCoinBlock_c, SerchRailID);

    /*
     * initializeState: 0x800373E0
     * executeState:    0x80037400
     * finalizeState:   0x800373F0
     */
    sState_Extern(0x80353B30, daEnObjCoinBlock_c, SerchObjPolID);

    /*
     * initializeState: 0x80037480
     * executeState:    0x800374A0
     * finalizeState:   0x80037490
     */
    sState_Extern(0x80353B70, daEnObjCoinBlock_c, SerchWaterMoveID);

    /*
     * initializeState: 0x80037520
     * executeState:    0x80037540
     * finalizeState:   0x80037530
     */
    sState_Extern(0x80353BB0, daEnObjCoinBlock_c, SerchSpinLiftID);

    /*
     * initializeState: 0x800375C0
     * executeState:    0x800375E0
     * finalizeState:   0x800375D0
     */
    sState_Extern(0x80353BF0, daEnObjCoinBlock_c, SerchSpinLiftChildID);

    /*
     * initializeState: 0x80037660
     * executeState:    0x80037690
     * finalizeState:   0x80037680
     */
    sState_Extern(0x80353C30, daEnObjCoinBlock_c, CoinWait);

    /*
     * initializeState: 0x800376E0
     * executeState:    0x80037700
     * finalizeState:   0x800376F0
     */
    sState_Extern(0x80353C70, daEnObjCoinBlock_c, BlockWait);
};
