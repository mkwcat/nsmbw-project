#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daKokoopaBall_c : public dEn_c {
    SIZE_ASSERT(0x6F8);
    VTABLE(0x060, fBase_c, 0x80962F00);
    // 0x80962E98 g_profile_KOKOOPA_BALL
    // 0x80821FE0 daKokoopaBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKokoopaBall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6F8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2BC 0x808232B0
     * executeState:    VT+0x2C0 0x808232E0
     * finalizeState:   VT+0x2C4 0x808232D0
     */
    sState_ExternVirtual(0x8099A33C, daKokoopaBall_c, Wait);

    /*
     * initializeState: VT+0x2C8 0x80823360
     * executeState:    VT+0x2CC 0x80823480
     * finalizeState:   VT+0x2D0 0x80823470
     */
    sState_ExternVirtual(0x8099A37C, daKokoopaBall_c, Move);

    /*
     * initializeState: VT+0x2D4 0x80823800
     * executeState:    VT+0x2D8 0x80823860
     * finalizeState:   VT+0x2DC 0x80823850
     */
    sState_ExternVirtual(0x8099A3BC, daKokoopaBall_c, BookingDown);

    /*
     * initializeState: VT+0x2E0 0x80823A30
     * executeState:    VT+0x2E4 0x80823AF0
     * finalizeState:   VT+0x2E8 0x80823AE0
     */
    sState_ExternVirtual(0x8099A3FC, daKokoopaBall_c, Down);

    /*
     * initializeState: VT+0x2EC 0x80823B50
     * executeState:    VT+0x2F0 0x80823BD0
     * finalizeState:   VT+0x2F4 0x80823BC0
     */
    sState_ExternVirtual(0x8099A43C, daKokoopaBall_c, Vanish);
};
