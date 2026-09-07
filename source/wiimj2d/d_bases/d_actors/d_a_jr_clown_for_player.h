#pragma once

#include "d_bg_ctr.h"
#include "d_enemy_jr_clown_base.h"

class daJrClownForPlayer_c : public dEnJrClownBase_c {
    SIZE_ASSERT(0xFD0);
    VTABLE(0x060, fBase_c, 0x8095FEE8);
    // 0x8095FDD0 g_profile_JR_CLOWN_FOR_PLAYER
    // 0x8080F910 daJrClownForPlayer_c_classInit

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80810D80 */
    bool PlayerEnter(dAcPy_c* py);

public:
    // Static Methods
    // ++++++

    static const char* getStepOnEffectName(const dAcPy_c* py);

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x3B4 0x808116B0 */
    void setPlayerEmblem(int playerNo);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0xD48, 0xD78);

    /* 0xD78 */ dBg_ctr_c mPlrCollider;

    FILL(0xE5C, 0xFD0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808122A0
     * executeState:    0x80812320
     * finalizeState:   0x80812310
     */
    sState_Extern(0x80999908, daJrClownForPlayer_c, Drone);

    /*
     * initializeState: 0x808129C0
     * executeState:    0x80812A60
     * finalizeState:   0x80812A50
     */
    sState_Extern(0x80999988, daJrClownForPlayer_c, EndDemo);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80811C00
     * executeState:    VT+0x284 0x80811C50
     * finalizeState:   VT+0x288 0x80811C40
     */
    sState_ExternVirtual(0x80999884, daJrClownForPlayer_c, DemoWait);

    /*
     * initializeState: VT+0x298 0x80811E20
     * executeState:    VT+0x29C 0x80811E70
     * finalizeState:   VT+0x2A0 0x80811E60
     */
    sState_ExternVirtual(0x809998C4, daJrClownForPlayer_c, Move);

    /*
     * initializeState: VT+0x2A4 0x80812520
     * executeState:    VT+0x2A8 0x808125E0
     * finalizeState:   VT+0x2AC 0x808125D0
     */
    sState_ExternVirtual(0x80999944, daJrClownForPlayer_c, Damaged);
};
