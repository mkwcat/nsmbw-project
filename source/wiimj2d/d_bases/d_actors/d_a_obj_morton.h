#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjMorton_c : public dEn_c {
    SIZE_ASSERT(0x7C8);
    VTABLE(0x060, fBase_c, 0x80974CD0);
    // 0x80974C60 g_profile_OBJ_MORTON
    // 0x80882E90 daObjMorton_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80882EC0 */
    daObjMorton_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x7C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80883830
     * executeState:    0x80883850
     * finalizeState:   0x80883840
     */
    sState_Extern(0x8099D9E0, daObjMorton_c, Wait);

    /*
     * initializeState: 0x80883860
     * executeState:    0x80883880
     * finalizeState:   0x80883870
     */
    sState_Extern(0x8099DA20, daObjMorton_c, MoveUp);

    /*
     * initializeState: 0x80883890
     * executeState:    0x808838B0
     * finalizeState:   0x808838A0
     */
    sState_Extern(0x8099DA60, daObjMorton_c, MoveDown);

    /*
     * initializeState: 0x808838C0
     * executeState:    0x80883960
     * finalizeState:   0x80883950
     */
    sState_Extern(0x8099DAA0, daObjMorton_c, DemoWait);

    /*
     * initializeState: 0x808839B0
     * executeState:    0x808839F0
     * finalizeState:   0x808839E0
     */
    sState_Extern(0x8099DAE0, daObjMorton_c, DemoSt);

    /*
     * initializeState: 0x80883AE0
     * executeState:    0x80883B30
     * finalizeState:   0x80883B20
     */
    sState_Extern(0x8099DB20, daObjMorton_c, AttackSide);

    /*
     * initializeState: 0x80883C10
     * executeState:    0x80883CC0
     * finalizeState:   0x80883CB0
     */
    sState_Extern(0x8099DB60, daObjMorton_c, AttackSideWait);

    /*
     * initializeState: 0x80883CF0
     * executeState:    0x80883D30
     * finalizeState:   0x80883D20
     */
    sState_Extern(0x8099DBA0, daObjMorton_c, AttackSideEn);

    /*
     * initializeState: 0x80883D90
     * executeState:    0x80883DD0
     * finalizeState:   0x80883DC0
     */
    sState_Extern(0x8099DBE0, daObjMorton_c, AttackCenter);

    /*
     * initializeState: 0x80883E40
     * executeState:    0x80883E70
     * finalizeState:   0x80883E60
     */
    sState_Extern(0x8099DC20, daObjMorton_c, AttackCenterWait);

    /*
     * initializeState: 0x80883EA0
     * executeState:    0x80883EE0
     * finalizeState:   0x80883ED0
     */
    sState_Extern(0x8099DC60, daObjMorton_c, AttackCenterEn);

    /*
     * initializeState: 0x80883F40
     * executeState:    0x80883F70
     * finalizeState:   0x80883F60
     */
    sState_Extern(0x8099DCA0, daObjMorton_c, Dent);

    /*
     * initializeState: 0x80883FD0
     * executeState:    0x80884000
     * finalizeState:   0x80883FF0
     */
    sState_Extern(0x8099DCE0, daObjMorton_c, DentWait);

    /*
     * initializeState: 0x80884030
     * executeState:    0x80884060
     * finalizeState:   0x80884050
     */
    sState_Extern(0x8099DD20, daObjMorton_c, DentEn);

    /*
     * initializeState: 0x808840C0
     * executeState:    0x808840F0
     * finalizeState:   0x808840E0
     */
    sState_Extern(0x8099DD60, daObjMorton_c, Bulge);

    /*
     * initializeState: 0x80884150
     * executeState:    0x80884180
     * finalizeState:   0x80884170
     */
    sState_Extern(0x8099DDA0, daObjMorton_c, BulgeWait);

    /*
     * initializeState: 0x808841B0
     * executeState:    0x808841E0
     * finalizeState:   0x808841D0
     */
    sState_Extern(0x8099DDE0, daObjMorton_c, BulgeEn);
};
