#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnMortonBigPile_c : public dEn_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x80ADA088);
    // 0x80ADA048 g_profile_EN_MORTON_BIGPILE
    // 0x809BAD30 daEnMortonBigPile_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMortonBigPile_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6A8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x809BBA60
     * executeState:    VT+0x284 0x809BBA80
     * finalizeState:   VT+0x288 0x809BBA70
     */
    sState_ExternVirtual(0x80B122F4, daEnMortonBigPile_c, Stop);

    /*
     * initializeState: VT+0x28C 0x809BB650
     * executeState:    VT+0x290 0x809BB6D0
     * finalizeState:   VT+0x294 0x809BB6C0
     */
    sState_ExternVirtual(0x80B12334, daEnMortonBigPile_c, GoWait);

    /*
     * initializeState: VT+0x298 0x809BB750
     * executeState:    VT+0x29C 0x809BB780
     * finalizeState:   VT+0x2A0 0x809BB770
     */
    sState_ExternVirtual(0x80B12374, daEnMortonBigPile_c, GoMove);

    /*
     * initializeState: VT+0x2A4 0x809BB8C0
     * executeState:    VT+0x2A8 0x809BB920
     * finalizeState:   VT+0x2AC 0x809BB910
     */
    sState_ExternVirtual(0x80B123B4, daEnMortonBigPile_c, RetWait);

    /*
     * initializeState: VT+0x2B0 0x809BB9A0
     * executeState:    VT+0x2B4 0x809BB9C0
     * finalizeState:   VT+0x2B8 0x809BB9B0
     */
    sState_ExternVirtual(0x80B123F4, daEnMortonBigPile_c, RetMove);

    /*
     * initializeState: VT+0x2BC 0x809BBAD0
     * executeState:    VT+0x2C0 0x809BBB30
     * finalizeState:   VT+0x2C4 0x809BBB20
     */
    sState_ExternVirtual(0x80B12434, daEnMortonBigPile_c, FadeOut);
};
