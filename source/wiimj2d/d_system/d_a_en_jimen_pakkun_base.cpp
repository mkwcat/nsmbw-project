// d_a_en_jimen_pakkun_base.cpp
// NSMBW .text: 0x8002EF50 - 0x800311E0

#include "d_a_en_jimen_pakkun_base.h"

[[nsmbw(0x8002F870)]]
void daEnJimenPakkunBase_c::Normal_VsPlHitCheck(
    dCc_c* main, dCc_c* other
) ASM_METHOD(
/* 8002F870 9421FFE0 */  stwu     r1, -32(r1);
/* 8002F874 7C0802A6 */  mflr     r0;
/* 8002F878 90010024 */  stw      r0, 36(r1);
/* 8002F87C 93E1001C */  stw      r31, 28(r1);
/* 8002F880 93C10018 */  stw      r30, 24(r1);
/* 8002F884 7CBE2B78 */  mr       r30, r5;
/* 8002F888 93A10014 */  stw      r29, 20(r1);
/* 8002F88C 7C7D1B78 */  mr       r29, r3;
/* 8002F890 83E50004 */  lwz      r31, 4(r5);
/* 8002F894 7FE4FB78 */  mr       r4, r31;
/* 8002F898 48067959 */  bl       UNDEF_800971f0;
/* 8002F89C 2C030000 */  cmpwi    r3, 0;
/* 8002F8A0 40820054 */  bne-     UNDEF_8002f8f4;
/* 8002F8A4 819D0060 */  lwz      r12, 96(r29);
/* 8002F8A8 7FA3EB78 */  mr       r3, r29;
/* 8002F8AC 7FE4FB78 */  mr       r4, r31;
/* 8002F8B0 818C0220 */  lwz      r12, 544(r12);
/* 8002F8B4 7D8903A6 */  mtctr    r12;
/* 8002F8B8 4E800421 */  bctrl;
/* 8002F8BC 881E002D */  lbz      r0, 45(r30);
/* 8002F8C0 2800000A */  cmplwi   r0, 10;
/* 8002F8C4 40820030 */  bne-     UNDEF_8002f8f4;

                         mr       r3, r29;
/* 8002F8C8          */  mr       r4, r31;
/* 8002F8CC          */  li       r5, 28;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;
UNDEF_8002f8f4:;
/* 8002F8F4 80010024 */  lwz      r0, 36(r1);
/* 8002F8F8 83E1001C */  lwz      r31, 28(r1);
/* 8002F8FC 83C10018 */  lwz      r30, 24(r1);
/* 8002F900 83A10014 */  lwz      r29, 20(r1);
/* 8002F904 7C0803A6 */  mtlr     r0;
/* 8002F908 38210020 */  addi     r1, r1, 32;
/* 8002F90C 4E800020 */  blr;
);

[[nsmbw(0x8002F970)]]
int daEnJimenPakkunBase_c::hitCallback_YoshiHipAttk(
    dCc_c* main, dCc_c* other
) ASM_METHOD(
/* 8002F970 9421FFE0 */  stwu     r1, -32(r1);
/* 8002F974 7C0802A6 */  mflr     r0;
/* 8002F978 90010024 */  stw      r0, 36(r1);
/* 8002F97C 93E1001C */  stw      r31, 28(r1);
/* 8002F980 93C10018 */  stw      r30, 24(r1);
/* 8002F984 93A10014 */  stw      r29, 20(r1);
/* 8002F988 7C7D1B78 */  mr       r29, r3;
/* 8002F98C 83C50004 */  lwz      r30, 4(r5);

/* 8002F994          */  mr       r4, r30;
                         bl       getCollTimer__5dEn_cCFP8dActor_c;
/* 8002F9B8          */  cmpwi    r3, 0;
/* 8002F9BC 4182000C */  beq-     UNDEF_8002f9c8;
/* 8002F9C0 38600001 */  li       r3, 1;
/* 8002F9C4 48000070 */  b        UNDEF_8002fa34;
UNDEF_8002f9c8:;
                         mr       r3, r29;
/* 8002F9CC          */  mr       r4, r30;
/* 8002F9D0          */  li       r5, 16;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 8002f9E4 7FA3EB78 */  mr       r3, r29;
/* 8002f9E8 7FC4F378 */  mr       r4, r30;
/* 8002F9FC 819D0060 */  lwz      r12, 96(r29);
/* 8002FA00 818C0258 */  lwz      r12, 600(r12);
/* 8002FA04 7D8903A6 */  mtctr    r12;
/* 8002FA08 4E800421 */  bctrl;
/* 8002FA0C 83EDA6BC */  lwz      r31, UNDEF_8042a03c@sda21;
/* 8002FA10 38610008 */  addi     r3, r1, 8;
/* 8002FA14 389D00AC */  addi     r4, r29, 172;
/* 8002FA18 4803AA99 */  bl       UNDEF_8006a4b0;
/* 8002FA1C 7FE3FB78 */  mr       r3, r31;
/* 8002FA20 38A10008 */  addi     r5, r1, 8;
/* 8002FA24 38800161 */  li       r4, 353;
/* 8002FA28 38C00000 */  li       r6, 0;
/* 8002FA2C 48168615 */  bl       UNDEF_80198040;
/* 8002FA30 38600001 */  li       r3, 1;
UNDEF_8002fa34:;
/* 8002FA34 80010024 */  lwz      r0, 36(r1);
/* 8002FA38 83E1001C */  lwz      r31, 28(r1);
/* 8002FA3C 83C10018 */  lwz      r30, 24(r1);
/* 8002FA40 83A10014 */  lwz      r29, 20(r1);
/* 8002FA44 7C0803A6 */  mtlr     r0;
/* 8002FA48 38210020 */  addi     r1, r1, 32;
/* 8002FA4C 4E800020 */  blr;
);
