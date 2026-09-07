#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockStaffRoll_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x808);
    VTABLE(0x060, fBase_c, 0x80ADC654);
    // 0x80ADC4A0 g_profile_EN_BLOCK_STAFFROLL
    // 0x809C4DB0 daEnBlockStaffRoll_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockStaffRoll_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x808);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C5B40
     * executeState:    0x809C5B60
     * finalizeState:   0x809C5B50
     */
    sState_Extern(0x80B12848, daEnBlockStaffRoll_c, Wait);

    /*
     * initializeState: 0x809C5B80
     * executeState:    0x809C5BA0
     * finalizeState:   0x809C5B90
     */
    sState_Extern(0x80B12888, daEnBlockStaffRoll_c, HitWait);
};
