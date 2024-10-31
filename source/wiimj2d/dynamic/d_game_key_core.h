#pragma once

#include <machine/m_pad.h>

class dGameKeyCore_c
{
    SIZE_ASSERT(0x94);
    /* 0x0 VTABLE 0x80315910 */

public:
    /* 0x800B5B50 */
    dGameKeyCore_c(mPad::CH_e channel);

    /* VT+0x8 0x800B5BA0 */
    virtual ~dGameKeyCore_c();

public:
    FILL(0x04, 0x94);
};