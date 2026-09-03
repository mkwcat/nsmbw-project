#pragma once

#include "d_enemy_boss.h"

class dEnBossKoopaJrBase_c : public dEnBoss_c {
    SIZE_ASSERT(0xC3C); // Assumed
    VTABLE(0x060, fBase_c, 0x80312A48);

public:
    // Structors
    // ^^^^^^

    /* 0x8009AD30 */
    dEnBossKoopaJrBase_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x600, 0xC3C);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8009CAC0
     * executeState:    VT+0x284 0x8009CB40
     * finalizeState:   VT+0x288 0x8009CB30
     */
    sState_ExternVirtual(0x80357B74, dEnBossKoopaJrBase_c, DemoWait);

    /*
     * initializeState: VT+0x390 0x8009CBF0
     * executeState:    VT+0x394 0x8009CC10
     * finalizeState:   VT+0x398 0x8009CC00
     */
    sState_ExternVirtual(0x80357BB4, dEnBossKoopaJrBase_c, DemoAwake);

    /*
     * initializeState: VT+0x39C 0x8009D780
     * executeState:    VT+0x3A0 0x8009D810
     * finalizeState:   VT+0x3A4 0x8009D800
     */
    sState_ExternVirtual(0x80357BF4, dEnBossKoopaJrBase_c, Move);

    /*
     * initializeState: VT+0x3A8 0x8009D2B0
     * executeState:    VT+0x3AC 0x8009D3C0
     * finalizeState:   VT+0x3B0 0x8009D3B0
     */
    sState_ExternVirtual(0x80357C34, dEnBossKoopaJrBase_c, DefaultHitRot);

    /*
     * initializeState: VT+0x3B4 0x8009CC20
     * executeState:    VT+0x3B8 0x8009CED0
     * finalizeState:   VT+0x3BC 0x8009CEC0
     */
    sState_ExternVirtual(0x80357C74, dEnBossKoopaJrBase_c, FumiHitRot);

    /*
     * initializeState: VT+0x3C0 0x8009D010
     * executeState:    VT+0x3C4 0x8009D0A0
     * finalizeState:   VT+0x3C8 0x8009D090
     */
    sState_ExternVirtual(0x80357CB4, dEnBossKoopaJrBase_c, FumiHitRotDamp);

    /*
     * initializeState: VT+0x3CC 0x8009D190
     * executeState:    VT+0x3D0 0x8009D230
     * finalizeState:   VT+0x3D4 0x8009D220
     */
    sState_ExternVirtual(0x80357CF4, dEnBossKoopaJrBase_c, FumiHitRotEnd);

    /*
     * initializeState: VT+0x3D8 0x8009D540
     * executeState:    VT+0x3DC 0x8009D600
     * finalizeState:   VT+0x3E0 0x8009D5F0
     */
    sState_ExternVirtual(0x80357D34, dEnBossKoopaJrBase_c, Fire);

    /*
     * initializeState: VT+0x3E4 0x8009D450
     * executeState:    VT+0x3E8 0x8009D4E0
     * finalizeState:   VT+0x3EC 0x8009D4D0
     */
    sState_ExternVirtual(0x80357D74, dEnBossKoopaJrBase_c, Stoop);

    /*
     * initializeState: VT+0x178 0x8009D880
     * executeState:    VT+0x17C 0x8009D980
     * finalizeState:   VT+0x180 0x8009D970
     */
    sState_ExternVirtual(0x80357DB4, dEnBossKoopaJrBase_c, DieFall);

    /*
     * initializeState: VT+0x16C 0x8009DA50
     * executeState:    VT+0x170 0x8009DA70
     * finalizeState:   VT+0x174 0x8009DA60
     */
    sState_ExternVirtual(0x80357DF4, dEnBossKoopaJrBase_c, DieFumi);
};
