#pragma once

#include "d_base.h"
#include "s_State.h"

class dEasyPairing_c : public dBase_c {
    SIZE_ASSERT(0x2AC);
    VTABLE(0x060, fBase_c, 0x80942DC0);
    // 0x80942B38 g_profile_EASY_PAIRING
    // 0x807801F0 dEasyPairing_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80780220 */
    dEasyPairing_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x279);

    /* 0x279 */ u8 m0x279;

    FILL(0x27A, 0x2AC);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807809F0
     * executeState:    0x80780A00
     * finalizeState:   0x80780B80
     */
    sState_Extern(0x80991C30, dEasyPairing_c, DispWait);

    /*
     * initializeState: 0x80780BA0
     * executeState:    0x80780BB0
     * finalizeState:   0x80780C50
     */
    sState_Extern(0x80991C70, dEasyPairing_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x80780C60
     * executeState:    0x80780C70
     * finalizeState:   0x80780CD0
     */
    sState_Extern(0x80991CB0, dEasyPairing_c, StartWait);

    /*
     * initializeState: 0x80780CE0
     * executeState:    0x80780D00
     * finalizeState:   0x80780CF0
     */
    sState_Extern(0x80991CF0, dEasyPairing_c, keyWait);

    /*
     * initializeState: 0x80780F60
     * executeState:    0x80780F70
     * finalizeState:   0x80780FC0
     */
    sState_Extern(0x80991D30, dEasyPairing_c, StopStartWait);

    /*
     * initializeState: 0x80780FD0
     * executeState:    0x80780FE0
     * finalizeState:   0x80781040
     */
    sState_Extern(0x80991D70, dEasyPairing_c, StopEndWait);

    /*
     * initializeState: 0x80781050
     * executeState:    0x807810B0
     * finalizeState:   0x80781130
     */
    sState_Extern(0x80991DB0, dEasyPairing_c, ExitAnimeEndWait);
};
