#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daCastleLemmyThrowBall_c : public dEn_c {
    SIZE_ASSERT(0x6F8);
    VTABLE(0x060, fBase_c, 0x80957C90);
    // 0x80957C80 g_profile_CASTLE_LEMMY_THROW_BALL
    // 0x807E06A0 daCastleLemmyThrowBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCastleLemmyThrowBall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6F8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2C8 0x807E0CD0
     * executeState:    VT+0x2CC 0x807E0D60
     * finalizeState:   VT+0x2D0 0x807E0D50
     */
    sState_ExternVirtual(0x80997D14, daCastleLemmyThrowBall_c, Move);
};
