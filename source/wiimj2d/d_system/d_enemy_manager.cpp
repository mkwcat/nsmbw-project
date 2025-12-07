// d_enemy_manager.cpp
// NSMBW .text: 0x800A7450 - 0x800A7DA0

#include "d_enemy_manager.h"
#include "d_actor.h"
#include "d_bases/d_profile.h"
#include "d_system/d_audio.h"
#include "sound/SndID.h"

[[address_data(0x8042A1F0)]]
dEnemyMng_c* dEnemyMng_c::m_instance;

[[address(0x800A7D30)]]
void dEnemyMng_c::execute();

[[address(0x800A7560)]]
void dEnemyMng_c::spawnYoshiEgg(mVec3_c* pos, int param_2, u32 param_3, s8 param_4, int param_5)
{
    if (param_4 == -1) {
        param_4 = 0xF;
    }

    float xOffset[2] = {4.0, -4.0};
    mVec3_c eggPos = mVec3_c(pos->x + xOffset[param_3 & 1], pos->y, pos->z);

    nw4r::math::VEC2 soundPos;
    dAudio::cvtSndObjctPos(soundPos, eggPos);
    dAudio::g_pSndObjMap->startSound(SndID::SE_PLY_YOSHI_LAY_EGG, soundPos, 0);

    dActor_c::construct(
      dProf::AC_YOSHI_EGG,
      param_5 << 0x10 | param_4 << 0x14 | param_2 | param_3 << 4 | 0x1000, &eggPos,
      nullptr, 0
    );
}
