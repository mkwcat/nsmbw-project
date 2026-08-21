// d_PreGame.cpp
// NSMBW d_en_boss.text: 0x80B6BCC0 - 0x80B6D1C0

// I'm not sure why this is in d_en_boss

#include "d_PreGame.h"

#include "d_static/d_a_player_manager.h"
#include "d_static/d_game_common.h"
#include "d_static/d_info.h"
#include "d_static/d_message.h"
#include "d_static/d_msgres.h"
#include <algorithm>

[[nsmbw(0x80B6BCC0)]]
void dPreGame_c::setPlayerRest() {
    for (std::size_t i = 0; i < LytPlayerCount; i++) {
        int           rest = daPyMng_c::mRest[static_cast<PLAYER_TYPE_e>(i)];

        LytTextBox_c *m0, *m1;
        if (i < 4) {
            m0 = mpTRemainder0[i];
            m1 = mpTRemainder1[i];
        } else {
            m0 = mpExtra->mpTRemainder0[i - 4];
            m1 = mpExtra->mpTRemainder1[i - 4];
        }

        if (m0) {
            dGameCom::LayoutDispNumber(rest, 2, m0, true);
        }
        if (m1) {
            dGameCom::LayoutDispNumber(rest, 2, m1, true);
        }
        if (i == 0) {
            dGameCom::LayoutDispNumber(rest, 2, mpTRemainderOld0, true);
            dGameCom::LayoutDispNumber(rest, 2, mpExtra->mpTRemainderOld1, true);
        }
    }
}

void dPreGame_c::createLayoutExtra() {
    LytTextBox_c* old         = reinterpret_cast<LytTextBox_c*>(mpExtra);
    mpExtra                   = new Extra_s{};
    mpExtra->mpTRemainderOld1 = old;

    mLayout.TPaneRegister(
        mpExtra->mpTRemainder0, //
        {
            "T_remainder_04",
            "T_remainder_06",
            "T_remainder_08",
            "T_remainder_15",
            "T_remainder_14",
            "T_remainder_05",
            "T_remainder_07",
            "T_remainder_09",
        }
    );

    mLayout.NPaneRegister(
        mpExtra->mpNPlayer, //
        {
            "N_kinopico_00",
            "N_player_05",
            "N_player_06",
            "N_player_07",
        }
    );
}

