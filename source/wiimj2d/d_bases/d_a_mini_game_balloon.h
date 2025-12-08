#pragma once

#include "d_system/d_enemy.h"

class daMiniGameBalloon_c : public dEn_c {
public:
    // Virtual Functions
    // ^^^^^^

    /* 0x80864170 */
    bool hitCallback_Cannon(dCc_c* self, dCc_c* other);

public:
    // Instance Methods
    // ^^^^^^

    /* unofficial */
    void EffectBalloonGet(int playerType, mVec3_c *effPos);
};
