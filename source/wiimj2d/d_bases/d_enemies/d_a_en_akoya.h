#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnAkoya_c : public dEn_c {
    SIZE_ASSERT(0x940);
    VTABLE(0x060, fBase_c, 0x80AD5B00);
    // 0x80AD5A60 g_profile_EN_AKOYA
    // 0x809A2F20 daEnAkoya_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnAkoya_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x940);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809A4660
     * executeState:    0x809A46F0
     * finalizeState:   0x809A46E0
     */
    sState_Extern(0x80B11438, daEnAkoya_c, DownWait);

    /*
     * initializeState: 0x809A4710
     * executeState:    0x809A4730
     * finalizeState:   0x809A4720
     */
    sState_Extern(0x80B11478, daEnAkoya_c, DownMove);

    /*
     * initializeState: 0x809A49D0
     * executeState:    0x809A49F0
     * finalizeState:   0x809A49E0
     */
    sState_Extern(0x80B114B8, daEnAkoya_c, VibrationMove);

    /*
     * initializeState: 0x809A4A40
     * executeState:    0x809A4A80
     * finalizeState:   0x809A4A70
     */
    sState_Extern(0x80B114F8, daEnAkoya_c, OpenWait);

    /*
     * initializeState: 0x809A4AC0
     * executeState:    0x809A4AE0
     * finalizeState:   0x809A4AD0
     */
    sState_Extern(0x80B11538, daEnAkoya_c, CloseBefore);

    /*
     * initializeState: 0x809A4B50
     * executeState:    0x809A4BE0
     * finalizeState:   0x809A4BD0
     */
    sState_Extern(0x80B11578, daEnAkoya_c, Close);

    /*
     * initializeState: 0x809A4D80
     * executeState:    0x809A4DF0
     * finalizeState:   0x809A4DE0
     */
    sState_Extern(0x80B115B8, daEnAkoya_c, CloseWait);

    /*
     * initializeState: 0x809A4EB0
     * executeState:    0x809A4F70
     * finalizeState:   0x809A4F60
     */
    sState_Extern(0x80B115F8, daEnAkoya_c, Open);

    /*
     * initializeState: 0x809A51D0
     * executeState:    0x809A52A0
     * finalizeState:   0x809A5290
     */
    sState_Extern(0x80B11638, daEnAkoya_c, AngleDown);

    /*
     * initializeState: 0x809A53E0
     * executeState:    0x809A5400
     * finalizeState:   0x809A53F0
     */
    sState_Extern(0x80B11678, daEnAkoya_c, AngleFallDown);
};
