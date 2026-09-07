#pragma once

#include "d_a_en_dpakkun_base.h"
#include "s_State.h"

class daEnDokanPakkunLeft_c : public daEnDpakkunBase_c {
    SIZE_ASSERT(0x6E8);
    VTABLE(0x060, fBase_c, 0x80AE72DC);
    // 0x80AE72D0 g_profile_EN_LEFT_DOKAN_PAKKUN
    // 0x809F3420 daEnDokanPakkunLeft_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanPakkunLeft_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6E0, 0x6E8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F3890
     * executeState:    VT+0x1D0 0x809F38D0
     * finalizeState:   VT+0x1D4 0x809F38C0
     */
    sState_ExternVirtual(0x80B1428C, daEnDokanPakkunLeft_c, EatIn);
};
