#pragma once

#include "d_system/d_cyuukan.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_start_info.h"
#include <mkwcat/Enum.h>

class dInfo_c {
    VTABLE(0x000, dInfo_c, 0x80315EA0);

public:
    // Constants and Types
    // ^^^^^^

    /* @unofficial */
    enum class DemoType_e {
        NONE         = 0,
        SUPER_GUIDE  = 1,
        TITLE        = 2,
        TITLE_REPLAY = 3,
        HINT_MOVIE   = 4,
    };

    enum class OtehonType_e : u8 {
        SUPER_SKILLS = 0,
        ENDLESS_1UPS = 1,
        STAR_COIN    = 2,
        SECRET_EXIT  = 3,
    };

    /* @unofficial */
    enum class MultiClearState_e {
        NONE           = 0, ///< Course is uncleared
        NOW_CLEAR      = 1, ///< Cleared by some players, activates the button frame
        CLEAR          = 2, ///< Cleared by some players, button frame is already active
        NOW_TEAM_CLEAR = 3, ///< Cleared by all players, activates the button frame
        TEAM_CLEAR     = 4, ///< Cleared by all players, button frame is already active
    };

    enum class IbaraMode_e {};

    /* @unofficial */
    enum class PlyConnectStage_e {
        OFF    = 0,
        SETUP  = 1,
        SELECT = 2,
        ENTER  = 3,
    };

    enum class GameFlag_e : u32 {
        MULTI_MODE   = 4_bit,
        FREE_FOR_ALL = 5_bit,
        COIN_BATTLE  = 6_bit,
    };

    /* @unofficial? */
    struct StageNo_s {
        WORLD_e world;
        STAGE_e stage;

        constexpr bool isInSaveGame() const {
            return world < WORLD_e::COUNT && stage < STAGE_e::COUNT;
        }

        constexpr bool operator==(
            const StageNo_s& other
        ) const {
            return world == other.world && stage == other.stage;
        }

        constexpr bool operator==(
            const STAGE_e& stage
        ) const {
            return this->stage == stage;
        }

        constexpr bool operator==(
            const WORLD_e& world
        ) const {
            return this->world == world;
        }

        constexpr operator STAGE_e() const { return stage; }

        constexpr operator WORLD_e() const { return world; }
    };

    struct StartGameInfo_s {
        SIZE_ASSERT(0x10);

        /**
         * Time the demo will end after.
         */
        /* 0x00 */ u32 demoTime;

        /**
         * Hint movie kind.
         */
        /* 0x04 */ OtehonType_e otehonType;

        /**
         * NextGoto number (a.k.a. entrance).
         */
        /* 0x05 */ u8 nextGotoNo;

        /**
         * Course number (a.k.a. area).
         */
        /* 0x06 */ u8 courseNo;

        /**
         * Is a replay/demo.
         */
        /* 0x07 */ bool isDemo;

        /**
         * The type of the demo.
         */
        /* 0x08 */ DemoType_e demoType;

        /* 0x0C */ StageNo_s  stage1;
        /* 0x0E */ StageNo_s  stage2;
    };

    struct enemy_s {
        SIZE_ASSERT(0x10);

        /* 0x00 */ int mSceneNo;
        /* 0x04 */ int mPosIndex;
        /* 0x08 */ int mWalkDir;
        /* 0x0C */ u8  mRevivalCnt;
    };

    /* @unofficial */
    struct MultiCourse_s {
        SIZE_ASSERT(0x8);

        /* 0x00 */ u8                mWorld;
        /* 0x01 */ u8                mLevel;

        /* 0x04 */ MultiClearState_e mClearState;
    };

    static constexpr u32 ORIGINAL_SIZE = 0xB5C;

public:
    // Structors
    // ^^^^^^

    /* 0x800BB0E0 */
    dInfo_c();

    /* VT+0x8 0x800BB130 */
    virtual ~dInfo_c();

    /**
     * Recreate the dInfo_c instance for the mod.
     */
    dInfo_c(dInfo_c* old);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800BB180 */
    void PlayerStateInit();

    /* 0x800BB1C0 */
    void CourseSelectInit();

    /* 0x800BB330 */
    void addStockItem(int item);

    /* 0x800BB380 */
    void subStockItem(int item);

    /* 0x800BB3D0 */
    u8 getStockItem(int item) const;

    /* 0x800BB410 */
    void clsStockItem(int item);

    /* 0x800BB5B0 */
    void initMultiMode();

    /* 0x800BB7D0 */
    void startGame(const StartGameInfo_s& startGameInfo);

    /* 0x800BB8D0 */
    void startStaffCredit();

    /* 0x800BB940 */
    void initStage();

    /* 0x800BBBC0 */
    void SetWorldMapEnemy(int world, int index, const enemy_s& enemy);

    /* 0x800BBC00 */
    const dInfo_c::enemy_s& GetWorldMapEnemy(int world, int index);

    /* 0x800BBCA0 */
    void SetIbaraNow(int i, IbaraMode_e mode);

    /* 0x800BBCB0 */
    void SetIbaraOld(int i, IbaraMode_e mode);

    /* 0x800BBCC0 */
    IbaraMode_e GetIbaraNow(int i);

