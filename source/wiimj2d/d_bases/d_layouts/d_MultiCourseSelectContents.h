#pragma once

#include "d_base.h"
#include "s_State.h"

class dMultiCourseSelectContents_c : public dBase_c {
    SIZE_ASSERT(0x2B4);
    VTABLE(0x060, fBase_c, 0x8094ACD0);
    // 0x8094A378 g_profile_MULTI_COURSE_SELECT_CONTENTS
    // 0x8079D540 dMultiCourseSelectContents_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8079D570 */
    dMultiCourseSelectContents_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x2B4);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8079E5C0
     * executeState:    0x8079E610
     * finalizeState:   0x8079E640
     */
    sState_Extern(0x80994308, dMultiCourseSelectContents_c, DispWait);

    /*
     * initializeState: 0x8079E650
     * executeState:    0x8079E660
     * finalizeState:   0x8079E720
     */
    sState_Extern(0x80994348, dMultiCourseSelectContents_c, ActionWait);

    /*
     * initializeState: 0x8079E760
     * executeState:    0x8079E7B0
     * finalizeState:   0x8079E810
     */
    sState_Extern(0x80994388, dMultiCourseSelectContents_c, OnAnimeEndWait);

    /*
     * initializeState: 0x8079E860
     * executeState:    0x8079E8A0
     * finalizeState:   0x8079E900
     */
    sState_Extern(0x809943C8, dMultiCourseSelectContents_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8079E910
     * executeState:    0x8079E920
     * finalizeState:   0x8079E980
     */
    sState_Extern(0x80994408, dMultiCourseSelectContents_c, PauseAnimeEndWait);

    /*
     * initializeState: 0x8079E9E0
     * executeState:    0x8079EA20
     * finalizeState:   0x8079EA80
     */
    sState_Extern(0x80994448, dMultiCourseSelectContents_c, OffAnimeEndWait);

    /*
     * initializeState: 0x8079EA90
     * executeState:    0x8079EBA0
     * finalizeState:   0x8079EC30
     */
    sState_Extern(0x80994488, dMultiCourseSelectContents_c, ClearAnimeEndWait);
};
