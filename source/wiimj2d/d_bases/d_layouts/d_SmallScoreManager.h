#pragma once

#include "d_base.h"

class mVec3_c;

class dSmallScoreManager_c : public dBase_c {
    SIZE_ASSERT(0x4A18);
    VTABLE(0x0060, fBase_c, 0x80322B48);
    // 0x80322B18 g_profile_SMALL_SCORE_MANAGER
    // 0x8010CAE0 dSmallScoreManager_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8010CB10 */
    dSmallScoreManager_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8010CFC0 */
    void CreateBlueNumber(const mVec3_c& pos, int, int);

    /* 0x8010CFE0 */
    void CreateRedNumber(const mVec3_c& pos, int);

    /* 0x8010D000 */
    void CreateSmallScore(const mVec3_c& pos, int type, int color);

    /* 0x8010D0B0 */
    void CreateGoalScore(const mVec3_c& pos, int type, int color);

    /* 0x8010D160 */
    void GoalScoreExecute(const mVec3_c& pos, int color);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0070, 0x4A18);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A5B0 */ static dSmallScoreManager_c* m_instance;
};
