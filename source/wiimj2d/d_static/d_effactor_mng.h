#pragma once

#include "machine/m_vec.h"

class dEffActorMng_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800923D0 */
    void execute();

    /* 0x800925F0 */
    bool createBlockFragEff(mVec3_c&, unsigned long, s8);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A1C8 */ static dEffActorMng_c* m_instance;
};
