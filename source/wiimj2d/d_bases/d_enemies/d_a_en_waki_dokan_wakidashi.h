#pragma once

#include "d_actor.h"

class daDokanWakidashi_c : public dActor_c {
    SIZE_ASSERT(0x3C0);
    VTABLE(0x060, fBase_c, 0x80B0D2DC);
    // 0x80B0D2D0 g_profile_DOKAN_WAKIDASHI
    // 0x80ABB5E0 daDokanWakidashi_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDokanWakidashi_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3C0);
};
