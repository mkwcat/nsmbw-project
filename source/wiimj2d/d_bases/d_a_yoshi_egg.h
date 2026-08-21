#pragma once

#include "d_static/d_enemy.h"

class daYoshiEgg_c : public dEn_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80911380 */
    void loadModel();

    /* 0x80911540 */
    void playAnimation(int);

    /* 0x80911610 */
    void spawnEggBreakEffect();

    /* 0x80911680 */
    void hatchYoshi();

    /* 0x80911AD0 */
    void initializeState_MultiJumpUp();

    /* 0x80911BD0 */
    void initializeState_MultiJumpDown();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F4);

    /* 0x5F4 */ int m0x5F4;
    /* 0x5F8 */ int mColor;

    FILL(0x5F8, 0x60C);

    /* 0x60C */ u16 m0x60C;
    /* 0x60E */ u8 m0x60E;

    FILL(0x60F, 0x610);
};
