#pragma once

#include "d_MultiCourseSelect.h"
#include "d_scene.h"
#include "s_FStateFct.h"
#include "s_State.h"
#include "s_StateMethodUsr_FI.h"
#include "s_StateMgr.h"

class dMultiCourseSelect_c;

class dScMulti_c : public dScene_c {
    SIZE_ASSERT(0x1DC);
    VTABLE(0x060, fBase_c, 0x8098B730);
    // 0x8098B660 g_profile_MULTI_PLAY_COURSE_SELECT
    // 0x8091A2F0 dScMulti_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8091A680 */
    dScMulti_c();

public:
    // Instance Methods
    // ^^^^^^

public:
    // Instance Variables
    // ^^^^^^

    /* 0x074 */ sStateMgr_c<dScMulti_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
        mStateMgr;

    FILL(0xB0, 0xBC);

    /* 0xBC */ dMultiCourseSelect_c* mpCourseSelect;

    FILL(0xC0, 0xD4);

    /* 0xD4 */ int m_D4;

    FILL(0xD8, 0x1DC);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8091AAA0
     * executeState:    0x8091AB70
     * finalizeState:   0x8091ABF0
     */
    sState_Extern(0x809A17A0, dScMulti_c, FadeInEndWait);

    /*
     * initializeState: 0x8091AC00
     * executeState:    0x8091AC10
     * finalizeState:   0x8091AD40
     */
    sState_Extern(0x809A17E0, dScMulti_c, SelectCourse);

    /*
     * initializeState: 0x8091AD50
     * executeState:    0x8091ADA0
     * finalizeState:   0x8091AF20
     */
    sState_Extern(0x809A1820, dScMulti_c, ReturnTitleFinalConfirm);

    /*
     * initializeState: 0x8091AF30
     * executeState:    0x8091AF40
     * finalizeState:   0x8091AFC0
     */
    sState_Extern(0x809A1860, dScMulti_c, ReturnTitleHitAnimrEndWait);
};
