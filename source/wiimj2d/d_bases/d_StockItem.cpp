// d_StockItem.cpp
// NSMBW d_bases.text: 0x807AF370 - 0x807B2030

#include "d_StockItem.h"

#include "d_bases/d_StockItemShadow.h"
#include "d_bases/d_a_wm_2DPlayer.h"
#include "d_bases/d_a_wm_Item.h"
#include "d_bases/d_wm_seManager.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_audio.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include "sound/SndSceneMgr.h"
#include <iterator>

[[address(0x807AF370)]]
dStockItem_c* dStockItem_c_classInit()
{
    return new dStockItem_c();
}

[[address(0x807AF3A0)]]
dStockItem_c::dStockItem_c();

[[address(0x807AF8D0)]]
bool dStockItem_c::createLayout() {
    if (!mLayout.ReadResource("stockItem/stockItem.arc", false)) {
      return false;
    }

    mLayout.build("stockItem_27.brlyt", nullptr);

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.AnimeResRegister(
      StringArray{
        "stockItem_27_inWindow.brlan",
        "stockItem_27_itemOnButton.brlan",
        "stockItem_27_itemIdleButton.brlan",
        "stockItem_27_itemHitButton.brlan",
        "stockItem_27_itemOffButton.brlan",
        "stockItem_27_outWindow.brlan",
      },
      6
    );

    mLayout.GroupRegister(
      StringArray{
        "A00_Window",
        "B00_itemButton", "B01_itemButton", "B02_itemButton", "B06_itemButton", "B04_itemButton", "B05_itemButton", "B03_itemButton",
        "B00_itemButton", "B01_itemButton", "B02_itemButton", "B06_itemButton", "B04_itemButton", "B05_itemButton", "B03_itemButton",
        "B00_itemButton", "B01_itemButton", "B02_itemButton", "B06_itemButton", "B04_itemButton", "B05_itemButton", "B03_itemButton",
        "B00_itemButton", "B01_itemButton", "B02_itemButton", "B06_itemButton", "B04_itemButton", "B05_itemButton", "B03_itemButton",
        "A00_Window",
      },
      IntArray{
        0,
        1, 1, 1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3,
        4, 4, 4, 4, 4, 4, 4,
        5,
      },
      0x1E
    );

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
      mpNullPanes,
      {
        "N_forUse_1PPos",
        "N_forUse_2PPos",
        "N_forUse_3PPos",
        "N_forUse_4PPos",
        "N_iconKinoko_00",
        "N_iconFlower_00",
        "N_iconPro_00",
        "N_iconIce_00",
        "N_iconPen_00",
        "N_mameKinoko_00",
        "N_iconStar_00",
        "N_stockItem",
        "N_stockItem_01",
        "N_itemSelect_00",
      }
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_titleStock_00",
        "T_titleUse_01",
      },
      IntArray{
        0x1E,
        0x2F,
      },
      0x2, 2
    );

    mLayout.PPaneRegister(
      mpPicturePanes,
      {
        "P_iconKinoko_00",
        "P_iconFlower_00",
        "P_iconPro_00",
        "P_iconIce_00",
        "P_iconPen_00",
        "P_mameKinoko_00",
        "P_iconStar_00",
        "P_buttonBase_00",
        "P_buttonBase_01",
        "P_buttonBase_02",
        "P_buttonBase_06",
        "P_buttonBase_04",
        "P_buttonBase_05",
        "P_buttonBase_03",
        "P_iconBase_00",
        "P_iconBase_01",
        "P_iconBase_02",
        "P_iconBase_03",
        "P_iconBase_04",
        "P_iconBase_05",
        "P_iconBase_06",
        "P_iconBase_07",
        "P_iconBase_08",
        "P_iconBase_09",
      }
    );

    // New
    mLayout.NPaneRegister(
      mpNForUsePos,
      {
        "N_forUse_1PPos",
        "N_forUse_2PPos",
        "N_forUse_3PPos",
        "N_forUse_4PPos",
        "N_forUse_5PPos",
        "N_forUse_5PPos",
        "N_forUse_5PPos",
        "N_forUse_5PPos",
      }
    );

    mLayout.PPaneRegister(
      mpPIconBase4P,
      {
        "P_iconBase_00",
        "P_iconBase_01",
        "P_iconBase_02",
        "P_iconBase_03",

        "P_iconBase_04",
        "P_iconBase_05",

        "P_iconBase_06",
        "P_iconBase_07",
        "P_iconBase_08",

        "P_iconBase_09",

        "P_iconBase_10",
        "P_iconBase_11",
        "P_iconBase_12",
        "P_iconBase_13",
        "P_iconBase_14",

        "P_iconBase_15",
        "P_iconBase_16",
        "P_iconBase_17",
        "P_iconBase_18",
        "P_iconBase_19",
        "P_iconBase_20",

        "P_iconBase_21",
        "P_iconBase_22",
        "P_iconBase_23",
        "P_iconBase_24",
        "P_iconBase_25",
        "P_iconBase_26",
        "P_iconBase_27",

        "P_iconBase_28",
        "P_iconBase_29",
        "P_iconBase_30",
        "P_iconBase_31",
        "P_iconBase_32",
        "P_iconBase_33",
        "P_iconBase_34",
        "P_iconBase_35",
      }
    );

    return true;
}

[[address(0x807AFB90)]]
dStockItem_c::PANE_LIST_e dStockItem_c::getPosPaneForPlayer(int player)
{
    using PaneList = PANE_LIST_e[8][8];

    PANE_LIST_e posPane = PaneList{
      {
        PANE_LIST_e::P_iconBase_09,
      },
      {
        PANE_LIST_e::P_iconBase_07,
        PANE_LIST_e::P_iconBase_08,
      },
      {
        PANE_LIST_e::P_iconBase_04,
        PANE_LIST_e::P_iconBase_05,
        PANE_LIST_e::P_iconBase_06,
      },
      {
        PANE_LIST_e::P_iconBase_00,
        PANE_LIST_e::P_iconBase_01,
        PANE_LIST_e::P_iconBase_02,
        PANE_LIST_e::P_iconBase_03,
      },
      {
        PANE_LIST_e::P_iconBase_10,
        PANE_LIST_e::P_iconBase_11,
        PANE_LIST_e::P_iconBase_12,
        PANE_LIST_e::P_iconBase_13,
        PANE_LIST_e::P_iconBase_14,
      },
      {
        PANE_LIST_e::P_iconBase_15,
        PANE_LIST_e::P_iconBase_16,
        PANE_LIST_e::P_iconBase_17,
        PANE_LIST_e::P_iconBase_18,
        PANE_LIST_e::P_iconBase_19,
        PANE_LIST_e::P_iconBase_20,
      },
      {
        PANE_LIST_e::P_iconBase_21,
        PANE_LIST_e::P_iconBase_22,
        PANE_LIST_e::P_iconBase_23,
        PANE_LIST_e::P_iconBase_24,
        PANE_LIST_e::P_iconBase_25,
        PANE_LIST_e::P_iconBase_26,
        PANE_LIST_e::P_iconBase_27,
      },
      {
        PANE_LIST_e::P_iconBase_28,
        PANE_LIST_e::P_iconBase_29,
        PANE_LIST_e::P_iconBase_30,
        PANE_LIST_e::P_iconBase_31,
        PANE_LIST_e::P_iconBase_32,
        PANE_LIST_e::P_iconBase_33,
        PANE_LIST_e::P_iconBase_34,
        PANE_LIST_e::P_iconBase_35,
      },
    }[mPresentPlayerCount - 1][player];

    if (posPane == PANE_LIST_e::FIRST) {
        posPane = PANE_LIST_e::NONE;
    }

    return posPane;
}

