#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnSanbo_c : public dEn_c {
    SIZE_ASSERT(0x800);
    VTABLE(0x060, fBase_c, 0x80B07958);
    // 0x80B07920 g_profile_EN_SANBO
    // 0x80A9CB90 daEnSanbo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSanbo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x800);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A9E880
     * executeState:    0x80A9E9A0
     * finalizeState:   0x80A9E990
     */
    sState_Extern(0x80B1ACD8, daEnSanbo_c, Move);

    /*
     * initializeState: 0x80A9EB20
     * executeState:    0x80A9EB50
     * finalizeState:   0x80A9EB40
     */
    sState_Extern(0x80B1AD18, daEnSanbo_c, Damage);

    /*
     * initializeState: 0x80A9EC50
     * executeState:    0x80A9EC80
     * finalizeState:   0x80A9EC70
     */
    sState_Extern(0x80B1AD58, daEnSanbo_c, Vacume);

    /*
     * initializeState: 0x80A9EC90
     * executeState:    0x80A9EDB0
     * finalizeState:   0x80A9EDA0
     */
    sState_Extern(0x80B1AD98, daEnSanbo_c, CriticalDie);

    /*
     * initializeState: 0x80A9EDF0
     * executeState:    0x80A9EE30
     * finalizeState:   0x80A9EE20
     */
    sState_Extern(0x80B1ADD8, daEnSanbo_c, FreezeDie);
};
