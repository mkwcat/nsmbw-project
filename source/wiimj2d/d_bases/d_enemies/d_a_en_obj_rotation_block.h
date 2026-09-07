#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnObjRotationBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x710);
    VTABLE(0x060, fBase_c, 0x80B0068C);
    // 0x80B00680 g_profile_EN_ROTATION_BLOCK
    // 0x80A7AD50 daEnObjRotationBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjRotationBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x710);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A7B6E0
     * executeState:    0x80A7B700
     * finalizeState:   0x80A7B6F0
     */
    sState_Extern(0x80B196A8, daEnObjRotationBlock_c, SearchID);

    /*
     * initializeState: 0x80A7B760
     * executeState:    0x80A7B780
     * finalizeState:   0x80A7B770
     */
    sState_Extern(0x80B196E8, daEnObjRotationBlock_c, Wait);

    /*
     * initializeState: 0x80A7B7D0
     * executeState:    0x80A7B7F0
     * finalizeState:   0x80A7B7E0
     */
    sState_Extern(0x80B19728, daEnObjRotationBlock_c, MoveEnd);
};
