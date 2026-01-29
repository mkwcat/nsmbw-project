// d_fukidashiInfo.cpp
// NSMBW .text: 0x800B14E0 - 0x800B2D20

#include "d_fukidashiInfo.h"

#include "d_system/d_a_player_manager.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_pause_manager.h"
#include "framework/f_feature.h"
#include <nw4r/lyt/Material.h>
#include <nw4r/ut/Color.h>

[[nsmbw(0x800B1990)]]
void dfukidashiInfo_c::draw()
{
    if (!mDisplayed) {
        return;
    }
    switch (fFeat::fukidashi_mode) {
    case fFeat::FUKIDASHI_MODE_e::ALWAYS_SHOW:
        return mLayout.entry();
    case fFeat::FUKIDASHI_MODE_e::HIDE_IF_5_TO_8_PLAYER:
        if (daPyMng_c::getNumInGame() < 5) {
            return mLayout.entry();
        }
        break;
    case fFeat::FUKIDASHI_MODE_e::ALWAYS_HIDE:
        return;
    }
}

[[nsmbw(0x800B1A50)]]
void dfukidashiInfo_c::SetPosOffset(int playerType, int powerupType)
{
    float s_FUKIDASHI_Y_OFFSET[PLAYER_COUNT][PLAYER_MODE_COUNT] = {
      // Mario
      {
        20.0, // Small
        32.0, // Mushroom
        32.0, // Fire Flower
        12.0, // Mini Mushroom
        38.0, // Propeller Shroom
        33.0, // Penguin Suit
        32.0, // Ice Flower
      },

      // Luigi
      {
        20.0, // Small
        34.0, // Mushroom
        34.0, // Fire Flower
        12.0, // Mini Mushroom
        39.0, // Propeller Shroom
        35.0, // Penguin Suit
        34.0, // Ice Flower
      },

      // Blue Toad
      {
        20.0, // Small
        29.0, // Mushroom
        29.0, // Fire Flower
        11.0, // Mini Mushroom
        34.0, // Propeller Shroom
        29.0, // Penguin Suit
        29.0, // Ice Flower
      },

      // Yellow Toad
      {
        20.0, // Small
        29.0, // Mushroom
        29.0, // Fire Flower
        11.0, // Mini Mushroom
        34.0, // Propeller Shroom
        29.0, // Penguin Suit
        29.0, // Ice Flower
      },

      // Toadette
      {
        20.0, // Small
        29.0, // Mushroom
        29.0, // Fire Flower
        11.0, // Mini Mushroom
        34.0, // Propeller Shroom
        29.0, // Penguin Suit
        29.0, // Ice Flower
      },

      // Purple Toadette
      {
        20.0, // Small
        29.0, // Mushroom
        29.0, // Fire Flower
        11.0, // Mini Mushroom
        34.0, // Propeller Shroom
        29.0, // Penguin Suit
        29.0, // Ice Flower
      },

      // Orange Toad
      {
        20.0, // Small
        29.0, // Mushroom
        29.0, // Fire Flower
        11.0, // Mini Mushroom
        34.0, // Propeller Shroom
        29.0, // Penguin Suit
        29.0, // Ice Flower
      },

      // Black Toad
      {
        20.0, // Small
        29.0, // Mushroom
        29.0, // Fire Flower
        11.0, // Mini Mushroom
        34.0, // Propeller Shroom
        29.0, // Penguin Suit
        29.0, // Ice Flower
      },
    };

    mPosOffset.x = 0.0;
    mPosOffset.y = s_FUKIDASHI_Y_OFFSET[playerType][powerupType];
    mPosOffset.z = 0.0;
}

