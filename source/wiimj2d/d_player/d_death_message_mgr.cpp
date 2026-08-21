// d_death_message_mgr.cpp
// NSMBW: ---

#include "d_death_message_mgr.h"

#include "d_static/d_game_common.h"
#include <algorithm>
#include <cwchar>
#include <egg/gfx/eggFrustum.h>
#include <egg/gfx/eggScreen.h>
#include <iterator>
#include <memory>
#include <nw4r/lyt/Material.h>
#include <nw4r/lyt/Resources.h>
#include <nw4r/lyt/TextBox.h>

static constinit nw4r::lyt::res::TextureList s_txl1 = {
  .blockHeader =
    {
      .kind = {'t', 'x', 'l', '1'},
      .size = sizeof(nw4r::lyt::res::TextureList),
    },
  .texNum = 0,
};

static constinit struct FontList1 {
    nw4r::lyt::res::FontList main;
    u32 offset1;
    nw4r::lyt::res::Font font;
    char fontName[0x20];
} s_fnl1 = {
  .main =
    {
      .blockHeader =
        {
          .kind = {'f', 'n', 'l', '1'},
          .size = sizeof(FontList1),
        },
      .fontNum = 1,
    },
  .offset1 = offsetof(FontList1, font),
  .font = {.nameStrOffset = offsetof(FontList1, fontName), .type = 0},
  .fontName = "mj2d00_MessageFont_32_I4.brfnt",
};

static constinit struct MaterialList1 {
    nw4r::lyt::res::MaterialList main;
    u32 offset1;
    nw4r::lyt::res::Material material;
} s_mat1 = {
  .main =
    {
      .blockHeader =
        {
          .kind = {'m', 'a', 't', '1'},
          .size = sizeof(MaterialList1),
        },
      .materialNum = 1,
    },
  .offset1 = offsetof(MaterialList1, material),
  .material = {
    .materialName = "Mat_DeathMsg",
    .foreColor = "#00000000",
    .backColor = "#FFFFFFFF",
    .colorReg3 = "#00000000",
    .tevColor1 = "#00000000",
    .tevColor2 = "#00000000",
    .tevColor3 = "#00000000",
    .tevColor4 = "#00000000",
    .flags = 0,
  },
};

static constinit struct TextBox1 {
    nw4r::lyt::res::TextBox main;
    wchar_t message[8] = {};
} s_txt1 = {
  .main =
    {
      .pane =
        {
          .blockHeader =
            {
              .kind = {'t', 'x', 't', '1'},
              .size = sizeof(TextBox1),
            },

          .flag = 0x5,
          .basePosition = 0,
          .alpha = 0xFF,
          .name = "Txt_DeathMsg",
          .userData = {},
          .translate = {-250.0, 0.0, -10.0},
          .rotate = {0.0, 0.0, 0.0},
          .scale = {1.0, 1.0},
          .size = {800.0, 45.0},
        },

      .textBufBytes = 127,
      .textStrBytes = 127,
      .materialIdx = 0,
      .fontIdx = 0,
      .textPosition = 0,
      .textAlignment = 2,
      .textStrOffset = offsetof(TextBox1, message),
      .textCols = {"#FF7F7F", "#FF3030"},
      .fontSize = {25.0, 25.0},
      .charSpace = 1.0,
      .lineSpace = 1.0,
    },
  .message = L"meow\0",
};

dDeathMsgMgr_c::dDeathMsgMgr_c()
  : Base_c(0)
  , mTextBox(nullptr)
  , mResBlockSet({
      .pTextureList = &s_txl1,
      .pFontList = &s_fnl1.main,
      .pMaterialList = &s_mat1.main,
      .pResAccessor = nullptr,
    })
  , mIndex(0)
  , mCount(0)
{
    // Allocate memory without constructing
    mTextBox = std::allocator<nw4r::lyt::TextBox>{}.allocate(MAX_MESSAGES);

    for (u32 i = 0; i < MAX_MESSAGES; i++) {
        mTimeToLive[i] = 0;
    }
}

