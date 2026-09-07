#pragma once

#include "d_enemy_carry.h"
#include "s_State.h"

class daEnJumpdai_c : public dEnemyCarry_c {
    SIZE_ASSERT(0x670);
    VTABLE(0x060, fBase_c, 0x80AF3F14);
    // 0x80AF3ED0 g_profile_EN_JUMPDAI
    // 0x80A38A00 daEnJumpdai_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A38A30 */
    daEnJumpdai_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x526, 0x670);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A3A440
     * executeState:    0x80A3A460
     * finalizeState:   0x80A3A450
     */
    sState_Extern(0x80B170D8, daEnJumpdai_c, Move);

    /*
     * initializeState: 0x80A3A000
     * executeState:    0x80A3A070
     * finalizeState:   0x80A3A010
     */
    sState_Extern(0x80B17118, daEnJumpdai_c, CarryUp);

    /*
     * initializeState: 0x80A3A1D0
     * executeState:    0x80A3A2F0
     * finalizeState:   0x80A3A2E0
     */
    sState_Extern(0x80B17158, daEnJumpdai_c, CarryUpThrow);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x80A3A5A0
     * executeState:    VT+0x1E8 0x80A3A660
     * finalizeState:   VT+0x1EC 0x80A3A640
     */
    sState_ExternVirtual(0x80B17194, daEnJumpdai_c, EatOut);
};
