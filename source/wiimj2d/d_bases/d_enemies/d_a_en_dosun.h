#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnDosun_c : public dEn_c {
    SIZE_ASSERT(0x5F0);
    VTABLE(0x060, fBase_c, 0x80AE8228);
    // 0x80AE8158 g_profile_EN_DOSUN
    // 0x809F5A90 daEnDosun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDosun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809F6830
     * executeState:    0x809F6870
     * finalizeState:   0x809F6860
     */
    sState_Extern(0x80B14350, daEnDosun_c, UpWait);

    /*
     * initializeState: 0x809F6910
     * executeState:    0x809F6940
     * finalizeState:   0x809F6930
     */
    sState_Extern(0x80B14390, daEnDosun_c, DownMoveWait);

    /*
     * initializeState: 0x809F69B0
     * executeState:    0x809F69E0
     * finalizeState:   0x809F69D0
     */
    sState_Extern(0x80B143D0, daEnDosun_c, PuruMove);

    /*
     * initializeState: 0x809F6A50
     * executeState:    0x809F6A80
     * finalizeState:   0x809F6A70
     */
    sState_Extern(0x80B14410, daEnDosun_c, DownMove_Kameck);

    /*
     * initializeState: 0x809F6AF0
     * executeState:    0x809F6B10
     * finalizeState:   0x809F6B00
     */
    sState_Extern(0x80B14450, daEnDosun_c, DownMove);

    /*
     * initializeState: 0x809F6C90
     * executeState:    0x809F6CB0
     * finalizeState:   0x809F6CA0
     */
    sState_Extern(0x80B14490, daEnDosun_c, DownWait);

    /*
     * initializeState: 0x809F6D30
     * executeState:    0x809F6D50
     * finalizeState:   0x809F6D40
     */
    sState_Extern(0x80B144D0, daEnDosun_c, UpMove);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809F6DC0
     * executeState:    VT+0x17C 0x809F6ED0
     * finalizeState:   VT+0x180 0x809F6EC0
     */
    sState_ExternVirtual(0x80B1450C, daEnDosun_c, DieFall);

    /*
     * initializeState: VT+0x1FC 0x809F6FE0
     * executeState:    VT+0x200 0x809F7050
     * finalizeState:   VT+0x204 0x809F7040
     */
    sState_ExternVirtual(0x80B1454C, daEnDosun_c, Ice);
};

class daEnBigDosun_c : public daEnDosun_c {
    SIZE_ASSERT(0x5F0);
    // 0x80AE8164 g_profile_EN_BIGDOSUN
    // 0x809F5B20 daEnDosun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigDosun_c();
};
