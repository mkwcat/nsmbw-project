#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockSoroban_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x798);
    VTABLE(0x060, fBase_c, 0x80ADC118);
    // 0x80ADC0B0 g_profile_EN_BLOCK_SOROBAN
    // 0x809C4040 daEnBlockSoroban_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockSoroban_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x798);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C4A40
     * executeState:    0x809C4A60
     * finalizeState:   0x809C4A50
     */
    sState_Extern(0x80B12808, daEnBlockSoroban_c, Wait);
};
