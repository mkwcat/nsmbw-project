#pragma once

#include "d_player/d_death_message_mgr.h"
#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include "machine/m_ef.h"
#include "nw4r/math/mtx.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include <nw4r/lyt/TexMap.h>
#include <revolution/gx/GXStruct.h>

class dGameDisplay_c final : public dBase_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x80157850 */
    dGameDisplay_c();

    /* VT+0x08 0x80157AA0 */
    virtual ~dGameDisplay_c();

public:
    // Constants
    // ^^^^^^

    static constexpr int cMaxDispScore = 99999950;

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80157B70
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x80158230
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x801580D0
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

    /**
     * VT+0x2C 0x801581E0
     * do method for the draw operation.
     */
    PACK_RESULT_e draw() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80158830 */ bool createLayout();
    /* +++ */ void DecEffectTimers();
    /* 0x801586C0 */ void RestDispSetup();
    /* 0x801589D0 */ void RestCoinAnimeCheck();
    /* 0x80158A50 */ void AreaCheck();
    /* 0x80158BD0 */ void AlphaEnterAndExit();
    /* 0x80158D90 */ bool NormalSettle();
    /* 0x80158E40 */ bool OtasukeSettle();
    /* 0x801591F0 */ bool Effect1Up(int paneIndex);
    /* 0x80159390 */ void GrayColorSet(int player);
    /* 0x80159620 */ void ReturnGrayColorSet(int player);
    /* 0x80159770 */ void EffectCollectionCoinClear();
    /* 0x801598E0 */ void EffectCollectionCoinGet(int coin);
    /* 0x801599C0 */ void setPlayNum(int* playNum);
    /* +++ */ void updatePlayNum(int* playNum);
    /* 0x80159AA0 */ void setCoinNum(int coinNum);
    /* 0x80159C00 */ void setTime(int time);
    /* 0x80159C30 */ void setCollect();
    /* 0x80159DF0 */ void setScore(int score);
    /* 0x80159E60 */ void RestCoinAnimeSetup();

    void newDeathMessage(const wchar_t* message, PLAYER_TYPE_e player)
    {
        mDeathMsgMgr.newMessage(message, player);
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ mEf::levelEffect_c mEffect;

    // Moved
    /* 0x330 */ s16 REMOVED(mPlayerRGBA0)[4][4];
    /* 0x350 */ s16 REMOVED(mPlayerRGBA1)[4][4];
    /* 0x370 */ s16 REMOVED(mPlayerRGBA2)[4][4];

    /* 0x390 */ sStateMgrDefault_c<dGameDisplay_c> mStateMgr;

    // Moved
    /* 0x3CC */ int REMOVED(mPlayNum)[4];
    /* 0x3DC */ int mCoinNum;
    /* 0x3E0 */ int mTime;
    /* 0x3E4 */ int m0x3E4;
    /* 0x3E8 */ int mScore;
    /* 0x3EC */ int mCollectCoin[STAR_COIN_COUNT];
    /* 0x3F8 */ int m0x3F8;
    /* 0x3FC */ int m0x3FC;
    /* 0x400 */ int m0x400;
    /* 0x404 */ int m0x404;
    /* 0x408 */ int m0x408;
    /* 0x40C */ int mSettleTimePerFrame;
    /* 0x410 */ int mSettleScorePerSecond;
    /* 0x414 */ int m0x414;
    /* 0x418 */ int mAreaZankiAlpha;
    /* 0x41C */ int mAreaCoinAlpha;
    /* 0x420 */ int mAreaScoreAlpha;

    // Changed from int to s8
    /* 0x424 */ s8 mEffectTimer[16];

    /* 0x434 */ int mSetScoreDelay;
    /* 0x438 */ int m0x438;
    /* 0x43C */ int m0x43C;
    /* 0x440 */ int m0x440;
    /* 0x444 */ int m0x444;

    /* 0x448 */ bool m0x448;
    /* 0x449 */ bool m0x449;
    /* 0x44A */ bool m0x44A;
    /* 0x44B */ bool mLayoutLoaded;
    /* 0x44C */ bool m0x44C;
    /* 0x44D */ bool mAreaZankiCrossed;
    /* 0x44E */ bool mAreaCoinCrossed;
    /* 0x44F */ bool mAreaScoreCrossed;
    /* 0x450 */ bool mIsAlphaEnterOrExit;
    /* 0x451 */ bool m0x451;
    /* 0x452 */ bool m0x452;
    /* 0x453 */ bool m0x453;

    FILL(0x454, 0x458);

    /* 0x458 */ float mAreaZankiRectTop;
    /* 0x45C */ float mAreaZankiRectBottom;
    /* 0x460 */ float mAreaZankiRectLeft;
    /* 0x464 */ float mAreaZankiRectRight;
    /* 0x468 */ float mAreaCoinRectTop;
    /* 0x46C */ float mAreaCoinRectBottom;
    /* 0x470 */ float mAreaCoinRectLeft;
    /* 0x474 */ float mAreaCoinRectRight;
    /* 0x478 */ float mAreaScoreRectTop;
    /* 0x47C */ float mAreaScoreRectBottom;
    /* 0x480 */ float mAreaScoreRectLeft;
    /* 0x484 */ float mAreaScoreRectRight;

    FILL(0x488, 0x490);

    /* 0x490 */ nw4r::lyt::Pane* mpRootPane;

    //
    // Panes
    //

    union {
        struct {
            /* 0x494 */ nw4r::lyt::Picture* mpPicture_CollectOff00;
            /* 0x498 */ nw4r::lyt::Picture* mpPicture_Collection00;
            /* 0x49C */ nw4r::lyt::Picture* mpPicture_CollectOff01;
            /* 0x4A0 */ nw4r::lyt::Picture* mpPicture_Collection01;
            /* 0x4A4 */ nw4r::lyt::Picture* mpPicture_CollectOff02;
            /* 0x4A8 */ nw4r::lyt::Picture* mpPicture_Collection02;
            /* 0x4AC */ nw4r::lyt::Picture* mpPicture_MarioIcon;
            /* 0x4B0 */ nw4r::lyt::Picture* mpPicture_LuigiIcon;
            /* 0x4B4 */ nw4r::lyt::Picture* mpPicture_KinoBIcon;
            /* 0x4B8 */ nw4r::lyt::Picture* mpPicture_KinoYIcon;
        };

        /* 0x494 */ nw4r::lyt::Picture* mpaPictures[10];
    };

    union {
        struct {
            /* 0x4BC */ LytTextBox_c* mpTextBox_Left00;
            /* 0x4C0 */ LytTextBox_c* mpTextBox_X01;
            /* 0x4C4 */ LytTextBox_c* mpTextBox_Left01;
            /* 0x4C8 */ LytTextBox_c* mpTextBox_X02;
            /* 0x4CC */ LytTextBox_c* mpTextBox_Left02;
            /* 0x4D0 */ LytTextBox_c* mpTextBox_X03;
            /* 0x4D4 */ LytTextBox_c* mpTextBox_Left03;
            /* 0x4D8 */ LytTextBox_c* mpTextBox_X04;
            /* 0x4DC */ LytTextBox_c* mpTextBox_Coins;
            /* 0x4E0 */ LytTextBox_c* mpTextBox_Timer;
            /* 0x4E4 */ LytTextBox_c* mpTextBox_Score;
        };

        /* 0x4BC */ LytTextBox_c* mpaTextBoxes[11];
    };

    union {
        struct {
            /* 0x4E8 */ nw4r::lyt::Pane* mpPane_OtasukeInfo;
            /* 0x4EC */ nw4r::lyt::Pane* mpPane_OtasukeChu;
            /* 0x4F0 */ nw4r::lyt::Pane* mpPane_Left;
            /* 0x4F4 */ nw4r::lyt::Pane* mpPane_Coin;
            /* 0x4F8 */ nw4r::lyt::Pane* mpPane_Collection;
            /* 0x4FC */ nw4r::lyt::Pane* mpPane_Score;
            /* 0x500 */ nw4r::lyt::Pane* mpPane_AreaZanki;
            /* 0x504 */ nw4r::lyt::Pane* mpPane_AreaCoin;
            /* 0x508 */ nw4r::lyt::Pane* mpPane_AreaScore;
            /* 0x50C */ nw4r::lyt::Pane* mpPane_MarioIcon;
            /* 0x510 */ nw4r::lyt::Pane* mpPane_LuigiIcon;
            /* 0x514 */ nw4r::lyt::Pane* mpPane_KinoBIcon;
            /* 0x518 */ nw4r::lyt::Pane* mpPane_KinoYIcon;
            /* 0x51C */ nw4r::lyt::Pane* mpPane_Coin2;
            /* 0x520 */ nw4r::lyt::Pane* mpPane_Time;
            /* 0x524 */ nw4r::lyt::Pane* mpPane_ProportionL;
            /* 0x528 */ nw4r::lyt::Pane* mpPane_ProportionR;
            /* 0x52C */ nw4r::lyt::Pane* mpPane_Coin1st;
            /* 0x530 */ nw4r::lyt::Pane* mpPane_Coin2nd;
            /* 0x534 */ nw4r::lyt::Pane* mpPane_Coin3rd;
        };

        /* 0x4E8 */ nw4r::lyt::Pane* mpaPanes[20];
    };

    FILL(0x538, 0x5A4);
    OFFSET_ASSERT(0x5A4);

#define dGameDisplay_c_EXTRA_PLAYER_COUNT 4
    static constexpr u32 EXTRA_PLAYER_COUNT = dGameDisplay_c_EXTRA_PLAYER_COUNT;

#define OFFSET_dGameDisplay_c_mPlayerRGBA0 0x5A4
    GXColorS10 mPlayerRGBA[4 + EXTRA_PLAYER_COUNT];

#define OFFSET_dGameDisplay_c_mPlayerRGBA1 0x5A4 + (4 + dGameDisplay_c_EXTRA_PLAYER_COUNT) * 0x8
    GXColorS10 mPlayerRGBA2[4 + EXTRA_PLAYER_COUNT];

#define OFFSET_dGameDisplay_c_mPlayerRGBA2 0x5A4 + (4 + dGameDisplay_c_EXTRA_PLAYER_COUNT) * 0x10
    GXColorS10 mPlayerRGBA3[4 + EXTRA_PLAYER_COUNT];

    int mPlayNum[4 + EXTRA_PLAYER_COUNT];
    bool mPlayerGray[4 + EXTRA_PLAYER_COUNT];
    bool mPlayNumSet;

    union {
        struct {
            nw4r::lyt::Picture* mpPicture_KinopicoIcon;
            nw4r::lyt::Picture* mpPicture_Player05Icon;
            nw4r::lyt::Picture* mpPicture_Player06Icon;
            nw4r::lyt::Picture* mpPicture_Player07Icon;
        };

        nw4r::lyt::Picture* mpaExPictures[EXTRA_PLAYER_COUNT];
    };

    union {
        struct {
            LytTextBox_c* mpTextBox_Left04;
            LytTextBox_c* mpTextBox_X05;
            LytTextBox_c* mpTextBox_Left05;
            LytTextBox_c* mpTextBox_X06;
            LytTextBox_c* mpTextBox_Left06;
            LytTextBox_c* mpTextBox_X07;
            LytTextBox_c* mpTextBox_Left07;
            LytTextBox_c* mpTextBox_X08;
        };

        LytTextBox_c* mpaExTextBoxes[EXTRA_PLAYER_COUNT * 2];
    };

    union {
        struct {
            nw4r::lyt::Pane* mpPane_KinopicoIcon;
            nw4r::lyt::Pane* mpPane_Player05Icon;
            nw4r::lyt::Pane* mpPane_Player06Icon;
            nw4r::lyt::Pane* mpPane_Player07Icon;
        };

        nw4r::lyt::Pane* mpaExPanes[EXTRA_PLAYER_COUNT];
    };

    nw4r::lyt::TexMap mpaTexMap[4 + EXTRA_PLAYER_COUNT];
    nw4r::lyt::Size maIconSize[4 + EXTRA_PLAYER_COUNT];
    nw4r::math::VEC2 maIconScale[4 + EXTRA_PLAYER_COUNT];

    dDeathMsgMgr_c mDeathMsgMgr;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A608 */
    static dGameDisplay_c* m_instance;

    static const long cPlayerPaneIndex[];
    static const long cPlayerPictureIndex[];
    static const long cPlayerTextboxIndex[];
    static const long cPlayerBothTextboxIndex[][2];
    static const long cPictureCollectionIndex[];
    static const long cPictureCollectOffIndex[];

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80377378, dGameDisplay_c, ProcMainGame);

    sState_Extern(0x803773B8, dGameDisplay_c, ProcMainPause);

    sState_Extern(0x803773F8, dGameDisplay_c, ProcGoalSettleUp);

    sState_Extern(0x80377438, dGameDisplay_c, ProcGoalEnd);
};
