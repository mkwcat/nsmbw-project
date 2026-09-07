#pragma once

#include "d_enemy.h"

class daEnLRStop_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80B06378);

    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLRStop_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};

class daEnLRStopDw_c : public daEnLRStop_c {
    SIZE_ASSERT(0x528);
    // 0x80B0636C g_profile_EN_LR_STOP_DW
    // 0x80A98080 daEnLRStopDw_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLRStopDw_c();
};

class daEnLRStopUp_c : public daEnLRStop_c {
    SIZE_ASSERT(0x528);
    // 0x80B06360 g_profile_EN_LR_STOP_UP
    // 0x80A98030 daEnLRStopUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLRStopUp_c();
};
