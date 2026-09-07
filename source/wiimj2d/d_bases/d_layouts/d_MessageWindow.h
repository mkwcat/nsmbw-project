#pragma once

#include "d_base.h"
#include "s_State.h"

class dMessageWindow_c : public dBase_c {
    SIZE_ASSERT(0x260);
    VTABLE(0x060, fBase_c, 0x80945B30);
    // 0x80945A20 g_profile_MESSAGE_WINDOW
    // 0x8078AD30 dMessageWindow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8078AD60 */
    dMessageWindow_c();

public:
    FILL(0x070, 0x254);

    /* 0x254 */ bool mReady;
    /* 0x255 */ bool mVisible;

    FILL(0x256, 0x260);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8078B290
     * executeState:    0x8078B2A0
     * finalizeState:   0x8078B2E0
     */
    sState_Extern(0x80992CC0, dMessageWindow_c, StartWait);

    /*
     * initializeState: 0x8078B2F0
     * executeState:    0x8078B4C0
     * finalizeState:   0x8078B520
     */
    sState_Extern(0x80992D00, dMessageWindow_c, StartAnimeEndWait);

    /*
     * initializeState: 0x8078B540
     * executeState:    0x8078B550
     * finalizeState:   0x8078B580
     */
    sState_Extern(0x80992D40, dMessageWindow_c, ExitWait);

    /*
     * initializeState: 0x8078B590
     * executeState:    0x8078B5E0
     * finalizeState:   0x8078B640
     */
    sState_Extern(0x80992D80, dMessageWindow_c, ExitAnimeEndWait);
};
