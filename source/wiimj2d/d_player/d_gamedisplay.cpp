// d_gamedisplay.cpp
// NSMBW .text: 0x80157820 - 0x8015A480

#include "d_gamedisplay.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_actorcreate_mng.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_multi_manager.h"
#include "d_system/d_pause_manager.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_stage_timer.h"
#include "framework/f_feature.h"
#include "machine/m_ef.h"
#include "machine/m_vec.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"
#include <algorithm>
#include <iterator>
#include <nw4r/lyt/Material.h>
#include <revolution/os.h>

[[nsmbw_data(0x8042A608)]]
dGameDisplay_c* dGameDisplay_c::m_instance;

[[nsmbw(0x80157820)]]
dGameDisplay_c* dGameDisplay_c_classInit()
{
    return new dGameDisplay_c();
}

#define X (*reinterpret_cast<dGameDisplay_c*>(0x1))

const long dGameDisplay_c::cPlayerPaneIndex[] = {
  std::distance(X.mpaPanes, &X.mpPane_MarioIcon),
  std::distance(X.mpaPanes, &X.mpPane_LuigiIcon),
  std::distance(X.mpaPanes, &X.mpPane_KinoBIcon),
  std::distance(X.mpaPanes, &X.mpPane_KinoYIcon),
  std::distance(X.mpaPanes, &X.mpPane_KinopicoIcon),
  std::distance(X.mpaPanes, &X.mpPane_Player05Icon),
  std::distance(X.mpaPanes, &X.mpPane_Player06Icon),
  std::distance(X.mpaPanes, &X.mpPane_Player07Icon),
};

const long dGameDisplay_c::cPlayerPictureIndex[] = {
  std::distance(X.mpaPictures, &X.mpPicture_MarioIcon),
  std::distance(X.mpaPictures, &X.mpPicture_LuigiIcon),
  std::distance(X.mpaPictures, &X.mpPicture_KinoBIcon),
  std::distance(X.mpaPictures, &X.mpPicture_KinoYIcon),
  std::distance(X.mpaPictures, &X.mpPicture_KinopicoIcon),
  std::distance(X.mpaPictures, &X.mpPicture_Player05Icon),
  std::distance(X.mpaPictures, &X.mpPicture_Player06Icon),
  std::distance(X.mpaPictures, &X.mpPicture_Player07Icon),
};

const long dGameDisplay_c::cPlayerTextboxIndex[] = {
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left00),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left01),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left02),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left03),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left04),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left05),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left06),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left07),
};

const long dGameDisplay_c::cPlayerBothTextboxIndex[][2] = {
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left00),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X01)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left01),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X02)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left02),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X03)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left03),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X04)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left04),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X05)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left05),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X06)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left06),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X07)},
  {std::distance(X.mpaTextBoxes, &X.mpTextBox_Left07),
   std::distance(X.mpaTextBoxes, &X.mpTextBox_X08)},
};

const long dGameDisplay_c::cPictureCollectionIndex[STAR_COIN_COUNT] = {
  std::distance(X.mpaPictures, &X.mpPicture_Collection00),
  std::distance(X.mpaPictures, &X.mpPicture_Collection01),
  std::distance(X.mpaPictures, &X.mpPicture_Collection02),
};

const long dGameDisplay_c::cPictureCollectOffIndex[STAR_COIN_COUNT] = {
  std::distance(X.mpaPictures, &X.mpPicture_CollectOff00),
  std::distance(X.mpaPictures, &X.mpPicture_CollectOff01),
  std::distance(X.mpaPictures, &X.mpPicture_CollectOff02),
};

const long dGameDisplay_c::cAreaPaneIndex[cAreaCheckCount] = {
  std::distance(X.mpaPanes, &X.mpPane_AreaZanki),
  std::distance(X.mpaPanes, &X.mpPane_AreaCoin),
  std::distance(X.mpaPanes, &X.mpPane_AreaScore),
};

#undef X

[[nsmbw(0x80157850)]]
dGameDisplay_c::dGameDisplay_c()
  : mStateMgr(*this, StateID_ProcMainGame)
  , mLayoutLoaded(false)
  , m0x452(true)
{
    for (std::size_t i = 0; i < std::size(mPlayNum); i++) {
        mPlayNum[i] = -1;
    }

    m_instance = this;
}

/* VT+0x08 */
[[nsmbw(0x80157AA0)]]
dGameDisplay_c::~dGameDisplay_c()
{
    dGameDisplay_c::m_instance = nullptr;
#ifndef __has_macintosh_dt_fix
    mEffect.~levelEffect_c();
    mDeathMsgMgr.~dDeathMsgMgr_c();
    mLayout.~LytBase_c();
#endif
}

