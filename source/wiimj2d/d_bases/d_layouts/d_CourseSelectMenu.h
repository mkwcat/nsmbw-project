#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"
#include <nw4r/lyt/Picture.h>

class dCourseSelectMenu_c : public dBase_c {
    SIZE_ASSERT(0x278);
    VTABLE(0x060, fBase_c, 0x809415D8);
    // 0x809412C0 g_profile_COURSE_SELECT_MENU
    // 0x8077A750 dCourseSelectMenu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8077A780 */
    dCourseSelectMenu_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x8077AA10 */
    PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8077AB70 */
    bool createLayout();

public:
    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */
    sStateMgrDefault_c<dCourseSelectMenu_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane*            m_rootPane;
    /* 0x248 */ nw4r::lyt::Picture*         m_pSBBase[4];
    /* 0x258 */ nw4r::lyt::Picture*         m_pBack;
    /* 0x25C */ nw4r::lyt::Picture*         m_pBackWhite;
    /* 0x260 */ LytTextBox_c*               m_tCourseSelectS;
    /* 0x264 */ LytTextBox_c*               m_tCourseSelect;

    FILL(0x268, 0x270);

    /* 0x270 */ bool m_created;
    /* 0x271 */ bool m0x271;
    /* 0x272 */ bool m0x272;
    /* 0x273 */ bool m0x273;

    FILL(0x274, 0x278);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8077ADB0
     * executeState:    0x8077ADC0
     * finalizeState:   0x8077AE70
     */
    sState_Extern(0x809915D0, dCourseSelectMenu_c, InitWait);

    /*
     * initializeState: 0x8077AE80
     * executeState:    0x8077AE90
     * finalizeState:   0x8077AEF0
     */
    sState_Extern(0x80991610, dCourseSelectMenu_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x8077AF10
     * executeState:    0x8077AF90
     * finalizeState:   0x8077AFF0
     */
    sState_Extern(0x80991650, dCourseSelectMenu_c, ButtonChangeAnimeEndWait);

    /*
     * initializeState: 0x8077B000
     * executeState:    0x8077B010
     * finalizeState:   0x8077B190
     */
    sState_Extern(0x80991690, dCourseSelectMenu_c, PauseDisp);

    /*
     * initializeState: 0x8077B1A0
     * executeState:    0x8077B1C0
     * finalizeState:   0x8077B220
     */
    sState_Extern(0x809916D0, dCourseSelectMenu_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8077B230
     * executeState:    0x8077B290
     * finalizeState:   0x8077B300
     */
    sState_Extern(0x80991710, dCourseSelectMenu_c, ClouseAnimeEndWait);
};
