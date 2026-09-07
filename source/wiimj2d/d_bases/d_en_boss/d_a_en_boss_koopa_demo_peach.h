#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBossKoopaDemoPeach_c : public dEn_c {
    SIZE_ASSERT(0x768);
    VTABLE(0x060, fBase_c, 0x80B7FE08);
    // 0x80B7FD00 g_profile_EN_BOSS_KOOPA_DEMO_PEACH
    // 0x80B48C70 daEnBossKoopaDemoPeach_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossKoopaDemoPeach_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x768);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B49280
     * executeState:    VT+0x284 0x80B49340
     * finalizeState:   VT+0x288 0x80B49400
     */
    sState_ExternVirtual(0x80B8C350, daEnBossKoopaDemoPeach_c, Wait);

    /*
     * initializeState: VT+0x28C 0x80B49410
     * executeState:    VT+0x290 0x80B49580
     * finalizeState:   VT+0x294 0x80B49620
     */
    sState_ExternVirtual(0x80B8C390, daEnBossKoopaDemoPeach_c, Call);

    /*
     * initializeState: VT+0x298 0x80B49630
     * executeState:    VT+0x29C 0x80B49660
     * finalizeState:   VT+0x2A0 0x80B49760
     */
    sState_ExternVirtual(0x80B8C3D0, daEnBossKoopaDemoPeach_c, Turn);

    /*
     * initializeState: VT+0x2A4 0x80B49770
     * executeState:    VT+0x2A8 0x80B497E0
     * finalizeState:   VT+0x2AC 0x80B498F0
     */
    sState_ExternVirtual(0x80B8C410, daEnBossKoopaDemoPeach_c, Open);

    /*
     * initializeState: VT+0x2B0 0x80B49900
     * executeState:    VT+0x2B4 0x80B49A10
     * finalizeState:   VT+0x2B8 0x80B49D40
     */
    sState_ExternVirtual(0x80B8C450, daEnBossKoopaDemoPeach_c, Rescue);

    /*
     * initializeState: VT+0x2BC 0x80B49D50
     * executeState:    VT+0x2C0 0x80B49D70
     * finalizeState:   VT+0x2C4 0x80B4A3D0
     */
    sState_ExternVirtual(0x80B8C490, daEnBossKoopaDemoPeach_c, Thank);
};
