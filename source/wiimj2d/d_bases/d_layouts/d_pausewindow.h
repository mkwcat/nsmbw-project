#pragma once

#include "d_base.h"
#include "s_State.h"

class Pausewindow_c : public dBase_c {
    SIZE_ASSERT(0x298);
    VTABLE(0x060, fBase_c, 0x80328078);
    // 0x80327D24 g_profile_PAUSEWINDOW
    // 0x8015A480 Pausewindow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8015A4B0 */
    Pausewindow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x298);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8015ADA0
     * executeState:    0x8015ADB0
     * finalizeState:   0x8015AEB0
     */
    sState_Extern(0x80377480, Pausewindow_c, InitWait);

    /*
     * initializeState: 0x8015AEC0
     * executeState:    0x8015AF30
     * finalizeState:   0x8015AF90
     */
    sState_Extern(0x803774C0, Pausewindow_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x8015AFB0
     * executeState:    0x8015B020
     * finalizeState:   0x8015B080
     */
    sState_Extern(0x80377500, Pausewindow_c, ButtonChangeAnimeEndWait);

    /*
     * initializeState: 0x8015B090
     * executeState:    0x8015B0A0
     * finalizeState:   0x8015B160
     */
    sState_Extern(0x80377540, Pausewindow_c, PauseDisp);

    /*
     * initializeState: 0x8015B170
     * executeState:    0x8015B190
     * finalizeState:   0x8015B1F0
     */
    sState_Extern(0x80377580, Pausewindow_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8015B200
     * executeState:    0x8015B220
     * finalizeState:   0x8015B280
     */
    sState_Extern(0x803775C0, Pausewindow_c, ClouseAnimeEndWait);
};
