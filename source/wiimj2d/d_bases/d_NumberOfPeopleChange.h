#pragma once

#include "d_system/d_2d.h"
#include "d_system/d_base.h"
#include "d_system/d_info.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_remocon_mng.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"

class dCharacterChangeSelectBase_c;
class dCharacterChangeSelectContents_c;
class dCharacterChangeSelectArrow_c;
class dCharacterChangeIndicator_c;

class da2DPlayer_c;

class dNumberOfPeopleChange_c : public dBase_c {
public:
    // Structors
    // ^^^^^^

    /* 0x8079F660 */
    dNumberOfPeopleChange_c();

    /* VT+0x48 0x8079F8D0 */
    virtual ~dNumberOfPeopleChange_c() override;

public:
    // Constants
    // ^^^^^^

    static constexpr std::size_t MAX_CC_COUNT = 8;

    static_assert(MAX_CC_COUNT <= PLAYER_COUNT);

    enum Group_e {
        inWindow_Window                    = 0,
        inWindow_guide                     = 1,
        inYesNoButtons_yesButton           = 2,
        inYesNoButtons_noButton            = 3,
        inYesNoButtons_guideYes            = 4,
        inYesNoButtons_guideNo             = 5,
        onYesNoButtons_yesButton           = 6,
        onYesNoButtons_noButton            = 7,
        idleYesNoButtons_yesButton         = 8,
        idleYesNoButtons_noButton          = 9,
        hitYesNoButtons_yesButton          = 10,
        hitYesNoButtons_noButton           = 11,
        offYesNoButtons_yesButton          = 12,
        offYesNoButtons_noButton           = 13,
        outWindow_Window                   = 14,
        outWindow_guide                    = 15,
        outWindowInCourseSelectMenu_Window = 16,
        outWindowInCourseSelectMenu_guide  = 17,
    };

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x08 0x8079F990
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x8079FFD0
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x8079FEA0
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

    /**
     * VT+0x24 0x8079FE40
     * pre method for the execute operation.
     */
    PACK_RESULT_e preExecute() override;

    /**
     * VT+0x2C 0x8079FF90
     * do method for the draw operation.
     */
    PACK_RESULT_e draw() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8079FCD0 */
    bool createLayout();

    void setCcAnimFrame();

    /* 0x807A0170 */
    void setCcLytPosition();

    /* 0x807A0440 */
    void set2dPlyPosition();

    /* 0x807A07C0 */
    void disableInactiveControllers();

    /* 0x807A0870 */
    void checkRemoConnect();

    /* 0x807A09B0 */
    [[nodiscard]]
    int getBaseForPlayerCount(int playerCount, int player) const;

    /* 0x807A09D0 */
    void calcBasesForPlayerCount();

    void setPlayerSelectPos();

    /* 0x807A0BF0 */
    void setupPlayerTypes();

    /* 0x807A0D20 */
    [[nodiscard]]
    bool checkCancel();

    void setEasyPairingWait(bool enable);

    inline void setPlayer(
        PLAYER_TYPE_e type, da2DPlayer_c* player
    ) {
        mp2DPlayer[type] = player;
    }

    [[nodiscard]]
    inline nw4r::lyt::Picture* getControllerLight(
        std::size_t index
    ) const {
        if (index < 4) {
            return mpPRemoLight[index];
        } else if (index < 8) {
            return mpPDolphinLight[index - 4];
        } else {
            return nullptr;
        }
    }

private:
    // Private Instance Methods
    // ^^^^^^

    [[nodiscard]]
    std::size_t getCcFromPly(std::size_t ply) const;

