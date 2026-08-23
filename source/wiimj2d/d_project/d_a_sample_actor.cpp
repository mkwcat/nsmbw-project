// d_a_sample_actor.cpp
// nsmbw-project

#include "d_a_sample_actor.h"

dBaseActorProfile_s g_profile_SAMPLE_ACTOR{
    {{
        .mClassInit = []() -> fBase_c* {
            return new daSampleActor_c();
        },
        .mExecuteOrder = 800,
        .mDrawOrder    = 800,
    }},
    .mActorProps = 0,
};
