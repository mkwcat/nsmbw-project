#pragma once

#include "d_base.h"
#include "s_State.h"

class dPointResultMulti_c : public dBase_c {
    SIZE_ASSERT(0x958);
    VTABLE(0x060, fBase_c, 0x8094DC00);
    // 0x8094D8D8 g_profile_POINT_RESULT_MULTI
    // 0x807A89C0 dPointResultMulti_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807A89F0 */
    dPointResultMulti_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x958);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807A9AC0
     * executeState:    0x807A9BA0
     * finalizeState:   0x807A9C60
     */
    sState_Extern(0x80994EA0, dPointResultMulti_c, OnSatgeSetup);

    /*
     * initializeState: 0x807A9C70
     * executeState:    0x807A9CA0
     * finalizeState:   0x807A9D00
     */
    sState_Extern(0x80994EE0, dPointResultMulti_c, BackGroundDisp);

    /*
     * initializeState: 0x807A9D10
     * executeState:    0x807A9D40
     * finalizeState:   0x807A9DE0
     */
    sState_Extern(0x80994F20, dPointResultMulti_c, OnSatgeAnimeEndCheck);

    /*
     * initializeState: 0x807A9DF0
     * executeState:    0x807A9E00
     * finalizeState:   0x807A9E60
     */
    sState_Extern(0x80994F60, dPointResultMulti_c, TitleOnStage);

    /*
     * initializeState: 0x807A9E70
     * executeState:    0x807A9EC0
     * finalizeState:   0x807A9F10
     */
    sState_Extern(0x80994FA0, dPointResultMulti_c, TitleDisp);

    /*
     * initializeState: 0x807A9F20
     * executeState:    0x807A9F70
     * finalizeState:   0x807A9FE0
     */
    sState_Extern(0x80994FE0, dPointResultMulti_c, TitleExitAnimeEndCheck);

    /*
     * initializeState: 0x807AA000
     * executeState:    0x807AA010
     * finalizeState:   0x807AA060
     */
    sState_Extern(0x80995020, dPointResultMulti_c, SubTitleExitWait);

    /*
     * initializeState: 0x807AA070
     * executeState:    0x807AA080
     * finalizeState:   0x807AA0E0
     */
    sState_Extern(0x80995060, dPointResultMulti_c, SubTitleExitAnimeEndCheck);

    /*
     * initializeState: 0x807AA0F0
     * executeState:    0x807AA2C0
     * finalizeState:   0x807AA3C0
     */
    sState_Extern(0x809950A0, dPointResultMulti_c, SubTitleOnStageAnimeEndCheck);

    /*
     * initializeState: 0x807AA3D0
     * executeState:    0x807AA4C0
     * finalizeState:   0x807AA5E0
     */
    sState_Extern(0x809950E0, dPointResultMulti_c, RankingWindowOnStageEndWait);

    /*
     * initializeState: 0x807AA5F0
     * executeState:    0x807AA600
     * finalizeState:   0x807AA650
     */
    sState_Extern(0x80995120, dPointResultMulti_c, CoinAddStartWait);

    /*
     * initializeState: 0x807AA660
     * executeState:    0x807AA670
     * finalizeState:   0x807AA6A0
     */
    sState_Extern(0x80995160, dPointResultMulti_c, CoinAdd);

    /*
     * initializeState: 0x807AA6B0
     * executeState:    0x807AA6C0
     * finalizeState:   0x807AA710
     */
    sState_Extern(0x809951A0, dPointResultMulti_c, StarCoinAddStartWait);

    /*
     * initializeState: 0x807AA720
     * executeState:    0x807AA730
     * finalizeState:   0x807AA770
     */
    sState_Extern(0x809951E0, dPointResultMulti_c, StarCoinAdd);

    /*
     * initializeState: 0x807AA780
     * executeState:    0x807AA790
     * finalizeState:   0x807AA7C0
     */
    sState_Extern(0x80995220, dPointResultMulti_c, RankChangeWait);

    /*
     * initializeState: 0x807AA7D0
     * executeState:    0x807AA7E0
     * finalizeState:   0x807AA8B0
     */
    sState_Extern(0x80995260, dPointResultMulti_c, GoalDeMoEndWait);

    /*
     * initializeState: 0x807AA8C0
     * executeState:    0x807AA8E0
     * finalizeState:   0x807AA930
     */
    sState_Extern(0x809952A0, dPointResultMulti_c, PlayPointCalc);

    /*
     * initializeState: 0x807AAA30
     * executeState:    0x807AAA70
     * finalizeState:   0x807AAB20
     */
    sState_Extern(0x809952E0, dPointResultMulti_c, PlayCountSave);

    /*
     * initializeState: 0x807AAB30
     * executeState:    0x807AAB60
     * finalizeState:   0x807AAC10
     */
    sState_Extern(0x80995320, dPointResultMulti_c, SaveError);

    /*
     * initializeState: 0x807AAC20
     * executeState:    0x807AAC30
     * finalizeState:   0x807AAC40
     */
    sState_Extern(0x80995360, dPointResultMulti_c, NothingWait);
};
