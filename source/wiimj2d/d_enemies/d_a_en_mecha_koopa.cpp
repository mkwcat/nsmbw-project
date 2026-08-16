// d_a_en_mecha_koopa.cpp
// NSMBW d_enemies.text: 0x80A64110 - 0x80A67470

#include "d_system/d_a_player_manager.h"

[[nsmbw(0x80A65530)]]
void UNDEF_80A65530() ASM_METHOD(
/* 80A65530 9421FFE0 */  stwu     r1, -32(r1);
/* 80A65534 7C0802A6 */  mflr     r0;
/* 80A65538 90010024 */  stw      r0, 36(r1);
/* 80A6553C 39610020 */  addi     r11, r1, 32;
/* 80A65540 4B877B25 */  bl       UNDEF_802dd064;
/* 80A65544 83650004 */  lwz      r27, 4(r5);
/* 80A65548 3FC080B2 */  lis      r30, UNDEF_80b18898@ha;
/* 80A6554C 7C7C1B78 */  mr       r28, r3;
/* 80A65550 819B0060 */  lwz      r12, 96(r27);
/* 80A65554 7F63DB78 */  mr       r3, r27;
/* 80A65558 3BDE8898 */  addi     r30, r30, UNDEF_80b18898@l;
/* 80A6555C 818C006C */  lwz      r12, 108(r12);
/* 80A65560 7D8903A6 */  mtctr    r12;
/* 80A65564 4E800421 */  bctrl;
/* 80A65568 8BA30000 */  lbz      r29, 0(r3);
/* 80A6556C 7FBD0774 */  extsb    r29, r29;
/* 80A65570          */  cmplwi   r29, PLAYER_COUNT;
/* 80A65574 4180000C */  blt-     UNDEF_80a65580;
/* 80A65578 38600001 */  li       r3, 1;
/* 80A6557C 4800015C */  b        UNDEF_80a656d8;
UNDEF_80a65580:;
                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r29;
                         bl       getCollTimer__5dEn_cCFi;

/* 80A6558C          */  cmpwi    r3, 0;
/* 80A65590 4182000C */  beq-     UNDEF_80a6559c;
/* 80A65594 38600001 */  li       r3, 1;
/* 80A65598 48000140 */  b        UNDEF_80a656d8;
UNDEF_80a6559c:;
/* 80A6559C C07B00AC */  lfs      f3, 172(r27);
/* 80A655A0 C05B00D0 */  lfs      f2, 208(r27);
/* 80A655A4 C03C00AC */  lfs      f1, 172(r28);
/* 80A655A8 C01C00D0 */  lfs      f0, 208(r28);
/* 80A655AC EC43102A */  fadds    f2, f3, f2;
/* 80A655B0 EC21002A */  fadds    f1, f1, f0;
/* 80A655B4 4B5FF47D */  bl       UNDEF_80064a30; // getTrgToSrcDir_Main__8dActor_cFff
/* 80A655B8 987C0348 */  stb      r3, 840(r28);
/* 80A655BC 387C0394 */  addi     r3, r28, 916;
/* 80A655C0 819C0394 */  lwz      r12, 916(r28);
/* 80A655C4 818C0028 */  lwz      r12, 40(r12);
/* 80A655C8 7D8903A6 */  mtctr    r12;
/* 80A655CC 4E800421 */  bctrl;
/* 80A655D0 81830000 */  lwz      r12, 0(r3);
/* 80A655D4 389E0028 */  addi     r4, r30, 40;
/* 80A655D8 818C0014 */  lwz      r12, 20(r12);
/* 80A655DC 7D8903A6 */  mtctr    r12;
/* 80A655E0 4E800421 */  bctrl;
/* 80A655E4 7C0300D0 */  neg      r0, r3;
/* 80A655E8 7C001B78 */  or       r0, r0, r3;
/* 80A655EC 54000FFF */  srwi.    r0, r0, 31;
/* 80A655F0 40820074 */  bne-     UNDEF_80a65664;
/* 80A655F4 819C0394 */  lwz      r12, 916(r28);
/* 80A655F8 387C0394 */  addi     r3, r28, 916;
/* 80A655FC 818C0028 */  lwz      r12, 40(r12);
/* 80A65600 7D8903A6 */  mtctr    r12;
/* 80A65604 4E800421 */  bctrl;
/* 80A65608 81830000 */  lwz      r12, 0(r3);
/* 80A6560C 389E0068 */  addi     r4, r30, 104;
/* 80A65610 818C0014 */  lwz      r12, 20(r12);
/* 80A65614 7D8903A6 */  mtctr    r12;
/* 80A65618 4E800421 */  bctrl;
/* 80A6561C 7C0300D0 */  neg      r0, r3;
/* 80A65620 7C001B78 */  or       r0, r0, r3;
/* 80A65624 54000FFF */  srwi.    r0, r0, 31;
/* 80A65628 4082003C */  bne-     UNDEF_80a65664;
/* 80A6562C 819C0394 */  lwz      r12, 916(r28);
/* 80A65630 387C0394 */  addi     r3, r28, 916;
/* 80A65634 818C0028 */  lwz      r12, 40(r12);
/* 80A65638 7D8903A6 */  mtctr    r12;
/* 80A6563C 4E800421 */  bctrl;
/* 80A65640 81830000 */  lwz      r12, 0(r3);
/* 80A65644 389E01A8 */  addi     r4, r30, 424;
/* 80A65648 818C0014 */  lwz      r12, 20(r12);
/* 80A6564C 7D8903A6 */  mtctr    r12;
/* 80A65650 4E800421 */  bctrl;
/* 80A65654 7C0300D0 */  neg      r0, r3;
/* 80A65658 7C001B78 */  or       r0, r0, r3;
/* 80A6565C 54000FFF */  srwi.    r0, r0, 31;
/* 80A65660 41820040 */  beq-     UNDEF_80a656a0;
UNDEF_80a65664:;
/* 80A65664 7F63DB78 */  mr       r3, r27;
/* 80A65668 4B63A029 */  bl       UNDEF_8009f690;
/* 80A6566C 7C641B78 */  mr       r4, r3;
/* 80A65670 387C0510 */  addi     r3, r28, 1296;
/* 80A65674 4B63A09D */  bl       UNDEF_8009f710;
/* 80A65678 3CC08043 */  lis      r6, UNDEF_8042cf68@ha;
/* 80A6567C 3CE08043 */  lis      r7, UNDEF_8042cf6c@ha;
/* 80A65680 C026CF68 */  lfs      f1, UNDEF_8042cf68@l(r6);
/* 80A65684 3C808043 */  lis      r4, UNDEF_8042a330@ha; // m_instance__11dScoreMng_c
/* 80A65688 7C651B78 */  mr       r5, r3;
/* 80A6568C 8064A330 */  lwz      r3, UNDEF_8042a330@l(r4); // m_instance__11dScoreMng_c
/* 80A65690 C047CF6C */  lfs      f2, UNDEF_8042cf6c@l(r7);
/* 80A65694 7F84E378 */  mr       r4, r28;
/* 80A65698 7FA6EB78 */  mr       r6, r29;
/* 80A6569C 4B67CAF5 */  bl       UNDEF_800e2190;
UNDEF_80a656a0:;
                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r29;
                         li       r5, 16;
                         bl       setCollTimer__5dEn_cFiUc;

/* 80A656A8 7F83E378 */  mr       r3, r28;
/* 80A656AC 4BFFEF15 */  bl       UNDEF_80a645c0;
/* 80A656B0 7F83E378 */  mr       r3, r28;
/* 80A656B4 4BFFF17D */  bl       UNDEF_80a64830;
/* 80A656B8 819C0060 */  lwz      r12, 96(r28);
/* 80A656BC 7F83E378 */  mr       r3, r28;
/* 80A656C0 389E0168 */  addi     r4, r30, 360;
/* 80A656C4 818C00D4 */  lwz      r12, 212(r12);
/* 80A656C8 7D8903A6 */  mtctr    r12;
/* 80A656CC 4E800421 */  bctrl;
/* 80A656D0 9BBC038D */  stb      r29, 909(r28);
/* 80A656D4 38600001 */  li       r3, 1;
UNDEF_80a656d8:;
/* 80A656D8 39610020 */  addi     r11, r1, 32;
/* 80A656DC 4B8779D5 */  bl       UNDEF_802dd0b0;
/* 80A656E0 80010024 */  lwz      r0, 36(r1);
/* 80A656E4 7C0803A6 */  mtlr     r0;
/* 80A656E8 38210020 */  addi     r1, r1, 32;
/* 80A656EC 4E800020 */  blr;
);
