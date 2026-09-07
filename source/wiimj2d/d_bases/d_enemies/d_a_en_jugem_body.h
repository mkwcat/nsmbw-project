#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnJugemBody_c : public dEn_c {
    SIZE_ASSERT(0x830);
    VTABLE(0x060, fBase_c, 0x80AF3AB0);
    // 0x80AF3A38 g_profile_EN_JUGEM_BODY
    // 0x80A367B0 daEnJugemBody_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJugemBody_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x830);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A37DD0
     * executeState:    0x80A37DF0
     * finalizeState:   0x80A37DE0
     */
    sState_Extern(0x80B16FD8, daEnJugemBody_c, Move);

    /*
     * initializeState: 0x80A37F20
     * executeState:    0x80A37F70
     * finalizeState:   0x80A37F60
     */
    sState_Extern(0x80B17018, daEnJugemBody_c, ThrowActor);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A37FC0
     * executeState:    VT+0x170 0x80A38050
     * finalizeState:   VT+0x174 0x80A38040
     */
    sState_ExternVirtual(0x80B17054, daEnJugemBody_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A380C0
     * executeState:    VT+0x17C 0x80A38120
     * finalizeState:   VT+0x180 0x80A38110
     */
    sState_ExternVirtual(0x80B17094, daEnJugemBody_c, DieFall);
};
