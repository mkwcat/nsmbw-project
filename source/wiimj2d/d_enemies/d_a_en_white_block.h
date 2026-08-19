#pragma once

#include "d_system/d_a_en_blockmain.h"
#include "d_system/d_allocator.h"
#include "machine/m_3d_mdl.h"
#include <array>

class daEnWhiteBlock_c : public daEnBlockMain_c {
    // Original size: 0x758
    VTABLE(0x060, fBase_c, 0x80B0FEB8);

public:
    // Structors
    // ^^^^^^

    /* Stripped */
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
};
