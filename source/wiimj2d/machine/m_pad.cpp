// m_pad.cpp
// NSMBW .text: 0x8016F330 - 0x8016F880

#include "m_pad.h"

#include "mkwcat/ToString.hpp"
#include <egg/core/eggController.h>
#include <mkwcat/Relocate.hpp>
#include <revolution/pad.h>
#include <revolution/wpad.h>

namespace mPad {

/* 0x80377F88 */
std::array<EGG::Controller*, CH_e::COUNT> g_core_order;

std::array<EGG::Controller*, CH_e::COUNT> g_core;

constinit std::array<CH_e, CH_e::COUNT>   g_playerChannel = [] {
    std::array<CH_e, CH_e::COUNT> arr{};
    for (int i = 0; i < CH_e::COUNT; i++) {
        arr[i] = static_cast<CH_e>(i);
    }
    return arr;
}();

[[nsmbw_data(0x8042A740)]]
EGG::CoreControllerMgr* g_padMg;

[[nsmbw_data(0x8042A744)]]
CH_e g_currentCoreID;

[[nsmbw_data(0x8042A748)]]
EGG::Controller* g_currentCore;

[[nsmbw_data(0x8042A74C)]] [[gnu::weak]]
bool g_IsConnectedOld[4];

bool g_IsConnected[CH_e::COUNT] = {
    g_IsConnectedOld[0], g_IsConnectedOld[1], g_IsConnectedOld[2], g_IsConnectedOld[3]
};

[[nsmbw_data(0x8042A750)]]
u32 g_PadFrame;

[[nsmbw(0x8042A754)]] [[gnu::weak]]
bool s_WPADInfoAvailableOld[4];

/* 0x8042A754 */
bool s_WPADInfoAvailable[CH_e::COUNT]{
    s_WPADInfoAvailableOld[0], s_WPADInfoAvailableOld[1], s_WPADInfoAvailableOld[2],
    s_WPADInfoAvailableOld[3]
};

[[nsmbw_data(0x8042A758)]]
s32 s_GetWPADInfoInterval;

[[nsmbw_data(0x8042A75C)]]
s32 s_GetWPADInfoCount;

[[nsmbw(0x80378008)]] [[gnu::weak]]
WPADInfo s_WPADInfoOld[4];

[[nsmbw(0x80378068)]] [[gnu::weak]]
WPADInfo s_WPADInfoTmpOld[4];

/* 0x80378008 */
WPADInfo s_WPADInfo[CH_e::COUNT] = {
    s_WPADInfoOld[0], s_WPADInfoOld[1], s_WPADInfoOld[2], s_WPADInfoOld[3]
};

/* 0x80378068 */
WPADInfo s_WPADInfoTmp[CH_e::COUNT] = {
    s_WPADInfoTmpOld[0], s_WPADInfoTmpOld[1], s_WPADInfoTmpOld[2], s_WPADInfoTmpOld[3]
};

[[nsmbw(0x80377FA8)]]
PadAdditionalData_s g_PadAdditionalData[4];

void initWPADInfo();

[[nsmbw(0x8016F330)]]
void create() {
    g_padMg = EGG::CoreControllerMgr::instance();
    initWPADInfo();
    beginPad();
    endPad();
}

[[nsmbw(0x8016F360)]]
void beginPad() {
    g_PadFrame++;

    g_padMg->beginFrame();
    auto* gcPadMg = EGG::GCControllerMgr::instance();
    gcPadMg->beginFrame();

    for (int i = CH_e::CHAN_0; i <= CH_e::CHAN_LAST; i++) {
        EGG::CoreController* core        = g_padMg->getNthController(i);
        g_core_order[g_playerChannel[i]] = g_core[i] = core;

        if (!core->connected()) {
            if (!g_IsConnected[i]) {
                continue;
            }

            core->mStatus->init();
            core->sceneReset();

            g_PadAdditionalData[i] = {};

            clearWPADInfo(static_cast<CH_e>(i));

            g_IsConnected[i] = false;
            continue;
        }

        mVec2_c x              = {core->mStatus->acc_vertical.x, core->mStatus->acc_vertical.y};
        mVec2_c y              = x - g_PadAdditionalData[i].mAccVertical[0];
        mVec2_c z              = y - g_PadAdditionalData[i].mAccVertical[1];
        g_PadAdditionalData[i] = {x, y, z};

        g_IsConnected[i]       = true;

        if (s_GetWPADInfoInterval != 0 &&
            (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == i ||
             (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
            getWPADInfoAsync(static_cast<CH_e>(i));
        }
    }

    for (int i = CH_e::CHAN_CL_0; i <= CH_e::CHAN_CL_LAST; i++) {
        EGG::ClassicController* classic  = g_padMg->getNthClassic(i - CH_e::CHAN_CL_0);
        g_core_order[g_playerChannel[i]] = g_core[i] = classic;
        g_IsConnected[i] =
            g_IsConnected[i - (CH_e::CHAN_CL_0 - CH_e::CHAN_0)] && classic->connected();
        if (!g_IsConnected[i]) {
            continue;
        }

        if (s_GetWPADInfoInterval != 0 &&
            (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == i ||
             (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
            // Fake WPAD info
            s_WPADInfo[i] = {
                .dpd       = false,
                .speaker   = false,
                .attach    = false,
                .lowBat    = false,
                .nearempty = false,
                .battery   = 0,
                .led       = 0,
                .protocol  = 0,
                .firmware  = 0
            };
            s_WPADInfoAvailable[i] = true;
        }
    }

    for (int i = CH_e::CHAN_GC_0; i <= CH_e::CHAN_GC_LAST; i++) {
        EGG::GCController* core          = gcPadMg->getNthController(i - CH_e::CHAN_GC_0);
        g_core_order[g_playerChannel[i]] = g_core[i] = core;
        g_IsConnected[i]                             = core->connected();
        if (!g_IsConnected[i]) {
            continue;
        }

        if (s_GetWPADInfoInterval != 0 &&
            (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == i ||
             (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
            // Fake WPAD info
            s_WPADInfo[i] = {
                .dpd       = false,
                .speaker   = false,
                .attach    = false,
                .lowBat    = false,
                .nearempty = false,
                .battery   = 0,
                .led       = 0,
                .protocol  = 0,
                .firmware  = 0
            };
            s_WPADInfoAvailable[i] = true;
        }
    }

    if (s_GetWPADInfoInterval <= s_GetWPADInfoCount++) {
        s_GetWPADInfoCount = 0;
    }

    g_currentCore = g_core_order[g_currentCoreID];
}

[[nsmbw(0x8016F550)]]
void endPad() {
    g_padMg->endFrame();
    EGG::GCControllerMgr::instance()->endFrame();
}

[[nsmbw(0x8016F570)]]
void setCurrentChannel(CH_e chan);

[[nsmbw(0x8016F5A0)]]
int getBatteryLevel_ch(
    CH_e chan
) {
    if (chan <= CH_e::CHAN_3 && s_WPADInfoAvailable[chan]) {
        return s_WPADInfo[chan].battery;
    }
    return 4;
}

[[nsmbw(0x8016F640)]]
void clearWPADInfo(
    CH_e chan
) {
    s_WPADInfo[chan]          = {};
    s_WPADInfoAvailable[chan] = false;
}

[[nsmbw(0x8016F690)]]
void initWPADInfo() {
    for (int i = 0; i < CH_e::COUNT; i++) {
        clearWPADInfo(static_cast<CH_e>(i));
    }
}

[[nsmbw(0x8016F710)]]
int getWPADInfoAsync(CH_e chan);

bool isGameCubeChannel(
    CH_e chan
) {
    return chan >= CH_e::CHAN_GC_0 && chan <= CH_e::CHAN_GC_3;
}

void setPlayerOrder(
    const std::array<CH_e, CH_e::COUNT>& order
) {
    g_playerChannel = order;
    for (int i = 0; i < CH_e::COUNT; i++) {
        g_core_order[g_playerChannel[i]] = g_core[i];
    }
    auto* prevCore = g_currentCore;
    g_currentCore  = g_core_order[g_currentCoreID];
    if (prevCore != g_currentCore) {
        OS_REPORT("New current core: %s\n", mkwcat::ToString(order[g_currentCoreID]));
    }
}

void setPlayerOrder(
    int player, CH_e channel
) {
    OS_REPORT("Register player #%d: %s\n", player, mkwcat::ToString(channel));

    g_playerChannel[player] = channel;
    g_core_order[player]    = g_core[channel];
    g_currentCore           = g_core_order[g_currentCoreID];
}

PATCH_REFERENCES(
    &g_core_order, //
    {
        {0x80017EEA, R_PPC_ADDR16_HA}, {0x80017EF6, R_PPC_ADDR16_LO}, {0x800582CA, R_PPC_ADDR16_HA},
        {0x800582CE, R_PPC_ADDR16_LO}, {0x800B540E, R_PPC_ADDR16_HA}, {0x800B5416, R_PPC_ADDR16_LO},
        {0x800B542E, R_PPC_ADDR16_HA}, {0x800B5436, R_PPC_ADDR16_LO}, {0x800B5E0E, R_PPC_ADDR16_HA},
        {0x800B5E1A, R_PPC_ADDR16_LO}, {0x800B5EBE, R_PPC_ADDR16_HA}, {0x800B5EC2, R_PPC_ADDR16_LO},
        {0x800B6456, R_PPC_ADDR16_HA}, {0x800B645A, R_PPC_ADDR16_LO}, {0x800D074E, R_PPC_ADDR16_HA},
        {0x800D0766, R_PPC_ADDR16_LO}, {0x800D088A, R_PPC_ADDR16_HA}, {0x800D088E, R_PPC_ADDR16_LO},
        {0x800D0892, R_PPC_ADDR16_LO}, {0x800D0DFE, R_PPC_ADDR16_HA}, {0x800D0E06, R_PPC_ADDR16_LO},
        {0x800D116A, R_PPC_ADDR16_HA}, {0x800D1172, R_PPC_ADDR16_LO}, {0x800D89BE, R_PPC_ADDR16_HA},
        {0x800D89C2, R_PPC_ADDR16_LO}, {0x800D8A82, R_PPC_ADDR16_HA}, {0x800D8A92, R_PPC_ADDR16_LO},
        {0x800D8B86, R_PPC_ADDR16_HA}, {0x800D8B8A, R_PPC_ADDR16_LO}, {0x800D8D0E, R_PPC_ADDR16_HA},
        {0x800D8D12, R_PPC_ADDR16_LO}, {0x800D8E4E, R_PPC_ADDR16_HA}, {0x800D8E56, R_PPC_ADDR16_LO},
        {0x800D8EE6, R_PPC_ADDR16_HA}, {0x800D8EEA, R_PPC_ADDR16_LO}, {0x800D988A, R_PPC_ADDR16_HA},
        {0x800D9892, R_PPC_ADDR16_LO}, {0x800DC7EA, R_PPC_ADDR16_HA}, {0x800DC7F2, R_PPC_ADDR16_LO},
        {0x800DC86E, R_PPC_ADDR16_HA}, {0x800DC872, R_PPC_ADDR16_LO}, {0x800DC956, R_PPC_ADDR16_HA},
        {0x800DC95A, R_PPC_ADDR16_LO}, {0x800DC9DA, R_PPC_ADDR16_HA}, {0x800DC9E2, R_PPC_ADDR16_LO},
        {0x800DCAB6, R_PPC_ADDR16_HA}, {0x800DCABA, R_PPC_ADDR16_LO}, {0x800DCB2A, R_PPC_ADDR16_HA},
        {0x800DCB3A, R_PPC_ADDR16_LO}, {0x800DCC6A, R_PPC_ADDR16_HA}, {0x800DCC72, R_PPC_ADDR16_LO},
        {0x800DCD9A, R_PPC_ADDR16_HA}, {0x800DCDA2, R_PPC_ADDR16_LO}, {0x800DCECA, R_PPC_ADDR16_HA},
        {0x800DCED2, R_PPC_ADDR16_LO}, {0x80101106, R_PPC_ADDR16_HA}, {0x8010110E, R_PPC_ADDR16_LO},
        {0x80109C4A, R_PPC_ADDR16_HA}, {0x80109C5E, R_PPC_ADDR16_LO}, {0x80109D26, R_PPC_ADDR16_HA},
        {0x80109D2E, R_PPC_ADDR16_LO}, {0x8010A15A, R_PPC_ADDR16_HA}, {0x8010A15E, R_PPC_ADDR16_LO},
        {0x8010D9E6, R_PPC_ADDR16_HA}, {0x8010D9F6, R_PPC_ADDR16_LO}, {0x8010DA96, R_PPC_ADDR16_HA},
        {0x8010DAA6, R_PPC_ADDR16_LO}, {0x8010DB46, R_PPC_ADDR16_HA}, {0x8010DB56, R_PPC_ADDR16_LO},
        {0x8016F39E, R_PPC_ADDR16_HA}, {0x8016F3AA, R_PPC_ADDR16_LO}, {0x8016F512, R_PPC_ADDR16_HA},
        {0x8016F516, R_PPC_ADDR16_LO}, {0x8016F576, R_PPC_ADDR16_HA}, {0x8016F582, R_PPC_ADDR16_LO},
        {0x807705A6, R_PPC_ADDR16_HA}, {0x807705AA, R_PPC_ADDR16_LO}, {0x8077094A, R_PPC_ADDR16_HA},
        {0x8077095A, R_PPC_ADDR16_LO}, {0x80811F6E, R_PPC_ADDR16_HA}, {0x80811F72, R_PPC_ADDR16_LO},
        {0x80916B52, R_PPC_ADDR16_HA}, {0x80916B5A, R_PPC_ADDR16_LO}, {0x8092592E, R_PPC_ADDR16_HA},
        {0x80925936, R_PPC_ADDR16_LO}, {0x80A97CEA, R_PPC_ADDR16_HA}, {0x80A97CF6, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    &g_PadAdditionalData, //
    {
        {0x800B5E12, R_PPC_ADDR16_HA},
        {0x800B5E26, R_PPC_ADDR16_LO},
        {0x8016F3A2, R_PPC_ADDR16_HA},
        {0x8016F3AE, R_PPC_ADDR16_LO},
        {0x8016F7BA, R_PPC_ADDR16_HA},
        {0x8016F7CE, R_PPC_ADDR16_LO},
        {0x8016F862, R_PPC_ADDR16_HA},
        {0x8016F86A, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    &s_WPADInfo, //
    {
        {0x8016F5B6, R_PPC_ADDR16_HA},
        {0x8016F5BA, R_PPC_ADDR16_LO},
        {0x8016F5D6, R_PPC_ADDR16_HA},
        {0x8016F5E2, R_PPC_ADDR16_LO},
        {0x8016F646, R_PPC_ADDR16_HA},
        {0x8016F64E, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    &s_WPADInfo, //
    {
        {0x8016F6F6, R_PPC_ADDR16_HA},
        {0x8016F6FA, R_PPC_ADDR16_LO},
        {0x8016F71A, R_PPC_ADDR16_HA},
        {0x8016F72A, R_PPC_ADDR16_LO},
    }
);

} // namespace mPad
