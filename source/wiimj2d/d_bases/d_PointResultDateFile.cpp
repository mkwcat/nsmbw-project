// d_PointResultDateFile.cpp
// NSMBW   d_bases.text:  0x807A3F50 - 0x807A7770

#include "d_bases/d_PointResultDateFile.h"
#include "d_system/d_info.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"

static const SndID::Type PLY_CLEAR_SND[4][2] = {
    {SndID::SE_VOC_MA_GET_PRIZE,  SndID::SE_VOC_MA_CLEAR_MULTI},
    {SndID::SE_VOC_LU_GET_PRIZE,  SndID::SE_VOC_LU_CLEAR_MULTI},
    {SndID::SE_VOC_KO_GET_PRIZE,  SndID::SE_VOC_KO_CLEAR_MULTI},
    {SndID::SE_VOC_KO2_GET_PRIZE, SndID::SE_VOC_KO2_CLEAR_MULTI},
};

[[address(0x807A6680)]]
void dPointResultDateFile_c::executeState_StarOnStage()
{
    if (!mLayout.isAnime()) {
        return;
    }

    dInfo_c *info = dInfo_c::m_instance;
    int firstPlaceCount = 0;

    for (int i = 0; i < 4; i++) {
        if (mPlayerData[i].mRankNum == 0) {
            firstPlaceCount++;
        }
    }

    for (int i = 0; i < 4; i++) {
        if ((mPlayerData[i].mRankNum == 0) && (mPlayerData[i].mIsPlayerEntry != false)) {
            int playerType = mPlayerData[i].mPlayerType;

            int winNum = info->mCoinBattleWin[playerType] + 1;
            if (winNum > 998) {
                winNum = 999;
            }
            info->mCoinBattleWin[playerType] = winNum;

            bool isMultiWin = firstPlaceCount > 1;
            SndAudioMgr::sInstance->startSystemSe(PLY_CLEAR_SND[playerType][isMultiWin], 1);
        }
    }

    mIsRankChange = false;
    mStateMgr.changeState(StateID_GoalDeMoEndWait);
}
