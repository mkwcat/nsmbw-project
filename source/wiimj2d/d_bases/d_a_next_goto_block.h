#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_actor_state.h"
#include "d_system/d_cc.h"
#include "d_player/d_a_player.h"
#include "machine/m_vec.h"
#include "state/s_State.h"

class daNextGotoBlock_c : public dActorState_c {
public:
    // Structors
    // ^^^^^^

    daNextGotoBlock_c()
    {
    }

    /* VT+0x48 0x8086EBB0 */
    virtual ~daNextGotoBlock_c() override;

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x8086E6C0
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x8086E870
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    virtual PACK_RESULT_e execute() override;

    /**
     * VT+0x2C 0x8086E8C0
     * do method for the draw operation.
     */
    virtual PACK_RESULT_e draw() override;

public:
    // Static Methods
    // ^^^^^^

    /* 0x8086E8D0 */
    static void normal_collcheck(dCc_c* self, dCc_c* other);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x3D0 */ mVec2_c mCenterDist;
    /* 0x3D8 */ mVec2_c mEdgeDist;
    /* 0x3E0 */ daPlBase_c* REMOVED(mpaPlayers)[4];
    /* 0x3F0 */ s32 m0x3F0;
    /* 0x3F4 */ s16 mWidth;
    /* 0x3F6 */ s16 mHeight;
    /* 0x3F8 */ s16 mRequireVine;
    /* 0x3FA */ s16 REMOVED(m0x3FA)[4];
    /* 0x402 */ s16 m0x402;
    /* 0x404 */ s16 m0x404;
    /* 0x406 */ s16 REMOVED(m0x406)[4];
    /* 0x40E */ bool REMOVED(mPlayerInBlock)[4];
    /* 0x412 */ u8 mGotoID;
    /* 0x413 */ bool mExitToWorldMap;

    OFFSET_ASSERT(0x414);

#define OFFSET_mpaPlayers 0x414
    daPlBase_c* mpaPlayers[PLAYER_COUNT];

#define OFFSET_m0x3FA (OFFSET_mpaPlayers + PLAYER_COUNT * 4)
    s16 m0x3FA[PLAYER_COUNT];

#define OFFSET_m0x406 (OFFSET_m0x3FA + PLAYER_COUNT * 2)
    s16 m0x406[PLAYER_COUNT];

#define OFFSET_mPlayerInBlock (OFFSET_m0x406 + PLAYER_COUNT * 2)
    bool mPlayerInBlock[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /**
     * initializeState: 0x8086E9D0
     * executeState:    0x8086EA10
     * finalizeState:   0x8086EA00
     */
    sState_Extern(0x8099D090, daNextGotoBlock_c, Move);
};
