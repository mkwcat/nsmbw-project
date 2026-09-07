#pragma once

#include "d_enemy.h"

class daEnKanon_c : public dEn_c {
    SIZE_ASSERT(0x880);
    VTABLE(0x060, fBase_c, 0x80AF55B8);
    // 0x80AF54A0 g_profile_EN_KARON
    // 0x80A41110 daEnKanon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKanon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x880);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A43160
     * executeState:    0x80A431D0
     * finalizeState:   0x80A431C0
     */
    sState_Extern(0x80B17568, daEnKanon_c, Walk);

    /*
     * initializeState: 0x80A43360
     * executeState:    0x80A433A0
     * finalizeState:   0x80A43390
     */
    sState_Extern(0x80B175A8, daEnKanon_c, Turn);

    /*
     * initializeState: 0x80A43470
     * executeState:    0x80A434E0
     * finalizeState:   0x80A434D0
     */
    sState_Extern(0x80B175E8, daEnKanon_c, FumiStop);

    /*
     * initializeState: 0x80A43570
     * executeState:    0x80A43610
     * finalizeState:   0x80A43600
     */
    sState_Extern(0x80B17628, daEnKanon_c, Damage);

    /*
     * initializeState: 0x80A43720
     * executeState:    0x80A43760
     * finalizeState:   0x80A43750
     */
    sState_Extern(0x80B17668, daEnKanon_c, Wait);

    /*
     * initializeState: 0x80A43830
     * executeState:    0x80A438C0
     * finalizeState:   0x80A43850
     */
    sState_Extern(0x80B176A8, daEnKanon_c, GetUp);

    /*
     * initializeState: 0x80A43C30
     * executeState:    0x80A43CD0
     * finalizeState:   0x80A43CC0
     */
    sState_Extern(0x80B176E8, daEnKanon_c, SpinDie);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1C0 0x80A43D20
     * executeState:    VT+0x1C4 0x80A43D40
     * finalizeState:   VT+0x1C8 0x80A43D30
     */
    sState_ExternVirtual(0x80B17724, daEnKanon_c, DieOther);

    /*
     * initializeState: VT+0x178 0x80A43D50
     * executeState:    VT+0x17C 0x80A43F60
     * finalizeState:   VT+0x180 0x80A43F50
     */
    sState_ExternVirtual(0x80B17764, daEnKanon_c, DieFall);
};

class daEnBigKanon_c : public daEnKanon_c {
    SIZE_ASSERT(0x880);
    // 0x80AF54AC g_profile_EN_BIGKARON
    // 0x80A41250 daEnBigKanon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigKanon_c();
};
