#pragma once

#include "System.h"
#include "d_base.h"

class sPhase_c;

class dScene_c : public dBase_c
{
    SIZE_ASSERT(0x74);

public:
    /* 0x800E1AA0 */
    dScene_c();

    /* VT+0x48 0x800E1B10 */
    virtual ~dScene_c() override;

    /* 0x70 */ sPhase_c* mpPhase;

    /* 0x80428A42 */ static u16 m_nowScene;
};
