#pragma once

#include "d_wm_actor.h"

class daWmGrid_c : public dWmActor_c {
    SIZE_ASSERT(0x164);
    VTABLE(0x060, fBase_c, 0x80982F40);
    // 0x80982F34 g_profile_WM_GRID
    // 0x808D19A0 daWmGrid_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D19D0 */
    daWmGrid_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x138, 0x164);
};
