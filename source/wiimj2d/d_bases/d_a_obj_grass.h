#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_base.h"

class daObjGrass_c : public dBase_c {
public:
    FILL(0x0070, 0x2464);

    /* 0x2464 */ float mPlayerDist[4];

    FILL(0x2474, 0x2480);
    OFFSET_ASSERT(0x2480);

#define daObjGrass_c_OFFSET_mPlayerDistEx 0x2480
    /* 0x2480 */ float mPlayerDistEx[PLAYER_COUNT - 4];
};
