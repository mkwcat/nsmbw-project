#pragma once

#include "d_system/d_wm_csvdata.h"
#include "d_system/d_wm_demo_actor.h"
#include "machine/m_vec.h"

class daWmMap_c : public dWmDemoActor_c
{
    SIZE_ASSERT(0x6C510);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80100310 */
    mVec3_c GetPos(int node);

    /* 0x808DFE50 */
    void createEnemyActors();

    /* 0x808E1750 */
    void createMapActors();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A46C */ static daWmMap_c* m_instance;

public:
    // Instance Variables
    // ^^^^^

    FILL(0x174, 0x3388);

    /* 0x3388 */ u32 mCurrentWorld;
    /* 0x338C */ int mCurrentMap;
    /* 0x3390 */ int m0x3390;
    /* 0x3394 */ dCsvData_c mCsvData[4];

    FILL(0x5C7F4, 0x6C510);
};
