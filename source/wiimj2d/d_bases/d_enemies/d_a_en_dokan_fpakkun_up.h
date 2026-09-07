#pragma once

#include "d_a_en_dfpakkun.h"
#include "s_State.h"

class daEnDokanFPakkunUp_c : public daEnDfpakkun_c {
    SIZE_ASSERT(0x760);
    VTABLE(0x060, fBase_c, 0x80AE6B54);
    // 0x80AE6B48 g_profile_EN_UP_DOKAN_FPAKKUN
    // 0x809F1C20 daEnDokanFPakkunUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanFPakkunUp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x758, 0x760);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F21E0
     * executeState:    VT+0x1D0 0x809F2250
     * finalizeState:   VT+0x1D4 0x809F2240
     */
    sState_ExternVirtual(0x80B1420C, daEnDokanFPakkunUp_c, EatIn);
};
