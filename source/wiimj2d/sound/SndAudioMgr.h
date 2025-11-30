#pragma once

#include "SndID.h"
#include <egg/audio/eggAudioMgr.h>
#include <nw4r/snd/SoundArchivePlayer.h>

class SndAudioMgr : public EGG::ExpAudioMgr
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x801954C0 */
    void startSystemSe(SndID::Type sound, u32 param2);

    /* 0x80196740 */
    bool isSndPlaying(SndID::Type sound);

    /* 0x80196FD0 */
    void setIsReplay(bool value);

    void loadKinopicoSound();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x010, 0x5BC);

    /* 0x5BC */ nw4r::snd::SoundArchivePlayer* mpSoundArchivePlayer;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A768 */ static SndAudioMgr* sInstance;
};
