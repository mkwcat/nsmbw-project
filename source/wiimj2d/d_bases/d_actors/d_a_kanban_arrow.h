#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKanbanArrow_c : public dActorState_c {
    SIZE_ASSERT(0x470);
    VTABLE(0x060, fBase_c, 0x80961F80);
    // 0x80961F40 g_profile_AC_KANBAN_ARROW
    // 0x8081C830 daKanbanArrow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKanbanArrow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x470);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8081CBF0
     * executeState:    0x8081CC10
     * finalizeState:   0x8081CC00
     */
    sState_Extern(0x80999D48, daKanbanArrow_c, Wait);
};
