#pragma once

#include "d_a_en_dfpakkun.h"
#include "s_State.h"

class daEnDokanFPakkunLeft_c : public daEnDfpakkun_c {
    SIZE_ASSERT(0x760);
    VTABLE(0x060, fBase_c, 0x80AE63E4);
    // 0x80AE63D8 g_profile_EN_LEFT_DOKAN_FPAKKUN
    // 0x809F0580 daEnDokanFPakkunLeft_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanFPakkunLeft_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x758, 0x760);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F0A40
     * executeState:    VT+0x1D0 0x809F0A80
     * finalizeState:   VT+0x1D4 0x809F0A70
     */
    sState_ExternVirtual(0x80B1418C, daEnDokanFPakkunLeft_c, EatIn);
};
