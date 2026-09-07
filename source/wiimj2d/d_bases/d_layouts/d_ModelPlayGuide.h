#pragma once

#include "d_base.h"

class dModelPlayGuide_c : public dBase_c {
    SIZE_ASSERT(0x210);
    VTABLE(0x060, fBase_c, 0x80948B70);
    // 0x80948B10 g_profile_MODEL_PLAY_GUIDE
    // 0x80794F90 dModelPlayGuide_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80794FC0 */
    dModelPlayGuide_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x210);
};
