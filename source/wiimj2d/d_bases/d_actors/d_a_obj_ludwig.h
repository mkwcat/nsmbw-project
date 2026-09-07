#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjLudwig_c : public dEn_c {
    SIZE_ASSERT(0x890);
    VTABLE(0x060, fBase_c, 0x80974860);
    // 0x809747F8 g_profile_OBJ_LUDWIG
    // 0x80881B10 daObjLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80881B40 */
    daObjLudwig_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x890);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80882620
     * executeState:    0x80882640
     * finalizeState:   0x80882630
     */
    sState_Extern(0x8099D8E0, daObjLudwig_c, Wait);

    /*
     * initializeState: 0x80882650
     * executeState:    0x808826F0
     * finalizeState:   0x808826E0
     */
    sState_Extern(0x8099D920, daObjLudwig_c, BattleReady);

    /*
     * initializeState: 0x80882750
     * executeState:    0x80882770
     * finalizeState:   0x80882760
     */
    sState_Extern(0x8099D960, daObjLudwig_c, Battle);

    /*
     * initializeState: 0x808827D0
     * executeState:    0x808827F0
     * finalizeState:   0x808827E0
     */
    sState_Extern(0x8099D9A0, daObjLudwig_c, EndDemo);
};
