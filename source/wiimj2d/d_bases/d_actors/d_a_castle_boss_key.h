#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daCastleBossKey_c : public dEn_c {
    SIZE_ASSERT(0x970);
    VTABLE(0x060, fBase_c, 0x80956950);
    // 0x809568D8 g_profile_CASTLE_BOSS_KEY
    // 0x807D94F0 daCastleBossKey_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807D9600 */
    daCastleBossKey_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x970);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807D9E40
     * executeState:    0x807D9E60
     * finalizeState:   0x807D9E50
     */
    sState_Extern(0x80997608, daCastleBossKey_c, DemoWait);

    /*
     * initializeState: 0x807D9E70
     * executeState:    0x807D9EF0
     * finalizeState:   0x807D9EE0
     */
    sState_Extern(0x80997648, daCastleBossKey_c, DemoFall);

    /*
     * initializeState: 0x807D9FD0
     * executeState:    0x807DA020
     * finalizeState:   0x807DA010
     */
    sState_Extern(0x80997688, daCastleBossKey_c, DemoWaft);

    /*
     * initializeState: 0x807DA110
     * executeState:    0x807DA160
     * finalizeState:   0x807DA150
     */
    sState_Extern(0x809976C8, daCastleBossKey_c, DemoRise);

    /*
     * initializeState: 0x807DA1C0
     * executeState:    0x807DA310
     * finalizeState:   0x807DA300
     */
    sState_Extern(0x80997708, daCastleBossKey_c, DemoCatch);

    /*
     * initializeState: 0x807DA3A0
     * executeState:    0x807DA3F0
     * finalizeState:   0x807DA3E0
     */
    sState_Extern(0x80997748, daCastleBossKey_c, DemoFlaunt);

    /*
     * initializeState: 0x807DA4E0
     * executeState:    0x807DA510
     * finalizeState:   0x807DA500
     */
    sState_Extern(0x80997788, daCastleBossKey_c, DemoInvisible);
};
