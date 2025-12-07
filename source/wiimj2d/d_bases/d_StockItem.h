#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_mj2d_game.h"
#include "nw4r/lyt/Pane.h"
#include "nw4r/lyt/Picture.h"
#include "state/s_FStateFct.h"
#include "state/s_State.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"

class da2DPlayer_c;
class daWmItem_c;
class dStockItemShadow_c;

class dStockItem_c : public dBase_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x807AF3A0 */
    dStockItem_c();

public:
    // Constants and Types
    // ^^^^^^

    enum class PANE_LIST_e {
        FIRST = 0,

        P_iconBase_00 = 8,
        P_iconBase_01 = 9,
        P_iconBase_02 = 10,
        P_iconBase_03 = 11,

        P_iconBase_04 = 12,
        P_iconBase_05 = 13,
        P_iconBase_06 = 14,

        P_iconBase_07 = 15,
        P_iconBase_08 = 16,

        P_iconBase_09 = 17,

        P_iconBase_10 = 18,
        P_iconBase_11 = 19,
        P_iconBase_12 = 20,
        P_iconBase_13 = 21,
        P_iconBase_14 = 22,

        P_iconBase_15 = 23,
        P_iconBase_16 = 24,
        P_iconBase_17 = 25,
        P_iconBase_18 = 26,
        P_iconBase_19 = 27,
        P_iconBase_20 = 28,

        P_iconBase_21 = 29,
        P_iconBase_22 = 30,
        P_iconBase_23 = 31,
        P_iconBase_24 = 32,
        P_iconBase_25 = 33,
        P_iconBase_26 = 34,
        P_iconBase_27 = 35,

        P_iconBase_28 = 36,
        P_iconBase_29 = 37,
        P_iconBase_30 = 38,
        P_iconBase_31 = 39,
        P_iconBase_32 = 40,
        P_iconBase_33 = 41,
        P_iconBase_34 = 42,
        P_iconBase_35 = 43,

        NONE = 44,
    };

#define PANE_LIST_e_NONE 44

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807AF8D0 */
    bool createLayout();

    /* 0x807AFB90 */
    PANE_LIST_e getPosPaneForPlayer(int player);

    /* 0x807AFBC0 */
    void calcPosScale();

    /* 0x807B00A0 */
    void calc2DPlayerItemUpdate();

    /* 0x807B03A0 */
    void calcUseEffects();

    /* 0x807B06C0 */
    bool checkItemSelect();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x074);

    /* 0x074 */ LytBase_c mLayout;
    /* 0x20C */
    sStateMgr_c<dStockItem_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    /* 0x248 */ nw4r::lyt::Pane* mpRootPane;
    /* 0x24C */ nw4r::lyt::Pane* mpNullPanes[14];
    /* 0x284 */ nw4r::lyt::Picture* mpPicturePanes[24];

    /* 0x2E4 */ da2DPlayer_c* REMOVED(mpa2DPlayer)[4];
    /* 0x2F4 */ daWmItem_c* mpaItem[7];
    /* 0x310 */ dStockItemShadow_c* mpShadow;

    FILL(0x314, 0x8B0);

    /* 0x8B0 */ int mPresentPlayerCount;
    /* 0x8B4 */ int mItemCount[7];

    FILL(0x8D0, 0x8D8);

    /* 0x8D8 */ bool REMOVED(maPlayerPresent)[4];

    FILL(0x8DC, 0x8DD);

    /* 0x8DD */ u8 m0x8DD;

    FILL(0x8DE, 0x8E0);
    OFFSET_ASSERT(0x8E0);

#define dStockItem_c_OFFSET_mpa2DPlayer 0x8E0
    /* 0x8E0 */ da2DPlayer_c* mpa2DPlayer[PLAYER_COUNT];

#define dStockItem_c_OFFSET_maPlayerPresent (dStockItem_c_OFFSET_mpa2DPlayer + PLAYER_COUNT * 4)
    /* 0x900 */ u8 maPlayerPresent[PLAYER_COUNT];

#define dStockItem_c_OFFSET_mpNForUsePos (dStockItem_c_OFFSET_maPlayerPresent + PLAYER_COUNT)
    /* 0x908 */ nw4r::lyt::Pane* mpNForUsePos[PLAYER_COUNT];
    /* 0x928 */ nw4r::lyt::Picture* mpPIconBase4P[4];
    /* 0x938 */ nw4r::lyt::Picture* mpPIconBase3P[3];
    /* 0x944 */ nw4r::lyt::Picture* mpPIconBase2P[2];
    /* 0x94C */ nw4r::lyt::Picture* mpPIconBase1P;

    /* 0x950 */ nw4r::lyt::Picture* mpPIconBase5P[5];
    /* 0x964 */ nw4r::lyt::Picture* mpPIconBase6P[6];
    /* 0x97C */ nw4r::lyt::Picture* mpPIconBase7P[7];
    /* 0x998 */ nw4r::lyt::Picture* mpPIconBase8P[8];

public:
    // State IDs
    // ^^^^^^

    /*
     * executeState: 0x807B09D0
     */
    sState_Extern(0x809957E8, dStockItem_c, WindowOpenInit);

    sState_Extern(0x80995828, dStockItem_c, WindowOpenAnimeEndWait);

    sState_Extern(0x80995868, dStockItem_c, ButtonChangeAnimeEndWait);

    sState_Extern(0x809958A8, dStockItem_c, ItemSelectWait);

    sState_Extern(0x809958E8, dStockItem_c, SuccessionItemSelectWait);

    sState_Extern(0x80995928, dStockItem_c, WindowCloseAnimeEndWait);

    sState_Extern(0x80995968, dStockItem_c, HitAnimeEndWait);

    sState_Extern(0x809959A8, dStockItem_c, WindowCloseInit);
};
