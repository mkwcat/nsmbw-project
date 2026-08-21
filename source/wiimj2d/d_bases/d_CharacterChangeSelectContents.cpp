// d_CharacterChangeSelectContents.cpp
// NSMBW: 0x80772A50 - 0x80773F30

#include "d_CharacterChangeSelectContents.h"

#include "d_static/d_a_player_manager.h"
#include "d_static/d_game_common.h"
#include "d_static/d_mj2d_game.h"
#include <algorithm>

[[nsmbw(0x80772A50)]]
dCharacterChangeSelectContents_c* dCharacterChangeSelectContents_c_classInit()
{
    return new dCharacterChangeSelectContents_c();
}

[[nsmbw(0x80772A80)]]
dCharacterChangeSelectContents_c::dCharacterChangeSelectContents_c();

[[nsmbw(0x80772E30)]]
bool dCharacterChangeSelectContents_c::createLayout()
{
    bool ret = mLayout.hasAccessor();
    if (!ret) {
        return ret;
    }

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.build("characterChangeSelectContents_05.brlyt", nullptr);

    mLayout.AnimeResRegister(StringArray{"characterChangeSelectContents_05_hitButton.brlan"}, 1);

    mLayout.GroupRegister(StringArray{"A00_Shine"}, IntArray{0}, 1);

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
      StringArray{
        "N_cSelectCon_00",
        "N_cSelectCon_01",
      },
      mpaSelectConPane, 2
    );

    mLayout.PPaneRegister(
      StringArray{
        "PbuttonShadow_00",
        "PbuttonShadow_01",
        "P_lui_00",
        "P_lui_01",
        "P_kinoB_00",
        "P_kinoB_01",
        "P_kinoY_00",
        "P_kinoY_01",
      },
      mpaPictures, 8
    );
    mLayout.TPaneRegister(
      StringArray{
        "T_zanki_01",
        "T_zanki_00",
        "T_kakeru_00",
        "T_kakeru_01",
      },
      mpaTextBoxes, 4
    );

    // Register the Mario panes as well
    mLayout.PPaneRegister(
      StringArray{
        "P_mar_00",
        "P_mar_01",
      },
      mpaMarioPictures, 2
    );

    return ret;
}

void dCharacterChangeSelectContents_c::setMarioIconVisible(int param2)
{
    dGameCom::LayoutDispNumber(mLives[0], 2, mpaTextBoxes[param2], false);
    mpaPictures[param2]->SetVisible(true);
}

[[nsmbw(0x80773220)]]
void dCharacterChangeSelectContents_c::dispNextConPicture(Icon_e iconNext, int side)
{
    for (std::size_t pic = side; pic < std::size(mpaPictures); pic += 2) {
        mpaPictures[pic]->SetVisible(false);
    }
    for (std::size_t pic = side; pic < std::size(mpaMarioPictures); pic += 2) {
        mpaMarioPictures[pic]->SetVisible(false);
    }
    for (std::size_t txt = side; txt < std::size(mpaTextBoxes); txt += 2) {
        mpaTextBoxes[txt]->SetVisible(false);
    }

    PLAYER_TYPE_e type = dCharacterChangeSelectBase_c::getCharacterFromIcon(iconNext);

    dGameCom::LayoutDispNumber(daPyMng_c::mRest[type], 2, mpaTextBoxes[side], false);

    int picIndex = cEnumArray_c<int, PLAYER_TYPE_e>{
      std::distance(mpaPictures, mpaMarioPictures), // Mario
      2, // Luigi
      4, // Blue Toad
      6, // Yellow Toad
      0, // Other
    }[std::min(type, PLAYER_TYPE_e::TOADETTE)];

    if (picIndex != 0) {
        mpaPictures[picIndex + side]->SetVisible(true);
    }

    if (dCharacterChangeSelectBase_c::isLockedIcon(iconNext)) {
        mpaPictures[0 + side]->SetVisible(true);
    }

    mpaTextBoxes[side]->SetVisible(true);
    mpaTextBoxes[2 + side]->SetVisible(true);
}

[[nsmbw(0x80773840)]]
void dCharacterChangeSelectContents_c::finalizeState_OnStageWait()
{
    mLives[0] = daPyMng_c::mRest[PLAYER_TYPE_e::MARIO];
    mLives[1] = daPyMng_c::mRest[PLAYER_TYPE_e::LUIGI];
    mLives[2] = daPyMng_c::mRest[PLAYER_TYPE_e::BLUE_TOAD];
    mLives[3] = daPyMng_c::mRest[PLAYER_TYPE_e::YELLOW_TOAD];

    m0x28C = Icon_e::ICON_NONE;
    m0x294 = Icon_e::ICON_NONE;
    m0x29E = 0;
    m0x29F = 0;
}