[[address(0x807AFBC0)]]
void dStockItem_c::calcPosScale() ASM_METHOD(
  // clang-format off
/* 807AFBC0 9421FE30 */  stwu     r1, -464(r1);
/* 807AFBC4 7C0802A6 */  mflr     r0;
/* 807AFBC8 900101D4 */  stw      r0, 468(r1);
/* 807AFBCC 396101B0 */  addi     r11, r1, 432;
/* 807AFBD0 DBE101C0 */  stfd     f31, 448(r1);
/* 807AFBD4 F3E101C8 */  .long    0xF3E101C8; // psq_st   f31, 456(r1), 0, 0;
/* 807AFBD8 DBC101B0 */  stfd     f30, 432(r1);
/* 807AFBDC F3C101B8 */  .long    0xF3C101B8; // psq_st   f30, 440(r1), 0, 0;
/* 807AFBE0 4BB2D459 */  bl       UNDEF_802dd038;
/* 807AFBE4 808308B0 */  lwz      r4, 2224(r3);
/* 807AFBE8 3FE08093 */  lis      r31, UNDEF_809358d0@ha;
/* 807AFBEC 3BFF58D0 */  addi     r31, r31, UNDEF_809358d0@l;
/* 807AFBF0 3E808035 */  lis      r20, mPlayerType__9daPyMng_c@ha;
/* 807AFBF4 3804FFFF */  subi     r0, r4, 1;
/* 807AFBF8 C01F00F8 */  lfs      f0, 248(r31);
/* 807AFBFC 5400103A */  slwi     r0, r0, 2;
/* 807AFC00 C03F00B0 */  lfs      f1, 176(r31);
/* 807AFC04 7C830214 */  add      r4, r3, r0;
/* 807AFC08 7C7E1B78 */  mr       r30, r3;
/* 807AFC0C 8084024C */  lwz      r4, 588(r4);
/* 807AFC10 3A945160 */  addi     r20, r20, mPlayerType__9daPyMng_c@l;
/* 807AFC14 D021002C */  stfs     f1, 44(r1);
/* 807AFC18 3AA00000 */  li       r21, 0;
/* 807AFC1C 80640044 */  lwz      r3, 68(r4);
/* 807AFC20 3AC00000 */  li       r22, 0;
/* 807AFC24 80040048 */  lwz      r0, 72(r4);
/* 807AFC28 90610010 */  stw      r3, 16(r1);
/* 807AFC2C C3FF00FC */  lfs      f31, 252(r31);
/* 807AFC30 90010014 */  stw      r0, 20(r1);
/* 807AFC34 C0210010 */  lfs      f1, 16(r1);
/* 807AFC38 C0410014 */  lfs      f2, 20(r1);
/* 807AFC3C D0010090 */  stfs     f0, 144(r1);
/* 807AFC40 C3DF0100 */  lfs      f30, 256(r31);
/* 807AFC44 D021009C */  stfs     f1, 156(r1);
/* 807AFC48 D041001C */  stfs     f2, 28(r1);
/* 807AFC4C D0010094 */  stfs     f0, 148(r1);
/* 807AFC50 D0010098 */  stfs     f0, 152(r1);
UNDEF_807afc54:;
/* 807AFC54 7C7EB214 */  add      r3, r30, r22;
/* 807AFC58          */  lbz      r0, dStockItem_c_OFFSET_maPlayerPresent(r3);
/* 807AFC5C 2C000000 */  cmpwi    r0, 0;
/* 807AFC60 41820108 */  beq-     UNDEF_807afd68;
/* 807AFC64 82F40000 */  lwz      r23, 0(r20);
/* 807AFC68 7FC3F378 */  mr       r3, r30;
/* 807AFC6C 7EA4AB78 */  mr       r4, r21;
/* 807AFC70 4BFFFF21 */  bl       UNDEF_807afb90;
/* 807AFC74          */  cmpwi    r3, PANE_LIST_e_NONE;
/* 807AFC78 418200EC */  beq-     UNDEF_807afd64;
/* 807AFC7C 5460103A */  slwi     r0, r3, 2;
/* 807AFC80 38610054 */  addi     r3, r1, 84;
/* 807AFC84 7CBE0214 */  add      r5, r30, r0;
/* 807AFC88 38810084 */  addi     r4, r1, 132;
/* 807AFC8C          */  lwz      r17, dStockItem_c_OFFSET_mpNForUsePos(r5);
/* 807AFC90 80B10090 */  lwz      r5, 144(r17);
/* 807AFC94 90A10144 */  stw      r5, 324(r1);
/* 807AFC98 801100A0 */  lwz      r0, 160(r17);
/* 807AFC9C 90010154 */  stw      r0, 340(r1);
/* 807AFCA0 82110084 */  lwz      r16, 132(r17);
/* 807AFCA4 81910088 */  lwz      r12, 136(r17);
/* 807AFCA8 8171008C */  lwz      r11, 140(r17);
/* 807AFCAC 81510094 */  lwz      r10, 148(r17);
/* 807AFCB0 81310098 */  lwz      r9, 152(r17);
/* 807AFCB4 8111009C */  lwz      r8, 156(r17);
/* 807AFCB8 80F100A4 */  lwz      r7, 164(r17);
/* 807AFCBC 80D100A8 */  lwz      r6, 168(r17);
/* 807AFCC0 80B100AC */  lwz      r5, 172(r17);
/* 807AFCC4 801100B0 */  lwz      r0, 176(r17);
/* 807AFCC8 C0210144 */  lfs      f1, 324(r1);
/* 807AFCCC C0010154 */  lfs      f0, 340(r1);
/* 807AFCD0 92010138 */  stw      r16, 312(r1);
/* 807AFCD4 9181013C */  stw      r12, 316(r1);
/* 807AFCD8 91610140 */  stw      r11, 320(r1);
/* 807AFCDC 91410148 */  stw      r10, 328(r1);
/* 807AFCE0 9121014C */  stw      r9, 332(r1);
/* 807AFCE4 91010150 */  stw      r8, 336(r1);
/* 807AFCE8 90E10158 */  stw      r7, 344(r1);
/* 807AFCEC 90C1015C */  stw      r6, 348(r1);
/* 807AFCF0 90A10160 */  stw      r5, 352(r1);
/* 807AFCF4 90010164 */  stw      r0, 356(r1);
/* 807AFCF8 D0210084 */  stfs     f1, 132(r1);
/* 807AFCFC D0010088 */  stfs     f0, 136(r1);
/* 807AFD00 D3E1008C */  stfs     f31, 140(r1);
/* 807AFD04 4B9035DD */  bl       UNDEF_800b32e0;
/* 807AFD08 C0610054 */  lfs      f3, 84(r1);
/* 807AFD0C 56E0103A */  slwi     r0, r23, 2;
/* 807AFD10 C0210058 */  lfs      f1, 88(r1);
/* 807AFD14 7C9E0214 */  add      r4, r30, r0;
/* 807AFD18 C001005C */  lfs      f0, 92(r1);
/* 807AFD1C D0210088 */  stfs     f1, 136(r1);
/* 807AFD20 C0410090 */  lfs      f2, 144(r1);
/* 807AFD24 D001008C */  stfs     f0, 140(r1);
/* 807AFD28 C0210094 */  lfs      f1, 148(r1);
/* 807AFD2C D0610084 */  stfs     f3, 132(r1);
/* 807AFD30 C0010098 */  lfs      f0, 152(r1);
/* 807AFD34          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r4);
/* 807AFD38 D06300AC */  stfs     f3, 172(r3);
/* 807AFD3C C0610088 */  lfs      f3, 136(r1);
/* 807AFD40 D06300B0 */  stfs     f3, 176(r3);
/* 807AFD44 C061008C */  lfs      f3, 140(r1);
/* 807AFD48 D06300B4 */  stfs     f3, 180(r3);
/* 807AFD4C          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r4);
/* 807AFD50 D0430220 */  stfs     f2, 544(r3);
/* 807AFD54 D0230224 */  stfs     f1, 548(r3);
/* 807AFD58 D0030228 */  stfs     f0, 552(r3);
/* 807AFD5C          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r4);
/* 807AFD60 D3C3025C */  stfs     f30, 604(r3);
UNDEF_807afd64:;
/* 807AFD64 3AB50001 */  addi     r21, r21, 1;
UNDEF_807afd68:;
/* 807AFD68 3AD60001 */  addi     r22, r22, 1;
/* 807AFD6C 3A940004 */  addi     r20, r20, 4;
/* 807AFD70          */  cmpwi    r22, PLAYER_COUNT;
/* 807AFD74 4180FEE0 */  blt+     UNDEF_807afc54;
/* 807AFD78 C3DF00B0 */  lfs      f30, 176(r31);
/* 807AFD7C 7FD4F378 */  mr       r20, r30;
/* 807AFD80 C3FF00FC */  lfs      f31, 252(r31);
/* 807AFD84 3AA00000 */  li       r21, 0;
UNDEF_807afd88:;
/* 807AFD88 8234025C */  lwz      r17, 604(r20);
/* 807AFD8C 3861003C */  addi     r3, r1, 60;
/* 807AFD90 80D402A0 */  lwz      r6, 672(r20);
/* 807AFD94 38810048 */  addi     r4, r1, 72;
/* 807AFD98 81110090 */  lwz      r8, 144(r17);
/* 807AFD9C 91010114 */  stw      r8, 276(r1);
/* 807AFDA0 80F100A0 */  lwz      r7, 160(r17);
/* 807AFDA4 90E10124 */  stw      r7, 292(r1);
/* 807AFDA8 80A60044 */  lwz      r5, 68(r6);
/* 807AFDAC 80060048 */  lwz      r0, 72(r6);
/* 807AFDB0 90A10008 */  stw      r5, 8(r1);
/* 807AFDB4 82110084 */  lwz      r16, 132(r17);
/* 807AFDB8 9001000C */  stw      r0, 12(r1);
/* 807AFDBC 81910088 */  lwz      r12, 136(r17);
/* 807AFDC0 8171008C */  lwz      r11, 140(r17);
/* 807AFDC4 81510094 */  lwz      r10, 148(r17);
/* 807AFDC8 81310098 */  lwz      r9, 152(r17);
/* 807AFDCC 8111009C */  lwz      r8, 156(r17);
/* 807AFDD0 80F100A4 */  lwz      r7, 164(r17);
/* 807AFDD4 80D100A8 */  lwz      r6, 168(r17);
/* 807AFDD8 80B100AC */  lwz      r5, 172(r17);
/* 807AFDDC 801100B0 */  lwz      r0, 176(r17);
/* 807AFDE0 C0210114 */  lfs      f1, 276(r1);
/* 807AFDE4 C0010124 */  lfs      f0, 292(r1);
/* 807AFDE8 C061000C */  lfs      f3, 12(r1);
/* 807AFDEC C0410008 */  lfs      f2, 8(r1);
/* 807AFDF0 92010108 */  stw      r16, 264(r1);
/* 807AFDF4 9181010C */  stw      r12, 268(r1);
/* 807AFDF8 91610110 */  stw      r11, 272(r1);
/* 807AFDFC 91410118 */  stw      r10, 280(r1);
/* 807AFE00 9121011C */  stw      r9, 284(r1);
/* 807AFE04 91010120 */  stw      r8, 288(r1);
/* 807AFE08 90E10128 */  stw      r7, 296(r1);
/* 807AFE0C 90C1012C */  stw      r6, 300(r1);
/* 807AFE10 90A10130 */  stw      r5, 304(r1);
/* 807AFE14 90010134 */  stw      r0, 308(r1);
/* 807AFE18 D0410078 */  stfs     f2, 120(r1);
/* 807AFE1C D061007C */  stfs     f3, 124(r1);
/* 807AFE20 D3C10080 */  stfs     f30, 128(r1);
/* 807AFE24 D021006C */  stfs     f1, 108(r1);
/* 807AFE28 D0010070 */  stfs     f0, 112(r1);
/* 807AFE2C D0210048 */  stfs     f1, 72(r1);
/* 807AFE30 D001004C */  stfs     f0, 76(r1);
/* 807AFE34 D3E10050 */  stfs     f31, 80(r1);
/* 807AFE38 4B9034A9 */  bl       UNDEF_800b32e0;
/* 807AFE3C C0810040 */  lfs      f4, 64(r1);
/* 807AFE40 3AB50001 */  addi     r21, r21, 1;
/* 807AFE44 C0610044 */  lfs      f3, 68(r1);
/* 807AFE48 FC00F018 */  frsp     f0, f30;
/* 807AFE4C C0A1003C */  lfs      f5, 60(r1);
/* 807AFE50 2C150007 */  cmpwi    r21, 7;
/* 807AFE54 807402F4 */  lwz      r3, 756(r20);
/* 807AFE58 C0410078 */  lfs      f2, 120(r1);
/* 807AFE5C D0A300AC */  stfs     f5, 172(r3);
/* 807AFE60 C021007C */  lfs      f1, 124(r1);
/* 807AFE64 D08300B0 */  stfs     f4, 176(r3);
/* 807AFE68 D06300B4 */  stfs     f3, 180(r3);
/* 807AFE6C 807402F4 */  lwz      r3, 756(r20);
/* 807AFE70 3A940004 */  addi     r20, r20, 4;
/* 807AFE74 D0A1006C */  stfs     f5, 108(r1);
/* 807AFE78 D04301F4 */  stfs     f2, 500(r3);
/* 807AFE7C D02301F8 */  stfs     f1, 504(r3);
/* 807AFE80 D0810070 */  stfs     f4, 112(r1);
/* 807AFE84 D0610074 */  stfs     f3, 116(r1);
/* 807AFE88 D0A10030 */  stfs     f5, 48(r1);
/* 807AFE8C D0810034 */  stfs     f4, 52(r1);
/* 807AFE90 D0610038 */  stfs     f3, 56(r1);
/* 807AFE94 D00301FC */  stfs     f0, 508(r3);
/* 807AFE98 4180FEF0 */  blt+     UNDEF_807afd88;
/* 807AFE9C 807E0278 */  lwz      r3, 632(r30);
/* 807AFEA0 823E027C */  lwz      r17, 636(r30);
/* 807AFEA4 80030090 */  lwz      r0, 144(r3);
/* 807AFEA8 900100E4 */  stw      r0, 228(r1);
/* 807AFEAC 820300A0 */  lwz      r16, 160(r3);
/* 807AFEB0 82A30084 */  lwz      r21, 132(r3);
/* 807AFEB4 82C30088 */  lwz      r22, 136(r3);
/* 807AFEB8 82E3008C */  lwz      r23, 140(r3);
/* 807AFEBC 83030094 */  lwz      r24, 148(r3);
/* 807AFEC0 83230098 */  lwz      r25, 152(r3);
/* 807AFEC4 8343009C */  lwz      r26, 156(r3);
/* 807AFEC8 836300A4 */  lwz      r27, 164(r3);
/* 807AFECC 838300A8 */  lwz      r28, 168(r3);
/* 807AFED0 83A300AC */  lwz      r29, 172(r3);
/* 807AFED4 818300B0 */  lwz      r12, 176(r3);
/* 807AFED8 82510084 */  lwz      r18, 132(r17);
/* 807AFEDC 81710088 */  lwz      r11, 136(r17);
/* 807AFEE0 8151008C */  lwz      r10, 140(r17);
/* 807AFEE4 81310090 */  lwz      r9, 144(r17);
/* 807AFEE8 81110094 */  lwz      r8, 148(r17);
/* 807AFEEC 82710098 */  lwz      r19, 152(r17);
/* 807AFEF0 80F1009C */  lwz      r7, 156(r17);
/* 807AFEF4 80D100A0 */  lwz      r6, 160(r17);
/* 807AFEF8 80B100A4 */  lwz      r5, 164(r17);
/* 807AFEFC 809100A8 */  lwz      r4, 168(r17);
/* 807AFF00 807100AC */  lwz      r3, 172(r17);
/* 807AFF04 801100B0 */  lwz      r0, 176(r17);
/* 807AFF08 920100F4 */  stw      r16, 244(r1);
/* 807AFF0C 829E0310 */  lwz      r20, 784(r30);
/* 807AFF10 C0A100E4 */  lfs      f5, 228(r1);
/* 807AFF14 82140208 */  lwz      r16, 520(r20);
/* 807AFF18 C08100F4 */  lfs      f4, 244(r1);
/* 807AFF1C D0B0002C */  stfs     f5, 44(r16);
/* 807AFF20 C07F00FC */  lfs      f3, 252(r31);
/* 807AFF24 D0900030 */  stfs     f4, 48(r16);
/* 807AFF28 924100A8 */  stw      r18, 168(r1);
/* 807AFF2C 926100BC */  stw      r19, 188(r1);
/* 807AFF30 C04100A8 */  lfs      f2, 168(r1);
/* 807AFF34 D0700034 */  stfs     f3, 52(r16);
/* 807AFF38 C02100BC */  lfs      f1, 188(r1);
/* 807AFF3C D0500044 */  stfs     f2, 68(r16);
/* 807AFF40 D0300048 */  stfs     f1, 72(r16);
/* 807AFF44 829E0310 */  lwz      r20, 784(r30);
/* 807AFF48 83FE02A0 */  lwz      r31, 672(r30);
/* 807AFF4C 82140244 */  lwz      r16, 580(r20);
/* 807AFF50 C01F0044 */  lfs      f0, 68(r31);
/* 807AFF54 D0100044 */  stfs     f0, 68(r16);
/* 807AFF58 C01F0048 */  lfs      f0, 72(r31);
/* 807AFF5C D0100048 */  stfs     f0, 72(r16);
/* 807AFF60 829E0310 */  lwz      r20, 784(r30);
/* 807AFF64 83FE02A4 */  lwz      r31, 676(r30);
/* 807AFF68 82140248 */  lwz      r16, 584(r20);
/* 807AFF6C C01F0044 */  lfs      f0, 68(r31);
/* 807AFF70 D0100044 */  stfs     f0, 68(r16);
/* 807AFF74 C01F0048 */  lfs      f0, 72(r31);
/* 807AFF78 D0100048 */  stfs     f0, 72(r16);
/* 807AFF7C 829E0310 */  lwz      r20, 784(r30);
/* 807AFF80 83FE02A8 */  lwz      r31, 680(r30);
/* 807AFF84 8214024C */  lwz      r16, 588(r20);
/* 807AFF88 C01F0044 */  lfs      f0, 68(r31);
/* 807AFF8C D0100044 */  stfs     f0, 68(r16);
/* 807AFF90 C01F0048 */  lfs      f0, 72(r31);
/* 807AFF94 D0100048 */  stfs     f0, 72(r16);
/* 807AFF98 829E0310 */  lwz      r20, 784(r30);
/* 807AFF9C 83FE02AC */  lwz      r31, 684(r30);
/* 807AFFA0 82140250 */  lwz      r16, 592(r20);
/* 807AFFA4 C01F0044 */  lfs      f0, 68(r31);
/* 807AFFA8 92A100D8 */  stw      r21, 216(r1);
/* 807AFFAC 92C100DC */  stw      r22, 220(r1);
/* 807AFFB0 92E100E0 */  stw      r23, 224(r1);
/* 807AFFB4 930100E8 */  stw      r24, 232(r1);
/* 807AFFB8 932100EC */  stw      r25, 236(r1);
/* 807AFFBC 934100F0 */  stw      r26, 240(r1);
/* 807AFFC0 936100F8 */  stw      r27, 248(r1);
/* 807AFFC4 938100FC */  stw      r28, 252(r1);
/* 807AFFC8 93A10100 */  stw      r29, 256(r1);
/* 807AFFCC 91810104 */  stw      r12, 260(r1);
/* 807AFFD0 916100AC */  stw      r11, 172(r1);
/* 807AFFD4 914100B0 */  stw      r10, 176(r1);
/* 807AFFD8 912100B4 */  stw      r9, 180(r1);
/* 807AFFDC 910100B8 */  stw      r8, 184(r1);
/* 807AFFE0 90E100C0 */  stw      r7, 192(r1);
/* 807AFFE4 90C100C4 */  stw      r6, 196(r1);
/* 807AFFE8 90A100C8 */  stw      r5, 200(r1);
/* 807AFFEC 908100CC */  stw      r4, 204(r1);
/* 807AFFF0 906100D0 */  stw      r3, 208(r1);
/* 807AFFF4 900100D4 */  stw      r0, 212(r1);
/* 807AFFF8 D0A10060 */  stfs     f5, 96(r1);
/* 807AFFFC D0810064 */  stfs     f4, 100(r1);
/* 807B0000 D0610068 */  stfs     f3, 104(r1);
/* 807B0004 D0410010 */  stfs     f2, 16(r1);
/* 807B0008 D0210014 */  stfs     f1, 20(r1);
/* 807B000C D0100044 */  stfs     f0, 68(r16);
/* 807B0010 C01F0048 */  lfs      f0, 72(r31);
/* 807B0014 D0100048 */  stfs     f0, 72(r16);
/* 807B0018 807E0310 */  lwz      r3, 784(r30);
/* 807B001C 809E02B0 */  lwz      r4, 688(r30);
/* 807B0020 80630254 */  lwz      r3, 596(r3);
/* 807B0024 C0040044 */  lfs      f0, 68(r4);
/* 807B0028 D0030044 */  stfs     f0, 68(r3);
/* 807B002C C0040048 */  lfs      f0, 72(r4);
/* 807B0030 D0030048 */  stfs     f0, 72(r3);
/* 807B0034 807E0310 */  lwz      r3, 784(r30);
/* 807B0038 809E02B4 */  lwz      r4, 692(r30);
/* 807B003C 80630258 */  lwz      r3, 600(r3);
/* 807B0040 C0040044 */  lfs      f0, 68(r4);
/* 807B0044 D0030044 */  stfs     f0, 68(r3);
/* 807B0048 C0040048 */  lfs      f0, 72(r4);
/* 807B004C D0030048 */  stfs     f0, 72(r3);
/* 807B0050 807E0310 */  lwz      r3, 784(r30);
/* 807B0054 809E02B8 */  lwz      r4, 696(r30);
/* 807B0058 8063025C */  lwz      r3, 604(r3);
/* 807B005C C0040044 */  lfs      f0, 68(r4);
/* 807B0060 D0030044 */  stfs     f0, 68(r3);
/* 807B0064 C0040048 */  lfs      f0, 72(r4);
/* 807B0068 D0030048 */  stfs     f0, 72(r3);
/* 807B006C E3E101C8 */  .long    0xE3E101C8; // psq_l    f31, 456(r1), 0, 0;
/* 807B0070 CBE101C0 */  lfd      f31, 448(r1);
/* 807B0074 E3C101B8 */  .long    0xE3C101B8; // psq_l    f30, 440(r1), 0, 0;
/* 807B0078 CBC101B0 */  lfd      f30, 432(r1);
/* 807B007C 396101B0 */  addi     r11, r1, 432;
/* 807B0080 4BB2D005 */  bl       UNDEF_802dd084;
/* 807B0084 800101D4 */  lwz      r0, 468(r1);
/* 807B0088 7C0803A6 */  mtlr     r0;
/* 807B008C 382101D0 */  addi     r1, r1, 464;
/* 807B0090 4E800020 */  blr;
  // clang-format on
);