[[nsmbw(0x80B6C040)]]
void dPreGame_c::createLayout() ASM_METHOD(
  // clang-format off
/* 80B6C040 9421FFE0 */  stwu     r1, -32(r1);
/* 80B6C044 7C0802A6 */  mflr     r0;
/* 80B6C048 90010024 */  stw      r0, 36(r1);
/* 80B6C04C 39610020 */  addi     r11, r1, 32;
/* 80B6C050 4B771015 */  bl       UNDEF_802dd064;
/* 80B6C054 880302E0 */  lbz      r0, 736(r3);
/* 80B6C058 3FA080B9 */  lis      r29, UNDEF_80b88238@ha;
/* 80B6C05C 7C7C1B78 */  mr       r28, r3;
/* 80B6C060 2C000000 */  cmpwi    r0, 0;
/* 80B6C064 3BBD8238 */  addi     r29, r29, UNDEF_80b88238@l;
/* 80B6C068 4182000C */  beq-     UNDEF_80b6c074;
/* 80B6C06C 38600001 */  li       r3, 1;
/* 80B6C070 48000404 */  b        UNDEF_80b6c474;
UNDEF_80b6c074:;
/* 80B6C074 389D07F4 */  addi     r4, r29, 2036;
/* 80B6C078 38A00000 */  li       r5, 0;
/* 80B6C07C 4B55CC85 */  bl       UNDEF_800c8d00;
/* 80B6C080 2C030000 */  cmpwi    r3, 0;
/* 80B6C084 4082000C */  bne-     UNDEF_80b6c090;
/* 80B6C088 38600000 */  li       r3, 0;
/* 80B6C08C 480003E8 */  b        UNDEF_80b6c474;
UNDEF_80b6c090:;
/* 80B6C090 819C0008 */  lwz      r12, 8(r28);
/* 80B6C094 7F83E378 */  mr       r3, r28;
/* 80B6C098 389D0808 */  addi     r4, r29, 2056;
/* 80B6C09C 38A00000 */  li       r5, 0;
/* 80B6C0A0 818C0014 */  lwz      r12, 20(r12);
/* 80B6C0A4 7D8903A6 */  mtctr    r12;
/* 80B6C0A8 4E800421 */  bctrl;
/* 80B6C0AC 7F83E378 */  mr       r3, r28;
/* 80B6C0B0 389D0170 */  addi     r4, r29, 368;
/* 80B6C0B4 38A00008 */  li       r5, 8;
/* 80B6C0B8 4B55CFE9 */  bl       UNDEF_800c90a0;
/* 80B6C0BC 3CA080B7 */  lis      r5, UNDEF_80b75a58@ha;
/* 80B6C0C0 7F83E378 */  mr       r3, r28;
/* 80B6C0C4 389D0200 */  addi     r4, r29, 512;
/* 80B6C0C8 38C0000F */  li       r6, 15;
/* 80B6C0CC 38A55A58 */  addi     r5, r5, UNDEF_80b75a58@l;
/* 80B6C0D0 4B55D111 */  bl       UNDEF_800c91e0;
/* 80B6C0D4 7F83E378 */  mr       r3, r28;
/* 80B6C0D8 4B49B149 */  bl       UNDEF_80007220;
/* 80B6C0DC 907C0198 */  stw      r3, 408(r28);
/* 80B6C0E0 3CA080B7 */  lis      r5, UNDEF_80b75a98@ha;
/* 80B6C0E4 7F83E378 */  mr       r3, r28;
/* 80B6C0E8 389D0288 */  addi     r4, r29, 648;
/* 80B6C0EC 38A55A98 */  addi     r5, r5, UNDEF_80b75a98@l;
/* 80B6C0F0 38C000C8 */  li       r6, 200;
/* 80B6C0F4 38E00006 */  li       r7, 6;
/* 80B6C0F8 4B55CF19 */  bl       UNDEF_800c9010;
/* 80B6C0FC 7F83E378 */  mr       r3, r28;
/* 80B6C100 389D0420 */  addi     r4, r29, 1056;
/* 80B6C104 38BC019C */  addi     r5, r28, 412;
/* 80B6C108 38C0001C */  li       r6, 28;
/* 80B6C10C 4B55CE95 */  bl       UNDEF_800c8fa0;
/* 80B6C110 4B561C41 */  bl       UNDEF_800cdd50;
/* 80B6C114 7C7F1B78 */  mr       r31, r3;
/* 80B6C118 3BDC0034 */  addi     r30, r28, 52;
/* 80B6C11C 3B60000D */  li       r27, 13;
UNDEF_80b6c120:;
/* 80B6C120 807E019C */  lwz      r3, 412(r30);
/* 80B6C124 7FE4FB78 */  mr       r4, r31;
/* 80B6C128 38A00066 */  li       r5, 102;
/* 80B6C12C 38C0002A */  li       r6, 42;
/* 80B6C130 38E00000 */  li       r7, 0;
/* 80B6C134 4CC63182 */  crclr    6;
/* 80B6C138 4B55DA19 */  bl       UNDEF_800c9b50;
/* 80B6C13C 3B7B0001 */  addi     r27, r27, 1;
/* 80B6C140 3BDE0004 */  addi     r30, r30, 4;
/* 80B6C144 2C1B0016 */  cmpwi    r27, 22;
/* 80B6C148 4081FFD8 */  ble+     UNDEF_80b6c120;

                         mr       r3, r28;
                         bl       createLayoutExtra__10dPreGame_cFv;

/* 80B6C14C 7F83E378 */  mr       r3, r28;
/* 80B6C150 389D0618 */  addi     r4, r29, 1560;
/* 80B6C154 38BC020C */  addi     r5, r28, 524;
/* 80B6C158 38C00022 */  li       r6, 34;
/* 80B6C15C 4B55CDD5 */  bl       UNDEF_800c8f30;
/* 80B6C160 7F83E378 */  mr       r3, r28;
/* 80B6C164 389D07A8 */  addi     r4, r29, 1960;
/* 80B6C168 38BC0294 */  addi     r5, r28, 660;
/* 80B6C16C 38C00013 */  li       r6, 19;
/* 80B6C170 4B55CCE1 */  bl       UNDEF_800c8e50;
/* 80B6C174 7F83E378 */  mr       r3, r28;
/* 80B6C178 4BFFFB49 */  bl       UNDEF_80b6bcc0;
/* 80B6C17C 809C0198 */  lwz      r4, 408(r28);
/* 80B6C180 3C608031 */  lis      r3, UNDEF_80315e90@ha;
/* 80B6C184 38635E90 */  addi     r3, r3, UNDEF_80315e90@l;
/* 80B6C188 880400BB */  lbz      r0, 187(r4);
/* 80B6C18C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C190 60000001 */  ori      r0, r0, 1;
/* 80B6C194 980400BB */  stb      r0, 187(r4);
/* 80B6C198 80030008 */  lwz      r0, 8(r3);
/* 80B6C19C 2C000001 */  cmpwi    r0, 1;
/* 80B6C1A0 4082001C */  bne-     UNDEF_80b6c1bc;
/* 80B6C1A4 807C02DC */  lwz      r3, 732(r28);
/* 80B6C1A8 880300BB */  lbz      r0, 187(r3);
/* 80B6C1AC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C1B0 60000001 */  ori      r0, r0, 1;
/* 80B6C1B4 980300BB */  stb      r0, 187(r3);
/* 80B6C1B8 48000014 */  b        UNDEF_80b6c1cc;
UNDEF_80b6c1bc:;
/* 80B6C1BC 807C02DC */  lwz      r3, 732(r28);
/* 80B6C1C0 880300BB */  lbz      r0, 187(r3);
/* 80B6C1C4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C1C8 980300BB */  stb      r0, 187(r3);
UNDEF_80b6c1cc:;
/* 80B6C1CC 809C020C */  lwz      r4, 524(r28);
/* 80B6C1D0 3C608043 */  lis      r3, UNDEF_8042a25c@ha;
/* 80B6C1D4 83C3A25C */  lwz      r30, UNDEF_8042a25c@l(r3);
/* 80B6C1D8 880400BB */  lbz      r0, 187(r4);
/* 80B6C1DC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C1E0 980400BB */  stb      r0, 187(r4);
/* 80B6C1E4 807C0210 */  lwz      r3, 528(r28);
/* 80B6C1E8 880300BB */  lbz      r0, 187(r3);
/* 80B6C1EC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C1F0 980300BB */  stb      r0, 187(r3);
/* 80B6C1F4 807C0214 */  lwz      r3, 532(r28);
/* 80B6C1F8 880300BB */  lbz      r0, 187(r3);
/* 80B6C1FC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C200 980300BB */  stb      r0, 187(r3);
/* 80B6C204 807C0218 */  lwz      r3, 536(r28);
/* 80B6C208 880300BB */  lbz      r0, 187(r3);
/* 80B6C20C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C210 980300BB */  stb      r0, 187(r3);
/* 80B6C214 807C021C */  lwz      r3, 540(r28);
/* 80B6C218 880300BB */  lbz      r0, 187(r3);
/* 80B6C21C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C220 980300BB */  stb      r0, 187(r3);
/* 80B6C224 809C0220 */  lwz      r4, 544(r28);
/* 80B6C228 880400BB */  lbz      r0, 187(r4);
/* 80B6C22C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C230 980400BB */  stb      r0, 187(r4);
/* 80B6C234 807C0224 */  lwz      r3, 548(r28);
/* 80B6C238 880300BB */  lbz      r0, 187(r3);
/* 80B6C23C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C240 980300BB */  stb      r0, 187(r3);
/* 80B6C244 807C0228 */  lwz      r3, 552(r28);
/* 80B6C248 880300BB */  lbz      r0, 187(r3);
/* 80B6C24C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C250 980300BB */  stb      r0, 187(r3);
/* 80B6C254 807C022C */  lwz      r3, 556(r28);
/* 80B6C258 880300BB */  lbz      r0, 187(r3);
/* 80B6C25C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C260 980300BB */  stb      r0, 187(r3);
/* 80B6C264 807C0230 */  lwz      r3, 560(r28);
/* 80B6C268 880300BB */  lbz      r0, 187(r3);
/* 80B6C26C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C270 980300BB */  stb      r0, 187(r3);
/* 80B6C274 807C0234 */  lwz      r3, 564(r28);
/* 80B6C278 880300BB */  lbz      r0, 187(r3);
/* 80B6C27C 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C280 980300BB */  stb      r0, 187(r3);
/* 80B6C284 83BE03E8 */  lwz      r29, 1000(r30);
/* 80B6C288 2C1D000A */  cmpwi    r29, 10;
/* 80B6C28C 41800008 */  blt-     UNDEF_80b6c294;
/* 80B6C290 3BBDFFF6 */  subi     r29, r29, 10;
UNDEF_80b6c294:;
/* 80B6C294 807C019C */  lwz      r3, 412(r28);
/* 80B6C298 3FE08043 */  lis      r31, UNDEF_8042a260@ha;
/* 80B6C29C 880300BB */  lbz      r0, 187(r3);
/* 80B6C2A0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C2A4 60000001 */  ori      r0, r0, 1;
/* 80B6C2A8 980300BB */  stb      r0, 187(r3);
/* 80B6C2AC 807C01A0 */  lwz      r3, 416(r28);
/* 80B6C2B0 880300BB */  lbz      r0, 187(r3);
/* 80B6C2B4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C2B8 60000001 */  ori      r0, r0, 1;
/* 80B6C2BC 980300BB */  stb      r0, 187(r3);
/* 80B6C2C0 807C01A4 */  lwz      r3, 420(r28);
/* 80B6C2C4 880300BB */  lbz      r0, 187(r3);
/* 80B6C2C8 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C2CC 60000001 */  ori      r0, r0, 1;
/* 80B6C2D0 980300BB */  stb      r0, 187(r3);
/* 80B6C2D4 807C01A8 */  lwz      r3, 424(r28);
/* 80B6C2D8 880300BB */  lbz      r0, 187(r3);
/* 80B6C2DC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C2E0 60000001 */  ori      r0, r0, 1;
/* 80B6C2E4 980300BB */  stb      r0, 187(r3);
/* 80B6C2E8 807C01AC */  lwz      r3, 428(r28);
/* 80B6C2EC 880300BB */  lbz      r0, 187(r3);
/* 80B6C2F0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C2F4 60000001 */  ori      r0, r0, 1;
/* 80B6C2F8 980300BB */  stb      r0, 187(r3);
/* 80B6C2FC 801FA260 */  lwz      r0, UNDEF_8042a260@l(r31);
/* 80B6C300 54000673 */  rlwinm.  r0, r0, 0, 25, 25;
/* 80B6C304 418200E0 */  beq-     UNDEF_80b6c3e4;
/* 80B6C308 801E03E4 */  lwz      r0, 996(r30);
/* 80B6C30C 2C000000 */  cmpwi    r0, 0;
/* 80B6C310 408200D4 */  bne-     UNDEF_80b6c3e4;
/* 80B6C314 2C1D0005 */  cmpwi    r29, 5;
/* 80B6C318 408000CC */  bge-     UNDEF_80b6c3e4;
/* 80B6C31C 807C0290 */  lwz      r3, 656(r28);
/* 80B6C320 880300BB */  lbz      r0, 187(r3);
/* 80B6C324 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C328 60000001 */  ori      r0, r0, 1;
/* 80B6C32C 980300BB */  stb      r0, 187(r3);
/* 80B6C330 807C0200 */  lwz      r3, 512(r28);
/* 80B6C334 880300BB */  lbz      r0, 187(r3);
/* 80B6C338 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C33C 980300BB */  stb      r0, 187(r3);
/* 80B6C340 807C01A4 */  lwz      r3, 420(r28);
/* 80B6C344 880300BB */  lbz      r0, 187(r3);
/* 80B6C348 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C34C 980300BB */  stb      r0, 187(r3);
/* 80B6C350 807C01A8 */  lwz      r3, 424(r28);
/* 80B6C354 880300BB */  lbz      r0, 187(r3);
/* 80B6C358 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C35C 980300BB */  stb      r0, 187(r3);
/* 80B6C360 4B5619F1 */  bl       UNDEF_800cdd50;
/* 80B6C364 7C7B1B78 */  mr       r27, r3;
/* 80B6C368 807C01A0 */  lwz      r3, 416(r28);
/* 80B6C36C 7F64DB78 */  mr       r4, r27;
/* 80B6C370 38A00066 */  li       r5, 102;
/* 80B6C374 38C0001F */  li       r6, 31;
/* 80B6C378 38E00000 */  li       r7, 0;
/* 80B6C37C 4CC63182 */  crclr    6;
/* 80B6C380 4B55D7D1 */  bl       UNDEF_800c9b50;
/* 80B6C384 381D0001 */  addi     r0, r29, 1;
/* 80B6C388 901E03B8 */  stw      r0, 952(r30);
/* 80B6C38C 7F64DB78 */  mr       r4, r27;
/* 80B6C390 38A00066 */  li       r5, 102;
/* 80B6C394 807C01AC */  lwz      r3, 428(r28);
/* 80B6C398 38C00021 */  li       r6, 33;
/* 80B6C39C 38E00000 */  li       r7, 0;
/* 80B6C3A0 4CC63182 */  crclr    6;
/* 80B6C3A4 4B55D7AD */  bl       UNDEF_800c9b50;
/* 80B6C3A8 801FA260 */  lwz      r0, UNDEF_8042a260@l(r31);
/* 80B6C3AC 540006B5 */  rlwinm.  r0, r0, 0, 26, 26;
/* 80B6C3B0 4182001C */  beq-     UNDEF_80b6c3cc;
/* 80B6C3B4 807C0234 */  lwz      r3, 564(r28);
/* 80B6C3B8 880300BB */  lbz      r0, 187(r3);
/* 80B6C3BC 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C3C0 60000001 */  ori      r0, r0, 1;
/* 80B6C3C4 980300BB */  stb      r0, 187(r3);
/* 80B6C3C8 48000044 */  b        UNDEF_80b6c40c;
UNDEF_80b6c3cc:;
/* 80B6C3CC 807C0230 */  lwz      r3, 560(r28);
/* 80B6C3D0 880300BB */  lbz      r0, 187(r3);
/* 80B6C3D4 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C3D8 60000001 */  ori      r0, r0, 1;
/* 80B6C3DC 980300BB */  stb      r0, 187(r3);
/* 80B6C3E0 4800002C */  b        UNDEF_80b6c40c;
UNDEF_80b6c3e4:;
/* 80B6C3E4 809C0290 */  lwz      r4, 656(r28);
/* 80B6C3E8 7F83E378 */  mr       r3, r28;
/* 80B6C3EC 880400BB */  lbz      r0, 187(r4);
/* 80B6C3F0 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C3F4 980400BB */  stb      r0, 187(r4);
/* 80B6C3F8 809C0200 */  lwz      r4, 512(r28);
/* 80B6C3FC 880400BB */  lbz      r0, 187(r4);
/* 80B6C400 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 80B6C404 980400BB */  stb      r0, 187(r4);
/* 80B6C408 4BFFF9C9 */  bl       UNDEF_80b6bdd0;
UNDEF_80b6c40c:;
/* 80B6C40C 38800001 */  li       r4, 1;
/* 80B6C410 3BA00000 */  li       r29, 0;
/* 80B6C414 989C02E0 */  stb      r4, 736(r28);
/* 80B6C418 3C608043 */  lis      r3, UNDEF_8042a490@ha;
/* 80B6C41C 93BC02E4 */  stw      r29, 740(r28);
/* 80B6C420 8803A490 */  lbz      r0, UNDEF_8042a490@l(r3);
/* 80B6C424 2C000000 */  cmpwi    r0, 0;
/* 80B6C428 4182001C */  beq-     UNDEF_80b6c444;
/* 80B6C42C 3C608043 */  lis      r3, UNDEF_8042a5b8@ha;
/* 80B6C430 38800001 */  li       r4, 1;
/* 80B6C434 8063A5B8 */  lwz      r3, UNDEF_8042a5b8@l(r3);
/* 80B6C438 4B5A2169 */  bl       UNDEF_8010e5a0;
/* 80B6C43C 9BBC02E2 */  stb      r29, 738(r28);
/* 80B6C440 48000008 */  b        UNDEF_80b6c448;
UNDEF_80b6c444:;
/* 80B6C444 989C02E2 */  stb      r4, 738(r28);
UNDEF_80b6c448:;
/* 80B6C448 38000000 */  li       r0, 0;
/* 80B6C44C 981C02E3 */  stb      r0, 739(r28);
/* 80B6C450 7F83E378 */  mr       r3, r28;
/* 80B6C454 4B55D19D */  bl       UNDEF_800c95f0;
/* 80B6C458 7F83E378 */  mr       r3, r28;
/* 80B6C45C 3880000E */  li       r4, 14;
/* 80B6C460 38A00000 */  li       r5, 0;
/* 80B6C464 4B55CF7D */  bl       UNDEF_800c93e0;
/* 80B6C468 3800017C */  li       r0, 380;
/* 80B6C46C 901C0304 */  stw      r0, 772(r28);
/* 80B6C470 38600001 */  li       r3, 1;
UNDEF_80b6c474:;
/* 80B6C474 39610020 */  addi     r11, r1, 32;
/* 80B6C478 4B770C39 */  bl       UNDEF_802dd0b0;
/* 80B6C47C 80010024 */  lwz      r0, 36(r1);
/* 80B6C480 7C0803A6 */  mtlr     r0;
/* 80B6C484 38210020 */  addi     r1, r1, 32;
/* 80B6C488 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80B6C830)]]
void dPreGame_c::Phase0_Init() {
    nw4r::math::VEC3 pos[LytPlayerCount], battPos[4];
    unsigned         i;
    for (i = 0; i < 4; i++) {
        nw4r::lyt::Pane* pane = mpNPlayer[i];
        pos[i]                = pane->GetTranslate();
        pane->SetVisible(false);

        pane       = mpNBatteryArray[i];
        battPos[i] = pane->GetTranslate();
        pane->SetVisible(false);
    }
    for (; i < LytPlayerCount; i++) {
        nw4r::lyt::Pane* pane = mpExtra->mpNPlayer[i - 4];
        pos[i]                = pane->GetTranslate();
        pane->SetVisible(false);
    }

    if (dInfo_c::m_startGameInfo.demoType != dInfo_c::DemoType_e::SUPER_GUIDE) {
        std::size_t count = 0, battCount = 0;
        bool        middle = daPyMng_c::getEntryNum() <= 4;
        for (i = 0; i < PLAYER_COUNT; i++) {
            unsigned type = +daPyMng_c::mPlayerType[i];
            if (type >= LytPlayerCount) {
                continue;
            }

            if (count < LytPlayerCount && daPyMng_c::mPlayerEntry[i]) {
                nw4r::lyt::Pane* pane   = type < 4 ? mpNPlayer[type] : mpExtra->mpNPlayer[type - 4];
                auto             fixPos = pos[count++];
                if (middle) {
                    fixPos.x = 0;
                }
                pane->SetTranslate(fixPos);
                pane->SetVisible(true);
            }

            if (type < 4 && battCount < 4 && daPyMng_c::mPlayerEntry[type]) {
                nw4r::lyt::Pane* pane = mpNBatteryArray[type];
                pane->SetTranslate(battPos[battCount++]);
                pane->SetVisible(true);
            }
        }

        mNumPlayers = count;

        nw4r::math::VEC3 zankiPos =
            mpNZankiPos[std::max<int>(std::min<int>(count - 1, 3), 0)]->GetTranslate();
        mpNZanki->SetTranslate(zankiPos);

        f32 battPos =
            mpNBatteryPos[std::max<int>(std::min<int>(battCount - 1, 3), 0)]->GetTranslate().x;
        nw4r::math::VEC3 origBattPos = mpNBattery->GetTranslate();
        mpNBattery->SetTranslate({battPos, origBattPos.y, origBattPos.z});
    }

    mLayout.ReverseAnimeStartSetup(1, false);
    mLayout.ReverseAnimeStartSetup(3, false);
    for (i = 4; i < 8; i++) {
        mLayout.ReverseAnimeStartSetup(i, false);
    }
    mLayout.AnimeStartSetup(0, false);

    m0x2E1 = true;

    if (dInfo_c::m_startGameInfo.demoType == dInfo_c::DemoType_e::SUPER_GUIDE) {
        MsgRes_c* msgRes = dMessage_c::getMesRes();
        mpTOtasukePlay0->setMessage(msgRes, 102, 45, 0);
        mpTOtasukePlay1->setMessage(msgRes, 102, 45, 0);

        float          width = mpTOtasukePlay0->GetSize().width;
        nw4r::ut::Rect rect  = mpTOtasukePlay0->GetTextDrawRect();
        width -= rect.right - rect.left;
        float center = width / 2;

        auto  pos    = mpTOtasukePlay0->GetTranslate();
        pos.x += center;

        mpTOtasukePlay0->SetTranslate(pos);
        mpTOtasukePlay1->SetTranslate(pos);

        pos = mpPLuigiIcon[0]->GetTranslate();
        pos.x += center;

        mpPLuigiIcon[0]->SetTranslate(pos);
        mpPLuigiIcon[1]->SetTranslate(pos);

        mLayout.AnimeStartSetup(1, false);
        mSuperGuideDispDone = false;
        mPhase              = 1;
    } else {
        mPhase = 2;
    }

    for (std::size_t i = 0; i < 20; i++) {
        mpOtherPane[i]->SetVisible(false);
    }

    mLayout.AnimePlay();
    mLayout.calc();
}
