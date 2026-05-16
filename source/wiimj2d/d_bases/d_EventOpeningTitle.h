#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include "nw4r/lyt/Pane.h"
#include "state/s_StateMgrDefault.h"

class dEventOpeningTitle_c : public dBase_c {
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
    // State ID Methods
    // ^^^^^^

    /* 0x80782340 */
    void executeState_PressButtonExitAnimeEndWait();

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
};
