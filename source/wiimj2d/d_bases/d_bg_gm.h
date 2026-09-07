#pragma once

#include "d_bg.h"

class dAcPy_c;

class dBgGm_c : public dBg_c {
    SIZE_ASSERT(0x90BE4);
    VTABLE(0x00060, fBase_c, 0x80327590);
    // 0x804296A0 g_profile_BG_GM
    // 0x80154800 dBgGm_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    dBgGm_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80154F90 @unofficial */
    bool inW2CastleMazeBounds(float param1, float param2);

    /* 0x801550A0 */
    PACK_RESULT_e execute() override;

    /* 0x80156960 */
    dAcPy_c* getNumberPlayerP(int player);

    /* 0x80156A10 */
    int getActScrPlayerNum();

    /* 0x80156BF0 @unofficial */
    bool UNDEF_80156BF0(void* param1, void* param2, void* param3);

    /* 0x80156D70 @unofficial */
    bool isManualZoomActive(void* param1);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x90AAC, 0x90BE4);
};
