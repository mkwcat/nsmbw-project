#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnRouletBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x7D8);
    VTABLE(0x060, fBase_c, 0x80B07098);
    // 0x80B07030 g_profile_EN_RULETBLOCK
    // 0x80A9A450 daEnRouletBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRouletBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x7D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A9B040
     * executeState:    0x80A9B060
     * finalizeState:   0x80A9B050
     */
    sState_Extern(0x80B1AB90, daEnRouletBlock_c, HitEnd);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2EC 0x80A9AFD0
     * executeState:    VT+0x2F0 0x80A9AFF0
     * finalizeState:   VT+0x2F4 0x80A9AFE0
     */
    sState_ExternVirtual(0x80B1AB4C, daEnRouletBlock_c, Wait);
};
