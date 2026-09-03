#pragma once

#include "d_enemy.h"

class daPeachForAirshipDemo_c : public dEn_c {
    SIZE_ASSERT(0x650);
    VTABLE(0x060, fBase_c, 0x809778F0);
    // 0x80977878 g_profile_PEACH_FOR_AIRSHIP_DEMO
    // 0x8088E670 daPeachForAirshipDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8088E6B0 */
    daPeachForAirshipDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x650);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8088F390
     * executeState:    0x8088F4A0
     * finalizeState:   0x8088F490
     */
    sState_Extern(0x8099E150, daPeachForAirshipDemo_c, DemoFind);

    /*
     * initializeState: 0x8088F680
     * executeState:    0x8088F790
     * finalizeState:   0x8088F780
     */
    sState_Extern(0x8099E190, daPeachForAirshipDemo_c, CarryAway);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8088F1A0
     * executeState:    VT+0x284 0x8088F2E0
     * finalizeState:   VT+0x288 0x8088F2D0
     */
    sState_ExternVirtual(0x8099E10C, daPeachForAirshipDemo_c, DemoWait);
};
