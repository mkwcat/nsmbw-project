#pragma once

#include "d_static/d_base.h"
#include "d_static/d_lyt/d_lytbase.h"
#include "nw4r/lyt/Picture.h"
#include "state/s_FStateFct.h"
#include "state/s_State.h"
#include "state/s_StateInterfaces.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"

class dSelectPlayer_c : public dBase_c
{
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

    /* 0xAC */ LytBase_c mLayout;
    /* 0x244 */ nw4r::lyt::Picture* REMOVED(mpaButtons)[4 + 3];
    /* 0x260 */ nw4r::lyt::Pane* mpaRootPanes[2];
    /* 0x268 */ bool mLayoutLoaded;
    /* 0x269 */ u8 m0x269;
    /* 0x26A */ u8 m0x26A;
    /* 0x26B */ u8 m0x26B;
    /* 0x26C */ s32 mCurrentButton;
    /* 0x270 */ s32 mActDirection;
    /* 0x274 */ s32 mButtonAnimeOn;
    /* 0x278 */ s32 mButtonAnimeOff;
    /* 0x27C */ s32 mSecondRowButton;

    OFFSET_ASSERT(0x280);

    /* 0x280 */ nw4r::lyt::Picture* mpaButtons[8 + 3];

    bool mMultiMode;

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x809953A0, dSelectPlayer_c, StartWait);
    sState_Extern(0x809953E0, dSelectPlayer_c, OnStageAnimeEndWait);
    sState_Extern(0x80995420, dSelectPlayer_c, InfoOnStageAnimeEndWait);
    sState_Extern(0x80995460, dSelectPlayer_c, ButtonChangeAnimeEndWait);
    sState_Extern(0x809954A0, dSelectPlayer_c, StartMemberSelect);
    sState_Extern(0x809954E0, dSelectPlayer_c, MultiStartMemberSelect);
    sState_Extern(0x80995520, dSelectPlayer_c, StartMemberButtonAnime);
    sState_Extern(0x80995560, dSelectPlayer_c, ExitAnimeEndWait);
};
