#pragma once

#include "d_a_en_dpakkun_base.h"
#include "s_State.h"

class daEnDokanPakkunUp_c : public daEnDpakkunBase_c {
    SIZE_ASSERT(0x6E8);
    VTABLE(0x060, fBase_c, 0x80AE7A8C);
    // 0x80AE7A80 g_profile_EN_UP_DOKAN_PAKKUN
    // 0x809F4A20 daEnDokanPakkunUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDokanPakkunUp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x6E0, 0x6E8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1CC 0x809F4F20
     * executeState:    VT+0x1D0 0x809F4F60
     * finalizeState:   VT+0x1D4 0x809F4F50
     */
    sState_ExternVirtual(0x80B1430C, daEnDokanPakkunUp_c, EatIn);
};
