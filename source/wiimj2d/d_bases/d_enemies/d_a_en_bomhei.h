#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBomhei_c : public dEn_c {
    SIZE_ASSERT(0x760);
    VTABLE(0x060, fBase_c, 0x80ADDB98);
    // 0x80ADDB20 g_profile_EN_BOMHEI
    // 0x809C8D30 daEnBomhei_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBomhei_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0xEC 0x809CA8D0 */
    bool hitCallback_HipAttk(dCc_c* main, dCc_c* other) override;

    /* 0x809C9DD0 */
    void Normal_VsYoshiHitCheck(dCc_c* self, dCc_c* other) override;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x760);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809CB270
     * executeState:    0x809CB400
     * finalizeState:   0x809CB3F0
     */
    sState_Extern(0x80B12A48, daEnBomhei_c, Walk);

    /*
     * initializeState: 0x809CB620
     * executeState:    0x809CB6D0
     * finalizeState:   0x809CB6C0
     */
    sState_Extern(0x80B12A88, daEnBomhei_c, Sleep);

    /*
     * initializeState: 0x809CBBC0
     * executeState:    0x809CBD00
     * finalizeState:   0x809CBCB0
     */
    sState_Extern(0x80B12B08, daEnBomhei_c, Slide);

    /*
     * initializeState: 0x809CBEE0
     * executeState:    0x809CBFB0
     * finalizeState:   0x809CBF70
     */
    sState_Extern(0x80B12B48, daEnBomhei_c, Kick);

    /*
     * initializeState: 0x809CC1A0
     * executeState:    0x809CC270
     * finalizeState:   0x809CC230
     */
    sState_Extern(0x80B12B88, daEnBomhei_c, KickBom);

    /*
     * initializeState: 0x809CC380
     * executeState:    0x809CC4D0
     * finalizeState:   0x809CC4A0
     */
    sState_Extern(0x80B12BC8, daEnBomhei_c, Wakidashi);

    /*
     * initializeState: 0x809CCCC0
     * executeState:    0x809CCDF0
     * finalizeState:   0x809CCDE0
     */
    sState_Extern(0x80B12C08, daEnBomhei_c, Explode);

    /*
     * initializeState: 0x809CB4D0
     * executeState:    0x809CB500
     * finalizeState:   0x809CB4F0
     */
    sState_Extern(0x80B12C48, daEnBomhei_c, Turn);

    /*
     * initializeState: 0x809CC540
     * executeState:    0x809CC650
     * finalizeState:   0x809CC630
     */
    sState_Extern(0x80B12C88, daEnBomhei_c, CannonHop_Upper);

    /*
     * initializeState: 0x809CC790
     * executeState:    0x809CC890
     * finalizeState:   0x809CC870
     */
    sState_Extern(0x80B12CC8, daEnBomhei_c, CannonHop_Under);

    /*
     * initializeState: 0x809CC9D0
     * executeState:    0x809CCA30
     * finalizeState:   0x809CCA20
     */
    sState_Extern(0x80B12D08, daEnBomhei_c, AfterIce);

    /*
     * initializeState: 0x809CCE20
     * executeState:    0x809CCEA0
     * finalizeState:   0x809CCE90
     */
    sState_Extern(0x80B12D48, daEnBomhei_c, InIceLump);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x809CB800
     * executeState:    VT+0x284 0x809CB9D0
     * finalizeState:   VT+0x288 0x809CB910
     */
    sState_ExternVirtual(0x80B12AC4, daEnBomhei_c, Carry);

    /*
     * initializeState: VT+0x1E4 0x809CCBA0
     * executeState:    VT+0x1E8 0x809CCC30
     * finalizeState:   VT+0x1EC 0x809CCC20
     */
    sState_ExternVirtual(0x80B12D84, daEnBomhei_c, EatOut);
};
