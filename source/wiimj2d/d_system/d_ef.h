#pragma once

#include "egg/util/eggEffect.h"
#include "machine/m_ef.h"
#include <revolution/sc.h>

class mVec3_c;

class mAng3_c;

namespace dEf
{

/* 0x8008FB60 */
void createPlayerEffect(
    int playerID, const char *name, unsigned long, const mVec3_c *pos, const mAng3_c *angle, const mVec3_c *scale
);

/* 0x8008FBA0 */
void createPlayerEffect(
    int playerID, mEf::levelEffect_c effect, const char *name, unsigned long, const mVec3_c *pos, const mAng3_c *angle, const mVec3_c *scale
);

class dLevelEffect_c : public mEf::levelEffect_c
{

};

} // namespace dEf
