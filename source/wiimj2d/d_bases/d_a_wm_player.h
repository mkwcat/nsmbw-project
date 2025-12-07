#pragma once

#include "d_bases/d_wm_seManager.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_manager.h"
#include "d_system/d_wm_player_base.h"
#include "machine/m_vec.h"

class daWmPlayer_c_0x29C
{
public:
    u32 m_0x0;

    virtual ~daWmPlayer_c_0x29C();
};

class daWmPlayer_c : public dWmPlayerBase_c
{
    SIZE_ASSERT(0x30C);

    /* 0x060 VTABLE 0x809893F8 */

public:
    // Constants and Types
    // ^^^^^^

    static constexpr u32 SUBPLAYER_COUNT = 8;

public:
    // Structors
    // ^^^^^^

    /* 0x809027C0 */
    daWmPlayer_c();

    /**
     * VT+0x48 0x80902890
     * Destroys the base.
     */
    virtual ~daWmPlayer_c() override;

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80902960
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x80902B30
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    virtual PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x809029E0
     * do method for the execute operation.
     */
    virtual PACK_RESULT_e execute() override;

    /**
     * VT+0x2C 0x80902AC0
     * do method for the draw operation.
     */
    virtual PACK_RESULT_e draw() override;

    /* VT+0x60 0x80909940 */
    virtual void VT_0x60() override;

    /**
     * VT+0x70 0x8090BE30
     */
    virtual void VT_0x70() override;

    /**
     * VT+0x74 0x8090C160
     */
    virtual void VT_0x74() override;

    /**
     * VT+0x78 0x8090C8E0
     */
    virtual void VT_0x78() override;

    /**
     * VT+0x7C 0x8090C940
     */
    virtual void procDemoLose() override;

    /**
     * VT+0x80 0x8090C8C0
     */
    virtual void VT_0x80() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80902C50 */
    void UNDEF_80902C50();

    /* 0x80902BD0 */
    void createSubPlayers();

    /* 0x80902CA0 */
    void updateActivePlayers();

    /* 0x80902E30 */
    void setPlayerActive(u32 id, bool param2, bool param3);

    /* 0x80902ED0 */
    void UNDEF_80902ED0(u32 param_1, int param_2, PLAYER_CREATE_ITEM_e param_3);

    /* 0x80902FA0 @unofficial */
    void setSubPlayerPower();

    /* 0x80903380 */
    void UNDEF_80903380();

    /* 0x80903930 */
    void UNDEF_80903930();

    /* 0x80903ED0 */
    void UNDEF_80903ED0();

    /* 0x80906FE0 */
    void UNDEF_80906FE0(s32 param_1, s32 param_2);

    /* 0x80907590 */
    void UNDEF_80907590();

    /* 0x80907A60 */
    PATH_DIR_e getMovementDirection();

    /* 0x809093D0 */
    void initActiveCharaFlags();

    /* 0x8090CE10 */
    bool startGame(WORLD_e world, STAGE_e stage, u8 entrance);

public:
    // Static Methods
    // ^^^^^^

    /* 0x80100A50 */
    static int getSubPlayerNum();
    
    /* 0x80100B60 @unofficial */
    static const char* getSkeletonRoot(dPyMdlMng_c::ModelType_e character);

    /* 0x80100C50 */
    static dWmSeManager_c::WmPlyVoice_e getCourseInVoiceId(int node);

    /* 0x801011A0 */
    static bool isPlayerStarMode();

    /* 0x80101220 */
    static void startStarSound();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x1CC */ dPyMdlMng_c mModelManager;

    FILL(0x1D8, 0x1F0);

    /* 0x1F0 */ mVec3_c m0x1F0;

    FILL(0x1FC, 0x23C);

    /* 0x23C */ s32 m0x23C;
    /* 0x240 */ s32 m0x240;

    FILL(0x244, 0x25A);

    /* 0x25A */ u8 m0x25A;
    /* 0x25B */ u8 m0x25B;

    FILL(0x25C, 0x27C);

    /* 0x27C */ s32 m0x27C;

    FILL(0x280, 0x298);

    /* 0x298 */ float m0x298;
    /* 0x29C */ daWmPlayer_c_0x29C* mp0x29C;

    FILL(0x2A0, 0x2E0);

    /* 0x2E0 */ s32 m0x2E0;

    FILL(0x2E4, 0x2FC);

    /* 0x2FC */ u8 m0x2FC;

    FILL(0x2FD, 0x30C);

    /* 0x8042A480 */ static daWmPlayer_c* ms_instance;

    /* 0x809A0DB8 */ static dInfo_c::PlyConnectStage_e ms_plyConnectStage[SUBPLAYER_COUNT];
};
