#pragma once

#include "d_base_actor.h"

class daWmItem_c : public dBaseActor_c {
    SIZE_ASSERT(0x210);
    VTABLE(0x060, fBase_c, 0x80983438);
    // 0x809832B0 g_profile_WM_ITEM
    // 0x808D4890 daWmItem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D48C0 */
    daWmItem_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x808D4F40 */
    void updateVisiblity();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x125, 0x209);

    /* 0x209 */ bool mVisible;

    FILL(0x20A, 0x210);
};
