#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daElasticKinoko_c : public dActorState_c {
    SIZE_ASSERT(0x538);
    VTABLE(0x060, fBase_c, 0x80958E78);
    // 0x80958E48 g_profile_ELASTIC_KINOKO
    // 0x807E53C0 daElasticKinoko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daElasticKinoko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x538);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E6000
     * executeState:    0x807E6090
     * finalizeState:   0x807E6080
     */
    sState_Extern(0x80997ED8, daElasticKinoko_c, MoveUpper);

    /*
     * initializeState: 0x807E6140
     * executeState:    0x807E6170
     * finalizeState:   0x807E6160
     */
    sState_Extern(0x80997F18, daElasticKinoko_c, WaitUpper);

    /*
     * initializeState: 0x807E61A0
     * executeState:    0x807E6230
     * finalizeState:   0x807E6220
     */
    sState_Extern(0x80997F58, daElasticKinoko_c, MoveUnder);

    /*
     * initializeState: 0x807E62E0
     * executeState:    0x807E6310
     * finalizeState:   0x807E6300
     */
    sState_Extern(0x80997F98, daElasticKinoko_c, WaitUnder);

    /*
     * initializeState: 0x807E6340
     * executeState:    0x807E6360
     * finalizeState:   0x807E6350
     */
    sState_Extern(0x80997FD8, daElasticKinoko_c, SearchID);

    /*
     * initializeState: 0x807E6370
     * executeState:    0x807E63D0
     * finalizeState:   0x807E63C0
     */
    sState_Extern(0x80998018, daElasticKinoko_c, ParentMoveUpper);

    /*
     * initializeState: 0x807E6490
     * executeState:    0x807E6510
     * finalizeState:   0x807E6500
     */
    sState_Extern(0x80998058, daElasticKinoko_c, ParentWaitUpper);

    /*
     * initializeState: 0x807E65B0
     * executeState:    0x807E6610
     * finalizeState:   0x807E6600
     */
    sState_Extern(0x80998098, daElasticKinoko_c, ParentMoveUnder);

    /*
     * initializeState: 0x807E66D0
     * executeState:    0x807E6750
     * finalizeState:   0x807E6740
     */
    sState_Extern(0x809980D8, daElasticKinoko_c, ParentWaitUnder);
};
