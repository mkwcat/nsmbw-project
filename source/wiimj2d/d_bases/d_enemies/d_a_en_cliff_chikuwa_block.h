#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnCliffChikuwa_c : public dEn_c {
    SIZE_ASSERT(0x630);
    VTABLE(0x060, fBase_c, 0x80AE10C8);
    // 0x80AE1088 g_profile_EN_CLIFF_CHIKUWA_BLOCK
    // 0x809DBCF0 daEnCliffChikuwa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCliffChikuwa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x630);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809DC2A0
     * executeState:    0x809DC2F0
     * finalizeState:   0x809DC2E0
     */
    sState_Extern(0x80B13538, daEnCliffChikuwa_c, Wait);

    /*
     * initializeState: 0x809DC430
     * executeState:    0x809DC450
     * finalizeState:   0x809DC440
     */
    sState_Extern(0x80B13578, daEnCliffChikuwa_c, DownMove);

    /*
     * initializeState: 0x809DC540
     * executeState:    0x809DC560
     * finalizeState:   0x809DC550
     */
    sState_Extern(0x80B135B8, daEnCliffChikuwa_c, ZoomUp);
};
