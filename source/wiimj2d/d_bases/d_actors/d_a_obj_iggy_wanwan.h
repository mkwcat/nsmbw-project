#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjIggyWanwan_c : public dEn_c {
    SIZE_ASSERT(0xB18);
    VTABLE(0x060, fBase_c, 0x80972D90);
    // 0x80972CD0 g_profile_OBJ_IGGY_WANWAN
    // 0x80878720 daObjIggyWanwan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjIggyWanwan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xB18);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8087A420
     * executeState:    0x8087A530
     * finalizeState:   0x8087A520
     */
    sState_Extern(0x8099D470, daObjIggyWanwan_c, DemoWait);

    /*
     * initializeState: 0x8087A610
     * executeState:    0x8087A680
     * finalizeState:   0x8087A670
     */
    sState_Extern(0x8099D4B0, daObjIggyWanwan_c, Wait);

    /*
     * initializeState: 0x8087A750
     * executeState:    0x8087A870
     * finalizeState:   0x8087A860
     */
    sState_Extern(0x8099D4F0, daObjIggyWanwan_c, AttackReady);

    /*
     * initializeState: 0x8087AD20
     * executeState:    0x8087AE10
     * finalizeState:   0x8087AE00
     */
    sState_Extern(0x8099D530, daObjIggyWanwan_c, Attack);

    /*
     * initializeState: 0x8087B060
     * executeState:    0x8087B0C0
     * finalizeState:   0x8087B0B0
     */
    sState_Extern(0x8099D570, daObjIggyWanwan_c, AttackEnd);

    /*
     * initializeState: 0x8087B250
     * executeState:    0x8087B2F0
     * finalizeState:   0x8087B2E0
     */
    sState_Extern(0x8099D5B0, daObjIggyWanwan_c, ChangeDirection);

    /*
     * initializeState: 0x8087B7A0
     * executeState:    0x8087B830
     * finalizeState:   0x8087B820
     */
    sState_Extern(0x8099D5F0, daObjIggyWanwan_c, Grow);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x8087B9F0
     * executeState:    VT+0x17C 0x8087BA80
     * finalizeState:   VT+0x180 0x8087BA70
     */
    sState_ExternVirtual(0x8099D630, daObjIggyWanwan_c, DieFall);
};
