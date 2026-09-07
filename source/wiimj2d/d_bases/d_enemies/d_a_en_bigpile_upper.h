#pragma once

#include "d_a_en_bigpile.h"

class daEnBigPileUpper_c : public daEnBigPile_c {
    SIZE_ASSERT(0x6D0);
    VTABLE(0x060, fBase_c, 0x80AD9DA8);
    // 0x80AD9D98 g_profile_EN_BIGPILE_UPPER
    // 0x809BA9E0 daEnBigPileUpper_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigPileUpper_c();
};
