#pragma once

#include "d_a_en_togezo_base.h"
#include "s_State.h"

class daEnTogezo_c : public daEnTogezoBase_c {
    SIZE_ASSERT(0x9E0);
    VTABLE(0x060, fBase_c, 0x80B0C15C);
    // 0x80B0C150 g_profile_EN_TOGEZO
    // 0x80AB7380 daEnTogezo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTogezo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x9C4, 0x9E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AB7A40
     * executeState:    0x80AB7B50
     * finalizeState:   0x80AB7A50
     */
    sState_Extern(0x80B1BD98, daEnTogezo_c, Hold_Jugem);
};
