#pragma once

#include <dynamic/d_wm_demo_actor.h>

class daWmMap_c : public dWmDemoActor_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    /* 0x808DFE50 */
    void createEnemyActors();

    /* 0x808E1750 */
    void createMapActors();

public:
    // -----------
    // Static Data
    // -----------

    /* 0x8042A46C */ static daWmMap_c* m_instance;
};