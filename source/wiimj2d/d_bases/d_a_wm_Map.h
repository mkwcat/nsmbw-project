#pragma once

#include "d_system/d_mj2d_game.h"
#include "d_system/d_wm_connect.h"
#include "d_system/d_wm_csvdata.h"
#include "d_system/d_wm_demo_actor.h"
#include "machine/m_vec.h"

class daWmMap_c : public dWmDemoActor_c {
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

    /* 0x808E2250 */
    bool IsRouteOpen(const char* routeName);

    /* 0x808E2250 */
    bool IsRouteOpen2(const char* routeName);

    /* 0x808E2380 */
    bool IsIbaraRouteOpen(const char* subRoute1, const char* subRoute2);

    /* 0x808E2380 */
    bool IsIbaraRouteOpen2(const char* subRoute1, const char* subRoute2);

public:
    // Instance Methods
    // ++++++

    void setNodeRndizer();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A46C */ static daWmMap_c* m_instance;

    // ++++++

    static STAGE_e m_setStageRndizer;

public:
    // Instance Variables
    // ^^^^^

    FILL(0x00174, 0x03388);

    /* 0x03388 */ u32          mCurrentWorld;
    /* 0x0338C */ int          mCurrentMap;
    /* 0x03390 */ int          m0x3390;
    /* 0x03394 */ dCsvData_c   mCsvData[4];
    /* 0x5C7F4 */ dWmConnect_c mConnect[4];

    FILL(0x6C414, 0x6C510);
};
