#pragma once

#include "d_base.h"
#include "s_State.h"

class dModelPlayBase_c : public dBase_c {
    SIZE_ASSERT(0x28C);
    VTABLE(0x060, fBase_c, 0x809482D0);
    // 0x80948030 g_profile_MODEL_PLAY_BASE
    // 0x80792B00 dModelPlayBase_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80792B30 */
    dModelPlayBase_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x28C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80793220
     * executeState:    0x80793230
     * finalizeState:   0x80793260
     */
    sState_Extern(0x80993788, dModelPlayBase_c, StartWait);

    /*
     * initializeState: 0x80793270
     * executeState:    0x807932F0
     * finalizeState:   0x80793350
     */
    sState_Extern(0x809937C8, dModelPlayBase_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x80793360
     * executeState:    0x80793370
     * finalizeState:   0x80793400
     */
    sState_Extern(0x80993808, dModelPlayBase_c, ActionWait);

    /*
     * initializeState: 0x80793410
     * executeState:    0x80793490
     * finalizeState:   0x807934F0
     */
    sState_Extern(0x80993848, dModelPlayBase_c, DateScroll);

    /*
     * initializeState: 0x80793550
     * executeState:    0x807935C0
     * finalizeState:   0x80793620
     */
    sState_Extern(0x80993888, dModelPlayBase_c, CollectionCoinCount);

    /*
     * initializeState: 0x80793630
     * executeState:    0x80793670
     * finalizeState:   0x807936D0
     */
    sState_Extern(0x809938C8, dModelPlayBase_c, ExitAnimeEndWait);
};
