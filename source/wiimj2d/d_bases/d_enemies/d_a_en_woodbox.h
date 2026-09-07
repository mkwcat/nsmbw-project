#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnWoodBox_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x748);
    VTABLE(0x060, fBase_c, 0x80B1083C);
    // 0x80B106D8 g_profile_EN_WOODBOX
    // 0x80ACB7C0 daEnWoodBox_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWoodBox_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x748);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80ACC5B0
     * executeState:    0x80ACC640
     * finalizeState:   0x80ACC630
     */
    sState_Extern(0x80B1C8D0, daEnWoodBox_c, Wait);
};
