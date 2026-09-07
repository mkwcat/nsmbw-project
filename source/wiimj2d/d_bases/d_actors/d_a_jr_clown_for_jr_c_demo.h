#pragma once

#include "d_base.h"
#include "s_State.h"

class daJrClownForJrCDemo_c : public dBase_c {
    SIZE_ASSERT(0xDE8);
    VTABLE(0x060, fBase_c, 0x8095F960);
    // 0x8095F924 g_profile_JR_CLOWN_FOR_JR_C_DEMO
    // 0x8080EC40 daJrClownForJrCDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8080EC70 */
    daJrClownForJrCDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0xDE8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8080EF50
     * executeState:    VT+0x284 0x8080F0A0
     * finalizeState:   VT+0x288 0x8080F090
     */
    sState_ExternVirtual(0x80999844, daJrClownForJrCDemo_c, DemoWait);
};