[[address(0x807B00A0)]]
void dStockItem_c::calc2DPlayerItemUpdate() ASM_METHOD(
  // clang-format off
/* 807B00A0 9421FF90 */  stwu     r1, -112(r1);
/* 807B00A4 7C0802A6 */  mflr     r0;
/* 807B00A8 90010074 */  stw      r0, 116(r1);
/* 807B00AC 39610070 */  addi     r11, r1, 112;
/* 807B00B0 4BB2CF9D */  bl       UNDEF_802dd04c;
/* 807B00B4 800308A0 */  lwz      r0, 2208(r3);
/* 807B00B8 7C771B78 */  mr       r23, r3;
/* 807B00BC 3B400000 */  li       r26, 0;
/* 807B00C0 2C000006 */  cmpwi    r0, 6;
/* 807B00C4 40820104 */  bne-     UNDEF_807b01c8;
/* 807B00C8 3EC08035 */  lis      r22, mCreateItem__9daPyMng_c@ha;
/* 807B00CC 3F608035 */  lis      r27, mPlayerType__9daPyMng_c@ha;
/* 807B00D0 7EFCBB78 */  mr       r28, r23;
/* 807B00D4 3BA00000 */  li       r29, 0;
/* 807B00D8 3B7B5160 */  addi     r27, r27, mPlayerType__9daPyMng_c@l;
/* 807B00DC 3AD65180 */  addi     r22, r22, mCreateItem__9daPyMng_c@l;
/* 807B00E0 3B000001 */  li       r24, 1;
UNDEF_807b00e4:;
/* 807B00E4 801B0000 */  lwz      r0, 0(r27);
/* 807B00E8 5400103A */  slwi     r0, r0, 2;
/* 807B00EC 7C16002E */  lwzx     r0, r22, r0;
/* 807B00F0 540007FF */  clrlwi.  r0, r0, 31;
/* 807B00F4 408200BC */  bne-     UNDEF_807b01b0;
/* 807B00F8 7C77EA14 */  add      r3, r23, r29;
/* 807B00FC          */  lbz      r0, dStockItem_c_OFFSET_maPlayerPresent(r3);
/* 807B0100 2C000000 */  cmpwi    r0, 0;
/* 807B0104 418200AC */  beq-     UNDEF_807b01b0;
/* 807B0108 2C1A0000 */  cmpwi    r26, 0;
/* 807B010C 40820008 */  bne-     UNDEF_807b0114;
/* 807B0110 4B951111 */  bl       startStarSound__12daWmPlayer_cFv;
UNDEF_807b0114:;
/* 807B0114 833B0000 */  lwz      r25, 0(r27);
/* 807B0118 5720103A */  slwi     r0, r25, 2;
/* 807B011C 7F16012E */  stwx     r24, r22, r0;
/* 807B0120 7FD70214 */  add      r30, r23, r0;
/* 807B0124          */  lwz      r4, dStockItem_c_OFFSET_mpa2DPlayer(r30);
/* 807B0128 80640128 */  lwz      r3, 296(r4);
/* 807B012C C00400B4 */  lfs      f0, 180(r4);
/* 807B0130 80630004 */  lwz      r3, 4(r3);
/* 807B0134 C02400B0 */  lfs      f1, 176(r4);
/* 807B0138 81830000 */  lwz      r12, 0(r3);
/* 807B013C C04400AC */  lfs      f2, 172(r4);
/* 807B0140 818C0040 */  lwz      r12, 64(r12);
/* 807B0144 D0410030 */  stfs     f2, 48(r1);
/* 807B0148 D0210034 */  stfs     f1, 52(r1);
/* 807B014C D0010038 */  stfs     f0, 56(r1);
/* 807B0150 7D8903A6 */  mtctr    r12;
/* 807B0154 4E800421 */  bctrl;
/* 807B0158          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r30);
/* 807B015C 80630128 */  lwz      r3, 296(r3);
/* 807B0160 80630004 */  lwz      r3, 4(r3);
/* 807B0164 81830000 */  lwz      r12, 0(r3);
/* 807B0168 818C0048 */  lwz      r12, 72(r12);
/* 807B016C 7D8903A6 */  mtctr    r12;
/* 807B0170 4E800421 */  bctrl;
/* 807B0190 3B400001 */  li       r26, 1;

                         // Can't play the item use effect here yet for 5+
                         cmpwi    r29, 4;
                         bge-     UNDEF_807b01b0;

/* 807B0174 933C0890 */  stw      r25, 0x890(r28);
/* 807B0178 7EE3BB78 */  mr       r3, r23;
/* 807B017C C0010038 */  lfs      f0, 56(r1);
/* 807B0180 7FA6EB78 */  mr       r6, r29;
/* 807B0184 C0210034 */  lfs      f1, 52(r1);
/* 807B0188 38A10018 */  addi     r5, r1, 24;
/* 807B018C C0410030 */  lfs      f2, 48(r1);
/* 807B0194 D0410018 */  stfs     f2, 24(r1);
/* 807B0198 D021001C */  stfs     f1, 28(r1);
/* 807B019C D0010020 */  stfs     f0, 32(r1);
/* 807B01A0 809E02E4 */  lwz      r4, 740(r30);
/* 807B01A4 80040004 */  lwz      r0, 4(r4);
/* 807B01A8 5404073E */  clrlwi   r4, r0, 28;
/* 807B01AC 480001B5 */  bl       UNDEF_807b0360;
UNDEF_807b01b0:;
/* 807B01B0 3BBD0001 */  addi     r29, r29, 1;
/* 807B01B4 3B9C0004 */  addi     r28, r28, 4;
/* 807B01B8          */  cmpwi    r29, PLAYER_COUNT;
/* 807B01BC 3B7B0004 */  addi     r27, r27, 4;
/* 807B01C0 4180FF24 */  blt+     UNDEF_807b00e4;
/* 807B01C4 480000EC */  b        UNDEF_807b02b0;
UNDEF_807b01c8:;
/* 807B01C8 3F808035 */  lis      r28, mPlayerType__9daPyMng_c@ha;
/* 807B01CC 3FC08035 */  lis      r30, mCreateItem__9daPyMng_c@ha;
/* 807B01D0 3FE08035 */  lis      r31, mPlayerMode__9daPyMng_c@ha;
/* 807B01D4 3EC08093 */  lis      r22, UNDEF_809359d8@ha;
/* 807B01D8 83230328 */  lwz      r25, 808(r3);
/* 807B01DC 7EFBBB78 */  mr       r27, r23;
/* 807B01E0 3B9C5160 */  addi     r28, r28, mPlayerType__9daPyMng_c@l;
/* 807B01E4 3BDE5180 */  addi     r30, r30, mCreateItem__9daPyMng_c@l;
/* 807B01E8 3BFF5170 */  addi     r31, r31, mPlayerMode__9daPyMng_c@l;
/* 807B01EC 3AD659D8 */  addi     r22, r22, UNDEF_809359d8@l;
/* 807B01F0 3B000000 */  li       r24, 0;
UNDEF_807b01f4:;
/* 807B01F4 83BC0000 */  lwz      r29, 0(r28);
/* 807B01F8 7F23CB78 */  mr       r3, r25;
/* 807B01FC 38A10008 */  addi     r5, r1, 8;
/* 807B0200 57B5103A */  slwi     r21, r29, 2;
/* 807B0204 7C1EA82E */  lwzx     r0, r30, r21;
/* 807B0208 7C9FA82E */  lwzx     r4, r31, r21;
/* 807B020C 540007FE */  clrlwi   r0, r0, 31;
/* 807B0210 98010008 */  stb      r0, 8(r1);
/* 807B0214 4B94C74D */  bl       UNDEF_800fc960;
/* 807B0218 7C1FA82E */  lwzx     r0, r31, r21;
/* 807B021C 7C030000 */  cmpw     r3, r0;
/* 807B0220 4182007C */  beq-     UNDEF_807b029c;
/* 807B0224 7C97C214 */  add      r4, r23, r24;
/* 807B0228          */  lbz      r0, dStockItem_c_OFFSET_maPlayerPresent(r4);
/* 807B022C 2C000000 */  cmpwi    r0, 0;
/* 807B0230 4182006C */  beq-     UNDEF_807b029c;
/* 807B0234 7C7FA92E */  stwx     r3, r31, r21;
/* 807B0238 7EB7AA14 */  add      r21, r23, r21;
/* 807B023C 801708A0 */  lwz      r0, 0x8A0(r23);
/* 807B0240          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r21);
/* 807B0244 5400103A */  slwi     r0, r0, 2;
/* 807B0248 7C96002E */  lwzx     r4, r22, r0;
/* 807B024C 48116BA5 */  bl       UNDEF_808c6df0;
/* 807B0250          */  lwz      r4, dStockItem_c_OFFSET_mpa2DPlayer(r21);
/* 807B0254 7EE3BB78 */  mr       r3, r23;
/* 807B0258 7F06C378 */  mr       r6, r24;
/* 807B025C 38A1000C */  addi     r5, r1, 12;
/* 807B0260 C00400B4 */  lfs      f0, 180(r4);
/* 807B0264 3B400001 */  li       r26, 1;
/* 807B0268 C02400B0 */  lfs      f1, 176(r4);
/* 807B026C C04400AC */  lfs      f2, 172(r4);
/* 807B0270 D0410024 */  stfs     f2, 36(r1);

                         // Can't play the item use effect here yet for 5+
                         cmpwi    r24, 4;
                         bge-     UNDEF_807b029c;

/* 807B0274 93BB0890 */  stw      r29, 0x890(r27);
/* 807B0278 D041000C */  stfs     f2, 12(r1);
/* 807B027C D0210010 */  stfs     f1, 16(r1);
/* 807B0280 D0010014 */  stfs     f0, 20(r1);
/* 807B0284          */  lwz      r4, dStockItem_c_OFFSET_mpa2DPlayer(r21);
/* 807B0288 D0210028 */  stfs     f1, 40(r1);
/* 807B028C 80040004 */  lwz      r0, 4(r4);
/* 807B0290 D001002C */  stfs     f0, 44(r1);
/* 807B0294 5404073E */  clrlwi   r4, r0, 28;
/* 807B0298 480000C9 */  bl       UNDEF_807b0360;
UNDEF_807b029c:;
/* 807B029C 3B180001 */  addi     r24, r24, 1;
/* 807B02A0 3B7B0004 */  addi     r27, r27, 4;
/* 807B02A4          */  cmpwi    r24, PLAYER_COUNT;
/* 807B02A8 3B9C0004 */  addi     r28, r28, 4;
/* 807B02AC 4180FF48 */  blt+     UNDEF_807b01f4;
UNDEF_807b02b0:;
/* 807B02B0 2C1A0000 */  cmpwi    r26, 0;
/* 807B02B4 41820068 */  beq-     UNDEF_807b031c;
/* 807B02B8 3C608043 */  lis      r3, m_instance__7dInfo_c@ha;
/* 807B02BC 809708A0 */  lwz      r4, 2208(r23);
/* 807B02C0 8063A25C */  lwz      r3, m_instance__7dInfo_c@l(r3);
/* 807B02C4 4B90B0BD */  bl       UNDEF_800bb380; // subStockItem__7dInfo_cFi
/* 807B02C8 801708A0 */  lwz      r0, 2208(r23);
/* 807B02CC 7EE3BB78 */  mr       r3, r23;
/* 807B02D0 5400103A */  slwi     r0, r0, 2;
/* 807B02D4 7CB70214 */  add      r5, r23, r0;
/* 807B02D8 808508B4 */  lwz      r4, 2228(r5);
/* 807B02DC 3804FFFF */  subi     r0, r4, 1;
/* 807B02E0 900508B4 */  stw      r0, 2228(r5);
/* 807B02E4 80B708A0 */  lwz      r5, 2208(r23);
/* 807B02E8 54A0103A */  slwi     r0, r5, 2;
/* 807B02EC 7C970214 */  add      r4, r23, r0;
/* 807B02F0 808408B4 */  lwz      r4, 2228(r4);
/* 807B02F4 4800004D */  bl       UNDEF_807b0340;
/* 807B02F8 801708A0 */  lwz      r0, 2208(r23);
/* 807B02FC 5400103A */  slwi     r0, r0, 2;
/* 807B0300 7C770214 */  add      r3, r23, r0;
/* 807B0304 800308B4 */  lwz      r0, 2228(r3);
/* 807B0308 2C000000 */  cmpwi    r0, 0;
/* 807B030C 40820010 */  bne-     UNDEF_807b031c;
/* 807B0310 806302F4 */  lwz      r3, 756(r3);
/* 807B0314 38000001 */  li       r0, 1;
/* 807B0318 90030204 */  stw      r0, 516(r3);
UNDEF_807b031c:;
/* 807B031C 39610070 */  addi     r11, r1, 112;
/* 807B0320 4BB2CD79 */  bl       UNDEF_802dd098;
/* 807B0324 80010074 */  lwz      r0, 116(r1);
/* 807B0328 7C0803A6 */  mtlr     r0;
/* 807B032C 38210070 */  addi     r1, r1, 112;
/* 807B0330 4E800020 */  blr;
  // clang-format on
);

