#pragma once

#include "d_a_bullet.h"
#include "s_State.h"

class daManhole_c : public daBullet_c {
    SIZE_ASSERT(0x458);
    VTABLE(0x060, fBase_c, 0x8096C188);
    // 0x8096C150 g_profile_MANHOLE
    // 0x8085CD20 daManhole_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daManhole_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x400, 0x458);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8085D010
     * executeState:    0x8085D040
     * finalizeState:   0x8085D030
     */
    sState_Extern(0x8099C728, daManhole_c, Wait);

    /*
     * initializeState: 0x8085D060
     * executeState:    0x8085D110
     * finalizeState:   0x8085D100
     */
    sState_Extern(0x8099C768, daManhole_c, Move);
};
