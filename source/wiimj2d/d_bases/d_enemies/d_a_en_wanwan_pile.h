#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnWanPile_c : public dEn_c {
    SIZE_ASSERT(0x660);
    VTABLE(0x060, fBase_c, 0x80B0E8F8);
    // 0x80B0E8B0 g_profile_EN_WANWAN_PILE
    // 0x80AC29D0 daEnWanPile_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWanPile_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x660);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC3190
     * executeState:    0x80AC31B0
     * finalizeState:   0x80AC31A0
     */
    sState_Extern(0x80B1C3D8, daEnWanPile_c, Wait);

    /*
     * initializeState: 0x80AC31C0
     * executeState:    0x80AC31F0
     * finalizeState:   0x80AC31E0
     */
    sState_Extern(0x80B1C418, daEnWanPile_c, Damage);
};
