#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleLarry_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x1108);
    VTABLE(0x0060, fBase_c, 0x80B76BA0);
    // 0x80B76B58 g_profile_EN_BOSS_CASTLE_LARRY
    // 0x80B21450 daEnBossCastleLarry_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossCastleLarry_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x1108);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B21CA0
     * executeState:    VT+0x284 0x80B21CE0
     * finalizeState:   VT+0x288 0x80B21D80
     */
    sState_ExternVirtual(0x80B89F34, daEnBossCastleLarry_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B21D90
     * executeState:    VT+0x5A4 0x80B21DC0
     * finalizeState:   VT+0x5A8 0x80B21DE0
     */
    sState_ExternVirtual(0x80B89F74, daEnBossCastleLarry_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B21DF0
     * executeState:    VT+0x5B0 0x80B21E00
     * finalizeState:   VT+0x5B4 0x80B21E10
     */
    sState_ExternVirtual(0x80B89FB4, daEnBossCastleLarry_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x39C 0x80B21E20
     * executeState:    VT+0x3A0 0x80B21ED0
     * finalizeState:   VT+0x3A4 0x80B21EE0
     */
    sState_ExternVirtual(0x80B89FF4, daEnBossCastleLarry_c, Jump);

    /*
     * initializeState: VT+0x3B4 0x80B21EF0
     * executeState:    VT+0x3B8 0x80B21FA0
     * finalizeState:   VT+0x3BC 0x80B21FB0
     */
    sState_ExternVirtual(0x80B8A034, daEnBossCastleLarry_c, BigJump);

    /*
     * initializeState: VT+0x45C 0x80B21FC0
     * executeState:    VT+0x460 0x80B22090
     * finalizeState:   VT+0x464 0x80B22350
     */
    sState_ExternVirtual(0x80B8A074, daEnBossCastleLarry_c, ShellAtk);

    /*
     * initializeState: VT+0x620 0x80B22360
     * executeState:    VT+0x624 0x80B22380
     * finalizeState:   VT+0x628 0x80B22620
     */
    sState_ExternVirtual(0x80B8A0B4, daEnBossCastleLarry_c, ShellAtk_Ed);

    /*
     * initializeState: VT+0x16C 0x80B22630
     * executeState:    VT+0x170 0x80B226A0
     * finalizeState:   VT+0x174 0x80B227D0
     */
    sState_ExternVirtual(0x80B8A0F4, daEnBossCastleLarry_c, DieFumi);
};
