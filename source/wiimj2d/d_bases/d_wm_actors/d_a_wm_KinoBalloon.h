#pragma once

#include "d_wm_demo_actor.h"

class daWmKinoBalloon_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x208);
    VTABLE(0x060, fBase_c, 0x80983920);
    // 0x809838E4 g_profile_WM_KINOBALLOON
    // 0x808D78C0 daWmKinoBalloon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D78F0 */
    daWmKinoBalloon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x208);

public:
    // Static Methods
    // ^^^^^^

    /* 0x808D8560 */
    static void balloonRemove();

    /* 0x808D85E0 */
    static void balloonAppear();

    /* 0x808D8720 */
    static void UNDEF_808D8720();
};
