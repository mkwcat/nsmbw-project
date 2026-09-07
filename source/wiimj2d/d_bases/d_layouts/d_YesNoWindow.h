#pragma once

#include "d_base.h"

class dYesNoWindow_c : public dBase_c {
    SIZE_ASSERT(0x29C);
    VTABLE(0x060, fBase_c, 0x8076B930);
    // 0x8076B470 g_profile_YES_NO_WINDOW
    // 0x80768A80 dYesNoWindow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80768AB0 */
    dYesNoWindow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x29C);
};
