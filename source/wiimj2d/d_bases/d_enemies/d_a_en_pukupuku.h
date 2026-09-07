#pragma once

#include "d_enemy.h"

class daEnPuku_c : public dEn_c {
    SIZE_ASSERT(0xEC8);
    VTABLE(0x060, fBase_c, 0x80B03680);
    // 0x80B03600 g_profile_EN_PUKUPUKU
    // 0x80A88620 daEnPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xEC8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A8AB90
     * executeState:    0x80A8ABB0
     * finalizeState:   0x80A8ABA0
     */
    sState_Extern(0x80B1A0F0, daEnPuku_c, Swim);

    /*
     * initializeState: 0x80A8ADC0
     * executeState:    0x80A8ADE0
     * finalizeState:   0x80A8ADD0
     */
    sState_Extern(0x80B1A130, daEnPuku_c, SrcSwim);

    /*
     * initializeState: 0x80A8B0B0
     * executeState:    0x80A8B0E0
     * finalizeState:   0x80A8B0D0
     */
    sState_Extern(0x80B1A170, daEnPuku_c, HellSrcSwim);

    /*
     * initializeState: 0x80A8B240
     * executeState:    0x80A8B2B0
     * finalizeState:   0x80A8B2A0
     */
    sState_Extern(0x80B1A1B0, daEnPuku_c, HellSrcReturn);

    /*
     * initializeState: 0x80A8B400
     * executeState:    0x80A8B420
     * finalizeState:   0x80A8B410
     */
    sState_Extern(0x80B1A1F0, daEnPuku_c, ReverseSrcSwim);

    /*
     * initializeState: 0x80A8B690
     * executeState:    0x80A8B6B0
     * finalizeState:   0x80A8B6A0
     */
    sState_Extern(0x80B1A230, daEnPuku_c, WaterWait);

    /*
     * initializeState: 0x80A8B7D0
     * executeState:    0x80A8B820
     * finalizeState:   0x80A8B810
     */
    sState_Extern(0x80B1A270, daEnPuku_c, WaterMove);

    /*
     * initializeState: 0x80A8B940
     * executeState:    0x80A8B990
     * finalizeState:   0x80A8B980
     */
    sState_Extern(0x80B1A2B0, daEnPuku_c, LrSwim);

    /*
     * initializeState: 0x80A8BAB0
     * executeState:    0x80A8BAE0
     * finalizeState:   0x80A8BAD0
     */
    sState_Extern(0x80B1A2F0, daEnPuku_c, LrTurnSwim);

    /*
     * initializeState: 0x80A8BB90
     * executeState:    0x80A8BBE0
     * finalizeState:   0x80A8BBD0
     */
    sState_Extern(0x80B1A330, daEnPuku_c, LrSrcSwim);

    /*
     * initializeState: 0x80A8BD00
     * executeState:    0x80A8BD60
     * finalizeState:   0x80A8BD50
     */
    sState_Extern(0x80B1A370, daEnPuku_c, EscapeSwim);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80A8BE00
     * executeState:    VT+0x17C 0x80A8BEA0
     * finalizeState:   VT+0x180 0x80A8BE90
     */
    sState_ExternVirtual(0x80B1A3AC, daEnPuku_c, DieFall);

    /*
     * initializeState: VT+0x1C0 0x80A8BF40
     * executeState:    VT+0x1C4 0x80A8BF60
     * finalizeState:   VT+0x1C8 0x80A8BF50
     */
    sState_ExternVirtual(0x80B1A3EC, daEnPuku_c, DieOther);

    /*
     * initializeState: VT+0x1E4 0x80A8BF70
     * executeState:    VT+0x1E8 0x80A8C0D0
     * finalizeState:   VT+0x1EC 0x80A8C0C0
     */
    sState_ExternVirtual(0x80B1A42C, daEnPuku_c, EatOut);

    /*
     * initializeState: VT+0x1FC 0x80A8C380
     * executeState:    VT+0x200 0x80A8C3D0
     * finalizeState:   VT+0x204 0x80A8C3C0
     */
    sState_ExternVirtual(0x80B1A46C, daEnPuku_c, Ice);
};

class daEnMiddlePuku_c : public daEnPuku_c {
    SIZE_ASSERT(0xEC8);
    // 0x80B0360C g_profile_EN_MIDDLE_PUKU
    // 0x80A886E0 daEnMiddlePuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMiddlePuku_c();
};

class daEnPukuCoin_c : public daEnPuku_c {
    SIZE_ASSERT(0xEC8);
    // 0x80B03618 g_profile_EN_PUKUCOIN
    // 0x80A887A0 daEnPukuCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPukuCoin_c();
};

class daEnTogePuku_c : public daEnPuku_c {
    SIZE_ASSERT(0xEC8);
    // 0x80B03624 g_profile_EN_TOGEPUKU
    // 0x80A88860 daEnTogePuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTogePuku_c();
};
