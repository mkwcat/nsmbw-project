#pragma once

#include "d_system/d_wm_actor.h"

class dCsSeqMng_c : public dWmActor_c
{
    SIZE_ASSERT(0x1D4);

public:
    // Instance Methods
    // ^^^^^^

    // Why is this at 0x801017C0???
    // Why are there a bunch of dCsSeqMng_c functions around that area???
    // They're not static, so I'm not sure how they got there...
    // Someone smarter than me will probably look over this later
    /* 0x801017C0 @unofficial */
    bool addScriptToQueue(u32 id, void*, void*, u32);

    /* 0x80915600 */
    bool UNDEF_80915600();

    /* 0x80915630 */
    u32 UNDEF_80915630();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x138, 0x1D4);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A48C */ static dCsSeqMng_c* ms_instance;
};