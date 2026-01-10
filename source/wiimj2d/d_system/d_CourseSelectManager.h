#pragma once

#include "d_bases/d_Continue.h"
#include "d_bases/d_MessageWindow.h"
#include "d_system/d_CourseSelectGuide.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_base.h"
#include "d_system/d_mj2d_game.h"
#include "state/s_FStateFct.h"
#include "state/s_State.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"


class dCourseSelectMenu_c;
class dNumberOfPeopleChange_c;
class dStockItem_c;
class dStockItemShadow_c;
class dCollectionCoin_c;
class dWorldSelect_c;
class dWorldSelectGuide_c;
class da2DPlayer_c;
class dEasyPairing_c;
class dContinue_c;
class dYesNoWindow_c;
class dLetterWindow_c;

class dCourseSelectManager_c : public dBase_c
{
    // SIZE_ASSERT(0x570);

    /* 0x060 VTABLE 0x8098EFE8 */

public:
    // Structors
    // ^^^^^^

    /* 0x8092F050 */
    dCourseSelectManager_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x24 0x8092F3D0
     * pre method for the execute operation.
     */
    virtual PACK_RESULT_e preExecute() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x809311E0 */
    PLAYER_MODE_e getPlayerPowerup(int playerIndex);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */
    sStateMgr_c<dCourseSelectManager_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
      mStateMgr;

    /* 0x0AC */ dCourseSelectMenu_c* mpCrsSelectMenu; // COURSE_SELECT_MENU
    /* 0x0B0 */ dNumberOfPeopleChange_c* mpNumPyChg; // NUMBER_OF_PEOPLE_CHANGE
    /* 0x0B4 */ dStockItem_c* mpStockItem; // STOCK_ITEM
    /* 0x0B8 */ dStockItemShadow_c* mpStockItemSha; // STOCK_ITEM_SHADOW
    /* 0x0BC */ dCollectionCoin_c* mpCollectionCoin; // COLLECTION_COIN
    /* 0x0C0 */ dWorldSelect_c* mpWSelect; // WORLD_SELECT
    /* 0x0C4 */ dWorldSelectGuide_c* mpWSelectGuide; // WORLD_SELECT_GUIDE
    /* 0x0C8 */ dCourseSelectGuide_c mCrsSelectGuide;
    // Field removed and 16 bytes added to the end of dCourseSelectGuide_c
    /* 0x518 */ // da2DPlayer_c* REMOVED(mpa2DPlayer)[4];
    /* 0x528 */ dEasyPairing_c* mpEasyPairing; // EASY_PAIRING
    /* 0x52C */ dContinue_c* mpContinue; // CONTINUE
    /* 0x530 */ dYesNoWindow_c* mpYesNoWindow; // YES_NO_WINDOW
    /* 0x534 */ dMessageWindow_c* mpMessageWindow; // MESSAGE_WINDOW
    /* 0x538 */ dLetterWindow_c* mpLetterWindow; // LETTER_WINDOW

    FILL(0x53C, 0x541);

    /* 0x541 */ bool mContinueActive;

    FILL(0x542, 0x545);

    /* 0x545 */ bool mStartedMsgChange;
    /* 0x546 */ bool mEndedMsgChange;

    FILL(0x547, 0x560);

    /* 0x560 */ PLAYER_MODE_e REMOVED(maPlayerPowerup)[4];

    OFFSET_ASSERT(0x570);

#define OFFSET_dCourseSelectManager_c_mpa2DPlayer 0x570
    da2DPlayer_c* mpa2DPlayer[PLAYER_COUNT];

#define OFFSET_dCourseSelectManager_c_maPlayerPowerup                                              \
    (OFFSET_dCourseSelectManager_c_mpa2DPlayer + 0x4 * PLAYER_COUNT)
    PLAYER_MODE_e maPlayerPowerup[PLAYER_COUNT];

public:
    // Static Variables
    // ^^^^^^

