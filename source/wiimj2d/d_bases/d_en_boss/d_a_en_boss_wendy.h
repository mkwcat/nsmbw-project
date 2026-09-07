#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossWendy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0xF98);
    VTABLE(0x060, fBase_c, 0x80B87554);
    // 0x80B87020 g_profile_EN_BOSS_WENDY
    // 0x80B67190 daEnBossWendy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossWendy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xF98);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80B69AE0
     * executeState:    VT+0x170 0x80B69C30
     * finalizeState:   VT+0x174 0x80B69C20
     */
    sState_ExternVirtual(0x80B8DE6C, daEnBossWendy_c, DieFumi);

    /*
     * initializeState: VT+0x468 0x80B69280
     * executeState:    VT+0x46C 0x80B69330
     * finalizeState:   VT+0x470 0x80B69310
     */
    sState_ExternVirtual(0x80B8DEAC, daEnBossWendy_c, ShellOut);

    /*
     * initializeState: VT+0x3F0 0x80B68650
     * executeState:    VT+0x3F4 0x80B68760
     * finalizeState:   VT+0x3F8 0x80B68710
     */
    sState_ExternVirtual(0x80B8DEEC, daEnBossWendy_c, Attack);

    /*
     * initializeState: VT+0x39C 0x80B68310
     * executeState:    VT+0x3A0 0x80B68480
     * finalizeState:   VT+0x3A4 0x80B68470
     */
    sState_ExternVirtual(0x80B8DF2C, daEnBossWendy_c, Jump);

    /*
     * initializeState: VT+0x3B4 0x80B68510
     * executeState:    VT+0x3B8 0x80B685B0
     * finalizeState:   VT+0x3BC 0x80B685A0
     */
    sState_ExternVirtual(0x80B8DF6C, daEnBossWendy_c, BigJump);

    /*
     * initializeState: VT+0x5A0 0x80B69400
     * executeState:    VT+0x5A4 0x80B694A0
     * finalizeState:   VT+0x5A8 0x80B69490
     */
    sState_ExternVirtual(0x80B8DFAC, daEnBossWendy_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B69560
     * executeState:    VT+0x5B0 0x80B695F0
     * finalizeState:   VT+0x5B4 0x80B695E0
     */
    sState_ExternVirtual(0x80B8DFEC, daEnBossWendy_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x5B8 0x80B69660
     * executeState:    VT+0x5BC 0x80B697C0
     * finalizeState:   VT+0x5C0 0x80B697B0
     */
    sState_ExternVirtual(0x80B8E02C, daEnBossWendy_c, DemoIkaku);

    /*
     * initializeState: VT+0x5C4 0x80B699E0
     * executeState:    VT+0x5C8 0x80B69A70
     * finalizeState:   VT+0x5CC 0x80B69A60
     */
    sState_ExternVirtual(0x80B8E06C, daEnBossWendy_c, DemoIkaku_Wait);

    /*
     * initializeState: VT+0x5F0 0x80B69CD0
     * executeState:    VT+0x5F4 0x80B69DD0
     * finalizeState:   VT+0x5F8 0x80B69DC0
     */
    sState_ExternVirtual(0x80B8E0AC, daEnBossWendy_c, DemoFall);

    /*
     * initializeState: VT+0x5FC 0x80B69E90
     * executeState:    VT+0x600 0x80B6A000
     * finalizeState:   VT+0x604 0x80B69FF0
     */
    sState_ExternVirtual(0x80B8E0EC, daEnBossWendy_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B6A1B0
     * executeState:    VT+0x5D4 0x80B6A2E0
     * finalizeState:   VT+0x5D8 0x80B6A2D0
     */
    sState_ExternVirtual(0x80B8E12C, daEnBossWendy_c, DemoEscape_St);

    /*
     * initializeState: VT+0x608 0x80B6A420
     * executeState:    VT+0x60C 0x80B6A4D0
     * finalizeState:   VT+0x610 0x80B6A4C0
     */
    sState_ExternVirtual(0x80B8E16C, daEnBossWendy_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x614 0x80B6A5A0
     * executeState:    VT+0x618 0x80B6A7A0
     * finalizeState:   VT+0x61C 0x80B6A790
     */
    sState_ExternVirtual(0x80B8E1AC, daEnBossWendy_c, DemoEscape_Jump);

    /*
     * initializeState: VT+0x450 0x80B68A80
     * executeState:    VT+0x454 0x80B68A90
     * finalizeState:   VT+0x458 0x80B68D10
     */
    sState_ExternVirtual(0x80B8E1EC, daEnBossWendy_c, ShellAtk_St);

    /*
     * initializeState: VT+0x45C 0x80B68D20
     * executeState:    VT+0x460 0x80B68DD0
     * finalizeState:   VT+0x464 0x80B68FA0
     */
    sState_ExternVirtual(0x80B8E22C, daEnBossWendy_c, ShellAtk);

    /*
     * initializeState: VT+0x5E4 0x80B68FB0
     * executeState:    VT+0x5E8 0x80B68FD0
     * finalizeState:   VT+0x5EC 0x80B69270
     */
    sState_ExternVirtual(0x80B8E26C, daEnBossWendy_c, ShellAtk_Ed);
};
