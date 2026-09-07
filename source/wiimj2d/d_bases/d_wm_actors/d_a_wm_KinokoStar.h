#pragma once

#include "d_a_wm_KinokoBase.h"

class daWmKinokoStar_c : public daWmKinokoBase_c {
    SIZE_ASSERT(0x294);
    VTABLE(0x060, fBase_c, 0x80983E68);
    // 0x80983E3C g_profile_WM_KINOKO_STAR
    // 0x808D96E0 daWmKinokoStar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D9710 */
    daWmKinokoStar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x290, 0x294);
};
