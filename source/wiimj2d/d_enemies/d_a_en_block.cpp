// d_a_en_block.cpp
// NSMBW d_enemies.text: 0x809BED80 - 0x809C0770

#include "d_a_en_block.h"

#include "d_enemies/d_a_en_item.h"
#include "framework//f_param.h"

[[nsmbw(0x809BEE00)]]
void daEnBlock_c_onCreate() ASM_METHOD(
  // clang-format off
/* 809BEE00 9421FFE0 */  stwu     r1, -32(r1);
/* 809BEE04 7C0802A6 */  mflr     r0;
/* 809BEE08 3C808043 */  lis      r4, UNDEF_8042a0b0@ha; // m_bg_p__5dBg_c
/* 809BEE0C 90010024 */  stw      r0, 36(r1);
/* 809BEE10 93E1001C */  stw      r31, 28(r1);
/* 809BEE14 3FE080AD */  lis      r31, UNDEF_80ace250@ha;
/* 809BEE18 3BFFE250 */  addi     r31, r31, UNDEF_80ace250@l;
/* 809BEE1C 93C10018 */  stw      r30, 24(r1);
/* 809BEE20 7C7E1B78 */  mr       r30, r3;
/* 809BEE24 93A10014 */  stw      r29, 20(r1);
/* 809BEE28 93810010 */  stw      r28, 16(r1);
/* 809BEE2C 83A4A0B0 */  lwz      r29, UNDEF_8042a0b0@l(r4); // m_bg_p__5dBg_c
/* 809BEE30 806306BC */  lwz      r3, 1724(r3);
/* 809BEE34 7C1D1840 */  cmplw    r29, r3;
/* 809BEE38 41820044 */  beq-     UNDEF_809bee7c;
/* 809BEE3C 2C030000 */  cmpwi    r3, 0;
/* 809BEE40 4182001C */  beq-     UNDEF_809bee5c;
/* 809BEE44 34A30064 */  addic.   r5, r3, 100;
/* 809BEE48 41820008 */  beq-     UNDEF_809bee50;
/* 809BEE4C 38A5FF9C */  subi     r5, r5, 100;
UNDEF_809bee50:;
/* 809BEE50 38630064 */  addi     r3, r3, 100;
/* 809BEE54 389E06BC */  addi     r4, r30, 1724;
/* 809BEE58 4B7A2AE9 */  bl       UNDEF_80161940;
UNDEF_809bee5c:;
/* 809BEE5C 2C1D0000 */  cmpwi    r29, 0;
/* 809BEE60 4182001C */  beq-     UNDEF_809bee7c;
/* 809BEE64 34BD0064 */  addic.   r5, r29, 100;
/* 809BEE68 41820008 */  beq-     UNDEF_809bee70;
/* 809BEE6C 38A5FF9C */  subi     r5, r5, 100;
UNDEF_809bee70:;
/* 809BEE70 387D0064 */  addi     r3, r29, 100;
/* 809BEE74 389E06BC */  addi     r4, r30, 1724;
/* 809BEE78 4B7A2A19 */  bl       UNDEF_80161890;
UNDEF_809bee7c:;
/* 809BEE7C 807E06BC */  lwz      r3, 1724(r30);
/* 809BEE80 38800000 */  li       r4, 0;
/* 809BEE84 4B6B969D */  bl       UNDEF_80078520; // getPanelObjMgr__5dBg_cFi
/* 809BEE88 389E0698 */  addi     r4, r30, 1688;
/* 809BEE8C 4B655995 */  bl       UNDEF_80014820; // addPanelObjList__14dPanelObjMgr_cFP15dPanelObjList_c
/* 809BEE90 839E0004 */  lwz      r28, 4(r30);
/* 809BEE94 387F0008 */  addi     r3, r31, 8;
/* 809BEE98 C05E00AC */  lfs      f2, 172(r30);
/* 809BEE9C 3BA00008 */  li       r29, 8;
/* 809BEEA0 C03E00B0 */  lfs      f1, 176(r30);
/* 809BEEA4 578B06FE */  clrlwi   r11, r28, 27;
/* 809BEEA8 C01E00B4 */  lfs      f0, 180(r30);
/* 809BEEAC 578ADF7E */  extrwi   r10, r28, 3, 24;
/* 809BEEB0 C0A30004 */  lfs      f5, 4(r3);
/* 809BEEB4 5789C7BE */  extrwi   r9, r28, 2, 22;
/* 809BEEB8 C0DF0008 */  lfs      f6, 8(r31);
/* 809BEEBC 57880FFE */  srwi     r8, r28, 31;
/* 809BEEC0 C063000C */  lfs      f3, 12(r3);
/* 809BEEC4 57870420 */  rlwinm   r7, r28, 0, 16, 16;
/* 809BEEC8 C0830008 */  lfs      f4, 8(r3);
/* 809BEECC          */  extrwi   r6, r28, 2, 1; // Direction
/* 809BEED0 578547BE */  extrwi   r5, r28, 2, 6;
/* 809BEED4 38000001 */  li       r0, 1;
/* 809BEED8 B3BE0364 */  sth      r29, 868(r30);
/* 809BEEDC 3C608043 */  lis      r3, UNDEF_8042a2e0@ha; // ms_instance__13dPSwManager_c
/* 809BEEE0 38800000 */  li       r4, 0;
/* 809BEEE4 D05E07E0 */  stfs     f2, 2016(r30);
/* 809BEEE8 D03E07E4 */  stfs     f1, 2020(r30);
/* 809BEEEC D01E07E8 */  stfs     f0, 2024(r30);
/* 809BEEF0 917E0800 */  stw      r11, 2048(r30);
/* 809BEEF4 915E0804 */  stw      r10, 2052(r30);
/* 809BEEF8 913E0808 */  stw      r9, 2056(r30);
/* 809BEEFC 991E0348 */  stb      r8, 840(r30);
/* 809BEF00 90FE07FC */  stw      r7, 2044(r30);
/* 809BEF04 98DE0824 */  stb      r6, 2084(r30);
/* 809BEF08 98BE0666 */  stb      r5, 1638(r30);
/* 809BEF0C D0DE0320 */  stfs     f6, 800(r30);
/* 809BEF10 D0BE0324 */  stfs     f5, 804(r30);
/* 809BEF14 D09E0318 */  stfs     f4, 792(r30);
/* 809BEF18 D07E031C */  stfs     f3, 796(r30);
/* 809BEF1C 901E0134 */  stw      r0, 308(r30);
/* 809BEF20 8063A2E0 */  lwz      r3, UNDEF_8042a2e0@l(r3); // ms_instance__13dPSwManager_c
/* 809BEF24 4B71997D */  bl       UNDEF_800d88a0; // checkSwitch__13dPSwManager_cFQ213dPSwManager_c8SwType_e
/* 809BEF28 57804FFF */  extrwi.  r0, r28, 1, 8;
/* 809BEF2C 987E0820 */  stb      r3, 2080(r30);
/* 809BEF30          */  extrwi   r0, r28, 4, 12; // Player ID
/* 809BEF34 981E0823 */  stb      r0, 2083(r30);
/* 809BEF38 981E038D */  stb      r0, 909(r30);
/* 809BEF3C 41820008 */  beq-     UNDEF_809bef44;
/* 809BEF40 93BE0804 */  stw      r29, 2052(r30);
UNDEF_809bef44:;
/* 809BEF44 887E0823 */  lbz      r3, 2083(r30);
/* 809BEF48 4B6A09B9 */  bl       getPlayer__9daPyMng_cFi;
/* 809BEF4C C04300AC */  lfs      f2, 172(r3);
/* 809BEF50 38000001 */  li       r0, 1;
/* 809BEF54 C03E00AC */  lfs      f1, 172(r30);
/* 809BEF58 C01F0064 */  lfs      f0, 100(r31);
/* 809BEF5C EC220828 */  fsubs    f1, f2, f1;
/* 809BEF60 981E081D */  stb      r0, 2077(r30);
/* 809BEF64 FC010040 */  fcmpo    cr0, f1, f0;
/* 809BEF68 4C411382 */  cror     2, 1, 2;
/* 809BEF6C 4082000C */  bne-     UNDEF_809bef78;
/* 809BEF70 38000000 */  li       r0, 0;
/* 809BEF74 981E081D */  stb      r0, 2077(r30);
UNDEF_809bef78:;
/* 809BEF78 7FC4F378 */  mr       r4, r30;
/* 809BEF7C 387E01EC */  addi     r3, r30, 492;
/* 809BEF80 38DF0024 */  addi     r6, r31, 36;
/* 809BEF84 38A00000 */  li       r5, 0;
/* 809BEF88 38E00000 */  li       r7, 0;
/* 809BEF8C 4B6AE105 */  bl       UNDEF_8006d090;
/* 809BEF90 801E0804 */  lwz      r0, 2052(r30);
/* 809BEF94 389F0050 */  addi     r4, r31, 80;
/* 809BEF98 C01E00B0 */  lfs      f0, 176(r30);
/* 809BEF9C 387E0698 */  addi     r3, r30, 1688;
/* 809BEFA0 5400083C */  slwi     r0, r0, 1;
/* 809BEFA4 88BE0823 */  lbz      r5, 2083(r30);
/* 809BEFA8 7C04022E */  lhzx     r0, r4, r0;
/* 809BEFAC FC000050 */  fneg     f0, f0;
/* 809BEFB0 C03E00AC */  lfs      f1, 172(r30);
/* 809BEFB4 38800000 */  li       r4, 0;
/* 809BEFB8 98BE0284 */  stb      r5, 644(r30);
/* 809BEFBC B01E06A0 */  sth      r0, 1696(r30);
/* 809BEFC0 D03E06A4 */  stfs     f1, 1700(r30);
/* 809BEFC4 D01E06A8 */  stfs     f0, 1704(r30);
/* 809BEFC8 4B655699 */  bl       UNDEF_80014660; // setChange__15dPanelObjList_cFb
/* 809BEFCC C03E00B0 */  lfs      f1, 176(r30);
/* 809BEFD0 3BA00000 */  li       r29, 0;
/* 809BEFD4 C01F0068 */  lfs      f0, 104(r31);
/* 809BEFD8 38000002 */  li       r0, 2;
/* 809BEFDC C05E00AC */  lfs      f2, 172(r30);
/* 809BEFE0 7FC3F378 */  mr       r3, r30;
/* 809BEFE4 EC210028 */  fsubs    f1, f1, f0;
/* 809BEFE8 C01F0064 */  lfs      f0, 100(r31);
/* 809BEFEC 981E081F */  stb      r0, 2079(r30);
/* 809BEFF0 EC02002A */  fadds    f0, f2, f0;
/* 809BEFF4 D03E00B0 */  stfs     f1, 176(r30);
/* 809BEFF8 D01E00AC */  stfs     f0, 172(r30);
/* 809BEFFC D03E0630 */  stfs     f1, 1584(r30);
/* 809BF000 B3BE0816 */  sth      r29, 2070(r30);
/* 809BF004 B3BE080C */  sth      r29, 2060(r30);
/* 809BF008 B3BE0812 */  sth      r29, 2066(r30);
/* 809BF00C 9BBE081C */  stb      r29, 2076(r30);
/* 809BF010 4B662681 */  bl       UNDEF_80021690; // Block_CreateClearSet__15daEnBlockMain_cFf
/* 809BF014 807E0800 */  lwz      r3, 2048(r30);
/* 809BF018 38000001 */  li       r0, 1;
/* 809BF01C 981E067F */  stb      r0, 1663(r30);
/* 809BF020 28030002 */  cmplwi   r3, 2;
/* 809BF024 9BBE0822 */  stb      r29, 2082(r30);
/* 809BF028 93BE0648 */  stw      r29, 1608(r30);
/* 809BF02C 4182000C */  beq-     UNDEF_809bf038;
/* 809BF030 28030004 */  cmplwi   r3, 4;
/* 809BF034 40820030 */  bne-     UNDEF_809bf064;
UNDEF_809bf038:;
/* 809BF038 7FC3F378 */  mr       r3, r30;
/* 809BF03C 38800000 */  li       r4, 0;
/* 809BF040 48000551 */  bl       UNDEF_809bf590;
/* 809BF044 801E0800 */  lwz      r0, 2048(r30);
/* 809BF048 38600001 */  li       r3, 1;
/* 809BF04C 987E0822 */  stb      r3, 2082(r30);
/* 809BF050 28000002 */  cmplwi   r0, 2;
/* 809BF054 41820064 */  beq-     UNDEF_809bf0b8;
/* 809BF058 38000008 */  li       r0, 8;
/* 809BF05C B01E0500 */  sth      r0, 1280(r30);
/* 809BF060 48000058 */  b        UNDEF_809bf0b8;
UNDEF_809bf064:;
/* 809BF064 2803001A */  cmplwi   r3, 26;
/* 809BF068 40820018 */  bne-     UNDEF_809bf080;
/* 809BF06C 38600005 */  li       r3, 5;
/* 809BF070 3800000F */  li       r0, 15;
/* 809BF074 B07E080C */  sth      r3, 2060(r30);
/* 809BF078 901E0800 */  stw      r0, 2048(r30);
/* 809BF07C 4800003C */  b        UNDEF_809bf0b8;
UNDEF_809bf080:;
/* 809BF080 28030015 */  cmplwi   r3, 21;
/* 809BF084 40820034 */  bne-     UNDEF_809bf0b8;
/* 809BF088 881E0823 */  lbz      r0, 2083(r30);
/* 809BF08C 7FC3F378 */  mr       r3, r30;
/* 809BF090 7C040774 */  extsb    r4, r0;
/* 809BF094 4B6630ED */  bl       UNDEF_80022180; // player_bigmario_check__15daEnBlockMain_cFSc
/* 809BF098 2C030000 */  cmpwi    r3, 0;
/* 809BF09C 41820014 */  beq-     UNDEF_809bf0b0;
/* 809BF0A0 7FC3F378 */  mr       r3, r30;
/* 809BF0A4 38800000 */  li       r4, 0;
/* 809BF0A8 480004E9 */  bl       UNDEF_809bf590;
/* 809BF0AC 4800000C */  b        UNDEF_809bf0b8;
UNDEF_809bf0b0:;
/* 809BF0B0 38000008 */  li       r0, 8;
/* 809BF0B4 901E0800 */  stw      r0, 2048(r30);
UNDEF_809bf0b8:;
/* 809BF0B8 801E0800 */  lwz      r0, 2048(r30);
/* 809BF0BC 387F0030 */  addi     r3, r31, 48;
/* 809BF0C0 38800000 */  li       r4, 0;
/* 809BF0C4 7C0300AE */  lbzx     r0, r3, r0;
/* 809BF0C8 2C000000 */  cmpwi    r0, 0;
/* 809BF0CC 41820014 */  beq-     UNDEF_809bf0e0;
/* 809BF0D0 881E0824 */  lbz      r0, 2084(r30);
/* 809BF0D4 28000003 */  cmplwi   r0, 3;
/* 809BF0D8 40820008 */  bne-     UNDEF_809bf0e0;
/* 809BF0DC 38800001 */  li       r4, 1;
UNDEF_809bf0e0:;
/* 809BF0E0 2C040000 */  cmpwi    r4, 0;
/* 809BF0E4 4182003C */  beq-     UNDEF_809bf120;
/* 809BF0E8 7FC4F378 */  mr       r4, r30;
/* 809BF0EC 387E01EC */  addi     r3, r30, 492;
/* 809BF0F0 38BF0018 */  addi     r5, r31, 24;
/* 809BF0F4 38C00000 */  li       r6, 0;
/* 809BF0F8 38E00000 */  li       r7, 0;
/* 809BF0FC 4B6ADF95 */  bl       UNDEF_8006d090;
/* 809BF100 819E0060 */  lwz      r12, 96(r30);
/* 809BF104 3C808035 */  lis      r4, UNDEF_80352d74@ha;
/* 809BF108 7FC3F378 */  mr       r3, r30;
/* 809BF10C 818C00D4 */  lwz      r12, 212(r12);
/* 809BF110 38842D74 */  addi     r4, r4, UNDEF_80352d74@l;
/* 809BF114 7D8903A6 */  mtctr    r12;
/* 809BF118 4E800421 */  bctrl;
/* 809BF11C 4800004C */  b        UNDEF_809bf168;
UNDEF_809bf120:;
/* 809BF120 801E0808 */  lwz      r0, 2056(r30);
/* 809BF124 28000001 */  cmplwi   r0, 1;
/* 809BF128 40820024 */  bne-     UNDEF_809bf14c;
/* 809BF12C 819E0060 */  lwz      r12, 96(r30);
/* 809BF130 3C8080B1 */  lis      r4, UNDEF_80b125b8@ha;
/* 809BF134 7FC3F378 */  mr       r3, r30;
/* 809BF138 818C00D4 */  lwz      r12, 212(r12);
/* 809BF13C 388425B8 */  addi     r4, r4, UNDEF_80b125b8@l;
/* 809BF140 7D8903A6 */  mtctr    r12;
/* 809BF144 4E800421 */  bctrl;
/* 809BF148 48000020 */  b        UNDEF_809bf168;
UNDEF_809bf14c:;
/* 809BF14C 819E0060 */  lwz      r12, 96(r30);
/* 809BF150 3C808035 */  lis      r4, UNDEF_80352d34@ha;
/* 809BF154 7FC3F378 */  mr       r3, r30;
/* 809BF158 818C00D4 */  lwz      r12, 212(r12);
/* 809BF15C 38842D34 */  addi     r4, r4, UNDEF_80352d34@l;
/* 809BF160 7D8903A6 */  mtctr    r12;
/* 809BF164 4E800421 */  bctrl;
UNDEF_809bf168:;
/* 809BF168 881E0824 */  lbz      r0, 2084(r30);
/* 809BF16C C01F006C */  lfs      f0, 108(r31);
/* 809BF170 28000003 */  cmplwi   r0, 3;
/* 809BF174 D01E00DC */  stfs     f0, 220(r30);
/* 809BF178 D01E00E0 */  stfs     f0, 224(r30);
/* 809BF17C D01E00E4 */  stfs     f0, 228(r30);
/* 809BF180 40820010 */  bne-     UNDEF_809bf190;
/* 809BF184 38000001 */  li       r0, 1;
/* 809BF188 981E0689 */  stb      r0, 1673(r30);
/* 809BF18C 981E068A */  stb      r0, 1674(r30);
UNDEF_809bf190:;
/* 809BF190 C0DE00DC */  lfs      f6, 220(r30);
/* 809BF194 3D408002 */  lis      r10, UNDEF_80020d60@ha;
/* 809BF198 C0BE00E0 */  lfs      f5, 224(r30);
/* 809BF19C 3D208002 */  lis      r9, UNDEF_80020ea0@ha;
/* 809BF1A0 C09E00E4 */  lfs      f4, 228(r30);
/* 809BF1A4 394A0D60 */  addi     r10, r10, UNDEF_80020d60@l;
/* 809BF1A8 C07F0070 */  lfs      f3, 112(r31);
/* 809BF1AC 39290EA0 */  addi     r9, r9, UNDEF_80020ea0@l;
/* 809BF1B0 C05F0068 */  lfs      f2, 104(r31);
/* 809BF1B4 38000000 */  li       r0, 0;
/* 809BF1B8 C03F0064 */  lfs      f1, 100(r31);
/* 809BF1BC 7FC4F378 */  mr       r4, r30;
/* 809BF1C0 C01F0074 */  lfs      f0, 116(r31);
/* 809BF1C4 387E06C4 */  addi     r3, r30, 1732;
/* 809BF1C8 D0DE07D4 */  stfs     f6, 2004(r30);
/* 809BF1CC 38BE07A8 */  addi     r5, r30, 1960;
/* 809BF1D0 88FE038F */  lbz      r7, 911(r30);
/* 809BF1D4 391E07D4 */  addi     r8, r30, 2004;
/* 809BF1D8 D0BE07D8 */  stfs     f5, 2008(r30);
/* 809BF1DC 38C00003 */  li       r6, 3;
/* 809BF1E0 D09E07DC */  stfs     f4, 2012(r30);
/* 809BF1E4 915E07B8 */  stw      r10, 1976(r30);
/* 809BF1E8 913E07BC */  stw      r9, 1980(r30);
/* 809BF1EC 901E07C0 */  stw      r0, 1984(r30);
/* 809BF1F0 D07E07A8 */  stfs     f3, 1960(r30);
/* 809BF1F4 D05E07AC */  stfs     f2, 1964(r30);
/* 809BF1F8 D03E07B0 */  stfs     f1, 1968(r30);
/* 809BF1FC D01E07B4 */  stfs     f0, 1972(r30);
/* 809BF200 4B6C0911 */  bl       UNDEF_8007fb10; // set__9dBg_ctr_cFP8dActor_cPC10sBgSetInfoUcUcP7mVec3_c
/* 809BF204 3CC08002 */  lis      r6, UNDEF_80021180@ha;
/* 809BF208 3CA08002 */  lis      r5, UNDEF_80021170@ha;
/* 809BF20C 3C808002 */  lis      r4, UNDEF_800211a0@ha;
/* 809BF210 38600003 */  li       r3, 3;
/* 809BF214 38C61180 */  addi     r6, r6, UNDEF_80021180@l;
/* 809BF218 38A51170 */  addi     r5, r5, UNDEF_80021170@l;
/* 809BF21C 388411A0 */  addi     r4, r4, UNDEF_800211a0@l;
/* 809BF220 38000260 */  li       r0, 608;
/* 809BF224 987E07A1 */  stb      r3, 1953(r30);
/* 809BF228 387E06C4 */  addi     r3, r30, 1732;
/* 809BF22C 901E0794 */  stw      r0, 1940(r30);
/* 809BF230 90DE0710 */  stw      r6, 1808(r30);
/* 809BF234 90BE0714 */  stw      r5, 1812(r30);
/* 809BF238 909E0718 */  stw      r4, 1816(r30);
/* 809BF23C 4B6C06C5 */  bl       UNDEF_8007f900; // entry__9dBg_ctr_cFv
/* 809BF240 83E1001C */  lwz      r31, 28(r1);
/* 809BF244 38600001 */  li       r3, 1;
/* 809BF248 83C10018 */  lwz      r30, 24(r1);
/* 809BF24C 83A10014 */  lwz      r29, 20(r1);
/* 809BF250 83810010 */  lwz      r28, 16(r1);
/* 809BF254 80010024 */  lwz      r0, 36(r1);
/* 809BF258 7C0803A6 */  mtlr     r0;
/* 809BF25C 38210020 */  addi     r1, r1, 32;
/* 809BF260 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x809BF590)]]
bool daEnBlock_c::create_items(
    int param
) {
    if (m_item_created) {
        return false;
    }

    if (m_set_item == 21 && param == 1 && player_bigmario_check(m_player_number)) {
        return false;
    }

    bool single_item = false;
    switch (m_set_item) {
    case 2:
    case 3:
    case 4:
    case 10:
    case 12:
    case 13:
    case 18:
    case 29:
    case 30:
        single_item = true;
    }

    int     extra_player_count = playernumber_set();
    u32     base_param         = mParam;
    mVec3_c pos                = mPos;

    if (extra_player_count == 0 || m_block_type != 0 || single_item) {
        if (m_set_item == 21 && param == 0 && player_bigmario_check(m_player_number)) {
            pos.y -= 8.0f;
        }

        if (m0x81C) {
            dActor_c::construct(
                dProf::EN_ITEM, (base_param & 0x800F001Fu) | 0x03000000u, &pos, nullptr, mLayer
            );
        } else {
            fParam_c<daEnItem_c> item_param{base_param & 0xF0FFFF7Fu};
            item_param.direction = (base_param >> 29) & 3;
            dActor_c::construct(dProf::EN_ITEM, item_param, &pos, nullptr, mLayer);
        }

        m_item_created = true;
        item_sound_set(pos, m_set_item, m_player_number, 0, 0);
    } else {
        int player_item[PLAYER_COUNT];
        player_item_set(base_param & 0x1F, player_item, std::size(player_item));

        fParam_c<daEnItem_c> item_param{};
        if (m0x824 == 3) {
            item_param.create_type = 12;
            pos.y -= 8.0;
        } else {
            item_param.create_type = 11;
            pos.y += 16.0;
        }

        for (int i = 0; i < extra_player_count + 1; i++) {
            item_param.type        = player_item[i];
            item_param.facing      = i & 1;
            item_param.appear_type = i / 2;
            dActor_c::construct(dProf::EN_ITEM, item_param, &pos, nullptr, mLayer);
            item_sound_set(pos, player_item[i], m_player_number, 1, 0);
        }
        m_item_created = true;
    }

    return true;
}

[[nsmbw(0x809BFB40)]]
void daEnBlock_c::create_sub_item() {
    mVec3_c pos = {
        .x = mPos.x + (mDirection ? 6.0f : -6.0f),
        .y = mPos.y + 12.0f,
        .z = mPos.z,
    };

    fParam_c<daEnItem_c> item_param = mParam & 0x80FFFF7Fu;
    item_param.create_type          = 4;
    item_param.direction            = (mParam >> 29) & 3;
    dActor_c::construct(dProf::EN_ITEM, item_param, &pos, nullptr, mLayer);
}

[[nsmbw(0x809BFDD0)]]
void daEnBlock_c_spawnContent() ASM_METHOD(
  // clang-format off
/* 809BFDD0 9421FFD0 */  stwu     r1, -48(r1);
/* 809BFDD4 7C0802A6 */  mflr     r0;
/* 809BFDD8 90010034 */  stw      r0, 52(r1);
/* 809BFDDC 93E1002C */  stw      r31, 44(r1);
/* 809BFDE0 93C10028 */  stw      r30, 40(r1);
/* 809BFDE4 7C7E1B78 */  mr       r30, r3;
/* 809BFDE8 93A10024 */  stw      r29, 36(r1);
/* 809BFDEC 80030800 */  lwz      r0, 2048(r3);
/* 809BFDF0 2800000F */  cmplwi   r0, 15;
/* 809BFDF4 418201BC */  beq-     UNDEF_809bffb0;
/* 809BFDF8 2800001E */  cmplwi   r0, 30;
/* 809BFDFC 3BE00000 */  li       r31, 0;
/* 809BFE00 4181019C */  bgt-     UNDEF_809bff9c;
/* 809BFE04 3C8080AE */  lis      r4, .L_SwitchTable@ha;
/* 809BFE08 5400103A */  slwi     r0, r0, 2;
/* 809BFE0C 3884B060 */  addi     r4, r4, .L_SwitchTable@l;
/* 809BFE10 7C84002E */  lwzx     r4, r4, r0;
/* 809BFE14 7C8903A6 */  mtctr    r4;
/* 809BFE18 4E800420 */  bctr;
UNDEF_809bfe1c:;
/* 809BFE1C 3BE00001 */  li       r31, 1;
/* 809BFE20 4800017C */  b        UNDEF_809bff9c;
UNDEF_809bfe24:;
/* 809BFE24 3BE00001 */  li       r31, 1;
/* 809BFE28 4B662569 */  bl       UNDEF_80022390;
/* 809BFE2C 38030001 */  addi     r0, r3, 1;
/* 809BFE30 2C000001 */  cmpwi    r0, 1;
/* 809BFE34 41820010 */  beq-     UNDEF_809bfe44;
/* 809BFE38 801E0804 */  lwz      r0, 2052(r30);
/* 809BFE3C 28000001 */  cmplwi   r0, 1;
/* 809BFE40 40820018 */  bne-     UNDEF_809bfe58;
UNDEF_809bfe44:;
/* 809BFE44 801E0004 */  lwz      r0, 4(r30);
/* 809BFE48 7FC3F378 */  mr       r3, r30;
/* 809BFE4C          */  extrwi   r4, r0, 2, 1;
/* 809BFE50 4B661D81 */  bl       UNDEF_80021bd0;
/* 809BFE54 48000148 */  b        UNDEF_809bff9c;
UNDEF_809bfe58:;
/* 809BFE58 801E0004 */  lwz      r0, 4(r30);
/* 809BFE5C 7FC3F378 */  mr       r3, r30;
/* 809BFE60          */  extrwi   r4, r0, 2, 1;
/* 809BFE64 4B661E1D */  bl       UNDEF_80021c80;
/* 809BFE68 48000134 */  b        UNDEF_809bff9c;
UNDEF_809bfe6c:;
/* 809BFE6C 3BE00001 */  li       r31, 1;
/* 809BFE70 4B662521 */  bl       UNDEF_80022390;
/* 809BFE74 38030001 */  addi     r0, r3, 1;
/* 809BFE78 2C000001 */  cmpwi    r0, 1;
/* 809BFE7C 41820010 */  beq-     UNDEF_809bfe8c;
/* 809BFE80 801E0804 */  lwz      r0, 2052(r30);
/* 809BFE84 28000001 */  cmplwi   r0, 1;
/* 809BFE88 40820018 */  bne-     UNDEF_809bfea0;
UNDEF_809bfe8c:;
/* 809BFE8C 801E0004 */  lwz      r0, 4(r30);
/* 809BFE90 7FC3F378 */  mr       r3, r30;
/* 809BFE94          */  extrwi   r4, r0, 2, 1;
/* 809BFE98 4B662009 */  bl       UNDEF_80021ea0;
/* 809BFE9C 48000100 */  b        UNDEF_809bff9c;
UNDEF_809bfea0:;
/* 809BFEA0 801E0004 */  lwz      r0, 4(r30);
/* 809BFEA4 7FC3F378 */  mr       r3, r30;
/* 809BFEA8          */  extrwi   r4, r0, 2, 1;
/* 809BFEAC 4B6620A5 */  bl       UNDEF_80021f50;
/* 809BFEB0 480000EC */  b        UNDEF_809bff9c;
UNDEF_809bfeb4:;
/* 809BFEB4 4BFFFBDD */  bl       UNDEF_809bfa90;
/* 809BFEB8 3BE00001 */  li       r31, 1;
/* 809BFEBC 480000E0 */  b        UNDEF_809bff9c;
UNDEF_809bfec0:;
/* 809BFEC0 4BFFF9B1 */  bl       UNDEF_809bf870;
/* 809BFEC4 3BE00001 */  li       r31, 1;
/* 809BFEC8 480000D4 */  b        UNDEF_809bff9c;
UNDEF_809bfecc:;
/* 809BFECC 88A30824 */  lbz      r5, 2084(r3);
/* 809BFED0 38800000 */  li       r4, 0;
/* 809BFED4 4B661B4D */  bl       UNDEF_80021a20;
/* 809BFED8 3BE00001 */  li       r31, 1;
/* 809BFEDC 480000C0 */  b        UNDEF_809bff9c;
UNDEF_809bfee0:;
/* 809BFEE0 3BE00001 */  li       r31, 1;
/* 809BFEE4 480000B8 */  b        UNDEF_809bff9c;
UNDEF_809bfee8:;
/* 809BFEE8 C00300B4 */  lfs      f0, 180(r3);
/* 809BFEEC 3BE00001 */  li       r31, 1;
/* 809BFEF0 C02300B0 */  lfs      f1, 176(r3);
/* 809BFEF4 C04300AC */  lfs      f2, 172(r3);
/* 809BFEF8 D0410010 */  stfs     f2, 16(r1);
/* 809BFEFC D0210014 */  stfs     f1, 20(r1);
/* 809BFF00 D0010018 */  stfs     f0, 24(r1);
/* 809BFF04 8803081C */  lbz      r0, 2076(r3);
/* 809BFF08 2C000000 */  cmpwi    r0, 0;
/* 809BFF0C 40820010 */  bne-     UNDEF_809bff1c;
/* 809BFF10 88030824 */  lbz      r0, 2084(r3);
/* 809BFF14 28000002 */  cmplwi   r0, 2;
/* 809BFF18 4082005C */  bne-     UNDEF_809bff74;
UNDEF_809bff1c:;
/* 809BFF1C 3CA080AD */  lis      r5, UNDEF_80ace2b8@ha;
/* 809BFF20 3C608043 */  lis      r3, UNDEF_8042a020@ha;
/* 809BFF24 C005E2B8 */  lfs      f0, UNDEF_80ace2b8@l(r5);
/* 809BFF28 38810010 */  addi     r4, r1, 16;
/* 809BFF2C C0210014 */  lfs      f1, 20(r1);
/* 809BFF30 38A00005 */  li       r5, 5;
/* 809BFF34 8063A020 */  lwz      r3, UNDEF_8042a020@l(r3);
/* 809BFF38 38C00000 */  li       r6, 0;
/* 809BFF3C EC01002A */  fadds    f0, f1, f0;
/* 809BFF40 D0010014 */  stfs     f0, 20(r1);
/* 809BFF44 4B6A67FD */  bl       UNDEF_80066740;
/* 809BFF48 3C808043 */  lis      r4, UNDEF_8042a040@ha;
/* 809BFF4C 38610008 */  addi     r3, r1, 8;
/* 809BFF50 83A4A040 */  lwz      r29, UNDEF_8042a040@l(r4);
/* 809BFF54 389E00AC */  addi     r4, r30, 172;
/* 809BFF58 4B6AA559 */  bl       UNDEF_8006a4b0;
/* 809BFF5C 7FA3EB78 */  mr       r3, r29;
/* 809BFF60 38A10008 */  addi     r5, r1, 8;
/* 809BFF64 38800238 */  li       r4, 568;
/* 809BFF68 38C00000 */  li       r6, 0;
/* 809BFF6C 4B7D8E05 */  bl       UNDEF_80198d70;
/* 809BFF70 4800002C */  b        UNDEF_809bff9c;
UNDEF_809bff74:;
/* 809BFF74 3C8080AD */  lis      r4, UNDEF_80ace2b4@ha;
/* 809BFF78 3C608043 */  lis      r3, UNDEF_8042a020@ha;
/* 809BFF7C C004E2B4 */  lfs      f0, UNDEF_80ace2b4@l(r4);
/* 809BFF80 38810010 */  addi     r4, r1, 16;
/* 809BFF84 8063A020 */  lwz      r3, UNDEF_8042a020@l(r3);
/* 809BFF88 38A00005 */  li       r5, 5;
/* 809BFF8C EC010028 */  fsubs    f0, f1, f0;
/* 809BFF90 38C00000 */  li       r6, 0;
/* 809BFF94 D0010014 */  stfs     f0, 20(r1);
/* 809BFF98 4B6A6819 */  bl       UNDEF_800667b0;
UNDEF_809bff9c:;
/* 809BFF9C 2C1F0000 */  cmpwi    r31, 0;
/* 809BFFA0 40820010 */  bne-     UNDEF_809bffb0;
/* 809BFFA4 7FC3F378 */  mr       r3, r30;
/* 809BFFA8 38800001 */  li       r4, 1;
/* 809BFFAC 4BFFF5E5 */  bl       UNDEF_809bf590;
UNDEF_809bffb0:;
/* 809BFFB0 80010034 */  lwz      r0, 52(r1);
/* 809BFFB4 83E1002C */  lwz      r31, 44(r1);
/* 809BFFB8 83C10028 */  lwz      r30, 40(r1);
/* 809BFFBC 83A10024 */  lwz      r29, 36(r1);
/* 809BFFC0 7C0803A6 */  mtlr     r0;
/* 809BFFC4 38210030 */  addi     r1, r1, 48;
/* 809BFFC8 4E800020 */  blr;

.L_SwitchTable:;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bfee0;
                        .long     UNDEF_809bfe1c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bfee8;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bfecc;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bfe24;
                        .long     UNDEF_809bfec0;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bfe6c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bff9c;
                        .long     UNDEF_809bfeb4;
  // clang-format on
);
