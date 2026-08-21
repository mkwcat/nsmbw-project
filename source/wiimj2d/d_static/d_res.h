#pragma once

#include <nw4r/g3d/g3d_resfile.h>

class dRes_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800DF270 */
    nw4r::g3d::ResFile getRes(const char*, const char*) const;
};