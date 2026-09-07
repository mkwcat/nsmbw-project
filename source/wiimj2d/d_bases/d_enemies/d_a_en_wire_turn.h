#pragma once

#include "d_allocator.h"
#include "d_ka_draw.h"
#include "d_mj2d_game.h"
#include "m_3d_mdl.h"
#include "m_vec.h"
#include "s_State.h"
#include <d_static/d_enemy/d_enemy.h>

class daEnWrturn_c : public dEn_c {
    // Original size: 0x8D0
    VTABLE(0x060, fBase_c, 0x80B10388);
    // 0x80B10340 g_profile_EN_WIRE_TURN
    // 0x80AC9F30 daEnWrturn_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWrturn_c();

public:
    // Constants
    // ^^^^^^

    enum class WireType_e {
        S = 0,
        L = 1,
    };

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x08 0x80ACA0F0
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /**
     * VT+0x20 0x80ACA2B0
     * do method for the execute operation.
     */
    virtual PACK_RESULT_e execute() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80ACA8B0 */
    void initS();

    void initL();

    /* 0x80ACA980 */
    void BgUpdate(bool);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ dHeapAllocator_c m_allocator;
    /* 0x540 */ void*            m_pResFile{};
    /* 0x544 */ m3d::mdl_c       m_model;
    /* 0x584 */ dKADr_c          m_kaDraw;
    /* 0x6A4 */ fBaseID_e        m_0x6A4[17];
    /* 0x6E8 */ fBaseID_e        m_0x6E8[17];
    /* 0x72C */ mVec3_c          m_0x72C;
    /* 0x738 */ mVec3_c          m_0x738;
    /* 0x744 */ float            REMOVED(m_plrMoveX)[4];
    /* 0x754 */ float            REMOVED(m_plrMoveY)[4];
    /* 0x764 */ float            REMOVED(m_plrMoveZ)[4];
    /* 0x774 */ float            m_0x774[17];
    /* 0x7B8 */ float            m_0x7B8[17];
    /* 0x7FC */ float            m_0x7FC[17];
    /* 0x840 */ float            m_0x840[17];
    /* 0x884 */ short            m_0x884[17];
    FILL(0x8A6, 0x8AC);
    /* 0x8AC */ WireType_e m_wireType;
    /* 0x8B0 */ int        m_0x8B0;
    /* 0x8B4 */ short      m_0x8B4;
    /* 0x8B6 */ short      m_0x8B6;
    /* 0x8B8 */ short      m_0x8B8;
    /* 0x8BA */ short      m_0x8BA;
    /* 0x8BC */ bool       REMOVED(m_plrAmiChange)[4];
    /* 0x8C0 */ u8         REMOVED(m_plrAmiLayer)[4];
    /* 0x8C4 */ bool       REMOVED(m_plrAmiRoll)[4];
    /* 0x8C8 */ s8         REMOVED(m_0x8C8)[4];
    FILL(0x8CC, 0x8D0);
    OFFSET_ASSERT(0x8D0);

    // Instance Variables
    // ++++++

    float m_plrMoveX[PLAYER_COUNT];
    float m_plrMoveY[PLAYER_COUNT];
    float m_plrMoveZ[PLAYER_COUNT];
    bool  m_plrAmiChange[PLAYER_COUNT];
    u8    m_plrAmiLayer[PLAYER_COUNT];
    bool  m_plrAmiRoll[PLAYER_COUNT];
    s8    m_0x8C8[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80ACB010
     * executeState:    0x80ACB040
     * finalizeState:   0x80ACB030
     */
    sState_Extern(0x80B1C850, daEnWrturn_c, Wait);

    /*
     * initializeState: 0x80ACB050
     * executeState:    0x80ACB120
     * finalizeState:   0x80ACB110
     */
    sState_Extern(0x80B1C890, daEnWrturn_c, Move);
};

class daEnBigWrturn_c : public daEnWrturn_c {
    // Original size: 0x8D0
    // 0x80B1034C g_profile_EN_BIG_WIRE_TURN
    // 0x80ACA010 daEnBigWrturn_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigWrturn_c();
};