    /* 0x809A2370 */ static dCourseSelectManager_c* m_instance;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8092F6E0
     * executeState:    0x8092F6F0
     * finalizeState:   0x8092F750
     */
    sState_Extern(0x809A2380, dCourseSelectManager_c, FadeEndWait);

    /*
     * initializeState: 0x8092F760
     * executeState:    0x8092F770
     * finalizeState:   0x8092F7F0
     */
    sState_Extern(0x809A23C0, dCourseSelectManager_c, ContinueCheck);

    /*
     * initializeState: 0x8092F800
     * executeState:    0x8092F830
     * finalizeState:   0x8092F910
     */
    sState_Extern(0x809A2400, dCourseSelectManager_c, ContinueEndWait);

    /*
     * initializeState: 0x8092F930
     * executeState:    0x8092F940
     * finalizeState:   0x8092FB80
     */
    sState_Extern(0x809A2440, dCourseSelectManager_c, KeyWait);

    /*
     * initializeState: 0x8092FB90
     * executeState:    0x8092FBA0
     * finalizeState:   0x8092FC10
     */
    sState_Extern(0x809A2480, dCourseSelectManager_c, MenuSelect);

    /*
     * initializeState: 0x8092FC20
     * executeState:    0x8092FC30
     * finalizeState:   0x8092FD80
     */
    sState_Extern(0x809A24C0, dCourseSelectManager_c, PushAnimeEndWait);

    /*
     * initializeState: 0x8092FD90
     * executeState:    0x8092FDF0
     * finalizeState:   0x8092FE90
     */
    sState_Extern(0x809A2500, dCourseSelectManager_c, StockItemSelectWait);

    /*
     * initializeState: 0x8092FED0
     * executeState:    0x8092FEE0
     * finalizeState:   0x8092FF00
     */
    sState_Extern(0x809A2540, dCourseSelectManager_c, CollectionCoinWait);

    /*
     * initializeState: 0x8092FF10
     * executeState:    0x8092FF20
     * finalizeState:   0x8092FFE0
     */
    sState_Extern(0x809A2580, dCourseSelectManager_c, CharacterChangeWait);

    /*
     * initializeState: 0x8092FFF0
     * executeState:    0x80930030
     * finalizeState:   0x80930060
     */
    sState_Extern(0x809A25C0, dCourseSelectManager_c, SaveWindowOpen);

    /*
     * initializeState: 0x80930070
     * executeState:    0x80930080
     * finalizeState:   0x809301D0
     */
    sState_Extern(0x809A2600, dCourseSelectManager_c, SaveButtonSelect);

    /*
     * initializeState: 0x809301E0
     * executeState:    0x809301F0
     * finalizeState:   0x80930260
     */
    sState_Extern(0x809A2640, dCourseSelectManager_c, SaveWindowClose);

    /*
     * initializeState: 0x80930270
     * executeState:    0x80930280
     * finalizeState:   0x80930310
     */
    sState_Extern(0x809A2680, dCourseSelectManager_c, NowSave);

    /*
     * initializeState: 0x80930320
     * executeState:    0x80930340
     * finalizeState:   0x809303E0
     */
    sState_Extern(0x809A26C0, dCourseSelectManager_c, SaveEndWindowOnStage);

    /*
     * initializeState: 0x809303F0
     * executeState:    0x80930400
     * finalizeState:   0x80930420
     */
    sState_Extern(0x809A2700, dCourseSelectManager_c, SaveEndAnimeWait);

    /*
     * initializeState: 0x80930430
     * executeState:    0x80930480
     * finalizeState:   0x809304B0
     */
    sState_Extern(0x809A2740, dCourseSelectManager_c, InterruptSaveWindowOpen);

    /*
     * initializeState: 0x809304C0
     * executeState:    0x809304D0
     * finalizeState:   0x80930620
     */
    sState_Extern(0x809A2780, dCourseSelectManager_c, InterruptSaveButtonSelect);

    /*
     * initializeState: 0x80930630
     * executeState:    0x80930640
     * finalizeState:   0x80930680
     */
    sState_Extern(0x809A27C0, dCourseSelectManager_c, InterruptSaveWindowClose);

