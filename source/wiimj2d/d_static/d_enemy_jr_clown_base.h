#pragma once

#include "d_enemy.h"
#include "machine/m_3d_anmtexpat.h"
#include <nw4r/g3d/g3d_resanmtexpat.h>
#include <nw4r/g3d/g3d_resfile.h>

class dEnJrClownBase_c : public dEn_c
{
    SIZE_ASSERT(0xD48);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x540);

    /* 0x540 */ nw4r::g3d::ResFile mRes;
    /* 0x544 */ m3d::mdl_c mModel;

    FILL(0x584, 0x5E8);

    /* 0x5E8 */ nw4r::g3d::ResAnmTexPat mResPat;
    /* 0x5EC */ m3d::anmTexPat_c mPlyChangePat;

    FILL(0x618, 0xD48);
};