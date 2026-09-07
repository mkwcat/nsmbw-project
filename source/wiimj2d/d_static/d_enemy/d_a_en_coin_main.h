#pragma once

#include "d_a_en_obj_coinblock.h"

class daEnCoinMain_c : public daEnObjCoinBlock_c {
    SIZE_ASSERT(0x8D0);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x74C, 0x8D0);
};
