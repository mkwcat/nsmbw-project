#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnLargeBarnar_c : public dEn_c {
    SIZE_ASSERT(0xBE8);
    VTABLE(0x060, fBase_c, 0x80AF8750);
    // 0x80AF8718 g_profile_EN_LARGE_BARNAR
    // 0x80A59870 daEnLargeBarnar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLargeBarnar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xBE8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80A59D20
     * executeState:    VT+0x284 0x80A59D40
     * finalizeState:   VT+0x288 0x80A59D30
     */
    sState_ExternVirtual(0x80B1836C, daEnLargeBarnar_c, Wait);

    /*
     * initializeState: VT+0x28C 0x80A59BD0
     * executeState:    VT+0x290 0x80A59C30
     * finalizeState:   VT+0x294 0x80A59C20
     */
    sState_ExternVirtual(0x80B183AC, daEnLargeBarnar_c, Fire);
};
