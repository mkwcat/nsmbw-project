#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleWendy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0xFD0);
    VTABLE(0x060, fBase_c, 0x80B7AC80);
    // 0x80B7AB38 g_profile_EN_BOSS_CASTLE_WENDY
    // 0x80B32540 daEnBossCastleWendy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossCastleWendy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xFD0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80B33190
     * executeState:    VT+0x284 0x80B331D0
     * finalizeState:   VT+0x288 0x80B332A0
     */
    sState_ExternVirtual(0x80B8B014, daEnBossCastleWendy_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B332B0
     * executeState:    VT+0x5A4 0x80B332C0
     * finalizeState:   VT+0x5A8 0x80B33390
     */
    sState_ExternVirtual(0x80B8B054, daEnBossCastleWendy_c, DemoAwake);

    /*
     * initializeState: VT+0x5AC 0x80B333A0
     * executeState:    VT+0x5B0 0x80B333B0
     * finalizeState:   VT+0x5B4 0x80B333C0
     */
    sState_ExternVirtual(0x80B8B094, daEnBossCastleWendy_c, DemoAwake_Wait);

    /*
     * initializeState: VT+0x450 0x80B337B0
     * executeState:    VT+0x454 0x80B33800
     * finalizeState:   VT+0x458 0x80B33B30
     */
    sState_ExternVirtual(0x80B8B0D4, daEnBossCastleWendy_c, ShellAtk_St);

    /*
     * initializeState: VT+0x45C 0x80B33B40
     * executeState:    VT+0x460 0x80B33C00
     * finalizeState:   VT+0x464 0x80B33E60
     */
    sState_ExternVirtual(0x80B8B114, daEnBossCastleWendy_c, ShellAtk);

    /*
     * initializeState: VT+0x39C 0x80B333D0
     * executeState:    VT+0x3A0 0x80B33430
     * finalizeState:   VT+0x3A4 0x80B335B0
     */
    sState_ExternVirtual(0x80B8B154, daEnBossCastleWendy_c, Jump);

    /*
     * initializeState: VT+0x3B4 0x80B335C0
     * executeState:    VT+0x3B8 0x80B33620
     * finalizeState:   VT+0x3BC 0x80B337A0
     */
    sState_ExternVirtual(0x80B8B194, daEnBossCastleWendy_c, BigJump);

    /*
     * initializeState: VT+0x16C 0x80B33E70
     * executeState:    VT+0x170 0x80B33F10
     * finalizeState:   VT+0x174 0x80B34140
     */
    sState_ExternVirtual(0x80B8B1D4, daEnBossCastleWendy_c, DieFumi);
};
