#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daFloorJrA_c : public dEn_c {
    SIZE_ASSERT(0x8A8);
    VTABLE(0x060, fBase_c, 0x8095AA68);
    // 0x8095AA00 g_profile_FLOOR_JR_A
    // 0x807F0DA0 daFloorJrA_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807F0DD0 */
    daFloorJrA_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x8A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807F1420
     * executeState:    0x807F1440
     * finalizeState:   0x807F1430
     */
    sState_Extern(0x809986E8, daFloorJrA_c, DemoWait);

    /*
     * initializeState: 0x807F1450
     * executeState:    0x807F1470
     * finalizeState:   0x807F1460
     */
    sState_Extern(0x80998728, daFloorJrA_c, Wait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x807F14B0
     * executeState:    VT+0x17C 0x807F14E0
     * finalizeState:   VT+0x180 0x807F14D0
     */
    sState_ExternVirtual(0x80998768, daFloorJrA_c, DieFall);
};
