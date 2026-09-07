#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daCastleBossDoor_c : public dEn_c {
    SIZE_ASSERT(0x680);
    VTABLE(0x060, fBase_c, 0x809564E0);
    // 0x80956468 g_profile_CASTLE_BOSS_DOOR
    // 0x807D8630 daCastleBossDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807D8690 */
    daCastleBossDoor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x680);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x807D8B00
     * executeState:    VT+0x284 0x807D8B20
     * finalizeState:   VT+0x288 0x807D8B10
     */
    sState_ExternVirtual(0x80997544, daCastleBossDoor_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x807D8B30
     * executeState:    VT+0x290 0x807D8C10
     * finalizeState:   VT+0x294 0x807D8C00
     */
    sState_ExternVirtual(0x80997584, daCastleBossDoor_c, DemoDown);

    /*
     * initializeState: VT+0x298 0x807D8D70
     * executeState:    VT+0x29C 0x807D8DF0
     * finalizeState:   VT+0x2A0 0x807D8DE0
     */
    sState_ExternVirtual(0x809975C4, daCastleBossDoor_c, DemoUp);
};
