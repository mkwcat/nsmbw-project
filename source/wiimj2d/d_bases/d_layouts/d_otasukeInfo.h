#pragma once

#include "d_base.h"
#include "s_State.h"

class dOtasukeInfo_c : public dBase_c {
    SIZE_ASSERT(0x270);
    VTABLE(0x060, fBase_c, 0x8098ACC0);
    // 0x8098AA88 g_profile_OTASUKE_INFO
    // 0x809160E0 dOtasukeInfo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80916110 */
    dOtasukeInfo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x270);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80916890
     * executeState:    0x809168A0
     * finalizeState:   0x80916930
     */
    sState_Extern(0x809A12E0, dOtasukeInfo_c, Initial);

    /*
     * initializeState: 0x80916960
     * executeState:    0x80916990
     * finalizeState:   0x80916A00
     */
    sState_Extern(0x809A1320, dOtasukeInfo_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x80916A10
     * executeState:    0x80916A20
     * finalizeState:   0x80916A80
     */
    sState_Extern(0x809A1360, dOtasukeInfo_c, FirstButtonChangeAnimeEndWait);

    /*
     * initializeState: 0x80916A90
     * executeState:    0x80916AA0
     * finalizeState:   0x80916C30
     */
    sState_Extern(0x809A13A0, dOtasukeInfo_c, Select);

    /*
     * initializeState: 0x80916C40
     * executeState:    0x80916CE0
     * finalizeState:   0x80916D40
     */
    sState_Extern(0x809A13E0, dOtasukeInfo_c, ButtonChangeAnimeEndWait);

    /*
     * initializeState: 0x80916D50
     * executeState:    0x80916DB0
     * finalizeState:   0x80916EB0
     */
    sState_Extern(0x809A1420, dOtasukeInfo_c, HitAnimeEndWait);

    /*
     * initializeState: 0x80916EC0
     * executeState:    0x80916F20
     * finalizeState:   0x80916FF0
     */
    sState_Extern(0x809A1460, dOtasukeInfo_c, ClouseAnimeEndWait);

    /*
     * initializeState: 0x80917040
     * executeState:    0x80917050
     * finalizeState:   0x80917060
     */
    sState_Extern(0x809A14A0, dOtasukeInfo_c, OtehonCourseOutWait);
};
