#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnCrasher_c : public dEn_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80AE5508);
    // 0x80AE5498 g_profile_EN_CRASHER
    // 0x809EA0F0 daEnCrasher_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCrasher_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809EB7C0
     * executeState:    0x809EB840
     * finalizeState:   0x809EB830
     */
    sState_Extern(0x80B13CE8, daEnCrasher_c, Walk);

    /*
     * initializeState: 0x809EBAA0
     * executeState:    0x809EBAE0
     * finalizeState:   0x809EBAD0
     */
    sState_Extern(0x80B13D28, daEnCrasher_c, Turn);

    /*
     * initializeState: 0x809EBBC0
     * executeState:    0x809EBC30
     * finalizeState:   0x809EBC20
     */
    sState_Extern(0x80B13D68, daEnCrasher_c, Wait);

    /*
     * initializeState: 0x809EBED0
     * executeState:    0x809EBF70
     * finalizeState:   0x809EBF60
     */
    sState_Extern(0x80B13DA8, daEnCrasher_c, AttackJump);

    /*
     * initializeState: 0x809EC090
     * executeState:    0x809EC130
     * finalizeState:   0x809EC110
     */
    sState_Extern(0x80B13DE8, daEnCrasher_c, AttackWalk);

    /*
     * initializeState: 0x809EC3F0
     * executeState:    0x809EC440
     * finalizeState:   0x809EC430
     */
    sState_Extern(0x80B13E28, daEnCrasher_c, ChangeWalkWait);

    /*
     * initializeState: 0x809EC500
     * executeState:    0x809EC560
     * finalizeState:   0x809EC550
     */
    sState_Extern(0x80B13E68, daEnCrasher_c, Damege);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x809EC650
     * executeState:    VT+0x170 0x809EC6B0
     * finalizeState:   VT+0x174 0x809EC6A0
     */
    sState_ExternVirtual(0x80B13EA4, daEnCrasher_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x809EC750
     * executeState:    VT+0x17C 0x809EC7C0
     * finalizeState:   VT+0x180 0x809EC7B0
     */
    sState_ExternVirtual(0x80B13EE4, daEnCrasher_c, DieFall);
};
