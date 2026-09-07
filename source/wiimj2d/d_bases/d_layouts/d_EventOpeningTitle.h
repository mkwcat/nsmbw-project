#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "d_lyttextbox.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"
#include <nw4r/lyt/Pane.h>

class dEventOpeningTitle_c : public dBase_c {
    SIZE_ASSERT(0x277);
    VTABLE(0x060, fBase_c, 0x809432C0);
    // 0x80943160 g_profile_EVENT_OPENING_TITLE
    // 0x80781980 dEventOpeningTitle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807819B0 */
    dEventOpeningTitle_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x80781C50 */
    PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80781D00 */
    bool createLayout();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c                                m_layout;
    /* 0x208 */ sStateMgrDefault_c<dEventOpeningTitle_c> m_stateMgr;
    /* 0x244 */ nw4r::lyt::Pane*                         m_rootPane;
    /* 0x248 */ LytTextBox_c*                            m_tE3VerCheck;
    /* 0x24C */ nw4r::lyt::Pane*                         m_nProportionC;

    FILL(0x250, 0x274);

    /* 0x274 */ bool m_created;
    /* 0x275 */ bool m_visible;
    /* 0x276 */ bool m_pressButton;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80782010
     * executeState:    0x80782020
     * finalizeState:   0x807820A0
     */
    sState_Extern(0x80991DF0, dEventOpeningTitle_c, WipeOutEndWait);

    /*
     * initializeState: 0x807820B0
     * executeState:    0x80782140
     * finalizeState:   0x807821A0
     */
    sState_Extern(0x80991E30, dEventOpeningTitle_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x807821B0
     * executeState:    0x807821C0
     * finalizeState:   0x80782220
     */
    sState_Extern(0x80991E70, dEventOpeningTitle_c, PressButtonDispWait);

    /*
     * initializeState: 0x80782230
     * executeState:    0x80782240
     * finalizeState:   0x807822C0
     */
    sState_Extern(0x80991EB0, dEventOpeningTitle_c, PressButtonExitWait);

    /*
     * initializeState: 0x807822D0
     * executeState:    0x80782340
     * finalizeState:   0x807823E0
     */
    sState_Extern(0x80991EF0, dEventOpeningTitle_c, PressButtonExitAnimeEndWait);
};
