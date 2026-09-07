#pragma once

#include "d_scene.h"
#include "s_State.h"

class dScWorld9DeMo_c : public dScene_c {
    SIZE_ASSERT(0x1D8);
    VTABLE(0x060, fBase_c, 0x8098BD78);
    // 0x8098BCB8 g_profile_WORLD_9_DEMO
    // 0x8091CB70 dScWorld9DeMo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8091D040 */
    dScWorld9DeMo_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x8091D350
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

public:
    // Functions
    // ^^^^^^

    /* 0x8091DEC0 */
    void initLight();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x74, 0xD0);

    /* 0xD0 */ bool mIsWorld9AlreadyOpen;

    FILL(0x0D1, 0x1D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8091D530
     * executeState:    0x8091D570
     * finalizeState:   0x8091D5F0
     */
    sState_Extern(0x809A1920, dScWorld9DeMo_c, FadeInEndWait);

    /*
     * initializeState: 0x8091D600
     * executeState:    0x8091D610
     * finalizeState:   0x8091D6B0
     */
    sState_Extern(0x809A1960, dScWorld9DeMo_c, World9OnStageAnimeEndWait);

    /*
     * initializeState: 0x8091D6D0
     * executeState:    0x8091D6F0
     * finalizeState:   0x8091D720
     */
    sState_Extern(0x809A19A0, dScWorld9DeMo_c, SaveWindowOpen);

    /*
     * initializeState: 0x8091D730
     * executeState:    0x8091D740
     * finalizeState:   0x8091D880
     */
    sState_Extern(0x809A19E0, dScWorld9DeMo_c, SaveButtonSelect);

    /*
     * initializeState: 0x8091D890
     * executeState:    0x8091D8A0
     * finalizeState:   0x8091D8F0
     */
    sState_Extern(0x809A1A20, dScWorld9DeMo_c, SaveWindowClose);

    /*
     * initializeState: 0x8091D900
     * executeState:    0x8091D950
     * finalizeState:   0x8091D9E0
     */
    sState_Extern(0x809A1A60, dScWorld9DeMo_c, NowSave);

    /*
     * initializeState: 0x8091D9F0
     * executeState:    0x8091DA30
     * finalizeState:   0x8091DAD0
     */
    sState_Extern(0x809A1AA0, dScWorld9DeMo_c, SaveEndWindowOnStage);

    /*
     * initializeState: 0x8091DAE0
     * executeState:    0x8091DAF0
     * finalizeState:   0x8091DB20
     */
    sState_Extern(0x809A1AE0, dScWorld9DeMo_c, SaveEndAnimeWait);

    /*
     * initializeState: 0x8091DB30
     * executeState:    0x8091DB60
     * finalizeState:   0x8091DBC0
     */
    sState_Extern(0x809A1B20, dScWorld9DeMo_c, SaveError);

    /*
     * initializeState: 0x8091DBD0
     * executeState:    0x8091DBE0
     * finalizeState:   0x8091DBF0
     */
    sState_Extern(0x809A1B60, dScWorld9DeMo_c, NextSceneWait);
};
