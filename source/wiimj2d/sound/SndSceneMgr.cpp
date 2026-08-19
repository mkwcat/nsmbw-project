// SndSceneMgr.cpp
// NSMBW .text: 0x8019B500 - 0x8019DE90

#include "SndSceneMgr.h"

[[nsmbw_data(0x8042A788)]]
SndSceneMgr* SndSceneMgr::sInstance;

[[nsmbw(0x8019BB60)]]
void SndSceneMgr::setGameSetupTrack(int track);

[[nsmbw(0x8019BD90)]]
void SndSceneMgr::setBgmStateBit(EBgmState bit);

[[nsmbw(0x8019BE60)]]
void SndSceneMgr::clearBgmStateBit(EBgmState bit);

[[nsmbw(0x8019C010)]]
void SndSceneMgr::setMiniGameTrack(int track);

[[nsmbw(0x8019C610)]]
void SndSceneMgr::startStaffCreditHiscore();

[[nsmbw(0x8019C620)]]
void SndSceneMgr::onPowerImpact();

[[nsmbw(0x8019CDB0)]]
void SndSceneMgr::closeWindow();
