#pragma once

#include "m_vec.h"
#include "s_State.h"

struct dReplayPlay_c {
    SIZE_ASSERT(0xF0);
    VTABLE(0x60, dReplayPlay_c, 0x803195E0);

public:
    // Structors
    // ^^^^^^

    /* 0x800DDA40 */
    dReplayPlay_c();

    /* VT+0x8 0x803195E8 */
    virtual ~dReplayPlay_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x04, 0x64);

    /* 0x64 */ u32     mFrameFlags;
    /* 0x68 */ u32     mPrevFrameFlags;
    /* 0x6C */ u32     mFrameInput;
    /* 0x70 */ u32     mPrevFrameInput;
    /* 0x74 */ u32     mFrameCount;
    /* 0x78 */ mVec3_c mFrameAccel;
    /* 0x84 */ mVec2_c mFrameAccelVertX;
    /* 0x8C */ mVec2_c mFrameAccelVertY;
    /* 0x94 */ mVec2_c mFrameAccelVertZ;
    /* 0x9C */ u16     mFrameTilt;

    FILL(0x9E, 0xF0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x800DE090
     * executeState:    0x800DE0B0
     * finalizeState:   0x800DE0A0
     */
    sState_Extern(0x80371CB0, dReplayPlay_c, StartWait);

    /*
     * initializeState: 0x800DE0C0
     * executeState:    0x800DE0E0
     * finalizeState:   0x800DE0D0
     */
    sState_Extern(0x80371CF0, dReplayPlay_c, Wait);

    /*
     * initializeState: 0x800DE0F0
     * executeState:    0x800DE110
     * finalizeState:   0x800DE100
     */
    sState_Extern(0x80371D30, dReplayPlay_c, Play);

    /*
     * initializeState: 0x800DE300
     * executeState:    0x800DE370
     * finalizeState:   0x800DE360
     */
    sState_Extern(0x80371D70, dReplayPlay_c, PlayEnd);
};
