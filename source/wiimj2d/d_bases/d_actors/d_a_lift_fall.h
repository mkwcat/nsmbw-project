#pragma once

#include "d_actor_state.h"
#include "d_rc.h"
#include "s_State.h"

class daLiftFall_c : public dActorState_c {
    SIZE_ASSERT(0x598);
    VTABLE(0x060, fBase_c, 0x80967000);
    // 0x80966FE0 g_profile_AC_LIFT_FALL
    // 0x80837370 daLiftFall_c_classInit

public:
    // Instance Methods
    // ^^^^^^

    /* 0x808377B0 */
    bool checkRideStart() const;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x508);

    /* 0x508 */ dRideRoll_c mRc;

    FILL(0x568, 0x598);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808378A0
     * executeState:    0x808378C0
     * finalizeState:   0x808378B0
     */
    sState_Extern(0x8099B0C8, daLiftFall_c, Wait);

    /*
     * initializeState: 0x80837A70
     * executeState:    0x80837AF0
     * finalizeState:   0x80837AE0
     */
    sState_Extern(0x8099B108, daLiftFall_c, Fall);

    /*
     * initializeState: 0x80837940
     * executeState:    0x80837980
     * finalizeState:   0x80837970
     */
    sState_Extern(0x8099B148, daLiftFall_c, Guragura);
};
