#pragma once

#include "d_static/d_base.h"

class dWiiStrap_c : public dBase_c
{
    SIZE_ASSERT(0x20A);

public:
    /* 0x60 VTABLE 0x80323118 */

    FILL(0x70, 0x208);

    /* 0x208 */ bool mReady;
    /* 0x209 */ bool mVisible;
};