[[nsmbw(0x80157B70)]]
fBase_c::PACK_RESULT_e dGameDisplay_c::create() ASM_METHOD(
  // clang-format off
/* 80157B70 9421FFC0 */  stwu     r1, -64(r1);
/* 80157B74 7C0802A6 */  mflr     r0;
/* 80157B78 90010044 */  stw      r0, 68(r1);
/* 80157B7C 39610040 */  addi     r11, r1, 64;
/* 80157B80 481854D1 */  bl       UNDEF_802dd050;
/* 80157B84 8803044B */  lbz      r0, 1099(r3);
/* 80157B88 7C781B78 */  mr       r24, r3;
/* 80157B8C 2C000000 */  cmpwi    r0, 0;
/* 80157B90 4182000C */  beq-     UNDEF_80157b9c;
/* 80157B94 38600001 */  li       r3, 1;
/* 80157B98 4800051C */  b        UNDEF_801580b4;
UNDEF_80157b9c:;
/* 80157B9C 48000C95 */  bl       UNDEF_80158830;
/* 80157BA0 2C030000 */  cmpwi    r3, 0;
/* 80157BA4 4082000C */  bne-     UNDEF_80157bb0;
/* 80157BA8 38600000 */  li       r3, 0;
/* 80157BAC 48000508 */  b        UNDEF_801580b4;
UNDEF_80157bb0:;
/* 80157BB0 3AC00000 */  li       r22, 0;
/* 80157BB4 3AE0FFFF */  li       r23, -1;
/* 80157BB8 38A00001 */  li       r5, 1;
/* 80157BBC 38600011 */  li       r3, 17;
/* 80157BC0 38000002 */  li       r0, 2;
/* 80157BC4 9878007C */  stb      r3, 124(r24);
/* 80157BC8 389803CC */  addi     r4, r24, 972;
/* 80157BCC 7F03C378 */  mr       r3, r24;
/* 80157BD0 92F803CC */  stw      r23, 972(r24);
/* 80157BD4 92D80424 */  stw      r22, 1060(r24);
/* 80157BD8 9AD80454 */  stb      r22, 1108(r24);
/* 80157BDC 92F803D0 */  stw      r23, 976(r24);
/* 80157BE0 92D80428 */  stw      r22, 1064(r24);
/* 80157BE4 9AD80455 */  stb      r22, 1109(r24);
/* 80157BE8 92F803D4 */  stw      r23, 980(r24);
/* 80157BEC 92D8042C */  stw      r22, 1068(r24);
/* 80157BF0 9AD80456 */  stb      r22, 1110(r24);
/* 80157BF4 92F803D8 */  stw      r23, 984(r24);
/* 80157BF8 92D80430 */  stw      r22, 1072(r24);
/* 80157BFC 9AD80457 */  stb      r22, 1111(r24);
/* 80157C00 90B803E8 */  stw      r5, 1000(r24);
/* 80157C04 90B803E4 */  stw      r5, 996(r24);
/* 80157C08 90B803DC */  stw      r5, 988(r24);
/* 80157C0C 92F803E0 */  stw      r23, 992(r24);
/* 80157C10 90180434 */  stw      r0, 1076(r24);
/* 80157C14 48001DAD */  bl       UNDEF_801599c0;
/* 80157C18 7F03C378 */  mr       r3, r24;
/* 80157C1C 38800000 */  li       r4, 0;
/* 80157C20 48001E81 */  bl       UNDEF_80159aa0;
/* 80157C24 7F03C378 */  mr       r3, r24;
/* 80157C28 38800000 */  li       r4, 0;
/* 80157C2C 48001FD5 */  bl       UNDEF_80159c00;
/* 80157C30 7F03C378 */  mr       r3, r24;
/* 80157C34 38800000 */  li       r4, 0;
/* 80157C38 480021B9 */  bl       UNDEF_80159df0;
/* 80157C3C C002AB40 */  lfs      f0, UNDEF_8042dea0@sda21;
/* 80157C40 3800001E */  li       r0, 30;
/* 80157C44 92D80438 */  stw      r22, 1080(r24);
/* 80157C48 7F03C378 */  mr       r3, r24;
/* 80157C4C 92D80440 */  stw      r22, 1088(r24);
/* 80157C50 92F803FC */  stw      r23, 1020(r24);
/* 80157C54 92F803F8 */  stw      r23, 1016(r24);
/* 80157C58 92D80444 */  stw      r22, 1092(r24);
/* 80157C5C 9AD80453 */  stb      r22, 1107(r24);
/* 80157C60 92D80400 */  stw      r22, 1024(r24);
/* 80157C64 90180404 */  stw      r0, 1028(r24);
/* 80157C68 90180408 */  stw      r0, 1032(r24);
/* 80157C6C 92D8040C */  stw      r22, 1036(r24);
/* 80157C70 92D8043C */  stw      r22, 1084(r24);
/* 80157C74 D0180540 */  stfs     f0, 1344(r24);
/* 80157C78 D018053C */  stfs     f0, 1340(r24);
/* 80157C7C D0180538 */  stfs     f0, 1336(r24);
/* 80157C80 48000A41 */  bl       UNDEF_801586c0;
/* 80157C84 7F03C378 */  mr       r3, r24;
/* 80157C88 48000939 */  bl       UNDEF_801585c0;
/* 80157C8C 38780070 */  addi     r3, r24, 112;
/* 80157C90 4BF71961 */  bl       UNDEF_800c95f0;
/* 80157C94 800DAB64 */  lwz      r0, UNDEF_8042a4e4@sda21;
/* 80157C98 2C000002 */  cmpwi    r0, 2;
/* 80157C9C 41820038 */  beq-     UNDEF_80157cd4;
/* 80157CA0 2C000003 */  cmpwi    r0, 3;
/* 80157CA4 41820030 */  beq-     UNDEF_80157cd4;
/* 80157CA8 800DAB80 */  lwz      r0, UNDEF_8042a500@sda21;
/* 80157CAC 2C000000 */  cmpwi    r0, 0;
/* 80157CB0 40820024 */  bne-     UNDEF_80157cd4;
/* 80157CB4 3C608031 */  lis      r3, UNDEF_80315e90@ha;
/* 80157CB8 38635E90 */  addi     r3, r3, UNDEF_80315e90@l;
/* 80157CBC 8803000D */  lbz      r0, 13(r3);
/* 80157CC0 28000028 */  cmplwi   r0, 40;
/* 80157CC4 41820010 */  beq-     UNDEF_80157cd4;
/* 80157CC8 880DAB7F */  lbz      r0, UNDEF_8042a4ff@sda21;
/* 80157CCC 2C000000 */  cmpwi    r0, 0;
/* 80157CD0 41820018 */  beq-     UNDEF_80157ce8;
UNDEF_80157cd4:;
/* 80157CD4 80780490 */  lwz      r3, 1168(r24);
/* 80157CD8 880300BB */  lbz      r0, 187(r3);
/* 80157CDC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157CE0 980300BB */  stb      r0, 187(r3);
/* 80157CE4 48000018 */  b        UNDEF_80157cfc;
UNDEF_80157ce8:;
/* 80157CE8 80780490 */  lwz      r3, 1168(r24);
/* 80157CEC 880300BB */  lbz      r0, 187(r3);
/* 80157CF0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157CF4 60000001 */  ori      r0, r0, 1;
/* 80157CF8 980300BB */  stb      r0, 187(r3);
UNDEF_80157cfc:;
/* 80157CFC 800DAB64 */  lwz      r0, UNDEF_8042a4e4@sda21;
/* 80157D00 2C000001 */  cmpwi    r0, 1;
/* 80157D04 4082001C */  bne-     UNDEF_80157d20;
/* 80157D08 807804E8 */  lwz      r3, 1256(r24);
/* 80157D0C 880300BB */  lbz      r0, 187(r3);
/* 80157D10 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157D14 60000001 */  ori      r0, r0, 1;
/* 80157D18 980300BB */  stb      r0, 187(r3);
/* 80157D1C 48000014 */  b        UNDEF_80157d30;
UNDEF_80157d20:;
/* 80157D20 807804E8 */  lwz      r3, 1256(r24);
/* 80157D24 880300BB */  lbz      r0, 187(r3);
/* 80157D28 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157D2C 980300BB */  stb      r0, 187(r3);
UNDEF_80157d30:;
/* 80157D30 880DA942 */  lbz      r0, UNDEF_8042a2c2@sda21;
/* 80157D34 2C000000 */  cmpwi    r0, 0;
/* 80157D38 41820044 */  beq-     UNDEF_80157d7c;
/* 80157D3C 38000001 */  li       r0, 1;
/* 80157D40 98180448 */  stb      r0, 1096(r24);
/* 80157D44 80D804EC */  lwz      r6, 1260(r24);
/* 80157D48 38780070 */  addi     r3, r24, 112;
/* 80157D4C 38800000 */  li       r4, 0;
/* 80157D50 38A00000 */  li       r5, 0;
/* 80157D54 880600BB */  lbz      r0, 187(r6);
/* 80157D58 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157D5C 60000001 */  ori      r0, r0, 1;
/* 80157D60 980600BB */  stb      r0, 187(r6);
/* 80157D64 80D804F0 */  lwz      r6, 1264(r24);
/* 80157D68 880600BB */  lbz      r0, 187(r6);
/* 80157D6C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157D70 980600BB */  stb      r0, 187(r6);
/* 80157D74 4BF7174D */  bl       UNDEF_800c94c0;
/* 80157D78 48000030 */  b        UNDEF_80157da8;
UNDEF_80157d7c:;
/* 80157D7C 38000000 */  li       r0, 0;
/* 80157D80 98180448 */  stb      r0, 1096(r24);
/* 80157D84 807804EC */  lwz      r3, 1260(r24);
/* 80157D88 880300BB */  lbz      r0, 187(r3);
/* 80157D8C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157D90 980300BB */  stb      r0, 187(r3);
/* 80157D94 807804F0 */  lwz      r3, 1264(r24);
/* 80157D98 880300BB */  lbz      r0, 187(r3);
/* 80157D9C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157DA0 60000001 */  ori      r0, r0, 1;
/* 80157DA4 980300BB */  stb      r0, 187(r3);
UNDEF_80157da8:;
/* 80157DA8 3C608031 */  lis      r3, UNDEF_80315e90@ha;
/* 80157DAC 38635E90 */  addi     r3, r3, UNDEF_80315e90@l;
/* 80157DB0 8803000D */  lbz      r0, 13(r3);
/* 80157DB4 28000023 */  cmplwi   r0, 35;
/* 80157DB8 40820038 */  bne-     UNDEF_80157df0;
/* 80157DBC 807804F8 */  lwz      r3, 1272(r24);
/* 80157DC0 880300BB */  lbz      r0, 187(r3);
/* 80157DC4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157DC8 980300BB */  stb      r0, 187(r3);
/* 80157DCC 807804FC */  lwz      r3, 1276(r24);
/* 80157DD0 880300BB */  lbz      r0, 187(r3);
/* 80157DD4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157DD8 980300BB */  stb      r0, 187(r3);
/* 80157DDC 80780520 */  lwz      r3, 1312(r24);
/* 80157DE0 880300BB */  lbz      r0, 187(r3);
/* 80157DE4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157DE8 980300BB */  stb      r0, 187(r3);
/* 80157DEC 48000040 */  b        UNDEF_80157e2c;
UNDEF_80157df0:;
/* 80157DF0 807804F8 */  lwz      r3, 1272(r24);
/* 80157DF4 880300BB */  lbz      r0, 187(r3);
/* 80157DF8 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157DFC 60000001 */  ori      r0, r0, 1;
/* 80157E00 980300BB */  stb      r0, 187(r3);
/* 80157E04 807804FC */  lwz      r3, 1276(r24);
/* 80157E08 880300BB */  lbz      r0, 187(r3);
/* 80157E0C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157E10 60000001 */  ori      r0, r0, 1;
/* 80157E14 980300BB */  stb      r0, 187(r3);
/* 80157E18 80780520 */  lwz      r3, 1312(r24);
/* 80157E1C 880300BB */  lbz      r0, 187(r3);
/* 80157E20 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157E24 60000001 */  ori      r0, r0, 1;
/* 80157E28 980300BB */  stb      r0, 187(r3);
UNDEF_80157e2c:;
/* 80157E2C 800DA8E0 */  lwz      r0, UNDEF_8042a260@sda21;
/* 80157E30 54000673 */  rlwinm.  r0, r0, 0, 25, 25;
/* 80157E34 41820014 */  beq-     UNDEF_80157e48;
/* 80157E38 807804FC */  lwz      r3, 1276(r24);
/* 80157E3C 880300BB */  lbz      r0, 187(r3);
/* 80157E40 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157E44 980300BB */  stb      r0, 187(r3);
UNDEF_80157e48:;
/* 80157E48 806DA9A0 */  lwz      r3, UNDEF_8042a320@sda21;
/* 80157E4C 3880FFFF */  li       r4, -1;
/* 80157E50 4BF88621 */  bl       UNDEF_800e0470;
/* 80157E54 3C808031 */  lis      r4, UNDEF_80315e90@ha;
/* 80157E58 7C7C1B78 */  mr       r28, r3;
/* 80157E5C 38845E90 */  addi     r4, r4, UNDEF_80315e90@l;
/* 80157E60 8B64000C */  lbz      r27, 12(r4);
/* 80157E64 8B44000D */  lbz      r26, 13(r4);
/* 80157E68 281B0009 */  cmplwi   r27, 9;
/* 80157E6C 40810008 */  ble-     UNDEF_80157e74;
/* 80157E70 3B600000 */  li       r27, 0;
UNDEF_80157e74:;
/* 80157E74 281A0029 */  cmplwi   r26, 41;
/* 80157E78 40810008 */  ble-     UNDEF_80157e80;
/* 80157E7C 3B400000 */  li       r26, 0;
UNDEF_80157e80:;
/* 80157E80 806DA8E0 */  lwz      r3, UNDEF_8042a260@sda21;
/* 80157E84 546006F7 */  rlwinm.  r0, r3, 0, 27, 27;
/* 80157E88 40820034 */  bne-     UNDEF_80157ebc;
/* 80157E8C 54600001 */  clrrwi.  r0, r3, 31;
/* 80157E90 4082002C */  bne-     UNDEF_80157ebc;
/* 80157E94 7F63DB78 */  mr       r3, r27;
/* 80157E98 7F44D378 */  mr       r4, r26;
/* 80157E9C 38A00002 */  li       r5, 2;
/* 80157EA0 4BFAA9C1 */  bl       UNDEF_80102860;
/* 80157EA4 2C030000 */  cmpwi    r3, 0;
/* 80157EA8 40820014 */  bne-     UNDEF_80157ebc;
/* 80157EAC 807804F8 */  lwz      r3, 1272(r24);
/* 80157EB0 880300BB */  lbz      r0, 187(r3);
/* 80157EB4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157EB8 980300BB */  stb      r0, 187(r3);
UNDEF_80157ebc:;
/* 80157EBC 3FA08037 */  lis      r29, UNDEF_803744b0@ha;
/* 80157EC0 7F1EC378 */  mr       r30, r24;
/* 80157EC4 3BBD44B0 */  addi     r29, r29, UNDEF_803744b0@l;
/* 80157EC8 3B200000 */  li       r25, 0;
/* 80157ECC 3AE00000 */  li       r23, 0;
/* 80157ED0 3BE00003 */  li       r31, 3;
/* 80157ED4 3AC00002 */  li       r22, 2;
UNDEF_80157ed8:;
/* 80157ED8 93FE03EC */  stw      r31, 1004(r30);
/* 80157EDC 801D0000 */  lwz      r0, 0(r29);
/* 80157EE0 2C000004 */  cmpwi    r0, 4;
/* 80157EE4 40820020 */  bne-     UNDEF_80157f04;
/* 80157EE8 7F83E378 */  mr       r3, r28;
/* 80157EEC 7F64DB78 */  mr       r4, r27;
/* 80157EF0 7F45D378 */  mr       r5, r26;
/* 80157EF4 7F26CB78 */  mr       r6, r25;
/* 80157EF8 4BF76409 */  bl       UNDEF_800ce300;
/* 80157EFC 5460063F */  clrlwi.  r0, r3, 24;
/* 80157F00 41820030 */  beq-     UNDEF_80157f30;
UNDEF_80157f04:;
/* 80157F04 7C98BA14 */  add      r4, r24, r23;
/* 80157F08 80640494 */  lwz      r3, 1172(r4);
/* 80157F0C 880300BB */  lbz      r0, 187(r3);
/* 80157F10 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157F14 980300BB */  stb      r0, 187(r3);
/* 80157F18 80640498 */  lwz      r3, 1176(r4);
/* 80157F1C 880300BB */  lbz      r0, 187(r3);
/* 80157F20 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80157F24 60000001 */  ori      r0, r0, 1;
/* 80157F28 980300BB */  stb      r0, 187(r3);
/* 80157F2C 92DE03EC */  stw      r22, 1004(r30);
UNDEF_80157f30:;
/* 80157F30 3B390001 */  addi     r25, r25, 1;
/* 80157F34 3BBD0004 */  addi     r29, r29, 4;
/* 80157F38 28190003 */  cmplwi   r25, 3;
/* 80157F3C 3AF70008 */  addi     r23, r23, 8;
/* 80157F40 3BDE0004 */  addi     r30, r30, 4;
/* 80157F44 4180FF94 */  blt+     UNDEF_80157ed8;
/* 80157F48 38610008 */  addi     r3, r1, 8;
/* 80157F4C 4BF5D1F5 */  bl       UNDEF_800b5140;
/* 80157F50 80980524 */  lwz      r4, 1316(r24);
/* 80157F54 7F03C378 */  mr       r3, r24;
/* 80157F58 C0010008 */  lfs      f0, 8(r1);
/* 80157F5C D0040044 */  stfs     f0, 68(r4);
/* 80157F60 C001000C */  lfs      f0, 12(r1);
/* 80157F64 D0040048 */  stfs     f0, 72(r4);
/* 80157F68 80980528 */  lwz      r4, 1320(r24);
/* 80157F6C C0010008 */  lfs      f0, 8(r1);
/* 80157F70 D0040044 */  stfs     f0, 68(r4);
/* 80157F74 C001000C */  lfs      f0, 12(r1);
/* 80157F78 D0040048 */  stfs     f0, 72(r4);
/* 80157F7C 80B80524 */  lwz      r5, 1316(r24);
/* 80157F80 80980528 */  lwz      r4, 1320(r24);
/* 80157F84 C005002C */  lfs      f0, 44(r5);
/* 80157F88 D0180544 */  stfs     f0, 1348(r24);
/* 80157F8C 813804EC */  lwz      r9, 1260(r24);
/* 80157F90 C0050030 */  lfs      f0, 48(r5);
/* 80157F94 D0180548 */  stfs     f0, 1352(r24);
/* 80157F98 81180500 */  lwz      r8, 1280(r24);
/* 80157F9C C0050034 */  lfs      f0, 52(r5);
/* 80157FA0 D018054C */  stfs     f0, 1356(r24);
/* 80157FA4 80F804E8 */  lwz      r7, 1256(r24);
/* 80157FA8 C004002C */  lfs      f0, 44(r4);
/* 80157FAC D0180550 */  stfs     f0, 1360(r24);
/* 80157FB0 80D80504 */  lwz      r6, 1284(r24);
/* 80157FB4 C0040030 */  lfs      f0, 48(r4);
/* 80157FB8 D0180554 */  stfs     f0, 1364(r24);
/* 80157FBC 80B80508 */  lwz      r5, 1288(r24);
/* 80157FC0 C0040034 */  lfs      f0, 52(r4);
/* 80157FC4 D0180558 */  stfs     f0, 1368(r24);
/* 80157FC8 80980520 */  lwz      r4, 1312(r24);
/* 80157FCC C009002C */  lfs      f0, 44(r9);
/* 80157FD0 D018055C */  stfs     f0, 1372(r24);
/* 80157FD4 C0090030 */  lfs      f0, 48(r9);
/* 80157FD8 D0180560 */  stfs     f0, 1376(r24);
/* 80157FDC C0090034 */  lfs      f0, 52(r9);
/* 80157FE0 D0180564 */  stfs     f0, 1380(r24);
/* 80157FE4 C008002C */  lfs      f0, 44(r8);
/* 80157FE8 D0180568 */  stfs     f0, 1384(r24);
/* 80157FEC C0080030 */  lfs      f0, 48(r8);
/* 80157FF0 D018056C */  stfs     f0, 1388(r24);
/* 80157FF4 C0080034 */  lfs      f0, 52(r8);
/* 80157FF8 D0180570 */  stfs     f0, 1392(r24);
/* 80157FFC C007002C */  lfs      f0, 44(r7);
/* 80158000 D0180574 */  stfs     f0, 1396(r24);
/* 80158004 C0070030 */  lfs      f0, 48(r7);
/* 80158008 D0180578 */  stfs     f0, 1400(r24);
/* 8015800C C0070034 */  lfs      f0, 52(r7);
/* 80158010 D018057C */  stfs     f0, 1404(r24);
/* 80158014 C006002C */  lfs      f0, 44(r6);
/* 80158018 D0180580 */  stfs     f0, 1408(r24);
/* 8015801C C0060030 */  lfs      f0, 48(r6);
/* 80158020 D0180584 */  stfs     f0, 1412(r24);
/* 80158024 C0060034 */  lfs      f0, 52(r6);
/* 80158028 D0180588 */  stfs     f0, 1416(r24);
/* 8015802C C005002C */  lfs      f0, 44(r5);
/* 80158030 D018058C */  stfs     f0, 1420(r24);
/* 80158034 C0050030 */  lfs      f0, 48(r5);
/* 80158038 D0180590 */  stfs     f0, 1424(r24);
/* 8015803C C0050034 */  lfs      f0, 52(r5);
/* 80158040 D0180594 */  stfs     f0, 1428(r24);
/* 80158044 C004002C */  lfs      f0, 44(r4);
/* 80158048 D0180598 */  stfs     f0, 1432(r24);
/* 8015804C C0040030 */  lfs      f0, 48(r4);
/* 80158050 D018059C */  stfs     f0, 1436(r24);
/* 80158054 C0040034 */  lfs      f0, 52(r4);
/* 80158058 D01805A0 */  stfs     f0, 1440(r24);
/* 8015805C 480001E5 */  bl       UNDEF_80158240;
/* 80158060 38A00000 */  li       r5, 0;
/* 80158064 380000FF */  li       r0, 255;
/* 80158068 38800001 */  li       r4, 1;
/* 8015806C 98B80449 */  stb      r5, 1097(r24);
/* 80158070 38780070 */  addi     r3, r24, 112;
/* 80158074 98B8044A */  stb      r5, 1098(r24);
/* 80158078 9898044B */  stb      r4, 1099(r24);
/* 8015807C 98B8044C */  stb      r5, 1100(r24);
/* 80158080 90180418 */  stw      r0, 1048(r24);
/* 80158084 98B8044D */  stb      r5, 1101(r24);
/* 80158088 9018041C */  stw      r0, 1052(r24);
/* 8015808C 98B8044E */  stb      r5, 1102(r24);
/* 80158090 90180420 */  stw      r0, 1056(r24);
/* 80158094 98B8044F */  stb      r5, 1103(r24);
/* 80158098 98B80450 */  stb      r5, 1104(r24);
/* 8015809C 98B80451 */  stb      r5, 1105(r24);
/* 801580A0 81980078 */  lwz      r12, 120(r24);
/* 801580A4 818C0010 */  lwz      r12, 16(r12);
/* 801580A8 7D8903A6 */  mtctr    r12;
/* 801580AC 4E800421 */  bctrl;
/* 801580B0 38600001 */  li       r3, 1;
UNDEF_801580b4:;
/* 801580B4 39610040 */  addi     r11, r1, 64;
/* 801580B8 48184FE5 */  bl       UNDEF_802dd09c;
/* 801580BC 80010044 */  lwz      r0, 68(r1);
/* 801580C0 7C0803A6 */  mtlr     r0;
/* 801580C4 38210040 */  addi     r1, r1, 64;
/* 801580C8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x801580D0)]]
fBase_c::PACK_RESULT_e dGameDisplay_c::execute() ASM_METHOD(
  // clang-format off
/* 801580D0 9421FFF0 */  stwu     r1, -16(r1);
/* 801580D4 7C0802A6 */  mflr     r0;
/* 801580D8 90010014 */  stw      r0, 20(r1);
/* 801580DC 93E1000C */  stw      r31, 12(r1);
/* 801580E0 7C7F1B78 */  mr       r31, r3;
/* 801580E4 8803044B */  lbz      r0, 1099(r3);
/* 801580E8 2C000000 */  cmpwi    r0, 0;
/* 801580EC 418200C4 */  beq-     UNDEF_801581b0;
/* 801580F0 480008E1 */  bl       UNDEF_801589d0;
/* 801580F4 819F0390 */  lwz      r12, 912(r31);
/* 801580F8 387F0390 */  addi     r3, r31, 912;
/* 801580FC 818C0010 */  lwz      r12, 16(r12);
/* 80158100 7D8903A6 */  mtctr    r12;
/* 80158104 4E800421 */  bctrl;
/* 80158108 387F0070 */  addi     r3, r31, 112;
/* 8015810C 4BF71625 */  bl       UNDEF_800c9730;
/* 80158110 2C030000 */  cmpwi    r3, 0;
/* 80158114 4082001C */  bne-     UNDEF_80158130;
/* 80158118 881F0450 */  lbz      r0, 1104(r31);
/* 8015811C 2C000000 */  cmpwi    r0, 0;
/* 80158120 40820010 */  bne-     UNDEF_80158130;
/* 80158124 881F0451 */  lbz      r0, 1105(r31);
/* 80158128 2C000000 */  cmpwi    r0, 0;
/* 8015812C 41820020 */  beq-     UNDEF_8015814c;
UNDEF_80158130:;
/* 80158130 387F0070 */  addi     r3, r31, 112;
/* 80158134 4BF7151D */  bl       UNDEF_800c9650;
/* 80158138 819F0078 */  lwz      r12, 120(r31);
/* 8015813C 387F0070 */  addi     r3, r31, 112;
/* 80158140 818C0010 */  lwz      r12, 16(r12);
/* 80158144 7D8903A6 */  mtctr    r12;
/* 80158148 4E800421 */  bctrl;
UNDEF_8015814c:;
/* 8015814C 7FE3FB78 */  mr       r3, r31;
/* 80158150 48000901 */  bl       UNDEF_80158a50;
/* 80158154 7FE3FB78 */  mr       r3, r31;
/* 80158158 48000A79 */  bl       UNDEF_80158bd0;

                         mr       r3, r31;
                         bl       DecEffectTimers__14dGameDisplay_cFv;

UNDEF_801581b0:;
/* 801581B0 83E1000C */  lwz      r31, 12(r1);
/* 801581B4 38600001 */  li       r3, 1;
/* 801581B8 80010014 */  lwz      r0, 20(r1);
/* 801581BC 7C0803A6 */  mtlr     r0;
/* 801581C0 38210010 */  addi     r1, r1, 16;
/* 801581C4 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x801581E0)]]
fBase_c::PACK_RESULT_e dGameDisplay_c::draw()
{
    if (m0x452 && mLayoutLoaded) {
        if (fFeat::death_messages != fFeat::DEATH_MESSAGES_MODE_e::DISABLED) {
            mDeathMsgMgr.entry();
        }
        mLayout.entry();
    }

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80158230)]]
fBase_c::PACK_RESULT_e dGameDisplay_c::doDelete();

[[nsmbw(0x80158240)]]
void dGameDisplay_c::OtehonPosChange() ASM_METHOD(
  // clang-format off
/* 80158240 9421FFE0 */  stwu     r1, -32(r1);
/* 80158244 7C0802A6 */  mflr     r0;
/* 80158248 90010024 */  stw      r0, 36(r1);
/* 8015824C 800DAB64 */  lwz      r0, UNDEF_8042a4e4@sda21;
/* 80158250 2C000004 */  cmpwi    r0, 4;
/* 80158254 40820180 */  bne-     UNDEF_801583d4;
/* 80158258 C022AB40 */  lfs      f1, UNDEF_8042dea0@sda21;
/* 8015825C C0C2AB44 */  lfs      f6, UNDEF_8042dea4@sda21;
/* 80158260 C0830548 */  lfs      f4, 1352(r3);
/* 80158264 ECE1302A */  fadds    f7, f1, f6;
/* 80158268 C0A30544 */  lfs      f5, 1348(r3);
/* 8015826C C063054C */  lfs      f3, 1356(r3);
/* 80158270 EC81202A */  fadds    f4, f1, f4;
/* 80158274 80830524 */  lwz      r4, 1316(r3);
/* 80158278 ECC13028 */  fsubs    f6, f1, f6;
/* 8015827C ECA7282A */  fadds    f5, f7, f5;
/* 80158280 C042AB48 */  lfs      f2, UNDEF_8042dea8@sda21;
/* 80158284 EC61182A */  fadds    f3, f1, f3;
/* 80158288 D0A4002C */  stfs     f5, 44(r4);
/* 8015828C EC011028 */  fsubs    f0, f1, f2;
/* 80158290 ECA1102A */  fadds    f5, f1, f2;
/* 80158294 D0840030 */  stfs     f4, 48(r4);
/* 80158298 D0640034 */  stfs     f3, 52(r4);
/* 8015829C C0830550 */  lfs      f4, 1360(r3);
/* 801582A0 C0630554 */  lfs      f3, 1364(r3);
/* 801582A4 C0430558 */  lfs      f2, 1368(r3);
/* 801582A8 EC86202A */  fadds    f4, f6, f4;
/* 801582AC 80830528 */  lwz      r4, 1320(r3);
/* 801582B0 EC61182A */  fadds    f3, f1, f3;
/* 801582B4 EC41102A */  fadds    f2, f1, f2;
/* 801582B8 D084002C */  stfs     f4, 44(r4);
/* 801582BC D0640030 */  stfs     f3, 48(r4);
/* 801582C0 D0440034 */  stfs     f2, 52(r4);
/* 801582C4 C083055C */  lfs      f4, 1372(r3);
/* 801582C8 C0630560 */  lfs      f3, 1376(r3);
/* 801582CC C0430564 */  lfs      f2, 1380(r3);
/* 801582D0 EC81202A */  fadds    f4, f1, f4;
/* 801582D4 808304EC */  lwz      r4, 1260(r3);
/* 801582D8 EC60182A */  fadds    f3, f0, f3;
/* 801582DC EC41102A */  fadds    f2, f1, f2;
/* 801582E0 D084002C */  stfs     f4, 44(r4);
/* 801582E4 D0640030 */  stfs     f3, 48(r4);
/* 801582E8 D0440034 */  stfs     f2, 52(r4);
/* 801582EC C0830568 */  lfs      f4, 1384(r3);
/* 801582F0 C063056C */  lfs      f3, 1388(r3);
/* 801582F4 C0430570 */  lfs      f2, 1392(r3);
/* 801582F8 EC81202A */  fadds    f4, f1, f4;
/* 801582FC 80830500 */  lwz      r4, 1280(r3);
/* 80158300 EC60182A */  fadds    f3, f0, f3;
/* 80158304 EC41102A */  fadds    f2, f1, f2;
/* 80158308 D084002C */  stfs     f4, 44(r4);
/* 8015830C D0640030 */  stfs     f3, 48(r4);
/* 80158310 D0440034 */  stfs     f2, 52(r4);
/* 80158314 C0830574 */  lfs      f4, 1396(r3);
/* 80158318 C0630578 */  lfs      f3, 1400(r3);
/* 8015831C C043057C */  lfs      f2, 1404(r3);
/* 80158320 EC81202A */  fadds    f4, f1, f4;
/* 80158324 808304E8 */  lwz      r4, 1256(r3);
/* 80158328 EC65182A */  fadds    f3, f5, f3;
/* 8015832C EC41102A */  fadds    f2, f1, f2;
/* 80158330 D084002C */  stfs     f4, 44(r4);
/* 80158334 D0640030 */  stfs     f3, 48(r4);
/* 80158338 D0440034 */  stfs     f2, 52(r4);
/* 8015833C C0830580 */  lfs      f4, 1408(r3);
/* 80158340 C0630584 */  lfs      f3, 1412(r3);
/* 80158344 C0430588 */  lfs      f2, 1416(r3);
/* 80158348 EC81202A */  fadds    f4, f1, f4;
/* 8015834C 80830504 */  lwz      r4, 1284(r3);
/* 80158350 EC60182A */  fadds    f3, f0, f3;
/* 80158354 EC41102A */  fadds    f2, f1, f2;
/* 80158358 D084002C */  stfs     f4, 44(r4);
/* 8015835C D0640030 */  stfs     f3, 48(r4);
/* 80158360 D0440034 */  stfs     f2, 52(r4);
/* 80158364 C083058C */  lfs      f4, 1420(r3);
/* 80158368 C0630590 */  lfs      f3, 1424(r3);
/* 8015836C C0430594 */  lfs      f2, 1428(r3);
/* 80158370 EC81202A */  fadds    f4, f1, f4;
/* 80158374 80830508 */  lwz      r4, 1288(r3);
/* 80158378 EC60182A */  fadds    f3, f0, f3;
/* 8015837C EC41102A */  fadds    f2, f1, f2;
/* 80158380 D084002C */  stfs     f4, 44(r4);
/* 80158384 D0640030 */  stfs     f3, 48(r4);
/* 80158388 D0440034 */  stfs     f2, 52(r4);
/* 8015838C C0430598 */  lfs      f2, 1432(r3);
/* 80158390 C063059C */  lfs      f3, 1436(r3);
/* 80158394 EC81102A */  fadds    f4, f1, f2;
/* 80158398 C04305A0 */  lfs      f2, 1440(r3);
/* 8015839C EC60182A */  fadds    f3, f0, f3;
/* 801583A0 80830520 */  lwz      r4, 1312(r3);
/* 801583A4 EC01102A */  fadds    f0, f1, f2;
/* 801583A8 D0810008 */  stfs     f4, 8(r1);
/* 801583AC D084002C */  stfs     f4, 44(r4);
/* 801583B0 D0640030 */  stfs     f3, 48(r4);
/* 801583B4 D0040034 */  stfs     f0, 52(r4);
/* 801583B8 81830078 */  lwz      r12, 120(r3);
/* 801583BC D061000C */  stfs     f3, 12(r1);
/* 801583C0 818C0010 */  lwz      r12, 16(r12);
/* 801583C4 D0010010 */  stfs     f0, 16(r1);
/* 801583C8 7D8903A6 */  mtctr    r12;
/* 801583CC 38630070 */  addi     r3, r3, 112;
/* 801583D0 4E800421 */  bctrl;
UNDEF_801583d4:;
/* 801583D4 80010024 */  lwz      r0, 36(r1);
/* 801583D8 7C0803A6 */  mtlr     r0;
/* 801583DC 38210020 */  addi     r1, r1, 32;
/* 801583E0 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x801583F0)]]
void dGameDisplay_c::AreaSetup(int area, int paneIndex) ASM_METHOD(
  // clang-format off
/* 801583F0 9421FFB0 */  stwu     r1, -80(r1);
/* 801583F4 54A0103A */  slwi     r0, r5, 2;
/* 801583F8 54852036 */  slwi     r5, r4, 4;
/* 801583FC 3C805555 */  lis      r4, 21845;
/* 80158400 93E1004C */  stw      r31, 76(r1);
/* 80158404 7CA32A14 */  add      r5, r3, r5;
/* 80158408 93C10048 */  stw      r30, 72(r1);
/* 8015840C 93A10044 */  stw      r29, 68(r1);
/* 80158410 7FA30214 */  add      r29, r3, r0;
/* 80158414 38045556 */  addi     r0, r4, 21846;
/* 80158418 93810040 */  stw      r28, 64(r1);
/* 8015841C 80DD04E8 */  lwz      r6, 1256(r29);
/* 80158420 80660090 */  lwz      r3, 144(r6);
/* 80158424 9061001C */  stw      r3, 28(r1);
/* 80158428 80860084 */  lwz      r4, 132(r6);
/* 8015842C 83C60088 */  lwz      r30, 136(r6);
/* 80158430 83E6008C */  lwz      r31, 140(r6);
/* 80158434 81860094 */  lwz      r12, 148(r6);
/* 80158438 81660098 */  lwz      r11, 152(r6);
/* 8015843C 8146009C */  lwz      r10, 156(r6);
/* 80158440 806600A0 */  lwz      r3, 160(r6);
/* 80158444 812600A4 */  lwz      r9, 164(r6);
/* 80158448 810600A8 */  lwz      r8, 168(r6);
/* 8015844C 80E600AC */  lwz      r7, 172(r6);
/* 80158450 80C600B0 */  lwz      r6, 176(r6);
/* 80158454 C021001C */  lfs      f1, 28(r1);
/* 80158458 9061002C */  stw      r3, 44(r1);
/* 8015845C D0250460 */  stfs     f1, 1120(r5);
/* 80158460 C001002C */  lfs      f0, 44(r1);
/* 80158464 D0250464 */  stfs     f1, 1124(r5);
/* 80158468 D0050458 */  stfs     f0, 1112(r5);
/* 8015846C D005045C */  stfs     f0, 1116(r5);
/* 80158470 839D04E8 */  lwz      r28, 1256(r29);
/* 80158474 90810010 */  stw      r4, 16(r1);
/* 80158478 889C00BA */  lbz      r4, 186(r28);
/* 8015847C C05C004C */  lfs      f2, 76(r28);
/* 80158480 7C602096 */  mulhw    r3, r0, r4;
/* 80158484 C01C0050 */  lfs      f0, 80(r28);
/* 80158488 93C10014 */  stw      r30, 20(r1);
/* 8015848C 93E10018 */  stw      r31, 24(r1);
/* 80158490 54600FFE */  srwi     r0, r3, 31;
/* 80158494 91810020 */  stw      r12, 32(r1);
/* 80158498 7C030214 */  add      r0, r3, r0;
/* 8015849C 1C000003 */  mulli    r0, r0, 3;
/* 801584A0 91610024 */  stw      r11, 36(r1);
/* 801584A4 91410028 */  stw      r10, 40(r1);
/* 801584A8 7C002050 */  sub      r0, r4, r0;
/* 801584AC 5400063F */  clrlwi.  r0, r0, 24;
/* 801584B0 91210030 */  stw      r9, 48(r1);
/* 801584B4 91010034 */  stw      r8, 52(r1);
/* 801584B8 90E10038 */  stw      r7, 56(r1);
/* 801584BC 90C1003C */  stw      r6, 60(r1);
/* 801584C0 D0410008 */  stfs     f2, 8(r1);
/* 801584C4 D001000C */  stfs     f0, 12(r1);
/* 801584C8 41820018 */  beq-     UNDEF_801584e0;
/* 801584CC 2C000001 */  cmpwi    r0, 1;
/* 801584D0 41820020 */  beq-     UNDEF_801584f0;
/* 801584D4 2C000002 */  cmpwi    r0, 2;
/* 801584D8 4182003C */  beq-     UNDEF_80158514;
/* 801584DC 48000044 */  b        UNDEF_80158520;
UNDEF_801584e0:;
/* 801584E0 C0050464 */  lfs      f0, 1124(r5);
/* 801584E4 EC00102A */  fadds    f0, f0, f2;
/* 801584E8 D0050464 */  stfs     f0, 1124(r5);
/* 801584EC 48000034 */  b        UNDEF_80158520;
UNDEF_801584f0:;
/* 801584F0 C022AB4C */  lfs      f1, UNDEF_8042deac@sda21;
/* 801584F4 C0050460 */  lfs      f0, 1120(r5);
/* 801584F8 EC220072 */  fmuls    f1, f2, f1;
/* 801584FC EC000828 */  fsubs    f0, f0, f1;
/* 80158500 D0050460 */  stfs     f0, 1120(r5);
/* 80158504 C0050464 */  lfs      f0, 1124(r5);
/* 80158508 EC00082A */  fadds    f0, f0, f1;
/* 8015850C D0050464 */  stfs     f0, 1124(r5);
/* 80158510 48000010 */  b        UNDEF_80158520;
UNDEF_80158514:;
/* 80158514 C0050460 */  lfs      f0, 1120(r5);
/* 80158518 EC001028 */  fsubs    f0, f0, f2;
/* 8015851C D0050460 */  stfs     f0, 1120(r5);
UNDEF_80158520:;
/* 80158520 809D04E8 */  lwz      r4, 1256(r29);
/* 80158524 3C605555 */  lis      r3, 21845;
/* 80158528 38635556 */  addi     r3, r3, 21846;
/* 8015852C C041000C */  lfs      f2, 12(r1);
/* 80158530 880400BA */  lbz      r0, 186(r4);
/* 80158534 7C630096 */  mulhw    r3, r3, r0;
/* 80158538 54600FFE */  srwi     r0, r3, 31;
/* 8015853C 7C030214 */  add      r0, r3, r0;
/* 80158540 5400063F */  clrlwi.  r0, r0, 24;
/* 80158544 41820018 */  beq-     UNDEF_8015855c;
/* 80158548 2C000001 */  cmpwi    r0, 1;
/* 8015854C 41820020 */  beq-     UNDEF_8015856c;
/* 80158550 2C000002 */  cmpwi    r0, 2;
/* 80158554 4182003C */  beq-     UNDEF_80158590;
/* 80158558 48000044 */  b        UNDEF_8015859c;
UNDEF_8015855c:;
/* 8015855C C005045C */  lfs      f0, 1116(r5);
/* 80158560 EC001028 */  fsubs    f0, f0, f2;
/* 80158564 D005045C */  stfs     f0, 1116(r5);
/* 80158568 48000034 */  b        UNDEF_8015859c;
UNDEF_8015856c:;
/* 8015856C C022AB4C */  lfs      f1, UNDEF_8042deac@sda21;
/* 80158570 C0050458 */  lfs      f0, 1112(r5);
/* 80158574 EC420072 */  fmuls    f2, f2, f1;
/* 80158578 EC00102A */  fadds    f0, f0, f2;
/* 8015857C D0050458 */  stfs     f0, 1112(r5);
/* 80158580 C005045C */  lfs      f0, 1116(r5);
/* 80158584 EC001028 */  fsubs    f0, f0, f2;
/* 80158588 D005045C */  stfs     f0, 1116(r5);
/* 8015858C 48000010 */  b        UNDEF_8015859c;
UNDEF_80158590:;
/* 80158590 C0050458 */  lfs      f0, 1112(r5);
/* 80158594 EC00102A */  fadds    f0, f0, f2;
/* 80158598 D0050458 */  stfs     f0, 1112(r5);
UNDEF_8015859c:;
/* 8015859C 83E1004C */  lwz      r31, 76(r1);
/* 801585A0 83C10048 */  lwz      r30, 72(r1);
/* 801585A4 83A10044 */  lwz      r29, 68(r1);
/* 801585A8 83810040 */  lwz      r28, 64(r1);
/* 801585AC 38210050 */  addi     r1, r1, 80;
/* 801585B0 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x801585C0)]]
void dGameDisplay_c::AreaSetupAll()
{
    for (int area = 0; area < cAreaCheckCount; area++) {
        AreaSetup(area, cAreaPaneIndex[area]);
    }
    if (m0x414 != STAR_COIN_COUNT * 2) {
        // ??????????
        mArea[0].right = mpaPictures[m0x414]->GetGlobalMtx()[0][3] +
                         mpaPictures[m0x414]->GetSize().width / 2.0f + 60.0f;
    }
}

[[nsmbw(0x80158830)]]
bool dGameDisplay_c::createLayout()
{
    if (!mLayout.ReadResource("gameScene/gameScene.arc", false)) {
        return false;
    }

    mLayout.build("gameScene_37.brlyt", nullptr);
    mDeathMsgMgr.build(mLayout.getResAccessor(), mLayout.getDrawInfo());

    mLayout.AnimeResRegister({
      "gameScene_37_inMarioCoin.brlan",
    });

    mLayout.GroupRegister({{"C00_inMarioCoin", 0}});

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
      &mpPane_OtasukeInfo, //
      {
        "N_otasukeInfo_00", "N_otasukeChu_00", "N_left_00",      "N_coin_00",
        "N_collection_00",  "N_score_00",      "N_areaZanki_00", "N_areaCoin_00",
        "N_areaScore_00",   "N_marioIcon_00",  "N_luigiIcon_00", "N_kinoB_00",
        "N_kinoY_00",       "N_coin_01",       "N_time_00",      "N_proportionL_00",
        "N_proportionR_00", "N_coin1st_00",    "N_coin2nd_00",   "N_coin3rd_00",
      }
    );

    mLayout.NPaneRegister(
      mpaExPanes, //
      {
        "N_kinopico_00",
        "N_player_05",
        "N_player_06",
        "N_player_07",
      }
    );

    mLayout.PPaneRegister(
      &mpPicture_CollectOff00, //
      {
        "P_collectOff_00",
        "P_collection_00",
        "P_collectOff_01",
        "P_collection_01",
        "P_collectOff_02",
        "P_collection_02",
        "P_marioIcon_00",
        "P_luijiIcon_00",
        "P_kinoB_00",
        "P_kinoY_00",
      }
    );

    mLayout.PPaneRegister(
      mpaExPictures, //
      {
        "P_kinopico_00",
        "P_player_05",
        "P_player_06",
        "P_player_07",
      }
    );

    mpPicture_Collection00->SetVisible(false);
    mpPicture_Collection01->SetVisible(false);
    mpPicture_Collection02->SetVisible(false);
    mpPicture_CollectOff00->SetVisible(true);
    mpPicture_CollectOff01->SetVisible(true);
    mpPicture_CollectOff02->SetVisible(true);

    mpPicture_MarioIcon->SetVisible(false);

    mLayout.TPaneRegister(
      &mpTextBox_Left00, //
      {
        "T_left_00",
        "T_x_01",
        "T_left_01",
        "T_x_02",
        "T_left_02",
        "T_x_03",
        "T_left_03",
        "T_x_04",
        "T_coin_00",
        "T_time_00",
        "T_score_00",
      }
    );

    mLayout.TPaneRegister(
      mpaExTextBoxes, //
      {
        "T_left_04",
        "T_x_05",
        "T_left_05",
        "T_x_06",
        "T_left_06",
        "T_x_07",
        "T_left_07",
        "T_x_08",
      }
    );

    mLayout.TPaneNameRegister(
      1, //
      {
        {"T_otaChuS_00", 20},
        {"T_otaChu_01", 20},
        {"T_InfoS_00", 19},
        {"T_Info_00", 19},
      }
    );

    for (std::size_t i = 0; i < 4 + EXTRA_PLAYER_COUNT; i++) {
        mpaTexMap[i] = *mpaPictures[cPlayerPictureIndex[i]]->GetMaterial()->GetTexturePtr(0);
        maIconSize[i] = mpaPictures[cPlayerPictureIndex[i]]->GetSize();
        maIconScale[i] = mpaPictures[cPlayerPictureIndex[i]]->GetScale();
    }

    return true;
}

void dGameDisplay_c::DecEffectTimers()
{
    for (std::size_t i = 0; i < std::size(mEffectTimer); i++) {
        if (mEffectTimer[i] != 0) {
            mEffectTimer[i]--;
        }
    }
}

[[nsmbw(0x801586C0)]]
void dGameDisplay_c::RestDispSetup()
{
    nw4r::math::VEC3 position[4 + EXTRA_PLAYER_COUNT];

    for (std::size_t i = 0; i < 4 + EXTRA_PLAYER_COUNT; i++) {
        position[i] = mpaPictures[cPlayerPictureIndex[i]]->GetTranslate();
        mpaPictures[cPlayerPictureIndex[i]]->SetVisible(false);
    }

    for (std::size_t i = 0, count = 0; i < 4 + EXTRA_PLAYER_COUNT; i++) {
        if (daPyMng_c::mPlayerEntry[i] == 0) {
            continue;
        }

        std::size_t player = static_cast<std::size_t>(daPyMng_c::mPlayerType[i]);
        if (player >= 4 + EXTRA_PLAYER_COUNT) {
            continue;
        }

        mpaPictures[cPlayerPictureIndex[player]]->SetVisible(true);
        mpaPictures[cPlayerPictureIndex[player]]->SetTranslate(position[count++]);

        m0x414 = cPlayerPictureIndex[player];

        int charaIndex = daPyMng_c::getPlayerColorType(static_cast<PLAYER_TYPE_e>(player));

        mpaPictures[cPlayerPictureIndex[player]]->GetMaterial()->SetTexture(
          0, mpaTexMap[charaIndex]
        );

        nw4r::lyt::Size size = maIconSize[charaIndex];
        size.width *= (maIconScale[charaIndex].x / maIconScale[player].x);
        size.height *= (maIconScale[charaIndex].y / maIconScale[player].y);

        mpaPictures[cPlayerPictureIndex[player]]->SetSize(size);
    }
}

[[nsmbw(0x801589D0)]]
void dGameDisplay_c::RestCoinAnimeCheck()
{
    if (m0x44A || !m0x449) {
        m0x449 = false;
        return;
    }

    m0x449 = false;
    m0x44A = true;
    mLayout.AnimeStartSetup(0);
    if (dActorCreateMng_c::m_instance->m_stopped) {
        PauseManager_c::m_instance->m_ForbidPause = true;
    }
}

[[nsmbw(0x80158A50)]]
void dGameDisplay_c::AreaCheck()
{
    if (!mpRootPane->IsVisible()) {
        return;
    }

    for (std::size_t plr = 0; plr < PLAYER_COUNT; plr++) {
        if (!daPyMng_c::isPlayerActive(plr)) {
            continue;
        }
        dAcPy_c* player = daPyMng_c::getPlayer(plr);
        if (player == nullptr) {
            continue;
        }

        mVec3_c plrPos = player->getCenterPos();
        mVec3_c pos = dGameCom::getGlbPosToLyt(plrPos);

        for (int area = 0; area < cAreaCheckCount; area++) {
            if (!mAreaCrossed[area] && pos.x > mArea[area].left && pos.x < mArea[area].right &&
                pos.y < mArea[area].top && pos.y > mArea[area].bottom) {
                mAreaCrossed[area] = mIsAlphaEnterOrExit = true;
            }
        }
    }
}

[[nsmbw(0x80158BD0)]]
void dGameDisplay_c::AlphaEnterAndExit()
{
    if (!mpRootPane->IsVisible()) {
        return;
    }

    constexpr int cLowAlpha = 71, cHighAlpha = 255, cAlphaChange = 12;

    int unchanged = 0;
    for (int area = 0; area < cAreaCheckCount; area++) {
        nw4r::lyt::Pane* pane = mpaPanes[cAreaPaneIndex[area]];
        int alpha = pane->GetAlpha();
        if ((mAreaCrossed[area] && alpha < cLowAlpha) ||
            (!mAreaCrossed[area] && alpha >= cHighAlpha)) {
            unchanged++;
        }

        mAreaAlpha[area] = std::clamp(
          mAreaAlpha[area] + (mAreaCrossed[area] ? -cAlphaChange : cAlphaChange), cLowAlpha,
          cHighAlpha
        );
        pane->SetAlpha(mAreaAlpha[area]);
        mAreaCrossed[area] = false;
    }
    mIsAlphaEnterOrExit = unchanged < cAreaCheckCount;
}

[[nsmbw(0x80158D90)]]
bool dGameDisplay_c::NormalSettle()
{
    short timer = dStageTimer_c::m_instance->getTimer();
    if (timer <= 0) {
        return true;
    }

    int subTime = std::min(+timer, mSettleTimePerFrame);
    int score = mSettleScorePerSecond * subTime;
    dStageTimer_c::m_instance->setTimer(timer - subTime);

    if (!dInfo_c::isGameFlag(dInfo_c::GameFlag_e::COIN_BATTLE)) {
        SndAudioMgr::sInstance->holdSystemSe(SndID::SE_SYS_SCORE_COUNT, 1);
    }
    daPyMng_c::addScore(score);

    return false;
}

[[nsmbw(0x80158E40)]]
bool dGameDisplay_c::OtasukeSettle()
{
    int score = daPyMng_c::mScore;
    short timer = dStageTimer_c::m_instance->getTimer();
    if (timer == 0 && score == 0 && mCoinNum == 0) {
        return true;
    }

    mCoinNum = std::max(0, mCoinNum - 3);
    dGameCom::LayoutDispNumber(mCoinNum, 2, mpTextBox_Coins, 0);

    timer = std::max(0, timer - mSettleTimePerFrame);
    dStageTimer_c::m_instance->setTimer(timer);

    daPyMng_c::mScore = std::max(0, score - mSettleScorePerSecond * mSettleTimePerFrame);

    SndAudioMgr::sInstance->holdSystemSe(SndID::SE_SYS_SCORE_COUNT, 1);
    return false;
}

[[nsmbw(0x80158F50)]]
void dGameDisplay_c::initializeState_ProcMainGame()
{
    m0x43C = 0;
    m0x453 = m0x451 = false;
}

[[nsmbw(0x80158F70)]]
void dGameDisplay_c::executeState_ProcMainGame()
{
    if (m0x438 == 1) {
        m0x440 = 0;
        return mStateMgr.changeState(StateID_ProcMainPause);
    }
    if (m0x44C) {
        return mStateMgr.changeState(StateID_ProcGoalSettleUp);
    }
}

[[nsmbw(0x80158FE0)]]
void dGameDisplay_c::finalizeState_ProcMainGame()
{
    m0x451 = true;
}

[[nsmbw(0x80158FF0)]]
void dGameDisplay_c::initializeState_ProcMainPause()
{
    m0x43C = 1;
    m0x438 = 0;
}

[[nsmbw(0x80159010)]]
void dGameDisplay_c::executeState_ProcMainPause()
{
    if (m0x440 == 1) {
        return mStateMgr.changeState(StateID_ProcMainGame);
    }
}

[[nsmbw(0x80159040)]]
void dGameDisplay_c::finalizeState_ProcMainPause()
{
    m0x440 = 0;
}

[[nsmbw(0x80159050)]]
void dGameDisplay_c::initializeState_ProcGoalSettleUp()
{
    m0x400 = 1;
    mSettleTimePerFrame = 10;
    mSettleScorePerSecond = 50;
    m0x444 = 1;
    m0x453 = true;

    dMultiMng_c::mspInstance->mGoalTime = dStageTimer_c::m_instance->getTimer();
    if (PauseManager_c::m_OtasukeAfter) {
        EffectCollectionCoinClear();
    }
}

[[nsmbw(0x801590B0)]]
void dGameDisplay_c::executeState_ProcGoalSettleUp()
{
    if (m0x400 < m0x404) {
        m0x400++;
        return;
    }

    if (PauseManager_c::m_OtasukeAfter) {
        if (OtasukeSettle()) {
            m0x400 = 0;
            SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_SCORE_COUNT_FINISH, 1);
            return mStateMgr.changeState(StateID_ProcGoalEnd);
        }
    } else {
        if (NormalSettle()) {
            m0x400 = 0;
            if (!dInfo_c::isGameFlag(dInfo_c::GameFlag_e::COIN_BATTLE)) {
                SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_SCORE_COUNT_FINISH, 1);
            }
            return mStateMgr.changeState(StateID_ProcGoalEnd);
        }
    }
}

// Empty
[[nsmbw(0x80159190)]]
void dGameDisplay_c::finalizeState_ProcGoalSettleUp();

// Empty
[[nsmbw(0x801591A0)]]
void dGameDisplay_c::initializeState_ProcGoalEnd();

[[nsmbw(0x801591B0)]]
void dGameDisplay_c::executeState_ProcGoalEnd()
{
    if (m0x400 < m0x408) {
        m0x400++;
        return;
    }

    m0x444 = 0;
}

// Empty
[[nsmbw(0x801591E0)]]
void dGameDisplay_c::finalizeState_ProcGoalEnd();

// Changed the parameter from playerNo to paneIndex and added bool return
[[nsmbw(0x801591F0)]]
bool dGameDisplay_c::Effect1Up(int paneIndex) ASM_METHOD(
  // clang-format off
/* 801591F0 9421FFB0 */  stwu     r1, -80(r1);
/* 801591F4 7C0802A6 */  mflr     r0;
/* 801591F8 90010054 */  stw      r0, 84(r1);
/* 801591FC 93E1004C */  stw      r31, 76(r1);
/* 80159200 7C7F1B78 */  mr       r31, r3;
/* 80159204 93C10048 */  stw      r30, 72(r1);
/* 80159208 7C9E2378 */  mr       r30, r4;
/* 8015920C 806DADA0 */  lwz      r3, UNDEF_8042a720@sda21;
/* 80159210 81830000 */  lwz      r12, 0(r3);
/* 80159214 818C0010 */  lwz      r12, 16(r12);
/* 80159218 7D8903A6 */  mtctr    r12;
/* 8015921C 4E800421 */  bctrl;
/* 80159220 3803FFFF */  subi     r0, r3, 1;
/* 80159224 7C000034 */  cntlzw   r0, r0;
/* 80159228 5400D97F */  srwi.    r0, r0, 5;
                         li       r3, 0;
/* 8015922C 41820140 */  beq-     UNDEF_8015936c;
/* 80159230 880DA942 */  lbz      r0, UNDEF_8042a2c2@sda21;
/* 80159234 2C000000 */  cmpwi    r0, 0;
/* 80159238 40820134 */  bne-     UNDEF_8015936c;
/* 8015923C 800DAB80 */  lwz      r0, UNDEF_8042a500@sda21;
/* 80159240 2C000000 */  cmpwi    r0, 0;
/* 80159244 40820128 */  bne-     UNDEF_8015936c;
/* 80159248          */  lis      r4, (m_startGameInfo__7dInfo_c + 8)@ha;
/* 80159250          */  lwz      r0, (m_startGameInfo__7dInfo_c + 8)@l(r4);
/* 80159254 2C000003 */  cmpwi    r0, 3;
/* 80159258 40820008 */  bne-     UNDEF_80159260;
/* 8015925C 48000110 */  b        UNDEF_8015936c;
UNDEF_80159260:;
// /* 80159260 57C0103A */  slwi     r0, r30, 2;
// /* 80159264 7C9F0214 */  add      r4, r31, r0;
// /* 80159268 80040424 */  lwz      r0, 1060(r4);
// /* 8015926C 2C000000 */  cmpwi    r0, 0;
// /* 80159270 408200FC */  bne-     UNDEF_8015936c;
// /* 80159274 381E0009 */  addi     r0, r30, 9;
// /* 80159278 3860000F */  li       r3, 15;
// /* 8015927C 90640424 */  stw      r3, 1060(r4);
/* 80159280          */  slwi     r0, r30, 2;
/* 80159284 7C7F0214 */  add      r3, r31, r0;
/* 80159288 C002AB40 */  lfs      f0, UNDEF_8042dea0@sda21;
/* 8015928C 83C304E8 */  lwz      r30, 1256(r3);
/* 80159290 38610008 */  addi     r3, r1, 8;
/* 80159294 38800000 */  li       r4, 0;
/* 80159298 80BE0090 */  lwz      r5, 144(r30);
/* 8015929C 90A10024 */  stw      r5, 36(r1);
/* 801592A0 801E00A0 */  lwz      r0, 160(r30);
/* 801592A4 90010034 */  stw      r0, 52(r1);
/* 801592A8 83FE0084 */  lwz      r31, 132(r30);
/* 801592AC 819E0088 */  lwz      r12, 136(r30);
/* 801592B0 817E008C */  lwz      r11, 140(r30);
/* 801592B4 815E0094 */  lwz      r10, 148(r30);
/* 801592B8 813E0098 */  lwz      r9, 152(r30);
/* 801592BC 811E009C */  lwz      r8, 156(r30);
/* 801592C0 80FE00A4 */  lwz      r7, 164(r30);
/* 801592C4 80DE00A8 */  lwz      r6, 168(r30);
/* 801592C8 80BE00AC */  lwz      r5, 172(r30);
/* 801592CC 801E00B0 */  lwz      r0, 176(r30);
/* 801592D0 C0410024 */  lfs      f2, 36(r1);
/* 801592D4 C0210034 */  lfs      f1, 52(r1);
/* 801592D8 93E10018 */  stw      r31, 24(r1);
/* 801592DC 9181001C */  stw      r12, 28(r1);
/* 801592E0 91610020 */  stw      r11, 32(r1);
/* 801592E4 91410028 */  stw      r10, 40(r1);
/* 801592E8 9121002C */  stw      r9, 44(r1);
/* 801592EC 91010030 */  stw      r8, 48(r1);
/* 801592F0 90E10038 */  stw      r7, 56(r1);
/* 801592F4 90C1003C */  stw      r6, 60(r1);
/* 801592F8 90A10040 */  stw      r5, 64(r1);
/* 801592FC 90010044 */  stw      r0, 68(r1);
/* 80159300 D0410008 */  stfs     f2, 8(r1);
/* 80159304 D021000C */  stfs     f1, 12(r1);
/* 80159308 D0010010 */  stfs     f0, 16(r1);
/* 8015930C 4BF5A4D5 */  bl       UNDEF_800b37e0;
/* 80159310 3C608032 */  lis      r3, UNDEF_803279e4@ha;
/* 80159314 38A10008 */  addi     r5, r1, 8;
/* 80159318 386379E4 */  addi     r3, r3, UNDEF_803279e4@l;
/* 8015931C 38800000 */  li       r4, 0;
/* 80159320 38C00000 */  li       r6, 0;
/* 80159324 38E00000 */  li       r7, 0;
/* 80159328 480136A9 */  bl       UNDEF_8016c9d0; // createEffect__3mEfFPCcUlPC7mVec3_cPC7mAng3_cPC7mVec3_c
/* 8015932C C0410024 */  lfs      f2, 36(r1);
/* 80159330 38610008 */  addi     r3, r1, 8;
/* 80159334 C0210034 */  lfs      f1, 52(r1);
/* 80159338 38800001 */  li       r4, 1;
/* 8015933C C002AB40 */  lfs      f0, UNDEF_8042dea0@sda21;
/* 80159340 D0410008 */  stfs     f2, 8(r1);
/* 80159344 D021000C */  stfs     f1, 12(r1);
/* 80159348 D0010010 */  stfs     f0, 16(r1);
/* 8015934C 4BF5A495 */  bl       UNDEF_800b37e0;
/* 80159350 3C608032 */  lis      r3, UNDEF_803279f0@ha;
/* 80159354 38A10008 */  addi     r5, r1, 8;
/* 80159358 386379F0 */  addi     r3, r3, UNDEF_803279f0@l;
/* 8015935C 38800000 */  li       r4, 0;
/* 80159360 38C00000 */  li       r6, 0;
/* 80159364 38E00000 */  li       r7, 0;
/* 80159368 48013669 */  bl       UNDEF_8016c9d0; // createEffect__3mEfFPCcUlPC7mVec3_cPC7mAng3_cPC7mVec3_c
                         li       r3, 1;
UNDEF_8015936c:;
/* 8015936C 80010054 */  lwz      r0, 84(r1);
/* 80159370 83E1004C */  lwz      r31, 76(r1);
/* 80159374 83C10048 */  lwz      r30, 72(r1);
/* 80159378 7C0803A6 */  mtlr     r0;
/* 8015937C 38210050 */  addi     r1, r1, 80;
/* 80159380 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80159390)]]
void dGameDisplay_c::GrayColorSet(int player) ASM_METHOD(
  // clang-format off
/* 80159390 9421FF90 */  stwu     r1, -112(r1);
/* 80159394 7C0802A6 */  mflr     r0;
/* 80159398 90010074 */  stw      r0, 116(r1);
/* 8015939C 39610070 */  addi     r11, r1, 112;
/* 801593A0 48183CC5 */  bl       UNDEF_802dd064;
// /* 801593A4 7D032214 */  add      r8, r3, r4;
/* 801593A8 7C7B1B78 */  mr       r27, r3;
// /* 801593AC 88080454 */  lbz      r0, 1108(r8);
/* 801593B0 7C9C2378 */  mr       r28, r4;
// /* 801593B4 2C000000 */  cmpwi    r0, 0;
// /* 801593B8 40820250 */  bne-     UNDEF_80159608;
/* 801593BC 880DAC8C */  lbz      r0, UNDEF_8042a60c@sda21;
/* 801593C0 7C000775 */  extsb.   r0, r0;
/* 801593C4 40820028 */  bne-     UNDEF_801593ec;
/* 801593C8 38CDAC90 */  la       r6, UNDEF_8042a610@sda21;
/* 801593CC 38E000A0 */  li       r7, 160;
/* 801593D0 38A000FF */  li       r5, 255;
/* 801593D4 38000001 */  li       r0, 1;
/* 801593D8 98EDAC90 */  stb      r7, UNDEF_8042a610@sda21;
/* 801593DC 98E60001 */  stb      r7, 1(r6);
/* 801593E0 98E60002 */  stb      r7, 2(r6);
/* 801593E4 98A60003 */  stb      r5, 3(r6);
/* 801593E8 980DAC8C */  stb      r0, UNDEF_8042a60c@sda21;
UNDEF_801593ec:;
/* 801593EC 3CA0802F */  lis      r5, cPlayerPictureIndex__14dGameDisplay_c@ha;
// /* 801593F0 38C00001 */  li       r6, 1;
/* 801593F4 5480103A */  slwi     r0, r4, 2;
// /* 801593F8 98C80454 */  stb      r6, 1108(r8);
/* 801593FC 38A55C78 */  addi     r5, r5, cPlayerPictureIndex__14dGameDisplay_c@l;
/* 80159400 7C05002E */  lwzx     r0, r5, r0;
/* 80159404 5400103A */  slwi     r0, r0, 2;
/* 80159408 7C630214 */  add      r3, r3, r0;
/* 8015940C 80630494 */  lwz      r3, 1172(r3);
/* 80159410 81830000 */  lwz      r12, 0(r3);
/* 80159414 818C0068 */  lwz      r12, 104(r12);
/* 80159418 7D8903A6 */  mtctr    r12;
/* 8015941C 4E800421 */  bctrl;
/* 80159420 80030018 */  lwz      r0, 24(r3);
/* 80159424 579D1838 */  slwi     r29, r28, 3;
/* 80159428 90010048 */  stw      r0, 72(r1);
/* 8015942C 3BCDAC90 */  la       r30, UNDEF_8042a610@sda21;
/* 80159430 8083001C */  lwz      r4, 28(r3);
/* 80159434 3FE0802F */  lis      r31, cPlayerBothTextboxIndex__14dGameDisplay_c@ha;
/* 80159438 7D3BEA14 */  add      r9, r27, r29; // r9 = this + (player * 0x8)
/* 8015943C A8010048 */  lha      r0, 72(r1);
/* 80159440 9081004C */  stw      r4, 76(r1);
/* 80159444 3BFF5C58 */  addi     r31, r31, cPlayerBothTextboxIndex__14dGameDisplay_c@l;
/* 80159448 888DAC90 */  lbz      r4, UNDEF_8042a610@sda21;
/* 8015944C 579C083C */  slwi     r28, r28, 1;
/* 80159450 B0090330 */  sth      r0, OFFSET_dGameDisplay_c_mPlayerRGBA0(r9);
/* 80159454 881E0001 */  lbz      r0, 1(r30);
/* 80159458 A8A1004A */  lha      r5, 74(r1);
/* 8015945C B001001A */  sth      r0, 26(r1);
/* 80159460 88FE0002 */  lbz      r7, 2(r30);
/* 80159464 B0810018 */  sth      r4, 24(r1);
/* 80159468 88DE0003 */  lbz      r6, 3(r30);
/* 8015946C B0A90332 */  sth      r5, OFFSET_dGameDisplay_c_mPlayerRGBA0 + 0x2(r9);
/* 80159470 A901004C */  lha      r8, 76(r1);
/* 80159474 80810018 */  lwz      r4, 24(r1);
/* 80159478 7C1FE82E */  lwzx     r0, r31, r29;
/* 8015947C B1090334 */  sth      r8, OFFSET_dGameDisplay_c_mPlayerRGBA0 + 0x4(r9);
/* 80159480 A8A1004E */  lha      r5, 78(r1);
/* 80159484 5400103A */  slwi     r0, r0, 2;
/* 80159488 90810040 */  stw      r4, 64(r1);
/* 8015948C 7C9B0214 */  add      r4, r27, r0;
/* 80159490 B0A90336 */  sth      r5, OFFSET_dGameDisplay_c_mPlayerRGBA0 + 0x6(r9);
/* 80159494 A8A10040 */  lha      r5, 64(r1);
/* 80159498 B0E1001C */  sth      r7, 28(r1);
/* 8015949C A8010042 */  lha      r0, 66(r1);
/* 801594A0 B0A30018 */  sth      r5, 24(r3);
/* 801594A4 B0C1001E */  sth      r6, 30(r1);
/* 801594A8 80A1001C */  lwz      r5, 28(r1);
/* 801594AC 90A10044 */  stw      r5, 68(r1);
/* 801594B0 B003001A */  sth      r0, 26(r3);
/* 801594B4 A8010044 */  lha      r0, 68(r1);
/* 801594B8 B003001C */  sth      r0, 28(r3);
/* 801594BC A8010046 */  lha      r0, 70(r1);
/* 801594C0 B003001E */  sth      r0, 30(r3);
/* 801594C4 806404BC */  lwz      r3, 1212(r4);
/* 801594C8 81830000 */  lwz      r12, 0(r3);
/* 801594CC 818C0068 */  lwz      r12, 104(r12);
/* 801594D0 7D8903A6 */  mtctr    r12;
/* 801594D4 4E800421 */  bctrl;
/* 801594D8 80830018 */  lwz      r4, 24(r3);
/* 801594DC 381C0001 */  addi     r0, r28, 1;
/* 801594E0 90810038 */  stw      r4, 56(r1);
/* 801594E4 5400103A */  slwi     r0, r0, 2;
/* 801594E8 80A3001C */  lwz      r5, 28(r3);
/* 801594EC 7D3BEA14 */  add      r9, r27, r29;
/* 801594F0 A8810038 */  lha      r4, 56(r1);
/* 801594F4 B0890350 */  sth      r4, OFFSET_dGameDisplay_c_mPlayerRGBA1(r9);
/* 801594F8 889E0001 */  lbz      r4, 1(r30);
/* 801594FC 90A1003C */  stw      r5, 60(r1);
/* 80159500 88ADAC90 */  lbz      r5, UNDEF_8042a610@sda21;
/* 80159504 B0A10010 */  sth      r5, 16(r1);
/* 80159508 A901003A */  lha      r8, 58(r1);
/* 8015950C B0810012 */  sth      r4, 18(r1);
/* 80159510 88FE0002 */  lbz      r7, 2(r30);
/* 80159514 B1090352 */  sth      r8, OFFSET_dGameDisplay_c_mPlayerRGBA1 + 0x2(r9);
/* 80159518 A901003C */  lha      r8, 60(r1);
/* 8015951C 80810010 */  lwz      r4, 16(r1);
/* 80159520 88DE0003 */  lbz      r6, 3(r30);
/* 80159524 7C1F002E */  lwzx     r0, r31, r0;
/* 80159528 B1090354 */  sth      r8, OFFSET_dGameDisplay_c_mPlayerRGBA1 + 0x4(r9);
/* 8015952C A8A1003E */  lha      r5, 62(r1);
/* 80159530 5400103A */  slwi     r0, r0, 2;
/* 80159534 90810030 */  stw      r4, 48(r1);
/* 80159538 7C9B0214 */  add      r4, r27, r0;
/* 8015953C B0A90356 */  sth      r5, OFFSET_dGameDisplay_c_mPlayerRGBA1 + 0x6(r9);
/* 80159540 A8A10030 */  lha      r5, 48(r1);
/* 80159544 B0E10014 */  sth      r7, 20(r1);
/* 80159548 A8010032 */  lha      r0, 50(r1);
/* 8015954C B0A30018 */  sth      r5, 24(r3);
/* 80159550 B0C10016 */  sth      r6, 22(r1);
/* 80159554 80A10014 */  lwz      r5, 20(r1);
/* 80159558 90A10034 */  stw      r5, 52(r1);
/* 8015955C B003001A */  sth      r0, 26(r3);
/* 80159560 A8010034 */  lha      r0, 52(r1);
/* 80159564 B003001C */  sth      r0, 28(r3);
/* 80159568 A8010036 */  lha      r0, 54(r1);
/* 8015956C B003001E */  sth      r0, 30(r3);
/* 80159570 806404BC */  lwz      r3, 1212(r4);
/* 80159574 81830000 */  lwz      r12, 0(r3);
/* 80159578 818C0068 */  lwz      r12, 104(r12);
/* 8015957C 7D8903A6 */  mtctr    r12;
/* 80159580 4E800421 */  bctrl;
/* 80159584 80030018 */  lwz      r0, 24(r3);
/* 80159588 7D1BEA14 */  add      r8, r27, r29;
/* 8015958C 90010028 */  stw      r0, 40(r1);
/* 80159590 8083001C */  lwz      r4, 28(r3);
/* 80159594 A8010028 */  lha      r0, 40(r1);
/* 80159598 B0080370 */  sth      r0, OFFSET_dGameDisplay_c_mPlayerRGBA2(r8);
/* 8015959C 881E0001 */  lbz      r0, 1(r30);
/* 801595A0 9081002C */  stw      r4, 44(r1);
/* 801595A4 888DAC90 */  lbz      r4, UNDEF_8042a610@sda21;
/* 801595A8 B0810008 */  sth      r4, 8(r1);
/* 801595AC A8E1002A */  lha      r7, 42(r1);
/* 801595B0 B001000A */  sth      r0, 10(r1);
/* 801595B4 88DE0002 */  lbz      r6, 2(r30);
/* 801595B8 B0E80372 */  sth      r7, OFFSET_dGameDisplay_c_mPlayerRGBA2 + 0x2(r8);
/* 801595BC A8E1002C */  lha      r7, 44(r1);
/* 801595C0 80010008 */  lwz      r0, 8(r1);
/* 801595C4 88BE0003 */  lbz      r5, 3(r30);
/* 801595C8 90010020 */  stw      r0, 32(r1);
/* 801595CC A881002E */  lha      r4, 46(r1);
/* 801595D0 B0E80374 */  sth      r7, OFFSET_dGameDisplay_c_mPlayerRGBA2 + 0x4(r8);
/* 801595D4 A8010022 */  lha      r0, 34(r1);
/* 801595D8 B0880376 */  sth      r4, OFFSET_dGameDisplay_c_mPlayerRGBA2 + 0x6(r8);
/* 801595DC A8810020 */  lha      r4, 32(r1);
/* 801595E0 B0830018 */  sth      r4, 24(r3);
/* 801595E4 B0C1000C */  sth      r6, 12(r1);
/* 801595E8 B0A1000E */  sth      r5, 14(r1);
/* 801595EC 8081000C */  lwz      r4, 12(r1);
/* 801595F0 90810024 */  stw      r4, 36(r1);
/* 801595F4 B003001A */  sth      r0, 26(r3);
/* 801595F8 A8010024 */  lha      r0, 36(r1);
/* 801595FC B003001C */  sth      r0, 28(r3);
/* 80159600 A8010026 */  lha      r0, 38(r1);
/* 80159604 B003001E */  sth      r0, 30(r3);
UNDEF_80159608:;
/* 80159608 39610070 */  addi     r11, r1, 112;
/* 8015960C 48183AA5 */  bl       UNDEF_802dd0b0;
/* 80159610 80010074 */  lwz      r0, 116(r1);
/* 80159614 7C0803A6 */  mtlr     r0;
/* 80159618 38210070 */  addi     r1, r1, 112;
/* 8015961C 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80159620)]]
void dGameDisplay_c::ReturnGrayColorSet(int player) ASM_METHOD(
  // clang-format off
/* 80159620 9421FFE0 */  stwu     r1, -32(r1);
/* 80159624 7C0802A6 */  mflr     r0;
// /* 80159628 7CE32214 */  add      r7, r3, r4;
/* 8015962C 90010024 */  stw      r0, 36(r1);
/* 80159630 93E1001C */  stw      r31, 28(r1);
/* 80159634 93C10018 */  stw      r30, 24(r1);
/* 80159638 7C7E1B78 */  mr       r30, r3;
/* 8015963C 93A10014 */  stw      r29, 20(r1);
/* 80159640 93810010 */  stw      r28, 16(r1);
/* 80159644 7C9C2378 */  mr       r28, r4;
// /* 80159648 88070454 */  lbz      r0, 1108(r7);
// /* 8015964C 2C000000 */  cmpwi    r0, 0;
// /* 80159650 418200FC */  beq-     UNDEF_8015974c;
/* 80159654 3CA0802F */  lis      r5, cPlayerPictureIndex__14dGameDisplay_c@ha;
// /* 80159658 38C00000 */  li       r6, 0;
/* 8015965C 5480103A */  slwi     r0, r4, 2;
// /* 80159660 98C70454 */  stb      r6, 1108(r7);
/* 80159664 38A55CA8 */  addi     r5, r5, cPlayerPictureIndex__14dGameDisplay_c@l;
/* 80159668 7C05002E */  lwzx     r0, r5, r0;
/* 8015966C 5400103A */  slwi     r0, r0, 2;
/* 80159670 7C630214 */  add      r3, r3, r0;
/* 80159674 80630494 */  lwz      r3, 1172(r3);
/* 80159678 81830000 */  lwz      r12, 0(r3);
/* 8015967C 818C0068 */  lwz      r12, 104(r12);
/* 80159680 7D8903A6 */  mtctr    r12;
/* 80159684 4E800421 */  bctrl;
/* 80159688 579F1838 */  slwi     r31, r28, 3;
/* 8015968C 3FA0802F */  lis      r29, cPlayerBothTextboxIndex__14dGameDisplay_c@ha;
/* 80159690 7CBEFA14 */  add      r5, r30, r31;
/* 80159694 579C083C */  slwi     r28, r28, 1;
/* 80159698 A8050330 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA0(r5);
/* 8015969C 3BBD5C88 */  addi     r29, r29, cPlayerBothTextboxIndex__14dGameDisplay_c@l;
/* 801596A0 B0030018 */  sth      r0, 24(r3);
/* 801596A4 7C1DF82E */  lwzx     r0, r29, r31;
/* 801596A8 A8850332 */  lha      r4, OFFSET_dGameDisplay_c_mPlayerRGBA0 + 0x2(r5);
/* 801596AC B083001A */  sth      r4, 26(r3);
/* 801596B0 5400103A */  slwi     r0, r0, 2;
/* 801596B4 7C9E0214 */  add      r4, r30, r0;
/* 801596B8 A8050334 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA0 + 0x4(r5);
/* 801596BC B003001C */  sth      r0, 28(r3);
/* 801596C0 A8050336 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA0 + 0x6(r5);
/* 801596C4 B003001E */  sth      r0, 30(r3);
/* 801596C8 806404BC */  lwz      r3, 1212(r4);
/* 801596CC 81830000 */  lwz      r12, 0(r3);
/* 801596D0 818C0068 */  lwz      r12, 104(r12);
/* 801596D4 7D8903A6 */  mtctr    r12;
/* 801596D8 4E800421 */  bctrl;
/* 801596DC 7CBEFA14 */  add      r5, r30, r31;
/* 801596E0 381C0001 */  addi     r0, r28, 1;
/* 801596E4 A8850350 */  lha      r4, OFFSET_dGameDisplay_c_mPlayerRGBA1(r5);
/* 801596E8 5400103A */  slwi     r0, r0, 2;
/* 801596EC B0830018 */  sth      r4, 24(r3);
/* 801596F0 7C1D002E */  lwzx     r0, r29, r0;
/* 801596F4 A8850352 */  lha      r4, OFFSET_dGameDisplay_c_mPlayerRGBA1 + 0x2(r5);
/* 801596F8 B083001A */  sth      r4, 26(r3);
/* 801596FC 5400103A */  slwi     r0, r0, 2;
/* 80159700 7C9E0214 */  add      r4, r30, r0;
/* 80159704 A8050354 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA1 + 0x4(r5);
/* 80159708 B003001C */  sth      r0, 28(r3);
/* 8015970C A8050356 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA1 + 0x6(r5);
/* 80159710 B003001E */  sth      r0, 30(r3);
/* 80159714 806404BC */  lwz      r3, 1212(r4);
/* 80159718 81830000 */  lwz      r12, 0(r3);
/* 8015971C 818C0068 */  lwz      r12, 104(r12);
/* 80159720 7D8903A6 */  mtctr    r12;
/* 80159724 4E800421 */  bctrl;
/* 80159728 7C9EFA14 */  add      r4, r30, r31;
/* 8015972C A8040370 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA2(r4);
/* 80159730 B0030018 */  sth      r0, 24(r3);
/* 80159734 A8040372 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA2 + 0x2(r4);
/* 80159738 B003001A */  sth      r0, 26(r3);
/* 8015973C A8040374 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA2 + 0x4(r4);
/* 80159740 B003001C */  sth      r0, 28(r3);
/* 80159744 A8040376 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA2 + 0x6(r4);
/* 80159748 B003001E */  sth      r0, 30(r3);
UNDEF_8015974c:;
/* 8015974C 80010024 */  lwz      r0, 36(r1);
/* 80159750 83E1001C */  lwz      r31, 28(r1);
/* 80159754 83C10018 */  lwz      r30, 24(r1);
/* 80159758 83A10014 */  lwz      r29, 20(r1);
/* 8015975C 83810010 */  lwz      r28, 16(r1);
/* 80159760 7C0803A6 */  mtlr     r0;
/* 80159764 38210020 */  addi     r1, r1, 32;
/* 80159768 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80159770)]]
void dGameDisplay_c::EffectCollectionCoinClear() ASM_METHOD(
  // clang-format off
/* 80159770 9421FF80 */  stwu     r1, -128(r1);
/* 80159774 7C0802A6 */  mflr     r0;
/* 80159778 90010084 */  stw      r0, 132(r1);
/* 8015977C 39610070 */  addi     r11, r1, 112;
/* 80159780 DBE10070 */  stfd     f31, 112(r1);
/* 80159784 F3E10078 */  .long    0xF3E10078; // psq_st   f31, 120(r1), 0, 0;
/* 80159788 481838D1 */  bl       UNDEF_802dd058;
/* 8015978C 7C7B1B78 */  mr       r27, r3;
/* 80159790 3FE0802F */  lis      r31, UNDEF_802f5cb8@ha;
/* 80159794 3FC0802F */  lis      r30, UNDEF_802f5cc4@ha;
/* 80159798 C3E2AB40 */  lfs      f31, UNDEF_8042dea0@sda21;
/* 8015979C 7F7DDB78 */  mr       r29, r27;
/* 801597A0 3BFF5CB8 */  addi     r31, r31, UNDEF_802f5cb8@l;
/* 801597A4 3BDE5CC4 */  addi     r30, r30, UNDEF_802f5cc4@l;
/* 801597A8 3B800000 */  li       r28, 0;
/* 801597AC 3F408032 */  lis      r26, UNDEF_803279fc@ha;
UNDEF_801597b0:;
/* 801597B0 807F0000 */  lwz      r3, 0(r31);
/* 801597B4 801E0000 */  lwz      r0, 0(r30);
/* 801597B8 5463103A */  slwi     r3, r3, 2;
/* 801597BC 7C7B1A14 */  add      r3, r27, r3;
/* 801597C0 5400103A */  slwi     r0, r0, 2;
/* 801597C4 80830494 */  lwz      r4, 1172(r3);
/* 801597C8 7C7B0214 */  add      r3, r27, r0;
/* 801597CC 880400BB */  lbz      r0, 187(r4);
/* 801597D0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 801597D4 60000001 */  ori      r0, r0, 1;
/* 801597D8 980400BB */  stb      r0, 187(r4);
/* 801597DC 80630494 */  lwz      r3, 1172(r3);
/* 801597E0 880300BB */  lbz      r0, 187(r3);
/* 801597E4 540007FF */  clrlwi.  r0, r0, 31;
/* 801597E8 418200A0 */  beq-     UNDEF_80159888;
/* 801597EC 831D052C */  lwz      r24, 1324(r29);
/* 801597F0 38610008 */  addi     r3, r1, 8;
/* 801597F4 38800000 */  li       r4, 0;
/* 801597F8 80B80090 */  lwz      r5, 144(r24);
/* 801597FC 90A10024 */  stw      r5, 36(r1);
/* 80159800 801800A0 */  lwz      r0, 160(r24);
/* 80159804 90010034 */  stw      r0, 52(r1);
/* 80159808 83380084 */  lwz      r25, 132(r24);
/* 8015980C 81980088 */  lwz      r12, 136(r24);
/* 80159810 8178008C */  lwz      r11, 140(r24);
/* 80159814 81580094 */  lwz      r10, 148(r24);
/* 80159818 81380098 */  lwz      r9, 152(r24);
/* 8015981C 8118009C */  lwz      r8, 156(r24);
/* 80159820 80F800A4 */  lwz      r7, 164(r24);
/* 80159824 80D800A8 */  lwz      r6, 168(r24);
/* 80159828 80B800AC */  lwz      r5, 172(r24);
/* 8015982C 801800B0 */  lwz      r0, 176(r24);
/* 80159830 C0210024 */  lfs      f1, 36(r1);
/* 80159834 C0010034 */  lfs      f0, 52(r1);
/* 80159838 93210018 */  stw      r25, 24(r1);
/* 8015983C 9181001C */  stw      r12, 28(r1);
/* 80159840 91610020 */  stw      r11, 32(r1);
/* 80159844 91410028 */  stw      r10, 40(r1);
/* 80159848 9121002C */  stw      r9, 44(r1);
/* 8015984C 91010030 */  stw      r8, 48(r1);
/* 80159850 90E10038 */  stw      r7, 56(r1);
/* 80159854 90C1003C */  stw      r6, 60(r1);
/* 80159858 90A10040 */  stw      r5, 64(r1);
/* 8015985C 90010044 */  stw      r0, 68(r1);
/* 80159860 D0210008 */  stfs     f1, 8(r1);
/* 80159864 D001000C */  stfs     f0, 12(r1);
/* 80159868 D3E10010 */  stfs     f31, 16(r1);
/* 8015986C 4BF59F75 */  bl       UNDEF_800b37e0;
/* 80159870 387A79FC */  addi     r3, r26, UNDEF_803279fc@l;
/* 80159874 38A10008 */  addi     r5, r1, 8;
/* 80159878 38800000 */  li       r4, 0;
/* 8015987C 38C00000 */  li       r6, 0;
/* 80159880 38E00000 */  li       r7, 0;
/* 80159884 4801314D */  bl       UNDEF_8016c9d0;
UNDEF_80159888:;
/* 80159888 801E0000 */  lwz      r0, 0(r30);
/* 8015988C 3B9C0001 */  addi     r28, r28, 1;
/* 80159890 2C1C0003 */  cmpwi    r28, 3;
/* 80159894 3BFF0004 */  addi     r31, r31, 4;
/* 80159898 5400103A */  slwi     r0, r0, 2;
/* 8015989C 3BDE0004 */  addi     r30, r30, 4;
/* 801598A0 7C7B0214 */  add      r3, r27, r0;
/* 801598A4 3BBD0004 */  addi     r29, r29, 4;
/* 801598A8 80630494 */  lwz      r3, 1172(r3);
/* 801598AC 880300BB */  lbz      r0, 187(r3);
/* 801598B0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 801598B4 980300BB */  stb      r0, 187(r3);
/* 801598B8 4180FEF8 */  blt+     UNDEF_801597b0;
/* 801598BC 39610070 */  addi     r11, r1, 112;
/* 801598C0 E3E10078 */  .long    0xE3E10078; //psq_l    f31, 120(r1), 0, 0;
/* 801598C4 CBE10070 */  lfd      f31, 112(r1);
/* 801598C8 481837DD */  bl       UNDEF_802dd0a4;
/* 801598CC 80010084 */  lwz      r0, 132(r1);
/* 801598D0 7C0803A6 */  mtlr     r0;
/* 801598D4 38210080 */  addi     r1, r1, 128;
/* 801598D8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x801598E0)]]
void dGameDisplay_c::EffectCollectionCoinGet(int coin) ASM_METHOD(
  // clang-format off
/* 801598E0 9421FFB0 */  stwu     r1, -80(r1);
/* 801598E4 7C0802A6 */  mflr     r0;
/* 801598E8 C002AB40 */  lfs      f0, UNDEF_8042dea0@sda21;
/* 801598EC 90010054 */  stw      r0, 84(r1);
/* 801598F0 38040011 */  addi     r0, r4, 17;
/* 801598F4 5400103A */  slwi     r0, r0, 2;
/* 801598F8 38800000 */  li       r4, 0;
/* 801598FC 93E1004C */  stw      r31, 76(r1);
/* 80159900 7CA30214 */  add      r5, r3, r0;
/* 80159904 38610008 */  addi     r3, r1, 8;
/* 80159908 93C10048 */  stw      r30, 72(r1);
/* 8015990C 83C504E8 */  lwz      r30, 1256(r5);
/* 80159910 80BE0090 */  lwz      r5, 144(r30);
/* 80159914 90A10024 */  stw      r5, 36(r1);
/* 80159918 801E00A0 */  lwz      r0, 160(r30);
/* 8015991C 90010034 */  stw      r0, 52(r1);
/* 80159920 83FE0084 */  lwz      r31, 132(r30);
/* 80159924 819E0088 */  lwz      r12, 136(r30);
/* 80159928 817E008C */  lwz      r11, 140(r30);
/* 8015992C 815E0094 */  lwz      r10, 148(r30);
/* 80159930 813E0098 */  lwz      r9, 152(r30);
/* 80159934 811E009C */  lwz      r8, 156(r30);
/* 80159938 80FE00A4 */  lwz      r7, 164(r30);
/* 8015993C 80DE00A8 */  lwz      r6, 168(r30);
/* 80159940 80BE00AC */  lwz      r5, 172(r30);
/* 80159944 801E00B0 */  lwz      r0, 176(r30);
/* 80159948 C0410024 */  lfs      f2, 36(r1);
/* 8015994C C0210034 */  lfs      f1, 52(r1);
/* 80159950 93E10018 */  stw      r31, 24(r1);
/* 80159954 9181001C */  stw      r12, 28(r1);
/* 80159958 91610020 */  stw      r11, 32(r1);
/* 8015995C 91410028 */  stw      r10, 40(r1);
/* 80159960 9121002C */  stw      r9, 44(r1);
/* 80159964 91010030 */  stw      r8, 48(r1);
/* 80159968 90E10038 */  stw      r7, 56(r1);
/* 8015996C 90C1003C */  stw      r6, 60(r1);
/* 80159970 90A10040 */  stw      r5, 64(r1);
/* 80159974 90010044 */  stw      r0, 68(r1);
/* 80159978 D0410008 */  stfs     f2, 8(r1);
/* 8015997C D021000C */  stfs     f1, 12(r1);
/* 80159980 D0010010 */  stfs     f0, 16(r1);
/* 80159984 4BF59E5D */  bl       UNDEF_800b37e0;
/* 80159988 3C608032 */  lis      r3, UNDEF_80327a14@ha;
/* 8015998C 38A10008 */  addi     r5, r1, 8;
/* 80159990 38637A14 */  addi     r3, r3, UNDEF_80327a14@l;
/* 80159994 38800000 */  li       r4, 0;
/* 80159998 38C00000 */  li       r6, 0;
/* 8015999C 38E00000 */  li       r7, 0;
/* 801599A0 48013031 */  bl       UNDEF_8016c9d0;
/* 801599A4 80010054 */  lwz      r0, 84(r1);
/* 801599A8 83E1004C */  lwz      r31, 76(r1);
/* 801599AC 83C10048 */  lwz      r30, 72(r1);
/* 801599B0 7C0803A6 */  mtlr     r0;
/* 801599B4 38210050 */  addi     r1, r1, 80;
/* 801599B8 4E800020 */  blr;
// clang-format off
);

