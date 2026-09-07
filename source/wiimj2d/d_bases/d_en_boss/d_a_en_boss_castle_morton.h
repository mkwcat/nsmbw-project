#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleMorton_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x1010);
    VTABLE(0x0060, fBase_c, 0x80B78F70);
    // 0x80B78EC8 g_profile_EN_BOSS_CASTLE_MORTON
    // 0x80B2AC70 daEnBossCastleMorton_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80B2ACA0 */
    daEnBossCastleMorton_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x1010);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B2BCD0
     * executeState:    0x80B2BCF0
     * finalizeState:   0x80B2BCE0
     */
    sState_Extern(0x80B8A910, daEnBossCastleMorton_c, ShellAtkWait);

    /*
     * initializeState: 0x80B2CE90
     * executeState:    0x80B2CF30
     * finalizeState:   0x80B2CEF0
     */
    sState_Extern(0x80B8AA90, daEnBossCastleMorton_c, DemoAwakeEnd);

    /*
     * initializeState: 0x80B2D2A0
     * executeState:    0x80B2D2C0
     * finalizeState:   0x80B2D2B0
     */
    sState_Extern(0x80B8AAD0, daEnBossCastleMorton_c, StartWait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x5FC 0x80B2B5D0
     * executeState:    VT+0x600 0x80B2B6B0
     * finalizeState:   VT+0x604 0x80B2B670
     */
    sState_ExternVirtual(0x80B8A750, daEnBossCastleMorton_c, QuakeFall);

    /*
     * initializeState: VT+0x608 0x80B2B760
     * executeState:    VT+0x60C 0x80B2B8F0
     * finalizeState:   VT+0x610 0x80B2B8E0
     */
    sState_ExternVirtual(0x80B8A790, daEnBossCastleMorton_c, Quake);

    /*
     * initializeState: VT+0x5F0 0x80B2B580
     * executeState:    VT+0x5F4 0x80B2B5A0
     * finalizeState:   VT+0x5F8 0x80B2B590
     */
    sState_ExternVirtual(0x80B8A7CC, daEnBossCastleMorton_c, AirWait);

    /*
     * initializeState: VT+0x16C 0x80B2C150
     * executeState:    VT+0x170 0x80B2C2A0
     * finalizeState:   VT+0x174 0x80B2C290
     */
    sState_ExternVirtual(0x80B8A80C, daEnBossCastleMorton_c, DieFumi);

    /*
     * initializeState: VT+0x3B4 0x80B2C410
     * executeState:    VT+0x3B8 0x80B2C6B0
     * finalizeState:   VT+0x3BC 0x80B2C6A0
     */
    sState_ExternVirtual(0x80B8A84C, daEnBossCastleMorton_c, BigJump);

    /*
     * initializeState: VT+0x3C0 0x80B2C780
     * executeState:    VT+0x3C4 0x80B2C7D0
     * finalizeState:   VT+0x3C8 0x80B2C7C0
     */
    sState_ExternVirtual(0x80B8A88C, daEnBossCastleMorton_c, LandOn);

    /*
     * initializeState: VT+0x450 0x80B2B980
     * executeState:    VT+0x454 0x80B2B9F0
     * finalizeState:   VT+0x458 0x80B2B9E0
     */
    sState_ExternVirtual(0x80B8A8CC, daEnBossCastleMorton_c, ShellAtk_St);

    /*
     * initializeState: VT+0x45C 0x80B2BEE0
     * executeState:    VT+0x460 0x80B2BF80
     * finalizeState:   VT+0x464 0x80B2BF70
     */
    sState_ExternVirtual(0x80B8A94C, daEnBossCastleMorton_c, ShellAtk);

    /*
     * initializeState: VT+0x408 0x80B2C820
     * executeState:    VT+0x40C 0x80B2C890
     * finalizeState:   VT+0x410 0x80B2C880
     */
    sState_ExternVirtual(0x80B8A98C, daEnBossCastleMorton_c, FumiHit);

    /*
     * initializeState: VT+0x414 0x80B2CA50
     * executeState:    VT+0x418 0x80B2CA70
     * finalizeState:   VT+0x41C 0x80B2CA60
     */
    sState_ExternVirtual(0x80B8A9CC, daEnBossCastleMorton_c, FireHit);

    /*
     * initializeState: VT+0x280 0x80B2CAD0
     * executeState:    VT+0x284 0x80B2CC00
     * finalizeState:   VT+0x288 0x80B2CBC0
     */
    sState_ExternVirtual(0x80B8AA0C, daEnBossCastleMorton_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B2CD50
     * executeState:    VT+0x5A4 0x80B2CDE0
     * finalizeState:   VT+0x5A8 0x80B2CDD0
     */
    sState_ExternVirtual(0x80B8AA4C, daEnBossCastleMorton_c, DemoAwake);
};
