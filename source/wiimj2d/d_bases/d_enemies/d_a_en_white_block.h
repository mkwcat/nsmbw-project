#pragma once

#include "d_a_en_blockmain.h"
#include "d_allocator.h"
#include "m_3d_mdl.h"
#include <array>

class daEnWhiteBlock_c : public daEnBlockMain_c {
    // Original size: 0x758
    VTABLE(0x060, fBase_c, 0x80B0FEB8);
    // 0x80B0FE60 g_profile_EN_WHITE_BLOCK
    // 0x80AC8270 daEnWhiteBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWhiteBlock_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80AC8A80 */
    void clear();

    /* 0x80AC9260 */
    void FUN_80AC9260();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x698 */ dHeapAllocator_c m_allocator;
    /* 0x6B4 */ void*            m_pResFile;
    /* 0x6B8 */ m3d::mdl_c       m_model;

    FILL(0x6F8, 0x732);

    /* 0x732 */ s8 m0x732;

    FILL(0x733, 0x737);

    /* 0x737 */ s8 m0x737;

    FILL(0x738, 0x73C);

    /* 0x73C */ int m0x73C;
    /* 0x740 */ int m0x740;
    /* 0x744 */ s8  REMOVED(m0x744)[4];
    /* 0x748 */ s8  REMOVED(m0x748)[4];
    /* 0x74C */ s8  REMOVED(m0x74C)[4];

    FILL(0x750, 0x758);
    OFFSET_ASSERT(0x758);

    // Instance Variables
    // ++++++

    std::array<s8, PLAYER_COUNT> m0x744;
    std::array<s8, PLAYER_COUNT> m0x748;
    std::array<s8, PLAYER_COUNT> m0x74C;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AC9680
     * executeState:    0x80AC96B0
     * finalizeState:   0x80AC96A0
     */
    sState_Extern(0x80B1C810, daEnWhiteBlock_c, DownWait);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2F4 0x80AC93D0
     * executeState:    VT+0x2F8 0x80AC93F0
     * finalizeState:   VT+0x2FC 0x80AC93E0
     */
    sState_ExternVirtual(0x80B1C74C, daEnWhiteBlock_c, Wait);

    /*
     * initializeState: VT+0x2A4 0x80AC9450
     * executeState:    VT+0x2A8 0x80AC9490
     * finalizeState:   VT+0x2AC 0x80AC9480
     */
    sState_ExternVirtual(0x80B1C78C, daEnWhiteBlock_c, UpMove);

    /*
     * initializeState: VT+0x2B0 0x80AC9530
     * executeState:    VT+0x2B4 0x80AC9590
     * finalizeState:   VT+0x2B8 0x80AC9580
     */
    sState_ExternVirtual(0x80B1C7CC, daEnWhiteBlock_c, DownMove);
};
