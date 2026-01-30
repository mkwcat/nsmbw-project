// d_enemy.cpp
// NSMBW .text: 0x80094E80 - 0x800983C0

#include "d_enemy.h"

[[nsmbw(0x80094E80)]]
dEn_c::dEn_c();

[[nsmbw(0x80095130)]]
dEn_c::~dEn_c();

[[nsmbw(0x800951D0)]]
void dEn_c::postCreate(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x80095240)]]
fBase_c::PACK_RESULT_e dEn_c::preExecute() ASM_METHOD(
  // clang-format off
/* 80095240 9421FFF0 */  stwu     r1, -16(r1);
/* 80095244 7C0802A6 */  mflr     r0;
/* 80095248 90010014 */  stw      r0, 20(r1);
/* 8009524C 93E1000C */  stw      r31, 12(r1);
/* 80095250 7C7F1B78 */  mr       r31, r3;
/* 80095254 4BFCF19D */  bl       UNDEF_800643f0;
/* 80095258 2C030000 */  cmpwi    r3, 0;
/* 8009525C 4082000C */  bne-     UNDEF_80095268;
/* 80095260 38600000 */  li       r3, 0;
/* 80095264 48000204 */  b        UNDEF_80095468;
UNDEF_80095268:;
/* 80095268 881F0390 */  lbz      r0, 912(r31);
/* 8009526C 2C000000 */  cmpwi    r0, 0;
/* 80095270 40820100 */  bne-     UNDEF_80095370;
/* 80095274 819F0394 */  lwz      r12, 916(r31);
/* 80095278 387F0394 */  addi     r3, r31, 916;
/* 8009527C 818C0028 */  lwz      r12, 40(r12);
/* 80095280 7D8903A6 */  mtctr    r12;
/* 80095284 4E800421 */  bctrl;
/* 80095288 81830000 */  lwz      r12, 0(r3);
/* 8009528C 3C808036 */  lis      r4, UNDEF_80358304@ha;
/* 80095290 38848304 */  addi     r4, r4, UNDEF_80358304@l;
/* 80095294 818C0014 */  lwz      r12, 20(r12);
/* 80095298 7D8903A6 */  mtctr    r12;
/* 8009529C 4E800421 */  bctrl;
/* 800952A0 7C0300D0 */  neg      r0, r3;
/* 800952A4 7C001B78 */  or       r0, r0, r3;
/* 800952A8 54000FFF */  srwi.    r0, r0, 31;
/* 800952AC 408200C4 */  bne-     UNDEF_80095370;
/* 800952B0 819F0060 */  lwz      r12, 96(r31);
/* 800952B4 7FE3FB78 */  mr       r3, r31;
/* 800952B8 818C0150 */  lwz      r12, 336(r12);
/* 800952BC 7D8903A6 */  mtctr    r12;
/* 800952C0 4E800421 */  bctrl;
/* 800952C4 2C030000 */  cmpwi    r3, 0;
/* 800952C8 418200A8 */  beq-     UNDEF_80095370;
/* 800952CC 806DA968 */  lwz      r3, UNDEF_8042a2e8@sda21;
/* 800952D0 80630030 */  lwz      r3, 48(r3);
/* 800952D4 546007BD */  rlwinm.  r0, r3, 0, 30, 30;
/* 800952D8 4182003C */  beq-     UNDEF_80095314;
/* 800952DC 819F0060 */  lwz      r12, 96(r31);
/* 800952E0 7FE3FB78 */  mr       r3, r31;
/* 800952E4 818C0218 */  lwz      r12, 536(r12);
/* 800952E8 7D8903A6 */  mtctr    r12;
/* 800952EC 4E800421 */  bctrl;
/* 800952F0 2C030000 */  cmpwi    r3, 0;
/* 800952F4 4182007C */  beq-     UNDEF_80095370;
/* 800952F8 819F0060 */  lwz      r12, 96(r31);
/* 800952FC 7FE3FB78 */  mr       r3, r31;
/* 80095300 38800000 */  li       r4, 0;
/* 80095304 818C0144 */  lwz      r12, 324(r12);
/* 80095308 7D8903A6 */  mtctr    r12;
/* 8009530C 4E800421 */  bctrl;
/* 80095310 48000060 */  b        UNDEF_80095370;
UNDEF_80095314:;
/* 80095314 5460077B */  rlwinm.  r0, r3, 0, 29, 29;
/* 80095318 4182003C */  beq-     UNDEF_80095354;
/* 8009531C 819F0060 */  lwz      r12, 96(r31);
/* 80095320 7FE3FB78 */  mr       r3, r31;
/* 80095324 818C0218 */  lwz      r12, 536(r12);
/* 80095328 7D8903A6 */  mtctr    r12;
/* 8009532C 4E800421 */  bctrl;
/* 80095330 2C030000 */  cmpwi    r3, 0;
/* 80095334 4182003C */  beq-     UNDEF_80095370;
/* 80095338 819F0060 */  lwz      r12, 96(r31);
/* 8009533C 7FE3FB78 */  mr       r3, r31;
/* 80095340 38800001 */  li       r4, 1;
/* 80095344 818C0144 */  lwz      r12, 324(r12);
/* 80095348 7D8903A6 */  mtctr    r12;
/* 8009534C 4E800421 */  bctrl;
/* 80095350 48000020 */  b        UNDEF_80095370;
UNDEF_80095354:;
/* 80095354 546007FF */  clrlwi.  r0, r3, 31;
/* 80095358 41820018 */  beq-     UNDEF_80095370;
/* 8009535C 819F0060 */  lwz      r12, 96(r31);
/* 80095360 7FE3FB78 */  mr       r3, r31;
/* 80095364 818C0214 */  lwz      r12, 532(r12);
/* 80095368 7D8903A6 */  mtctr    r12;
/* 8009536C 4E800421 */  bctrl;
UNDEF_80095370:;
/* 80095370 881F0432 */  lbz      r0, 1074(r31);
/* 80095374 2C000000 */  cmpwi    r0, 0;
/* 80095378 41820044 */  beq-     UNDEF_800953bc;
/* 8009537C 881F0390 */  lbz      r0, 912(r31);
/* 80095380 2C000000 */  cmpwi    r0, 0;
/* 80095384 4082002C */  bne-     UNDEF_800953b0;
/* 80095388 38000001 */  li       r0, 1;
/* 8009538C 981F0390 */  stb      r0, 912(r31);
/* 80095390 7FE3FB78 */  mr       r3, r31;
/* 80095394 48002A9D */  bl       UNDEF_80097e30;
/* 80095398 819F0060 */  lwz      r12, 96(r31);
/* 8009539C 7FE3FB78 */  mr       r3, r31;
/* 800953A0 809F0424 */  lwz      r4, 1060(r31);
/* 800953A4 818C00D4 */  lwz      r12, 212(r12);
/* 800953A8 7D8903A6 */  mtctr    r12;
/* 800953AC 4E800421 */  bctrl;
UNDEF_800953b0:;
/* 800953B0 38000000 */  li       r0, 0;
/* 800953B4 981F0432 */  stb      r0, 1074(r31);
/* 800953B8 48000090 */  b        UNDEF_80095448;
UNDEF_800953bc:;
/* 800953BC 887F050C */  lbz      r3, 1292(r31);
/* 800953C0 2C030000 */  cmpwi    r3, 0;
/* 800953C4 4182000C */  beq-     UNDEF_800953d0;
/* 800953C8 3803FFFF */  subi     r0, r3, 1;
/* 800953CC 981F050C */  stb      r0, 1292(r31);
UNDEF_800953d0:;
/* 800953D0 A07F0500 */  lhz      r3, 1280(r31);
/* 800953D4 2C030000 */  cmpwi    r3, 0;
/* 800953D8 4182000C */  beq-     UNDEF_800953e4;
/* 800953DC 3803FFFF */  subi     r0, r3, 1;
/* 800953E0 B01F0500 */  sth      r0, 1280(r31);
UNDEF_800953e4:;
/* 800953E4 A07F0502 */  lhz      r3, 1282(r31);
/* 800953E8 2C030000 */  cmpwi    r3, 0;
/* 800953EC 4182000C */  beq-     UNDEF_800953f8;
/* 800953F0 3803FFFF */  subi     r0, r3, 1;
/* 800953F4 B01F0502 */  sth      r0, 1282(r31);
UNDEF_800953f8:;

                         mr       r3, r31;
                         li       r4, -1;
                         li       r5, -1;
                         bl       incrementCollTimer__5dEn_cFii;

UNDEF_80095448:;
/* 80095448 819F0060 */  lwz      r12, 96(r31);
/* 8009544C 7FE3FB78 */  mr       r3, r31;
/* 80095450 818C0228 */  lwz      r12, 552(r12);
/* 80095454 7D8903A6 */  mtctr    r12;
/* 80095458 4E800421 */  bctrl;
/* 8009545C 881F000B */  lbz      r0, 11(r31);
/* 80095460 7C000034 */  cntlzw   r0, r0;
/* 80095464 5403D97E */  srwi     r3, r0, 5;
UNDEF_80095468:;
/* 80095468 80010014 */  lwz      r0, 20(r1);
/* 8009546C 83E1000C */  lwz      r31, 12(r1);
/* 80095470 7C0803A6 */  mtlr     r0;
/* 80095474 38210010 */  addi     r1, r1, 16;
/* 80095478 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80095480)]]
void dEn_c::postExecute(fBase_c::MAIN_STATE_e);

[[nsmbw(0x800954A0)]]
fBase_c::PACK_RESULT_e dEn_c::preDraw();

[[nsmbw(0x80095520)]]
void dEn_c::fumidamageEffect(const mVec3_c&);

[[nsmbw(0x80095530)]]
void dEn_c::hipatkEffect(const mVec3_c&);

[[nsmbw(0x80095580)]]
void dEn_c::fumidamageSE(const mVec3_c&, int);

[[nsmbw(0x800955D0)]]
void dEn_c::quakeAction();

[[nsmbw(0x80095890)]]
bool dEn_c::checkDispIn();

[[nsmbw(0x80095950)]]
void dEn_c::normal_collcheck(dCc_c* object, dCc_c* other) ASM_METHOD(
  // clang-format off
/* 80095950 9421FFE0 */  stwu     r1, -32(r1);
/* 80095954 7C0802A6 */  mflr     r0;
/* 80095958 90010024 */  stw      r0, 36(r1);
/* 8009595C 93E1001C */  stw      r31, 28(r1);
/* 80095960 93C10018 */  stw      r30, 24(r1);
/* 80095964 7C9E2378 */  mr       r30, r4;
/* 80095968 93A10014 */  stw      r29, 20(r1);
/* 8009596C 7C7D1B78 */  mr       r29, r3;
/* 80095970 93810010 */  stw      r28, 16(r1);
/* 80095974 83E30004 */  lwz      r31, 4(r3); // dEn_c
/* 80095978 83840004 */  lwz      r28, 4(r4); // dAcPy_c
/* 8009597C 881F0432 */  lbz      r0, 1074(r31);
/* 80095980 2C000000 */  cmpwi    r0, 0;
/* 80095984 41820014 */  beq-     UNDEF_80095998;
/* 80095988 880300A1 */  lbz      r0, 161(r3);
/* 8009598C 60000002 */  ori      r0, r0, 2;
/* 80095990 980300A1 */  stb      r0, 161(r3);
/* 80095994 48000254 */  b        UNDEF_80095be8;
UNDEF_80095998:;
/* 80095998 881C038C */  lbz      r0, 908(r28);
/* 8009599C 28000003 */  cmplwi   r0, 3;
/* 800959A0 40820058 */  bne-     UNDEF_800959f8;
/* 800959A4 819F0060 */  lwz      r12, 96(r31);
/* 800959A8 7FE3FB78 */  mr       r3, r31;
/* 800959AC 7FA4EB78 */  mr       r4, r29;
/* 800959B0 7FC5F378 */  mr       r5, r30;
/* 800959B4 818C00E4 */  lwz      r12, 228(r12);
/* 800959B8 7D8903A6 */  mtctr    r12;
/* 800959BC 4E800421 */  bctrl;
/* 800959C0 2C030000 */  cmpwi    r3, 0;
/* 800959C4 41820014 */  beq-     UNDEF_800959d8;
/* 800959C8 881D00A1 */  lbz      r0, 161(r29);
/* 800959CC 60000002 */  ori      r0, r0, 2;
/* 800959D0 981D00A1 */  stb      r0, 161(r29);
/* 800959D4 48000214 */  b        UNDEF_80095be8;
UNDEF_800959d8:;
/* 800959D8 819F0060 */  lwz      r12, 96(r31);
/* 800959DC 7FE3FB78 */  mr       r3, r31;
/* 800959E0 7FA4EB78 */  mr       r4, r29;
/* 800959E4 7FC5F378 */  mr       r5, r30;
/* 800959E8 818C00F4 */  lwz      r12, 244(r12);
/* 800959EC 7D8903A6 */  mtctr    r12;
/* 800959F0 4E800421 */  bctrl;
/* 800959F4 480001F4 */  b        UNDEF_80095be8;
UNDEF_800959f8:;
/* 800959F8 28000001 */  cmplwi   r0, 1;
/* 800959FC 408200C8 */  bne-     UNDEF_80095ac4;
/* 80095A00 801F04FC */  lwz      r0, 1276(r31);
/* 80095A04 540001CF */  rlwinm.  r0, r0, 0, 7, 7;
/* 80095A08 40820014 */  bne-     UNDEF_80095a1c;
/* 80095A0C C03F00B0 */  lfs      f1, 176(r31);
/* 80095A10 480008F1 */  bl       UNDEF_80096300;
/* 80095A14 2C030000 */  cmpwi    r3, 0;
/* 80095A18 408201D0 */  bne-     UNDEF_80095be8;
UNDEF_80095a1c:;
/* 80095A1C 819F0060 */  lwz      r12, 96(r31);
/* 80095A20 7FE3FB78 */  mr       r3, r31;
/* 80095A24 7FA4EB78 */  mr       r4, r29;
/* 80095A28 7FC5F378 */  mr       r5, r30;
/* 80095A2C 818C00E8 */  lwz      r12, 232(r12);
/* 80095A30 7D8903A6 */  mtctr    r12;
/* 80095A34 4E800421 */  bctrl;
/* 80095A38 2C030000 */  cmpwi    r3, 0;
/* 80095A3C 4182001C */  beq-     UNDEF_80095a58;
/* 80095A40 801D0018 */  lwz      r0, 24(r29);
/* 80095A44 901F0434 */  stw      r0, 1076(r31);
/* 80095A48 881D00A1 */  lbz      r0, 161(r29);
/* 80095A4C 60000002 */  ori      r0, r0, 2;
/* 80095A50 981D00A1 */  stb      r0, 161(r29);
/* 80095A54 48000194 */  b        UNDEF_80095be8;
UNDEF_80095a58:;
/* 80095A58 881E002C */  lbz      r0, 44(r30);
/* 80095A5C 28000001 */  cmplwi   r0, 1;
/* 80095A60 41820188 */  beq-     UNDEF_80095be8;

                         // Damage cooldown
                         mr       r3, r31;
                         mr       r4, r28;
                         bl       getCollTimer__5dEn_cCFP8dActor_c;

/* 80095A94          */  cmpwi    r3, 0;
/* 80095A98 40820150 */  bne-     UNDEF_80095be8;

                         mr       r3, r31;
                         mr       r4, r28;
                         li       r5, 5;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 80095AA4 7FE3FB78 */  mr       r3, r31;
/* 80095AA8 7FA4EB78 */  mr       r4, r29;
/* 80095AAC 819F0060 */  lwz      r12, 96(r31);
/* 80095AB0 7FC5F378 */  mr       r5, r30;
/* 80095AB4 818C00F8 */  lwz      r12, 248(r12);
/* 80095AB8 7D8903A6 */  mtctr    r12;
/* 80095ABC 4E800421 */  bctrl;
/* 80095AC0 48000128 */  b        UNDEF_80095be8;
UNDEF_80095ac4:;
/* 80095AC4 28000002 */  cmplwi   r0, 2;
/* 80095AC8 408200E8 */  bne-     UNDEF_80095bb0;
/* 80095ACC 819C0060 */  lwz      r12, 96(r28);
/* 80095AD0 7F83E378 */  mr       r3, r28;
/* 80095AD4 818C006C */  lwz      r12, 108(r12);
/* 80095AD8 7D8903A6 */  mtctr    r12;
/* 80095ADC 4E800421 */  bctrl;
/* 80095AE0 88030000 */  lbz      r0, 0(r3);
/* 80095AE4 7C7C1B78 */  mr       r28, r3;
/* 80095AE8          */  cmplwi   r0, PLAYER_COUNT - 1;
/* 80095AEC 418100FC */  bgt-     UNDEF_80095be8;
/* 80095AF0 881E002D */  lbz      r0, 45(r30);
/* 80095AF4 2800000F */  cmplwi   r0, 15;
/* 80095AF8 40820024 */  bne-     UNDEF_80095b1c;
/* 80095AFC 819F0060 */  lwz      r12, 96(r31);
/* 80095B00 7FE3FB78 */  mr       r3, r31;
/* 80095B04 7FA4EB78 */  mr       r4, r29;
/* 80095B08 7FC5F378 */  mr       r5, r30;
/* 80095B0C 818C0154 */  lwz      r12, 340(r12);
/* 80095B10 7D8903A6 */  mtctr    r12;
/* 80095B14 4E800421 */  bctrl;
/* 80095B18 480000D0 */  b        UNDEF_80095be8;
UNDEF_80095b1c:;
/* 80095B1C C03F00B0 */  lfs      f1, 176(r31);
/* 80095B20 7FA3EB78 */  mr       r3, r29;
/* 80095B24 480007DD */  bl       UNDEF_80096300;
/* 80095B28 2C030000 */  cmpwi    r3, 0;
/* 80095B2C 408200BC */  bne-     UNDEF_80095be8;
/* 80095B30 819F0060 */  lwz      r12, 96(r31);
/* 80095B34 7FE3FB78 */  mr       r3, r31;
/* 80095B38 7FA4EB78 */  mr       r4, r29;
/* 80095B3C 7FC5F378 */  mr       r5, r30;
/* 80095B40 818C00EC */  lwz      r12, 236(r12);
/* 80095B44 7D8903A6 */  mtctr    r12;
/* 80095B48 4E800421 */  bctrl;
/* 80095B4C 2C030000 */  cmpwi    r3, 0;
/* 80095B50 4182001C */  beq-     UNDEF_80095b6c;
/* 80095B54 801D0018 */  lwz      r0, 24(r29);
/* 80095B58 901F0434 */  stw      r0, 1076(r31);
/* 80095B5C 881D00A1 */  lbz      r0, 161(r29);
/* 80095B60 60000002 */  ori      r0, r0, 2;
/* 80095B64 981D00A1 */  stb      r0, 161(r29);
/* 80095B68 48000080 */  b        UNDEF_80095be8;
UNDEF_80095b6c:;

/* 80095B6C          */  lbz      r4, 0(r28);
                         mr       r3, r31;
                         bl       getCollTimer__5dEn_cCFi;

/* 80095B80          */  cmpwi    r3, 0;
/* 80095B84 40820064 */  bne-     UNDEF_80095be8;

                         lbz      r4, 0(r28);
                         mr       r3, r31;
                         li       r5, 5;
                         bl       setCollTimer__5dEn_cFiUc;

/* 80095B90 7FE3FB78 */  mr       r3, r31;
/* 80095B94 7FA4EB78 */  mr       r4, r29;
/* 80095B98 819F0060 */  lwz      r12, 96(r31);
/* 80095B9C 7FC5F378 */  mr       r5, r30;
/* 80095BA0 818C00FC */  lwz      r12, 252(r12);
/* 80095BA4 7D8903A6 */  mtctr    r12;
/* 80095BA8 4E800421 */  bctrl;
/* 80095BAC 4800003C */  b        UNDEF_80095be8;
UNDEF_80095bb0:;
/* 80095BB0 819F0060 */  lwz      r12, 96(r31);
/* 80095BB4 7FE3FB78 */  mr       r3, r31;
/* 80095BB8 7FA4EB78 */  mr       r4, r29;
/* 80095BBC 7FC5F378 */  mr       r5, r30;
/* 80095BC0 818C00F0 */  lwz      r12, 240(r12);
/* 80095BC4 7D8903A6 */  mtctr    r12;
/* 80095BC8 4E800421 */  bctrl;
/* 80095BCC 2C030000 */  cmpwi    r3, 0;
/* 80095BD0 41820018 */  beq-     UNDEF_80095be8;
/* 80095BD4 801D0018 */  lwz      r0, 24(r29);
/* 80095BD8 901F0434 */  stw      r0, 1076(r31);
/* 80095BDC 881D00A1 */  lbz      r0, 161(r29);
/* 80095BE0 60000002 */  ori      r0, r0, 2;
/* 80095BE4 981D00A1 */  stb      r0, 161(r29);
UNDEF_80095be8:;
/* 80095BE8 80010024 */  lwz      r0, 36(r1);
/* 80095BEC 83E1001C */  lwz      r31, 28(r1);
/* 80095BF0 83C10018 */  lwz      r30, 24(r1);
/* 80095BF4 83A10014 */  lwz      r29, 20(r1);
/* 80095BF8 83810010 */  lwz      r28, 16(r1);
/* 80095BFC 7C0803A6 */  mtlr     r0;
/* 80095C00 38210020 */  addi     r1, r1, 32;
/* 80095C04 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80095C10)]]
void dEn_c::Normal_VsEnHitCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80095C20)]]
void dEn_c::Normal_VsPlHitCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80095C80)]]
void dEn_c::Normal_VsYoshiHitCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80095CE0)]]
bool dEn_c::EnDamageCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80095D30)]]
bool dEn_c::PlDamageCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80095F50)]]
bool dEn_c::YoshiDamageCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80096060)]]
bool dEn_c::EtcDamageCheck(dCc_c*, dCc_c*);

[[nsmbw(0x80096230)]]
void dEn_c::hitYoshiEat(dCc_c*, dCc_c*);

[[nsmbw(0x80096700)]]
void dEn_c::FumiScoreSet(dActor_c*);

[[nsmbw(0x80096710)]]
void dEn_c::FumiJumpSet(dActor_c*);

[[nsmbw(0x80096720)]]
void dEn_c::MameFumiJumpSet(dActor_c*);

[[nsmbw(0x80096760)]]
void dEn_c::YoshiFumiJumpSet(dActor_c*);

[[nsmbw(0x80096770)]]
void dEn_c::YoshiFumiScoreSet(dActor_c*);

[[nsmbw(0x800968E0)]]
bool dEn_c::checkComboClap(int);

[[nsmbw(0x80096910)]]
void dEn_c::fumiSE(dActor_c*);

[[nsmbw(0x80096A20)]]
void dEn_c::spinfumiSE(dActor_c*);

[[nsmbw(0x80096B30)]]
void dEn_c::yoshifumiSE(dActor_c*);

[[nsmbw(0x80096C40)]]
void dEn_c::mamefumiSE(dActor_c*);

[[nsmbw(0x80096D60)]]
void dEn_c::fumiEffect(dActor_c*);

[[nsmbw(0x80096DF0)]]
void dEn_c::spinfumiEffect(dActor_c*);

[[nsmbw(0x80096E40)]]
void dEn_c::yoshifumiEffect(dActor_c*);

[[nsmbw(0x80096E50)]]
void dEn_c::mamefumiEffect(dActor_c*);

[[nsmbw(0x800973F0)]]
void dEn_c::yoganSplashEffect(const mVec3_c&, f32);

[[nsmbw(0x800974F0)]]
void dEn_c::poisonSplashEffect(const mVec3_c&, f32);

[[nsmbw(0x80097770)]]
void dEn_c::setWaterSpeed();

[[nsmbw(0x80097B90)]]
void dEn_c::slipBound(dActor_c*) ASM_METHOD(
  // clang-format off
/* 80097B90 9421FFF0 */  stwu     r1, -16(r1);
/* 80097B94 7C0802A6 */  mflr     r0;
/* 80097B98 90010014 */  stw      r0, 20(r1);
/* 80097B9C 93E1000C */  stw      r31, 12(r1);
/* 80097BA0 7C9F2378 */  mr       r31, r4;
/* 80097BA4 93C10008 */  stw      r30, 8(r1);
/* 80097BA8 7C7E1B78 */  mr       r30, r3;
/* 80097BAC C02400AC */  lfs      f1, 172(r4);
/* 80097BB0 C00300AC */  lfs      f0, 172(r3);
/* 80097BB4 FC010040 */  fcmpo    cr0, f1, f0;
/* 80097BB8 4C411382 */  cror     2, 1, 2;
/* 80097BBC 7C000026 */  mfcr     r0;
/* 80097BC0 819F0060 */  lwz      r12, 96(r31);
/* 80097BC4 54001FFE */  extrwi   r0, r0, 1, 2;
/* 80097BC8 38C29198 */  la       r6, UNDEF_8042c4f8@sda21;
/* 80097BCC 7C000034 */  cntlzw   r0, r0;
/* 80097BD0 818C03FC */  lwz      r12, 1020(r12);
/* 80097BD4 5400EDBA */  rlwinm   r0, r0, 29, 22, 29;
/* 80097BD8 7FE3FB78 */  mr       r3, r31;
/* 80097BDC 7C46042E */  lfsx     f2, r6, r0;
/* 80097BE0 38800001 */  li       r4, 1;
/* 80097BE4 C02291A0 */  lfs      f1, UNDEF_8042c500@sda21;
/* 80097BE8 38A00000 */  li       r5, 0;
/* 80097BEC 38C00000 */  li       r6, 0;
/* 80097BF0 7D8903A6 */  mtctr    r12;
/* 80097BF4 4E800421 */  bctrl;

                         // Damage cooldown
                         mr       r3, r30;
                         mr       r4, r31;
                         li       r5, 3;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 80097C24 83E1000C */  lwz      r31, 12(r1);
/* 80097C28 83C10008 */  lwz      r30, 8(r1);
/* 80097C2C 80010014 */  lwz      r0, 20(r1);
/* 80097C30 7C0803A6 */  mtlr     r0;
/* 80097C34 38210010 */  addi     r1, r1, 16;
/* 80097C38 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80097C40)]]
void dEn_c::setEatTongue(dActor_c*);

[[nsmbw(0x80097CB0)]]
void dEn_c::setEatTongueOff(dActor_c*);

/* VT+0x8C */
[[nsmbw(0x80097D30)]]
bool dEn_c::setEatSpitOut(dActor_c* actor)
{
    calcSpitOutPos(actor);
    setCollTimer(actor, 16);

    mDirection = actor->mDirection;

    reviveCc();
    setAfterEatScale();

    changeState(StateID_EatOut);

    return true;
}

[[nsmbw(0x80097DF0)]]
void dEn_c::calcEatInScale(dActor_c*);

[[nsmbw(0x80097F20)]]
void dEn_c::setDamage(dActor_c*);

[[nsmbw(0x80097F60)]]
void dEn_c::boyonBegin();

[[nsmbw(0x80097F70)]]
void dEn_c::block_hit_init();

u8 dEn_c::setCollTimer(int player, u8 timer)
{
    if (player < 0 || player >= PLAYER_COUNT) {
        return 0xFF;
    }

    return mCollTimer[player] = timer;
}

u8 dEn_c::setCollTimer(dActor_c* player, u8 timer)
{
    return setCollTimer(*player->getPlrNo(), timer);
}

u8 dEn_c::getCollTimer(int player) const
{
    if (player < 0 || player >= PLAYER_COUNT) {
        return 0xFF;
    }

    return mCollTimer[player];
}

u8 dEn_c::getCollTimer(dActor_c* player) const
{
    return getCollTimer(*player->getPlrNo());
}

u8 dEn_c::incrementCollTimer(int player, int increment)
{
    if (player == -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            // Check overflow
            if (increment > 0 && u8(mCollTimer[i] + increment) < mCollTimer[i]) {
                mCollTimer[i] = 0xFF;
                continue;
            } else if (increment < 0 && u8(mCollTimer[i] + increment) > mCollTimer[i]) {
                mCollTimer[i] = 0;
                continue;
            }

            mCollTimer[i] += increment;
        }
        return 0;
    }

    if (player < 0 || player >= PLAYER_COUNT) {
        return 0xFF;
    }

    // Check overflow
    if (increment > 0 && u8(mCollTimer[player] + increment) < mCollTimer[player]) {
        return mCollTimer[player] = 0xFF;
    } else if (increment < 0 && u8(mCollTimer[player] + increment) > mCollTimer[player]) {
        return mCollTimer[player] = 0;
    }

    return mCollTimer[player] += increment;
}