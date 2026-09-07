#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnCarry_c : public dEn_c {
    SIZE_ASSERT(0x524);
    VTABLE(0x60, fBase_c, 0x80302CE0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80026D90
     * executeState:    VT+0x284 0x80026DB0
     * finalizeState:   VT+0x288 0x80026DA0
     */
    sState_ExternVirtual(0x803530B4, daEnCarry_c, Carry);
};