[[nsmbw(0x800B1BD0)]]
void dfukidashiInfo_c::ColorSet()
{
    static constinit nw4r::ut::Color l_PLAYER_COLOR_1[PLAYER_COUNT] = {
      "#FAE6E6", // Mario
      "#F0FFF0", // Luigi,
      "#F0FAFA", // Blue Toad
      "#FAFAE6", // Yellow Toad
      "#FAE1EC", // Toadette
      "#E3D5EB", // Purple Toadette
      "#F6E7D9", // Orange Toad
      "#86798B", // Black Toad
    };

    static constinit nw4r::ut::Color l_PLAYER_COLOR_2[PLAYER_COUNT] = {
      "#F06E6E", // Mario
      "#64C864", // Luigi
      "#648CDC", // Blue Toad
      "#FFDC50", // Yellow Toad
      "#FF8DB7", // Toadette
      "#DA89FA", // Purple Toadette
      "#EA7F4F", // Orange Toad
      "#2D2A2E", // Black Toad
    };

    static constinit nw4r::ut::Color l_PLAYER_COLOR_3[PLAYER_COUNT] = {
      "#FFB4B4", // Mario
      "#64FF64", // Luigi
      "#8CFAFF", // Blue Toad
      "#FFF06E", // Yellow Toad
      "#FFB2D6", // Toadette
      "#E6C2FB", // Purple Toadette
      "#F3C489", // Orange Toad
      "#5C5560", // Black Toad
    };

    PLAYER_TYPE_e playerType = daPyMng_c::mPlayerType[mPlayerID];
    if (m0x220 == 8 && !PauseManager_c::m_OtasukeAfter) {
        playerType = PLAYER_TYPE_e::MARIO;
    }

    int playerIndex = daPyMng_c::getPlayerColorType(playerType);

    nw4r::ut::Color color1 = l_PLAYER_COLOR_1[playerIndex];
    nw4r::ut::Color color2 = l_PLAYER_COLOR_2[playerIndex];
    nw4r::ut::Color color3 = l_PLAYER_COLOR_3[playerIndex];

    auto setPictureColor = [&](nw4r::lyt::Picture* picture) {
        for (int i = 0; i < 2; i++) {
            picture->SetVtxColor(i, color1);
        }
        for (int i = 2; i < 4; i++) {
            picture->SetVtxColor(i, color2);
        }
    };

    setPictureColor(mpAfterImgUD);
    setPictureColor(mpUpDownImg01);
    setPictureColor(mpAfterImgK);
    setPictureColor(mpKatamukiHand);

    nw4r::lyt::Material* material = mpArrow->GetMaterial();

    material->SetTevColor(1, color3);
}

