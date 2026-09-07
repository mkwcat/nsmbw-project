#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBigHanachan_c : public dEn_c {
    SIZE_ASSERT(0x938);
    VTABLE(0x060, fBase_c, 0x80AD7ED8);
    // 0x80AD7EC0 g_profile_EN_BIG_HANACHAN
    // 0x809B1EC0 daEnBigHanachan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigHanachan_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x809B28C0 */
    void Normal_VsPlHitCheck(dCc_c* self, dCc_c* other) override;

    /* 0x809B2AD0 */
    void Normal_VsYoshiHitCheck(dCc_c* self, dCc_c* other) override;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x938);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809B3450
     * executeState:    0x809B3520
     * finalizeState:   0x809B3510
     */
    sState_Extern(0x80B11E38, daEnBigHanachan_c, Dush);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809B38D0
     * executeState:    VT+0x17C 0x809B38F0
     * finalizeState:   VT+0x180 0x809B38E0
     */
    sState_ExternVirtual(0x80B11E74, daEnBigHanachan_c, DieFall);
};
