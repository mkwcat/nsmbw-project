#pragma once

#include "d_a_en_dpakkun_base.h"
#include "s_State.h"

class daEnDokanPakkunDown_c : public daEnDpakkunBase_c {
    SIZE_ASSERT(0x6E8);
    VTABLE(0x060, fBase_c, 0x80AE6F04);
    // 0x80AE6EF8 g_profile_EN_DOWN_DOKAN_PAKKUN
    // 0x809F28D0 daEnDokanPakkunDown_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanPakkunDown_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6E0, 0x6E8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F2D20
     * executeState:    VT+0x1D0 0x809F2D60
     * finalizeState:   VT+0x1D4 0x809F2D50
     */
    sState_ExternVirtual(0x80B1424C, daEnDokanPakkunDown_c, EatIn);
};
