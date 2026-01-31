// d_enemy_carry.cpp
// NSMBW .text: 0x8009EAF0 - 0x8009F5F0

#include "d_enemy_carry.h"

[[nsmbw(0x8009EF90)]]
void dEnemyCarry_c::initializeState_Throw()
{
    setCollTimer(mPlrNo, 12);
    mCc.mCcData.mVsKind |= 0xA0;

    if (m0x524) {
        return;
    }

    mCc.mCcData.mAttack = 9;
}