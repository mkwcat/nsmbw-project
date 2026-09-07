#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockWater_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x720);
    VTABLE(0x060, fBase_c, 0x80ADCDF4);
    // 0x80ADCDE8 g_profile_EN_BLOCK_HATENA_WATER
    // 0x809C6CE0 daEnBlockWater_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockWater_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x720);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C78F0
     * executeState:    0x809C7910
     * finalizeState:   0x809C7900
     */
    sState_Extern(0x80B12948, daEnBlockWater_c, Wait);

    /*
     * initializeState: 0x809C7920
     * executeState:    0x809C7940
     * finalizeState:   0x809C7930
     */
    sState_Extern(0x80B12988, daEnBlockWater_c, HitWait);
};