[[address(0x807B03A0)]]
void dStockItem_c::calcUseEffects() ASM_METHOD(
  // clang-format off
UNDEF_807b03a0:;
/* 807B03A0 9421FFC0 */  stwu     r1, -64(r1);
/* 807B03A4 7C0802A6 */  mflr     r0;
/* 807B03A8 3C808093 */  lis      r4, UNDEF_809359d0@ha;
/* 807B03AC 90010044 */  stw      r0, 68(r1);
/* 807B03B0 DBE10030 */  stfd     f31, 48(r1);
/* 807B03B4 F3E10038 */  .long    0xF3E10038; // psq_st   f31, 56(r1), 0, 0;
/* 807B03B8 C3E459D0 */  lfs      f31, UNDEF_809359d0@l(r4);
/* 807B03BC 93E1002C */  stw      r31, 44(r1);
/* 807B03C0 93C10028 */  stw      r30, 40(r1);
/* 807B03C4 3BC3032C */  addi     r30, r3, 812;
/* 807B03C8 93A10024 */  stw      r29, 36(r1);
/* 807B03CC 3BA00000 */  li       r29, 0;
/* 807B03D0 93810020 */  stw      r28, 32(r1);
/* 807B03D4 7C7C1B78 */  mr       r28, r3;
/* 807B03D8 7F9FE378 */  mr       r31, r28;
UNDEF_807b03dc:;
/* 807B03DC 801F0890 */  lwz      r0, 2192(r31);
/* 807B03E0 2C000004 */  cmpwi    r0, 4;
/* 807B03E4 4182004C */  beq-     UNDEF_807b0430;
/* 807B03E8 5400103A */  slwi     r0, r0, 2                 ;
/* 807B03EC 7FC3F378 */  mr       r3, r30;
/* 807B03F0 7CBC0214 */  add      r5, r28, r0;
/* 807B03F4 38810008 */  addi     r4, r1, 8;
/* 807B03F8          */  lwz      r7, dStockItem_c_OFFSET_mpa2DPlayer(r5);
/* 807B03FC 38A00000 */  li       r5, 0;
/* 807B0400 38C00000 */  li       r6, 0;
/* 807B0404 C00700B0 */  lfs      f0, 176(r7);
/* 807B0408 C02700B4 */  lfs      f1, 180(r7);
/* 807B040C C04700AC */  lfs      f2, 172(r7);
/* 807B0410 EC00F82A */  fadds    f0, f0, f31;
/* 807B0414 D0410008 */  stfs     f2, 8(r1);
/* 807B0418 D0210010 */  stfs     f1, 16(r1);
/* 807B041C D001000C */  stfs     f0, 12(r1);
/* 807B0420 819E0000 */  lwz      r12, 0(r30);
/* 807B0424 818C00B0 */  lwz      r12, 176(r12);
/* 807B0428 7D8903A6 */  mtctr    r12;
/* 807B042C 4E800421 */  bctrl    ;
UNDEF_807b0430:;
/* 807B0430 3BBD0001 */  addi     r29, r29, 1;
/* 807B0434 3BDE0114 */  addi     r30, r30, 276;
/* 807B0438 2C1D0004 */  cmpwi    r29, 4;
/* 807B043C 3BFF0004 */  addi     r31, r31, 4;
/* 807B0440 4180FF9C */  blt+     UNDEF_807b03dc;
/* 807B0444 80010044 */  lwz      r0, 68(r1);
/* 807B0448 E3E10038 */  .long    0xE3E10038; // psq_l    f31, 56(r1), 0, 0;
/* 807B044C CBE10030 */  lfd      f31, 48(r1);
/* 807B0450 83E1002C */  lwz      r31, 44(r1);
/* 807B0454 83C10028 */  lwz      r30, 40(r1);
/* 807B0458 83A10024 */  lwz      r29, 36(r1);
/* 807B045C 83810020 */  lwz      r28, 32(r1);
/* 807B0460 7C0803A6 */  mtlr     r0;
/* 807B0464 38210040 */  addi     r1, r1, 64;
/* 807B0468 4E800020 */  blr      ;
/* 807B046C 00000000 */  .word    0x00000000;
  // clang-format on
)

