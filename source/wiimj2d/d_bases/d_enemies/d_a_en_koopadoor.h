#pragma once

#include "d_a_en_door.h"

class daEnKoopaDoor_c : public daEnDoor_c {
    SIZE_ASSERT(0x638);
    VTABLE(0x060, fBase_c, 0x80AF7564);
    // 0x80AF7528 g_profile_EN_KOOPADOOR
    // 0x80A529B0 daEnKoopaDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKoopaDoor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x5E0, 0x638);
};
