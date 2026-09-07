#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "d_lyttextbox.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include <nw4r/lyt/Window.h>

class dMiniGameWire_c : public dBase_c {
    // Original size: 0x384
    VTABLE(0x060, fBase_c, 0x80946F30);
    // 0x80946728 g_profile_MINI_GAME_WIRE
    // 0x8078DA20 dMiniGameWire_c_classInit

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

    /* 0x070 */ LytBase_c                           mLayout;
    /* 0x208 */ sStateMgrDefault_c<dMiniGameWire_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane*                    mpRootPane;

    /* 0x248 */ nw4r::lyt::Pane*                    mpNullPanes[40];
    /* 0x2E8 */ LytTextBox_c*                       mpTextBoxes[9];
    /* 0x30C */ nw4r::lyt::Picture*                 mpPicturePanes[15];
    /* 0x348 */ nw4r::lyt::Window*                  mpWindowPanes[2];

    /* 0x350 */ int                                 mCurrentTurn;

    FILL(0x354, 0x378);

    /* 0x378 */ bool mReady;

    FILL(0x379, 0x384);
    OFFSET_ASSERT(0x384);

    // New (added 0x20 bytes)
    /* 0x384 */ nw4r::lyt::Picture* mpExFaceIcon[8];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8078E380
     * executeState:    0x8078E3A0
     * finalizeState:   0x8078E3E0
     */
    sState_Extern(0x80993040, dMiniGameWire_c, TitleOpenWait);

    /*
     * initializeState: 0x8078E3F0
     * executeState:    0x8078E540
     * finalizeState:   0x8078E5A0
     */
    sState_Extern(0x80993080, dMiniGameWire_c, TitleOpenAnimeEndWait);

    /*
     * initializeState: 0x8078E5B0
     * executeState:    0x8078E5F0
     * finalizeState:   0x8078E620
     */
    sState_Extern(0x809930C0, dMiniGameWire_c, TitleDisp);

    /*
     * initializeState: 0x8078E630
     * executeState:    0x8078E670
     * finalizeState:   0x8078E6D0
     */
    sState_Extern(0x80993100, dMiniGameWire_c, TitleExitAnimeEndWait);

    /*
     * initializeState: 0x8078E700
     * executeState:    0x8078E710
     * finalizeState:   0x8078E770
     */
    sState_Extern(0x80993140, dMiniGameWire_c, StartWait);

    /*
     * initializeState: 0x8078E860
     * executeState:    0x8078EBA0
     * finalizeState:   0x8078EC50
     */
    sState_Extern(0x80993180, dMiniGameWire_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x8078EC60
     * executeState:    0x8078EC70
     * finalizeState:   0x8078ECA0
     */
    sState_Extern(0x809931C0, dMiniGameWire_c, NowDisp);

    /*
     * initializeState: 0x8078ECB0
     * executeState:    0x8078ED50
     * finalizeState:   0x8078EDB0
     */
    sState_Extern(0x80993200, dMiniGameWire_c, ResultDispAnimeEndWait);

    /*
     * initializeState: 0x8078EDF0
     * executeState:    0x8078EE60
     * finalizeState:   0x8078EE90
     */
    sState_Extern(0x80993240, dMiniGameWire_c, ResultNowDisp);

    /*
     * initializeState: 0x8078EEA0
     * executeState:    0x8078EEB0
     * finalizeState:   0x8078EEE0
     */
    sState_Extern(0x80993280, dMiniGameWire_c, BadResultNowDisp);

    /*
     * initializeState: 0x8078EEF0
     * executeState:    0x8078EFC0
     * finalizeState:   0x8078F020
     */
    sState_Extern(0x809932C0, dMiniGameWire_c, TurnOverOpenAnimeEndWait);

    /*
     * initializeState: 0x8078F030
     * executeState:    0x8078F070
     * finalizeState:   0x8078F0D0
     */
    sState_Extern(0x80993300, dMiniGameWire_c, TurnOverFaceOpenAnimeEndWait);

    /*
     * initializeState: 0x8078F0E0
     * executeState:    0x8078F120
     * finalizeState:   0x8078F1B0
     */
    sState_Extern(0x80993340, dMiniGameWire_c, TurnOverFaceDisp);

    /*
     * initializeState: 0x8078F1C0
     * executeState:    0x8078F1E0
     * finalizeState:   0x8078F200
     */
    sState_Extern(0x80993380, dMiniGameWire_c, FaceChengeWait);

    /*
     * initializeState: 0x8078F240
     * executeState:    0x8078F280
     * finalizeState:   0x8078F2E0
     */
    sState_Extern(0x809933C0, dMiniGameWire_c, TurnOverFaceExitAnimeEndWait);

    /*
     * initializeState: 0x8078F2F0
     * executeState:    0x8078F300
     * finalizeState:   0x8078F390
     */
    sState_Extern(0x80993400, dMiniGameWire_c, TurnOverExitAnimeEndWait);

    /*
     * initializeState: 0x8078F3A0
     * executeState:    0x8078F3E0
     * finalizeState:   0x8078F440
     */
    sState_Extern(0x80993440, dMiniGameWire_c, ExitAnimeEndWait);
};
