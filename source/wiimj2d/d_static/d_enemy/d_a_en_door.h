#pragma once

#include "d_enemy.h"

class daEnDoor_c : public dEn_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x60, fBase_c, 0x80303958);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8002B460
     * executeState:    0x8002B480
     * finalizeState:   0x8002B470
     */
    sState_Extern(0x803532D0, daEnDoor_c, Search);

    /*
     * initializeState: 0x8002B490
     * executeState:    0x8002B510
     * finalizeState:   0x8002B500
     */
    sState_Extern(0x80353310, daEnDoor_c, Open);

    /*
     * initializeState: 0x8002B660
     * executeState:    0x8002B690
     * finalizeState:   0x8002B680
     */
    sState_Extern(0x80353350, daEnDoor_c, Close);

    /*
     * initializeState: 0x8002B740
     * executeState:    0x8002B780
     * finalizeState:   0x8002B770
     */
    sState_Extern(0x80353390, daEnDoor_c, Wait);

    /*
     * initializeState: 0x8002B590
     * executeState:    0x8002B650
     * finalizeState:   0x8002B640
     */
    sState_Extern(0x803533D0, daEnDoor_c, Dummy);
};
