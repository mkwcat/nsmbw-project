#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnManholeChoropu_c : public dEn_c {
    SIZE_ASSERT(0x710);
    VTABLE(0x060, fBase_c, 0x80AFAD98);
    // 0x80AFACC8 g_profile_EN_MANHOLE_CHOROPU
    // 0x80A603F0 daEnManholeChoropu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnManholeChoropu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x710);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A61430
     * executeState:    0x80A614E0
     * finalizeState:   0x80A614D0
     */
    sState_Extern(0x80B185F8, daEnManholeChoropu_c, Hide);

    /*
     * initializeState: 0x80A61550
     * executeState:    0x80A61630
     * finalizeState:   0x80A61620
     */
    sState_Extern(0x80B18638, daEnManholeChoropu_c, AppearLittle);

    /*
     * initializeState: 0x80A617A0
     * executeState:    0x80A61830
     * finalizeState:   0x80A61820
     */
    sState_Extern(0x80B18678, daEnManholeChoropu_c, Search);

    /*
     * initializeState: 0x80A61910
     * executeState:    0x80A61A10
     * finalizeState:   0x80A61A00
     */
    sState_Extern(0x80B186B8, daEnManholeChoropu_c, AppearFull);

    /*
     * initializeState: 0x80A61B50
     * executeState:    0x80A61C30
     * finalizeState:   0x80A61C20
     */
    sState_Extern(0x80B186F8, daEnManholeChoropu_c, Attack);

    /*
     * initializeState: 0x80A61D80
     * executeState:    0x80A61E40
     * finalizeState:   0x80A61E30
     */
    sState_Extern(0x80B18738, daEnManholeChoropu_c, Disappear);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80A62120
     * executeState:    VT+0x17C 0x80A621F0
     * finalizeState:   VT+0x180 0x80A621E0
     */
    sState_ExternVirtual(0x80B18774, daEnManholeChoropu_c, DieFall);

    /*
     * initializeState: VT+0x16C 0x80A62000
     * executeState:    VT+0x170 0x80A620D0
     * finalizeState:   VT+0x174 0x80A620C0
     */
    sState_ExternVirtual(0x80B187B4, daEnManholeChoropu_c, DieFumi);

    /*
     * initializeState: VT+0x1CC 0x80A62240
     * executeState:    VT+0x1D0 0x80A622F0
     * finalizeState:   VT+0x1D4 0x80A622A0
     */
    sState_ExternVirtual(0x80B187F4, daEnManholeChoropu_c, EatIn);

    /*
     * initializeState: VT+0x1FC 0x80A625A0
     * executeState:    VT+0x200 0x80A625C0
     * finalizeState:   VT+0x204 0x80A625B0
     */
    sState_ExternVirtual(0x80B18834, daEnManholeChoropu_c, Ice);
};
