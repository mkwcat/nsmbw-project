#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBigBlock_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x820);
    VTABLE(0x060, fBase_c, 0x80AD9118);
    // 0x80AD9060 g_profile_EN_BIGBLOCK
    // 0x809B88C0 daEnBigBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigBlock_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x809B90B0 */
    void FUN_809B90B0();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x820);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809B93E0
     * executeState:    0x809B9400
     * finalizeState:   0x809B93F0
     */
    sState_Extern(0x80B121F8, daEnBigBlock_c, Wait);

    /*
     * initializeState: 0x809B94A0
     * executeState:    0x809B94C0
     * finalizeState:   0x809B94B0
     */
    sState_Extern(0x80B12238, daEnBigBlock_c, OffDisp);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2A4 0x809B91E0
     * executeState:    VT+0x2A8 0x809B9200
     * finalizeState:   VT+0x2AC 0x809B91F0
     */
    sState_ExternVirtual(0x80B12274, daEnBigBlock_c, UpMove);

    /*
     * initializeState: VT+0x2B0 0x809B92E0
     * executeState:    VT+0x2B4 0x809B9300
     * finalizeState:   VT+0x2B8 0x809B92F0
     */
    sState_ExternVirtual(0x80B122B4, daEnBigBlock_c, DownMove);
};
