#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daNeedleForKoopaJrB_c : public dEn_c {
    SIZE_ASSERT(0x3990);
    VTABLE(0x0060, fBase_c, 0x80971140);
    // 0x80971090 g_profile_NEEDLE_FOR_KOOPA_JR_B
    // 0x8086CF50 daNeedleForKoopaJrB_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8086D1D0 */
    daNeedleForKoopaJrB_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x3990);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8086D930
     * executeState:    0x8086D9A0
     * finalizeState:   0x8086D990
     */
    sState_Extern(0x8099CFD0, daNeedleForKoopaJrB_c, DemoAwake);

    /*
     * initializeState: 0x8086DA40
     * executeState:    0x8086DC40
     * finalizeState:   0x8086DC30
     */
    sState_Extern(0x8099D010, daNeedleForKoopaJrB_c, Idle);

    /*
     * initializeState: 0x8086DEA0
     * executeState:    0x8086DF60
     * finalizeState:   0x8086DF50
     */
    sState_Extern(0x8099D050, daNeedleForKoopaJrB_c, Die);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x284 0x8086D900
     * executeState:    VT+0x288 0x8086D920
     * finalizeState:   VT+0x28C 0x8086D910
     */
    sState_ExternVirtual(0x8099CF8C, daNeedleForKoopaJrB_c, DemoWait);
};
