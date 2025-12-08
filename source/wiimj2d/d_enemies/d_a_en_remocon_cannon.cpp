// d_a_en_remocon_cannon.cpp
// NSMBW .text: 0x80A94D90 - 0x80A97B30

#include "d_a_en_remocon_cannon.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include "egg/util/eggEffect.h"
#include "machine/m_ef.h"
#include "machine/m_vec.h"
#include "nw4r/math/types.h"
#include "sound/SndID.h"

float remoCannonGuideColorSet(int playerNo)
{
    return static_cast<float>(playerNo);
}

[[address(0x80A950A0)]]
void daEnRemoconCannon_c::setupGuide(dRemoconCannonGuide_c** guide, int mPlayerNo) ASM_METHOD(
  // clang-format off
/* 80A950A0 9421FFD0 */  stwu     r1, -48(r1);
/* 80A950A4 7C0802A6 */  mflr     r0;
/* 80A950A8 90010034 */  stw      r0, 52(r1);
/* 80A950AC DBE10020 */  stfd     f31, 32(r1);
/* 80A950B0 F3E10028 */  .long    0xF3E10028; // psq_st   f31, 40(r1), 0, 0;
/* 80A950B4 93E1001C */  stw      r31, 28(r1);
/* 80A950B8 3FE080AD */  lis      r31, UNDEF_80ad4018@ha;
/* 80A950BC 3BFF4018 */  addi     r31, r31, UNDEF_80ad4018@l;
/* 80A950C0 93C10018 */  stw      r30, 24(r1);
/* 80A950C4 7C7E1B78 */  mr       r30, r3;
/* 80A950C8 7C832378 */  mr       r3, r4;
/* 80A950CC 4B5CA835 */  bl       UNDEF_8005f900;
/* 80A950D0 2C030000 */  cmpwi    r3, 0;
/* 80A950D4 C3FF0028 */  lfs      f31, 40(r31);
/* 80A950D8 41820084 */  beq-     UNDEF_80a9515c;
/* 80A950DC          */  lwz      r3, 5332(r3);
                         bl       remoCannonGuideColorSet__Fi;
                         fmr      f31, f0;
/* 80A9511C 387E0080 */  addi     r3, r30, 128;
/* 80A95120 38800001 */  li       r4, 1;
/* 80A95124 38A00000 */  li       r5, 0;
/* 80A95128 4B6D1F59 */  bl       UNDEF_80167080;
/* 80A9512C C03F0028 */  lfs      f1, 40(r31);
/* 80A95130 387E0004 */  addi     r3, r30, 4;
/* 80A95134 389E0080 */  addi     r4, r30, 128;
/* 80A95138 4B6D4F89 */  bl       UNDEF_8016a0c0;
/* 80A9513C FC20F890 */  fmr      f1, f31;
/* 80A95140 387E0080 */  addi     r3, r30, 128;
/* 80A95144 38800000 */  li       r4, 0;
/* 80A95148 4B6D1EE9 */  bl       UNDEF_80167030;
/* 80A9514C C03F0028 */  lfs      f1, 40(r31);
/* 80A95150 387E0080 */  addi     r3, r30, 128;
/* 80A95154 38800000 */  li       r4, 0;
/* 80A95158 4B6D1EF9 */  bl       UNDEF_80167050;
UNDEF_80a9515c:;
/* 80A9515C 3C8080B0 */  lis      r4, UNDEF_80b05864@ha;
/* 80A95160 7FC3F378 */  mr       r3, r30;
/* 80A95164 38845864 */  addi     r4, r4, UNDEF_80b05864@l;
/* 80A95168 4B7A5089 */  bl       UNDEF_8023a1f0;
/* 80A9516C 90610008 */  stw      r3, 8(r1);
/* 80A95170 387E0044 */  addi     r3, r30, 68;
/* 80A95174 389E0004 */  addi     r4, r30, 4;
/* 80A95178 38A10008 */  addi     r5, r1, 8;
/* 80A9517C 38C00001 */  li       r6, 1;
/* 80A95180 4B6D01B1 */  bl       UNDEF_80165330;
/* 80A95184 C03F0024 */  lfs      f1, 36(r31);
/* 80A95188 387E0044 */  addi     r3, r30, 68;
/* 80A9518C 4B6D3095 */  bl       UNDEF_80168220;
/* 80A95190 C03F0028 */  lfs      f1, 40(r31);
/* 80A95194 387E0004 */  addi     r3, r30, 4;
/* 80A95198 389E0044 */  addi     r4, r30, 68;
/* 80A9519C 4B6D4F25 */  bl       UNDEF_8016a0c0;
/* 80A951A0 80010034 */  lwz      r0, 52(r1);
/* 80A951A4 E3E10028 */  .long    0xE3E10028; // psq_l    f31, 40(r1), 0, 0;
/* 80A951A8 CBE10020 */  lfd      f31, 32(r1);
/* 80A951AC 83E1001C */  lwz      r31, 28(r1);
/* 80A951B0 83C10018 */  lwz      r30, 24(r1);
/* 80A951B4 7C0803A6 */  mtlr     r0;
/* 80A951B8 38210030 */  addi     r1, r1, 48;
/* 80A951BC 4E800020 */  blr      ;
  // clang-format on
);

