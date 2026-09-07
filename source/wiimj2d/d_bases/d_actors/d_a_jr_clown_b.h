#pragma once

#include "d_enemy_jr_clown_base.h"
#include "s_State.h"

class daJrClownB_c : public dEnJrClownBase_c {
    SIZE_ASSERT(0xDE8);
    VTABLE(0x060, fBase_c, 0x8095EAD0);
    // 0x8095E9B4 g_profile_JR_CLOWN_B
    // 0x80806930 daJrClownB_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80806960 */
    daJrClownB_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xD48, 0xDE8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80809360
     * executeState:    0x808094A0
     * finalizeState:   0x80809490
     */
    sState_Extern(0x809994F0, daJrClownB_c, EscapeMove);

    /*
     * initializeState: 0x80808CD0
     * executeState:    0x80808DD0
     * finalizeState:   0x80808DC0
     */
    sState_Extern(0x80999530, daJrClownB_c, AlignMove);

    /*
     * initializeState: 0x808097F0
     * executeState:    0x80809940
     * finalizeState:   0x80809930
     */
    sState_Extern(0x809995B0, daJrClownB_c, Thrust);

    /*
     * initializeState: 0x80809CA0
     * executeState:    0x80809E00
     * finalizeState:   0x80809DF0
     */
    sState_Extern(0x809995F0, daJrClownB_c, ThrustOnNoDmg);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80808360
     * executeState:    VT+0x284 0x808083B0
     * finalizeState:   VT+0x288 0x808083A0
     */
    sState_ExternVirtual(0x8099942C, daJrClownB_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x80808460
     * executeState:    VT+0x290 0x808085A0
     * finalizeState:   VT+0x294 0x80808590
     */
    sState_ExternVirtual(0x8099946C, daJrClownB_c, DemoAwake);

    /*
     * initializeState: VT+0x298 0x80808880
     * executeState:    VT+0x29C 0x808089A0
     * finalizeState:   VT+0x2A0 0x80808990
     */
    sState_ExternVirtual(0x809994AC, daJrClownB_c, Move);

    /*
     * initializeState: VT+0x2A4 0x8080A0F0
     * executeState:    VT+0x2A8 0x8080A1E0
     * finalizeState:   VT+0x2AC 0x8080A1D0
     */
    sState_ExternVirtual(0x8099956C, daJrClownB_c, Damaged);
};
