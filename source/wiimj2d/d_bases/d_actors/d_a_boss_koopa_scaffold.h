#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBossKoopaScaffold_c : public dActorState_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80955788);
    // 0x809556C0 g_profile_AC_BOSS_KOOPA_SCAFFOLD
    // 0x807D40E0 daBossKoopaScaffold_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBossKoopaScaffold_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x528);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x807D44F0
     * executeState:    VT+0xE4 0x807D4570
     * finalizeState:   VT+0xE8 0x807D4580
     */
    sState_ExternVirtual(0x8099703C, daBossKoopaScaffold_c, Wait);

    /*
     * initializeState: VT+0xEC 0x807D4590
     * executeState:    VT+0xF0 0x807D4720
     * finalizeState:   VT+0xF4 0x807D47C0
     */
    sState_ExternVirtual(0x8099707C, daBossKoopaScaffold_c, Fall);
};