[[nsmbw(0x801599C0)]]
void dGameDisplay_c::setPlayNum(int* playNum)
{
    // Stubbed
}

void dGameDisplay_c::updatePlayNum(int* playNum)
{
    for (std::size_t i = 0; i < 4 + EXTRA_PLAYER_COUNT; i++) {
        int oldPlayNum = mPlayNum[i];
        int newPlayNum = playNum[i];

        if (!mPlayNumSet && newPlayNum == oldPlayNum) {
            continue;
        }

        mPlayNum[i] = newPlayNum;

        if (newPlayNum > oldPlayNum && mEffectTimer[i] == 0) {
            mEffectTimer[i] = Effect1Up(cPlayerPaneIndex[i]) ? 15 : 0;
        }

        if (!fFeat::infinite_lives && newPlayNum == 0 && !mPlayerGray[i]) {
            GrayColorSet(int(i));
            mPlayerGray[i] = 1;
        } else if ((newPlayNum != 0 || fFeat::infinite_lives) && mPlayerGray[i]) {
            ReturnGrayColorSet(int(i));
            mPlayerGray[i] = 0;
        }

        int maxChars = 2;
        if (fFeat::infinite_lives) {
            if (newPlayNum > 99) {
                maxChars = 4;
            }
        }
        dGameCom::LayoutDispNumber(newPlayNum, maxChars, mpaTextBoxes[cPlayerTextboxIndex[i]], 0);
    }
}

