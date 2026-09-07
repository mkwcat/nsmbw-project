#pragma once

#include "d_enemy.h"
#include "state/s_State.h"

class daKoopaShipForCastleDemo_c : public dEn_c {
    SIZE_ASSERT(0x948);
    VTABLE(0x060, fBase_c, 0x80964B28);
    // 0x80964AE0 g_profile_KOOPA_SHIP_FOR_CASTLE_DEMO
    // 0x8082CCB0 daKoopaShipForCastleDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8082CD00 */
    daKoopaShipForCastleDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x948);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8082D8B0
     * executeState:    VT+0x284 0x8082D970
     * finalizeState:   VT+0x288 0x8082D960
     */
    sState_ExternVirtual(0x8099A984, daKoopaShipForCastleDemo_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x8082DA30
     * executeState:    VT+0x290 0x8082DB00
     * finalizeState:   VT+0x294 0x8082DAF0
     */
    sState_ExternVirtual(0x8099A9C4, daKoopaShipForCastleDemo_c, DemoEscape);
};
