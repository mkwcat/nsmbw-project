#pragma once

#include "d_enemy.h"

class daKameckForAirshipDemo_c : public dEn_c {
    SIZE_ASSERT(0x860);
    VTABLE(0x060, fBase_c, 0x80961048);
    // 0x80960F38 g_profile_KAMECK_FOR_AIRSHIP_DEMO
    // 0x80816D50 daKameckForAirshipDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80816DC0 */
    daKameckForAirshipDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x858);

    /* 0x858 */ float mBossDemoX;

    FILL(0x85C, 0x860);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x808178E0
     * executeState:    VT+0x284 0x808179E0
     * finalizeState:   VT+0x288 0x808179D0
     */
    sState_ExternVirtual(0x80999B04, daKameckForAirshipDemo_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x80817A70
     * executeState:    VT+0x290 0x80817C10
     * finalizeState:   VT+0x294 0x80817C00
     */
    sState_ExternVirtual(0x80999B44, daKameckForAirshipDemo_c, Demo1Begin);

    /*
     * initializeState: VT+0x298 0x80817DF0
     * executeState:    VT+0x29C 0x80817F20
     * finalizeState:   VT+0x2A0 0x80817F10
     */
    sState_ExternVirtual(0x80999B84, daKameckForAirshipDemo_c, Demo1Magic);

    /*
     * initializeState: VT+0x2A4 0x80818210
     * executeState:    VT+0x2A8 0x808183A0
     * finalizeState:   VT+0x2AC 0x80818390
     */
    sState_ExternVirtual(0x80999BC4, daKameckForAirshipDemo_c, Demo2Begin);
};
