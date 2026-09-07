#pragma once

#include "d_a_en_dpakkun_base.h"
#include "s_State.h"

class daEnDokanPakkunRight_c : public daEnDpakkunBase_c {
    SIZE_ASSERT(0x6E8);
    VTABLE(0x060, fBase_c, 0x80AE76B4);
    // 0x80AE76A8 g_profile_EN_RIGHT_DOKAN_PAKKUN
    // 0x809F3F20 daEnDokanPakkunRight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanPakkunRight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6E0, 0x6E8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F4390
     * executeState:    VT+0x1D0 0x809F43D0
     * finalizeState:   VT+0x1D4 0x809F43C0
     */
    sState_ExternVirtual(0x80B142CC, daEnDokanPakkunRight_c, EatIn);
};
