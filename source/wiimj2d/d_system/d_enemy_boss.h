#pragma once

#include "d_enemy.h"

class dBossLifeCommon_c
{
public:
    // Structors
    // ^^^^^^

    /* VT+0x8 0x8009A2E0 */
    virtual ~dBossLifeCommon_c();

public:
    /* 0x4 */ int mLife;
};

class dEnBoss_c : public dEn_c
{
public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F8);

    /* 0x5F8 */ dBossLifeCommon_c* mpBossLife;
};