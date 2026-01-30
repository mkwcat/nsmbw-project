// d_gamedisplay.cpp
// NSMBW .text: 0x80157820 - 0x8015A480

#include "d_gamedisplay.h"

#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_mj2d_game.h"
#include "framework/f_feature.h"
#include "machine/m_ef.h"
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

const long dGameDisplay_c::PLAYER_PANE_INDEX[] = {
  std::distance(X.mpaPanes, &X.mpPane_MarioIcon),
  std::distance(X.mpaPanes, &X.mpPane_LuigiIcon),
  std::distance(X.mpaPanes, &X.mpPane_KinoBIcon),
  std::distance(X.mpaPanes, &X.mpPane_KinoYIcon),
  std::distance(X.mpaPanes, &X.mpPane_KinopicoIcon),
  std::distance(X.mpaPanes, &X.mpPane_Player05Icon),
  std::distance(X.mpaPanes, &X.mpPane_Player06Icon),
  std::distance(X.mpaPanes, &X.mpPane_Player07Icon),
};

const long dGameDisplay_c::PLAYER_PICTURE_INDEX[] = {
  std::distance(X.mpaPictures, &X.mpPicture_MarioIcon),
  std::distance(X.mpaPictures, &X.mpPicture_LuigiIcon),
  std::distance(X.mpaPictures, &X.mpPicture_KinoBIcon),
  std::distance(X.mpaPictures, &X.mpPicture_KinoYIcon),
  std::distance(X.mpaPictures, &X.mpPicture_KinopicoIcon),
  std::distance(X.mpaPictures, &X.mpPicture_Player05Icon),
  std::distance(X.mpaPictures, &X.mpPicture_Player06Icon),
  std::distance(X.mpaPictures, &X.mpPicture_Player07Icon),
};

const long dGameDisplay_c::PLAYER_TEXTBOX_INDEX[] = {
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left00),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left01),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left02),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left03),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left04),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left05),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left06),
  std::distance(X.mpaTextBoxes, &X.mpTextBox_Left07),
};

const long dGameDisplay_c::PLAYER_BOTH_TEXTBOX_INDEX[][2] = {
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

#undef X

[[nsmbw(0x80157850)]]
dGameDisplay_c::dGameDisplay_c()
  : mStateMgr(*this, StateID_ProcMainGame)
  , mLayoutLoaded(false)
  , m0x452(1)
{
    OSReport("CONSTRUCT dGameDisplay_c\n");

    for (std::size_t i = 0; i < std::size(mPlayNum); i++) {
        mPlayNum[i] = -1;
    }

    m_instance = this;
}

/* VT+0x08 */
[[nsmbw(0x80157AA0)]]
dGameDisplay_c::~dGameDisplay_c()
{
    OSReport("DESTRUCT dGameDisplay_c\n");

    // TODO: Fix kuribo clang so that it actually calls the destructor of member variables. Also it
    // destroys the base class (dBase_c::~dBase_c()) before emitting the following code, instead of
    // after. Also it doesn't check if 'this' is nullptr, but maybe that's just a standard-breaking
    // optimization :3
    dGameDisplay_c::m_instance = nullptr;
    mEffect.~levelEffect_c();
    mDeathMsgMgr.~dDeathMsgMgr_c();
    mLayout.~LytBase_c();
}

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x80157B70)]]
fBase_c::PACK_RESULT_e dGameDisplay_c::create();

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[nsmbw(0x80158230)]]
fBase_c::PACK_RESULT_e dGameDisplay_c::doDelete();

/**
 * VT+0x20
 * do method for the execute operation.
 */
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

/**
 * VT+0x2C
 * do method for the draw operation.
 */
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

