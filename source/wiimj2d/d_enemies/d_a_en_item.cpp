// d_a_en_item.cpp
// NSMBW d_enemies.text: 0x80A26A80 - 0x80A2D610

#include "d_a_en_item.h"

#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_audio.h"
#include "d_system/d_enemy_manager.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_score_mng.h"
#include "framework/f_feature.h"
#include "sound/SndID.h"

[[nsmbw(0x80A26C30)]]
fBase_c::PACK_RESULT_e daEnItem_c::create() ASM_METHOD(
  // clang-format off
/* 80A26C30 9421FFB0 */  stwu     r1, -80(r1);
/* 80A26C34 7C0802A6 */  mflr     r0;
/* 80A26C38 90010054 */  stw      r0, 84(r1);
/* 80A26C3C 39610050 */  addi     r11, r1, 80;
/* 80A26C40 4B8B6409 */  bl       UNDEF_802dd048;
/* 80A26C44 3FE080AD */  lis      r31, UNDEF_80ad10c0@ha;
/* 80A26C48 7C7A1B78 */  mr       r26, r3;
/* 80A26C4C 3BFF10C0 */  addi     r31, r31, UNDEF_80ad10c0@l;
/* 80A26C50 83A30004 */  lwz      r29, 4(r3);
/* 80A26C54 3FC080B1 */  lis      r30, UNDEF_80b165c8@ha;
/* 80A26C58 7F44D378 */  mr       r4, r26;
/* 80A26C5C 3BDE65C8 */  addi     r30, r30, UNDEF_80b165c8@l;
/* 80A26C60 38BF0130 */  addi     r5, r31, 304;
/* 80A26C64 38C00003 */  li       r6, 3;
/* 80A26C68 38630148 */  addi     r3, r3, 328;
/* 80A26C6C 4B6657D5 */  bl       UNDEF_8008c440;
/* 80A26C70 881A038F */  lbz      r0, 911(r26);
/* 80A26C74 38800008 */  li       r4, 8;
/* 80A26C78 38600000 */  li       r3, 0;
/* 80A26C7C B09A0364 */  sth      r4, 868(r26);
/* 80A26C80 28000001 */  cmplwi   r0, 1;
/* 80A26C84 987A0DFB */  stb      r3, 3579(r26);
/* 80A26C88 40820010 */  bne-     UNDEF_80a26c98;
/* 80A26C8C C01F0160 */  lfs      f0, 352(r31);
/* 80A26C90 D01A00B4 */  stfs     f0, 180(r26);
/* 80A26C94 48000020 */  b        UNDEF_80a26cb4;
UNDEF_80a26c98:;
/* 80A26C98 57A0AFFF */  extrwi.  r0, r29, 1, 20;
/* 80A26C9C 41820010 */  beq-     UNDEF_80a26cac;
/* 80A26CA0 C01F0164 */  lfs      f0, 356(r31);
/* 80A26CA4 D01A00B4 */  stfs     f0, 180(r26);
/* 80A26CA8 4800000C */  b        UNDEF_80a26cb4;
UNDEF_80a26cac:;
/* 80A26CAC C01F0168 */  lfs      f0, 360(r31);
/* 80A26CB0 D01A00B4 */  stfs     f0, 180(r26);
UNDEF_80a26cb4:;
/* 80A26CB4 57B8467E */  extrwi   r24, r29, 7, 1;
/* 80A26CB8 C03F0174 */  lfs      f1, 372(r31);
/* 80A26CBC 387F00A8 */  addi     r3, r31, 168;
/* 80A26CC0 C01F0178 */  lfs      f0, 376(r31);
/* 80A26CC4 C05F0170 */  lfs      f2, 368(r31);
/* 80A26CC8 3818FFF5 */  subi     r0, r24, 11;
/* 80A26CCC C09F0094 */  lfs      f4, 148(r31);
/* 80A26CD0 3A800001 */  li       r20, 1;
/* 80A26CD4 38A00000 */  li       r5, 0;
/* 80A26CD8 C0FA00AC */  lfs      f7, 172(r26);
/* 80A26CDC C0DA00B0 */  lfs      f6, 176(r26);
/* 80A26CE0 57BBDFBE */  extrwi   r27, r29, 2, 25;
/* 80A26CE4 C0BA00B4 */  lfs      f5, 180(r26);
/* 80A26CE8 57B506FE */  clrlwi   r21, r29, 27;
/* 80A26CEC C07F016C */  lfs      f3, 364(r31);
/* 80A26CF0 57B60FFE */  srwi     r22, r29, 31;
/* 80A26CF4 C1430004 */  lfs      f10, 4(r3);
/* 80A26CF8 57B7BFFE */  extrwi   r23, r29, 1, 22;
/* 80A26CFC C17F00A8 */  lfs      f11, 168(r31);
/* 80A26D00          */  extrwi   r25, r29, 4, 12; // Player ID
/* 80A26D04 C103000C */  lfs      f8, 12(r3);
/* 80A26D08          */  extrwi   r12, r29, 2, 16; // Direction
/* 80A26D0C C1230008 */  lfs      f9, 8(r3);
/* 80A26D10 57ABA7FE */  extrwi   r11, r29, 1, 19;
/* 80A26D14          */  extrwi   r10, r29, 1, 23; // wait parameter
/* 80A26D18 57A99FFE */  extrwi   r9, r29, 1, 18;
/* 80A26D1C 57A867BE */  extrwi   r8, r29, 2, 10;
/* 80A26D20 57A757BE */  extrwi   r7, r29, 2, 8;
/* 80A26D24 38C00002 */  li       r6, 2;
/* 80A26D28 3880FFFF */  li       r4, -1;
/* 80A26D2C 38600064 */  li       r3, 100;
/* 80A26D30 57BCCFFE */  extrwi   r28, r29, 1, 24;
/* 80A26D34 28000001 */  cmplwi   r0, 1;
/* 80A26D38 D0FA0C00 */  stfs     f7, 3072(r26);
/* 80A26D3C 57BDB7FE */  extrwi   r29, r29, 1, 21;
/* 80A26D40 D0DA0C04 */  stfs     f6, 3076(r26);
/* 80A26D44 D0BA0C08 */  stfs     f5, 3080(r26);
/* 80A26D48 D09A00D0 */  stfs     f4, 208(r26);
/* 80A26D4C D07A00D4 */  stfs     f3, 212(r26);
/* 80A26D50 D09A00D8 */  stfs     f4, 216(r26);
/* 80A26D54 D05A00DC */  stfs     f2, 220(r26);
/* 80A26D58 D05A00E0 */  stfs     f2, 224(r26);
/* 80A26D5C D05A00E4 */  stfs     f2, 228(r26);
/* 80A26D60 D17A0320 */  stfs     f11, 800(r26);
/* 80A26D64 D15A0324 */  stfs     f10, 804(r26);
/* 80A26D68 D13A0318 */  stfs     f9, 792(r26);
/* 80A26D6C D11A031C */  stfs     f8, 796(r26);
/* 80A26D70 D0210008 */  stfs     f1, 8(r1);
/* 80A26D74 D021000C */  stfs     f1, 12(r1);
/* 80A26D78 D0010010 */  stfs     f0, 16(r1);
/* 80A26D7C D0010014 */  stfs     f0, 20(r1);
/* 80A26D80 D03A0338 */  stfs     f1, 824(r26);
/* 80A26D84 D03A033C */  stfs     f1, 828(r26);
/* 80A26D88 D01A0340 */  stfs     f0, 832(r26);
/* 80A26D8C D01A0344 */  stfs     f0, 836(r26);
/* 80A26D90 9A9A036D */  stb      r20, 877(r26);
/* 80A26D94 92BA0D8C */  stw      r21, 3468(r26);
/* 80A26D98 9ADA0348 */  stb      r22, 840(r26);
/* 80A26D9C 92FA0D9C */  stw      r23, 3484(r26);
/* 80A26DA0 931A0D94 */  stw      r24, 3476(r26);
/* 80A26DA4 933A0D90 */  stw      r25, 3472(r26);
/* 80A26DA8 919A0D98 */  stw      r12, 3480(r26);
/* 80A26DAC 917A0D68 */  stw      r11, 3432(r26);
/* 80A26DB0 915A0DA0 */  stw      r10, 3488(r26);
/* 80A26DB4 913A0DB0 */  stw      r9, 3504(r26);
/* 80A26DB8 911A0DA4 */  stw      r8, 3492(r26);
/* 80A26DBC 90FA0DA8 */  stw      r7, 3496(r26);
/* 80A26DC0 90DA0D78 */  stw      r6, 3448(r26);
/* 80A26DC4 B37A0DCE */  sth      r27, 3534(r26);
/* 80A26DC8 90BA0BEC */  stw      r5, 3052(r26);
/* 80A26DCC 989A0DFF */  stb      r4, 3583(r26);
/* 80A26DD0 9A9A0DF5 */  stb      r20, 3573(r26);
/* 80A26DD4 B07A0DC4 */  sth      r3, 3524(r26);
/* 80A26DD8 98BA0DF8 */  stb      r5, 3576(r26);
/* 80A26DDC 41810010 */  bgt-     UNDEF_80a26dec;
/* 80A26DE0 7F43D378 */  mr       r3, r26;
/* 80A26DE4 4800524D */  bl       UNDEF_80a2c030;
/* 80A26DE8 48000010 */  b        UNDEF_80a26df8;
UNDEF_80a26dec:;
/* 80A26DEC 7F43D378 */  mr       r3, r26;
/* 80A26DF0 7F84E378 */  mr       r4, r28;
/* 80A26DF4 480050ED */  bl       UNDEF_80a2bee0;
UNDEF_80a26df8:;
/* 80A26DF8 7F43D378 */  mr       r3, r26;
/* 80A26DFC 48005305 */  bl       UNDEF_80a2c100;
/* 80A26E00 A01A0DCA */  lhz      r0, 3530(r26);
/* 80A26E04 2800000E */  cmplwi   r0, 14;
/* 80A26E08 40820020 */  bne-     UNDEF_80a26e28;
/* 80A26E0C 7F44D378 */  mr       r4, r26;
/* 80A26E10 387A01EC */  addi     r3, r26, 492;
/* 80A26E14 38BF00E8 */  addi     r5, r31, 232;
/* 80A26E18 38DF0104 */  addi     r6, r31, 260;
/* 80A26E1C 38FF0120 */  addi     r7, r31, 288;
/* 80A26E20 4B646271 */  bl       UNDEF_8006d090;
/* 80A26E24 4800001C */  b        UNDEF_80a26e40;
UNDEF_80a26e28:;
/* 80A26E28 7F44D378 */  mr       r4, r26;
/* 80A26E2C 387A01EC */  addi     r3, r26, 492;
/* 80A26E30 38BF00D8 */  addi     r5, r31, 216;
/* 80A26E34 38DF0104 */  addi     r6, r31, 260;
/* 80A26E38 38FF0110 */  addi     r7, r31, 272;
/* 80A26E3C 4B646255 */  bl       UNDEF_8006d090;
UNDEF_80a26e40:;
/* 80A26E40 A09A0DCA */  lhz      r4, 3530(r26);
/* 80A26E44 C01A00AC */  lfs      f0, 172(r26);
/* 80A26E48 2804000D */  cmplwi   r4, 13;
/* 80A26E4C D01A0238 */  stfs     f0, 568(r26);
/* 80A26E50 40820044 */  bne-     UNDEF_80a26e94;
/* 80A26E54 C09F017C */  lfs      f4, 380(r31);
/* 80A26E58 C05F0180 */  lfs      f2, 384(r31);
/* 80A26E5C C07F0170 */  lfs      f3, 368(r31);
/* 80A26E60 C03F0094 */  lfs      f1, 148(r31);
/* 80A26E64 C01F0184 */  lfs      f0, 388(r31);
/* 80A26E68 D09A00DC */  stfs     f4, 220(r26);
/* 80A26E6C D09A00E0 */  stfs     f4, 224(r26);
/* 80A26E70 D09A00E4 */  stfs     f4, 228(r26);
/* 80A26E74 D07A00D0 */  stfs     f3, 208(r26);
/* 80A26E78 D05A00D4 */  stfs     f2, 212(r26);
/* 80A26E7C D03A00D8 */  stfs     f1, 216(r26);
/* 80A26E80 D07A0164 */  stfs     f3, 356(r26);
/* 80A26E84 D05A0168 */  stfs     f2, 360(r26);
/* 80A26E88 D01A016C */  stfs     f0, 364(r26);
/* 80A26E8C D05A0170 */  stfs     f2, 368(r26);
/* 80A26E90 4800009C */  b        UNDEF_80a26f2c;
UNDEF_80a26e94:;
/* 80A26E94 28040010 */  cmplwi   r4, 16;
/* 80A26E98 4082004C */  bne-     UNDEF_80a26ee4;
/* 80A26E9C C01F0188 */  lfs      f0, 392(r31);
/* 80A26EA0 7F43D378 */  mr       r3, r26;
/* 80A26EA4 D01A00DC */  stfs     f0, 220(r26);
/* 80A26EA8 D01A00E0 */  stfs     f0, 224(r26);
/* 80A26EAC D01A00E4 */  stfs     f0, 228(r26);
/* 80A26EB0 48000D01 */  bl       UNDEF_80a27bb0;
/* 80A26EB4 C03F018C */  lfs      f1, 396(r31);
/* 80A26EB8 7F43D378 */  mr       r3, r26;
/* 80A26EBC C01A00B0 */  lfs      f0, 176(r26);
/* 80A26EC0 389E0410 */  addi     r4, r30, 1040;
/* 80A26EC4 EC01002A */  fadds    f0, f1, f0;
/* 80A26EC8 D01A0D50 */  stfs     f0, 3408(r26);
/* 80A26ECC 819A0060 */  lwz      r12, 96(r26);
/* 80A26ED0 818C00D4 */  lwz      r12, 212(r12);
/* 80A26ED4 7D8903A6 */  mtctr    r12;
/* 80A26ED8 4E800421 */  bctrl;
/* 80A26EDC 38600001 */  li       r3, 1;
/* 80A26EE0 48000530 */  b        UNDEF_80a27410;
UNDEF_80a26ee4:;
/* 80A26EE4 28040003 */  cmplwi   r4, 3;
/* 80A26EE8 40820044 */  bne-     UNDEF_80a26f2c;
/* 80A26EEC 7F43D378 */  mr       r3, r26;
/* 80A26EF0 48000CC1 */  bl       UNDEF_80a27bb0;
/* 80A26EF4 C01A00B0 */  lfs      f0, 176(r26);
/* 80A26EF8 7F43D378 */  mr       r3, r26;
/* 80A26EFC C03F018C */  lfs      f1, 396(r31);
/* 80A26F00 389E0290 */  addi     r4, r30, 656;
/* 80A26F04 EC00082A */  fadds    f0, f0, f1;
/* 80A26F08 D01A00B0 */  stfs     f0, 176(r26);
/* 80A26F0C EC01002A */  fadds    f0, f1, f0;
/* 80A26F10 D01A0D50 */  stfs     f0, 3408(r26);
/* 80A26F14 819A0060 */  lwz      r12, 96(r26);
/* 80A26F18 818C00D4 */  lwz      r12, 212(r12);
/* 80A26F1C 7D8903A6 */  mtctr    r12;
/* 80A26F20 4E800421 */  bctrl;
/* 80A26F24 38600001 */  li       r3, 1;
/* 80A26F28 480004E8 */  b        UNDEF_80a27410;
UNDEF_80a26f2c:;
/* 80A26F2C A09A0DCA */  lhz      r4, 3530(r26);
/* 80A26F30 7F43D378 */  mr       r3, r26;
/* 80A26F34 48000C7D */  bl       UNDEF_80a27bb0;
/* 80A26F38 A01A0DCA */  lhz      r0, 3530(r26);
/* 80A26F3C 28000002 */  cmplwi   r0, 2;
/* 80A26F40 40820020 */  bne-     UNDEF_80a26f60;
/* 80A26F44 819A0E48 */  lwz      r12, 3656(r26);
/* 80A26F48 387A0E48 */  addi     r3, r26, 3656;
/* 80A26F4C 389A0E2C */  addi     r4, r26, 3628;
/* 80A26F50 38A00002 */  li       r5, 2;
/* 80A26F54 818C0008 */  lwz      r12, 8(r12);
/* 80A26F58 7D8903A6 */  mtctr    r12;
/* 80A26F5C 4E800421 */  bctrl;
UNDEF_80a26f60:;
/* 80A26F60 7F43D378 */  mr       r3, r26;
/* 80A26F64 4800516D */  bl       UNDEF_80a2c0d0;
/* 80A26F68 2C030000 */  cmpwi    r3, 0;
/* 80A26F6C 4182000C */  beq-     UNDEF_80a26f78;
/* 80A26F70 38000000 */  li       r0, 0;
/* 80A26F74 981A0DFC */  stb      r0, 3580(r26);
UNDEF_80a26f78:;
/* 80A26F78 801A0DA0 */  lwz      r0, 3488(r26);
/* 80A26F7C 2C000000 */  cmpwi    r0, 0;
/* 80A26F80 4182005C */  beq-     UNDEF_80a26fdc;
/* 80A26F84 C07F0170 */  lfs      f3, 368(r31);
/* 80A26F88 387A0148 */  addi     r3, r26, 328;
/* 80A26F8C C05F0190 */  lfs      f2, 400(r31);
/* 80A26F90 C03F0094 */  lfs      f1, 148(r31);
/* 80A26F94 C01F0194 */  lfs      f0, 404(r31);
/* 80A26F98 D07A00F4 */  stfs     f3, 244(r26);
/* 80A26F9C D05A00F8 */  stfs     f2, 248(r26);
/* 80A26FA0 D03A00FC */  stfs     f1, 252(r26);
/* 80A26FA4 D01A0114 */  stfs     f0, 276(r26);
/* 80A26FA8 4B665389 */  bl       UNDEF_8008c330;
/* 80A26FAC C03F0094 */  lfs      f1, 148(r31);
/* 80A26FB0 7F43D378 */  mr       r3, r26;
/* 80A26FB4 C01F0198 */  lfs      f0, 408(r31);
/* 80A26FB8 389E00D0 */  addi     r4, r30, 208;
/* 80A26FBC D03A00EC */  stfs     f1, 236(r26);
/* 80A26FC0 D01A00B4 */  stfs     f0, 180(r26);
/* 80A26FC4 819A0060 */  lwz      r12, 96(r26);
/* 80A26FC8 818C00D4 */  lwz      r12, 212(r12);
/* 80A26FCC 7D8903A6 */  mtctr    r12;
/* 80A26FD0 4E800421 */  bctrl;
/* 80A26FD4 38600001 */  li       r3, 1;
/* 80A26FD8 48000438 */  b        UNDEF_80a27410;
UNDEF_80a26fdc:;
/* 80A26FDC 2C1D0000 */  cmpwi    r29, 0;
/* 80A26FE0 4182002C */  beq-     UNDEF_80a2700c;
/* 80A26FE4 819A0060 */  lwz      r12, 96(r26);
/* 80A26FE8 7F43D378 */  mr       r3, r26;
/* 80A26FEC 389E0250 */  addi     r4, r30, 592;
/* 80A26FF0 818C00D4 */  lwz      r12, 212(r12);
/* 80A26FF4 7D8903A6 */  mtctr    r12;
/* 80A26FF8 4E800421 */  bctrl;
/* 80A26FFC C01F0198 */  lfs      f0, 408(r31);
/* 80A27000 38600001 */  li       r3, 1;
/* 80A27004 D01A00B4 */  stfs     f0, 180(r26);
/* 80A27008 48000408 */  b        UNDEF_80a27410;
UNDEF_80a2700c:;
/* 80A2700C 801A0DB0 */  lwz      r0, 3504(r26);
/* 80A27010 2C000000 */  cmpwi    r0, 0;
/* 80A27014 4182002C */  beq-     UNDEF_80a27040;
/* 80A27018 819A0060 */  lwz      r12, 96(r26);
/* 80A2701C 7F43D378 */  mr       r3, r26;
/* 80A27020 389E04D0 */  addi     r4, r30, 1232;
/* 80A27024 818C00D4 */  lwz      r12, 212(r12);
/* 80A27028 7D8903A6 */  mtctr    r12;
/* 80A2702C 4E800421 */  bctrl;
/* 80A27030 C01F019C */  lfs      f0, 412(r31);
/* 80A27034 38600001 */  li       r3, 1;
/* 80A27038 D01A00B4 */  stfs     f0, 180(r26);
/* 80A2703C 480003D4 */  b        UNDEF_80a27410;
UNDEF_80a27040:;
/* 80A27040 2C1C0000 */  cmpwi    r28, 0;
/* 80A27044 4182002C */  beq-     UNDEF_80a27070;
/* 80A27048 819A0060 */  lwz      r12, 96(r26);
/* 80A2704C 7F43D378 */  mr       r3, r26;
/* 80A27050 389E0090 */  addi     r4, r30, 144;
/* 80A27054 818C00D4 */  lwz      r12, 212(r12);
/* 80A27058 7D8903A6 */  mtctr    r12;
/* 80A2705C 4E800421 */  bctrl;
/* 80A27060 C01F0198 */  lfs      f0, 408(r31);
/* 80A27064 38600001 */  li       r3, 1;
/* 80A27068 D01A00B4 */  stfs     f0, 180(r26);
/* 80A2706C 480003A4 */  b        UNDEF_80a27410;
UNDEF_80a27070:;
/* 80A27070 801A0D94 */  lwz      r0, 3476(r26);
/* 80A27074 2800000F */  cmplwi   r0, 15;
/* 80A27078 418102B4 */  bgt-     UNDEF_80a2732c;
/* 80A2707C 3C6080AF */  lis      r3, UNDEF_80af0e14@ha;
/* 80A27080 5400103A */  slwi     r0, r0, 2;
/* 80A27084 38630E14 */  addi     r3, r3, UNDEF_80af0e14@l;
/* 80A27088 7C63002E */  lwzx     r3, r3, r0;
/* 80A2708C 7C6903A6 */  mtctr    r3;
/* 80A27090 4E800420 */  bctr;
/* 80A27094 7F43D378 */  mr       r3, r26;
/* 80A27098 389A00AC */  addi     r4, r26, 172;
/* 80A2709C 4B66F1A5 */  bl       UNDEF_80096240;
/* 80A270A0 68600001 */  xori     r0, r3, 1;
/* 80A270A4 981A0348 */  stb      r0, 840(r26);
/* 80A270A8 7F43D378 */  mr       r3, r26;
/* 80A270AC 389E0310 */  addi     r4, r30, 784;
/* 80A270B0 819A0060 */  lwz      r12, 96(r26);
/* 80A270B4 818C00D4 */  lwz      r12, 212(r12);
/* 80A270B8 7D8903A6 */  mtctr    r12;
/* 80A270BC 4E800421 */  bctrl;
/* 80A270C0 7F43D378 */  mr       r3, r26;
/* 80A270C4 48001ACD */  bl       UNDEF_80a28b90;
/* 80A270C8 38600001 */  li       r3, 1;
/* 80A270CC 48000344 */  b        UNDEF_80a27410;
/* 80A270D0 7F43D378 */  mr       r3, r26;
/* 80A270D4 480019DD */  bl       UNDEF_80a28ab0;
/* 80A270D8 7F43D378 */  mr       r3, r26;
/* 80A270DC 48001AB5 */  bl       UNDEF_80a28b90;
/* 80A270E0 881A0348 */  lbz      r0, 840(r26);
/* 80A270E4 389F0098 */  addi     r4, r31, 152;
/* 80A270E8 C01F0188 */  lfs      f0, 392(r31);
/* 80A270EC 38600001 */  li       r3, 1;
/* 80A270F0 5400103A */  slwi     r0, r0, 2;
/* 80A270F4 D01A00EC */  stfs     f0, 236(r26);
/* 80A270F8 7C04042E */  lfsx     f0, r4, r0;
/* 80A270FC D01A00E8 */  stfs     f0, 232(r26);
/* 80A27100 48000310 */  b        UNDEF_80a27410;
/* 80A27104 A01A0DCA */  lhz      r0, 3530(r26);
/* 80A27108 C01F0168 */  lfs      f0, 360(r31);
/* 80A2710C 2800000D */  cmplwi   r0, 13;
/* 80A27110 D01A00B4 */  stfs     f0, 180(r26);
/* 80A27114 40820014 */  bne-     UNDEF_80a27128;
/* 80A27118 C03A00B0 */  lfs      f1, 176(r26);
/* 80A2711C C01F01A0 */  lfs      f0, 416(r31);
/* 80A27120 EC01002A */  fadds    f0, f1, f0;
/* 80A27124 D01A00B0 */  stfs     f0, 176(r26);
UNDEF_80a27128:;
/* 80A27128 281B0003 */  cmplwi   r27, 3;
/* 80A2712C 4082000C */  bne-     UNDEF_80a27138;
/* 80A27130 38000001 */  li       r0, 1;
/* 80A27134 981A0DFB */  stb      r0, 3579(r26);
UNDEF_80a27138:;
/* 80A27138 819A0060 */  lwz      r12, 96(r26);
/* 80A2713C 7F43D378 */  mr       r3, r26;
/* 80A27140 389E02D0 */  addi     r4, r30, 720;
/* 80A27144 818C00D4 */  lwz      r12, 212(r12);
/* 80A27148 7D8903A6 */  mtctr    r12;
/* 80A2714C 4E800421 */  bctrl    ;
/* 80A27150 38600001 */  li       r3, 1;
/* 80A27154 480002BC */  b        UNDEF_80a27410;
/* 80A27158 7F43D378 */  mr       r3, r26;
/* 80A2715C 48001955 */  bl       UNDEF_80a28ab0;
/* 80A27160 801A0D9C */  lwz      r0, 3484(r26);
/* 80A27164 2C000000 */  cmpwi    r0, 0;
/* 80A27168 4182001C */  beq-     UNDEF_80a27184;
/* 80A2716C C01F0094 */  lfs      f0, 148(r31);
/* 80A27170 38000009 */  li       r0, 9;
/* 80A27174 D01A00EC */  stfs     f0, 236(r26);
/* 80A27178 D01A00E8 */  stfs     f0, 232(r26);
/* 80A2717C B01A0DCC */  sth      r0, 3532(r26);
/* 80A27180 48000020 */  b        UNDEF_80a271a0;
UNDEF_80a27184:;
/* 80A27184 881A0348 */  lbz      r0, 840(r26);
/* 80A27188 387F0098 */  addi     r3, r31, 152;
/* 80A2718C C01F01A0 */  lfs      f0, 416(r31);
/* 80A27190 5400103A */  slwi     r0, r0, 2;
/* 80A27194 D01A00EC */  stfs     f0, 236(r26);
/* 80A27198 7C03042E */  lfsx     f0, r3, r0;
/* 80A2719C D01A00E8 */  stfs     f0, 232(r26);
UNDEF_80a271a0:;
/* 80A271A0 38600001 */  li       r3, 1;
/* 80A271A4 4800026C */  b        UNDEF_80a27410;
/* 80A271A8 819A0060 */  lwz      r12, 96(r26);
/* 80A271AC 7F43D378 */  mr       r3, r26;
/* 80A271B0 389E01D0 */  addi     r4, r30, 464;
/* 80A271B4 818C00D4 */  lwz      r12, 212(r12);
/* 80A271B8 7D8903A6 */  mtctr    r12;
/* 80A271BC 4E800421 */  bctrl;
/* 80A271C0 38600001 */  li       r3, 1;
/* 80A271C4 4800024C */  b        UNDEF_80a27410;
/* 80A271C8 819A0060 */  lwz      r12, 96(r26);
/* 80A271CC 7F43D378 */  mr       r3, r26;
/* 80A271D0 389E0210 */  addi     r4, r30, 528;
/* 80A271D4 818C00D4 */  lwz      r12, 212(r12);
/* 80A271D8 7D8903A6 */  mtctr    r12;
/* 80A271DC 4E800421 */  bctrl;
/* 80A271E0 38600001 */  li       r3, 1;
/* 80A271E4 4800022C */  b        UNDEF_80a27410;
/* 80A271E8 819A0060 */  lwz      r12, 96(r26);
/* 80A271EC 7F43D378 */  mr       r3, r26;
/* 80A271F0 389E0210 */  addi     r4, r30, 528;
/* 80A271F4 818C00D4 */  lwz      r12, 212(r12);
/* 80A271F8 7D8903A6 */  mtctr    r12;
/* 80A271FC 4E800421 */  bctrl;
/* 80A27200 38600001 */  li       r3, 1;
/* 80A27204 4800020C */  b        UNDEF_80a27410;
/* 80A27208 A01A0DCA */  lhz      r0, 3530(r26);
/* 80A2720C C03F01A0 */  lfs      f1, 416(r31);
/* 80A27210 2800000B */  cmplwi   r0, 11;
/* 80A27214 40820010 */  bne-     UNDEF_80a27224;
/* 80A27218 C01F01A8 */  lfs      f0, 424(r31);
/* 80A2721C D01A00B4 */  stfs     f0, 180(r26);
/* 80A27220 C03F01A4 */  lfs      f1, 420(r31);
UNDEF_80a27224:;
/* 80A27224 801A0DA8 */  lwz      r0, 3496(r26);
/* 80A27228 2C000000 */  cmpwi    r0, 0;
/* 80A2722C 41820028 */  beq-     UNDEF_80a27254;
/* 80A27230 881A0348 */  lbz      r0, 840(r26);
/* 80A27234 387F0158 */  addi     r3, r31, 344;
/* 80A27238 C01F0094 */  lfs      f0, 148(r31);
/* 80A2723C 5400103A */  slwi     r0, r0, 2;
/* 80A27240 D03A00EC */  stfs     f1, 236(r26);
/* 80A27244 7C23042E */  lfsx     f1, r3, r0;
/* 80A27248 D03A00E8 */  stfs     f1, 232(r26);
/* 80A2724C D01A00F0 */  stfs     f0, 240(r26);
/* 80A27250 48000024 */  b        UNDEF_80a27274;
UNDEF_80a27254:;
/* 80A27254 881A0348 */  lbz      r0, 840(r26);
/* 80A27258 387F0098 */  addi     r3, r31, 152;
/* 80A2725C C01F0094 */  lfs      f0, 148(r31);
/* 80A27260 5400103A */  slwi     r0, r0, 2;
/* 80A27264 D03A00EC */  stfs     f1, 236(r26);
/* 80A27268 7C23042E */  lfsx     f1, r3, r0;
/* 80A2726C D03A00E8 */  stfs     f1, 232(r26);
/* 80A27270 D01A00F0 */  stfs     f0, 240(r26);
UNDEF_80a27274:;
/* 80A27274 819A0060 */  lwz      r12, 96(r26);
/* 80A27278 7F43D378 */  mr       r3, r26;
/* 80A2727C 389E0350 */  addi     r4, r30, 848;
/* 80A27280 818C00D4 */  lwz      r12, 212(r12);
/* 80A27284 7D8903A6 */  mtctr    r12;
/* 80A27288 4E800421 */  bctrl;
/* 80A2728C 38600001 */  li       r3, 1;
/* 80A27290 48000180 */  b        UNDEF_80a27410;
/* 80A27294 819A0060 */  lwz      r12, 96(r26);
/* 80A27298 7F43D378 */  mr       r3, r26;
/* 80A2729C 389E0390 */  addi     r4, r30, 912;
/* 80A272A0 818C00D4 */  lwz      r12, 212(r12);
/* 80A272A4 7D8903A6 */  mtctr    r12;
/* 80A272A8 4E800421 */  bctrl;
/* 80A272AC 38600001 */  li       r3, 1;
/* 80A272B0 48000160 */  b        UNDEF_80a27410;
/* 80A272B4 819A0060 */  lwz      r12, 96(r26);
/* 80A272B8 7F43D378 */  mr       r3, r26;
/* 80A272BC 389E03D0 */  addi     r4, r30, 976;
/* 80A272C0 818C00D4 */  lwz      r12, 212(r12);
/* 80A272C4 7D8903A6 */  mtctr    r12;
/* 80A272C8 4E800421 */  bctrl;
/* 80A272CC 38600001 */  li       r3, 1;
/* 80A272D0 48000140 */  b        UNDEF_80a27410;
/* 80A272D4 3C608043 */  lis      r3, UNDEF_8042a4a8@ha;
/* 80A272D8 3CA08043 */  lis      r5, UNDEF_8042a210@ha;
/* 80A272DC 8083A4A8 */  lwz      r4, UNDEF_8042a4a8@l(r3);
/* 80A272E0 8065A210 */  lwz      r3, UNDEF_8042a210@l(r5);
/* 80A272E4 8884120E */  lbz      r4, 4622(r4);
/* 80A272E8 C03A0C00 */  lfs      f1, 3072(r26);
/* 80A272EC C05A0C04 */  lfs      f2, 3076(r26);
/* 80A272F0 4B689CE1 */  bl       UNDEF_800b0fd0;
/* 80A272F4 5460043F */  clrlwi.  r0, r3, 16;
/* 80A272F8 4182000C */  beq-     UNDEF_80a27304;
/* 80A272FC 38600002 */  li       r3, 2;
/* 80A27300 48000110 */  b        UNDEF_80a27410;
UNDEF_80a27304:;
/* 80A27304 7F43D378 */  mr       r3, r26;
/* 80A27308 48001889 */  bl       UNDEF_80a28b90;
/* 80A2730C 819A0060 */  lwz      r12, 96(r26);
/* 80A27310 7F43D378 */  mr       r3, r26;
/* 80A27314 389E0490 */  addi     r4, r30, 1168;
/* 80A27318 818C00D4 */  lwz      r12, 212(r12);
/* 80A2731C 7D8903A6 */  mtctr    r12;
/* 80A27320 4E800421 */  bctrl;
/* 80A27324 38600001 */  li       r3, 1;
/* 80A27328 480000E8 */  b        UNDEF_80a27410;
UNDEF_80a2732c:;
/* 80A2732C 807A0D8C */  lwz      r3, 3468(r26);
/* 80A27330 4BF98101 */  bl       UNDEF_809bf430;
/* 80A27334 5460063F */  clrlwi.  r0, r3, 24;
/* 80A27338 41820014 */  beq-     UNDEF_80a2734c;
/* 80A2733C 801A0D98 */  lwz      r0, 3480(r26);
/* 80A27340 28000003 */  cmplwi   r0, 3;
/* 80A27344 40820008 */  bne-     UNDEF_80a2734c;
/* 80A27348 3B600003 */  li       r27, 3;
UNDEF_80a2734c:;
/* 80A2734C A07A0DCA */  lhz      r3, 3530(r26);
/* 80A27350 2803000B */  cmplwi   r3, 11;
/* 80A27354 40820038 */  bne-     UNDEF_80a2738c;
/* 80A27358 C01F01A8 */  lfs      f0, 424(r31);
/* 80A2735C 38000000 */  li       r0, 0;
/* 80A27360 D01A00B4 */  stfs     f0, 180(r26);
/* 80A27364 7F43D378 */  mr       r3, r26;
/* 80A27368 389E0190 */  addi     r4, r30, 400;
/* 80A2736C 937A0DAC */  stw      r27, 3500(r26);
/* 80A27370 901A0DC0 */  stw      r0, 3520(r26);
/* 80A27374 819A0060 */  lwz      r12, 96(r26);
/* 80A27378 818C00D4 */  lwz      r12, 212(r12);
/* 80A2737C 7D8903A6 */  mtctr    r12;
/* 80A27380 4E800421 */  bctrl;
/* 80A27384 38600001 */  li       r3, 1;
/* 80A27388 48000088 */  b        UNDEF_80a27410;
UNDEF_80a2738c:;
/* 80A2738C 281B0003 */  cmplwi   r27, 3;
/* 80A27390 40820054 */  bne-     UNDEF_80a273e4;
/* 80A27394 C05A00B0 */  lfs      f2, 176(r26);
/* 80A27398 38000001 */  li       r0, 1;
/* 80A2739C C03F018C */  lfs      f1, 396(r31);
/* 80A273A0 2803000D */  cmplwi   r3, 13;
/* 80A273A4 C01F01AC */  lfs      f0, 428(r31);
/* 80A273A8 EC220828 */  fsubs    f1, f2, f1;
/* 80A273AC D01A00EC */  stfs     f0, 236(r26);
/* 80A273B0 D03A0D50 */  stfs     f1, 3408(r26);
/* 80A273B4 981A0DFB */  stb      r0, 3579(r26);
/* 80A273B8 40820010 */  bne-     UNDEF_80a273c8;
/* 80A273BC C01F01B0 */  lfs      f0, 432(r31);
/* 80A273C0 EC020028 */  fsubs    f0, f2, f0;
/* 80A273C4 D01A0D50 */  stfs     f0, 3408(r26);
UNDEF_80a273c8:;
/* 80A273C8 819A0060 */  lwz      r12, 96(r26);
/* 80A273CC 7F43D378 */  mr       r3, r26;
/* 80A273D0 389E0050 */  addi     r4, r30, 80;
/* 80A273D4 818C00D4 */  lwz      r12, 212(r12);
/* 80A273D8 7D8903A6 */  mtctr    r12;
/* 80A273DC 4E800421 */  bctrl;
/* 80A273E0 4800002C */  b        UNDEF_80a2740c;
UNDEF_80a273e4:;
/* 80A273E4 C03F018C */  lfs      f1, 396(r31);
/* 80A273E8 7F43D378 */  mr       r3, r26;
/* 80A273EC C01A00B0 */  lfs      f0, 176(r26);
/* 80A273F0 389E0010 */  addi     r4, r30, 16;
/* 80A273F4 EC01002A */  fadds    f0, f1, f0;
/* 80A273F8 D01A0D50 */  stfs     f0, 3408(r26);
/* 80A273FC 819A0060 */  lwz      r12, 96(r26);
/* 80A27400 818C00D4 */  lwz      r12, 212(r12);
/* 80A27404 7D8903A6 */  mtctr    r12;
/* 80A27408 4E800421 */  bctrl;
UNDEF_80a2740c:;
/* 80A2740C 38600001 */  li       r3, 1;
UNDEF_80a27410:;
/* 80A27410 39610050 */  addi     r11, r1, 80;
/* 80A27414 4B8B5C81 */  bl       UNDEF_802dd094;
/* 80A27418 80010054 */  lwz      r0, 84(r1);
/* 80A2741C 7C0803A6 */  mtlr     r0;
/* 80A27420 38210050 */  addi     r1, r1, 80;
/* 80A27424 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80A28240)]]
void daEnItem_c::playGetItemEffect();

[[nsmbw(0x80A282F0)]]
bool daEnItem_c::collectItem()
{
    if (!mpCollectPlayer || mCollectPlayerNo == -1) {
        return false;
    }

    dAcPy_c* player = daPyMng_c::getPlayer(mCollectPlayerNo);

    if (player->isDemo()) {
        mpCollectPlayer = nullptr;
        mCollectPlayerNo = -1;
        return false;
    }

    ITEM_e item = static_cast<ITEM_e>(mItemType);

    if (item == ITEM_e::ONE_UP) {
        if (fFeat::deadly_1up) {
            player->set1UpKinokoEffect();
            player->setForcedDamage(this, daPlBase_c::DamageType_e::POISON_FOG);
        } else {
            playGetItemQuake();
            player->set1UpKinokoEffect();
            dScoreMng_c::m_instance->UNDEF_800E25A0(8, mCollectPlayerNo, 1);
        }
        playGetItemEffect();
        deleteRequest();
        return true;
    }

    if (player->isItemKinopio()) {
        mpCollectPlayer = nullptr;
        mCollectPlayerNo = -1;
        return false;
    }

    if (item == ITEM_e::STAR) {
        playGetItemQuake();
        player->setStar(daPlBase_c::StarSet_e(0), 660);
        dScoreMng_c::m_instance->UNDEF_800E25A0(4, mCollectPlayerNo, 1);
        dEnemyMng_c::m_instance->setNoGetItemTimer(mCollectPlayerNo);
        playGetItemEffect();
        deleteRequest();
        return true;
    }

    PLAYER_MODE_e mode = player->mNextMode;
    unsigned collect = 0, change = 6;
    switch (item) {
    case ITEM_e::MUSHROOM:
        if (mode != PLAYER_MODE_e::NONE && mode != PLAYER_MODE_e::MINI_MUSHROOM) {
            collect = 2;
            change = 0;
        } else if (player->switchMode(PLAYER_MODE_e::MUSHROOM)) {
            collect = 1;
        }
        break;

    case ITEM_e::FIRE_FLOWER:
        if (mode == PLAYER_MODE_e::FIRE_FLOWER) {
            collect = 2;
            change = 1;
        } else if (player->switchMode(PLAYER_MODE_e::FIRE_FLOWER)) {
            collect = 1;
        }
        break;

    case ITEM_e::PROPELLER_SHROOM:
        if (mode == PLAYER_MODE_e::PROPELLER_SHROOM) {
            collect = 2;
            change = 2;
        } else if (player->switchMode(PLAYER_MODE_e::PROPELLER_SHROOM)) {
            collect = 1;
        }
        break;

    case ITEM_e::PENGUIN_SUIT:
        if (mode == PLAYER_MODE_e::PENGUIN_SUIT) {
            collect = 2;
            change = 3;
        } else if (player->switchMode(PLAYER_MODE_e::PENGUIN_SUIT)) {
            collect = 1;
        }
        break;

    case ITEM_e::MINI_MUSHROOM:
        if (mode == PLAYER_MODE_e::MINI_MUSHROOM) {
            collect = 2;
            change = 4;
        } else if (player->switchMode(PLAYER_MODE_e::MINI_MUSHROOM)) {
            collect = 1;
        }
        break;

    case ITEM_e::ICE_FLOWER:
        if (mode == PLAYER_MODE_e::ICE_FLOWER) {
            collect = 2;
            change = 5;
        } else if (player->switchMode(PLAYER_MODE_e::ICE_FLOWER)) {
            collect = 1;
        }
        break;

    default:
        return false;
    }

    if (collect == 2 && change != 6) {
        playGetItemQuake();
        dAudio::g_pSndObjMap->startSound(
          SndID::SE_PLY_GET_ITEM_AGAIN, dAudio::cvtSndObjctPos(mPos), 0
        );
    } else if (collect == 1) {
        startGetItemShock();
        dEnemyMng_c::m_instance->setNoGetItemTimer(mCollectPlayerNo);
    }

    dScoreMng_c::m_instance->UNDEF_800E25A0(4, mCollectPlayerNo, 1);
    playGetItemEffect();
    deleteRequest();
    return true;
}

[[nsmbw(0x80A29070)]]
void daEnItem_c::playGetItemQuake();

[[nsmbw(0x80A290A0)]]
void daEnItem_c::startGetItemShock();
