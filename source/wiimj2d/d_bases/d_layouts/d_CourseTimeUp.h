#pragma once

#include "d_base.h"
#include "s_State.h"

class dCourseTimeUp_c : public dBase_c {
    SIZE_ASSERT(0x388);
    VTABLE(0x060, fBase_c, 0x80941A50);
    // 0x80941960 g_profile_COURSE_TIME_UP
    // 0x8077BB00 dCourseTimeUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8077BB30 */
    dCourseTimeUp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x388);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8077C1C0
     * executeState:    0x8077C1D0
     * finalizeState:   0x8077C270
     */
    sState_Extern(0x80991750, dCourseTimeUp_c, DispWait);

    /*
     * initializeState: 0x8077C280
     * executeState:    0x8077C2E0
     * finalizeState:   0x8077C340
     */
    sState_Extern(0x80991790, dCourseTimeUp_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x8077C350
     * executeState:    0x8077C390
     * finalizeState:   0x8077C3D0
     */
    sState_Extern(0x809917D0, dCourseTimeUp_c, DispEndWait);

    /*
     * initializeState: 0x8077C3E0
     * executeState:    0x8077C430
     * finalizeState:   0x8077C4B0
     */
    sState_Extern(0x80991810, dCourseTimeUp_c, ExitAnimeEndWait);
};
