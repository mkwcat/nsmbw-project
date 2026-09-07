#pragma once

#include "c_bitmask.h"
#include "d_actor.h"
#include "d_rc.h"
#include "s_State.h"

class daLineTrain_c : public dActor_c {
    // Original size: 0x1398
    VTABLE(0x0060, fBase_c, 0x8096BBC0);
    // 0x8096BB30 g_profile_LINE_TRAIN
    // 0x80859440 daLineTrain_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLineTrain_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8085A990 */
    int numPlayersRide();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0392, 0x1044);

    dRide2Point_c maRide2Point[9];

    FILL(0x1380, 0x1393);
    OFFSET_ASSERT(0x1393);

    // /* 0x1393 */ u8 REMOVED(mPlayerRideMask);
    // /* 0x1394 */ u8 REMOVED(mPrevPlayerRideMask);

#define TEMP_RIDE_MASK_SIZE 8 // TODO

#define OFFSET_dLineTrain_c_mPlayerRideMask 0x1393
    /* 0x1393 */ cBitmask_c<TEMP_RIDE_MASK_SIZE> mPlayerRideMask;
#define OFFSET_dLineTrain_c_mPrevPlayerRideMask \
    (OFFSET_dLineTrain_c_mPlayerRideMask + cBitmask_c_SIZE_ASM(TEMP_RIDE_MASK_SIZE))
    /* 0x1395? */ cBitmask_c<TEMP_RIDE_MASK_SIZE> mPrevPlayerRideMask;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8085B330
     * executeState:    0x8085B350
     * finalizeState:   0x8085B340
     */
    sState_Extern(0x8099C5E8, daLineTrain_c, Wait);

    /*
     * initializeState: 0x8085B3B0
     * executeState:    0x8085B3D0
     * finalizeState:   0x8085B3C0
     */
    sState_Extern(0x8099C628, daLineTrain_c, Search);

    /*
     * initializeState: 0x8085B3E0
     * executeState:    0x8085B400
     * finalizeState:   0x8085B3F0
     */
    sState_Extern(0x8099C668, daLineTrain_c, WaitParent);

    /*
     * initializeState: 0x8085B490
     * executeState:    0x8085B4F0
     * finalizeState:   0x8085B4E0
     */
    sState_Extern(0x8099C6A8, daLineTrain_c, Move);
};
