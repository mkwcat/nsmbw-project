#pragma once

#include <mkwcat/Enum.h>

class SndSceneMgr {
public:
    // Constants
    // ^^^^^^

    /* @unofficial */
    enum class EBgmState {
        MAIN  = 0_bit,
        STAR  = 2_bit,
        YOSHI = 9_bit,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8019BB60 @unofficial */
    void setGameSetupTrack(int track);

    /* 0x8019BD90 @unofficial */
    void setBgmStateBit(EBgmState bit);

    /* 0x8019BE60 @unofficial */
    void clearBgmStateBit(EBgmState bit);

    /* 0x8019C010 @unofficial */
    void setMiniGameTrack(int track);

    /* 0x8019C390 */
    void UNDEF_8019C390(int);

    /* 0x8019C610 */
    void startStaffCreditHiscore();

    /* 0x8019C620 */
    void onPowerImpact();

    /* 0x8019CDB0 */
    void closeWindow();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A788 */ static SndSceneMgr* sInstance;
};

ENUM_ALLOW_BITWISE(SndSceneMgr::EBgmState);
