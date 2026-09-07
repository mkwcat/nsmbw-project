#pragma once

#include "d_base_actor.h"
#include "d_mj2d_game.h"

class daObjGrass_c : public dBaseActor_c {
    // Original size: 0x2480
    VTABLE(0x0060, fBase_c, 0x80972760);
    // 0x80972660 g_profile_OBJ_GRASS
    // 0x808760E0 daObjGrass_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjGrass_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0125, 0x2464);

    /* 0x2464 */ float mPlayerDist[4];

    FILL(0x2474, 0x2480);
    OFFSET_ASSERT(0x2480);

#define daObjGrass_c_OFFSET_mPlayerDistEx 0x2480
    /* 0x2480 */ float mPlayerDistEx[PLAYER_COUNT - 4];
};
