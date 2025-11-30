// SndAudioMgr.cpp
// NSMBW .text: 0x80194A10 - 0x80197440

#include "SndAudioMgr.h"

#include "machine/m_dvd.h"
#include <egg/core/eggDvdRipper.h>
#include <nw4r/snd/DvdSoundArchive.h>
#include <revolution/os.h>

[[address_data(0x8042A768)]]
SndAudioMgr* SndAudioMgr::sInstance;

[[address(0x801954C0)]]
void SndAudioMgr::startSystemSe(SndID::Type sound, u32 param2);

[[address(0x80196740)]]
bool SndAudioMgr::isSndPlaying(SndID::Type sound);

[[address(0x80196FD0)]]
void SndAudioMgr::setIsReplay(bool value);

void SndAudioMgr::loadKinopicoSound()
{
    // Allocate memory for the sound data
    u32 bnkSize = 0, waveSize = 0;
    mDvd::getFileSize("/Sound/BANK_SE_VOC_COURSE_KC.brbnk", &bnkSize);
    mDvd::getFileSize("/Sound/GROUP_SE_VOC_COURSE_KC.brwar", &waveSize);
    ASSERT(bnkSize != 0 && waveSize != 0);
    void* bnkData = mHeapMgr.mHeap.Alloc(bnkSize);
    ASSERT(bnkData != nullptr);
    void* waveData = mHeapMgr.mHeap.Alloc(waveSize);
    ASSERT(waveData != nullptr);

    // Load bank data
    bnkData = mDvd::loadToMainRAM(
      "/Sound/BANK_SE_VOC_COURSE_KC.brbnk", (char*) bnkData, nullptr,
      EGG::DvdRipper::EAllocDirection::ALLOC_DIR_TOP, 0, nullptr, nullptr, 0
    );
    ASSERT(bnkData != nullptr);

    waveData = mDvd::loadToMainRAM(
      "/Sound/GROUP_SE_VOC_COURSE_KC.brwar", (char*) waveData, nullptr,
      EGG::DvdRipper::EAllocDirection::ALLOC_DIR_TOP, 0, nullptr, nullptr, 0
    );
    ASSERT(waveData != nullptr);

    nw4r::snd::DvdSoundArchive::RegisterTmpFile(bnkData, waveData);
}
