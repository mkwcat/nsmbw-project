#pragma once

#include "d_enemy_jr_clown_base.h"
#include "s_State.h"

class daJrClownC_c : public dEnJrClownBase_c {
    SIZE_ASSERT(0xEB0);
    VTABLE(0x060, fBase_c, 0x8095F1B8);
    // 0x8095F118 g_profile_JR_CLOWN_C
    // 0x8080B210 daJrClownC_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8080B240 */
    daJrClownC_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xD48, 0xEB0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8080CBE0
     * executeState:    0x8080CCC0
     * finalizeState:   0x8080CCB0
     */
    sState_Extern(0x809996F8, daJrClownC_c, BombardReady);

    /*
     * initializeState: 0x8080D050
     * executeState:    0x8080D130
     * finalizeState:   0x8080D120
     */
    sState_Extern(0x80999738, daJrClownC_c, LargeBombardReady);

    /*
     * initializeState: 0x8080D520
     * executeState:    0x8080D580
     * finalizeState:   0x8080D530
     */
    sState_Extern(0x80999778, daJrClownC_c, Bombard);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x298 0x8080C700
     * executeState:    VT+0x29C 0x8080C800
     * finalizeState:   VT+0x2A0 0x8080C7F0
     */
    sState_ExternVirtual(0x80999634, daJrClownC_c, Move);

    /*
     * initializeState: VT+0x280 0x8080C1D0
     * executeState:    VT+0x284 0x8080C220
     * finalizeState:   VT+0x288 0x8080C210
     */
    sState_ExternVirtual(0x80999674, daJrClownC_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x8080C2B0
     * executeState:    VT+0x290 0x8080C420
     * finalizeState:   VT+0x294 0x8080C410
     */
    sState_ExternVirtual(0x809996B4, daJrClownC_c, DemoAwake);

    /*
     * initializeState: VT+0x2A4 0x8080D710
     * executeState:    VT+0x2A8 0x8080D910
     * finalizeState:   VT+0x2AC 0x8080D8A0
     */
    sState_ExternVirtual(0x809997B4, daJrClownC_c, Damaged);

    /*
     * initializeState: VT+0x2C8 0x8080DCD0
     * executeState:    VT+0x2CC 0x8080DDC0
     * finalizeState:   VT+0x2D0 0x8080DDB0
     */
    sState_ExternVirtual(0x809997F4, daJrClownC_c, Fire);
};
