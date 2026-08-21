// d_a_en_redcoin.cpp
// NSMBW d_enemies.text: 0x80A93990 - 0x80A94D90

#include "d_a_en_redcoin.h"

#include "d_player/d_a_player.h"
#include "d_static/d_a_player_manager.h"
#include "d_static/d_bg_parameter.h"
#include "d_profile/d_profile.h"

u32 daEnRedcoin_c_sizeof()
{
    return sizeof(daEnRedcoin_c);
}

[[nsmbw(0x80A93990)]]
daEnRedcoin_c* daEnRedcoin_c_classInit() ASM_METHOD(
  // clang-format off
/* 80A93990 9421FFF0 */  stwu     r1, -16(r1);
/* 80A93994 7C0802A6 */  mflr     r0;
/* 80A9399C 90010014 */  stw      r0, 20(r1);
/* 80A939A0 93E1000C */  stw      r31, 12(r1);
                         bl       daEnRedcoin_c_sizeof__Fv;
/* 80A939A4 4B6CF05D */  bl       UNDEF_80162a00;
/* 80A939A8 2C030000 */  cmpwi    r3, 0;
/* 80A939AC 7C7F1B78 */  mr       r31, r3;
/* 80A939B0 41820034 */  beq-     UNDEF_80a939e4;
/* 80A939B4 4B6014CD */  bl       UNDEF_80094e80;
/* 80A939B8 3C8080B0 */  lis      r4, UNDEF_80b05448@ha;
/* 80A939BC 387F0524 */  addi     r3, r31, 1316;
/* 80A939C0 38845448 */  addi     r4, r4, UNDEF_80b05448@l;
/* 80A939C4 909F0060 */  stw      r4, 96(r31);
/* 80A939C8 4B5D5659 */  bl       UNDEF_80069020;
/* 80A939CC 38000000 */  li       r0, 0;
/* 80A939D0 901F0540 */  stw      r0, 1344(r31);
/* 80A939D4 387F0544 */  addi     r3, r31, 1348;
/* 80A939D8 4B6D6439 */  bl       UNDEF_80169e10;
/* 80A939DC 387F0584 */  addi     r3, r31, 1412;
/* 80A939E0 4B5EBDC1 */  bl       UNDEF_8007f7a0;
UNDEF_80a939e4:;
/* 80A939E4 7FE3FB78 */  mr       r3, r31;
/* 80A939E8 83E1000C */  lwz      r31, 12(r1);
/* 80A939EC 80010014 */  lwz      r0, 20(r1);
/* 80A939F0 7C0803A6 */  mtlr     r0;
/* 80A939F4 38210010 */  addi     r1, r1, 16;
/* 80A939F8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80A94250)]]
void daEnRedcoin_c::selectItems()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mPlyItemSpawnMode[i] = 0;

        if (!daPyMng_c::isPlayerActive(i)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player == nullptr || player->isStatus(83) || player->isItemKinopio()) {
            continue;
        }

        mPlyItemSpawnMode[i] = 1;

        using IntArray = int[];
        switch (player->mPlayerMode) {
        case PLAYER_MODE_e::NONE:
        case PLAYER_MODE_e::MUSHROOM:
            mPlyItem[i] = IntArray{9, 21, 17, 14}[mItemType % 4];
            break;

        default:
            mPlyItem[i] = 7; // 1-Up
            break;
        }
    }
}

[[nsmbw(0x80A94340)]]
void daEnRedcoin_c::awardItems()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlyItemSpawnMode[i] == 0) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);
        if (player == nullptr || !daPyMng_c::isPlayerActive(i) || player->isStatus(83) ||
            player->isItemKinopio()) {
            continue;
        }

        mVec3_c position = {mPos.x, dBgParameter_c::ms_Instance_p->mScreenTop + 2, 0};
        dActor_c::construct(
          dProf::EN_ITEM, i << 16 | mPlyItem[i] | 0x2080, &position, nullptr, 0
        );
    }
}
