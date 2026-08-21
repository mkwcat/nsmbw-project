// d_enemy_toride_kokoopa.cpp
// NSMBW .text: 0x800A8710 - 0x800B0A20

[[nsmbw(0x800B0840)]]
void UNDEF_800B0840() ASM_METHOD(
  // clang-format off
/* 800B0840 9421FFE0 */  stwu     r1, -32(r1);
/* 800B0844 7C0802A6 */  mflr     r0;
/* 800B0848 38E00000 */  li       r7, 0;
/* 800B084C 90010024 */  stw      r0, 36(r1);
/* 800B0850 93E1001C */  stw      r31, 28(r1);
/* 800B0854 7C9F2378 */  mr       r31, r4;
/* 800B0858 93C10018 */  stw      r30, 24(r1);
/* 800B085C 93A10014 */  stw      r29, 20(r1);
/* 800B0860 7CBD2B78 */  mr       r29, r5;
/* 800B0864 90E40000 */  stw      r7, 0(r4);
/* 800B0868 80660008 */  lwz      r3, 8(r6);
/* 800B086C 83C30004 */  lwz      r30, 4(r3);
/* 800B0870 807E1074 */  lwz      r3, 4212(r30);
/* 800B0874 801E1078 */  lwz      r0, 4216(r30);
/* 800B0878 7C600379 */  or.      r0, r3, r0;
/* 800B087C 41820020 */  beq-     UNDEF_800b089c;
/* 800B0880 C03E00EC */  lfs      f1, 236(r30);
/* 800B0884 C0029408 */  lfs      f0, UNDEF_8042c768@sda21;
/* 800B0888 FC010040 */  fcmpo    cr0, f1, f0;
/* 800B088C 40810010 */  ble-     UNDEF_800b089c;
/* 800B0890 90E40000 */  stw      r7, 0(r4);
/* 800B0894 38600001 */  li       r3, 1;
/* 800B0898 480000E4 */  b        UNDEF_800b097c;
UNDEF_800b089c:;
/* 800B089C 387E01EC */  addi     r3, r30, 492;
/* 800B08A0 4BFC0411 */  bl       UNDEF_80070cb0;
/* 800B08A4 2C030000 */  cmpwi    r3, 0;
/* 800B08A8 408200D0 */  bne-     UNDEF_800b0978;
/* 800B08AC C03D00EC */  lfs      f1, 236(r29);
/* 800B08B0 C0029408 */  lfs      f0, UNDEF_8042c768@sda21;
/* 800B08B4 FC010040 */  fcmpo    cr0, f1, f0;
/* 800B08B8 408100C0 */  ble-     UNDEF_800b0978;
/* 800B08BC 801E1090 */  lwz      r0, 4240(r30);
/* 800B08C0 2C000003 */  cmpwi    r0, 3;
/* 800B0920 C0229410 */  lfs      f1, UNDEF_8042c770@sda21;
/* 800B08C4          */  bne-     UNDEF_800b08cc;
/* 800B08C8 C022940C */  lfs      f1, UNDEF_8042c76c@sda21;
UNDEF_800b08cc:;
/* 800B08CC C01D00B0 */  lfs      f0, 176(r29);
/* 800B08D0 C05E00B0 */  lfs      f2, 176(r30);
/* 800B08D4 EC01002A */  fadds    f0, f1, f0;
/* 800B08D8 FC020040 */  fcmpo    cr0, f2, f0;
/* 800B08DC 4C411382 */  cror     2, 1, 2;
/* 800B08E0 40820098 */  bne-     UNDEF_800b0978;

                         mr       r3, r29;
                         mr       r4, r30;
/* 800B08FC 38A00018 */  li       r5, 24;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 800B0904 38600001 */  li       r3, 1;
/* 800B0918          */  stw      r3, 0(r31);
/* 800B091C 48000060 */  b        UNDEF_800b097c;

UNDEF_800b0978:;
/* 800B0978 38600000 */  li       r3, 0;
UNDEF_800b097c:;
/* 800B097C 80010024 */  lwz      r0, 36(r1);
/* 800B0980 83E1001C */  lwz      r31, 28(r1);
/* 800B0984 83C10018 */  lwz      r30, 24(r1);
/* 800B0988 83A10014 */  lwz      r29, 20(r1);
/* 800B098C 7C0803A6 */  mtlr     r0;
/* 800B0990 38210020 */  addi     r1, r1, 32;
/* 800B0994 4E800020 */  blr;
  // clang-format on
);