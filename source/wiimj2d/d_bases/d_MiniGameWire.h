#pragma once

#include "System.h"
#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include "nw4r/lyt/Window.h"
#include "state/s_FStateFct.h"
#include "state/s_StateInterfaces.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"

class dMiniGameWire_c : public dBase_c
{
    SIZE_ASSERT(0x384 + 0x20);

public:
    // Structors
    // ^^^^^^

    /* 0x8078DE20 */
    dMiniGameWire_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8078DE20 */
    bool createLayout();

    /* 0x8078E2B0 */
    void setTurnFaceIcon();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ sStateMgr_c<dMiniGameWire_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane* mpRootPane;

    /* 0x248 */ nw4r::lyt::Pane* mpNullPanes[40];
    /* 0x2E8 */ LytTextBox_c* mpTextBoxes[9];
    /* 0x30C */ nw4r::lyt::Picture* mpPicturePanes[15];
    /* 0x348 */ nw4r::lyt::Window* mpWindowPanes[2];

    /* 0x350 */ int mCurrentTurn;

    FILL(0x354, 0x378);

    /* 0x378 */ bool mReady;

    FILL(0x379, 0x384);

    // New (added 0x20 bytes)
    /* 0x384 */ nw4r::lyt::Picture* mpExFaceIcon[8];
};
