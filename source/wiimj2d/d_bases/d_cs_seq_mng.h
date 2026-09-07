#pragma once

#include "d_wm_actor.h"

class dCsSeqMng_c : public dWmActor_c {
    SIZE_ASSERT(0x1D4);
    VTABLE(0x060, fBase_c, 0x8098A9C0);
    // 0x8098A98C g_profile_WM_CS_SEQ_MNG
    // 0x80914680 dCsSeqMng_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x809146B0 */
    dCsSeqMng_c();

public:
    // Instance Methods
    // ^^^^^^

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
