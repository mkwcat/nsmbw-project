#pragma once

#include "d_actor.h"

class daMovePipe_c : public dActor_c {
    SIZE_ASSERT(0x450);
    VTABLE(0x060, fBase_c, 0x803077A8);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x450);
};