[[address(0x80A854B0)]]
void daEnRemoconCannon_c::createModel() ASM_METHOD(
  // clang-format off
/* 80A954B0 9421FFD0 */  stwu     r1, -48(r1);
/* 80A954B4 7C0802A6 */  mflr     r0;
/* 80A954B8 3C808037 */  lis      r4, UNDEF_80377f48@ha;
/* 80A954BC 38C00000 */  li       r6, 0;
/* 80A954C0 90010034 */  stw      r0, 52(r1);
/* 80A954C4 38E00020 */  li       r7, 32;
/* 80A954C8 93E1002C */  stw      r31, 44(r1);
/* 80A954CC 93C10028 */  stw      r30, 40(r1);
/* 80A954D0 3FC080B0 */  lis      r30, UNDEF_80b05808@ha;
/* 80A954D4 3BDE5808 */  addi     r30, r30, UNDEF_80b05808@l;
/* 80A954D8 93A10024 */  stw      r29, 36(r1);
/* 80A954DC 7C7D1B78 */  mr       r29, r3;
/* 80A954E0 38630524 */  addi     r3, r3, 1316;
/* 80A954E4 80A47F48 */  lwz      r5, UNDEF_80377f48@l(r4);
/* 80A954E8 3880FFFF */  li       r4, -1;
/* 80A954EC 4B5D3BD5 */  bl       UNDEF_800690c0;
/* 80A954F0 3C608043 */  lis      r3, UNDEF_8042a318@ha;
/* 80A954F4 38BE000C */  addi     r5, r30, 12;
/* 80A954F8 8063A318 */  lwz      r3, UNDEF_8042a318@l(r3);
/* 80A954FC 389E0028 */  addi     r4, r30, 40;
/* 80A95500 38630004 */  addi     r3, r3, 4;
/* 80A95504 4B649D6D */  bl       UNDEF_800df270;
/* 80A95508 907D0540 */  stw      r3, 1344(r29);
/* 80A9550C 387D0540 */  addi     r3, r29, 1344;
/* 80A95510 389E0028 */  addi     r4, r30, 40;
/* 80A95514 4B7A4A5D */  bl       UNDEF_80239f70;
/* 80A95518 90610008 */  stw      r3, 8(r1);
/* 80A9551C 7C7F1B78 */  mr       r31, r3;
/* 80A95520 387D0544 */  addi     r3, r29, 1348;
/* 80A95524 38810008 */  addi     r4, r1, 8;
/* 80A95528 38BD0524 */  addi     r5, r29, 1316;
/* 80A9552C 38C00023 */  li       r6, 35;
/* 80A95530 38E00001 */  li       r7, 1;
/* 80A95534 39000000 */  li       r8, 0;
/* 80A95538 4B6D4999 */  bl       UNDEF_80169ed0;
/* 80A9553C 387D0544 */  addi     r3, r29, 1348;
/* 80A95540 4B5CF6B1 */  bl       UNDEF_80064bf0;
/* 80A95544 387D0540 */  addi     r3, r29, 1344;
/* 80A95548 389E0068 */  addi     r4, r30, 104;
/* 80A9554C 4B7A4CA5 */  bl       UNDEF_8023a1f0;
/* 80A95550 90610018 */  stw      r3, 24(r1);
/* 80A95554 387D08C4 */  addi     r3, r29, 2244;
/* 80A95558 3881001C */  addi     r4, r1, 28;
/* 80A9555C 38A10018 */  addi     r5, r1, 24;
/* 80A95560 93E1001C */  stw      r31, 28(r1);
/* 80A95564 38DD0524 */  addi     r6, r29, 1316;
/* 80A95568 38E00000 */  li       r7, 0;
/* 80A9556C 4B6CFCA5 */  bl       UNDEF_80165210;
/* 80A95570 387D0540 */  addi     r3, r29, 1344;
/* 80A95574 389E0028 */  addi     r4, r30, 40;
/* 80A95578 4B7A4DC9 */  bl       UNDEF_8023a340;
/* 80A9557C 907D0894 */  stw      r3, 2196(r29);
/* 80A95580 38810014 */  addi     r4, r1, 20;
/* 80A95584 38A10010 */  addi     r5, r1, 16;
/* 80A95588 38DD0524 */  addi     r6, r29, 1316;
/* 80A9558C 90610010 */  stw      r3, 16(r1);
/* 80A95590 387D0898 */  addi     r3, r29, 2200;
/* 80A95594 38E00000 */  li       r7, 0;
/* 80A95598 39000001 */  li       r8, 1;
/* 80A9559C 93E10014 */  stw      r31, 20(r1);
/* 80A955A0 4B6D13D1 */  bl       UNDEF_80166970;
/* 80A955A4 801D0894 */  lwz      r0, 2196(r29);
/* 80A955A8 387D0898 */  addi     r3, r29, 2200;
/* 80A955AC 9001000C */  stw      r0, 12(r1);
/* 80A955B0 389D0544 */  addi     r4, r29, 1348;
/* 80A955B4 38A1000C */  addi     r5, r1, 12;
/* 80A955B8 38C00000 */  li       r6, 0;
/* 80A955BC 38E00001 */  li       r7, 1;
/* 80A955C0 4B6D1751 */  bl       UNDEF_80166d10;
/* 80A955C4 819D0544 */  lwz      r12, 1348(r29);
/* 80A955C8 387D0544 */  addi     r3, r29, 1348;
/* 80A955CC 389D0898 */  addi     r4, r29, 2200;
/* 80A955D0 818C0018 */  lwz      r12, 24(r12);
/* 80A955D4 7D8903A6 */  mtctr    r12;
/* 80A955D8 4E800421 */  bctrl    ;
/* 80A955DC 3FE080AD */  lis      r31, UNDEF_80ad4040@ha;
/* 80A955E0 387D0898 */  addi     r3, r29, 2200;
/* 80A955E4 C03F4040 */  lfs      f1, UNDEF_80ad4040@l(r31);
/* 80A955E8 38800000 */  li       r4, 0;
/* 80A955EC 4B6D1A45 */  bl       UNDEF_80167030;
/* 80A955F0 C03F4040 */  lfs      f1, UNDEF_80ad4040@l(r31);
/* 80A955F4 387D0898 */  addi     r3, r29, 2200;
/* 80A955F8 38800000 */  li       r4, 0;
/* 80A955FC 4B6D1A55 */  bl       UNDEF_80167050;
/* 80A95600 387D07BC */  addi     r3, r29, 1980;
/* 80A95604 389D0524 */  addi     r4, r29, 1316;
/* 80A95608 4BFFF989 */  bl       UNDEF_80a94f90;
/* 80A9560C 38000000 */  li       r0, 0;
/* 80A95610          */  stb      r0, 2912(r29);
/* 80A95614 387D0524 */  addi     r3, r29, 1316;
/* 80A95618          */  stb      r0, 2913(r29);
/* 80A9561C          */  stb      r0, 2914(r29);
/* 80A95620          */  stb      r0, 2915(r29);
                         stb      r0, 2916(r29);
                         stb      r0, 2917(r29);
                         stb      r0, 2918(r29);
                         stb      r0, 2919(r29);
/* 80A95624 981D0888 */  stb      r0, 2184(r29);
/* 80A95628 981D0B50 */  stb      r0, 2896(r29);
/* 80A9562C 4B5D3AB5 */  bl       UNDEF_800690e0;
/* 80A95630 80010034 */  lwz      r0, 52(r1);
/* 80A95634 83E1002C */  lwz      r31, 44(r1);
/* 80A95638 83C10028 */  lwz      r30, 40(r1);
/* 80A9563C 83A10024 */  lwz      r29, 36(r1);
/* 80A95640 7C0803A6 */  mtlr     r0;
/* 80A95644 38210030 */  addi     r1, r1, 48;
/* 80A95648 4E800020 */  blr      ;
/* 80A9564C 00000000 */  .word    0x00000000;
  // clang-format on
);

