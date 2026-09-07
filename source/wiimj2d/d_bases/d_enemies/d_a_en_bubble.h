#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBubble_c : public dEn_c {
    SIZE_ASSERT(0xB80);
    VTABLE(0x060, fBase_c, 0x80ADF028);
    // 0x80ADEF88 g_profile_EN_BUBBLE
    // 0x809D0450 daEnBubble_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBubble_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xB80);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809D1BC0
     * executeState:    0x809D1C10
     * finalizeState:   0x809D1C00
     */
    sState_Extern(0x80B12F30, daEnBubble_c, UpMove);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809D1E10
     * executeState:    VT+0x17C 0x809D1E80
     * finalizeState:   VT+0x180 0x809D1E70
     */
    sState_ExternVirtual(0x80B12F6C, daEnBubble_c, DieFall);

    /*
     * initializeState: VT+0x184 0x809D1F40
     * executeState:    VT+0x188 0x809D1F60
     * finalizeState:   VT+0x18C 0x809D1F50
     */
    sState_ExternVirtual(0x80B12FAC, daEnBubble_c, DieBigFall);
};
