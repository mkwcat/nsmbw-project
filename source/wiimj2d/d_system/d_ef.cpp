// d_ef.cpp
// NSMBW .text: 0x8008F920 - 0x8008FE30

#include "d_system/d_ef.h"

namespace dEf
{

[[address(0x8008FB60)]]
void createPlayerEffect(
    int playerID, const char *name, unsigned long, const mVec3_c *pos, const mAng3_c *angle, const mVec3_c *scale
);

[[address(0x8008FBA0)]]
void createPlayerEffect(
    int playerID, mEf::levelEffect_c effect, const char *name, unsigned long, const mVec3_c *pos, const mAng3_c *angle, const mVec3_c *scale
);

} // namespace dEf
