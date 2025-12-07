// d_a_yoshi_egg.cpp
// NSMBW d_bases.text: 0x80910F00 - 0x809125E0

#include "d_a_yoshi_egg.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_yoshi_model.h"
#include "machine/m_ef.h"

extern const float c_eggColorFrames[dYoshiMdl_c::COLOR_COUNT] = {
  0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0,
};

[[address(0x80911380)]]
void daYoshiEgg_c::loadModel() ASM_METHOD(
  // clang-format off
/* 80911380 9421FFB0 */  stwu     r1, -80(r1);
/* 80911384 7C0802A6 */  mflr     r0;
/* 80911388 90010054 */  stw      r0, 84(r1);
/* 8091138C 39610040 */  addi     r11, r1, 64;
/* 80911390 DBE10040 */  stfd     f31, 64(r1);
/* 80911394 F3E10048 */  .long    0xF3E10048;
/* 80911398 4B9CBCCD */  bl       UNDEF_802dd064;
/* 8091139C 3C808037 */  lis      r4, UNDEF_80377f48@ha;
/* 809113A0 3F808099 */  lis      r28, UNDEF_80989d08@ha;
/* 809113A4 3FA08094 */  lis      r29, UNDEF_8093da40@ha;
/* 809113A8 80A47F48 */  lwz      r5, UNDEF_80377f48@l(r4);
/* 809113AC 7C7B1B78 */  mr       r27, r3;
/* 809113B0 3B9C9D08 */  addi     r28, r28, UNDEF_80989d08@l;
/* 809113B4 3BBDDA40 */  addi     r29, r29, UNDEF_8093da40@l;
/* 809113B8 3880FFFF */  li       r4, -1;
/* 809113BC 38C00000 */  li       r6, 0;
/* 809113C0 38E00020 */  li       r7, 32;
/* 809113C4 38630524 */  addi     r3, r3, 1316;
/* 809113C8 4B757CF9 */  bl       UNDEF_800690c0;
/* 809113CC 3C608043 */  lis      r3, UNDEF_8042a318@ha;
/* 809113D0 38BC000C */  addi     r5, r28, 12;
/* 809113D4 8063A318 */  lwz      r3, UNDEF_8042a318@l(r3);
/* 809113D8 389C0024 */  addi     r4, r28, 36;
/* 809113DC 38630004 */  addi     r3, r3, 4;
/* 809113E0 4B7CDE91 */  bl       UNDEF_800df270;
/* 809113E4 907B0540 */  stw      r3, 1344(r27);
/* 809113E8 387B0540 */  addi     r3, r27, 1344;
/* 809113EC 389C0024 */  addi     r4, r28, 36;
/* 809113F0 4B928B81 */  bl       UNDEF_80239f70;
/* 809113F4 90610018 */  stw      r3, 24(r1);
/* 809113F8 7C7E1B78 */  mr       r30, r3;
/* 809113FC 387B0544 */  addi     r3, r27, 1348;
/* 80911400 38810018 */  addi     r4, r1, 24;
/* 80911404 38BB0524 */  addi     r5, r27, 1316;
/* 80911408 38C00023 */  li       r6, 35;
/* 8091140C 38E00001 */  li       r7, 1;
/* 80911410 39000000 */  li       r8, 0;
/* 80911414 4B858ABD */  bl       UNDEF_80169ed0;
/* 80911418 387B0544 */  addi     r3, r27, 1348;
/* 8091141C 4B7537F5 */  bl       UNDEF_80064c10;
/* 80911420 387B0540 */  addi     r3, r27, 1344;
/* 80911424 389C0030 */  addi     r4, r28, 48;
/* 80911428 4B928DC9 */  bl       UNDEF_8023a1f0;
/* 8091142C 90610010 */  stw      r3, 16(r1);
/* 80911430 7C7F1B78 */  mr       r31, r3;
/* 80911434 387B0584 */  addi     r3, r27, 1412;
/* 80911438 38810014 */  addi     r4, r1, 20;
/* 8091143C 93C10014 */  stw      r30, 20(r1);
/* 80911440 38A10010 */  addi     r5, r1, 16;
/* 80911444 38DB0524 */  addi     r6, r27, 1316;
/* 80911448 38E00000 */  li       r7, 0;
/* 8091144C 4B853DC5 */  bl       UNDEF_80165210;
/* 80911450 93E10020 */  stw      r31, 32(r1);
/* 80911454 387B0584 */  addi     r3, r27, 1412;
/* 80911458 389B0544 */  addi     r4, r27, 1348;
/* 8091145C 38A10020 */  addi     r5, r1, 32;
/* 80911460 38C00000 */  li       r6, 0;
/* 80911464 4B853ECD */  bl       UNDEF_80165330;
/* 80911468 C03D0060 */  lfs      f1, 96(r29);
/* 8091146C 387B0544 */  addi     r3, r27, 1348;
/* 80911470 389B0584 */  addi     r4, r27, 1412;
/* 80911474 4B858C4D */  bl       UNDEF_8016a0c0;
/* 80911478 387B0540 */  addi     r3, r27, 1344;
/* 8091147C 389C0024 */  addi     r4, r28, 36;
/* 80911480 4B928EC1 */  bl       UNDEF_8023a340;
/* 80911484 907B05BC */  stw      r3, 1468(r27);
/* 80911488 3881000C */  addi     r4, r1, 12;
/* 8091148C 38A10008 */  addi     r5, r1, 8;
/* 80911490 38DB0524 */  addi     r6, r27, 1316;
/* 80911494 90610008 */  stw      r3, 8(r1);
/* 80911498 387B05C0 */  addi     r3, r27, 1472;
/* 8091149C 38E00000 */  li       r7, 0;
/* 809114A0 39000001 */  li       r8, 1;
/* 809114A4 93C1000C */  stw      r30, 12(r1);
/* 809114A8 4B8554C9 */  bl       UNDEF_80166970;
/* 809114AC 387B0524 */  addi     r3, r27, 1316;
/* 809114B0 4B757C31 */  bl       UNDEF_800690e0;
/* 809114B4 80BB05F8 */  lwz      r5, 1528(r27);
/* 809114B8 389D0070 */  addi     r4, r29, 112;
/* 809114BC 801B05BC */  lwz      r0, 1468(r27);
/* 809114C0 387B05C0 */  addi     r3, r27, 1472;
/* 809114C4 54A5103A */  slwi     r5, r5, 2;
/* 809114C8 9001001C */  stw      r0, 28(r1);
                         lis      r4, c_eggColorFrames@ha;
                         addi     r4, r4, c_eggColorFrames@l;
/* 809114CC 7FE42C2E */  lfsx     f31, r4, r5;
/* 809114D0 389B0544 */  addi     r4, r27, 1348;
/* 809114D4 38A1001C */  addi     r5, r1, 28;
/* 809114D8 38C00000 */  li       r6, 0;
/* 809114DC 38E00001 */  li       r7, 1;
/* 809114E0 4B855831 */  bl       UNDEF_80166d10;
/* 809114E4 819B0544 */  lwz      r12, 1348(r27);
/* 809114E8 387B0544 */  addi     r3, r27, 1348;
/* 809114EC 389B05C0 */  addi     r4, r27, 1472;
/* 809114F0 818C0018 */  lwz      r12, 24(r12);
/* 809114F4 7D8903A6 */  mtctr    r12;
/* 809114F8 4E800421 */  bctrl    ;
/* 809114FC FC20F890 */  fmr      f1, f31;
/* 80911500 387B05C0 */  addi     r3, r27, 1472;
/* 80911504 38800000 */  li       r4, 0;
/* 80911508 4B855B29 */  bl       UNDEF_80167030;
/* 8091150C C03D0058 */  lfs      f1, 88(r29);
/* 80911510 387B05C0 */  addi     r3, r27, 1472;
/* 80911514 38800000 */  li       r4, 0;
/* 80911518 4B855B39 */  bl       UNDEF_80167050;
/* 8091151C 39610040 */  addi     r11, r1, 64;
/* 80911520 E3E10048 */  .long    0xE3E10048;
/* 80911524 CBE10040 */  lfd      f31, 64(r1);
/* 80911528 4B9CBB89 */  bl       UNDEF_802dd0b0;
/* 8091152C 80010054 */  lwz      r0, 84(r1);
/* 80911530 7C0803A6 */  mtlr     r0;
/* 80911534 38210050 */  addi     r1, r1, 80;
/* 80911538 4E800020 */  blr;
  // clang-format on
)

  [[address(0x80911540)]] void daYoshiEgg_c::playAnimation(int);

