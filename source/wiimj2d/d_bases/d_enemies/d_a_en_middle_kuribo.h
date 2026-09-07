#pragma once

#include "d_a_en_lkuribo_base.h"
#include "s_State.h"

class daEnMiddleKuribo_c : public daEnLkuriboBase_c {
    SIZE_ASSERT(0x770);
    VTABLE(0x060, fBase_c, 0x80AFC568);
    // 0x80AFC4E8 g_profile_EN_MIDDLE_KURIBO
    // 0x80A69C20 daEnMiddleKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMiddleKuribo_c();

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A6A430
     * executeState:    0x80A6A5A0
     * finalizeState:   0x80A6A590
     */
    sState_Extern(0x80B18CF8, daEnMiddleKuribo_c, Born);
};
