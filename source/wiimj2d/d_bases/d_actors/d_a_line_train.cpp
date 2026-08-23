// d_a_line_train.cpp
// NSMBW d_bases.text: 0x80859440 - 0x8085BCB0

#include "d_a_line_train.h"

#include "component/c_bitmask.h"

[[gnu::used]]
constinit u32 daLineTrain_c_size = sizeof(daLineTrain_c);

[[nsmbw(0x80859440)]]
daLineTrain_c* daLineTrain_c_classInit() ASM_METHOD(
  // clang-format off
  /* 80859440 9421FFE0 */  stwu     r1, -32(r1);
  /* 80859444 7C0802A6 */  mflr     r0;
  /* 80859448 90010024 */  stw      r0, 36(r1);
  /* 8085944C 39610020 */  addi     r11, r1, 32;
  /* 80859450 4BA83C15 */  bl       UNDEF_802dd064;
  /* 80859454          */  lis      r3, daLineTrain_c_size@ha;
                           lwz      r3, daLineTrain_c_size@l(r3);
  /* 80859458 4B9095A9 */  bl       UNDEF_80162a00;
  /* 8085945C 2C030000 */  cmpwi    r3, 0;
  /* 80859460 7C7C1B78 */  mr       r28, r3;
  /* 80859464 41820108 */  beq-     UNDEF_8085956c;
  /* 80859468 4B80DB59 */  bl       UNDEF_80066fc0;
  /* 8085946C 3C808097 */  lis      r4, UNDEF_8096bbc0@ha;
  /* 80859470 387C03D4 */  addi     r3, r28, 980;
  /* 80859474 3884BBC0 */  addi     r4, r4, UNDEF_8096bbc0@l;
  /* 80859478 909C0060 */  stw      r4, 96(r28);
  /* 8085947C 4B80FBA5 */  bl       UNDEF_80069020;
  /* 80859480 3FA08097 */  lis      r29, UNDEF_8096bcdc@ha;
  /* 80859484 3BC00000 */  li       r30, 0;
  /* 80859488 3BBDBCDC */  addi     r29, r29, UNDEF_8096bcdc@l;
  /* 8085948C 93BC03F0 */  stw      r29, 1008(r28);
  /* 80859490 387C03F8 */  addi     r3, r28, 1016;
  /* 80859494 93DC03F4 */  stw      r30, 1012(r28);
  /* 80859498 4B910979 */  bl       UNDEF_80169e10;
  /* 8085949C 3B7C0438 */  addi     r27, r28, 1080;
  /* 808594A0 7F63DB78 */  mr       r3, r27;
  /* 808594A4 4B90F9AD */  bl       UNDEF_80168e50;
  /* 808594A8 3FE08095 */  lis      r31, UNDEF_80951518@ha;
  /* 808594AC 387C0470 */  addi     r3, r28, 1136;
  /* 808594B0 3BFF1518 */  addi     r31, r31, UNDEF_80951518@l;
  /* 808594B4 93FB0000 */  stw      r31, 0(r27);
  /* 808594B8 4B867909 */  bl       UNDEF_800c0dc0;
  /* 808594BC 3C608097 */  lis      r3, UNDEF_8096bcc8@ha;
  /* 808594C0 3B7C0570 */  addi     r27, r28, 1392;
  /* 808594C4 3863BCC8 */  addi     r3, r3, UNDEF_8096bcc8@l;
  /* 808594C8 907C03F0 */  stw      r3, 1008(r28);
  /* 808594CC 3C608033 */  lis      r3, UNDEF_80329920@ha;
  /* 808594D0 38639920 */  addi     r3, r3, UNDEF_80329920@l;
  /* 808594D4 907C0570 */  stw      r3, 1392(r28);
  /* 808594D8 387B000C */  addi     r3, r27, 12;
  /* 808594DC 93DC0574 */  stw      r30, 1396(r28);
  /* 808594E0 93DC0578 */  stw      r30, 1400(r28);
  /* 808594E4 4B91123D */  bl       UNDEF_8016a720;
  /* 808594E8 3C608033 */  lis      r3, UNDEF_80329860@ha;
  /* 808594EC 3C808086 */  lis      r4, UNDEF_80859590@ha;
  /* 808594F0 38639860 */  addi     r3, r3, UNDEF_80329860@l;
  /* 808594F4 907B0000 */  stw      r3, 0(r27);
  /* 808594F8 3CA08086 */  lis      r5, UNDEF_80859610@ha;
  /* 808594FC 38849590 */  addi     r4, r4, UNDEF_80859590@l;
  /* 80859500 93DB0028 */  stw      r30, 40(r27);
  /* 80859504 387C05A4 */  addi     r3, r28, 1444;
  /* 80859508 38A59610 */  addi     r5, r5, UNDEF_80859610@l;
  /* 8085950C 38C00180 */  li       r6, 384;
  /* 80859510 38E00006 */  li       r7, 6;
  /* 80859514 4BA8377D */  bl       UNDEF_802dcc90;
  /* 80859518 93BC0EA4 */  stw      r29, 3748(r28);
  /* 8085951C 387C0EAC */  addi     r3, r28, 3756;
  /* 80859520 93DC0EA8 */  stw      r30, 3752(r28);
  /* 80859524 4B9108ED */  bl       UNDEF_80169e10;
  /* 80859528 3BBC0EEC */  addi     r29, r28, 3820;
  /* 8085952C 7FA3EB78 */  mr       r3, r29;
  /* 80859530 4B90F921 */  bl       UNDEF_80168e50;
  /* 80859534 93FD0000 */  stw      r31, 0(r29);
  /* 80859538 387C0F24 */  addi     r3, r28, 3876;
  /* 8085953C 4B867885 */  bl       UNDEF_800c0dc0;
  /* 80859540 3C608097 */  lis      r3, UNDEF_8096bca0@ha;
  /* 80859544 3C80800E */  lis      r4, UNDEF_800db540@ha;
  /* 80859548 3863BCA0 */  addi     r3, r3, UNDEF_8096bca0@l;
  /* 8085954C 3CA08080 */  lis      r5, UNDEF_80801f70@ha;
  /* 80859550 907C0EA4 */  stw      r3, 3748(r28);
  /* 80859554 387C1044 */  addi     r3, r28, 4164;
  /* 80859558 3884B540 */  addi     r4, r4, UNDEF_800db540@l;
  /* 8085955C 38A51F70 */  addi     r5, r5, UNDEF_80801f70@l;
  /* 80859560 38C0005C */  li       r6, 92;
  /* 80859564 38E00009 */  li       r7, 9;
  /* 80859568 4BA83729 */  bl       UNDEF_802dcc90;
  cBitmask_c_ASM_CLEAR(TEMP_RIDE_MASK_SIZE, r28, OFFSET_dLineTrain_c_mPlayerRideMask, r30);
  cBitmask_c_ASM_CLEAR(TEMP_RIDE_MASK_SIZE, r28, OFFSET_dLineTrain_c_mPrevPlayerRideMask, r30);

UNDEF_8085956c:;
  /* 8085956C 39610020 */  addi     r11, r1, 32;
  /* 80859570 7F83E378 */  mr       r3, r28;
  /* 80859574 4BA83B3D */  bl       UNDEF_802dd0b0;
  /* 80859578 80010024 */  lwz      r0, 36(r1);
  /* 8085957C 7C0803A6 */  mtlr     r0;
  /* 80859580 38210020 */  addi     r1, r1, 32;
  /* 80859584 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x8085A990)]]
int daLineTrain_c::numPlayersRide()
{
    return mPlayerRideMask.popCount();
}
