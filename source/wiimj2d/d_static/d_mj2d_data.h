#pragma once

#include "d_mj2d_game.h"
#include "d_mj2d_header.h"

struct dMj2dData_c {
    constexpr dMj2dData_c() = default;
    constexpr dMj2dData_c(const dMj2dData_c& other) = default;

    dMj2dHeader_c mHeader;
    dMj2dGame_c mSaveGames[SAVE_SLOT_COUNT];
    dMj2dGame_c mTempGames[SAVE_SLOT_COUNT];
};

static_assert(sizeof(dMj2dData_c) <= 0x3FA0);