[[nsmbw(0x80158830)]]
bool dGameDisplay_c::createLayout()
{
    if (!mLayout.ReadResource("gameScene/gameScene.arc", false)) {
        return false;
    }

    mLayout.build("gameScene_37.brlyt", nullptr);
    mDeathMsgMgr.build(mLayout.getResAccessor(), mLayout.getDrawInfo());

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.AnimeResRegister(
      StringArray{
        "gameScene_37_inMarioCoin.brlan",
      },
      1
    );

    mLayout.GroupRegister(
      StringArray{
        "C00_inMarioCoin",
      },
      IntArray{
        0,
      },
      1
    );

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
      StringArray{
        "N_otasukeInfo_00", "N_otasukeChu_00", "N_left_00",      "N_coin_00",
        "N_collection_00",  "N_score_00",      "N_areaZanki_00", "N_areaCoin_00",
        "N_areaScore_00",   "N_marioIcon_00",  "N_luigiIcon_00", "N_kinoB_00",
        "N_kinoY_00",       "N_coin_01",       "N_time_00",      "N_proportionL_00",
        "N_proportionR_00", "N_coin1st_00",    "N_coin2nd_00",   "N_coin3rd_00",
      },
      &mpPane_OtasukeInfo, 20
    );

    mLayout.NPaneRegister(
      StringArray{
        "N_kinopico_00",
        "N_player_05",
        "N_player_06",
        "N_player_07",
      },
      mpaExPanes, EXTRA_PLAYER_COUNT
    );

    mLayout.PPaneRegister(
      StringArray{
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
      },
      &mpPicture_CollectOff00, 10
    );

    mLayout.PPaneRegister(
      StringArray{
        "P_kinopico_00",
        "P_player_05",
        "P_player_06",
        "P_player_07",
      },
      mpaExPictures, EXTRA_PLAYER_COUNT
    );

    mpPicture_Collection00->SetVisible(false);
    mpPicture_Collection01->SetVisible(false);
    mpPicture_Collection02->SetVisible(false);
    mpPicture_CollectOff00->SetVisible(true);
    mpPicture_CollectOff01->SetVisible(true);
    mpPicture_CollectOff02->SetVisible(true);

    mpPicture_MarioIcon->SetVisible(false);

    mLayout.TPaneRegister(
      StringArray{
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
      },
      &mpTextBox_Left00, 11
    );

    mLayout.TPaneRegister(
      StringArray{
        "T_left_04",
        "T_x_05",
        "T_left_05",
        "T_x_06",
        "T_left_06",
        "T_x_07",
        "T_left_07",
        "T_x_08",
      },
      mpaExTextBoxes, EXTRA_PLAYER_COUNT * 2
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_otaChuS_00",
        "T_otaChu_01",
        "T_InfoS_00",
        "T_Info_00",
      },
      IntArray{
        20,
        20,
        19,
        19,
      },
      1, 4
    );

    for (std::size_t i = 0; i < 4 + EXTRA_PLAYER_COUNT; i++) {
        mpaTexMap[i] = *mpaPictures[PLAYER_PICTURE_INDEX[i]]->GetMaterial()->GetTexturePtr(0);
        maIconSize[i] = mpaPictures[PLAYER_PICTURE_INDEX[i]]->GetSize();
        maIconScale[i] = mpaPictures[PLAYER_PICTURE_INDEX[i]]->GetScale();
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
        position[i] = mpaPictures[PLAYER_PICTURE_INDEX[i]]->GetTranslate();
        mpaPictures[PLAYER_PICTURE_INDEX[i]]->SetVisible(false);
    }

    for (std::size_t i = 0, count = 0; i < 4 + EXTRA_PLAYER_COUNT; i++) {
        if (daPyMng_c::mPlayerEntry[i] == 0) {
            continue;
        }

        std::size_t player = static_cast<std::size_t>(daPyMng_c::mPlayerType[i]);
        if (player >= 4 + EXTRA_PLAYER_COUNT) {
            continue;
        }

        mpaPictures[PLAYER_PICTURE_INDEX[player]]->SetVisible(true);
        mpaPictures[PLAYER_PICTURE_INDEX[player]]->SetTranslate(position[count++]);

        m0x414 = PLAYER_PICTURE_INDEX[player];

        int charaIndex = daPyMng_c::getPlayerColorType(static_cast<PLAYER_TYPE_e>(player));

        mpaPictures[PLAYER_PICTURE_INDEX[player]]->GetMaterial()->SetTexture(
          0, mpaTexMap[charaIndex]
        );

        nw4r::lyt::Size size = maIconSize[charaIndex];
        size.width *= (maIconScale[charaIndex].x / maIconScale[player].x);
        size.height *= (maIconScale[charaIndex].y / maIconScale[player].y);

        mpaPictures[PLAYER_PICTURE_INDEX[player]]->SetSize(size);
    }
}

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
/* 801593EC 3CA0802F */  lis      r5, PLAYER_PICTURE_INDEX__14dGameDisplay_c@ha;
// /* 801593F0 38C00001 */  li       r6, 1;
/* 801593F4 5480103A */  slwi     r0, r4, 2;
// /* 801593F8 98C80454 */  stb      r6, 1108(r8);
/* 801593FC 38A55C78 */  addi     r5, r5, PLAYER_PICTURE_INDEX__14dGameDisplay_c@l;
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
/* 80159434 3FE0802F */  lis      r31, PLAYER_BOTH_TEXTBOX_INDEX__14dGameDisplay_c@ha;
/* 80159438 7D3BEA14 */  add      r9, r27, r29; // r9 = this + (player * 0x8)
/* 8015943C A8010048 */  lha      r0, 72(r1);
/* 80159440 9081004C */  stw      r4, 76(r1);
/* 80159444 3BFF5C58 */  addi     r31, r31, PLAYER_BOTH_TEXTBOX_INDEX__14dGameDisplay_c@l;
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
/* 80159654 3CA0802F */  lis      r5, PLAYER_PICTURE_INDEX__14dGameDisplay_c@ha;
// /* 80159658 38C00000 */  li       r6, 0;
/* 8015965C 5480103A */  slwi     r0, r4, 2;
// /* 80159660 98C70454 */  stb      r6, 1108(r7);
/* 80159664 38A55CA8 */  addi     r5, r5, PLAYER_PICTURE_INDEX__14dGameDisplay_c@l;
/* 80159668 7C05002E */  lwzx     r0, r5, r0;
/* 8015966C 5400103A */  slwi     r0, r0, 2;
/* 80159670 7C630214 */  add      r3, r3, r0;
/* 80159674 80630494 */  lwz      r3, 1172(r3);
/* 80159678 81830000 */  lwz      r12, 0(r3);
/* 8015967C 818C0068 */  lwz      r12, 104(r12);
/* 80159680 7D8903A6 */  mtctr    r12;
/* 80159684 4E800421 */  bctrl;
/* 80159688 579F1838 */  slwi     r31, r28, 3;
/* 8015968C 3FA0802F */  lis      r29, PLAYER_BOTH_TEXTBOX_INDEX__14dGameDisplay_c@ha;
/* 80159690 7CBEFA14 */  add      r5, r30, r31;
/* 80159694 579C083C */  slwi     r28, r28, 1;
/* 80159698 A8050330 */  lha      r0, OFFSET_dGameDisplay_c_mPlayerRGBA0(r5);
/* 8015969C 3BBD5C88 */  addi     r29, r29, PLAYER_BOTH_TEXTBOX_INDEX__14dGameDisplay_c@l;
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

[[nsmbw(0x801599C0)]]
void dGameDisplay_c::setPlayNum(int* playNum);

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
            mEffectTimer[i] = Effect1Up(PLAYER_PANE_INDEX[i]) ? 15 : 0;
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
        dGameCom::LayoutDispNumber(newPlayNum, maxChars, mpaTextBoxes[PLAYER_TEXTBOX_INDEX[i]], 0);
    }
}

[[nsmbw(0x80159AA0)]]
void dGameDisplay_c::setCoinNum(int coinNum);

[[nsmbw(0x80159C00)]]
void dGameDisplay_c::setTime(int time);

[[nsmbw(0x80159C30)]]
void dGameDisplay_c::setCollect();

[[nsmbw(0x80159DF0)]]
void dGameDisplay_c::setScore(int score);
