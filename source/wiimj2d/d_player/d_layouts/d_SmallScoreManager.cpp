// d_SmallScoreManager.cpp
// NSMBW .text: 0x8010CAE0 - 0x8010D270

#include "d_SmallScoreManager.h"

#include "machine/m_vec.h"

[[nsmbw(0x8042A5B0)]]
dSmallScoreManager_c* dSmallScoreManager_c::m_instance;

[[nsmbw(0x8010CFC0)]]
void dSmallScoreManager_c::CreateBlueNumber(const mVec3_c& pos, int, int);

[[nsmbw(0x8010CFE0)]]
void dSmallScoreManager_c::CreateRedNumber(const mVec3_c& pos, int);

[[nsmbw(0x8010D000)]]
void dSmallScoreManager_c::CreateSmallScore(const mVec3_c& pos, int type, int color);

[[nsmbw(0x8010D0B0)]]
void dSmallScoreManager_c::CreateGoalScore(const mVec3_c& pos, int type, int color);

[[nsmbw(0x8010D160)]]
void dSmallScoreManager_c::GoalScoreExecute(const mVec3_c& pos, int);
