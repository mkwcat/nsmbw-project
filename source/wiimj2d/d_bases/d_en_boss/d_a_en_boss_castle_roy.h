#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleRoy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x1118);
    VTABLE(0x0060, fBase_c, 0x80B79CD8);
    // 0x80B79B60 g_profile_EN_BOSS_CASTLE_ROY
    // 0x80B2E590 daEnBossCastleRoy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossCastleRoy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x1118);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B2ED80
     * executeState:    VT+0x284 0x80B2EDC0
     * finalizeState:   VT+0x288 0x80B2EE60
     */
    sState_ExternVirtual(0x80B8AB0C, daEnBossCastleRoy_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B2EE70
     * executeState:    VT+0x5A4 0x80B2EF00
     * finalizeState:   VT+0x5A8 0x80B2EF20
     */
    sState_ExternVirtual(0x80B8AB4C, daEnBossCastleRoy_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B2EF30
     * executeState:    VT+0x5B0 0x80B2EF40
     * finalizeState:   VT+0x5B4 0x80B2EF50
     */
    sState_ExternVirtual(0x80B8AB8C, daEnBossCastleRoy_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x3A8 0x80B2EF60
     * executeState:    VT+0x3AC 0x80B2EFA0
     * finalizeState:   VT+0x3B0 0x80B2F130
     */
    sState_ExternVirtual(0x80B8ABCC, daEnBossCastleRoy_c, BigJump_St);

    /*
     * initializeState: VT+0x3B4 0x80B2F140
     * executeState:    VT+0x3B8 0x80B2F1A0
     * finalizeState:   VT+0x3BC 0x80B2F250
     */
    sState_ExternVirtual(0x80B8AC0C, daEnBossCastleRoy_c, BigJump);

    /*
     * initializeState: VT+0x658 0x80B2F260
     * executeState:    VT+0x65C 0x80B2F370
     * finalizeState:   VT+0x660 0x80B2F460
     */
    sState_ExternVirtual(0x80B8AC4C, daEnBossCastleRoy_c, Enter);

    /*
     * initializeState: VT+0x664 0x80B2F470
     * executeState:    VT+0x668 0x80B2F4E0
     * finalizeState:   VT+0x66C 0x80B2F510
     */
    sState_ExternVirtual(0x80B8AC8C, daEnBossCastleRoy_c, Hide);

    /*
     * initializeState: VT+0x670 0x80B2F520
     * executeState:    VT+0x674 0x80B2F7F0
     * finalizeState:   VT+0x678 0x80B2F860
     */
    sState_ExternVirtual(0x80B8ACCC, daEnBossCastleRoy_c, Peek);

    /*
     * initializeState: VT+0x67C 0x80B2F870
     * executeState:    VT+0x680 0x80B2F900
     * finalizeState:   VT+0x684 0x80B2F9C0
     */
    sState_ExternVirtual(0x80B8AD0C, daEnBossCastleRoy_c, Peek_Wait);

    /*
     * initializeState: VT+0x688 0x80B2F9D0
     * executeState:    VT+0x68C 0x80B2FA40
     * finalizeState:   VT+0x690 0x80B2FAB0
     */
    sState_ExternVirtual(0x80B8AD4C, daEnBossCastleRoy_c, Feint);

    /*
     * initializeState: VT+0x694 0x80B2FAC0
     * executeState:    VT+0x698 0x80B2FB70
     * finalizeState:   VT+0x69C 0x80B2FC50
     */
    sState_ExternVirtual(0x80B8AD8C, daEnBossCastleRoy_c, Exit);

    /*
     * initializeState: VT+0x6A0 0x80B2FC60
     * executeState:    VT+0x6A4 0x80B2FD00
     * finalizeState:   VT+0x6A8 0x80B2FF40
     */
    sState_ExternVirtual(0x80B8ADCC, daEnBossCastleRoy_c, Drop);

    /*
     * initializeState: VT+0x3C0 0x80B2FF50
     * executeState:    VT+0x3C4 0x80B30050
     * finalizeState:   VT+0x3C8 0x80B300F0
     */
    sState_ExternVirtual(0x80B8AE0C, daEnBossCastleRoy_c, LandOn);

    /*
     * initializeState: VT+0x450 0x80B301E0
     * executeState:    VT+0x454 0x80B301F0
     * finalizeState:   VT+0x458 0x80B304B0
     */
    sState_ExternVirtual(0x80B8AE4C, daEnBossCastleRoy_c, ShellAtk_St);

    /*
     * initializeState: VT+0x45C 0x80B304C0
     * executeState:    VT+0x460 0x80B30590
     * finalizeState:   VT+0x464 0x80B30830
     */
    sState_ExternVirtual(0x80B8AE8C, daEnBossCastleRoy_c, ShellAtk);

    /*
     * initializeState: VT+0x614 0x80B30840
     * executeState:    VT+0x618 0x80B30860
     * finalizeState:   VT+0x61C 0x80B30A60
     */
    sState_ExternVirtual(0x80B8AECC, daEnBossCastleRoy_c, ShellAtk_Ed);

    /*
     * initializeState: VT+0x468 0x80B30A70
     * executeState:    VT+0x46C 0x80B30AC0
     * finalizeState:   VT+0x470 0x80B30C30
     */
    sState_ExternVirtual(0x80B8AF0C, daEnBossCastleRoy_c, ShellOut);

    /*
     * initializeState: VT+0x408 0x80B30100
     * executeState:    VT+0x40C 0x80B30150
     * finalizeState:   VT+0x410 0x80B30160
     */
    sState_ExternVirtual(0x80B8AF4C, daEnBossCastleRoy_c, FumiHit);

    /*
     * initializeState: VT+0x414 0x80B30170
     * executeState:    VT+0x418 0x80B301C0
     * finalizeState:   VT+0x41C 0x80B301D0
     */
    sState_ExternVirtual(0x80B8AF8C, daEnBossCastleRoy_c, FireHit);

    /*
     * initializeState: VT+0x16C 0x80B30C40
     * executeState:    VT+0x170 0x80B30CB0
     * finalizeState:   VT+0x174 0x80B30DD0
     */
    sState_ExternVirtual(0x80B8AFCC, daEnBossCastleRoy_c, DieFumi);
};
