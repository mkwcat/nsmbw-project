#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBasa_c : public dEn_c {
    SIZE_ASSERT(0x8A8);
    VTABLE(0x060, fBase_c, 0x80AD7588);
    // 0x80AD74F8 g_profile_EN_BASABASA
    // 0x809AD060 daEnBasa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBasa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x8A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809AE5B0
     * executeState:    0x809AE720
     * finalizeState:   0x809AE710
     */
    sState_Extern(0x80B11B78, daEnBasa_c, Wait);

    /*
     * initializeState: 0x809AEB90
     * executeState:    0x809AEC80
     * finalizeState:   0x809AEC70
     */
    sState_Extern(0x80B11BB8, daEnBasa_c, Drop);

    /*
     * initializeState: 0x809AEE00
     * executeState:    0x809AEF70
     * finalizeState:   0x809AEF60
     */
    sState_Extern(0x80B11BF8, daEnBasa_c, Fly);

    /*
     * initializeState: 0x809AF0E0
     * executeState:    0x809AF110
     * finalizeState:   0x809AF100
     */
    sState_Extern(0x80B11C38, daEnBasa_c, Escape);

    /*
     * initializeState: 0x809AE880
     * executeState:    0x809AE9C0
     * finalizeState:   0x809AE9B0
     */
    sState_Extern(0x80B11C78, daEnBasa_c, GroupWait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x809AF160
     * executeState:    VT+0x170 0x809AF200
     * finalizeState:   VT+0x174 0x809AF1F0
     */
    sState_ExternVirtual(0x80B11CB4, daEnBasa_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x809AF2E0
     * executeState:    VT+0x17C 0x809AF3A0
     * finalizeState:   VT+0x180 0x809AF390
     */
    sState_ExternVirtual(0x80B11CF4, daEnBasa_c, DieFall);
};
