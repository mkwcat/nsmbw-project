// d_a_en_big_hanachan.cpp
// NSMBW d_enemies.text: 0x809B1EC0 - 0x809B4200

#include "d_a_en_big_hanachan.h"

[[nsmbw(0x809B28C0)]]
void daEnBigHanachan_c::Normal_VsPlHitCheck(
    dCc_c* self, dCc_c* other
) ASM_METHOD(
/* 809B28C0 9421FFE0 */  stwu     r1, -32(r1);
/* 809B28C4 7C0802A6 */  mflr     r0;
/* 809B28C8 90010024 */  stw      r0, 36(r1);
/* 809B28CC 93E1001C */  stw      r31, 28(r1);
/* 809B28D0 7C7F1B78 */  mr       r31, r3;
/* 809B28D4 93C10018 */  stw      r30, 24(r1);
/* 809B28D8 93A10014 */  stw      r29, 20(r1);
/* 809B28DC 93810010 */  stw      r28, 16(r1);
/* 809B28E0 7C9C2378 */  mr       r28, r4;
/* 809B28E4 8805002D */  lbz      r0, 0x2D(r5);
/* 809B28E8 886500A1 */  lbz      r3, 0xA1(r5);
/* 809B28EC 2800000A */  cmplwi   r0, 10;
/* 809B28F0 83C50004 */  lwz      r30, 4(r5);
/* 809B28F4 60600002 */  ori      r0, r3, 2;
/* 809B28F8 980500A1 */  stb      r0, 0xA1(r5);
/* 809B28FC 40820050 */  bne-     UNDEF_809b294c;
/* 809B2900 819E0060 */  lwz      r12, 96(r30);
/* 809B2904 7FC3F378 */  mr       r3, r30;
/* 809B2908 7FE4FB78 */  mr       r4, r31;
/* 809B290C 38A00003 */  li       r5, 3;
/* 809B2910 818C03F8 */  lwz      r12, 1016(r12);
/* 809B2914 7D8903A6 */  mtctr    r12;
/* 809B2918 4E800421 */  bctrl;

                         // Damage cooldown
                         mr       r3, r31;
                         mr       r4, r30;
                         li       r5, 28;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 809B2948 48000150 */  b        UNDEF_809b2a98;
UNDEF_809b294c:;
/* 809B294C 80040018 */  lwz      r0, 24(r4);
/* 809B2950 3BA00000 */  li       r29, 0;
/* 809B2954 28000001 */  cmplwi   r0, 1;
/* 809B2958 40820030 */  bne-     UNDEF_809b2988;
/* 809B295C 387E01EC */  addi     r3, r30, 492;
/* 809B2960 4B6BE351 */  bl       UNDEF_80070cb0;
/* 809B2964 2C030000 */  cmpwi    r3, 0;
/* 809B2968 40820020 */  bne-     UNDEF_809b2988;
/* 809B296C 7F83E378 */  mr       r3, r28;
/* 809B2970 4B6D9B81 */  bl       UNDEF_8008c4f0;
/* 809B2974 C01E00B0 */  lfs      f0, 176(r30);
/* 809B2978 FC000840 */  fcmpo    cr0, f0, f1;
/* 809B297C 4C411382 */  cror     2, 1, 2;
/* 809B2980 40820008 */  bne-     UNDEF_809b2988;
/* 809B2984 3BA00001 */  li       r29, 1;
UNDEF_809b2988:;
/* 809B2988 2C1D0000 */  cmpwi    r29, 0;
/* 809B298C 4182006C */  beq-     UNDEF_809b29f8;
/* 809B2990 819F0060 */  lwz      r12, 96(r31);
/* 809B2994 7FE3FB78 */  mr       r3, r31;
/* 809B2998 818C0224 */  lwz      r12, 548(r12);
/* 809B299C 7D8903A6 */  mtctr    r12;
/* 809B29A0 4E800421 */  bctrl;
/* 809B29A4 819F0060 */  lwz      r12, 96(r31);
/* 809B29A8 7FE3FB78 */  mr       r3, r31;
/* 809B29AC 7FC4F378 */  mr       r4, r30;
/* 809B29B0 818C024C */  lwz      r12, 588(r12);
/* 809B29B4 7D8903A6 */  mtctr    r12;
/* 809B29B8 4E800421 */  bctrl;
/* 809B29BC 7FE3FB78 */  mr       r3, r31;
/* 809B29C0 7FC4F378 */  mr       r4, r30;
/* 809B29C4 4B6E42DD */  bl       UNDEF_80096ca0;

                         // Damage cooldown
                         mr       r3, r31;
                         mr       r4, r30;
                         li       r5, 10;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 809B29F4 480000A4 */  b        UNDEF_809b2a98;
UNDEF_809b29f8:;
/* 809B29F8 819E0060 */  lwz      r12, 96(r30);
/* 809B29FC 7FC3F378 */  mr       r3, r30;
/* 809B2A00 818C03D4 */  lwz      r12, 980(r12);
/* 809B2A04 7D8903A6 */  mtctr    r12;
/* 809B2A08 4E800421 */  bctrl;
/* 809B2A0C 2C030000 */  cmpwi    r3, 0;
/* 809B2A10 41820050 */  beq-     UNDEF_809b2a60;
/* 809B2A14 819E0060 */  lwz      r12, 96(r30);
/* 809B2A18 7FC3F378 */  mr       r3, r30;
/* 809B2A1C 7FE4FB78 */  mr       r4, r31;
/* 809B2A20 38A00003 */  li       r5, 3;
/* 809B2A24 818C03F8 */  lwz      r12, 1016(r12);
/* 809B2A28 7D8903A6 */  mtctr    r12;
/* 809B2A2C 4E800421 */  bctrl;

                         // Damage cooldown
                         mr       r3, r31;
                         mr       r4, r30;
                         li       r5, 28;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 809B2A5C 4800003C */  b        UNDEF_809b2a98;
UNDEF_809b2a60:;
/* 809B2A60 819E0060 */  lwz      r12, 96(r30);
/* 809B2A64 7FC3F378 */  mr       r3, r30;
/* 809B2A68 818C03F0 */  lwz      r12, 1008(r12);
/* 809B2A6C 7D8903A6 */  mtctr    r12;
/* 809B2A70 4E800421 */  bctrl;
/* 809B2A74 2C030000 */  cmpwi    r3, 0;
/* 809B2A78 40820020 */  bne-     UNDEF_809b2a98;
/* 809B2A7C 819E0060 */  lwz      r12, 96(r30);
/* 809B2A80 7FC3F378 */  mr       r3, r30;
/* 809B2A84 7FE4FB78 */  mr       r4, r31;
/* 809B2A88 38A00000 */  li       r5, 0;
/* 809B2A8C 818C03F8 */  lwz      r12, 1016(r12);
/* 809B2A90 7D8903A6 */  mtctr    r12;
/* 809B2A94 4E800421 */  bctrl;
UNDEF_809b2a98:;
/* 809B2A98 80010024 */  lwz      r0, 36(r1);
/* 809B2A9C 83E1001C */  lwz      r31, 28(r1);
/* 809B2AA0 83C10018 */  lwz      r30, 24(r1);
/* 809B2AA4 83A10014 */  lwz      r29, 20(r1);
/* 809B2AA8 83810010 */  lwz      r28, 16(r1);
/* 809B2AAC 7C0803A6 */  mtlr     r0;
/* 809B2AB0 38210020 */  addi     r1, r1, 32;
/* 809B2AB4 4E800020 */  blr;
);

