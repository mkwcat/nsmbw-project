#pragma once

#include "m_vec.h"
#include <array>
#include <egg/core/eggController.h>
#include <slu/array.hpp>
#include <utility>

namespace mPad {

using PadID = int;

enum class CH_e {
    CHAN_0    = 0,
    CHAN_1    = 1,
    CHAN_2    = 2,
    CHAN_3    = 3,
    CHAN_LAST = CHAN_3,

    // GameCube
    CHAN_GC_0,
    CHAN_GC_1,
    CHAN_GC_2,
    CHAN_GC_3,
    CHAN_GC_LAST = CHAN_GC_3,

    // Classic
    CHAN_CL_0,
    CHAN_CL_1,
    CHAN_CL_2,
    CHAN_CL_3,
    CHAN_CL_LAST = CHAN_CL_3,

    COUNT,
};

enum {
    CHAN_COUNT = std::to_underlying(CH_e::COUNT),
    PAD_COUNT  = CHAN_COUNT,
};

struct PadAdditionalData_s {
    mVec2_c mAccVertical[3];
};

/* 0x80377F88 */
extern std::array<EGG::Controller*, PAD_COUNT> g_core;

extern slu::enum_array<EGG::Controller*, CH_e> g_coreUnordered;

extern std::array<CH_e, PAD_COUNT>             g_channel;

/* 0x80377FA8 */
extern PadAdditionalData_s g_PadAdditionalData[4];

/* 0x8042A740 */
extern EGG::CoreControllerMgr* g_padMg;

/* 0x8042A744 - type changed */
extern PadID g_currentCoreID;

/* 0x8042A748 */
extern EGG::Controller* g_currentCore;

/* 0x8042A750 */
extern u32 g_PadFrame;

/* 0x8016F330 */
void create();

/* 0x8016F360 */
void beginPad();

/* 0x8016F550 */
void endPad();

/* 0x8016F5A0 */
int getBatteryLevel_ch(CH_e chan);

/* 0x8016F570 @renamed */
PadID setCurrentChannel(PadID id);

bool isGameCubeChannel(CH_e chan);

void setPlayerOrder(const std::array<CH_e, PAD_COUNT>& order);

void setPlayerOrder(PadID id, CH_e chan);

inline CH_e getChannel(
    PadID id
) {
    return g_channel[id];
}

constexpr CH_e getClassicChannel(
    CH_e chan
) {
    return static_cast<mPad::CH_e>(
        std::to_underlying(chan) +
        (std::to_underlying(mPad::CH_e::CHAN_CL_0) - std::to_underlying(mPad::CH_e::CHAN_0))
    );
}

} // namespace mPad
