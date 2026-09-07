#pragma once

#include "d_base.h"

class dInfoWindow_c : public dBase_c {
    SIZE_ASSERT(0x224);
    VTABLE(0x060, fBase_c, 0x80945510);
    // 0x80945418 g_profile_INFO_WINDOW
    // 0x80789810 dInfoWindow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80789840 */
    dInfoWindow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x224);
};
