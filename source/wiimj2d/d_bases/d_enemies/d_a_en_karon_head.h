#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKanonHead_c : public dEn_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80AF5B90);
    // 0x80AF5B38 g_profile_EN_KARON_HEAD
    // 0x80A44C50 daEnKanonHead_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKanonHead_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A45530
     * executeState:    0x80A45550
     * finalizeState:   0x80A45540
     */
    sState_Extern(0x80B177A8, daEnKanonHead_c, DeadWait);

    /*
     * initializeState: 0x80A45560
     * executeState:    0x80A45650
     * finalizeState:   0x80A45640
     */
    sState_Extern(0x80B177E8, daEnKanonHead_c, Dead);

    /*
     * initializeState: 0x80A456F0
     * executeState:    0x80A45720
     * finalizeState:   0x80A45710
     */
    sState_Extern(0x80B17828, daEnKanonHead_c, Vibration);

    /*
     * initializeState: 0x80A457C0
     * executeState:    0x80A457E0
     * finalizeState:   0x80A457D0
     */
    sState_Extern(0x80B17868, daEnKanonHead_c, Search);

    /*
     * initializeState: 0x80A45930
     * executeState:    0x80A45950
     * finalizeState:   0x80A45940
     */
    sState_Extern(0x80B178A8, daEnKanonHead_c, SearchEnd);
};
