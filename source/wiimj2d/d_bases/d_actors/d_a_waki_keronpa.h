#pragma once

#include "d_actor.h"

class daWakiKeronpa_c : public dActor_c {
    SIZE_ASSERT(0x3A0);
    VTABLE(0x060, fBase_c, 0x8097E76C);
    // 0x8097E760 g_profile_WAKI_KERONPA
    // 0x808B5A20 daWakiKeronpa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiKeronpa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A0);
};
