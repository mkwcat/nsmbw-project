// d_a_en_dpakkun_base.cpp
// NSMBW .text: 0x8002CB70 - 0x8002EF50

#include "d_a_en_dpakkun_base.h"

#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"

[[nsmbw(0x8002D730)]]
int daEnDpakkunBase_c::hitCallback_YoshiHipAttk(dCc_c* main, dCc_c* other) ASM_METHOD(
  // clang-format off
/* 8002D730 9421FFE0 */  stwu     r1, -32(r1);
/* 8002D734 7C0802A6 */  mflr     r0;
/* 8002D738 90010024 */  stw      r0, 36(r1);
/* 8002D73C 93E1001C */  stw      r31, 28(r1);
/* 8002D740 93C10018 */  stw      r30, 24(r1);
/* 8002D744 93A10014 */  stw      r29, 20(r1);
/* 8002D748 7C7D1B78 */  mr       r29, r3;
/* 8002D74C 83C50004 */  lwz      r30, 4(r5);

/* 8002D754          */  mr       r4, r30;
                         bl       getCollTimer__5dEn_cCFP8dActor_c;
/* 8002D778          */  cmpwi    r3, 0;
/* 8002D77C 4182000C */  beq-     UNDEF_8002d788;
/* 8002D780 38600001 */  li       r3, 1;
/* 8002D784 48000098 */  b        UNDEF_8002d81c;
UNDEF_8002d788:;
                         mr       r3, r29;
/* 8002D78C          */  mr       r4, r30;
/* 8002D790          */  li       r5, 16;
                         bl       setCollTimer__5dEn_cFP8dActor_cUc;

/* 8002D7B4 C03E00AC */  lfs      f1, 172(r30);
/* 8002D7B8 C01D00AC */  lfs      f0, 172(r29);
/* 8002D7BC FC010040 */  fcmpo    cr0, f1, f0;
/* 8002D7C0 4081000C */  ble-     UNDEF_8002d7cc;
/* 8002D7C4 C04283A4 */  lfs      f2, UNDEF_8042b704@sda21;
/* 8002D7C8 48000008 */  b        UNDEF_8002d7d0;
UNDEF_8002d7cc:;
/* 8002D7CC C04283A8 */  lfs      f2, UNDEF_8042b708@sda21;
UNDEF_8002d7d0:;
/* 8002D7D0 819E0060 */  lwz      r12, 96(r30);
/* 8002D7D4 7FC3F378 */  mr       r3, r30;
/* 8002D7D8 38800001 */  li       r4, 1;
/* 8002D7DC C02283AC */  lfs      f1, UNDEF_8042b70c@sda21;
/* 8002D7E0 818C03FC */  lwz      r12, 1020(r12);
/* 8002D7E4 38A00000 */  li       r5, 0;
/* 8002D7E8 38C00000 */  li       r6, 0;
/* 8002D7EC 7D8903A6 */  mtctr    r12;
/* 8002D7F0 4E800421 */  bctrl;
/* 8002D7F4 83EDA6BC */  lwz      r31, UNDEF_8042a03c@sda21;
/* 8002D7F8 38610008 */  addi     r3, r1, 8;
/* 8002D7FC 389D00AC */  addi     r4, r29, 172;
/* 8002D800 4803CCB1 */  bl       UNDEF_8006a4b0;
/* 8002D804 7FE3FB78 */  mr       r3, r31;
/* 8002D808 38A10008 */  addi     r5, r1, 8;
/* 8002D80C 38800161 */  li       r4, 353;
/* 8002D810 38C00000 */  li       r6, 0;
/* 8002D814 4816A82D */  bl       UNDEF_80198040;
/* 8002D818 38600001 */  li       r3, 1;
UNDEF_8002d81c:;
/* 8002D81C 80010024 */  lwz      r0, 36(r1);
/* 8002D820 83E1001C */  lwz      r31, 28(r1);
/* 8002D824 83C10018 */  lwz      r30, 24(r1);
/* 8002D828 83A10014 */  lwz      r29, 20(r1);
/* 8002D82C 7C0803A6 */  mtlr     r0;
/* 8002D830 38210020 */  addi     r1, r1, 32;
/* 8002D834 4E800020 */  blr;
  // clang-format on
);

// Four patch: daEnDpakkunBase_c::hitCallback_Star
// Four patch: daEnDpakkunBase_c::hitCallback_Shell

[[nsmbw(0x8002DAB0)]]
bool daEnDpakkunBase_c::isPlayerDemo()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player != nullptr && player->isDemo()) {
            return true;
        }
    }

    return false;
}