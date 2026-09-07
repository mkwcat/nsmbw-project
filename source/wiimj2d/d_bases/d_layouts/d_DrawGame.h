#pragma once

#include "d_base.h"
#include "s_State.h"

class dDrawGame_c : public dBase_c {
    SIZE_ASSERT(0x254);
    VTABLE(0x060, fBase_c, 0x80942878);
    // 0x809427B0 g_profile_DRAW_GAME
    // 0x8077F450 dDrawGame_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8077F480 */
    dDrawGame_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x254);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8077F980
     * executeState:    0x8077F990
     * finalizeState:   0x8077FA10
     */
    sState_Extern(0x80991B30, dDrawGame_c, FadeInEndWait);

    /*
     * initializeState: 0x8077FA20
     * executeState:    0x8077FA70
     * finalizeState:   0x8077FAD0
     */
    sState_Extern(0x80991B70, dDrawGame_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x8077FAE0
     * executeState:    0x8077FB20
     * finalizeState:   0x8077FB50
     */
    sState_Extern(0x80991BB0, dDrawGame_c, DispEndWait);

    /*
     * initializeState: 0x8077FB60
     * executeState:    0x8077FB70
     * finalizeState:   0x8077FBE0
     */
    sState_Extern(0x80991BF0, dDrawGame_c, ExitAnimeEndWait);
};