[[nsmbw(0x800B2230)]]
void dfukidashiInfo_c::executeState_Move() ASM_METHOD(
  // clang-format off
/* 800B2230 9421FFF0 */  stwu     r1, -16(r1);
/* 800B2234 7C0802A6 */  mflr     r0;
/* 800B2238 90010014 */  stw      r0, 20(r1);
/* 800B223C 93E1000C */  stw      r31, 12(r1);
/* 800B2240 93C10008 */  stw      r30, 8(r1);
/* 800B2244 7C7E1B78 */  mr       r30, r3;
/* 800B2248 80830224 */  lwz      r4, 548(r3);
/* 800B224C 83EDA8DC */  lwz      r31, UNDEF_8042a25c@sda21; // m_instance__7dInfo_c
/* 800B2250 2C040000 */  cmpwi    r4, 0;
/* 800B2254 41820010 */  beq-     UNDEF_800b2264;
/* 800B2258 80030234 */  lwz      r0, 564(r3);
/* 800B225C 7C040214 */  add      r0, r4, r0;
/* 800B2260 90030224 */  stw      r0, 548(r3);
UNDEF_800b2264:;
/* 800B2264 80830230 */  lwz      r4, 560(r3);
/* 800B2268 2C040000 */  cmpwi    r4, 0;
/* 800B226C 41800010 */  blt-     UNDEF_800b227c;
/* 800B2270 3800FFFF */  li       r0, -1;
/* 800B2274 90830224 */  stw      r4, 548(r3);
/* 800B2278 90030234 */  stw      r0, 564(r3);
UNDEF_800b227c:;
/* 800B227C 8803023A */  lbz      r0, 570(r3);
/* 800B2280 2C000000 */  cmpwi    r0, 0;
/* 800B2284 4182000C */  beq-     UNDEF_800b2290;
/* 800B2288 38000000 */  li       r0, 0;
/* 800B228C 90030224 */  stw      r0, 548(r3);
UNDEF_800b2290:;
/* 800B2290 80030220 */  lwz      r0, 544(r3);
/* 800B2294 2C000001 */  cmpwi    r0, 1;
/* 800B2298 40820030 */  bne-     UNDEF_800b22c8;
/* 800B229C 480000B5 */  bl       UNDEF_800b2350;
/* 800B22A0 5460063F */  clrlwi.  r0, r3, 24;
/* 800B22A4 40820024 */  bne-     UNDEF_800b22c8;
/* 800B22A8 480000B9 */  bl       UNDEF_800b2360;
/* 800B22AC 5460063F */  clrlwi.  r0, r3, 24;
/* 800B22B0 40820018 */  bne-     UNDEF_800b22c8;
/* 800B22B4 801E0230 */  lwz      r0, 560(r30);
/* 800B22B8 2C000000 */  cmpwi    r0, 0;
/* 800B22BC 41800074 */  blt-     UNDEF_800b2330;
/* 800B22C0 38000000 */  li       r0, 0;
/* 800B22C4 901E0224 */  stw      r0, 548(r30);
UNDEF_800b22c8:;
/* 800B22C8 801E0230 */  lwz      r0, 560(r30);
/* 800B22CC 2C000000 */  cmpwi    r0, 0;
/* 800B22D0 4180000C */  blt-     UNDEF_800b22dc;
/* 800B22D4 3800FFFF */  li       r0, -1;
/* 800B22D8 901E0230 */  stw      r0, 560(r30);
UNDEF_800b22dc:;
/* 800B22DC 801E0224 */  lwz      r0, 548(r30);
/* 800B22E0 2C800000 */  cmpwi    cr1, r0, 0;
/* 800B22E4 4086004C */  bne-     cr1, UNDEF_800b2330;
/* 800B22E8 801E0220 */  lwz      r0, 544(r30);
/* 800B22EC 2C000001 */  cmpwi    r0, 1;
/* 800B22F0 40820024 */  bne-     UNDEF_800b2314;
/* 800B22F4 881E023A */  lbz      r0, 570(r30);
/* 800B22F8 2C000000 */  cmpwi    r0, 0;
/* 800B22FC 40820018 */  bne-     UNDEF_800b2314;
/* 800B2300 40860014 */  bne-     cr1, UNDEF_800b2314;
/* 800B2304 801E021C */  lwz      r0, 540(r30);
/* 800B2308 38800001 */  li       r4, 1;
/* 800B230C 7C7F0214 */  add      r3, r31, r0;

                         cmpwi    r0, 4;
                         blt+     L_dfukidashiInfo_c_executeState_Move_NormalPlayer;
                         addi     r3, r3, ADJUST_dInfo_c_mEx0xB56;
L_dfukidashiInfo_c_executeState_Move_NormalPlayer:;
/* 800B2310 98830B56 */  stb      r4, 0xB56(r3);
UNDEF_800b2314:;
/* 800B2314 819E019C */  lwz      r12, 412(r30);
/* 800B2318 3C808036 */  lis      r4, UNDEF_80358d18@ha;
/* 800B231C 387E019C */  addi     r3, r30, 412;
/* 800B2320 818C0018 */  lwz      r12, 24(r12);
/* 800B2324 38848D18 */  addi     r4, r4, UNDEF_80358d18@l;
/* 800B2328 7D8903A6 */  mtctr    r12;
/* 800B232C 4E800421 */  bctrl;
UNDEF_800b2330:;
/* 800B2330 80010014 */  lwz      r0, 20(r1);
/* 800B2334 83E1000C */  lwz      r31, 12(r1);
/* 800B2338 83C10008 */  lwz      r30, 8(r1);
/* 800B233C 7C0803A6 */  mtlr     r0;
/* 800B2340 38210010 */  addi     r1, r1, 16;
/* 800B2344 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x800B2370)]]
void dfukidashiInfo_c::finalizeState_Move()
{
    mLayout.AnimeEndSetup(m0x22C);

    if (m0x23A == false) {
        return;
    }

    dInfo_c* dInfo = dInfo_c::m_instance;

    u8* afeValue = mPlayerID < 4 ? dInfo->m0xAFE[mPlayerID] : dInfo->mEx0xAFE[mPlayerID - 4];

    if (!(dInfo_c::m_startGameInfo.world1 == WORLD_e::WORLD_1 &&
          dInfo_c::m_startGameInfo.stage1 == STAGE_e::STAGE_1)) {
        afeValue[m0x220] = 1;
    }

    if (m0x220 == 8) {
        dInfo->m0xAFE[0][8] = 1;
        dInfo->m0xAFE[1][8] = 1;
        dInfo->m0xAFE[2][8] = 1;
        dInfo->m0xAFE[3][8] = 1;

        for (int i = 0; i < PLAYER_COUNT - 4; i++) {
            dInfo->mEx0xAFE[i][8] = 1;
        }
    }

    m0x23A = false;
}

[[nsmbw(0x800B24B0)]]
void dfukidashiInfo_c::finalizeState_Exit()
{
    u8* b56Value = mPlayerID < 4 ? &dInfo_c::m_instance->m0xB56[mPlayerID]
                                 : &dInfo_c::m_instance->mEx0xB56[mPlayerID - 4];

    if ((dInfo_c::m_startGameInfo.world1 == WORLD_e::WORLD_1 &&
         dInfo_c::m_startGameInfo.stage1 == STAGE_e::STAGE_1) ||
        m0x230 >= 0) {
        *b56Value = 0;
    }

    m0x234 = 0;
    mDisplayed = false;
    mLayout.AllAnimeEndSetup();
    mpPane->SetVisible(false);
}
