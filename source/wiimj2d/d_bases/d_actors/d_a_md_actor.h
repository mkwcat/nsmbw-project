#pragma once

#include "d_md_actor.h"

class daMdActor_c : public dMdActor_c {
    SIZE_ASSERT(0xBEC0);
    VTABLE(0x0060, fBase_c, 0x8096E890);
    // 0x8096C9C8 g_profile_MD_ACTOR
    // 0x808604D0 daMdActor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMdActor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0138, 0xBEC0);
};