[[address(0x80A95890)]]
void daEnRemoconCannon_c::setBodyColor()
{
    if (mPlayerNo > -1) {
        dAcPy_c* player = daPyMng_c::getPlayer(mPlayerNo);
        float frame = 0.0;
        if (player != nullptr) {
            frame = static_cast<float>(player->mPlayerType + 1);
            mAnmTexPat.setFrame(frame, 0);
            mAnmTexPat.setRate(0.0, 0);
            player->playSound(SndID::SE_OBJ_RC_CONTROL_ON, 0);
        }
        setupGuide(&mpGuide, mPlayerNo);
        mHasPlayer = true;
        mPlayerNo2 = mPlayerNo;
        dGameCom::FUN_800B3600(mPlayerNo, 0xF);
    }
}

static constinit const nw4r::ut::Color PLY_TRAIL_EFF_COLOR_1[] = {
    "#FFCCDD", // Mario
    "#CCFFCE", // Luigi
    "#FFFFFF", // Blue Toad
    "#FFFFAC", // Yellow Toad
    "#FFCEFF", // Toadette
    "#CCACFF", // Purple Toadette
    "#FFCCAC", // Orange Toad
    "#ACACAC", // Black Toad
};

static constinit const nw4r::ut::Color PLY_TRAIL_EFF_COLOR_2[] = {
    "#FF2970", // Mario
    "#29FF33", // Luigi
    "#6CFFFF", // Blue Toad
    "#FFFF00", // Yellow Toad
    "#FF6CFF", // Toadette
    "#AC6CFF", // Purple Toadette
    "#FFAC70", // Orange Toad
    "#6C6C6C", // Black Toad
};

