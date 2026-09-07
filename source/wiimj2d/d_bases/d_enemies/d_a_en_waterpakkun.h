#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWaterPakkun_c : public dEn_c {
    SIZE_ASSERT(0x858);
    VTABLE(0x060, fBase_c, 0x80B0F708);
    // 0x80B0F688 g_profile_EN_WATERPAKKUN
    // 0x80AC5840 daEnWaterPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWaterPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x858);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC65D0
     * executeState:    0x80AC6600
     * finalizeState:   0x80AC65F0
     */
    sState_Extern(0x80B1C558, daEnWaterPakkun_c, FooRise);

    /*
     * initializeState: 0x80AC6730
     * executeState:    0x80AC6750
     * finalizeState:   0x80AC6740
     */
    sState_Extern(0x80B1C598, daEnWaterPakkun_c, FooRise_End);

    /*
     * initializeState: 0x80AC6850
     * executeState:    0x80AC6880
     * finalizeState:   0x80AC6870
     */
    sState_Extern(0x80B1C5D8, daEnWaterPakkun_c, FooFall);

    /*
     * initializeState: 0x80AC69B0
     * executeState:    0x80AC69D0
     * finalizeState:   0x80AC69C0
     */
    sState_Extern(0x80B1C618, daEnWaterPakkun_c, FooFall_End);

    /*
     * initializeState: 0x80AC6AD0
     * executeState:    0x80AC6B20
     * finalizeState:   0x80AC6B10
     */
    sState_Extern(0x80B1C658, daEnWaterPakkun_c, Hurry);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80AC6BA0
     * executeState:    VT+0x17C 0x80AC6CF0
     * finalizeState:   VT+0x180 0x80AC6CE0
     */
    sState_ExternVirtual(0x80B1C694, daEnWaterPakkun_c, DieFall);
};
