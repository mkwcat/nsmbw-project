#pragma once

#include "d_a_en_dfpakkun.h"
#include "s_State.h"

class daEnDokanFPakkunDown_c : public daEnDfpakkun_c {
    SIZE_ASSERT(0x760);
    VTABLE(0x060, fBase_c, 0x80AE602C);
    // 0x80AE6020 g_profile_EN_DOWN_DOKAN_FPAKKUN
    // 0x809EF840 daEnDokanFPakkunDown_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanFPakkunDown_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x758, 0x760);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809EFD60
     * executeState:    VT+0x1D0 0x809EFDD0
     * finalizeState:   VT+0x1D4 0x809EFDC0
     */
    sState_ExternVirtual(0x80B1414C, daEnDokanFPakkunDown_c, EatIn);
};
