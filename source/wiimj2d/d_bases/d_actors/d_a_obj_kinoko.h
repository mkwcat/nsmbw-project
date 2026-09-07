#pragma once

#include "d_actor.h"

class daObjKinoko_c : public dActor_c {
    SIZE_ASSERT(0x650);
    VTABLE(0x060, fBase_c, 0x8097421C);
    // 0x80974168 g_profile_OBJ_KINOKO
    // 0x8087F510 daObjKinoko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjKinoko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x650);
};
