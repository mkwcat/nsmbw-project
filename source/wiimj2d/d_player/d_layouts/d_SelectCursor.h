#pragma once

#include "d_static/d_base.h"

class dSelectCursor_c : public dBase_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8010C890 */
    void Cancel(int param);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A5A8 */ static dSelectCursor_c* m_instance;
};