[[address(0x80A95990)]]
void daEnRemoconCannon_c::EffectDischargeTail()
{
    GXColor color0, color1;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c *ply = daPyMng_c::getPlayer(i);
        if (((ply != nullptr) && !ply->isStatus(0x7D)) && mCannonFired[i]) {
            mVec3_c effPos = {ply->mPos.x, ply->mPos.y, 5500.0};

            int playerType = ply->mPlayerType;
            if (playerType >= PLAYER_COUNT) {
                color0 = {0xFF, 0xFF, 0xFF, 0xFF};
                color1 = {0xFF, 0xFF, 0xFF, 0xFF};
            } else {
                color0 = PLY_TRAIL_EFF_COLOR_1[playerType];
                color1 = PLY_TRAIL_EFF_COLOR_2[playerType];
            }

            mEffectTrail[0].createEffect("Wm_mg_dischargetail01", 0, &effPos, nullptr, nullptr);
            mEffectTrail[0].setRegisterColor(color0, color1, 0, EGG::Effect::ERecursive::RECURSIVE_3);
            mEffectTrail[0].setRegisterAlpha(color0.a, color1.a, 0, EGG::Effect::ERecursive::RECURSIVE_3);

            mEffectTrail[1].createEffect("Wm_mg_dischargetail02", 0, &effPos, nullptr, nullptr);
            mEffectTrail[1].setRegisterColor(color0, color1, 0, EGG::Effect::ERecursive::RECURSIVE_3);
            mEffectTrail[1].setRegisterAlpha(color0.a, color1.a, 0, EGG::Effect::ERecursive::RECURSIVE_3);
        }
    }
}

