#pragma once

#include "d_actor_state.h"

class daCageBlock_c : public dActorState_c {
    SIZE_ASSERT(0x970);
    VTABLE(0x060, fBase_c, 0x80955DE0);
    // 0x80955D40 g_profile_CAGE_BLOCK
    // 0x807D5C60 daCageBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCageBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x970);
};
