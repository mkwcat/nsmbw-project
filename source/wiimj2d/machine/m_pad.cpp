// m_pad.cpp
// NSMBW .text: 0x8016F330 - 0x8016F880

#include "m_pad.h"

#include <egg/core/eggController.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>
#include <slu/relocate.hpp>
#include <slu/to_string.hpp>
#include <utility>

namespace mPad {

/* 0x80377F88 */
std::array<EGG::Controller*, PAD_COUNT> g_core;

slu::enum_array<EGG::Controller*, CH_e> g_coreUnordered;

constinit std::array<CH_e, PAD_COUNT>   g_channel = [] {
    std::array<CH_e, PAD_COUNT> arr{};
    for (int i = 0; i < PAD_COUNT; i++) {
        arr[i] = static_cast<CH_e>(i);
    }
    return arr;
}();

[[nsmbw_data(0x8042A740)]]
EGG::CoreControllerMgr* g_padMg;

[[nsmbw_data(0x8042A744)]]
PadID g_currentCoreID;

[[nsmbw_data(0x8042A748)]]
EGG::Controller* g_currentCore;

[[nsmbw_data(0x8042A74C)]] [[gnu::weak]]
bool                        REMOVED(g_IsConnected)[4];

slu::enum_array<bool, CH_e> g_IsConnected = {
    REMOVED(g_IsConnected)[0], REMOVED(g_IsConnected)[1], REMOVED(g_IsConnected)[2],
    REMOVED(g_IsConnected)[3]
};

[[nsmbw_data(0x8042A750)]]
u32 g_PadFrame;

[[nsmbw(0x8042A754)]] [[gnu::weak]]
bool REMOVED(s_WPADInfoAvailable)[4];

/* 0x8042A754 */
slu::enum_array<bool, CH_e> s_WPADInfoAvailable = {
    REMOVED(s_WPADInfoAvailable)[0], REMOVED(s_WPADInfoAvailable)[1],
    REMOVED(s_WPADInfoAvailable)[2], REMOVED(s_WPADInfoAvailable)[3]
};

[[nsmbw_data(0x8042A758)]]
s32 s_GetWPADInfoInterval;

[[nsmbw_data(0x8042A75C)]]
s32 s_GetWPADInfoCount;

[[nsmbw(0x80378008)]] [[gnu::weak]]
WPADInfo REMOVED(s_WPADInfo)[4];

[[nsmbw(0x80378068)]] [[gnu::weak]]
WPADInfo REMOVED(s_WPADInfoTmp)[4];

/* 0x80378008 */
slu::enum_array<WPADInfo, CH_e> s_WPADInfo = {
    REMOVED(s_WPADInfo)[0], REMOVED(s_WPADInfo)[1], REMOVED(s_WPADInfo)[2], REMOVED(s_WPADInfo)[3]
};

/* 0x80378068 */
slu::enum_array<WPADInfo, CH_e> s_WPADInfoTmp = {
    REMOVED(s_WPADInfoTmp)[0], REMOVED(s_WPADInfoTmp)[1], REMOVED(s_WPADInfoTmp)[2],
    REMOVED(s_WPADInfoTmp)[3]
};

[[nsmbw(0x80377FA8)]]
PadAdditionalData_s g_PadAdditionalData[4];

void initWPADInfo();

/* 0x8016F640 */
void clearWPADInfo(CH_e chan);

/* 0x8016F710 */
int getWPADInfoAsync(CH_e chan);

[[nsmbw(0x8016F330)]]
void create() {
    g_padMg = EGG::CoreControllerMgr::instance();
    initWPADInfo();
    beginPad();
    for (std::size_t i = 0; i < PAD_COUNT; i++) {
        g_core[i] = g_coreUnordered[g_channel[i]];
    }
    endPad();
}

[[nsmbw(0x8016F360)]]
void beginPad() {
    g_PadFrame++;

    g_padMg->beginFrame();
    auto* gcPadMg = EGG::GCControllerMgr::instance();
    gcPadMg->beginFrame();

    // Normal Wii Remote channels
    for (int i = 0; i < 4; i++) {
        auto                 ch   = static_cast<CH_e>(i);
        EGG::CoreController* core = g_padMg->getNthController(i);
        g_coreUnordered[ch]       = core;

        if (!core->connected()) {
            if (!g_IsConnected[ch]) {
                continue;
            }

            core->mStatus->init();
            core->sceneReset();

            g_PadAdditionalData[i] = {};

            clearWPADInfo(ch);

            g_IsConnected[ch] = false;
            continue;
        }

        mVec2_c x              = {core->mStatus->acc_vertical.x, core->mStatus->acc_vertical.y};
        mVec2_c y              = x - g_PadAdditionalData[i].mAccVertical[0];
        mVec2_c z              = y - g_PadAdditionalData[i].mAccVertical[1];
        g_PadAdditionalData[i] = {x, y, z};

        g_IsConnected[ch]      = true;

        if (s_GetWPADInfoInterval != 0 &&
            (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == i ||
             (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
            getWPADInfoAsync(ch);
        }
    }

    // Classic Controller channels
    for (int i = 0; i < 4; i++) {
        auto                    ch = static_cast<CH_e>(i + std::to_underlying(CH_e::CHAN_CL_0));
        EGG::ClassicController* classic = g_padMg->getNthClassic(i);
        g_coreUnordered[ch]             = classic;

        g_IsConnected[ch] = g_IsConnected[static_cast<CH_e>(i)] && classic->connected();
        if (!g_IsConnected[ch]) {
            continue;
        }

        if (s_GetWPADInfoInterval != 0 &&
            (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == std::to_underlying(ch) ||
             (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
            // Fake WPAD info
            s_WPADInfo[ch] = {
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
            s_WPADInfoAvailable[ch] = true;
        }
    }

    // GameCube Controller channels
    for (int i = 0; i < 4; i++) {
        auto               ch   = static_cast<CH_e>(i + std::to_underlying(CH_e::CHAN_GC_0));
        EGG::GCController* core = gcPadMg->getNthController(i);
        g_coreUnordered[ch]     = core;

        g_IsConnected[ch]       = core->connected();
        if (!g_IsConnected[ch]) {
            continue;
        }

        if (s_GetWPADInfoInterval != 0 &&
            (s_GetWPADInfoInterval == 1 || s_GetWPADInfoCount == std::to_underlying(ch) ||
             (s_GetWPADInfoInterval < 4 && ((s_GetWPADInfoCount & 1) == (i & 1))))) {
            // Fake WPAD info
            s_WPADInfo[ch] = {
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
            s_WPADInfoAvailable[ch] = true;
        }
    }

    if (s_GetWPADInfoInterval <= s_GetWPADInfoCount++) {
        s_GetWPADInfoCount = 0;
    }

    setCurrentChannel(g_currentCoreID);
}

[[nsmbw(0x8016F550)]]
void endPad() {
    g_padMg->endFrame();
    EGG::GCControllerMgr::instance()->endFrame();
}

[[nsmbw(0x8016F570)]]
PadID setCurrentChannel(
    PadID id
) {
    if (std::exchange(g_currentCore, g_coreUnordered[g_channel[id]]) !=
        g_coreUnordered[g_channel[id]]) {
        OS_REPORT("New current core: %s\n", slu::to_string(g_channel[id]));
    }
    return std::exchange(g_currentCoreID, id);
}

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
    for (int i = 0; i < CHAN_COUNT; i++) {
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
    const std::array<CH_e, PAD_COUNT>& order
) {
    g_channel = order;
    for (int i = 0; i < PAD_COUNT; i++) {
        g_core[i] = g_coreUnordered[g_channel[i]];
    }
    setCurrentChannel(g_currentCoreID);
}

void setPlayerOrder(
    PadID id, CH_e chan
) {
    OS_REPORT("Register player #%d: %s\n", id, slu::to_string(chan));

    g_channel[id] = chan;
    g_core[id]    = g_coreUnordered[chan];
    g_currentCore = g_core[g_currentCoreID];
}

PATCH_REFERENCES(
    &g_core, //
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
    s_WPADInfo.data(), //
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
    s_WPADInfoTmp.data(), //
    {
        {0x8016F6F6, R_PPC_ADDR16_HA},
        {0x8016F6FA, R_PPC_ADDR16_LO},
        {0x8016F71A, R_PPC_ADDR16_HA},
        {0x8016F72A, R_PPC_ADDR16_LO},
    }
);

} // namespace mPad