[[address(0x80A95C00)]]
void daEnRemoconCannon_c::UNDEF_80a95c00() ASM_METHOD(
  // clang-format off
/* 80A95C00 9421FFE0 */  stwu     r1, -32(r1);
/* 80A95C04 7C0802A6 */  mflr     r0;
/* 80A95C08 90010024 */  stw      r0, 36(r1);
/* 80A95C0C 93E1001C */  stw      r31, 28(r1);
/* 80A95C10 3FE0809A */  lis      r31, UNDEF_8099cc60@ha;
/* 80A95C14 93C10018 */  stw      r30, 24(r1);
/* 80A95C18 3BC00000 */  li       r30, 0;
/* 80A95C1C 93A10014 */  stw      r29, 20(r1);
/* 80A95C20 7C7D1B78 */  mr       r29, r3;
UNDEF_80a95c24:;
/* 80A95C24 7FC3F378 */  mr       r3, r30;
/* 80A95C28 4B5C9CD9 */  bl       UNDEF_8005f900;
/* 80A95C2C 2C030000 */  cmpwi    r3, 0;
/* 80A95C30 41820038 */  beq-     UNDEF_80a95c68;
/* 80A95C34 3880007D */  li       r4, 125;
/* 80A95C38 4B5C10B9 */  bl       UNDEF_80056cf0;
/* 80A95C3C 2C030000 */  cmpwi    r3, 0;
/* 80A95C40 41820028 */  beq-     UNDEF_80a95c68;
/* 80A95C44 7C7DF214 */  add      r3, r29, r30;
/* 80A95C48          */  lbz      r0, 2912(r3);
/* 80A95C4C 2C000000 */  cmpwi    r0, 0;
/* 80A95C50 41820018 */  beq-     UNDEF_80a95c68;
/* 80A95C54 807FCC60 */  lwz      r3, UNDEF_8099cc60@l(r31);
/* 80A95C58 2C030000 */  cmpwi    r3, 0;
/* 80A95C5C 4182000C */  beq-     UNDEF_80a95c68;
/* 80A95C60 7FC4F378 */  mr       r4, r30;
/* 80A95C64 4BDD09ED */  bl       UNDEF_80866650;
UNDEF_80a95c68:;
/* 80A95C68 3BDE0001 */  addi     r30, r30, 1;
/* 80A95C6C          */  cmpwi    r30, PLAYER_COUNT;
/* 80A95C70 4180FFB4 */  blt+     UNDEF_80a95c24;
/* 80A95C74 80010024 */  lwz      r0, 36(r1);
/* 80A95C78 83E1001C */  lwz      r31, 28(r1);
/* 80A95C7C 83C10018 */  lwz      r30, 24(r1);
/* 80A95C80 83A10014 */  lwz      r29, 20(r1);
/* 80A95C84 7C0803A6 */  mtlr     r0;
/* 80A95C88 38210020 */  addi     r1, r1, 32;
/* 80A95C8C 4E800020 */  blr      ;
  // clang-format on
);

[[address(0x80A960A0)]]
void daEnRemoconCannon_c::firePlayer(int playerType)
{
    float modifiers[4] = {15.0, 7.0, 7.0, 7.0};

    dAcPy_c *ply = daPyMng_c::getPlayer(playerType);
    if (ply != nullptr) {
        ply->endDemoDokanCannon(mStagePos);
        float mod = modifiers[mParam & 3];
        float accelF = nw4r::math::SinFIdx(mTargetAngle * 1.875 * 0.00390625);
        float speedY = nw4r::math::CosFIdx(mTargetAngle * 1.875 * 0.00390625);

        ply->setCannonJump(mod * speedY, mod * accelF, 1000);
        ply->onStatus(0x8E);

        mCannonFired[*ply->getPlrNo()] = true;
    }
}


[[address(0x80A96210)]]
mVec3_c daEnRemoconCannon_c::calcTiltPos();

[[address(0x80A964E0)]]
bool daEnRemoconCannon_c::UNDEF_80a964e0(short target)
{
    return dGameCom::CalculateTiltShoulder(&mTargetAngle, target, 400, mPlayerNo, 0x3520);
}

