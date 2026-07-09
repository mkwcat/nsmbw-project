// d_project.cpp
// nsmbw-project

#include "d_project.h"

#include "component/c_json.h"
#include "d_player/d_s_boot.h"
#include "d_project/d_exception.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_info.h"
#include "d_system/d_nand_thread.h"
#include "d_system/d_remocon_mng.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_system.h"
#include "machine/m_dvd.h"
#include "machine/m_heap.h"
#include "machine/m_pad.h"
#include "revolution/os/OSError.h"
#include "sound/SndAudioMgr.h"
#include <egg/core/eggController.h>

void dProject_c::preCModuleInit(
    s32 arcEntryNum, ARCHandle* arcHandle
) {
    dException_c::initCallback();

    // Unlock root heaps
    dSys_c::ms_RootHeapMem1->mFlags.resetBit(0);
    dSys_c::ms_RootHeapMem2->mFlags.resetBit(0);

    __DVDEXInit(arcEntryNum, arcHandle);
}

dProject_c::dProject_c() {
    mHeap::ScopeHeap_c scope{0};

    EGG::GCControllerMgr::createInstance();
    EGG::CoreControllerMgr::instance()->initClassic();

    mPad::create();

    static constexpr auto l_asd_info = std::to_array<mDvd::UncompressInfo_c*>({
        &mDvd::s_UncompressInfoSZS,
        &mDvd::s_UncompressInfoLZ,
    });
    mDvd::initAutoStreamDecompInfo(l_asd_info.begin(), l_asd_info.end());

    dRemoconMng_c::m_instance = new dRemoconMng_c(dRemoconMng_c::m_instance);

    dNandThread_c::reinitialize();
    dSaveMng_c::m_instance->refresh();

    dInfo_c::m_instance = new dInfo_c(dInfo_c::m_instance);

    daPyMng_c::initGame();

    SndAudioMgr::sInstance->loadKinopicoSound();

    loadVersionJson();
    OS_REPORT("Project: %s %s\n", m_name, m_version);

    dSys_c::ms_RootHeapMem1->mFlags.setBit(0);
    dSys_c::ms_RootHeapMem2->mFlags.setBit(0);

    dScBoot_c::m_instance->mLoadedSceneSnd = true;
}

void dProject_c::loadVersionJson() {
    if (cJson::DvdReader_c r("/Info/Version.json"); r.startObject()) {
        if (auto key = r.key(); key) {
            std::strncpy(
                m_name, key.string.data(), std::min(key.string.length(), std::size(m_name))
            );
            if (auto value = r.string(); value && r.endObject()) {
                std::strncpy(
                    m_version, value.string.data(),
                    std::min(value.string.length(), std::size(m_version))
                );
                return;
            }
        }
    }

    std::strcpy(m_name, "unknown project");
    std::strcpy(m_version, "(unknown)");
}

int preinit(
    s32 param1, void* param2
) {
    dProject_c::preCModuleInit(param1, static_cast<ARCHandle*>(param2));
    return 0;
}

int main() {
    dProject_c::m_instance = new dProject_c;
    return 0;
}
