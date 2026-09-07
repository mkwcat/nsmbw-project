#pragma once

#include "d_mj2d_game.h"
#include "d_scene.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"

class da2DPlayer_c;
class dNumberOfPeopleChange_c;
class dSelectPlayer_c;
class dEasyPairing_c;
class dSequenceBG_c;
class dFileSelect_c;
class dDateFile_c;
class dInfoWindow_c;

class dScGameSetup_c : public dScene_c {
    SIZE_ASSERT(0x210);
    VTABLE(0x060, fBase_c, 0x8098B1A0);
    // 0x8098B0D0 g_profile_GAME_SETUP
    // 0x80917960 dScGameSetup_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80918020 */
    dScGameSetup_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80917A70 */
    bool Phase_LinkProfiles();

    /* 0x80917BE0 */
    bool Phase_CreateSequenceBG();

    /* 0x80917C30 */
    bool Phase_SyncAllRes();

    /* 0x80917C80 */
    bool Phase_CreateLayoutManagers();

    /* 0x80917E00 */
    bool Phase_WaitLayoutReady();

    /* 0x80917EB0 */
    bool Phase_Create2DPlayer();

    /* 0x80917F50 */
    bool Phase_CreateSelectCursor();

    /* 0x80917FA0 */
    bool Phase_WaitChildProcessCreateDone();

    /* 0x80917BB0 */
    bool Phase_LoadSound();

    /* 0x80917FD0 */
    bool Phase_SoundLoadedWait();

    /* 0x80918000 */
    bool Phase_InitGraphDrawFunc();

    /* 0x80918450 */
    bool executeDateFileAnimeOut();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x074 */ sStateMgrDefault_c<dScGameSetup_c> mStateMgr;

    FILL(0x0B0, 0x0B8);

    /* 0x0B8 */ dNumberOfPeopleChange_c* mpNumPyChg;

    FILL(0x0BC, 0x0C0);

    /* 0x0C0 */ da2DPlayer_c*    mpa2DPlayer[ORIGINAL_PLAYER_COUNT];
    /* 0x0D0 */ dSelectPlayer_c* mpSelectPlayer;
    /* 0x0D4 */ dEasyPairing_c*  mpEasyPairing;
    /* 0x0D8 */ dSequenceBG_c*   mpSequenceBG;
    /* 0x0DC */ dDateFile_c*     mpDateFile[SAVE_SLOT_COUNT];
    /* 0x0E8 */ dFileSelect_c*   mpFileSelect;
    /* 0x0EC */ dInfoWindow_c*   mpInfoWindow;

    FILL(0x0F0, 0x0F8);

    /* 0x0F8 */ u32 mPlayerCreateIdx;

    FILL(0x0FC, 0x108);

    /* 0x108 */ bool mInPlayerSelect;

    FILL(0x109, 0x210);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80918680
     * executeState:    0x80918690
     * finalizeState:   0x80918710
     */
    sState_Extern(0x809A14E0, dScGameSetup_c, FadeInEndWait);

    /*
     * initializeState: 0x80918720
     * executeState:    0x80918780
     * finalizeState:   0x809188E0
     */
    sState_Extern(0x809A1520, dScGameSetup_c, FileSelect);

    /*
     * initializeState: 0x80918910
     * executeState:    0x80918950
     * finalizeState:   0x809189C0
     */
    sState_Extern(0x809A1560, dScGameSetup_c, FadeOut);

    /*
     * initializeState: 0x809189F0
     * executeState:    0x80918A20
     * finalizeState:   0x80918AC0
     */
    sState_Extern(0x809A15A0, dScGameSetup_c, FadeIn);

    /*
     * initializeState: 0x80918AD0
     * executeState:    0x80918B00
     * finalizeState:   0x80918C00
     */
    sState_Extern(0x809A15E0, dScGameSetup_c, StartMember);

    /*
     * initializeState: 0x80918C10
     * executeState:    0x80918D10
     * finalizeState:   0x80918DB0
     */
    sState_Extern(0x809A1620, dScGameSetup_c, ConnectionCheck);

    /*
     * initializeState: 0x80918DC0
     * executeState:    0x80918E40
     * finalizeState:   0x80918E70
     */
    sState_Extern(0x809A1660, dScGameSetup_c, EasyPairingWait);

    /*
     * initializeState: 0x80918EE0
     * executeState:    0x80918EF0
     * finalizeState:   0x80918F80
     */
    sState_Extern(0x809A16A0, dScGameSetup_c, LowBatteryCheck);

    /*
     * initializeState: 0x80918FF0
     * executeState:    0x80919050
     * finalizeState:   0x809190E0
     */
    sState_Extern(0x809A16E0, dScGameSetup_c, NandAccess);

    /*
     * initializeState: 0x80919120
     * executeState:    0x80919130
     * finalizeState:   0x80919190
     */
    sState_Extern(0x809A1720, dScGameSetup_c, VoiceEndWait);

    /*
     * initializeState: 0x80919210
     * executeState:    0x80919220
     * finalizeState:   0x80919230
     */
    sState_Extern(0x809A1760, dScGameSetup_c, NextSceneWait);
};
