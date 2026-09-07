#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBossKoopaBGEffect_c : public dActorState_c {
    SIZE_ASSERT(0x400);
    VTABLE(0x060, fBase_c, 0x80954308);
    // 0x80954288 g_profile_AC_BOSS_KOOPA_BG_EFFECT
    // 0x807C8BA0 daBossKoopaBGEffect_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBossKoopaBGEffect_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x400);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x807C8F80
     * executeState:    VT+0xE4 0x807C8F90
     * finalizeState:   VT+0xE8 0x807C8FA0
     */
    sState_ExternVirtual(0x80996BDC, daBossKoopaBGEffect_c, Wait);
};
