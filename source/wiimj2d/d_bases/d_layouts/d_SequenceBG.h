#pragma once

#include "d_base.h"

class dSequenceBG_c : public dBase_c {
    SIZE_ASSERT(0x280);
    VTABLE(0x060, fBase_c, 0x8094F088);
    // 0x8094EC40 g_profile_SEQUENCE_BG
    // 0x807AD5F0 dSequenceBG_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807AD620 */
    dSequenceBG_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x280);
};