[[address(0x80A96C10)]]
void daEnRemoconCannon_c::initializeState_Fire() ASM_METHOD(
/* 80A96C10 9421FFA0 */  stwu     r1, -96(r1);
/* 80A96C14 7C0802A6 */  mflr     r0;
/* 80A96C18 90010064 */  stw      r0, 100(r1);
/* 80A96C1C 39610060 */  addi     r11, r1, 96;
/* 80A96C20 4B846445 */  bl       UNDEF_802dd064;
/* 80A96C24 7C7B1B78 */  mr       r27, r3;
/* 80A96C28 3FA080AD */  lis      r29, UNDEF_80ad4018@ha;
/* 80A96C2C 3FC080B0 */  lis      r30, UNDEF_80b05808@ha;
/* 80A96C30 3BE00000 */  li       r31, 0;
/* 80A96C34 B3E30500 */  sth      r31, 1280(r3);
/* 80A96C38 7F64DB78 */  mr       r4, r27;
/* 80A96C3C 3BBD4018 */  addi     r29, r29, UNDEF_80ad4018@l;
/* 80A96C40 3BDE5808 */  addi     r30, r30, UNDEF_80b05808@l;
/* 80A96C44 3861002C */  addi     r3, r1, 44;
/* 80A96C48 4BFFF5C9 */  bl       UNDEF_80a96210;
/* 80A96C4C C001002C */  lfs      f0, 44(r1);
/* 80A96C50 3CA08043 */  lis      r5, UNDEF_8042a040@ha;
/* 80A96C54 D01B078C */  stfs     f0, 1932(r27);
/* 80A96C58 38610010 */  addi     r3, r1, 16;
/* 80A96C5C 389B078C */  addi     r4, r27, 1932;
/* 80A96C60 C0010030 */  lfs      f0, 48(r1);
/* 80A96C64 D01B0790 */  stfs     f0, 1936(r27);
/* 80A96C68 C0010034 */  lfs      f0, 52(r1);
/* 80A96C6C D01B0794 */  stfs     f0, 1940(r27);
/* 80A96C70 8385A040 */  lwz      r28, UNDEF_8042a040@l(r5);
/* 80A96C74 4B5D383D */  bl       UNDEF_8006a4b0;
/* 80A96C78 7F83E378 */  mr       r3, r28;
/* 80A96C7C 38A10010 */  addi     r5, r1, 16;
/* 80A96C80 388005F6 */  li       r4, 1526;
/* 80A96C84 38C00000 */  li       r6, 0;
/* 80A96C88 4B7020E9 */  bl       UNDEF_80198d70;
/* 80A96C8C 38000001 */  li       r0, 1;
/* 80A96C90 901B0360 */  stw      r0, 864(r27);
/* 80A96C94 387B0540 */  addi     r3, r27, 1344;
/* 80A96C98 389E00B4 */  addi     r4, r30, 180;
/* 80A96C9C 4B7A3555 */  bl       UNDEF_8023a1f0;
/* 80A96CA0 90610008 */  stw      r3, 8(r1);
/* 80A96CA4 387B08C4 */  addi     r3, r27, 2244;
/* 80A96CA8 389B0544 */  addi     r4, r27, 1348;
/* 80A96CAC 38A10008 */  addi     r5, r1, 8;
/* 80A96CB0 38C00001 */  li       r6, 1;
/* 80A96CB4 4B6CE67D */  bl       UNDEF_80165330;
/* 80A96CB8 C03D0024 */  lfs      f1, 36(r29);
/* 80A96CBC 387B08C4 */  addi     r3, r27, 2244;
/* 80A96CC0 4B6D1561 */  bl       UNDEF_80168220;
/* 80A96CC4 C03D0028 */  lfs      f1, 40(r29);
/* 80A96CC8 387B0544 */  addi     r3, r27, 1348;
/* 80A96CCC 389B08C4 */  addi     r4, r27, 2244;
/* 80A96CD0 4B6D33F1 */  bl       UNDEF_8016a0c0;

// REMOVED 80A96CD4 - 80A96DBC
                         mr       r3, r27;
                         bl       EffectDischarge__19daEnRemoconCannon_cFv;

/* 80A96DBC 39610060 */  addi     r11, r1, 96;
/* 80A96DC0 4B8462F1 */  bl       UNDEF_802dd0b0;
/* 80A96DC4 80010064 */  lwz      r0, 100(r1);
/* 80A96DC8 7C0803A6 */  mtlr     r0;
/* 80A96DCC 38210060 */  addi     r1, r1, 96;
/* 80A96DD0 4E800020 */  blr      ;
);

// Originally part of initializeState_Fire()
void daEnRemoconCannon_c::EffectDischarge()
{
    const char *PLY_EFFECT_NAME[] = {
        "Wm_mg_discharge03_r",
        "Wm_mg_discharge03_g",
        "Wm_mg_discharge03_b",
        "Wm_mg_discharge03_y",
        // TODO: figure out how to handle these
        "Wm_mg_discharge03_r",
        "Wm_mg_discharge03_r",
        "Wm_mg_discharge03_r",
        "Wm_mg_discharge03_r",
    };

    mVec3_c tiltPos = calcTiltPos();
    mVec3_c effPos = {tiltPos.x, tiltPos.y, 5500.0};

    s16 angZ = -_7A6;
    mAng3_c effAng = {0, 0, angZ};

    mEf::createEffect("Wm_mg_discharge01", 0, &effPos, &effAng, nullptr);
    mEf::createEffect("Wm_mg_discharge02", 0, &effPos, &effAng, nullptr);

    dAcPy_c *ply = daPyMng_c::getPlayer(mPlayerNo);
    if (ply != nullptr) {
        const char *effName = PLY_EFFECT_NAME[*ply->getPlrNo()];
        mEf::createEffect(effName, 0, &effPos, &effAng, nullptr);
    }

    mHasPlayer = false;
}