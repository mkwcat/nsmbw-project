// d_a_en_sample_enemy.cpp
// nsmbw-project

#include "d_a_en_sample_enemy.h"

dBaseActorProfile_s g_profile_EN_SAMPLE_ENEMY = {
    {{
        .mClassInit = []() -> fBase_c* {
            return new daEnSampleEnemy_c();
        },
        .mExecuteOrder = 800,
        .mDrawOrder    = 800,
    }},
    .mActorProps = 0,
};
