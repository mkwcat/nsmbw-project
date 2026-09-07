#pragma once

#include "d_base.h"
#include "s_State.h"

class dLetterWindow_c : public dBase_c {
    SIZE_ASSERT(0x258);
    VTABLE(0x060, fBase_c, 0x809456A8);
    // 0x80945560 g_profile_LETTER_WINDOW
    // 0x80789BB0 dLetterWindow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80789BE0 */
    dLetterWindow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x258);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8078A110
     * executeState:    0x8078A120
     * finalizeState:   0x8078A150
     */
    sState_Extern(0x80992B40, dLetterWindow_c, StartWait);

    /*
     * initializeState: 0x8078A160
     * executeState:    0x8078A250
     * finalizeState:   0x8078A2B0
     */
    sState_Extern(0x80992B80, dLetterWindow_c, StartAnimeEndWait);

    /*
     * initializeState: 0x8078A2C0
     * executeState:    0x8078A300
     * finalizeState:   0x8078A360
     */
    sState_Extern(0x80992BC0, dLetterWindow_c, ButtonOnStageAnimeEndWait);

    /*
     * initializeState: 0x8078A3A0
     * executeState:    0x8078A3B0
     * finalizeState:   0x8078A420
     */
    sState_Extern(0x80992C00, dLetterWindow_c, ButtonInputWait);

    /*
     * initializeState: 0x8078A430
     * executeState:    0x8078A490
     * finalizeState:   0x8078A4F0
     */
    sState_Extern(0x80992C40, dLetterWindow_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8078A500
     * executeState:    0x8078A540
     * finalizeState:   0x8078A5A0
     */
    sState_Extern(0x80992C80, dLetterWindow_c, ExitAnimeEndWait);
};
