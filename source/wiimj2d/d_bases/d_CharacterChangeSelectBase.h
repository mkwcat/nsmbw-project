#pragma once

#include "component/c_array.h"
#include "d_static/d_base.h"
#include "d_static/d_info.h"
#include "d_static/d_lytbase.h"
#include "state/s_State.h"
#include "state/s_StateMgrDefault.h"

class dCharacterChangeSelectContents_c;
class dCharacterChangeSelectArrow_c;
class dCharacterChangeIndicator_c;
class da2DPlayer_c;

class dCharacterChangeSelectBase_c : public dBase_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x8076F400 */
    dCharacterChangeSelectBase_c();

public:
    // Constants and Types
    // ^^^^^^

#define CHARACTER_LIST_COUNT 8

    enum class Icon_e {
        // Reserved
        ICON_NONE = 6,

        ICON_BLUE_TOAD = 0,
        ICON_BLUE_TOAD_LOCKED = 3,
        ICON_YELLOW_TOAD = 1,
        ICON_YELLOW_TOAD_LOCKED = 4,
        ICON_LUIGI = 2,
        ICON_LUIGI_LOCKED = 5,
        ICON_MARIO = 7,
        ICON_MARIO_LOCKED = 8,
        ICON_TOADETTE = 9,
        ICON_TOADETTE_LOCKED = 10,
        ICON_PURPLE_TOADETTE = 11,
        ICON_PURPLE_TOADETTE_LOCKED = 12,
        ICON_ORANGE_TOAD = 13,
        ICON_ORANGE_TOAD_LOCKED = 14,
        ICON_BLACK_TOAD = 15,
        ICON_BLACK_TOAD_LOCKED = 16,
    };

    static constexpr Icon_e ICON_FROM_BASE[] = {
      Icon_e::ICON_MARIO,       Icon_e::ICON_LUIGI,      Icon_e::ICON_YELLOW_TOAD,
      Icon_e::ICON_BLUE_TOAD,   Icon_e::ICON_TOADETTE,   Icon_e::ICON_PURPLE_TOADETTE,
      Icon_e::ICON_ORANGE_TOAD, Icon_e::ICON_BLACK_TOAD,
    };

    static constexpr Icon_e ICON_LOCKED_FROM_BASE[] = {
      Icon_e::ICON_MARIO_LOCKED,       Icon_e::ICON_LUIGI_LOCKED,
      Icon_e::ICON_YELLOW_TOAD_LOCKED, Icon_e::ICON_BLUE_TOAD_LOCKED,
      Icon_e::ICON_TOADETTE_LOCKED,    Icon_e::ICON_PURPLE_TOADETTE_LOCKED,
      Icon_e::ICON_ORANGE_TOAD_LOCKED, Icon_e::ICON_BLACK_TOAD_LOCKED,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8076FA40 */
    void clearPlayerNo();

    /* 0x8076FAE0 */
    bool updateRemocon();

    /* 0x8076FC80 */
    bool isCharacterLocked(PLAYER_TYPE_e character);

    /* 0x8076FD70 */
    void calcContentsIcon(int swapIndex, int baseIndex);

    /* 0x8076FE40 */
    void initDecidedCharacter();

    /* 0x8076FE60 */
    void initOption();

    /* 0x8076FE90 */
    void resetIndicator();

    /* 0x8076FEE0 */
    void readyContents();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x074);

    /* 0x074 */ dCharacterChangeSelectContents_c* mpCcSelContents;
    /* 0x078 */ dCharacterChangeSelectArrow_c* mpCcSelArrow;
    /* 0x07C */ dCharacterChangeIndicator_c* mpCcIndicator;

    union {
        /* 0x080 */ da2DPlayer_c* REMOVED(mp2DPlayer)[4];
        /* 0x080 */ cEnumArrayRef_c<da2DPlayer_c*, PLAYER_TYPE_e> mp2DPlayer;
    };

    /* 0x090 */ LytBase_c mLayout;
    /* 0x228 */ sStateMgrDefault_c<dCharacterChangeSelectBase_c> mStateMgr;

    /* 0x264 */ nw4r::lyt::Pane* mpRootPane;

    /* 0x268 */ nw4r::lyt::Pane* mp0x268;
    /* 0x26C */ nw4r::lyt::Pane* mp0x26C;
    /* 0x270 */ nw4r::lyt::Pane* mp0x270;
    /* 0x274 */ nw4r::lyt::Pane* mp0x274;
    /* 0x278 */ nw4r::lyt::Pane* mp0x278;
    /* 0x27C */ nw4r::lyt::Pane* mp0x27C;

    /* 0x280 */ dInfo_c::PlyConnectStage_e* mpNumPyConnectStage;
    /* 0x284 */ int* mpNumPySetupPlayers;
    /* 0x288 */ int* mpNumPyEnterCount;
    /* 0x28C */ PLAYER_TYPE_e* mpNumPyPlyDecidedPlayerType;
    /* 0x290 */ PLAYER_TYPE_e* mpNumPyCcDecidedPlayerType;
    /* 0x294 */ bool m0x294;
    /* 0x295 */ bool m0x295;
    /* 0x296 */ bool m0x296;
    /* 0x297 */ bool m0x297;
    /* 0x298 */ bool m0x298;
    /* 0x299 */ bool m0x299;
    /* 0x29A */ bool mDecided;
    /* 0x29B */ bool m0x29B;
    /* 0x29C */ bool mEasyPairingWait;

    FILL(0x29D, 0x2A0);

    /* 0x2A0 */ int m0x2A0;
    /* 0x2A4 */ mVec3_c mAllBasePos[4]; // Changed to just use the first element
    /* 0x2D4 */ PLAYER_TYPE_e mDecidedCharacter;
    /* 0x2D8 */ int mPlayerNo;
    /* 0x2DC */ int mCcIndex;
    /* 0x2E0 */ int mOption;
    /* 0x2E4 */ int m0x2E4;
    /* 0x2E8 */ int mPlayerCount;
    /* 0x2EC */ float m0x2EC;
    /* 0x2F0 */ float m2dPlayerBaseY;

    OFFSET_ASSERT(0x2F4);

    /* 0x2F4 */ std::size_t mCcCount;

