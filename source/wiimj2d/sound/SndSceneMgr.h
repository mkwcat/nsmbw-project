#pragma once

class SndSceneMgr
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8019BB60 @unofficial */
    void setGameSetupTrack(int track);

    /* 0x8019C010 @unofficial */
    void setMiniGameTrack(int track);

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
