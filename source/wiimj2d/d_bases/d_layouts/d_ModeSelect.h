#pragma once

#include "d_base.h"
#include "s_State.h"

class dModeSelect_c : public dBase_c {
    SIZE_ASSERT(0x274);
    VTABLE(0x060, fBase_c, 0x809477F8);
    // 0x80947630 g_profile_MODE_SELECT
    // 0x80790450 dModeSelect_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80790480 */
    dModeSelect_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x274);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80790AA0
     * executeState:    0x80790AF0
     * finalizeState:   0x80790B40
     */
    sState_Extern(0x80993480, dModeSelect_c, StartWait);

    /*
     * initializeState: 0x80790B50
     * executeState:    0x80790BB0
     * finalizeState:   0x80790C10
     */
    sState_Extern(0x809934C0, dModeSelect_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x80790C30
     * executeState:    0x80790CA0
     * finalizeState:   0x80790D00
     */
    sState_Extern(0x80993500, dModeSelect_c, ButtonChangeAnimeEndWait);

    /*
     * initializeState: 0x80790D10
     * executeState:    0x80790D30
     * finalizeState:   0x80790E30
     */
    sState_Extern(0x80993540, dModeSelect_c, SelectWait);

    /*
     * initializeState: 0x80790E40
     * executeState:    0x80790E60
     * finalizeState:   0x80790EC0
     */
    sState_Extern(0x80993580, dModeSelect_c, HitAnimeEndWait);

    /*
     * initializeState: 0x80790ED0
     * executeState:    0x80790EE0
     * finalizeState:   0x80790F50
     */
    sState_Extern(0x809935C0, dModeSelect_c, ExitAnimeEndWait);
};
