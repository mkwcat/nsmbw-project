#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnChikuwa_c : public dEn_c {
    SIZE_ASSERT(0x6C0);
    VTABLE(0x060, fBase_c, 0x80ADFE20);
    // 0x80ADFDE0 g_profile_EN_CHIKUWA_BLOCK
    // 0x809D4B80 daEnChikuwa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnChikuwa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809D5430
     * executeState:    0x809D5460
     * finalizeState:   0x809D5450
     */
    sState_Extern(0x80B13030, daEnChikuwa_c, Wait);

    /*
     * initializeState: 0x809D5550
     * executeState:    0x809D5570
     * finalizeState:   0x809D5560
     */
    sState_Extern(0x80B13070, daEnChikuwa_c, DownMove);

    /*
     * initializeState: 0x809D5630
     * executeState:    0x809D5650
     * finalizeState:   0x809D5640
     */
    sState_Extern(0x80B130B0, daEnChikuwa_c, ZoomUp);
};
