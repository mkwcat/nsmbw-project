#pragma once

#include "d_scene.h"

class dScMovie_c : public dScene_c {
    SIZE_ASSERT(0x1A4);
    VTABLE(0x060, fBase_c, 0x8098D2F0);
    // 0x8098CD18 g_profile_MOVIE
    // 0x80922060 dScMovie_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80922460 */
    dScMovie_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x074, 0x1A4);

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x20 0x80922910
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;
};
