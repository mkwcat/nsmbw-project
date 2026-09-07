#pragma once

#include "d_a_boss_demo.h"
#include "d_a_player_manager.h"
#include "d_mj2d_game.h"
#include "m_vec.h"

class dAcPy_c;
class daKoopaShipForCastleDemo_c;
class daPeachForCastleDemo_c;
class daKoopaJrForCastleDemo_c;

class daCastleKokoopaDemo2nd_c : public daBossDemo_c {
    // Original size: 0x440
    VTABLE(0x060, fBase_c, 0x80957240);
    // 0x80957230 g_profile_CASTLE_KOKOOPA_DEMO_2ND
    // 0x807DCD80 daCastleKokoopaDemo2nd_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCastleKokoopaDemo2nd_c();

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x138 0x807DCE80
     * Subclass-specific initialization code.
     */
    void initialize() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807DD290 */
    bool isPlayerActive(int plrNo);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3DC, 0x3E0);

    /* 0x3E0 */ int                         mWorldNo;
    /* 0x3E4 */ mVec3_c                     mBasePos;
    /* 0x3F0 */ mVec3_c                     mDoomshipPos;
    /* 0x3FC */ float                       m0x3FC;
    /* 0x400 */ float                       REMOVED(m0x400)[4];
    /* 0x410 */ float                       REMOVED(m0x410)[4];
    /* 0x420 */ dAcPy_c*                    REMOVED(mpPlayersInOrder)[4];
    /* 0x430 */ daKoopaJrForCastleDemo_c*   mpKoopaJr;
    /* 0x434 */ daPeachForCastleDemo_c*     mpPeach;
    /* 0x438 */ daKoopaShipForCastleDemo_c* mpKoopaShip;
    OFFSET_ASSERT(0x43C);

    // Instance Variables
    // ++++++

    float    m0x400[PLAYER_COUNT];
    float    m0x410[PLAYER_COUNT];
    dAcPy_c* mpPlayersInOrder[PLAYER_COUNT];

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x13C 0x807DD2C0
     * executeState:    VT+0x140 0x807DD2F0
     * finalizeState:   VT+0x144 0x807DD2E0
     */
    sState_ExternVirtual(0x809978C4, daCastleKokoopaDemo2nd_c, DemoSt);
};
