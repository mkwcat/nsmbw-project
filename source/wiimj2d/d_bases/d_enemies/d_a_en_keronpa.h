#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKeronpa_c : public dEn_c {
    SIZE_ASSERT(0xA58);
    VTABLE(0x060, fBase_c, 0x80AF6060);
    // 0x80AF5FC0 g_profile_EN_KERONPA
    // 0x80A45FB0 daEnKeronpa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A47640 */
    daEnKeronpa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xA58);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A47A50
     * executeState:    0x80A47BA0
     * finalizeState:   0x80A47B90
     */
    sState_Extern(0x80B178F0, daEnKeronpa_c, Move);

    /*
     * initializeState: 0x80A47D00
     * executeState:    0x80A47D80
     * finalizeState:   0x80A47D70
     */
    sState_Extern(0x80B17930, daEnKeronpa_c, AttackSt);

    /*
     * initializeState: 0x80A47DF0
     * executeState:    0x80A47E70
     * finalizeState:   0x80A47E60
     */
    sState_Extern(0x80B17970, daEnKeronpa_c, AttackMd);

    /*
     * initializeState: 0x80A47F10
     * executeState:    0x80A47F60
     * finalizeState:   0x80A47F50
     */
    sState_Extern(0x80B179B0, daEnKeronpa_c, AttackMdBoyon);

    /*
     * initializeState: 0x80A48000
     * executeState:    0x80A48030
     * finalizeState:   0x80A48020
     */
    sState_Extern(0x80B179F0, daEnKeronpa_c, Attack);

    /*
     * initializeState: 0x80A48150
     * executeState:    0x80A48180
     * finalizeState:   0x80A48170
     */
    sState_Extern(0x80B17A30, daEnKeronpa_c, Explode);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80A477A0
     * executeState:    VT+0x170 0x80A47860
     * finalizeState:   VT+0x174 0x80A47850
     */
    sState_ExternVirtual(0x80B17A6C, daEnKeronpa_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80A478B0
     * executeState:    VT+0x17C 0x80A479D0
     * finalizeState:   VT+0x180 0x80A479C0
     */
    sState_ExternVirtual(0x80B17AAC, daEnKeronpa_c, DieFall);

    /*
     * initializeState: VT+0x184 0x80A47A20
     * executeState:    VT+0x188 0x80A47A40
     * finalizeState:   VT+0x18C 0x80A47A30
     */
    sState_ExternVirtual(0x80B17AEC, daEnKeronpa_c, DieBigFall);
};
