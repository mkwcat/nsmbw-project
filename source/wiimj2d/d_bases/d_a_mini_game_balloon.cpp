// d_a_mini_game_balloon.cpp
// NSMBW: 0x808638C0 - 0x80864A80

#include "d_a_mini_game_balloon.h"
#include "d_bases/d_a_mini_game_gun_battery_mgr.h"
#include "machine/m_ef.h"
#include "machine/m_vec.h"

[[address(0x80864170)]]
bool daMiniGameBalloon_c::hitCallback_Cannon(dCc_c* self, dCc_c* other) ASM_METHOD(
  // clang-format off
/* 80864170 9421FFA0 */  stwu     r1, -96(r1);
/* 80864174 7C0802A6 */  mflr     r0;
/* 80864178 90010064 */  stw      r0, 100(r1);
/* 8086417C 39610060 */  addi     r11, r1, 96;
/* 80864180 4BA78EE5 */  bl       UNDEF_802dd064;
/* 80864184 83C50004 */  lwz      r30, 4(r5);
/* 80864188 3FE08097 */  lis      r31, UNDEF_8096f220@ha;
/* 8086418C 3C808043 */  lis      r4, UNDEF_8042a330@ha;
/* 80864190 7C7D1B78 */  mr       r29, r3;
/* 80864194 819E0060 */  lwz      r12, 96(r30);
/* 80864198 7FC3F378 */  mr       r3, r30;
/* 8086419C 8384A330 */  lwz      r28, UNDEF_8042a330@l(r4);
/* 808641A0 3BFFF220 */  addi     r31, r31, UNDEF_8096f220@l;
/* 808641A4 818C006C */  lwz      r12, 108(r12);
/* 808641A8 7D8903A6 */  mtctr    r12;
/* 808641AC 4E800421 */  bctrl;
/* 808641B0 88030000 */  lbz      r0, 0(r3);
/* 808641B4 7F83E378 */  mr       r3, r28;
/* 808641B8 80BD0720 */  lwz      r5, 1824(r29);
/* 808641BC 389D00AC */  addi     r4, r29, 172;
/* 808641C0 7C060774 */  extsb    r6, r0;
/* 808641C4 38A5FFFF */  subi     r5, r5, 1;
/* 808641C8 4B87E339 */  bl       UNDEF_800e2500;
/* 808641CC 3C60809A */  lis      r3, UNDEF_8099cc60@ha;
/* 808641D0 8363CC60 */  lwz      r27, UNDEF_8099cc60@l(r3);
/* 808641D4 2C1B0000 */  cmpwi    r27, 0;
/* 808641D8 4182002C */  beq-     UNDEF_80864204;
/* 808641DC 819E0060 */  lwz      r12, 96(r30);
/* 808641E0 7FC3F378 */  mr       r3, r30;
/* 808641E4 818C006C */  lwz      r12, 108(r12);
/* 808641E8 7D8903A6 */  mtctr    r12;
/* 808641EC 4E800421 */  bctrl;
/* 808641F0 88030000 */  lbz      r0, 0(r3);
/* 808641F4 7F63DB78 */  mr       r3, r27;
/* 808641F8 80BD0720 */  lwz      r5, 1824(r29);
/* 808641FC 7C040774 */  extsb    r4, r0;
/* 80864200 48002331 */  bl       UNDEF_80866530;
UNDEF_80864204:;
/* 80864204 819E0060 */  lwz      r12, 96(r30);
/* 80864208 7FC3F378 */  mr       r3, r30;
/* 8086420C 818C006C */  lwz      r12, 108(r12);
/* 80864210 7D8903A6 */  mtctr    r12;
/* 80864214 4E800421 */  bctrl;
/* 80864218 88830000 */  lbz      r4, 0(r3);
/* 8086421C 3C60809A */  lis      r3, UNDEF_8099cc60@ha;
/* 80864220 80BD0720 */  lwz      r5, 1824(r29);
/* 80864224 7C840774 */  extsb    r4, r4;
/* 80864228 8003CC60 */  lwz      r0, UNDEF_8099cc60@l(r3);
/* 8086422C 1C64000C */  mulli    r3, r4, 12;
/* 80864230 2C050001 */  cmpwi    r5, 1;
/* 80864234 7C601A14 */  add      r3, r0, r3;
/* 80864238          */  lwz      r27, OFFSET_daMiniGameGunBatteryMgrObj_c_mPlayers(r3);
/* 8086423C 41820020 */  beq-     UNDEF_8086425c;
/* 80864240 2C050002 */  cmpwi    r5, 2;
/* 80864244 41820048 */  beq-     UNDEF_8086428c;
/* 80864248 2C050003 */  cmpwi    r5, 3;
/* 8086424C 41820070 */  beq-     UNDEF_808642bc;
/* 80864250 2C050004 */  cmpwi    r5, 4;
/* 80864254 41820098 */  beq-     UNDEF_808642ec;
/* 80864258 480000C0 */  b        UNDEF_80864318;
UNDEF_8086425c:;
/* 8086425C 3C808043 */  lis      r4, UNDEF_8042a040@ha;
/* 80864260 38610028 */  addi     r3, r1, 40;
/* 80864264 8384A040 */  lwz      r28, UNDEF_8042a040@l(r4);
/* 80864268 389D00AC */  addi     r4, r29, 172;
/* 8086426C 4B806245 */  bl       UNDEF_8006a4b0;
/* 80864270 7F83E378 */  mr       r3, r28;
/* 80864274 38A10028 */  addi     r5, r1, 40;
/* 80864278 7F660734 */  extsh    r6, r27;
/* 8086427C 388005F7 */  li       r4, 1527;
/* 80864280 38E00000 */  li       r7, 0;
/* 80864284 4B934E7D */  bl       UNDEF_80199100;
/* 80864288 48000090 */  b        UNDEF_80864318;
UNDEF_8086428c:;
/* 8086428C 3C808043 */  lis      r4, UNDEF_8042a040@ha;
/* 80864290 38610020 */  addi     r3, r1, 32;
/* 80864294 8384A040 */  lwz      r28, UNDEF_8042a040@l(r4);
/* 80864298 389D00AC */  addi     r4, r29, 172;
/* 8086429C 4B806215 */  bl       UNDEF_8006a4b0;
/* 808642A0 7F83E378 */  mr       r3, r28;
/* 808642A4 38A10020 */  addi     r5, r1, 32;
/* 808642A8 7F660734 */  extsh    r6, r27;
/* 808642AC 388005F8 */  li       r4, 1528;
/* 808642B0 38E00000 */  li       r7, 0;
/* 808642B4 4B934E4D */  bl       UNDEF_80199100;
/* 808642B8 48000060 */  b        UNDEF_80864318;
UNDEF_808642bc:;
/* 808642BC 3C808043 */  lis      r4, UNDEF_8042a040@ha;
/* 808642C0 38610018 */  addi     r3, r1, 24;
/* 808642C4 8384A040 */  lwz      r28, UNDEF_8042a040@l(r4);
/* 808642C8 389D00AC */  addi     r4, r29, 172;
/* 808642CC 4B8061E5 */  bl       UNDEF_8006a4b0;
/* 808642D0 7F83E378 */  mr       r3, r28;
/* 808642D4 38A10018 */  addi     r5, r1, 24;
/* 808642D8 7F660734 */  extsh    r6, r27;
/* 808642DC 388005F9 */  li       r4, 1529;
/* 808642E0 38E00000 */  li       r7, 0;
/* 808642E4 4B934E1D */  bl       UNDEF_80199100;
/* 808642E8 48000030 */  b        UNDEF_80864318;
UNDEF_808642ec:;
/* 808642EC 3C808043 */  lis      r4, UNDEF_8042a040@ha;
/* 808642F0 38610010 */  addi     r3, r1, 16;
/* 808642F4 8384A040 */  lwz      r28, UNDEF_8042a040@l(r4);
/* 808642F8 389D00AC */  addi     r4, r29, 172;
/* 808642FC 4B8061B5 */  bl       UNDEF_8006a4b0;
/* 80864300 7F83E378 */  mr       r3, r28;
/* 80864304 38A10010 */  addi     r5, r1, 16;
/* 80864308 7F660734 */  extsh    r6, r27;
/* 8086430C 388005FA */  li       r4, 1530;
/* 80864310 38E00000 */  li       r7, 0;
/* 80864314 4B934DED */  bl       UNDEF_80199100;
UNDEF_80864318:;
/* 80864318 3C608094 */  lis      r3, UNDEF_809398f8@ha;
/* 8086431C C05D00B0 */  lfs      f2, 176(r29);
/* 80864320 C03D00AC */  lfs      f1, 172(r29);
/* 80864324 3800FFFF */  li       r0, -1;
/* 80864328 C00398F8 */  lfs      f0, UNDEF_809398f8@l(r3);
/* 8086432C D0210030 */  stfs     f1, 48(r1);
/* 80864330 D0410034 */  stfs     f2, 52(r1);
/* 80864334 D0010038 */  stfs     f0, 56(r1);
/* 80864338 807D0524 */  lwz      r3, 1316(r29);
/* 8086433C 90010008 */  stw      r0, 8(r1);
/* 80864340 2C030000 */  cmpwi    r3, 0;
/* 80864344 41820020 */  beq-     UNDEF_80864364;
/* 80864348 2C030001 */  cmpwi    r3, 1;
/* 8086434C 41820034 */  beq-     UNDEF_80864380;
/* 80864350 2C030002 */  cmpwi    r3, 2;
/* 80864354 4182004C */  beq-     UNDEF_808643a0;
/* 80864358 2C030003 */  cmpwi    r3, 3;
/* 8086435C 41820064 */  beq-     UNDEF_808643c0;
/* 80864360 4800007C */  b        UNDEF_808643dc;
UNDEF_80864364:;
/* 80864364 386000FF */  li       r3, 255;
/* 80864368 38000000 */  li       r0, 0;
/* 8086436C 98610008 */  stb      r3, 8(r1);
/* 80864370 98610009 */  stb      r3, 9(r1);
/* 80864374 9801000A */  stb      r0, 10(r1);
/* 80864378 9861000B */  stb      r3, 11(r1);
/* 8086437C 48000060 */  b        UNDEF_808643dc;
UNDEF_80864380:;
/* 80864380 386000FF */  li       r3, 255;
/* 80864384 38800073 */  li       r4, 115;
/* 80864388 38000000 */  li       r0, 0;
/* 8086438C 98810008 */  stb      r4, 8(r1);
/* 80864390 98610009 */  stb      r3, 9(r1);
/* 80864394 9801000A */  stb      r0, 10(r1);
/* 80864398 9861000B */  stb      r3, 11(r1);
/* 8086439C 48000040 */  b        UNDEF_808643dc;
UNDEF_808643a0:;
/* 808643A0 380000FF */  li       r0, 255;
/* 808643A4 38800000 */  li       r4, 0;
/* 808643A8 386000CB */  li       r3, 203;
/* 808643AC 98810008 */  stb      r4, 8(r1);
/* 808643B0 98610009 */  stb      r3, 9(r1);
/* 808643B4 9801000A */  stb      r0, 10(r1);
/* 808643B8 9801000B */  stb      r0, 11(r1);
/* 808643BC 48000020 */  b        UNDEF_808643dc;
UNDEF_808643c0:;
/* 808643C0 380000FF */  li       r0, 255;
/* 808643C4 388000DC */  li       r4, 220;
/* 808643C8 38600000 */  li       r3, 0;
/* 808643CC 98810008 */  stb      r4, 8(r1);
/* 808643D0 98610009 */  stb      r3, 9(r1);
/* 808643D4 9801000A */  stb      r0, 10(r1);
/* 808643D8 9801000B */  stb      r0, 11(r1);
UNDEF_808643dc:;
/* 808643DC 819D0724 */  lwz      r12, 1828(r29);
/* 808643E0 387D0724 */  addi     r3, r29, 1828;
/* 808643E4 389F0050 */  addi     r4, r31, 80;
/* 808643E8 38C10030 */  addi     r6, r1, 48;
/* 808643EC 818C00A0 */  lwz      r12, 160(r12);
/* 808643F0 38A00000 */  li       r5, 0;
/* 808643F4 38E00000 */  li       r7, 0;
/* 808643F8 39000000 */  li       r8, 0;
/* 808643FC 7D8903A6 */  mtctr    r12;
/* 80864400 4E800421 */  bctrl;
/* 80864404 819D0724 */  lwz      r12, 1828(r29);
/* 80864408 387D0724 */  addi     r3, r29, 1828;
/* 8086440C 88810008 */  lbz      r4, 8(r1);
/* 80864410 39000003 */  li       r8, 3;
/* 80864414 818C0058 */  lwz      r12, 88(r12);
/* 80864418 88A10009 */  lbz      r5, 9(r1);
/* 8086441C 88C1000A */  lbz      r6, 10(r1);
/* 80864420 88E1000B */  lbz      r7, 11(r1);
/* 80864424 7D8903A6 */  mtctr    r12;
/* 80864428 4E800421 */  bctrl;
/* 8086442C 819D0724 */  lwz      r12, 1828(r29);
/* 80864430 387D0724 */  addi     r3, r29, 1828;
/* 80864434 818C0094 */  lwz      r12, 148(r12);
/* 80864438 7D8903A6 */  mtctr    r12;
/* 8086443C 4E800421 */  bctrl    ;
/* 80864440          */  lwz      r4, 5332(r30);

// REMOVED 80864444 - 8086449C
                         mr       r3, r29;
                         addi     r5, r1, 0x30;
                         bl       EffectBalloonGet__19daMiniGameBalloon_cFiP7mVec3_c;

/* 8086449C 7FA3EB78 */  mr       r3, r29;
/* 808644A0 4B8FE1B1 */  bl       UNDEF_80162650;
/* 808644A4 39610060 */  addi     r11, r1, 96;
/* 808644A8 38600001 */  li       r3, 1;
/* 808644AC 4BA78C05 */  bl       UNDEF_802dd0b0;
/* 808644B0 80010064 */  lwz      r0, 100(r1);
/* 808644B4 7C0803A6 */  mtlr     r0;
/* 808644B8 38210060 */  addi     r1, r1, 96;
/* 808644BC 4E800020 */  blr;
  // clang-format on
);

void daMiniGameBalloon_c::EffectBalloonGet(int playerType, mVec3_c *effPos) {
    const char *PLY_EFFECT_NAME[] = {
        "Wm_mg_balloonget_r",
        "Wm_mg_balloonget_g",
        "Wm_mg_balloonget_b",
        "Wm_mg_balloonget_y",
        // TODO: figure out how to handle these
        "Wm_mg_balloonget_r",
        "Wm_mg_balloonget_r",
        "Wm_mg_balloonget_r",
        "Wm_mg_balloonget_r",
    };

    const char *effName = PLY_EFFECT_NAME[playerType];
    mEf::createEffect(effName, 0, effPos, nullptr, nullptr);
}