#pragma once

#include "m_vec.h"
#include <array>
#include <egg/core/eggController.h>

namespace mPad
{

enum CH_e {
    CHAN_0 = 0,
    CHAN_1 = 1,
    CHAN_2 = 2,
    CHAN_3 = 3,
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

struct PadAdditionalData_s {
    mVec2_c mAccVertical[3];
};

/* 0x80377F88 @renamed */
extern std::array<EGG::Controller*, CH_e::COUNT> g_core_order;

extern std::array<EGG::Controller*, CH_e::COUNT> g_core;

extern std::array<CH_e, CH_e::COUNT> g_playerChannel;

/* 0x80377FA8 */
extern PadAdditionalData_s g_PadAdditionalData[4];

/* 0x8042A740 */
extern EGG::CoreControllerMgr* g_padMg;

/* 0x8042A744 */
extern CH_e g_currentCoreID;

/* 0x8042A748 */
extern EGG::Controller* g_currentCore;

/* 0x8042A74C */
extern bool g_IsConnected[CH_e::COUNT];

/* 0x8042A750 */
extern u32 g_PadFrame;

/* 0x8016F330 */
void create();

/* 0x8016F360 */
void beginPad();

/* 0x8016F550 */
void endPad();

/* 0x8016F5A0 @unofficial */
int getBatteryLevel_ch(CH_e chan);

/* 0x8016F570 */
void setCurrentChannel(CH_e chan);

/* 0x8016F640 */
void clearWPADInfo(CH_e chan);

/* 0x8016F710 */
int getWPADInfoAsync(CH_e chan);

bool isGameCubeChannel(CH_e chan);

void setPlayerOrder(const std::array<CH_e, CH_e::COUNT>& order);

void setPlayerOrder(int player, CH_e channel);

} // namespace mPad
