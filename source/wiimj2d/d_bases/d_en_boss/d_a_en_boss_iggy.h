#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossIggy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0xE80);
    VTABLE(0x060, fBase_c, 0x80B7BB38);
    // 0x80B7B6E8 g_profile_EN_BOSS_IGGY
    // 0x80B34EB0 daEnBossIggy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossIggy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xE80);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80B36870
     * executeState:    VT+0x170 0x80B36970
     * finalizeState:   VT+0x174 0x80B36960
     */
    sState_ExternVirtual(0x80B8B21C, daEnBossIggy_c, DieFumi);

    /*
     * initializeState: VT+0x3F0 0x80B35EC0
     * executeState:    VT+0x3F4 0x80B35EE0
     * finalizeState:   VT+0x3F8 0x80B35ED0
     */
    sState_ExternVirtual(0x80B8B25C, daEnBossIggy_c, Attack);

    /*
     * initializeState: VT+0x3E4 0x80B360D0
     * executeState:    VT+0x3E8 0x80B36120
     * finalizeState:   VT+0x3EC 0x80B36110
     */
    sState_ExternVirtual(0x80B8B29C, daEnBossIggy_c, AttackSearch);

    /*
     * initializeState: VT+0x45C 0x80B36130
     * executeState:    VT+0x460 0x80B361D0
     * finalizeState:   VT+0x464 0x80B361C0
     */
    sState_ExternVirtual(0x80B8B2DC, daEnBossIggy_c, ShellAtk);

    /*
     * initializeState: VT+0x5E4 0x80B36390
     * executeState:    VT+0x5E8 0x80B36400
     * finalizeState:   VT+0x5EC 0x80B363F0
     */
    sState_ExternVirtual(0x80B8B31C, daEnBossIggy_c, ShellAtk_Ed);

    /*
     * initializeState: VT+0x390 0x80B365B0
     * executeState:    VT+0x394 0x80B36610
     * finalizeState:   VT+0x398 0x80B36600
     */
    sState_ExternVirtual(0x80B8B35C, daEnBossIggy_c, Jump_St);

    /*
     * initializeState: VT+0x39C 0x80B36620
     * executeState:    VT+0x3A0 0x80B36640
     * finalizeState:   VT+0x3A4 0x80B36630
     */
    sState_ExternVirtual(0x80B8B39C, daEnBossIggy_c, Jump);

    /*
     * initializeState: VT+0x3A8 0x80B36710
     * executeState:    VT+0x3AC 0x80B36770
     * finalizeState:   VT+0x3B0 0x80B36760
     */
    sState_ExternVirtual(0x80B8B3DC, daEnBossIggy_c, BigJump_St);

    /*
     * initializeState: VT+0x3B4 0x80B36780
     * executeState:    VT+0x3B8 0x80B367A0
     * finalizeState:   VT+0x3BC 0x80B36790
     */
    sState_ExternVirtual(0x80B8B41C, daEnBossIggy_c, BigJump);

    /*
     * initializeState: VT+0x5A0 0x80B369F0
     * executeState:    VT+0x5A4 0x80B36A80
     * finalizeState:   VT+0x5A8 0x80B36A70
     */
    sState_ExternVirtual(0x80B8B45C, daEnBossIggy_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B36B50
     * executeState:    VT+0x5B0 0x80B36BE0
     * finalizeState:   VT+0x5B4 0x80B36BD0
     */
    sState_ExternVirtual(0x80B8B49C, daEnBossIggy_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x5B8 0x80B36C50
     * executeState:    VT+0x5BC 0x80B36D00
     * finalizeState:   VT+0x5C0 0x80B36CF0
     */
    sState_ExternVirtual(0x80B8B4DC, daEnBossIggy_c, DemoIkaku);

    /*
     * initializeState: VT+0x5C4 0x80B36E60
     * executeState:    VT+0x5C8 0x80B36F00
     * finalizeState:   VT+0x5CC 0x80B36EF0
     */
    sState_ExternVirtual(0x80B8B51C, daEnBossIggy_c, DemoIkaku_Wait);

    /*
     * initializeState: VT+0x5F0 0x80B36F70
     * executeState:    VT+0x5F4 0x80B37090
     * finalizeState:   VT+0x5F8 0x80B37080
     */
    sState_ExternVirtual(0x80B8B55C, daEnBossIggy_c, DemoFall);

    /*
     * initializeState: VT+0x5FC 0x80B37130
     * executeState:    VT+0x600 0x80B37280
     * finalizeState:   VT+0x604 0x80B37270
     */
    sState_ExternVirtual(0x80B8B59C, daEnBossIggy_c, DemoFallEd);

    /*
     * initializeState: VT+0x5D0 0x80B37420
     * executeState:    VT+0x5D4 0x80B37540
     * finalizeState:   VT+0x5D8 0x80B37530
     */
    sState_ExternVirtual(0x80B8B5DC, daEnBossIggy_c, DemoEscape_St);

    /*
     * initializeState: VT+0x608 0x80B37670
     * executeState:    VT+0x60C 0x80B37720
     * finalizeState:   VT+0x610 0x80B37710
     */
    sState_ExternVirtual(0x80B8B61C, daEnBossIggy_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x614 0x80B377F0
     * executeState:    VT+0x618 0x80B379F0
     * finalizeState:   VT+0x61C 0x80B379E0
     */
    sState_ExternVirtual(0x80B8B65C, daEnBossIggy_c, DemoEscape_Jump);
};
