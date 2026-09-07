#pragma once

#include "d_enemy_toride_kokoopa.h"
#include "s_State.h"

class daEnBossCastleIggy_c : public dEnTorideKokoopa_c {
    SIZE_ASSERT(0x10A8);
    VTABLE(0x0060, fBase_c, 0x80B75E90);
    // 0x80B75CA8 g_profile_EN_BOSS_CASTLE_IGGY
    // 0x80B1CB60 daEnBossCastleIggy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBossCastleIggy_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80B1D450 */
    bool FUN_80B1D450();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0600, 0x10A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80B1DCE0
     * executeState:    0x80B1DD00
     * finalizeState:   0x80B1DCF0
     */
    sState_Extern(0x80B89AB8, daEnBossCastleIggy_c, Driving_St);

    /*
     * initializeState: 0x80B1DD60
     * executeState:    0x80B1DE20
     * finalizeState:   0x80B1DE10
     */
    sState_Extern(0x80B89AF8, daEnBossCastleIggy_c, Driving);

    /*
     * initializeState: 0x80B1DF70
     * executeState:    0x80B1E070
     * finalizeState:   0x80B1E000
     */
    sState_Extern(0x80B89B38, daEnBossCastleIggy_c, FunnyAction);

    /*
     * initializeState: 0x80B1E130
     * executeState:    0x80B1E1F0
     * finalizeState:   0x80B1E1E0
     */
    sState_Extern(0x80B89B78, daEnBossCastleIggy_c, Topple);

    /*
     * initializeState: 0x80B1F090
     * executeState:    0x80B1F170
     * finalizeState:   0x80B1F160
     */
    sState_Extern(0x80B89BB8, daEnBossCastleIggy_c, UpsideDown);

    /*
     * initializeState: 0x80B1F6B0
     * executeState:    0x80B1F6E0
     * finalizeState:   0x80B1F6C0
     */
    sState_Extern(0x80B89EF8, daEnBossCastleIggy_c, DemoAwakeEnd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x3CC 0x80B1E2D0
     * executeState:    VT+0x3D0 0x80B1E2F0
     * finalizeState:   VT+0x3D4 0x80B1E2E0
     */
    sState_ExternVirtual(0x80B89BF4, daEnBossCastleIggy_c, AttackReady);

    /*
     * initializeState: VT+0x3D8 0x80B1E3E0
     * executeState:    VT+0x3DC 0x80B1E400
     * finalizeState:   VT+0x3E0 0x80B1E3F0
     */
    sState_ExternVirtual(0x80B89C34, daEnBossCastleIggy_c, AttackBegin);

    /*
     * initializeState: VT+0x3E4 0x80B1E4D0
     * executeState:    VT+0x3E8 0x80B1E4F0
     * finalizeState:   VT+0x3EC 0x80B1E4E0
     */
    sState_ExternVirtual(0x80B89C74, daEnBossCastleIggy_c, AttackSearch);

    /*
     * initializeState: VT+0x3F0 0x80B1E700
     * executeState:    VT+0x3F4 0x80B1E720
     * finalizeState:   VT+0x3F8 0x80B1E710
     */
    sState_ExternVirtual(0x80B89CB4, daEnBossCastleIggy_c, Attack);

    /*
     * initializeState: VT+0x3FC 0x80B1E8F0
     * executeState:    VT+0x400 0x80B1E970
     * finalizeState:   VT+0x404 0x80B1E900
     */
    sState_ExternVirtual(0x80B89CF4, daEnBossCastleIggy_c, AttackEnd);

    /*
     * initializeState: VT+0x414 0x80B1EC60
     * executeState:    VT+0x418 0x80B1EC80
     * finalizeState:   VT+0x41C 0x80B1EC70
     */
    sState_ExternVirtual(0x80B89D34, daEnBossCastleIggy_c, FireHit);

    /*
     * initializeState: VT+0x42C 0x80B1ED30
     * executeState:    VT+0x430 0x80B1ED50
     * finalizeState:   VT+0x434 0x80B1ED40
     */
    sState_ExternVirtual(0x80B89D74, daEnBossCastleIggy_c, StarHit);

    /*
     * initializeState: VT+0x420 0x80B1EE00
     * executeState:    VT+0x424 0x80B1EE20
     * finalizeState:   VT+0x428 0x80B1EE10
     */
    sState_ExternVirtual(0x80B89DB4, daEnBossCastleIggy_c, SlideHit);

    /*
     * initializeState: VT+0x408 0x80B1EA90
     * executeState:    VT+0x40C 0x80B1EAB0
     * finalizeState:   VT+0x410 0x80B1EAA0
     */
    sState_ExternVirtual(0x80B89DF4, daEnBossCastleIggy_c, FumiHit);

    /*
     * initializeState: VT+0x16C 0x80B1EED0
     * executeState:    VT+0x170 0x80B1EF40
     * finalizeState:   VT+0x174 0x80B1EF30
     */
    sState_ExternVirtual(0x80B89E34, daEnBossCastleIggy_c, DieFumi);

    /*
     * initializeState: VT+0x280 0x80B1F360
     * executeState:    VT+0x284 0x80B1F480
     * finalizeState:   VT+0x288 0x80B1F440
     */
    sState_ExternVirtual(0x80B89E74, daEnBossCastleIggy_c, DemoWait);

    /*
     * initializeState: VT+0x5A0 0x80B1F5E0
     * executeState:    VT+0x5A4 0x80B1F620
     * finalizeState:   VT+0x5A8 0x80B1F610
     */
    sState_ExternVirtual(0x80B89EB4, daEnBossCastleIggy_c, DemoAwake);
};
