#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBossKoopaDemoKameck_c : public dEn_c {
    SIZE_ASSERT(0x780);
    VTABLE(0x060, fBase_c, 0x80B7F890);
    // 0x80B7F630 g_profile_EN_BOSS_KOOPA_DEMO_KAMECK
    // 0x80B46CB0 daEnBossKoopaDemoKameck_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossKoopaDemoKameck_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x780);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B47420
     * executeState:    VT+0x284 0x80B47440
     * finalizeState:   VT+0x288 0x80B47450
     */
    sState_ExternVirtual(0x80B8C23C, daEnBossKoopaDemoKameck_c, Wait);

    /*
     * initializeState: VT+0x28C 0x80B47460
     * executeState:    VT+0x290 0x80B47560
     * finalizeState:   VT+0x294 0x80B47570
     */
    sState_ExternVirtual(0x80B8C27C, daEnBossKoopaDemoKameck_c, Cry);

    /*
     * initializeState: VT+0x298 0x80B47580
     * executeState:    VT+0x29C 0x80B47730
     * finalizeState:   VT+0x2A0 0x80B481A0
     */
    sState_ExternVirtual(0x80B8C2BC, daEnBossKoopaDemoKameck_c, Magic);

    /*
     * initializeState: VT+0x2A4 0x80B481B0
     * executeState:    VT+0x2A8 0x80B48350
     * finalizeState:   VT+0x2AC 0x80B483E0
     */
    sState_ExternVirtual(0x80B8C2FC, daEnBossKoopaDemoKameck_c, Fall);
};
