#pragma once

#include "d_enemy.h"

class daWallInsectMgr_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x8097F740);
    // 0x8097F730 g_profile_WALLINSECT_MGR
    // 0x808BC430 daWallInsectMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWallInsectMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
