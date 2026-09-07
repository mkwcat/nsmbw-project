#pragma once

#include "d_actor.h"

class daKinokoLiftParent_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80962DC4);
    // 0x80962DB8 g_profile_KINOKO_LIFT_PARENT
    // 0x80821EF0 daKinokoLiftParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKinokoLiftParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
