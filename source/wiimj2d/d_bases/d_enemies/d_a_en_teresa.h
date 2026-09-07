#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnTeresa_c : public dEn_c {
    SIZE_ASSERT(0x9E8);
    VTABLE(0x060, fBase_c, 0x80B0ACE8);
    // 0x80B0ABD0 g_profile_EN_TERESA
    // 0x80AAE570 daEnTeresa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTeresa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x9E8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AB0790
     * executeState:    0x80AB07F0
     * finalizeState:   0x80AB07E0
     */
    sState_Extern(0x80B1B868, daEnTeresa_c, Move);

    /*
     * initializeState: 0x80AB0830
     * executeState:    0x80AB08E0
     * finalizeState:   0x80AB08D0
     */
    sState_Extern(0x80B1B8A8, daEnTeresa_c, Stop);

    /*
     * initializeState: 0x80AB0A20
     * executeState:    0x80AB0AB0
     * finalizeState:   0x80AB0AA0
     */
    sState_Extern(0x80B1B8E8, daEnTeresa_c, Recover);
};

class daEnBigTeresa_c : public daEnTeresa_c {
    SIZE_ASSERT(0x9E8);
    // 0x80B0ABDC g_profile_EN_BIG_TERESA
    // 0x80AAE700 daEnBigTeresa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigTeresa_c();
};
