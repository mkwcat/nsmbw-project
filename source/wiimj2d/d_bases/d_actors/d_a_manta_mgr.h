#pragma once

#include "d_actor.h"

class daMantaMgr_c : public dActor_c {
    SIZE_ASSERT(0x4A0);
    VTABLE(0x060, fBase_c, 0x8096C74C);
    // 0x8096C740 g_profile_MANTA_MGR
    // 0x8085F330 daMantaMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMantaMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x4A0);
};