void stockItemPlayStarVoice(PLAYER_TYPE_e character, bool isMame)
{
    dAudio::SndObjctCSPly_c* playerSound = dWmSeManager_c::m_pInstance->mpObjCSPlyArray[character];
    playerSound->mSoundPlyMode = (isMame) ? 3 : 0;
    playerSound->startVoiceSound(SndObjctPly::PLAYER_VOICE_e::GET_STAR, 0);
}

[[address(0x807B06C0)]]
bool dStockItem_c::checkItemSelect() ASM_METHOD(
  // clang-format off
/* 807B06C0 9421FFD0 */  stwu     r1, -48(r1);
/* 807B06C4 7C0802A6 */  mflr     r0;
/* 807B06C8 90010034 */  stw      r0, 52(r1);
/* 807B06CC 39610030 */  addi     r11, r1, 48;
/* 807B06D0 4BB2C98D */  bl       UNDEF_802dd05c;
/* 807B06D4 80A308A0 */  lwz      r5, 2208(r3);
/* 807B06D8 3C808093 */  lis      r4, UNDEF_80935a0c@ha;
/* 807B06DC 38845A0C */  addi     r4, r4, UNDEF_80935a0c@l;
/* 807B06E0 7C791B78 */  mr       r25, r3;
/* 807B06E4 54A0103A */  slwi     r0, r5, 2;
/* 807B06E8 2C050006 */  cmpwi    r5, 6;
/* 807B06EC 7F64002E */  lwzx     r27, r4, r0;
/* 807B06F0 93630328 */  stw      r27, 808(r3);
/* 807B06F4 408200C4 */  bne-     UNDEF_807b07b8;
/* 807B06F8          */  lbz      r0, dStockItem_c_OFFSET_maPlayerPresent(r3);
/* 807B06FC 38E00000 */  li       r7, 0;
/* 807B0700 2C000000 */  cmpwi    r0, 0;
/* 807B0704 41820028 */  beq-     UNDEF_807b072c;
/* 807B0708 3CA08035 */  lis      r5, mPlayerType__9daPyMng_c@ha;
/* 807B070C 3C808035 */  lis      r4, mPlayerMode__9daPyMng_c@ha;
/* 807B0710 80055160 */  lwz      r0, mPlayerType__9daPyMng_c@l(r5);
/* 807B0714 38845170 */  addi     r4, r4, mPlayerMode__9daPyMng_c@l;
/* 807B0718 5400103A */  slwi     r0, r0, 2;
/* 807B071C 7C04002E */  lwzx     r0, r4, r0;
/* 807B0720 2C000003 */  cmpwi    r0, 3;
/* 807B0724 40820008 */  bne-     UNDEF_807b072c;
/* 807B0728 38E00001 */  li       r7, 1;
UNDEF_807b072c:;
/* 807B072C 3CC08035 */  lis      r6, mPlayerType__9daPyMng_c@ha;
/* 807B0730 3CA08035 */  lis      r5, mCreateItem__9daPyMng_c@ha;
/* 807B0734          */  li       r0, PLAYER_COUNT;
/* 807B0738 39000000 */  li       r8, 0;
/* 807B073C 38C65160 */  addi     r6, r6, mPlayerType__9daPyMng_c@l;
/* 807B0740 38A55180 */  addi     r5, r5, mCreateItem__9daPyMng_c@l;
/* 807B0744 7C0903A6 */  mtctr    r0;
UNDEF_807b0748:;
/* 807B0748 80060000 */  lwz      r0, 0(r6);
/* 807B074C 5400103A */  slwi     r0, r0, 2;
/* 807B0750 7C05002E */  lwzx     r0, r5, r0;
/* 807B0754 540007FF */  clrlwi.  r0, r0, 31;
/* 807B0758 40820050 */  bne-     UNDEF_807b07a8;
/* 807B075C 7C834214 */  add      r4, r3, r8;
/* 807B0760          */  lbz      r0, dStockItem_c_OFFSET_maPlayerPresent(r4);
/* 807B0764 2C000000 */  cmpwi    r0, 0;
/* 807B0768 41820040 */  beq-     UNDEF_807b07a8;
/* 807B076C 2C070000 */  cmpwi    r7, 0;
/* 807B0770 4182001C */  beq-     UNDEF_807b078c;
                         lwz      r3, 0x0(r6);
                         li       r4, 1;
                         bl       stockItemPlayStarVoice__F13PLAYER_TYPE_eb;
/* 807B0788 48000018 */  b        UNDEF_807b07a0;
UNDEF_807b078c:;
                         lwz      r3, 0x0(r6);
                         li       r4, 0;
                         bl       stockItemPlayStarVoice__F13PLAYER_TYPE_eb;
UNDEF_807b07a0:;
/* 807B07A0 38600001 */  li       r3, 1;
/* 807B07A4 48000118 */  b        UNDEF_807b08bc;
UNDEF_807b07a8:;
/* 807B07A8 38C60004 */  addi     r6, r6, 4;
/* 807B07AC 39080001 */  addi     r8, r8, 1;
/* 807B07B0 4200FF98 */  bdnz+    UNDEF_807b0748;
/* 807B07B4 48000104 */  b        UNDEF_807b08b8;
UNDEF_807b07b8:;
/* 807B07B8 3FA08035 */  lis      r29, mPlayerType__9daPyMng_c@ha;
/* 807B07BC 3FC08035 */  lis      r30, mCreateItem__9daPyMng_c@ha;
/* 807B07C0 3FE08035 */  lis      r31, mPlayerMode__9daPyMng_c@ha;
/* 807B07C4 3B400000 */  li       r26, 0;
/* 807B07C8 3BBD5160 */  addi     r29, r29, mPlayerType__9daPyMng_c@l;
/* 807B07CC 3BDE5180 */  addi     r30, r30, mCreateItem__9daPyMng_c@l;
/* 807B07D0 3BFF5170 */  addi     r31, r31, mPlayerMode__9daPyMng_c@l;
UNDEF_807b07d4:;
/* 807B07D4 801D0000 */  lwz      r0, 0(r29);
/* 807B07D8 7F63DB78 */  mr       r3, r27;
/* 807B07DC 38A10008 */  addi     r5, r1, 8;
/* 807B07E0 541C103A */  slwi     r28, r0, 2;
/* 807B07E4 7C1EE02E */  lwzx     r0, r30, r28;
/* 807B07E8 7C9FE02E */  lwzx     r4, r31, r28;
/* 807B07EC 540007FE */  clrlwi   r0, r0, 31;
/* 807B07F0 98010008 */  stb      r0, 8(r1);
/* 807B07F4 4B94C16D */  bl       UNDEF_800fc960;
/* 807B07F8 7C1FE02E */  lwzx     r0, r31, r28;
/* 807B07FC 7C030000 */  cmpw     r3, r0;
/* 807B0800 418200A8 */  beq-     UNDEF_807b08a8;
/* 807B0804 7C79D214 */  add      r3, r25, r26;
/* 807B0808          */  lbz      r0, dStockItem_c_OFFSET_maPlayerPresent(r3);
/* 807B080C 2C000000 */  cmpwi    r0, 0;
/* 807B0810 41820098 */  beq-     UNDEF_807b08a8;
/* 807B0814 80190328 */  lwz      r0, 808(r25);
/* 807B0818 28000001 */  cmplwi   r0, 1;
/* 807B081C 40810028 */  ble-     UNDEF_807b0844;
/* 807B0820 2C000003 */  cmpwi    r0, 3;
/* 807B0824 41820020 */  beq-     UNDEF_807b0844;
/* 807B0828 2C000002 */  cmpwi    r0, 2;
/* 807B082C 41820030 */  beq-     UNDEF_807b085c;
/* 807B0830 2C000004 */  cmpwi    r0, 4;
/* 807B0834 41820040 */  beq-     UNDEF_807b0874;
/* 807B0838 2C000005 */  cmpwi    r0, 5;
/* 807B083C 41820050 */  beq-     UNDEF_807b088c;
/* 807B0840 48000060 */  b        UNDEF_807b08a0;
UNDEF_807b0844:;
/* 807B0844 3C608043 */  lis      r3, sInstance__11SndAudioMgr@ha;
/* 807B0848 38800669 */  li       r4, 1641; // SE_PLY_CS_CHANGE_BIG
/* 807B084C 8063A768 */  lwz      r3, sInstance__11SndAudioMgr@l(r3);
/* 807B0850 38A00001 */  li       r5, 1;
/* 807B0854 4B9E4C6D */  bl       startSystemSe__11SndAudioMgrFUiUl;
/* 807B0858 48000048 */  b        UNDEF_807b08a0;
UNDEF_807b085c:;
/* 807B085C 3C608043 */  lis      r3, sInstance__11SndAudioMgr@ha;
/* 807B0860 3880066A */  li       r4, 1642; // SE_PLY_CS_CHANGE_PRPL
/* 807B0864 8063A768 */  lwz      r3, sInstance__11SndAudioMgr@l(r3);
/* 807B0868 38A00001 */  li       r5, 1;
/* 807B086C 4B9E4C55 */  bl       startSystemSe__11SndAudioMgrFUiUl;
/* 807B0870 48000030 */  b        UNDEF_807b08a0;
UNDEF_807b0874:;
/* 807B0874 3C608043 */  lis      r3, sInstance__11SndAudioMgr@ha;
/* 807B0878 3880066B */  li       r4, 1643; // SE_PLY_CS_CHANGE_PNGN
/* 807B087C 8063A768 */  lwz      r3, sInstance__11SndAudioMgr@l(r3);
/* 807B0880 38A00001 */  li       r5, 1;
/* 807B0884 4B9E4C3D */  bl       startSystemSe__11SndAudioMgrFUiUl;
/* 807B0888 48000018 */  b        UNDEF_807b08a0;
UNDEF_807b088c:;
/* 807B088C 3C608043 */  lis      r3, sInstance__11SndAudioMgr@ha;
/* 807B0890 3880066C */  li       r4, 1644; // SE_PLY_CS_CHANGE_MAME
/* 807B0894 8063A768 */  lwz      r3, sInstance__11SndAudioMgr@l(r3);
/* 807B0898 38A00001 */  li       r5, 1;
/* 807B089C 4B9E4C25 */  bl       startSystemSe__11SndAudioMgrFUiUl;
UNDEF_807b08a0:;
/* 807B08A0 38600001 */  li       r3, 1;
/* 807B08A4 48000018 */  b        UNDEF_807b08bc;
UNDEF_807b08a8:;
/* 807B08A8 3B5A0001 */  addi     r26, r26, 1;
/* 807B08AC 3BBD0004 */  addi     r29, r29, 4;
/* 807B08B0          */  cmpwi    r26, PLAYER_COUNT;
/* 807B08B4 4180FF20 */  blt+     UNDEF_807b07d4;
UNDEF_807b08b8:;
/* 807B08B8 38600000 */  li       r3, 0;
UNDEF_807b08bc:;
/* 807B08BC 39610030 */  addi     r11, r1, 48;
/* 807B08C0 4BB2C7E9 */  bl       UNDEF_802dd0a8;
/* 807B08C4 80010034 */  lwz      r0, 52(r1);
/* 807B08C8 7C0803A6 */  mtlr     r0;
/* 807B08CC 38210030 */  addi     r1, r1, 48;
/* 807B08D0 4E800020 */  blr;
  // clang-format on
);