[[nsmbw(0x809B2AD0)]]
void daEnBigHanachan_c::Normal_VsYoshiHitCheck(
    dCc_c* self, dCc_c* other
) ASM_METHOD(
/* 809B2AD0 9421FFE0 */  stwu     r1, -32(r1);
/* 809B2AD4 7C0802A6 */  mflr     r0;
/* 809B2AD8 90010024 */  stw      r0, 36(r1);
/* 809B2ADC 93E1001C */  stw      r31, 28(r1);
/* 809B2AE0 93C10018 */  stw      r30, 24(r1);
/* 809B2AE4 3BC00000 */  li       r30, 0;
/* 809B2AE8 93A10014 */  stw      r29, 20(r1);
/* 809B2AEC 7C9D2378 */  mr       r29, r4;
/* 809B2AF0 93810010 */  stw      r28, 16(r1);
/* 809B2AF4 7C7C1B78 */  mr       r28, r3;
/* 809B2AF8 880500A1 */  lbz      r0, 161(r5);
/* 809B2AFC 83E50004 */  lwz      r31, 4(r5);
/* 809B2B00 60000002 */  ori      r0, r0, 2;
/* 809B2B04 980500A1 */  stb      r0, 161(r5);
/* 809B2B08 80040018 */  lwz      r0, 24(r4);
/* 809B2B0C 28000001 */  cmplwi   r0, 1;
/* 809B2B10 40820030 */  bne-     UNDEF_809b2b40;
/* 809B2B14 387F01EC */  addi     r3, r31, 492;
/* 809B2B18 4B6BE199 */  bl       UNDEF_80070cb0;
/* 809B2B1C 2C030000 */  cmpwi    r3, 0;
/* 809B2B20 40820020 */  bne-     UNDEF_809b2b40;
/* 809B2B24 7FA3EB78 */  mr       r3, r29;
/* 809B2B28 4B6D99C9 */  bl       UNDEF_8008c4f0;
/* 809B2B2C C01F00B0 */  lfs      f0, 176(r31);
/* 809B2B30 FC000840 */  fcmpo    cr0, f0, f1;
/* 809B2B34 4C411382 */  cror     2, 1, 2;
/* 809B2B38 40820008 */  bne-     UNDEF_809b2b40;
/* 809B2B3C 3BC00001 */  li       r30, 1;
UNDEF_809b2b40:;
/* 809B2B40 2C1E0000 */  cmpwi    r30, 0;
/* 809B2B44 4182006C */  beq-     UNDEF_809b2bb0;
/* 809B2B48 819C0060 */  lwz      r12, 96(r28);
/* 809B2B4C 7F83E378 */  mr       r3, r28;
/* 809B2B50 818C0224 */  lwz      r12, 548(r12);
/* 809B2B54 7D8903A6 */  mtctr    r12;
/* 809B2B58 4E800421 */  bctrl;
/* 809B2B5C 819C0060 */  lwz      r12, 96(r28);
/* 809B2B60 7F83E378 */  mr       r3, r28;
/* 809B2B64 7FE4FB78 */  mr       r4, r31;
/* 809B2B68 818C0258 */  lwz      r12, 600(r12);
/* 809B2B6C 7D8903A6 */  mtctr    r12;
/* 809B2B70 4E800421 */  bctrl;
/* 809B2B74 7F83E378 */  mr       r3, r28;
/* 809B2B78 7FE4FB78 */  mr       r4, r31;
/* 809B2B7C 4B6E4185 */  bl       UNDEF_80096d00; // yoshifumistepSE__5dEn_cFP8dActor_c

                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r31;
                         li       r5, 10;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 809B2BAC 480000A4 */  b        UNDEF_809b2c50;
UNDEF_809b2bb0:;
/* 809B2BB0 819F0060 */  lwz      r12, 96(r31);
/* 809B2BB4 7FE3FB78 */  mr       r3, r31;
/* 809B2BB8 818C03D4 */  lwz      r12, 980(r12);
/* 809B2BBC 7D8903A6 */  mtctr    r12;
/* 809B2BC0 4E800421 */  bctrl;
/* 809B2BC4 2C030000 */  cmpwi    r3, 0;
/* 809B2BC8 41820050 */  beq-     UNDEF_809b2c18;
/* 809B2BCC 819F0060 */  lwz      r12, 96(r31);
/* 809B2BD0 7FE3FB78 */  mr       r3, r31;
/* 809B2BD4 7F84E378 */  mr       r4, r28;
/* 809B2BD8 38A00003 */  li       r5, 3;
/* 809B2BDC 818C03F8 */  lwz      r12, 1016(r12);
/* 809B2BE0 7D8903A6 */  mtctr    r12;
/* 809B2BE4 4E800421 */  bctrl;

                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r31;
                         li       r5, 28;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 809B2C14 4800003C */  b        UNDEF_809b2c50;
UNDEF_809b2c18:;
/* 809B2C18 819F0060 */  lwz      r12, 96(r31);
/* 809B2C1C 7FE3FB78 */  mr       r3, r31;
/* 809B2C20 818C03F0 */  lwz      r12, 1008(r12);
/* 809B2C24 7D8903A6 */  mtctr    r12;
/* 809B2C28 4E800421 */  bctrl;
/* 809B2C2C 2C030000 */  cmpwi    r3, 0;
/* 809B2C30 40820020 */  bne-     UNDEF_809b2c50;
/* 809B2C34 819F0060 */  lwz      r12, 96(r31);
/* 809B2C38 7FE3FB78 */  mr       r3, r31;
/* 809B2C3C 7F84E378 */  mr       r4, r28;
/* 809B2C40 38A00000 */  li       r5, 0;
/* 809B2C44 818C03F8 */  lwz      r12, 1016(r12);
/* 809B2C48 7D8903A6 */  mtctr    r12;
/* 809B2C4C 4E800421 */  bctrl;
UNDEF_809b2c50:;
/* 809B2C50 80010024 */  lwz      r0, 36(r1);
/* 809B2C54 83E1001C */  lwz      r31, 28(r1);
/* 809B2C58 83C10018 */  lwz      r30, 24(r1);
/* 809B2C5C 83A10014 */  lwz      r29, 20(r1);
/* 809B2C60 83810010 */  lwz      r28, 16(r1);
/* 809B2C64 7C0803A6 */  mtlr     r0;
/* 809B2C68 38210020 */  addi     r1, r1, 32;
/* 809B2C6C 4E800020 */  blr;
);
