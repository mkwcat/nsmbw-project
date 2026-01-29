#pragma once

#include "d_profile/d_profile.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_base.h"
#include "d_system/d_fader.h"
#include "d_system/d_mj2d_game.h"
#include "framework/f_feature.h"
#include "machine/m_vec.h"

class dGameDisplay_c;
class dMiniGameCannon_c;
class dMiniGameWire_c;
class dModelPlayManager_c;
class dMessageWindow_c;
class dStaffCreditScore_c;

// TODO
struct dReplayPlay_c {
    FILL(0x00, 0x64);

    /* 0x64 */ u32 mFrameFlags;
    /* 0x68 */ u32 mPrevFrameFlags;
    /* 0x6C */ u32 mFrameInput;
    /* 0x70 */ u32 mPrevFrameInput;
    /* 0x74 */ u32 mFrameCount;
    /* 0x78 */ mVec3_c mFrameAccel;
    /* 0x84 */ mVec2_c mFrameAccelVertX;
    /* 0x8C */ mVec2_c mFrameAccelVertY;
    /* 0x94 */ mVec2_c mFrameAccelVertZ;
    /* 0x9C */ u16 mFrameTilt;
};

class dScStage_c : public dBase_c
{
public:
    // Constants and Types
    // ^^^^^^

    // @unofficial
    enum class GAME_MODE_e {
        UNKNOWN_0 = 0,
        UNKNOWN_2 = 2,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80924950 */
    bool CreatedLayouts() const;

    /* 0x809251F0 */
    void courseClear();

    /* 0x809253E0 */
    void restoreStartInfo();

public:
    // Static Methods
    // ^^^^^^

    /* 0x8005EC90 */
    static bool getCourseIn()
    {
        return m_isCourseIn;
    }

    /* 0x80101A70 */
    static dGameDisplay_c* getGameDisplay();

    /* 0x80101AA0 */
    static void setLoopType();

    /* 0x801020E0 @unofficial */
    static void setCollectionCoin(int coin, PLAYER_TYPE_e player);

    /* 0x801022C0 */
    static bool isNowReplay();

    /* 0x80102370 @unofficial */
    static void
    goToSceneAfterLevel(int profile, int sceneParam, int exitMode, dFader_c::fader_type_e faderType);

public:
    // Static Inline Methods
    // ^^^^^^

    static inline dMiniGameCannon_c* getMiniGameCannon()
    {
        if (dScStage_c::m_instance == nullptr) {
            return nullptr;
        }
        return dScStage_c::m_instance->mpMiniGameCannon;
    }

    static inline bool isGameStopAllowed()
    {
        if (!fFeat::disable_mode_change_pause) {
            return true;
        }

        return daPyMng_c::isOnePlayerInGame() || isNowReplay();
    }

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A4A8 */
    static dScStage_c* m_instance;

    /* 0x8042A4DC */
    static s32 m_goalType;

    /* 0x8042A4E0 */
    static u32 m_exeFrame;

    /* 0x8042A4E4 */
    static GAME_MODE_e m_gameMode;

    /* 0x8042A4FC */
    static bool m_isCourseIn;

    /* 0x8042A4FD */
    static bool m_isCourseOut;

    /* 0x8042A4FE */
    static bool m_isOtehonReturn;

    /* 0x8042A4FF */
    static bool m_isStaffCredit;

    /* 0x8042A500 */
    static s32 m_miniGame;

    /* 0x8042A504 */
    static u8 m_replayMode;

    /* 0x8042A506 */
    static bool m_isReplayGoal;

    /* 0x803744B0 */
    static PLAYER_TYPE_e mCollectionCoin[COLLECTION_COIN_COUNT];

    /* 0x803744D0 */
    static dReplayPlay_c* m_replayPlay_p[PLAYER_COUNT];

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0070, 0x11D4);

    /* 0x11D4 */ dGameDisplay_c* mpGameDisplay;

    FILL(0x11D8, 0x11E8);

    /* 0x11E8 */ dMiniGameCannon_c* mpMiniGameCannon;
    /* 0x11EC */ dMiniGameWire_c* mpMiniGameWire;
    /* 0x11F0 */ dModelPlayManager_c* mpModelPlayManager;
    /* 0x11F4 */ dMessageWindow_c* mpMessageWindow;
    FILL(0x11F8, 0x11FC);
    /* 0x11FC */ dStaffCreditScore_c* mpStaffCreditScore;

    FILL(0x1200, 0x120C);

    /* 0x120C */ WORLD_e mWorld;
    /* 0x120D */ STAGE_e mStage;
    /* 0x120E */ u8 mCourse; // A.k.a. Area
    /* 0x120F */ u8 mArea; // A.k.a. Zone
    /* 0x1210 */ u8 mLayer;
    /* 0x1211 */ u8 mGoto; // A.k.a Entrance

    OFFSET_ASSERT(0x1212);
};
