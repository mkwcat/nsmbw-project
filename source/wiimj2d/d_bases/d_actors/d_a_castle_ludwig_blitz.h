#pragma once

#include "d_actor_state.h"

class daCastleLudwigBlitz_c : public dActorState_c {
    SIZE_ASSERT(0x6F8);
    VTABLE(0x060, fBase_c, 0x8096BF38);
    // 0x8096BE48 g_profile_CASTLE_LUDWIG_BLITZ
    // 0x8085BCB0 daCastleLudwigBlitz_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCastleLudwigBlitz_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6F8);
};
