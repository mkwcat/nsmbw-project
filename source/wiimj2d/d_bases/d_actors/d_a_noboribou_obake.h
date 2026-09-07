#pragma once

#include "d_actor.h"

class daNoboribouObake_c : public dActor_c {
    SIZE_ASSERT(0x408);
    VTABLE(0x060, fBase_c, 0x80971BE8);
    // 0x80971BB0 g_profile_NOBORIBOU_OBAKE
    // 0x80872BC0 daNoboribouObake_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daNoboribouObake_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x408);
};
