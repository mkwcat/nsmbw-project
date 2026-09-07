#pragma once

#include "d_enemy.h"

class daEnBigPile_c : public dEn_c {
    SIZE_ASSERT(0x6D0);
    VTABLE(0x060, fBase_c, 0x80301EF8);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6D0);
};
