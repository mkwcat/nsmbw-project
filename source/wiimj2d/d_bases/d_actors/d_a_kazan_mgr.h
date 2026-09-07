#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKazanMgr_c : public dActorState_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x809623E8);
    // 0x809623D8 g_profile_KAZAN_MGR
    // 0x8081DA10 daKazanMgr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKazanMgr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8081DE10
     * executeState:    0x8081DE60
     * finalizeState:   0x8081DE50
     */
    sState_Extern(0x80999E08, daKazanMgr_c, Ready);

    /*
     * initializeState: 0x8081DEF0
     * executeState:    0x8081DF80
     * finalizeState:   0x8081DF70
     */
    sState_Extern(0x80999E48, daKazanMgr_c, Wait);

    /*
     * initializeState: 0x8081E030
     * executeState:    0x8081E060
     * finalizeState:   0x8081E050
     */
    sState_Extern(0x80999E88, daKazanMgr_c, Volcano);

    /*
     * initializeState: 0x8081E090
     * executeState:    0x8081E0B0
     * finalizeState:   0x8081E0A0
     */
    sState_Extern(0x80999EC8, daKazanMgr_c, VolcanoEd);

    /*
     * initializeState: 0x8081E0E0
     * executeState:    0x8081E150
     * finalizeState:   0x8081E140
     */
    sState_Extern(0x80999F08, daKazanMgr_c, Make);

    /*
     * initializeState: 0x8081E210
     * executeState:    0x8081E230
     * finalizeState:   0x8081E220
     */
    sState_Extern(0x80999F48, daKazanMgr_c, UsualWait);

    /*
     * initializeState: 0x8081E2A0
     * executeState:    0x8081E310
     * finalizeState:   0x8081E300
     */
    sState_Extern(0x80999F88, daKazanMgr_c, UsualMake);
};
