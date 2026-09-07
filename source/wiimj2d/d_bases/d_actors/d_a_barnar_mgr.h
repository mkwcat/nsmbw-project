#pragma once

#include "d_actor.h"

class daBarnarMgr_c : public dActor_c {
    SIZE_ASSERT(0x3A8);
    VTABLE(0x060, fBase_c, 0x8095153C);
    // 0x80951530 g_profile_BARNAR_MGR
    // 0x807B8EA0 daBarnarMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBarnarMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A8);
};
