#pragma once

#include "d_scene.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"

class dWiiStrap_c;
class dYesNoWindow_c;
class dSelectCursor_c;
class dControllerInformation_c;

class dScBoot_c : public dScene_c {
    SIZE_ASSERT(0x110);
    VTABLE(0x060, fBase_c, 0x803284C8);
    // 0x804296E8 g_profile_BOOT
    // 0x8015BA70 dScBoot_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8015C270 */
    dScBoot_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x074 */ sStateMgrDefault_c<dScBoot_c> mStateMgr;
    /* 0x0B0 */ sStateMgrDefault_c<dScBoot_c> mStateMgr2;

    FILL(0xEC, 0xF0);

    /* 0x0F0 */ dWiiStrap_c*              mWiiStrap;
    /* 0x0F4 */ dYesNoWindow_c*           mYesNoWindow;
    /* 0x0F8 */ dSelectCursor_c*          mSelectCursor;
    /* 0x0FC */ dControllerInformation_c* mControllerInformation;

    FILL(0x100, 0x102);

    /* 0x102 */ bool mLoadedSceneSnd;

    FILL(0x103, 0x110);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A620 */ static dScBoot_c* m_instance;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8015C770
     * executeState:    0x8015C7C0
     * finalizeState:   0x8015C840
     */
    sState_Extern(0x80377708, dScBoot_c, ResetWait);

    /*
     * initializeState: 0x8015C850
     * executeState:    0x8015C8B0
     * finalizeState:   0x8015CA10
     */
    sState_Extern(0x80377748, dScBoot_c, ResetFadeOut);

    /*
     * initializeState: 0x8015CB90
     * executeState:    0x8015CBF0
     * finalizeState:   0x8015CC60
     */
    sState_Extern(0x80377788, dScBoot_c, ResetFadeIn);

    /*
     * initializeState: 0x8015CDF0
     * executeState:    0x8015CE00
     * finalizeState:   0x8015CE70
     */
    sState_Extern(0x803777C8, dScBoot_c, FadeOutWait);

    /*
     * initializeState: 0x8015CE80
     * executeState:    0x8015CED0
     * finalizeState:   0x8015CF10
     */
    sState_Extern(0x80377808, dScBoot_c, WiiStrapKeyWait);

    /*
     * initializeState: 0x8015CF20
     * executeState:    0x8015CF30
     * finalizeState:   0x8015CFB0
     */
    sState_Extern(0x80377848, dScBoot_c, WiiStrapDispEndWait);

    /*
     * initializeState: 0x8015CFC0
     * executeState:    0x8015D010
     * finalizeState:   0x8015D0A0
     */
    sState_Extern(0x80377888, dScBoot_c, WiiStrapFadeOut);

    /*
     * initializeState: 0x8015D0B0
     * executeState:    0x8015D100
     * finalizeState:   0x8015D170
     */
    sState_Extern(0x803778C8, dScBoot_c, ControllerInformationFadeIn);

    /*
     * initializeState: 0x8015D1E0
     * executeState:    0x8015D230
     * finalizeState:   0x8015D280
     */
    sState_Extern(0x80377908, dScBoot_c, ControllerInformationSoundWait);

    /*
     * initializeState: 0x8015D290
     * executeState:    0x8015D2A0
     * finalizeState:   0x8015D2F0
     */
    sState_Extern(0x80377948, dScBoot_c, ControllerInformationKeyWait);

    /*
     * initializeState: 0x8015D300
     * executeState:    0x8015D310
     * finalizeState:   0x8015D3C0
     */
    sState_Extern(0x80377988, dScBoot_c, ControllerInformationDispEndWait);

    /*
     * initializeState: 0x8015D3D0
     * executeState:    0x8015D3E0
     * finalizeState:   0x8015D460
     */
    sState_Extern(0x803779C8, dScBoot_c, NandCommandEndWait);

    /*
     * initializeState: 0x8015D470
     * executeState:    0x8015D4E0
     * finalizeState:   0x8015D4D0
     */
    sState_Extern(0x80377A08, dScBoot_c, ExistFileCheck);

    /*
     * initializeState: 0x8015D5A0
     * executeState:    0x8015D5C0
     * finalizeState:   0x8015D5B0
     */
    sState_Extern(0x80377A48, dScBoot_c, NandSpaceCheck);

    /*
     * initializeState: 0x8015D670
     * executeState:    0x8015D6F0
     * finalizeState:   0x8015D770
     */
    sState_Extern(0x80377A88, dScBoot_c, CreateFile);

    /*
     * initializeState: 0x8015D780
     * executeState:    0x8015D790
     * finalizeState:   0x8015D830
     */
    sState_Extern(0x80377AC8, dScBoot_c, Load);

    /*
     * initializeState: 0x8015DA30
     * executeState:    0x8015DA70
     * finalizeState:   0x8015DAF0
     */
    sState_Extern(0x80377B08, dScBoot_c, GoToErrorFadeOut);

    /*
     * initializeState: 0x8015DB00
     * executeState:    0x8015DB30
     * finalizeState:   0x8015DBE0
     */
    sState_Extern(0x80377B48, dScBoot_c, GoToErrorFadeIn);

    /*
     * initializeState: 0x8015D870
     * executeState:    0x8015D890
     * finalizeState:   0x8015D8C0
     */
    sState_Extern(0x80377B88, dScBoot_c, NewSaveFileDisp);

    /*
     * initializeState: 0x8015D8F0
     * executeState:    0x8015D900
     * finalizeState:   0x8015D980
     */
    sState_Extern(0x80377BC8, dScBoot_c, ButtonInputWait);

    /*
     * initializeState: 0x8015D990
     * executeState:    0x8015D9A0
     * finalizeState:   0x8015DA20
     */
    sState_Extern(0x80377C08, dScBoot_c, WindowExitWait);

    /*
     * initializeState: 0x8015D840
     * executeState:    0x8015D850
     * finalizeState:   0x8015D860
     */
    sState_Extern(0x80377C48, dScBoot_c, ProcEnd);

    /*
     * initializeState: 0x8015DC10
     * executeState:    0x8015DC30
     * finalizeState:   0x8015DD10
     */
    sState_Extern(0x80377C88, dScBoot_c, ErrorWindowOnStageWait);
};
