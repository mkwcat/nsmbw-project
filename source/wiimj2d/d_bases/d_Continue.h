#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include "state/s_FStateFct.h"
#include "state/s_StateInterfaces.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"
#include "state/s_State.h"

class dContinue_c : public dBase_c
{
    SIZE_ASSERT(0x2E4 + 0xF0);

public:
    // Structors
    // ^^^^^^

    /* 0x80777610 */
    dContinue_c();

    /* VT+0x8 0x80777810 */
    //virtual ~dContinue_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80157B70
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

public:
    // Constants and Types
    // ^^^^^^
    static constexpr std::size_t LytPlayerCount = 8;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807779D0 */
    bool createLayout();

    /* 0x80777C20 */
    int getPaneIdx(int playerID);

    /* 0x80777C50 */
    void setCardPosition();

    /* 0x80777DA0 */
    void setContinue();

    /* 0x80777E30 */
    void setRest();

    /* 0x80777EC0 */
    void setPlayerInfo();

    /* 0x80777FD0 */
    void EffectContinueInc(int playerID, int numLength);
public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ sStateMgr_c<dContinue_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane* mpRootPane;
    /* 0x248 */ nw4r::lyt::Picture* mpP_bg_PContinue; 

    /* 0x24C */ nw4r::lyt::Pane* REMOVED(mpNPos4P)[4];
    /* 0x25C */ nw4r::lyt::Pane* REMOVED(mpNPos3P)[3];
    /* 0x268 */ nw4r::lyt::Pane* REMOVED(mpNPos2P)[2];
    /* 0x270 */ nw4r::lyt::Pane* REMOVED(mpNPos1P);
    /* 0x274 */ nw4r::lyt::Pane* REMOVED(mpNDateFile)[4];
    /* 0x284 */ LytTextBox_c* REMOVED(mpTConTime)[4];
    /* 0x294 */ LytTextBox_c* REMOVED(mpTplyZanki)[4];

    /* 0x2A4 */ int mPlayCount;
    /* 0x2A8 */ int REMOVED(mContinue)[4];
    /* 0x2B8 */ int REMOVED(mRestNum)[4];
    /* 0x2C8 */ int mRestInc;

    /* 0x2CC */ int mDelay;
    /* 0x2D0 */ int mExitDelay;

    /* 0x2D4 */ bool mLayoutLoaded;
    /* 0x2D5 */ bool mVisible;
    /* 0x2D6 */ bool mIsOpen;
    /* 0x2D7 */ bool mDoExit;

    /* 0x2D8 */ bool REMOVED(mMustRevive)[4];

    FILL(0x2DC, 0x2E0);

    /* 0x2E0 */ bool mIsGameOver;

    FILL(0x2E1, 0x2E4);

    // New (added 0xF0 bytes)
    /* 0x2E4 */ nw4r::lyt::Pane* mpNPos4P[4];
    /* 0x2F4 */ nw4r::lyt::Pane* mpNPos3P[3];
    /* 0x300 */ nw4r::lyt::Pane* mpNPos2P[2];
    /* 0x308 */ nw4r::lyt::Pane* mpNPos1P;

    /* 0x30C */ nw4r::lyt::Pane* mpNPos4PEx[4];
    /* 0x31C */ nw4r::lyt::Pane* mpNPos5P;
    /* 0x320 */ nw4r::lyt::Pane* mpNPos6P;
    /* 0x324 */ nw4r::lyt::Pane* mpNPos7P;
    /* 0x328 */ nw4r::lyt::Pane* mpNPos8P;
    /* 0x32C */ nw4r::lyt::Pane* mpNDateFile[8];

    /* 0x34C */ LytTextBox_c* mpTConTime[8];
    /* 0x36C */ LytTextBox_c* mpTPlyZanki[8];

    /* 0x38C */ int mContinue[8];
    /* 0x3AC */ int mRestNum[8];
    /* 0x3CC */ bool mMustRevive[8];

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x809911C0, dContinue_c, StartWait);

    sState_Extern(0x80991200, dContinue_c, BlackInAnimeEndWait);

    sState_Extern(0x80991240, dContinue_c, OpenAnimeEndWait);

    sState_Extern(0x80991280, dContinue_c, ContinueCountUpWait);

    sState_Extern(0x809912C0, dContinue_c, ContinueCountUp);

    sState_Extern(0x80991300, dContinue_c, RestCountUpWait);

    sState_Extern(0x80991340, dContinue_c, RestCountUp);

    sState_Extern(0x80991380, dContinue_c, ColorRecover);

    sState_Extern(0x809913C0, dContinue_c, EndWait);

    sState_Extern(0x80991400, dContinue_c, ExitAnimeEndWait);

    sState_Extern(0x80991440, dContinue_c, BlackExitAnimeEndWait);
};
