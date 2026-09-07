#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBarnar_c : public dEn_c {
    SIZE_ASSERT(0x998);
    VTABLE(0x060, fBase_c, 0x80AD6BFC);
    // 0x80AD6B38 g_profile_EN_BARNAR
    // 0x809A9F20 daEnBarnar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBarnar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x998);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x809AAA00
     * executeState:    VT+0x284 0x809AAA20
     * finalizeState:   VT+0x288 0x809AAA10
     */
    sState_ExternVirtual(0x80B11874, daEnBarnar_c, Wait);

    /*
     * initializeState: VT+0x28C 0x809AA9C0
     * executeState:    VT+0x290 0x809AA9F0
     * finalizeState:   VT+0x294 0x809AA9E0
     */
    sState_ExternVirtual(0x80B118B4, daEnBarnar_c, Fire);
};