    /*
     * initializeState: 0x80930690
     * executeState:    0x809306A0
     * finalizeState:   0x80930730
     */
    sState_Extern(0x809A2800, dCourseSelectManager_c, InterruptNowSave);

    /*
     * initializeState: 0x80930740
     * executeState:    0x80930760
     * finalizeState:   0x80930800
     */
    sState_Extern(0x809A2840, dCourseSelectManager_c, InterruptSaveEndWindowOnStage);

    /*
     * initializeState: 0x80930810
     * executeState:    0x80930830
     * finalizeState:   0x80930860
     */
    sState_Extern(0x809A2880, dCourseSelectManager_c, InterruptSaveEndAnimeWait);

    /*
     * initializeState: 0x80930870
     * executeState:    0x809308E0
     * finalizeState:   0x80930950
     */
    sState_Extern(0x809A28C0, dCourseSelectManager_c, WorldSelect);

    /*
     * initializeState: 0x80930960
     * executeState:    0x809309E0
     * finalizeState:   0x80930A10
     */
    sState_Extern(0x809A2900, dCourseSelectManager_c, EasyPairingWait);

    /*
     * initializeState: 0x80930A80
     * executeState:    0x80930AB0
     * finalizeState:   0x80930B40
     */
    sState_Extern(0x809A2940, dCourseSelectManager_c, SaveError);

    /*
     * initializeState: 0x80930B50
     * executeState:    0x80930B70
     * finalizeState:   0x80930BA0
     */
    sState_Extern(0x809A2980, dCourseSelectManager_c, TitleConfirmationWindowOpen);

    /*
     * initializeState: 0x80930BB0
     * executeState:    0x80930BC0
     * finalizeState:   0x80930CF0
     */
    sState_Extern(0x809A29C0, dCourseSelectManager_c, TitleConfirmationButtonSelect);

    /*
     * initializeState: 0x80930D00
     * executeState:    0x80930D10
     * finalizeState:   0x80930D50
     */
    sState_Extern(0x809A2A00, dCourseSelectManager_c, TitleConfirmationHitAnimeEndWait);

    /*
     * initializeState: 0x80930D60
     * executeState:    0x80930D70
     * finalizeState:   0x80930D80
     */
    sState_Extern(0x809A2A40, dCourseSelectManager_c, TitleSceneChangeWait);

    /*
     * initializeState: 0x80930D90
     * executeState:    0x80930DC0
     * finalizeState:   0x80930DF0
     */
    sState_Extern(0x809A2A80, dCourseSelectManager_c, MsgOpenAnimeEndWait);

    /*
     * initializeState: 0x80930E00
     * executeState:    0x80930E10
     * finalizeState:   0x80930E40
     */
    sState_Extern(0x809A2AC0, dCourseSelectManager_c, MsgDispEndWait);

    /*
     * initializeState: 0x80930E50
     * executeState:    0x80930E70
     * finalizeState:   0x80930EA0
     */
    sState_Extern(0x809A2B00, dCourseSelectManager_c, MsgExitAnimeEndWait);

    /*
     * initializeState: 0x80930EB0
     * executeState:    0x80930ED0
     * finalizeState:   0x80930F00
     */
    sState_Extern(0x809A2B40, dCourseSelectManager_c, YesNoWindowOpenAnimeEndWait);

    /*
     * initializeState: 0x80930F10
     * executeState:    0x80930F20
     * finalizeState:   0x80930F90
     */
    sState_Extern(0x809A2B80, dCourseSelectManager_c, YesNoWindowDispEndWait);

    /*
     * initializeState: 0x80930FA0
     * executeState:    0x80930FB0
     * finalizeState:   0x80930FE0
     */
    sState_Extern(0x809A2BC0, dCourseSelectManager_c, YesNoWindowExitAnimeEndWait);

    /*
     * initializeState: 0x80930FF0
     * executeState:    0x80931010
     * finalizeState:   0x80931040
     */
    sState_Extern(0x809A2C00, dCourseSelectManager_c, LetterWindowWait);
};
