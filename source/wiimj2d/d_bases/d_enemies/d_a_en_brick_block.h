#pragma once

#include "d_a_en_blockmain.h"

class daEnBrickBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x6C8);
    VTABLE(0x060, fBase_c, 0x80ADEC9C);
    // 0x80ADEC90 g_profile_EN_BKBLOCK
    // 0x809D0090 daEnBkblock_c_classInit

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x809D0120 */
    PACK_RESULT_e create() override;

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBrickBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x6C8);
};