    [[nodiscard]]
    inline bool isBottomIndex(
        std::size_t cc
    ) const {
        if (mPlayerCount <= 6) {
            return cc >= 3u;
        } else {
            return cc >= 4u;
        }
    }

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x809944C8, dNumberOfPeopleChange_c, InitialSetup);
    sState_Extern(0x80994508, dNumberOfPeopleChange_c, OnStageAnimeEndWait);
    sState_Extern(0x80994548, dNumberOfPeopleChange_c, InfoOnStageAnimeEndWait);
    sState_Extern(0x80994588, dNumberOfPeopleChange_c, NowEntrantRecruit);
    sState_Extern(0x809945C8, dNumberOfPeopleChange_c, StoryModeCourseSelectExitWait);
    sState_Extern(0x80994608, dNumberOfPeopleChange_c, InfoWindowExitWait);
    sState_Extern(0x80994648, dNumberOfPeopleChange_c, ButtonOnStageAnimeEndWait);
    sState_Extern(0x80994688, dNumberOfPeopleChange_c, ButtonChangeAnimeEndWait);
    sState_Extern(0x809946C8, dNumberOfPeopleChange_c, ButtonSelect);
    sState_Extern(0x80994708, dNumberOfPeopleChange_c, ButtonDecision);
    sState_Extern(0x80994748, dNumberOfPeopleChange_c, ExitAnimeEndCheck);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x074);

    /* 0x074 */ dCharacterChangeSelectBase_c*               REMOVED(mpCcSelBase)[4];
    /* 0x084 */ dCharacterChangeSelectContents_c*           REMOVED(mpCcSelContents)[4];
    /* 0x094 */ dCharacterChangeSelectArrow_c*              REMOVED(mpCcSelArrow)[4];
    /* 0x0A4 */ dCharacterChangeIndicator_c*                REMOVED(mpCcIndicator)[4];

    /* 0x0B4 */ d2d::ResAccMultLoader_c                     mBaseLytRes;
    /* 0x188 */ d2d::ResAccMultLoader_c                     mContentsLytRes;
    /* 0x25C */ d2d::ResAccMultLoader_c                     mArrowLytRes;
    /* 0x330 */ d2d::ResAccMultLoader_c                     mIndicatorLytRes;

    /* 0x404 */ LytBase_c                                   mLayout;
    /* 0x59C */ sStateMgrDefault_c<dNumberOfPeopleChange_c> mStateMgr = {
        *this, StateID_InitialSetup
    };

    /* 0x5D8 */ nw4r::lyt::Pane*    mpRootPane;

    /* 0x5DC */ nw4r::lyt::Pane*    mpNPlayerBasePos[10];

    /* 0x604 */ LytTextBox_c*       mpTTitleNinzuMenu;
    /* 0x608 */ LytTextBox_c*       mpTTitleNinzu;
    /* 0x60C */ LytTextBox_c*       mpTGuide;
    /* 0x610 */ LytTextBox_c*       mpTGuideS;

    /* 0x614 */ nw4r::lyt::Picture* mpPYesNoBase[2];
    /* 0x61C */ nw4r::lyt::Picture* mpPBgShadowST;
    /* 0x620 */ nw4r::lyt::Picture* mpPBgST;
    /* 0x624 */ nw4r::lyt::Picture* mpPStripeMLT;
    /* 0x628 */ nw4r::lyt::Picture* mpPRemoLight[4];
    /* 0x638 */ nw4r::lyt::Picture* mpPBase[2];
    /* 0x640 */ nw4r::lyt::Picture* mpPMenu43;

    /* 0x644 */ nw4r::lyt::Window*  mpWButton[2];

    /* 0x64C */ da2DPlayer_c*       REMOVED(mp2DPlayer)[4];

    FILL(0x65C, 0x67C);

    /* 0x67C */ bool                       mReady = false;
    /* 0x67D */ bool                       m0x67D;
    /* 0x67E */ bool                       m0x67E;
    /* 0x67F */ bool                       mEasyPairingWait;
    /* 0x680 */ bool                       mCancelAllowed;
    /* 0x681 */ bool                       mBaseLytResReady     = false;
    /* 0x682 */ bool                       mContentsLytResReady = false;
    /* 0x683 */ bool                       mArrowLytResReady    = false;
    /* 0x684 */ bool                       m0x684;
    /* 0x685 */ bool                       mIndicatorLytResReady = false;
    /* 0x686 */ bool                       m0x686;
    /* 0x687 */ bool                       mExiting;
    /* 0x688 */ bool                       mExitWithGuide;
    /* 0x689 */ bool                       mAllowControllerCut;

    /* 0x68C */ int                        m0x68C;
    /* 0x690 */ dInfo_c::PlyConnectStage_e REMOVED(mPlyConnectStage)[4];
    /* 0x6A0 */ int                        mEnterCount;
    /* 0x6A4 */ int                        REMOVED(mCcPlrBaseIndex)[4];
    /* 0x6B4 */ int                        REMOVED(mPlyPlrBaseIndex)[4];
    /* 0x6C4 */ int                        mPlayerCount;
    /* 0x6C8 */ int                        mOnButton;
    /* 0x6CC */ int                        mOffButton;
    /* 0x6D0 */ int                        REMOVED(mSetupPlayers)[4];
    /* 0x6E0 */ PLAYER_TYPE_e              REMOVED(mPlyDecidedPlayerType)[4];
    /* 0x6F0 */ PLAYER_TYPE_e              REMOVED(mCcDecidedPlayerType)[4];

    FILL(0x700, 0x710);
    OFFSET_ASSERT(0x710);

    int                                        mCcCount                      = MAX_CC_COUNT;

    dCharacterChangeSelectBase_c*              mpCcSelBase[MAX_CC_COUNT]     = {};
    dCharacterChangeSelectContents_c*          mpCcSelContents[MAX_CC_COUNT] = {};
    dCharacterChangeSelectArrow_c*             mpCcSelArrow[MAX_CC_COUNT]    = {};
    dCharacterChangeIndicator_c*               mpCcIndicator[MAX_CC_COUNT]   = {};

    cEnumArray_c<da2DPlayer_c*, PLAYER_TYPE_e> mp2DPlayer;

    int                                        mConnectPlrNo[REMOCON_CONNECT_COUNT];
    dInfo_c::PlyConnectStage_e                 mPlyConnectStage[PLAYER_COUNT];
    int                                        mCcPlrBaseIndex[MAX_CC_COUNT];
    int                                        mPlyPlrBaseIndex[PLAYER_COUNT];
    int                                        mSetupPlayers[MAX_CC_COUNT];

    PLAYER_TYPE_e                              mPlyDecidedPlayerType[MAX_CC_COUNT];
    PLAYER_TYPE_e                              mCcDecidedPlayerType[PLAYER_COUNT];

    nw4r::lyt::Picture*                        mpPDolphinLight[4];
};
