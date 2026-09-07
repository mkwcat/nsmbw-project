#pragma once

#include "d_a_en_dfpakkun.h"
#include "s_State.h"

class daEnDokanFPakkunRight_c : public daEnDfpakkun_c {
    SIZE_ASSERT(0x760);
    VTABLE(0x060, fBase_c, 0x80AE679C);
    // 0x80AE6790 g_profile_EN_RIGHT_DOKAN_FPAKKUN
    // 0x809F10A0 daEnDokanFPakkunRight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanFPakkunRight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x758, 0x760);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F1560
     * executeState:    VT+0x1D0 0x809F15E0
     * finalizeState:   VT+0x1D4 0x809F15D0
     */
    sState_ExternVirtual(0x80B141CC, daEnDokanFPakkunRight_c, EatIn);
};
