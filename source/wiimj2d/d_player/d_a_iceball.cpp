// d_a_iceball.cpp
// NSMBW .text: 0x801233F0 - 0x80124D40

#include "d_system/d_mj2d_game.h"
#include <mkwcat/Relocate.hpp>

/* 0x80375DA8 */
[[gnu::section(".sdata")]]
int daIceBall_c_m_limit1[PLAYER_COUNT];

/* 0x80375DB8 */
[[gnu::section(".sdata")]]
int daIceBall_c_m_limit2[PLAYER_COUNT];

[[nsmbw(0x80123470)]]
int daIceBall_c_create(void* this_) ASM_METHOD(
  // clang-format off
/* 80123470 9421FFC0 */  stwu     r1, -64(r1);
/* 80123474 7C0802A6 */  mflr     r0;
/* 80123478 90010044 */  stw      r0, 68(r1);
/* 8012347C 93E1003C */  stw      r31, 60(r1);
/* 80123480 3FE0802F */  lis      r31, UNDEF_802f5000@ha;
/* 80123484 3BFF5000 */  addi     r31, r31, UNDEF_802f5000@l;
/* 80123488 93C10038 */  stw      r30, 56(r1);
/* 8012348C 3FC08037 */  lis      r30, daIceBall_c_m_limit1@ha;
/* 80123490 3BDE5DA8 */  addi     r30, r30, daIceBall_c_m_limit1@l;
/* 80123494 93A10034 */  stw      r29, 52(r1);
/* 80123498 7C7D1B78 */  mr       r29, r3;
/* 8012349C 80830004 */  lwz      r4, 4(r3);
/* 801234A0          */  rlwinm   r0, r4, 0, 0xF;
/* 801234A4 9803038D */  stb      r0, 909(r3);
/* 801234A8 7C030378 */  mr       r3, r0;
/* 801234AC 548487BE */  extrwi   r4, r4, 2, 14;
/* 801234B0 7C630774 */  extsb    r3, r3;
/* 801234B4 4800124D */  bl       UNDEF_80124700;
/* 801234B8 881D038D */  lbz      r0, 909(r29);
/* 801234BC 3880003C */  li       r4, 60;
/* 801234C0 909D03D0 */  stw      r4, 976(r29);
/* 801234C4 38DE0000 */  addi     r6, r30, 0;
/* 801234C8 7C000774 */  extsb    r0, r0;
/* 801234CC 389E0010 */  addi     r4, r30, daIceBall_c_m_limit2 - daIceBall_c_m_limit1;
/* 801234D0 5407103A */  slwi     r7, r0, 2;
/* 801234D4 2C030000 */  cmpwi    r3, 0;
/* 801234D8 7CA6382E */  lwzx     r5, r6, r7;
/* 801234DC 7C64382E */  lwzx     r3, r4, r7;
/* 801234E0 38050001 */  addi     r0, r5, 1;
/* 801234E4 7C06392E */  stwx     r0, r6, r7;
/* 801234E8 38030001 */  addi     r0, r3, 1;
/* 801234EC 7C04392E */  stwx     r0, r4, r7;
/* 801234F0 40820014 */  bne-     UNDEF_80123504;
/* 801234F4 7FA3EB78 */  mr       r3, r29;
/* 801234F8 4803F159 */  bl       UNDEF_80162650;
/* 801234FC 38600000 */  li       r3, 0;
/* 80123500 48000200 */  b        UNDEF_80123700;
UNDEF_80123504:;
/* 80123504 801D0004 */  lwz      r0, 4(r29);
/* 80123508 389D03E0 */  addi     r4, r29, 992;
/* 8012350C C03D00AC */  lfs      f1, 172(r29);
/* 80123510 5403C7BE */  extrwi   r3, r0, 2, 22;
/* 80123514 5400A7BE */  extrwi   r0, r0, 2, 18;
/* 80123518 981D01E7 */  stb      r0, 487(r29);
/* 8012351C C05D00B0 */  lfs      f2, 176(r29);
/* 80123520 981D02D1 */  stb      r0, 721(r29);
/* 80123524 981D030A */  stb      r0, 778(r29);
/* 80123528 987D038F */  stb      r3, 911(r29);
/* 8012352C 987D01E8 */  stb      r3, 488(r29);
/* 80123530 987D02D8 */  stb      r3, 728(r29);
/* 80123534 4BF51D3D */  bl       UNDEF_80075270;
/* 80123538 801D0004 */  lwz      r0, 4(r29);
/* 8012353C 3881000C */  addi     r4, r1, 12;
/* 80123540 907D03DC */  stw      r3, 988(r29);
/* 80123544 7FA3EB78 */  mr       r3, r29;
/* 80123548 5400E7FE */  extrwi   r0, r0, 1, 27;
/* 8012354C C002A5F0 */  lfs      f0, UNDEF_8042d950@sda21;
/* 80123550 981D0348 */  stb      r0, 840(r29);
/* 80123554 D001000C */  stfs     f0, 12(r1);
/* 80123558 480003D9 */  bl       UNDEF_80123930;
/* 8012355C 2C030000 */  cmpwi    r3, 0;
/* 80123560 41820014 */  beq-     UNDEF_80123574;
/* 80123564 C022A5F4 */  lfs      f1, UNDEF_8042d954@sda21;
/* 80123568 C001000C */  lfs      f0, 12(r1);
/* 8012356C EC01002A */  fadds    f0, f1, f0;
/* 80123570 D01D00B0 */  stfs     f0, 176(r29);
UNDEF_80123574:;
/* 80123574 7FA3EB78 */  mr       r3, r29;
/* 80123578 48000309 */  bl       UNDEF_80123880;
/* 8012357C 2C030000 */  cmpwi    r3, 0;
/* 80123580 41820040 */  beq-     UNDEF_801235c0;
/* 80123584 7FA3EB78 */  mr       r3, r29;
/* 80123588 480005B9 */  bl       UNDEF_80123b40;
/* 8012358C 83CDA6C0 */  lwz      r30, UNDEF_8042a040@sda21;
/* 80123590 38610010 */  addi     r3, r1, 16;
/* 80123594 389D00AC */  addi     r4, r29, 172;
/* 80123598 4BF46F19 */  bl       UNDEF_8006a4b0;
/* 8012359C 7FC3F378 */  mr       r3, r30;
/* 801235A0 38A10010 */  addi     r5, r1, 16;
/* 801235A4 38800269 */  li       r4, 617;
/* 801235A8 38C00000 */  li       r6, 0;
/* 801235AC 480757C5 */  bl       UNDEF_80198d70;
/* 801235B0 7FA3EB78 */  mr       r3, r29;
/* 801235B4 4803F09D */  bl       UNDEF_80162650;
/* 801235B8 38600000 */  li       r3, 0;
/* 801235BC 48000144 */  b        UNDEF_80123700;
UNDEF_801235c0:;
/* 801235C0 801D0120 */  lwz      r0, 288(r29);
/* 801235C4 38600005 */  li       r3, 5;
/* 801235C8 C002A5F0 */  lfs      f0, UNDEF_8042d950@sda21;
/* 801235CC 60000080 */  ori      r0, r0, 128;
/* 801235D0 D01D00D0 */  stfs     f0, 208(r29);
/* 801235D4 D01D00D4 */  stfs     f0, 212(r29);
/* 801235D8 D01D00D8 */  stfs     f0, 216(r29);
/* 801235DC 987D036D */  stb      r3, 877(r29);
/* 801235E0 901D0120 */  stw      r0, 288(r29);
/* 801235E4 806DAB28 */  lwz      r3, UNDEF_8042a4a8@sda21;
/* 801235E8 808DA7F8 */  lwz      r4, UNDEF_8042a178@sda21;
/* 801235EC 8803120E */  lbz      r0, 4622(r3);
/* 801235F0 1C0003B0 */  mulli    r0, r0, 944;
/* 801235F4 7C640214 */  add      r3, r4, r0;
/* 801235F8 8003002C */  lwz      r0, 44(r3);
/* 801235FC 2C000000 */  cmpwi    r0, 0;
/* 80123600 41820008 */  beq-     UNDEF_80123608;
/* 80123604 48000008 */  b        UNDEF_8012360c;
UNDEF_80123608:;
/* 80123608 38600000 */  li       r3, 0;
UNDEF_8012360c:;
/* 8012360C 389D00AC */  addi     r4, r29, 172;
/* 80123610 4BF6B161 */  bl       UNDEF_8008e770;
/* 80123614 987D0349 */  stb      r3, 841(r29);
/* 80123618 7FA4EB78 */  mr       r4, r29;
/* 8012361C 387D0148 */  addi     r3, r29, 328;
/* 80123620 38BF0034 */  addi     r5, r31, 52;
/* 80123624 4BF68DBD */  bl       UNDEF_8008c3e0;
/* 80123628 881D038F */  lbz      r0, 911(r29);
/* 8012362C 387D0148 */  addi     r3, r29, 328;
/* 80123630 981D01E8 */  stb      r0, 488(r29);
/* 80123634 4BF68CFD */  bl       UNDEF_8008c330;
/* 80123638 819D040C */  lwz      r12, 1036(r29);
/* 8012363C 387D040C */  addi     r3, r29, 1036;
/* 80123640 389D03F0 */  addi     r4, r29, 1008;
/* 80123644 38A00003 */  li       r5, 3;
/* 80123648 818C0008 */  lwz      r12, 8(r12);
/* 8012364C 7D8903A6 */  mtctr    r12;
/* 80123650 4E800421 */  bctrl;
/* 80123654 C022A5F4 */  lfs      f1, UNDEF_8042d954@sda21;
/* 80123658 38610018 */  addi     r3, r1, 24;
/* 8012365C C01D00B0 */  lfs      f0, 176(r29);
/* 80123660 38810008 */  addi     r4, r1, 8;
/* 80123664 C07D00B4 */  lfs      f3, 180(r29);
/* 80123668 38C00001 */  li       r6, 1;
/* 8012366C C05D00AC */  lfs      f2, 172(r29);
/* 80123670 EC01002A */  fadds    f0, f1, f0;
/* 80123674 D0410018 */  stfs     f2, 24(r1);
/* 80123678 D001001C */  stfs     f0, 28(r1);
/* 8012367C D0610020 */  stfs     f3, 32(r1);
/* 80123680 88BD038F */  lbz      r5, 911(r29);
/* 80123684 4BF5261D */  bl       UNDEF_80075ca0;
/* 80123688 2C030000 */  cmpwi    r3, 0;
/* 8012368C 41820020 */  beq-     UNDEF_801236ac;
/* 80123690 C0210008 */  lfs      f1, 8(r1);
/* 80123694 C002A5F8 */  lfs      f0, UNDEF_8042d958@sda21;
/* 80123698 C05D00B0 */  lfs      f2, 176(r29);
/* 8012369C EC010028 */  fsubs    f0, f1, f0;
/* 801236A0 FC020040 */  fcmpo    cr0, f2, f0;
/* 801236A4 40810008 */  ble-     UNDEF_801236ac;
/* 801236A8 D01D00B0 */  stfs     f0, 176(r29);
UNDEF_801236ac:;
/* 801236AC 7FA4EB78 */  mr       r4, r29;
/* 801236B0 387D01EC */  addi     r3, r29, 492;
/* 801236B4 38BF0010 */  addi     r5, r31, 16;
/* 801236B8 38DF001C */  addi     r6, r31, 28;
/* 801236BC 38FF0028 */  addi     r7, r31, 40;
/* 801236C0 4BF499D1 */  bl       UNDEF_8006d090;
/* 801236C4 C05D00AC */  lfs      f2, 172(r29);
/* 801236C8 38000000 */  li       r0, 0;
/* 801236CC C03D00B0 */  lfs      f1, 176(r29);
/* 801236D0 387D0394 */  addi     r3, r29, 916;
/* 801236D4 C01D00B4 */  lfs      f0, 180(r29);
/* 801236D8          */  lis      r4, UNDEF_80375dd8@ha; // daIceBall_c::StateID_FireMove
                         addi     r4, r4, UNDEF_80375dd8@l; // daIceBall_c::StateID_FireMove
/* 801236DC 901D03D4 */  stw      r0, 980(r29);
/* 801236E0 D05D03E4 */  stfs     f2, 996(r29);
/* 801236E4 D03D03E8 */  stfs     f1, 1000(r29);
/* 801236E8 D01D03EC */  stfs     f0, 1004(r29);
/* 801236EC 819D0394 */  lwz      r12, 916(r29);
/* 801236F0 818C0018 */  lwz      r12, 24(r12);
/* 801236F4 7D8903A6 */  mtctr    r12;
/* 801236F8 4E800421 */  bctrl;
/* 801236FC 38600001 */  li       r3, 1;
UNDEF_80123700:;
/* 80123700 80010044 */  lwz      r0, 68(r1);
/* 80123704 83E1003C */  lwz      r31, 60(r1);
/* 80123708 83C10038 */  lwz      r30, 56(r1);
/* 8012370C 83A10034 */  lwz      r29, 52(r1);
/* 80123710 7C0803A6 */  mtlr     r0;
/* 80123714 38210040 */  addi     r1, r1, 64;
/* 80123718 4E800020 */  blr;
  // clang-format on
);

PATCH_REFERENCES(
  &daIceBall_c_m_limit1, //
  {
    {0x8012348E, R_PPC_ADDR16_HA},
    {0x80123492, R_PPC_ADDR16_LO},
    {0x80123816, R_PPC_ADDR16_HA},
    {0x8012381A, R_PPC_ADDR16_LO},
    {0x80124702, R_PPC_ADDR16_HA},
    {0x8012470A, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daIceBall_c_m_limit2, //
  {
    {0x8012384A, R_PPC_ADDR16_HA},
    {0x8012384E, R_PPC_ADDR16_LO},
    {0x8012427E, R_PPC_ADDR16_HA},
    {0x80124282, R_PPC_ADDR16_LO},
    {0x801244BE, R_PPC_ADDR16_HA},
    {0x801244C2, R_PPC_ADDR16_LO},
    {0x8012472A, R_PPC_ADDR16_HA},
    {0x8012472E, R_PPC_ADDR16_LO},
  }
);
