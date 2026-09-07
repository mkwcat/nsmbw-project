#pragma once

#include "d_a_wm_KinokoBase.h"

class daWmKinoko1up_c : public daWmKinokoBase_c {
    SIZE_ASSERT(0x294);
    VTABLE(0x060, fBase_c, 0x80983A98);
    // 0x80983A6C g_profile_WM_KINOKO_1UP
    // 0x808D8860 daWmKinoko1up_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D8890 */
    daWmKinoko1up_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x290, 0x294);
};
