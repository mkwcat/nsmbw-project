// SndAudioMgr.cpp
// NSMBW .text: 0x80194A10 - 0x80197440

#include "SndAudioMgr.h"

[[address_data(0x8042A768)]]
SndAudioMgr* SndAudioMgr::sInstance;

[[address(0x801954C0)]]
void SndAudioMgr::startSystemSe(unsigned int sound, u32 param2);

[[address(0x80196FD0)]]
void SndAudioMgr::setIsReplay(bool value);