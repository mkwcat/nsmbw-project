#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKinokoLift_c : public dActorState_c {
    SIZE_ASSERT(0x1360);
    VTABLE(0x0060, fBase_c, 0x80962B30);
    // 0x80962B20 g_profile_KINOKO_LIFT
    // 0x80820A40 daKinokoLift_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKinokoLift_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x1360);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808218C0
     * executeState:    0x808218E0
     * finalizeState:   0x808218D0
     */
    sState_Extern(0x8099A158, daKinokoLift_c, Move);

    /*
     * initializeState: 0x80821900
     * executeState:    0x80821920
     * finalizeState:   0x80821910
     */
    sState_Extern(0x8099A198, daKinokoLift_c, SearchID);

    /*
     * initializeState: 0x80821930
     * executeState:    0x80821950
     * finalizeState:   0x80821940
     */
    sState_Extern(0x8099A1D8, daKinokoLift_c, MoveChild);
};
