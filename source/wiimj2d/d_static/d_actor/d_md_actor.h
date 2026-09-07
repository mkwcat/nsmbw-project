#pragma once

#include "d_base_actor.h"

class dMdActor_c : public dBaseActor_c {
    SIZE_ASSERT(0x138);
    VTABLE(0x060, fBase_c, 0x80317C30);

public:
    // Structors
    // ^^^^^^

    /* 0x800CD800 */
    dMdActor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x125, 0x138);
};
