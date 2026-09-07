#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "s_FStateFct.h"
#include "s_State.h"
#include "s_StateInterfaces.h"
#include "s_StateMethodUsr_FI.h"
#include "s_StateMgr.h"
#include <nw4r/lyt/Picture.h>

class dSelectPlayer_c : public dBase_c {
    // Original size: 0x280
    VTABLE(0x060, fBase_c, 0x8094E818);
    // 0x8094E418 g_profile_SELECT_PLAYER
    // 0x807ABE10 dSelectPlayer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807ABE40 */
    dSelectPlayer_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807AC170 */
    PACK_RESULT_e createLayout();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */
    sStateMgr_c<dSelectPlayer_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    /* 0xAC */ LytBase_c                                                            mLayout;
    /* 0x244 */ nw4r::lyt::Picture* REMOVED(mpaButtons)[4 + 3];
    /* 0x260 */ nw4r::lyt::Pane*    mpaRootPanes[2];
    /* 0x268 */ bool                mLayoutLoaded;
    /* 0x269 */ u8                  m0x269;
    /* 0x26A */ u8                  m0x26A;
    /* 0x26B */ u8                  m0x26B;
    /* 0x26C */ s32                 mCurrentButton;
    /* 0x270 */ s32                 mActDirection;
    /* 0x274 */ s32                 mButtonAnimeOn;
    /* 0x278 */ s32                 mButtonAnimeOff;
    /* 0x27C */ s32                 mSecondRowButton;

    OFFSET_ASSERT(0x280);

    // Instance Variables
    // ++++++

    /* 0x280 */ nw4r::lyt::Picture* mpaButtons[8 + 3];

    bool                            mMultiMode;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807AC3C0
     * executeState:    0x807AC3D0
     * finalizeState:   0x807AC490
     */
    sState_Extern(0x809953A0, dSelectPlayer_c, StartWait);

    /*
     * initializeState: 0x807AC4A0
     * executeState:    0x807AC510
     * finalizeState:   0x807AC570
     */
    sState_Extern(0x809953E0, dSelectPlayer_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x807AC580
     * executeState:    0x807AC590
     * finalizeState:   0x807AC5F0
     */
    sState_Extern(0x80995420, dSelectPlayer_c, InfoOnStageAnimeEndWait);

    /*
     * initializeState: 0x807AC610
     * executeState:    0x807AC6E0
     * finalizeState:   0x807AC770
     */
    sState_Extern(0x80995460, dSelectPlayer_c, ButtonChangeAnimeEndWait);

    /*
     * initializeState: 0x807AC780
     * executeState:    0x807AC7A0
     * finalizeState:   0x807AC950
     */
    sState_Extern(0x809954A0, dSelectPlayer_c, StartMemberSelect);

    /*
     * initializeState: 0x807AC960
     * executeState:    0x807AC980
     * finalizeState:   0x807ACAC0
     */
    sState_Extern(0x809954E0, dSelectPlayer_c, MultiStartMemberSelect);

    /*
     * initializeState: 0x807ACAD0
     * executeState:    0x807ACB60
     * finalizeState:   0x807ACBC0
     */
    sState_Extern(0x80995520, dSelectPlayer_c, StartMemberButtonAnime);

    /*
     * initializeState: 0x807ACBD0
     * executeState:    0x807ACC40
     * finalizeState:   0x807ACCD0
     */
    sState_Extern(0x80995560, dSelectPlayer_c, ExitAnimeEndWait);
};
