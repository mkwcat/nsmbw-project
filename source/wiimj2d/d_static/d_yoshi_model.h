#pragma once

#include "d_player_model_base.h"
#include "nw4r/g3d/g3d_resfile.h"

class dYoshiMdl_c : public dPyMdlBase_c
{
    SIZE_ASSERT(0x404);

public:
    // Structors
    // ^^^^^^

    /* 0x800FE2E0 */
    dYoshiMdl_c(u8 index);

public:
    // Constants and Types
    // ^^^^^^

    enum COLOR_e {
        COLOR_GREEN = 0,
        COLOR_RED = 1,
        COLOR_YELLOW = 2,
        COLOR_BLUE = 3,

        COLOR_CRIMSON = 4,
        COLOR_ORANGE = 5,
        COLOR_PURPLE = 6,
        COLOR_AZURE = 7,

        COLOR_COUNT,
    };

    static int s_yoshiColors[dYoshiMdl_c::COLOR_COUNT];

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800FE510 */
    void getPlayerObjectRes();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x20C */ nw4r::g3d::ResFile mModelResFile;
    /* 0x210 */ nw4r::g3d::ResFile mCommonAnimResFile;
    /* 0x214 */ nw4r::g3d::ResFile mAnimResFile;

    FILL(0x218, 0x24C);

    /* 0x24C */ COLOR_e mColor;
    /* 0x250 */ nw4r::g3d::ResFile mColorResFile;

    FILL(0x254, 0x404);

public:
    // Static Methods
    // ^^^^^

    static void setDefaultColors();
};