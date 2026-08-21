#pragma once

#include "d_static/d_enemy/d_enemy.h"

class dBossLifeCommon_c {
public:
    // Structors
    // ^^^^^^

    /* VT+0x8 0x8009A2E0 */
    virtual ~dBossLifeCommon_c();

public:
    /* 0x4 */ int mLife;
};

class dEnBoss_c : public dEn_c {
    SIZE_ASSERT(0x600); // Assumed

    VTABLE(0x60, fBase_c, 0x80312288);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F8);

    /* 0x5F8 */ dBossLifeCommon_c* mpBossLife;

    FILL(0x5FC, 0x600);
};
