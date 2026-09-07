#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnSanboEl_c : public dEn_c {
    SIZE_ASSERT(0x618);
    VTABLE(0x060, fBase_c, 0x80B07DD8);
    // 0x80B07D58 g_profile_EN_SANBO_EL
    // 0x80A9F630 daEnSanboEl_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSanboEl_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x618);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AA0580
     * executeState:    0x80AA05B0
     * finalizeState:   0x80AA05A0
     */
    sState_Extern(0x80B1AEA8, daEnSanboEl_c, Move);

    /*
     * initializeState: 0x80AA0940
     * executeState:    0x80AA0990
     * finalizeState:   0x80AA0980
     */
    sState_Extern(0x80B1AEE8, daEnSanboEl_c, Vacume);

    /*
     * initializeState: 0x80AA0740
     * executeState:    0x80AA0760
     * finalizeState:   0x80AA0750
     */
    sState_Extern(0x80B1AF28, daEnSanboEl_c, DamageJump);

    /*
     * initializeState: 0x80AA09D0
     * executeState:    0x80AA09F0
     * finalizeState:   0x80AA09E0
     */
    sState_Extern(0x80B1AF68, daEnSanboEl_c, DamageJump_Fin);

    /*
     * initializeState: 0x80AA0B20
     * executeState:    0x80AA0BB0
     * finalizeState:   0x80AA0BA0
     */
    sState_Extern(0x80B1AFA8, daEnSanboEl_c, DamageFall);

    /*
     * initializeState: 0x80AA0BC0
     * executeState:    0x80AA0C50
     * finalizeState:   0x80AA0C40
     */
    sState_Extern(0x80B1AFE8, daEnSanboEl_c, CriticalFall);

    /*
     * initializeState: 0x80AA0E70
     * executeState:    0x80AA0F60
     * finalizeState:   0x80AA0F50
     */
    sState_Extern(0x80B1B028, daEnSanboEl_c, FreezeFall);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1FC 0x80AA0D50
     * executeState:    VT+0x200 0x80AA0D70
     * finalizeState:   VT+0x204 0x80AA0D60
     */
    sState_ExternVirtual(0x80B1B064, daEnSanboEl_c, Ice);
};
