#pragma once

#include "d_base.h"

class daLemmyFoothold_c : public dBase_c {
    SIZE_ASSERT(0x6A8);
    // 0x80966030 g_profile_LEMMY_FOOTHOLD
    // 0x80833400 daLemmyFoothold_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLemmyFoothold_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x6A8);
};
