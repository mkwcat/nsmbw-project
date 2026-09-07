#pragma once

#include "d_enemy_boss_koopa_jr_base.h"

class daKoopaJrForCastleDemo_c : public dEnBossKoopaJrBase_c {
    SIZE_ASSERT(0xC50);
    VTABLE(0x060, fBase_c, 0x80964080);
    // 0x80964028 g_profile_KOOPA_JR_FOR_CASTLE_DEMO
    // 0x80829C90 daKoopaJrForCastleDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80829CC0 */
    daKoopaJrForCastleDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xC3C, 0xC50);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8082A2A0
     * executeState:    0x8082A370
     * finalizeState:   0x8082A360
     */
    sState_Extern(0x8099A7C8, daKoopaJrForCastleDemo_c, ProvocateOnFloor);

    /*
     * initializeState: 0x8082A430
     * executeState:    0x8082A4E0
     * finalizeState:   0x8082A4D0
     */
    sState_Extern(0x8099A808, daKoopaJrForCastleDemo_c, JumpOnShip);

    /*
     * initializeState: 0x8082A920
     * executeState:    0x8082A970
     * finalizeState:   0x8082A960
     */
    sState_Extern(0x8099A848, daKoopaJrForCastleDemo_c, ProvocateOnShip);

    /*
     * initializeState: 0x8082AB90
     * executeState:    0x8082AC90
     * finalizeState:   0x8082AC80
     */
    sState_Extern(0x8099A888, daKoopaJrForCastleDemo_c, ProvocateOnFloorLong);

    /*
     * initializeState: 0x8082AE60
     * executeState:    0x8082AF00
     * finalizeState:   0x8082AEF0
     */
    sState_Extern(0x8099A8C8, daKoopaJrForCastleDemo_c, Angry);

    /*
     * initializeState: 0x8082B140
     * executeState:    0x8082B1F0
     * finalizeState:   0x8082B1E0
     */
    sState_Extern(0x8099A908, daKoopaJrForCastleDemo_c, FallDown);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8082A160
     * executeState:    VT+0x284 0x8082A200
     * finalizeState:   VT+0x288 0x8082A1F0
     */
    sState_ExternVirtual(0x8099A784, daKoopaJrForCastleDemo_c, DemoWait);
};