    /* 0x800BBCD0 */
    IbaraMode_e GetIbaraOld(int i);

public:
    // Inline Nethods
    // ^^^^^^

    inline PlyConnectStage_e getPlyConnectStage(
        u32 index
    ) {
        if (index < 4) {
            return mPlyConnectStage[index];
        } else {
            return mExPlyConnectStage[index - 4];
        }
    }

    inline PlyConnectStage_e& setPlyConnectStage(
        u32 index, PlyConnectStage_e value
    ) {
        if (index < 4) {
            return mPlyConnectStage[index] = value;
        } else {
            return mExPlyConnectStage[index - 4] = value;
        }
    }

    static inline bool isPipeRandomizer() {
        return dSaveMng_c::m_instance->getSaveGame()->getPipeRandomizerMode() !=
               dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::DISABLED;
    }

    /* 0x807823C0 */
    static void clearGameFlag(
        GameFlag_e flag
    ) {
        mGameFlag = static_cast<GameFlag_e>(static_cast<u32>(mGameFlag) & ~static_cast<u32>(flag));
    }

    static inline bool isGameFlag(
        GameFlag_e flag
    ) {
        return (static_cast<u32>(mGameFlag) & static_cast<u32>(flag)) != 0;
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ s32        m0x004;

    /* 0x008 */ dCyuukan_c mCyuukan;

    /* 0x03C */ WORLD_e    mWorld;
    /* 0x040 */ int        mWmSceneNo;
    /* 0x044 */ int        mWmNode;
    /* 0x048 */ s32        m0x048;

    FILL(0x04C, 0x060);

    /* 0x060 */ s32 m0x060;
    /* 0x064 */ int m_zoromeTime;
    /* 0x068 */ s32 m0x068;
    /* 0x06C */ u8  m0x06C;

    FILL(0x06D, 0x380);

    /**
     * The status of the World 3 switch.
     */
    /* 0x380 */ bool              mSwitchOn;

    /* 0x384 */ PlyConnectStage_e mPlyConnectStage[4];
    /* 0x394 */ u8                m0x394;
    /* 0x395 */ STAGE_e           mKinopioCourseNo[WORLD_COUNT];
    /* 0x39F */ STAGE_e           mStage0x39F[WORLD_COUNT];
    /* 0x3A9 */ bool              mKinopioCourseInvalid[WORLD_COUNT];

    FILL(0x3B3, 0x3CC);

    /* 0x3CC */ int mPlayerCount;

    FILL(0x3D0, 0x3E4);

    /* 0x3E4 */ int mMultiCurrPage;
    /* 0x3E8 */ int mMultiCurrButton;
    /* 0x3EC */ int mCoinBattleWin[4];

    FILL(0x3FC, 0x400);

    /* 0x400 */ MultiCourse_s mCoinCourse[10][10];
    /* 0x720 */ MultiCourse_s mCoinFavorite[10];
    /* 0x770 */ MultiCourse_s mFreeCourse[10][10];
    /* 0xA90 */ MultiCourse_s mFreeFavorite[10];

    FILL(0xAE0, 0xAF4);

    /* 0xAF4 */ int mCyuukanState;

    FILL(0xAF8, 0xAFC);

    /* 0xAFC */ u8 m0xAFC;

    FILL(0xAFD, 0xAFE);

    /* 0xAFE */ u8 m0xAFE[4][22];

    /* 0xB56 */ u8 m0xB56[4];

    FILL(0xB5A, 0xB5C);
    OFFSET_ASSERT(0xB5C);

#define OFFSET_dInfo_c_mExPlayerActiveMode 0xB5C
    /* 0xB5C */ PlyConnectStage_e mExPlyConnectStage[PLAYER_COUNT - 4] = {};

#define OFFSET_dInfo_c_mEx0xAFE (OFFSET_dInfo_c_mExPlayerActiveMode + (PLAYER_COUNT - 4) * 4)
#define ADJUST_dInfo_c_mEx0xAFE (OFFSET_dInfo_c_mEx0xAFE - 0xAFE - 4 * 22)
    /* 0xB6C? */ u8 mEx0xAFE[PLAYER_COUNT - 4][22] = {};

#define OFFSET_dInfo_c_mEx0xB56 (OFFSET_dInfo_c_mEx0xAFE + (PLAYER_COUNT - 4) * 22)
#define ADJUST_dInfo_c_mEx0xB56 (OFFSET_dInfo_c_mEx0xB56 - 0xB56 - 4)
    /* 0xBC4? */ u8 mEx0xB56[PLAYER_COUNT - 4] = {};

    /* 0xBC8 */ int mExCoinBattleWin[PLAYER_COUNT - 4];

public:
    // Static Variables
    // ^^^^^^

    /* 0x80315E98 */ static StartGameInfo_s m_startGameInfo;

    /* 0x80359054 */ static dStartInfo_c    m_startInfo;

    /* 0x8042A25C */ static dInfo_c*        m_instance;

    /* 0x8042A260 */ static GameFlag_e      mGameFlag;
};

ENUM_ALLOW_BITWISE(
    dInfo_c::GameFlag_e
)
