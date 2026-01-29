// d_yoshi_model.cpp
// NSMBW .text: 0x800FE2E0 - 0x800FFF80

#include "d_yoshi_model.h"
#include "d_bases/d_s_stage.h"
#include "d_system/d_game_common.h"
#include "framework/f_feature.h"

extern const char* const c_yoshiColorNames[dYoshiMdl_c::COLOR_COUNT] = {
  "Y_TexGreen",   "Y_TexRed",    "Y_TexYellow", "Y_TexBlue",
  "Y_TexCrimson", "Y_TexOrange", "Y_TexPurple", "Y_TexAzure",
};

[[nsmbw(0x800FE2E0)]]
dYoshiMdl_c::dYoshiMdl_c(u8 index);

[[nsmbw(0x800FE510)]]
void dYoshiMdl_c::getPlayerObjectRes() ASM_METHOD(
  // clang-format off
/* 800FE510 9421FFD0 */  stwu     r1, -48(r1);
/* 800FE514 7C0802A6 */  mflr     r0;
/* 800FE518 90010034 */  stw      r0, 52(r1);
/* 800FE51C 93E1002C */  stw      r31, 44(r1);
/* 800FE520 7C7F1B78 */  mr       r31, r3;
/* 800FE524 93C10028 */  stw      r30, 40(r1);
/* 800FE528 3FC08032 */  lis      r30, UNDEF_8031c530@ha;
/* 800FE52C 3BDEC530 */  addi     r30, r30, UNDEF_8031c530@l;
/* 800FE530 808DA998 */  lwz      r4, UNDEF_8042a318@sda21;
/* 800FE534 38BE0040 */  addi     r5, r30, 64;
/* 800FE538 38640004 */  addi     r3, r4, 4;
/* 800FE53C 388D9560 */  la       r4, UNDEF_80428ee0@sda21;
/* 800FE540 4BFE0D31 */  bl       UNDEF_800df270;
/* 800FE544 907F020C */  stw      r3, 524(r31);
/* 800FE548 38BE0040 */  addi     r5, r30, 64;
/* 800FE54C 388D9568 */  la       r4, UNDEF_80428ee8@sda21;
/* 800FE550 806DA998 */  lwz      r3, UNDEF_8042a318@sda21;
/* 800FE554 38630004 */  addi     r3, r3, 4;
/* 800FE558 4BFE0D19 */  bl       UNDEF_800df270;
/* 800FE55C 907F0210 */  stw      r3, 528(r31);
/* 800FE560 38BE0040 */  addi     r5, r30, 64;
/* 800FE564 388D9570 */  la       r4, UNDEF_80428ef0@sda21;
/* 800FE568 806DA998 */  lwz      r3, UNDEF_8042a318@sda21;
/* 800FE56C 38630004 */  addi     r3, r3, 4;
/* 800FE570 4BFE0D01 */  bl       UNDEF_800df270;
/* 800FE574 907F0214 */  stw      r3, 532(r31);
/* 800FE578 387E0030 */  addi     r3, r30, 48;
/* 800FE57C 801F024C */  lwz      r0, 588(r31);
/* 800FE580 38BE0040 */  addi     r5, r30, 64;
/* 800FE584 80CDA998 */  lwz      r6, UNDEF_8042a318@sda21;
/* 800FE588 5400103A */  slwi     r0, r0, 2;
                         lis      r3, c_yoshiColorNames@ha;
                         addi     r3, r3, c_yoshiColorNames@l;
/* 800FE58C 7C83002E */  lwzx     r4, r3, r0;
/* 800FE590 38660004 */  addi     r3, r6, 4;
/* 800FE594 4BFE0CDD */  bl       UNDEF_800df270;
/* 800FE598 907F0250 */  stw      r3, 592(r31);
/* 800FE59C 387F020C */  addi     r3, r31, 524;
/* 800FE5A0 389E0050 */  addi     r4, r30, 80;
/* 800FE5A4 4813B9CD */  bl       UNDEF_80239f70;
/* 800FE5A8 90610024 */  stw      r3, 36(r1);
/* 800FE5AC 3BC00000 */  li       r30, 0;
/* 800FE5B0 48000090 */  b        UNDEF_800fe640;
UNDEF_800fe5b4:;
/* 800FE5B4 7FC4F378 */  mr       r4, r30;
/* 800FE5B8 38610024 */  addi     r3, r1, 36;
/* 800FE5BC 4813D3E5 */  bl       UNDEF_8023b9a0;
/* 800FE5C0 90610020 */  stw      r3, 32(r1);
/* 800FE5C4 80030030 */  lwz      r0, 48(r3);
/* 800FE5C8 2C000000 */  cmpwi    r0, 0;
/* 800FE5CC 4182000C */  beq-     UNDEF_800fe5d8;
/* 800FE5D0 7C830214 */  add      r4, r3, r0;
/* 800FE5D4 48000008 */  b        UNDEF_800fe5dc;
UNDEF_800fe5d8:;
/* 800FE5D8 38800000 */  li       r4, 0;
UNDEF_800fe5dc:;
/* 800FE5DC 38C30144 */  addi     r6, r3, 324;
/* 800FE5E0 38030040 */  addi     r0, r3, 64;
/* 800FE5E4 9081001C */  stw      r4, 28(r1);
/* 800FE5E8 3861001C */  addi     r3, r1, 28;
/* 800FE5EC 38810018 */  addi     r4, r1, 24;
/* 800FE5F0 38A10014 */  addi     r5, r1, 20;
/* 800FE5F4 90C10014 */  stw      r6, 20(r1);
/* 800FE5F8 90010018 */  stw      r0, 24(r1);
/* 800FE5FC 48140195 */  bl       UNDEF_8023e790;
/* 800FE600 80E10020 */  lwz      r7, 32(r1);
/* 800FE604 3861001C */  addi     r3, r1, 28;
/* 800FE608 38810010 */  addi     r4, r1, 16;
/* 800FE60C 38A1000C */  addi     r5, r1, 12;
/* 800FE610 38C70144 */  addi     r6, r7, 324;
/* 800FE614 38070040 */  addi     r0, r7, 64;
/* 800FE618 90C10008 */  stw      r6, 8(r1);
/* 800FE61C 38C10008 */  addi     r6, r1, 8;
/* 800FE620 9001000C */  stw      r0, 12(r1);
/* 800FE624 801F0250 */  lwz      r0, 592(r31);
/* 800FE628 90010010 */  stw      r0, 16(r1);
/* 800FE62C 4813FEA5 */  bl       UNDEF_8023e4d0;
/* 800FE630 38610020 */  addi     r3, r1, 32;
/* 800FE634 38800000 */  li       r4, 0;
/* 800FE638 4813E5E9 */  bl       UNDEF_8023cc20;
/* 800FE63C 3BDE0001 */  addi     r30, r30, 1;
UNDEF_800fe640:;
/* 800FE640 38610024 */  addi     r3, r1, 36;
/* 800FE644 4813D3BD */  bl       UNDEF_8023ba00;
/* 800FE648 7C1E1840 */  cmplw    r30, r3;
/* 800FE64C 4180FF68 */  blt+     UNDEF_800fe5b4;
/* 800FE650 80010034 */  lwz      r0, 52(r1);
/* 800FE654 83E1002C */  lwz      r31, 44(r1);
/* 800FE658 83C10028 */  lwz      r30, 40(r1);
/* 800FE65C 7C0803A6 */  mtlr     r0;
/* 800FE660 38210030 */  addi     r1, r1, 48;
/* 800FE664 4E800020 */  blr;
  // clang-format on
)

int dYoshiMdl_c::s_yoshiColors[dYoshiMdl_c::COLOR_COUNT] = {
    dYoshiMdl_c::COLOR_GREEN,
    dYoshiMdl_c::COLOR_YELLOW,
    dYoshiMdl_c::COLOR_BLUE,
    dYoshiMdl_c::COLOR_RED,
    dYoshiMdl_c::COLOR_AZURE,
    dYoshiMdl_c::COLOR_ORANGE,
    dYoshiMdl_c::COLOR_PURPLE,
    dYoshiMdl_c::COLOR_CRIMSON,
};

void dYoshiMdl_c::setDefaultColors()
{
    if (!dScStage_c::isNowReplay()) {
        if (fFeat::yoshi_color_mode == fFeat::YOSHI_COLOR_MODE_e::RANDOM) {
            // Shuffle the s_yoshiColors array
            for (int i = 0; i < dYoshiMdl_c::COLOR_COUNT; i++) {
                int j = dGameCom::rndInt(i);
                int temp = s_yoshiColors[i];
                s_yoshiColors[i] = s_yoshiColors[j];
                s_yoshiColors[j] = temp;
            }
        }
    }
}