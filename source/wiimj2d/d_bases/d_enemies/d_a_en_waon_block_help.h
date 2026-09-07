#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockHelp_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x790);
    VTABLE(0x060, fBase_c, 0x80B0EC60);
    // 0x80B0EC30 g_profile_EN_BLOCK_HELP
    // 0x80AC3680 daEnBlockHelp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockHelp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x790);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC3FA0
     * executeState:    0x80AC3FC0
     * finalizeState:   0x80AC3FB0
     */
    sState_Extern(0x80B1C458, daEnBlockHelp_c, Wait);
};