[[address(0x80911610)]]
void daYoshiEgg_c::spawnEggBreakEffect()
{
    // TODO: Add effects for new egg colors
    const char* eggBreakEffects[dYoshiMdl_c::COLOR_COUNT] = {
      "Wm_ob_eggbreak_gr", "Wm_ob_eggbreak_rd", "Wm_ob_eggbreak_yw", "Wm_ob_eggbreak_bl",
      "Wm_ob_eggbreak_rd", "Wm_ob_eggbreak_yw", "Wm_ob_eggbreak_bl", "Wm_ob_eggbreak_bl",
    };

    mEf::createEffect(eggBreakEffects[mColor], 0, &mPos, nullptr, nullptr);
}

[[address(0x80911680)]]
void daYoshiEgg_c::hatchYoshi()
{
    spawnEggBreakEffect();
    daPyMng_c::createYoshi(mPos, mColor, nullptr);
    deleteRequest();
}

[[address(0x80911AD0)]]
void daYoshiEgg_c::initializeState_MultiJumpUp()
{
    // Add some variation to the spawning speeds if >4 players
    if (daPyMng_c::getNumInGame() > 4) {
        float randomXSpeed = dGameCom::rndF(1.3) + 0.6;
        if (mDirection != 0) {
            randomXSpeed = -randomXSpeed;
        }
        mSpeed.x = randomXSpeed;
        mSpeed.y = dGameCom::rndF(2.1) + 2.5;
    } else {
        if (m0x5F4 == 0) {
            float randomXSpeed = dGameCom::rndF(0.7) + 0.3;
            if (mDirection != 0) {
                randomXSpeed = -randomXSpeed;
            }
            mSpeed.x = randomXSpeed;
            mSpeed.y = dGameCom::rndF(2.1) + 2.5;
        } else {
            mSpeed.x = (mDirection == 0) ? 1.8 : -1.8;
            mSpeed.y = 3.4;
        }
    }
    mSpeed.z = 0.0;
    m0x60C = 1;
    m0x60C = 0xD;
    playAnimation(1);
}

[[address(0x80911BD0)]]
void daYoshiEgg_c::initializeState_MultiJumpDown()
{
    // Add some variation to the spawning speeds if >4 players
    if (daPyMng_c::getNumInGame() > 4) {
        float randomXSpeed = dGameCom::rndF(1.3) + 0.6;
        if (mDirection != 0) {
            randomXSpeed = -randomXSpeed;
        }
        mSpeed.x = randomXSpeed;
    } else {
        if (m0x5F4 == 0) {
            float randomXSpeed = dGameCom::rndF(0.7) + 0.3;
            if (mDirection != 0) {
                randomXSpeed = -randomXSpeed;
            }
            mSpeed.x = randomXSpeed;
        } else {
            mSpeed.x = (mDirection == 0) ? 2.0 : -2.0;
        }
    }
    mSpeed.y = -0.5;
    mSpeed.z = 0.0;
    m0x60C = 1;
    m0x60C = 0xD;
    playAnimation(1);
}