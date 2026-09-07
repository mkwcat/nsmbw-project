#pragma once

#include "d_base.h"

class dSelectCursor_c : public dBase_c {
    SIZE_ASSERT(0xD3C);
    VTABLE(0x060, fBase_c, 0x80322AC8);
    // 0x803229E8 g_profile_SELECT_CURSOR
    // 0x8010C130 dSelectCursor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8010C160 */
    dSelectCursor_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8010C890 */
    void Cancel(int param);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0xD3C);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A5A8 */ static dSelectCursor_c* m_instance;
};
