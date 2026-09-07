#pragma once

#include "d_base.h"
#include "s_State.h"

class dCourseClear_c : public dBase_c {
    SIZE_ASSERT(0x378);
    VTABLE(0x060, fBase_c, 0x80940F70);
    // 0x80940C40 g_profile_COURSE_CLEAR
    // 0x80779650 dCourseClear_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80779680 */
    dCourseClear_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x378);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80779E40
     * executeState:    0x80779E50
     * finalizeState:   0x80779E80
     */
    sState_Extern(0x80991480, dCourseClear_c, OnSatgeSetup);

    /*
     * initializeState: 0x80779E90
     * executeState:    0x80779EC0
     * finalizeState:   0x80779F20
     */
    sState_Extern(0x809914C0, dCourseClear_c, OnSatgeAnimeEndCheck);

    /*
     * initializeState: 0x80779F30
     * executeState:    0x80779F50
     * finalizeState:   0x80779F80
     */
    sState_Extern(0x80991500, dCourseClear_c, Disp);

    /*
     * initializeState: 0x80779F90
     * executeState:    0x80779FE0
     * finalizeState:   0x8077A050
     */
    sState_Extern(0x80991540, dCourseClear_c, ExitAnimeEndCheck);

    /*
     * initializeState: 0x8077A060
     * executeState:    0x8077A070
     * finalizeState:   0x8077A080
     */
    sState_Extern(0x80991580, dCourseClear_c, GoalDeMoEndWait);
};