[[address(0x807B09D0)]]
void dStockItem_c::executeState_WindowOpenInit() ASM_METHOD(
  // clang-format off
/* 807B09D0 9421FFE0 */  stwu     r1, -32(r1);
/* 807B09D4 7C0802A6 */  mflr     r0;
/* 807B09D8 90010024 */  stw      r0, 36(r1);
/* 807B09DC 39610020 */  addi     r11, r1, 32;
/* 807B09E0 4BB2C685 */  bl       UNDEF_802dd064;
/* 807B09E4 7C7F1B78 */  mr       r31, r3;
/* 807B09E8 4B91D369 */  bl       UNDEF_800cdd50; // getMesRes__10dMessage_cFv
/* 807B09EC 3C608043 */  lis      r3, m_instance__7dInfo_c@ha;
/* 807B09F0 3F808035 */  lis      r28, mPlayerType__9daPyMng_c@ha;
/* 807B09F4 8063A25C */  lwz      r3, m_instance__7dInfo_c@l(r3);
/* 807B09F8 3BA00001 */  li       r29, 1;
/* 807B09FC 3BC00000 */  li       r30, 0;
/* 807B0A00 3B9C5160 */  addi     r28, r28, mPlayerType__9daPyMng_c@l;
/* 807B0A04 9BA30AFC */  stb      r29, 2812(r3);
/* 807B0A08 3B600000 */  li       r27, 0;
/* 807B0A0C 93DF08B0 */  stw      r30, 2224(r31);
UNDEF_807b0a10:;
/* 807B0A10 7F63DB78 */  mr       r3, r27;
/* 807B0A14 4B903D4D */  bl       PlayerEnterCheck__8dGameComFi;
/* 807B0A18 2C030000 */  cmpwi    r3, 0;
/* 807B0A1C 41820038 */  beq-     UNDEF_807b0a54;
/* 807B0A20 7C7FDA14 */  add      r3, r31, r27;
/* 807B0A24          */  stb      r29, dStockItem_c_OFFSET_maPlayerPresent(r3);
/* 807B0A28 801C0000 */  lwz      r0, 0(r28);
/* 807B0A2C 5400103A */  slwi     r0, r0, 2;
/* 807B0A30 7C9F0214 */  add      r4, r31, r0;
/* 807B0A34          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r4);
/* 807B0A38 9BA30261 */  stb      r29, 609(r3);
/* 807B0A3C          */  lwz      r3, dStockItem_c_OFFSET_mpa2DPlayer(r4);
/* 807B0A40 9BA30267 */  stb      r29, 615(r3);
/* 807B0A44 807F08B0 */  lwz      r3, 2224(r31);
/* 807B0A48 38030001 */  addi     r0, r3, 1;
/* 807B0A4C 901F08B0 */  stw      r0, 2224(r31);
/* 807B0A50 4800000C */  b        UNDEF_807b0a5c;
UNDEF_807b0a54:;
/* 807B0A54 7C7FDA14 */  add      r3, r31, r27;
/* 807B0A58          */  stb      r30, dStockItem_c_OFFSET_maPlayerPresent(r3);
UNDEF_807b0a5c:;
/* 807B0A5C 3B7B0001 */  addi     r27, r27, 1;
/* 807B0A60 3B9C0004 */  addi     r28, r28, 4;
/* 807B0A64          */  cmpwi    r27, PLAYER_COUNT;
/* 807B0A68 4180FFA8 */  blt+     UNDEF_807b0a10;
/* 807B0A6C 7FFDFB78 */  mr       r29, r31;
/* 807B0A70 3B600000 */  li       r27, 0;
UNDEF_807b0a74:;
/* 807B0A74 809D08B4 */  lwz      r4, 2228(r29);
/* 807B0A78 7FE3FB78 */  mr       r3, r31;
/* 807B0A7C 7F65DB78 */  mr       r5, r27;
/* 807B0A80 4BFFF8C1 */  bl       UNDEF_807b0340;
/* 807B0A84 3B7B0001 */  addi     r27, r27, 1;
/* 807B0A88 3BBD0004 */  addi     r29, r29, 4;
/* 807B0A8C 2C1B0007 */  cmpwi    r27, 7;
/* 807B0A90 4180FFE4 */  blt+     UNDEF_807b0a74;
/* 807B0A94 819F020C */  lwz      r12, 524(r31);
/* 807B0A98 3C808099 */  lis      r4, UNDEF_80995828@ha;
/* 807B0A9C 387F020C */  addi     r3, r31, 524;
/* 807B0AA0 818C0018 */  lwz      r12, 24(r12);
/* 807B0AA4 38845828 */  addi     r4, r4, UNDEF_80995828@l;
/* 807B0AA8 7D8903A6 */  mtctr    r12;
/* 807B0AAC 4E800421 */  bctrl;
/* 807B0AB0 39610020 */  addi     r11, r1, 32;
/* 807B0AB4 4BB2C5FD */  bl       UNDEF_802dd0b0;
/* 807B0AB8 80010024 */  lwz      r0, 36(r1);
/* 807B0ABC 7C0803A6 */  mtlr     r0;
/* 807B0AC0 38210020 */  addi     r1, r1, 32;
/* 807B0AC4 4E800020 */  blr;
  // clang-format on
);

[[address(0x807B13C0)]]
void dStockItem_c::finalizeState_WindowCloseAnimeEndWait()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (maPlayerPresent[i]) {
            int type = static_cast<int>(daPyMng_c::mPlayerType[i]);
            mpa2DPlayer[type]->m0x269 = 1;
        }
    }

    for (int i = 0; i < std::size(mpaItem); i++) {
        daWmItem_c* item = mpaItem[i];

        item->mVisible = false;
        item->updateVisiblity();
    }

    mpShadow->m0x261 = 0;

    SndSceneMgr::sInstance->closeWindow();
}
