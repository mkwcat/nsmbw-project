#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBossKoopaDemoCage_c : public dEn_c {
    SIZE_ASSERT(0x6B0);
    VTABLE(0x060, fBase_c, 0x80B7F220);
    // 0x80B7F1A8 g_profile_EN_BOSS_KOOPA_DEMO_CAGE
    // 0x80B45EE0 daEnBossKoopaDemoCage_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossKoopaDemoCage_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6B0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B46360
     * executeState:    VT+0x284 0x80B46370
     * finalizeState:   VT+0x288 0x80B46380
     */
    sState_ExternVirtual(0x80B8C174, daEnBossKoopaDemoCage_c, Wait);

    /*
     * initializeState: VT+0x28C 0x80B46390
     * executeState:    VT+0x290 0x80B46400
     * finalizeState:   VT+0x294 0x80B46410
     */
    sState_ExternVirtual(0x80B8C1B4, daEnBossKoopaDemoCage_c, Magic);

    /*
     * initializeState: VT+0x298 0x80B46420
     * executeState:    VT+0x29C 0x80B464D0
     * finalizeState:   VT+0x2A0 0x80B46530
     */
    sState_ExternVirtual(0x80B8C1F4, daEnBossKoopaDemoCage_c, Open);
};
