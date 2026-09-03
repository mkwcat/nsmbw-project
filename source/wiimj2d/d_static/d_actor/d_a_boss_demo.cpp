// d_a_boss_demo.cpp
// NSMBW .text: 0x8001CBB0 - 0x8001DA50

#include "d_a_boss_demo.h"

#include "d_a_player_demo_manager.h"
#include "d_enemy_boss.h"
#include "f_feature.h"
#include "f_manager.h"

[[nsmbw(0x8001D090)]]
void daBossDemo_c::initializeState_BattleIn() {
    daPyDemoMng_c::mspInstance->releaseDemoMode(1);
    dEnBoss_c* boss = static_cast<dEnBoss_c*>(fManager_c::searchBaseByID(mBossID));
    if (boss) {
        boss->setBattleReady();

        if (fFeat::end_battles_immediately) {
            boss->mpBossLife->mLife = 0;
            boss->deadAllKill();
            boss->setQuakeDead();
            boss->deadProc();
        }
    }
    mBattleEnd = false;
}