public:
    // Static Methods
    // ^^^^^^

    static PLAYER_TYPE_e getCharacterFromBase(int baseIndex);
    static int getBaseFromCharacter(PLAYER_TYPE_e chara);
    static PLAYER_TYPE_e getCharacterFromIcon(Icon_e icon);
    static bool isLockedIcon(Icon_e icon);
    static u32 getLampPattern(int playerNo);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8076FFF0
     * executeState:    0x80770030
     * finalizeState:   0x80770050
     */
    sState_Extern(0x80990958, dCharacterChangeSelectBase_c, initial);

    /*
     * initializeState: 0x80770060
     * executeState:    0x80770070
     * finalizeState:   0x80770090
     */
    sState_Extern(0x80990998, dCharacterChangeSelectBase_c, OnStageWait);

    /*
     * initializeState: 0x807701F0
     * executeState:    0x807702A0
     * finalizeState:   0x807703F0
     */
    sState_Extern(0x809909D8, dCharacterChangeSelectBase_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x80770400
     * executeState:    0x80770430
     * finalizeState:   0x80770540
     */
    sState_Extern(0x80990A18, dCharacterChangeSelectBase_c, ConnectWait);

    /*
     * initializeState: 0x80770550
     * executeState:    0x80770560
     * finalizeState:   0x80770620
     */
    sState_Extern(0x80990A58, dCharacterChangeSelectBase_c, SelectStartWait);

    /*
     * initializeState: 0x80770630
     * executeState:    0x80770670
     * finalizeState:   0x807706D0
     */
    sState_Extern(0x80990A98, dCharacterChangeSelectBase_c, ButtonExitAnimeEndWait);

    /*
     * initializeState: 0x807706E0
     * executeState:    0x80770790
     * finalizeState:   0x80770820
     */
    sState_Extern(0x80990AD8, dCharacterChangeSelectBase_c, ButtonOnStageAnimeEndWait);

    /*
     * initializeState: 0x80770830
     * executeState:    0x80770850
     * finalizeState:   0x807708B0
     */
    sState_Extern(0x80990B18, dCharacterChangeSelectBase_c, ArrowDispWait);

    /*
     * initializeState: 0x807708D0
     * executeState:    0x807708E0
     * finalizeState:   0x80770B40
     */
    sState_Extern(0x80990B58, dCharacterChangeSelectBase_c, SelectWait);

    /*
     * initializeState: 0x80770B50
     * executeState:    0x80770BA0
     * finalizeState:   0x80770BE0
     */
    sState_Extern(0x80990B98, dCharacterChangeSelectBase_c, MoveAnimeStartWait);

    /*
     * initializeState: 0x80770BF0
     * executeState:    0x80770C90
     * finalizeState:   0x80770D00
     */
    sState_Extern(0x80990BD8, dCharacterChangeSelectBase_c, MoveAnimeEndWait);

    /*
     * initializeState: 0x80770D80
     * executeState:    0x80770E20
     * finalizeState:   0x80770E70
     */
    sState_Extern(0x80990C18, dCharacterChangeSelectBase_c, HitAnimeEndWait);

    /*
     * initializeState: 0x80770E80
     * executeState:    0x80770E90
     * finalizeState:   0x80770ED0
     */
    sState_Extern(0x80990C58, dCharacterChangeSelectBase_c, HitAfterExitWait);

    /*
     * initializeState: 0x80770EE0
     * executeState:    0x80771010
     * finalizeState:   0x80771070
     */
    sState_Extern(0x80990C98, dCharacterChangeSelectBase_c, ExitAnimeEndForPlayerOnStageWait);

    /*
     * initializeState: 0x80771090
     * executeState:    0x80771220
     * finalizeState:   0x80771270
     */
    sState_Extern(0x80990CD8, dCharacterChangeSelectBase_c, PlayerOnStageWait);

    /*
     * initializeState: 0x807712B0
     * executeState:    0x807712E0
     * finalizeState:   0x807713D0
     */
    sState_Extern(0x80990D18, dCharacterChangeSelectBase_c, PlayerDisp);

    /*
     * initializeState: 0x807713E0
     * executeState:    0x80771470
     * finalizeState:   0x807714C0
     */
    sState_Extern(0x80990D58, dCharacterChangeSelectBase_c, PlayerExitWait);

    /*
     * initializeState: 0x80771530
     * executeState:    0x807715B0
     * finalizeState:   0x80771610
     */
    sState_Extern(0x80990D98, dCharacterChangeSelectBase_c, PlayerExitEndClearWaKu);

    /*
     * initializeState: 0x80771620
     * executeState:    0x80771710
     * finalizeState:   0x807717A0
     */
    sState_Extern(
      0x80990DD8, dCharacterChangeSelectBase_c, ConnectCutEnterWaitWindowOnStageAnimeEndWait
    );

    /*
     * initializeState: 0x807717B0
     * executeState:    0x807717F0
     * finalizeState:   0x80771850
     */
    sState_Extern(0x80990E18, dCharacterChangeSelectBase_c, ExitAnimeEndWait);
};
