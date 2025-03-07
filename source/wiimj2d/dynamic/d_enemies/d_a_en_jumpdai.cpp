// d_a_en_jumpdai.cpp
// NSMBW d_enemies.text: 0x80A38A00 - 0x80A3AEF0

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_info.h>

[[address(0x80A39660)]]
void UNDEF_80A39660() ASM_METHOD(
  // clang-format off
/* 80A39660 9421FF30 */  stwu     r1, -208(r1);
/* 80A39664 7C0802A6 */  mflr     r0;
/* 80A39668 3CC08043 */  lis      r6, m_instance__10dScStage_c@ha;
/* 80A3966C 900100D4 */  stw      r0, 212(r1);
/* 80A39670 DBE100C0 */  stfd     f31, 192(r1);
/* 80A39674 F3E100C8 */  .long    0xF3E100C8; // psq_st   f31, 200(r1), 0, 0;
/* 80A39678 DBC100B0 */  stfd     f30, 176(r1);
/* 80A3967C F3C100B8 */  .long    0xF3C100B8; // psq_st   f30, 184(r1), 0, 0;
/* 80A39680 93E100AC */  stw      r31, 172(r1);
/* 80A39684 7C9F2378 */  mr       r31, r4;
/* 80A39688 93C100A8 */  stw      r30, 168(r1);
/* 80A3968C 7C7E1B78 */  mr       r30, r3;
/* 80A39690 93A100A4 */  stw      r29, 164(r1);
/* 80A39694 938100A0 */  stw      r28, 160(r1);
/* 80A39698 80C6A4A8 */  lwz      r6, m_instance__10dScStage_c@l(r6);
/* 80A3969C 88C6120D */  lbz      r6, 0x120D(r6);
/* 80A396A0 3806FFE0 */  subi     r0, r6, 32;
/* 80A396A4 28000002 */  cmplwi   r0, 2;
/* 80A396A8 4181000C */  bgt-     UNDEF_80a396b4;
/* 80A396AC 38600000 */  li       r3, 0;
/* 80A396B0 480002CC */  b        UNDEF_80a3997c;
UNDEF_80a396b4:;
/* 80A396B4 C06300B0 */  lfs      f3, 176(r3);
/* 80A396B8 C0450004 */  lfs      f2, 4(r5);
/* 80A396BC C02300AC */  lfs      f1, 172(r3);
/* 80A396C0 EC831028 */  fsubs    f4, f3, f2;
/* 80A396C4 C0050000 */  lfs      f0, 0(r5);
/* 80A396C8 C0A300B4 */  lfs      f5, 180(r3);
/* 80A396CC EC63102A */  fadds    f3, f3, f2;
/* 80A396D0 EC410028 */  fsubs    f2, f1, f0;
/* 80A396D4 D0A10094 */  stfs     f5, 148(r1);
/* 80A396D8 EC01002A */  fadds    f0, f1, f0;
/* 80A396DC D041008C */  stfs     f2, 140(r1);
/* 80A396E0 D0810090 */  stfs     f4, 144(r1);
/* 80A396E4 D0010080 */  stfs     f0, 128(r1);
/* 80A396E8 D0610084 */  stfs     f3, 132(r1);
/* 80A396EC D0A10088 */  stfs     f5, 136(r1);
/* 80A396F0 80030128 */  lwz      r0, 296(r3);
/* 80A396F4          */  cmplwi   r0, PLAYER_COUNT - 1;
/* 80A396F8 4181002C */  bgt-     UNDEF_80a39724;
/* 80A396FC 3CA08043 */  lis      r5, m_instance__7dInfo_c@ha;
                         cmpwi    r0, 4;
/* 80A39700 1C000016 */  mulli    r0, r0, 22;
/* 80A39704 80A5A25C */  lwz      r5, m_instance__7dInfo_c@l(r5);
/* 80A39708 7C050214 */  add      r0, r5, r0;
/* 80A3970C 7C802214 */  add      r4, r0, r4;

                         blt-     L_UNDEF_80A39660_SkipAFEAdjust;
                         addi     r4, r4, ADJUST_dInfo_c_mEx0xAFE;
L_UNDEF_80A39660_SkipAFEAdjust:;

/* 80A39710 88040AFE */  lbz      r0, 0xAFE(r4);
/* 80A39714 2C000000 */  cmpwi    r0, 0;
/* 80A39718 4182000C */  beq-     UNDEF_80a39724;
/* 80A3971C 3800FFFF */  li       r0, -1;
/* 80A39720 90030128 */  stw      r0, 296(r3);
UNDEF_80a39724:;
/* 80A39724 80630128 */  lwz      r3, 296(r3);
/* 80A39728          */  cmplwi   r3, PLAYER_COUNT - 1;
/* 80A3972C 4181012C */  bgt-     UNDEF_80a39858;
/* 80A39730 4B6261D1 */  bl       getPlayer__9daPyMng_cFi;
/* 80A39734 2C030000 */  cmpwi    r3, 0;
/* 80A39738 7C7C1B78 */  mr       r28, r3;
/* 80A3973C 4182023C */  beq-     UNDEF_80a39978;
/* 80A39740 4B70E561 */  bl       UNDEF_80147ca0; // isDrawingCarryFukidashi__7dAcPy_cFv
/* 80A39744 7C7D1B78 */  mr       r29, r3;
/* 80A39748 7F83E378 */  mr       r3, r28;
/* 80A3974C 38810070 */  addi     r4, r1, 112;
/* 80A39750 4B708961 */  bl       UNDEF_801420b0;
/* 80A39754 C0610074 */  lfs      f3, 116(r1);
/* 80A39758 C05C00B0 */  lfs      f2, 176(r28);
/* 80A3975C C0210070 */  lfs      f1, 112(r1);
/* 80A39760 C01C00AC */  lfs      f0, 172(r28);
/* 80A39764 EFE3102A */  fadds    f31, f3, f2;
/* 80A39768 C3DC00B4 */  lfs      f30, 180(r28);
/* 80A3976C EC21002A */  fadds    f1, f1, f0;
/* 80A39770 4B6C8441 */  bl       UNDEF_80101bb0; // getLoopPosX__10dScStage_cFf
/* 80A39774 FC800818 */  frsp     f4, f1;
/* 80A39778 C0010078 */  lfs      f0, 120(r1);
/* 80A3977C 3C8080AD */  lis      r4, UNDEF_80ad19e4@ha;
/* 80A39780 C0A1007C */  lfs      f5, 124(r1);
/* 80A39784 C04419E4 */  lfs      f2, UNDEF_80ad19e4@l(r4);
/* 80A39788 3C608043 */  lis      r3, m_instance__19dfukidashiManager_c@ha;
/* 80A3978C EC640028 */  fsubs    f3, f4, f0;
/* 80A39790 D3C1005C */  stfs     f30, 92(r1);
/* 80A39794 EC04002A */  fadds    f0, f4, f0;
/* 80A39798 8083A600 */  lwz      r4, m_instance__19dfukidashiManager_c@l(r3);
/* 80A3979C EC9F2828 */  fsubs    f4, f31, f5;
/* 80A397A0 D3C10050 */  stfs     f30, 80(r1);
/* 80A397A4 EC631028 */  fsubs    f3, f3, f2;
/* 80A397A8 D0810058 */  stfs     f4, 88(r1);
/* 80A397AC EC9F282A */  fadds    f4, f31, f5;
/* 80A397B0 EC02002A */  fadds    f0, f2, f0;
/* 80A397B4 D0610054 */  stfs     f3, 84(r1);
/* 80A397B8 D0010048 */  stfs     f0, 72(r1);
/* 80A397BC D081004C */  stfs     f4, 76(r1);
/* 80A397C0 807E0128 */  lwz      r3, 296(r30);
/* 80A397C4 D0210060 */  stfs     f1, 96(r1);
/* 80A397C8 1C03023C */  mulli    r0, r3, 572;
/* 80A397CC D3E10064 */  stfs     f31, 100(r1);
/* 80A397D0 7C840214 */  add      r4, r4, r0;
/* 80A397D4 D3C10068 */  stfs     f30, 104(r1);
/* 80A397D8 88040381 */  lbz      r0, 897(r4);
/* 80A397DC 2C000000 */  cmpwi    r0, 0;
/* 80A397E0 4082000C */  bne-     UNDEF_80a397ec;
/* 80A397E4 7FE4FB78 */  mr       r4, r31;
/* 80A397E8 4B679E19 */  bl       UNDEF_800b3600;
UNDEF_80a397ec:;
/* 80A397EC 3C8080AD */  lis      r4, UNDEF_80ad1974@ha;
/* 80A397F0 3861008C */  addi     r3, r1, 140;
/* 80A397F4 C0241974 */  lfs      f1, UNDEF_80ad1974@l(r4);
/* 80A397F8 38810080 */  addi     r4, r1, 128;
/* 80A397FC 38A10054 */  addi     r5, r1, 84;
/* 80A39800 38C10048 */  addi     r6, r1, 72;
/* 80A39804 4B6798FD */  bl       UNDEF_800b3100;
/* 80A39808 2C1D0000 */  cmpwi    r29, 0;
/* 80A3980C 4182000C */  beq-     UNDEF_80a39818;
/* 80A39810 2C030000 */  cmpwi    r3, 0;
/* 80A39814 40820038 */  bne-     UNDEF_80a3984c;
UNDEF_80a39818:;
/* 80A39818 A07E0634 */  lhz      r3, 1588(r30);
/* 80A3981C 2803003C */  cmplwi   r3, 60;
/* 80A39820 40810020 */  ble-     UNDEF_80a39840;
/* 80A39824 807E0128 */  lwz      r3, 296(r30);
/* 80A39828 7FE4FB78 */  mr       r4, r31;
/* 80A3982C 38A00000 */  li       r5, 0;
/* 80A39830 4B679F21 */  bl       UNDEF_800b3750;
/* 80A39834 3800FFFF */  li       r0, -1;
/* 80A39838 901E0128 */  stw      r0, 296(r30);
/* 80A3983C 4800013C */  b        UNDEF_80a39978;
UNDEF_80a39840:;
/* 80A39840 38030001 */  addi     r0, r3, 1;
/* 80A39844 B01E0634 */  sth      r0, 1588(r30);
/* 80A39848 48000130 */  b        UNDEF_80a39978;
UNDEF_80a3984c:;
/* 80A3984C 38000000 */  li       r0, 0;
/* 80A39850 B01E0634 */  sth      r0, 1588(r30);
/* 80A39854 48000124 */  b        UNDEF_80a39978;
UNDEF_80a39858:;
/* 80A39858 7FC3F378 */  mr       r3, r30;
/* 80A3985C 38810008 */  addi     r4, r1, 8;
/* 80A39860 4B62AEE1 */  bl       UNDEF_80064740; // searchNearPlayer__8dActor_cFR7mVec2_c
/* 80A39864 2C030000 */  cmpwi    r3, 0;
/* 80A39868 7C7C1B78 */  mr       r28, r3;
/* 80A3986C 4182010C */  beq-     UNDEF_80a39978;
/* 80A39870 8803038C */  lbz      r0, 908(r3);
/* 80A39874 28000001 */  cmplwi   r0, 1;
/* 80A39878 40820100 */  bne-     UNDEF_80a39978;
/* 80A3987C 81830060 */  lwz      r12, 96(r3);
/* 80A39880 818C006C */  lwz      r12, 108(r12);
/* 80A39884 7D8903A6 */  mtctr    r12;
/* 80A39888 4E800421 */  bctrl;
/* 80A3988C 88030000 */  lbz      r0, 0(r3);
/* 80A39890 3C608043 */  lis      r3, m_instance__7dInfo_c@ha;
/* 80A39894 8063A25C */  lwz      r3, m_instance__7dInfo_c@l(r3);
/* 80A39898 7C000774 */  extsb    r0, r0;
                         cmpwi    r0, 4;
/* 80A3989C 1C000016 */  mulli    r0, r0, 22;
/* 80A398A0 7C030214 */  add      r0, r3, r0;
/* 80A398A4 7C60FA14 */  add      r3, r0, r31;

                         blt-     L_UNDEF_80A39858_SkipAFEAdjust2;
                         addi     r3, r3, ADJUST_dInfo_c_mEx0xAFE;
L_UNDEF_80A39858_SkipAFEAdjust2:;

/* 80A398A8 88030AFE */  lbz      r0, 0xAFE(r3);
/* 80A398AC 2C000000 */  cmpwi    r0, 0;
/* 80A398B0 408200C8 */  bne-     UNDEF_80a39978;
/* 80A398B4 7F83E378 */  mr       r3, r28;
/* 80A398B8 4B70E3E9 */  bl       UNDEF_80147ca0; // isDrawingCarryFukidashi__7dAcPy_cFv
/* 80A398BC 7C7F1B78 */  mr       r31, r3;
/* 80A398C0 7F83E378 */  mr       r3, r28;
/* 80A398C4 38810038 */  addi     r4, r1, 56;
/* 80A398C8 4B7087E9 */  bl       UNDEF_801420b0;
/* 80A398CC C061003C */  lfs      f3, 60(r1);
/* 80A398D0 C05C00B0 */  lfs      f2, 176(r28);
/* 80A398D4 C0210038 */  lfs      f1, 56(r1);
/* 80A398D8 C01C00AC */  lfs      f0, 172(r28);
/* 80A398DC EFC3102A */  fadds    f30, f3, f2;
/* 80A398E0 C3FC00B4 */  lfs      f31, 180(r28);
/* 80A398E4 EC21002A */  fadds    f1, f1, f0;
/* 80A398E8 4B6C82C9 */  bl       UNDEF_80101bb0; // getLoopPosX__10dScStage_cFf
/* 80A398EC FC400818 */  frsp     f2, f1;
/* 80A398F0 C0610044 */  lfs      f3, 68(r1);
/* 80A398F4 C0010040 */  lfs      f0, 64(r1);
/* 80A398F8 3C6080AD */  lis      r3, UNDEF_80ad1974@ha;
/* 80A398FC ECBE1828 */  fsubs    f5, f30, f3;
/* 80A39900 D0210028 */  stfs     f1, 40(r1);
/* 80A39904 EC820028 */  fsubs    f4, f2, f0;
/* 80A39908 C0231974 */  lfs      f1, UNDEF_80ad1974@l(r3);
/* 80A3990C EC7E182A */  fadds    f3, f30, f3;
/* 80A39910 D3C1002C */  stfs     f30, 44(r1);
/* 80A39914 EC02002A */  fadds    f0, f2, f0;
/* 80A39918 3861008C */  addi     r3, r1, 140;
/* 80A3991C D3E10030 */  stfs     f31, 48(r1);
/* 80A39920 38810080 */  addi     r4, r1, 128;
/* 80A39924 38A1001C */  addi     r5, r1, 28;
/* 80A39928 38C10010 */  addi     r6, r1, 16;
/* 80A3992C D081001C */  stfs     f4, 28(r1);
/* 80A39930 D0A10020 */  stfs     f5, 32(r1);
/* 80A39934 D3E10024 */  stfs     f31, 36(r1);
/* 80A39938 D0010010 */  stfs     f0, 16(r1);
/* 80A3993C D0610014 */  stfs     f3, 20(r1);
/* 80A39940 D3E10018 */  stfs     f31, 24(r1);
/* 80A39944 4B6797BD */  bl       UNDEF_800b3100;
/* 80A39948 2C1F0000 */  cmpwi    r31, 0;
/* 80A3994C 4182002C */  beq-     UNDEF_80a39978;
/* 80A39950 2C030000 */  cmpwi    r3, 0;
/* 80A39954 41820024 */  beq-     UNDEF_80a39978;
/* 80A39958 819C0060 */  lwz      r12, 96(r28);
/* 80A3995C 7F83E378 */  mr       r3, r28;
/* 80A39960 818C006C */  lwz      r12, 108(r12);
/* 80A39964 7D8903A6 */  mtctr    r12;
/* 80A39968 4E800421 */  bctrl;
/* 80A3996C 88030000 */  lbz      r0, 0(r3);
/* 80A39970 7C000774 */  extsb    r0, r0;
/* 80A39974 901E0128 */  stw      r0, 296(r30);
UNDEF_80a39978:;
/* 80A39978 38600000 */  li       r3, 0;
UNDEF_80a3997c:;
/* 80A3997C 800100D4 */  lwz      r0, 212(r1);
/* 80A39980 E3E100C8 */  .long    0xE3E100C8; // psq_l    f31, 200(r1), 0, 0;
/* 80A39984 CBE100C0 */  lfd      f31, 192(r1);
/* 80A39988 E3C100B8 */  .long    0xE3C100B8; // psq_l    f30, 184(r1), 0, 0;
/* 80A3998C CBC100B0 */  lfd      f30, 176(r1);
/* 80A39990 83E100AC */  lwz      r31, 172(r1);
/* 80A39994 83C100A8 */  lwz      r30, 168(r1);
/* 80A39998 83A100A4 */  lwz      r29, 164(r1);
/* 80A3999C 838100A0 */  lwz      r28, 160(r1);
/* 80A399A0 7C0803A6 */  mtlr     r0;
/* 80A399A4 382100D0 */  addi     r1, r1, 208;
/* 80A399A8 4E800020 */  blr;
  // clang-format on
);