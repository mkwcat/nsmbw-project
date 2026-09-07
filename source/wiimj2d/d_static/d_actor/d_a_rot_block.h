#pragma once

#include "d_actor_state.h"

class daRotBlock_c : public dActorState_c {
    SIZE_ASSERT(0x4E0);
    VTABLE(0x060, fBase_c, 0x80309C38);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4E0);
};
