#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossKameck_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x1238);
    VTABLE(0x0060, fBase_c, 0x80B7CAEC);
    // 0x80B7C790 g_profile_EN_BOSS_KAMECK
    // 0x80B38FB0 daEnBossKameck_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80B39060 */
    daEnBossKameck_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x1238);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B3A140
     * executeState:    VT+0x284 0x80B3A180
     * finalizeState:   VT+0x288 0x80B3A220
     */
    sState_ExternVirtual(0x80B8B724, daEnBossKameck_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B3A230
     * executeState:    VT+0x5A4 0x80B3A250
     * finalizeState:   VT+0x5A8 0x80B3A270
     */
    sState_ExternVirtual(0x80B8B764, daEnBossKameck_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B3A280
     * executeState:    VT+0x5B0 0x80B3A290
     * finalizeState:   VT+0x5B4 0x80B3A2A0
     */
    sState_ExternVirtual(0x80B8B7A4, daEnBossKameck_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x5E4 0x80B3A2B0
     * executeState:    VT+0x5E8 0x80B3A350
     * finalizeState:   VT+0x5EC 0x80B3A3D0
     */
    sState_ExternVirtual(0x80B8B7E4, daEnBossKameck_c, Disappear_St);

    /*
     * initializeState: VT+0x5F0 0x80B3A3E0
     * executeState:    VT+0x5F4 0x80B3A4E0
     * finalizeState:   VT+0x5F8 0x80B3A640
     */
    sState_ExternVirtual(0x80B8B824, daEnBossKameck_c, Disappear);

    /*
     * initializeState: VT+0x5FC 0x80B3A650
     * executeState:    VT+0x600 0x80B3A880
     * finalizeState:   VT+0x604 0x80B3ABB0
     */
    sState_ExternVirtual(0x80B8B864, daEnBossKameck_c, Vanish);

    /*
     * initializeState: VT+0x608 0x80B3ABC0
     * executeState:    VT+0x60C 0x80B3AD40
     * finalizeState:   VT+0x610 0x80B3AEC0
     */
    sState_ExternVirtual(0x80B8B8A4, daEnBossKameck_c, Appear);

    /*
     * initializeState: VT+0x3E4 0x80B3AED0
     * executeState:    VT+0x3E8 0x80B3AF20
     * finalizeState:   VT+0x3EC 0x80B3AFE0
     */
    sState_ExternVirtual(0x80B8B8E4, daEnBossKameck_c, AttackSearch);

    /*
     * initializeState: VT+0x3F0 0x80B3AFF0
     * executeState:    VT+0x3F4 0x80B3B000
     * finalizeState:   VT+0x3F8 0x80B3B2B0
     */
    sState_ExternVirtual(0x80B8B924, daEnBossKameck_c, Attack);

    /*
     * initializeState: VT+0x3FC 0x80B3B2C0
     * executeState:    VT+0x400 0x80B3B2D0
     * finalizeState:   VT+0x404 0x80B3B370
     */
    sState_ExternVirtual(0x80B8B964, daEnBossKameck_c, AttackEnd);

    /*
     * initializeState: VT+0x408 0x80B3B380
     * executeState:    VT+0x40C 0x80B3B410
     * finalizeState:   VT+0x410 0x80B3B5D0
     */
    sState_ExternVirtual(0x80B8B9A4, daEnBossKameck_c, FumiHit);

    /*
     * initializeState: VT+0x414 0x80B3B5E0
     * executeState:    VT+0x418 0x80B3B5F0
     * finalizeState:   VT+0x41C 0x80B3B650
     */
    sState_ExternVirtual(0x80B8B9E4, daEnBossKameck_c, FireHit);

    /*
     * initializeState: VT+0x42C 0x80B3B660
     * executeState:    VT+0x430 0x80B3B670
     * finalizeState:   VT+0x434 0x80B3B690
     */
    sState_ExternVirtual(0x80B8BA24, daEnBossKameck_c, StarHit);

    /*
     * initializeState: VT+0x444 0x80B3B6A0
     * executeState:    VT+0x448 0x80B3B6B0
     * finalizeState:   VT+0x44C 0x80B3B6D0
     */
    sState_ExternVirtual(0x80B8BA64, daEnBossKameck_c, ShellHit);

    /*
     * initializeState: VT+0x28C 0x80B3B6E0
     * executeState:    VT+0x290 0x80B3B6F0
     * finalizeState:   VT+0x294 0x80B3B710
     */
    sState_ExternVirtual(0x80B8BAA4, daEnBossKameck_c, DieFire);

    /*
     * initializeState: VT+0x2A4 0x80B3B720
     * executeState:    VT+0x2A8 0x80B3B730
     * finalizeState:   VT+0x2AC 0x80B3B750
     */
    sState_ExternVirtual(0x80B8BAE4, daEnBossKameck_c, DieShell);

    /*
     * initializeState: VT+0x2B0 0x80B3B760
     * executeState:    VT+0x2B4 0x80B3B770
     * finalizeState:   VT+0x2B8 0x80B3B790
     */
    sState_ExternVirtual(0x80B8BB24, daEnBossKameck_c, DieStar);

    /*
     * initializeState: VT+0x474 0x80B3B7A0
     * executeState:    VT+0x478 0x80B3B7D0
     * finalizeState:   VT+0x47C 0x80B3B990
     */
    sState_ExternVirtual(0x80B8BB64, daEnBossKameck_c, DieFumi_St);

    /*
     * initializeState: VT+0x16C 0x80B3B9A0
     * executeState:    VT+0x170 0x80B3B9B0
     * finalizeState:   VT+0x174 0x80B3B9D0
     */
    sState_ExternVirtual(0x80B8BBA4, daEnBossKameck_c, DieFumi);

    /*
     * initializeState: VT+0x614 0x80B3B9E0
     * executeState:    VT+0x618 0x80B3B9F0
     * finalizeState:   VT+0x61C 0x80B3BA10
     */
    sState_ExternVirtual(0x80B8BBE4, daEnBossKameck_c, DemoFall);

    /*
     * initializeState: VT+0x620 0x80B3BA20
     * executeState:    VT+0x624 0x80B3BB30
     * finalizeState:   VT+0x628 0x80B3BC30
     */
    sState_ExternVirtual(0x80B8BC24, daEnBossKameck_c, DemoFall_Ed);

    /*
     * initializeState: VT+0x5D0 0x80B3BC40
     * executeState:    VT+0x5D4 0x80B3BCD0
     * finalizeState:   VT+0x5D8 0x80B3BD60
     */
    sState_ExternVirtual(0x80B8BC64, daEnBossKameck_c, DemoEscape_St);

    /*
     * initializeState: VT+0x62C 0x80B3BD70
     * executeState:    VT+0x630 0x80B3BEC0
     * finalizeState:   VT+0x634 0x80B3BF40
     */
    sState_ExternVirtual(0x80B8BCA4, daEnBossKameck_c, DemoEscape_Ready);

    /*
     * initializeState: VT+0x638 0x80B3BF50
     * executeState:    VT+0x63C 0x80B3C060
     * finalizeState:   VT+0x640 0x80B3C1B0
     */
    sState_ExternVirtual(0x80B8BCE4, daEnBossKameck_c, DemoEscape_Jump);
};