[[nsmbw(0x80159AA0)]]
void dGameDisplay_c::setCoinNum(int coinNum) ASM_METHOD(
  // clang-format off
/* 80159AA0 9421FFB0 */  stwu     r1, -80(r1);
/* 80159AA4 7C0802A6 */  mflr     r0;
/* 80159AA8 90010054 */  stw      r0, 84(r1);
/* 80159AAC 93E1004C */  stw      r31, 76(r1);
/* 80159AB0 7C7F1B78 */  mr       r31, r3;
/* 80159AB4 93C10048 */  stw      r30, 72(r1);
/* 80159AB8 7C9E2378 */  mr       r30, r4;
/* 80159ABC 88030453 */  lbz      r0, 1107(r3);
/* 80159AC0 2C000000 */  cmpwi    r0, 0;
/* 80159AC4 40820120 */  bne-     UNDEF_80159be4;
/* 80159AC8 800303DC */  lwz      r0, 988(r3);
/* 80159ACC 7C002000 */  cmpw     r0, r4;
/* 80159AD0 41820114 */  beq-     UNDEF_80159be4;
/* 80159AD4 908303DC */  stw      r4, 988(r3);
/* 80159AD8 3882AB34 */  la       r4, UNDEF_8042de94@sda21;
/* 80159ADC 80A304DC */  lwz      r5, 1244(r3);
/* 80159AE0 38C00000 */  li       r6, 0;
/* 80159AE4 386303DC */  addi     r3, r3, 988;
/* 80159AE8 4BF5A079 */  bl       UNDEF_800b3b60;
/* 80159AEC 2C1E0000 */  cmpwi    r30, 0;
/* 80159AF0 408200F4 */  bne-     UNDEF_80159be4;
/* 80159AF4 801F0444 */  lwz      r0, 1092(r31);
/* 80159AF8 2C000000 */  cmpwi    r0, 0;
/* 80159AFC 408200E8 */  bne-     UNDEF_80159be4;
/* 80159B00 806DADA0 */  lwz      r3, UNDEF_8042a720@sda21;
/* 80159B04 81830000 */  lwz      r12, 0(r3);
/* 80159B08 818C0010 */  lwz      r12, 16(r12);
/* 80159B0C 7D8903A6 */  mtctr    r12;
/* 80159B10 4E800421 */  bctrl    ;
/* 80159B14 3803FFFF */  subi     r0, r3, 1;
/* 80159B18 7C000034 */  cntlzw   r0, r0;
/* 80159B1C 5400D97F */  srwi.    r0, r0, 5;
/* 80159B20 40820008 */  bne-     UNDEF_80159b28;
/* 80159B24 480000C0 */  b        UNDEF_80159be4;
UNDEF_80159b28:;
/* 80159B28 3C608031 */  lis      r3, UNDEF_80315e90@ha;
/* 80159B2C 38635E90 */  addi     r3, r3, UNDEF_80315e90@l;
/* 80159B30 80630008 */  lwz      r3, 8(r3);
/* 80159B34 3803FFFE */  subi     r0, r3, 2;
/* 80159B38 28000001 */  cmplwi   r0, 1;
/* 80159B3C 408100A8 */  ble-     UNDEF_80159be4;
/* 80159B40 83DF051C */  lwz      r30, 1308(r31);
/* 80159B44 38610008 */  addi     r3, r1, 8;
/* 80159B48 C002AB40 */  lfs      f0, UNDEF_8042dea0@sda21;
/* 80159B4C 38800000 */  li       r4, 0;
/* 80159B50 80BE0090 */  lwz      r5, 144(r30);
/* 80159B54 90A10024 */  stw      r5, 36(r1);
/* 80159B58 801E00A0 */  lwz      r0, 160(r30);
/* 80159B5C 90010034 */  stw      r0, 52(r1);
/* 80159B60 83FE0084 */  lwz      r31, 132(r30);
/* 80159B64 819E0088 */  lwz      r12, 136(r30);
/* 80159B68 817E008C */  lwz      r11, 140(r30);
/* 80159B6C 815E0094 */  lwz      r10, 148(r30);
/* 80159B70 813E0098 */  lwz      r9, 152(r30);
/* 80159B74 811E009C */  lwz      r8, 156(r30);
/* 80159B78 80FE00A4 */  lwz      r7, 164(r30);
/* 80159B7C 80DE00A8 */  lwz      r6, 168(r30);
/* 80159B80 80BE00AC */  lwz      r5, 172(r30);
/* 80159B84 801E00B0 */  lwz      r0, 176(r30);
/* 80159B88 C0410024 */  lfs      f2, 36(r1);
/* 80159B8C C0210034 */  lfs      f1, 52(r1);
/* 80159B90 93E10018 */  stw      r31, 24(r1);
/* 80159B94 9181001C */  stw      r12, 28(r1);
/* 80159B98 91610020 */  stw      r11, 32(r1);
/* 80159B9C 91410028 */  stw      r10, 40(r1);
/* 80159BA0 9121002C */  stw      r9, 44(r1);
/* 80159BA4 91010030 */  stw      r8, 48(r1);
/* 80159BA8 90E10038 */  stw      r7, 56(r1);
/* 80159BAC 90C1003C */  stw      r6, 60(r1);
/* 80159BB0 90A10040 */  stw      r5, 64(r1);
/* 80159BB4 90010044 */  stw      r0, 68(r1);
/* 80159BB8 D0410008 */  stfs     f2, 8(r1);
/* 80159BBC D021000C */  stfs     f1, 12(r1);
/* 80159BC0 D0010010 */  stfs     f0, 16(r1);
/* 80159BC4 4BF59C1D */  bl       UNDEF_800b37e0;
/* 80159BC8 3C608032 */  lis      r3, UNDEF_80327a28@ha;
/* 80159BCC 38A10008 */  addi     r5, r1, 8;
/* 80159BD0 38637A28 */  addi     r3, r3, UNDEF_80327a28@l;
/* 80159BD4 38800000 */  li       r4, 0;
/* 80159BD8 38C00000 */  li       r6, 0;
/* 80159BDC 38E00000 */  li       r7, 0;
/* 80159BE0 48012DF1 */  bl       UNDEF_8016c9d0;
UNDEF_80159be4:;
/* 80159BE4 80010054 */  lwz      r0, 84(r1);
/* 80159BE8 83E1004C */  lwz      r31, 76(r1);
/* 80159BEC 83C10048 */  lwz      r30, 72(r1);
/* 80159BF0 7C0803A6 */  mtlr     r0;
/* 80159BF4 38210050 */  addi     r1, r1, 80;
/* 80159BF8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80159C00)]]
void dGameDisplay_c::setTime(int time)
{
    if (mTime == time) {
        return;
    }
    dGameCom::LayoutDispNumber(mTime = time, 3, mpTextBox_Timer, 1);
}

[[nsmbw(0x80159C30)]]
void dGameDisplay_c::setCollect()
{
    if (m0x453) {
        return;
    }

    dScStage_c* const stage = dScStage_c::m_instance;
    const dInfo_c::StageNo_s stageNo = {stage->mWorld, stage->mStage};
    if (!stageNo.isInSaveGame()) {
        return;
    }
    const dInfo_c::DemoType_e demoType = dInfo_c::m_startGameInfo.demoType;
    if (demoType == dInfo_c::DemoType_e::TITLE || demoType == dInfo_c::DemoType_e::TITLE_REPLAY) {
        return;
    }

    const dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();
    for (std::size_t coin = 0; coin < STAR_COIN_COUNT; coin++) {
        bool collected = save->isCollectCoin(stageNo.world, stageNo.stage, coin);
        if (collected && demoType == dInfo_c::DemoType_e::NONE) {
            mpaPictures[cPictureCollectOffIndex[coin]]->SetVisible(false);
            mpaPictures[cPictureCollectionIndex[coin]]->SetVisible(true);
            mCollectCoin[coin] = 2;
        } else if (stage->mCollectionCoin[coin] != PLAYER_TYPE_e::COUNT) {
            mpaPictures[cPictureCollectOffIndex[coin]]->SetVisible(false);
            mpaPictures[cPictureCollectionIndex[coin]]->SetVisible(true);
            if (mCollectCoin[coin] != 2) {
                mCollectCoin[coin] = 2;
                EffectCollectionCoinGet(coin);
            }
        } else {
            mpaPictures[cPictureCollectOffIndex[coin]]->SetVisible(true);
            mpaPictures[cPictureCollectionIndex[coin]]->SetVisible(false);
            mCollectCoin[coin] = 0;
        }
    }

    mLayout.calc();
}

[[nsmbw(0x80159DF0)]]
void dGameDisplay_c::setScore(int score)
{
    if (mScore == score || mScore >= cMaxDispScore) {
        return;
    }

    if (++mSetScoreDelay < 2) {
        return;
    }
    mSetScoreDelay = 0;
    dGameCom::LayoutDispNumber(mScore = std::min(score, cMaxDispScore), 8, mpTextBox_Score, 1);
}

[[nsmbw(0x80159E60)]]
void dGameDisplay_c::RestCoinAnimeSetup()
{
    if (PauseManager_c::m_OtasukeAfter) {
        m0x449 = true;
    }
}