dDeathMsgMgr_c::~dDeathMsgMgr_c()
{
    std::destroy(mTextBox, mTextBox + MAX_MESSAGES);
    std::allocator<nw4r::lyt::TextBox>{}.deallocate(mTextBox, MAX_MESSAGES);
}

void dDeathMsgMgr_c::build(nw4r::lyt::ResourceAccessor* resAcc, nw4r::lyt::DrawInfo* drawInfo)
{
    mResBlockSet.pResAccessor = resAcc;
    mpDrawInfo = drawInfo;

    for (s32 i = 0; i < MAX_MESSAGES; i++) {
        std::construct_at<nw4r::lyt::TextBox>(mTextBox + i, &s_txt1.main, mResBlockSet);
        mTextBox[i].SetVisible(false);
    }
}

static constinit nw4r::ut::Color s_playerColors[PLAYER_COUNT] = {
  "#FF7F7F", // Mario
  "#7FFF7F", // Luigi
  "#7F7FFF", // Blue Toad
  "#FFFF7F", // Yellow Toad
  "#FF7FBF", // Toadette
  "#EFBFFF", // Purple Toadette
  "#FFBF7F", // Orange Toad
  "#7F6F7F", // Black Toad
};

void dDeathMsgMgr_c::newMessage(const wchar_t* message, PLAYER_TYPE_e player)
{
    if (mCount >= MAX_MESSAGES) {
        deleteFront();
    }

    u32 index = (mIndex + mCount) % MAX_MESSAGES;
    mCount++;

    std::size_t colorType = daPyMng_c::getPlayerColorType(player);
    std::size_t playerIndex = std::min(colorType, std::size(s_playerColors) - 1);

    mTextBox[index].SetTextColor(nw4r::lyt::TextColor::TEXTCOLOR_TOP, s_playerColors[playerIndex]);
    mTextBox[index].SetTextColor(
      nw4r::lyt::TextColor::TEXTCOLOR_BOTTOM, s_playerColors[playerIndex]
    );
    mTextBox[index].SetString(message, 0);
    mTextBox[index].SetVisible(true);
    mTimeToLive[index] = 8 * 60;
}

void dDeathMsgMgr_c::deleteFront()
{
    if (mCount == 0) {
        return;
    }

    mTextBox[mIndex].SetVisible(false);

    mIndex = (mIndex + 1) % MAX_MESSAGES;
    mCount--;
}

void dDeathMsgMgr_c::draw()
{
    u32 count = mCount;

    // Configure the screen
    if (count != 0) {
        EGG::Screen screen;

        f32 left = -304.0f;
        f32 top = 228.0f;
        f32 right = 304.0f;
        f32 bottom = -228.0f;

        bool widescreen = dGameCom::GetAspectRatio() == SCAspectRatio::WIDESCREEN;
        f64 width4_3 = EGG::Screen::GetSizeXMax(EGG::Screen::TV_MODE_4_3);
        f64 width16_9 = EGG::Screen::GetSizeXMax(EGG::Screen::TV_MODE_16_9);

        if (widescreen) {
            left *= (width16_9 / width4_3);
            right *= (width16_9 / width4_3);
        }

        screen.SetProjectionType(EGG::Frustum::ProjectionType::PROJ_ORTHO);
        screen.ResetOrthographic(top, bottom, left, right, 0.0f, 500.0f);

        if (widescreen) {
            screen.SetScale({f32(width4_3 / width16_9), 1.0f, 1.0f});
        }

        screen.SetProjectionGX();
    }

    float position = -170.0f + 35.0f * count;

    for (s32 i = 0; i < count; i++) {
        position -= 35.0f;
        u32 index = (mIndex + i) % MAX_MESSAGES;
        auto textBox = &mTextBox[index];

        u32 ttl = --mTimeToLive[index];
        textBox->SetAlpha(std::min<u32>(ttl * 255 / 30, 255));
        textBox->SetTranslate({textBox->GetTranslate().x, position, textBox->GetTranslate().z});

        textBox->CalculateMtx(*mpDrawInfo);
        textBox->Draw(*mpDrawInfo);

        if (ttl == 0) {
            deleteFront();
            count--;
            i--;
        }
    }
}
