#pragma once

#include <component/c_bitmask.h>

/**
 * The maximum amount of ambush enemies per world map.
 */
#define AMBUSH_ENEMY_COUNT 4

/**
 * The total hint movie count.
 */
#define HINT_MOVIE_COUNT 70

/**
 * The maximum life count.
 */
#define MAX_LIVES 99

/**
 * The maximum inventory amount per item.
 */
#define MAX_STOCK_ITEM 99

/**
 * The total save slot count.
 */
#define SAVE_SLOT_COUNT 3

/**
 * The amount of Star Coins per level.
 */
#define STAR_COIN_COUNT 3

/**
 * The amount of starting lives.
 */
#define STARTING_LIVES_COUNT 5

/**
 * The amount of deaths required for the Super Guide to show.
 */
#define SUPER_GUIDE_DEATH_COUNT 8

/**
 * The identifiers for each character.
 */
enum PLAYER_TYPE_e {
    MARIO = 0,
    LUIGI = 1,
    BLUE_TOAD = 2,
    YELLOW_TOAD = 3,
    TOADETTE = 4,
    PURPLE_TOADETTE = 5,
    ORANGE_TOAD = 6,
    BLACK_TOAD = 7,
    COUNT,
};

#define CHARACTER_COUNT 8
#define PLAYER_COUNT 8 // Same as CHARACTER_COUNT
#define ORIGINAL_PLAYER_COUNT 4

/**
 * Various flags applied to the player on occasion.
 * @unofficial
 */
enum class PLAYER_CREATE_ITEM_e {
    NONE = 0,

    /**
     * Gives the player Star Power.
     */
    STAR_POWER = 0_bit,

    /**
     * Spawns a Yoshi along with the player.
     */
    YOSHI = 1_bit,

    /**
     * Spawns the player inside a bubble.
     */
    BUBBLE = 2_bit,

    /**
     * Spawns a Rescue Toad instead of the regular player character.
     */
    RESCUE_TOAD = 3_bit,
};

/**
 * The identifiers for each powerup.
 * @unofficial
 */
enum class PLAYER_MODE_e {
    NONE = 0,
    MUSHROOM = 1,
    FIRE_FLOWER = 2,
    MINI_MUSHROOM = 3,
    PROPELLER_SHROOM = 4,
    PENGUIN_SUIT = 5,
    ICE_FLOWER = 6,
    COUNT,
};

#define PLAYER_MODE_COUNT 7

/**
 * Stock item identifiers.
 * @unofficial
 */
enum class STOCK_ITEM_e : u8 {
    MUSHROOM = 0,
    FIRE_FLOWER = 1,
    PROPELLER_SHROOM = 2,
    ICE_FLOWER = 3,
    PENGUIN_SUIT = 4,
    MINI_MUSHROOM = 5,
    STAR = 6,
    COUNT,
};

#define STOCK_ITEM_COUNT 7

enum class ITEM_e : u8 {
    MUSHROOM = 0,
    FIRE_FLOWER = 1,
    STAR = 2,
    COIN = 3,
    ICE_FLOWER = 4,
    ONE_UP = 6,
    PROPELLER_SHROOM = 11,
    MINI_MUSHROOM = 13,
    PENGUIN_SUIT = 14,
    COIN2 = 16,
};

/**
 * The numbers corresponding to each level type.
 * @unofficial
 */
enum class STAGE_e : u8 {
    STAGE_1 = 0,
    STAGE_2 = 1,
    STAGE_3 = 2,
    STAGE_4 = 3,
    STAGE_5 = 4,
    STAGE_6 = 5,
    STAGE_7 = 6,
    STAGE_8 = 7,
    STAGE_9 = 8,
    STAGE_10 = 9,
    STAGE_11 = 10,
    STAGE_12 = 11,
    STAGE_13 = 12,
    STAGE_14 = 13,
    STAGE_15 = 14,
    STAGE_16 = 15,
    STAGE_17 = 16,
    STAGE_18 = 17,
    STAGE_19 = 18,
    COIN_BATTLE = 19,
    GHOST_HOUSE = 20,
    TOWER = 21,
    TOWER_2 = 22, // @unused
    CASTLE = 23,
    CASTLE_2 = 24, // @unused
    KINOKO_HOUSE = 25,
    KINOKO_HOUSE_2 = 26,
    KINOKO_HOUSE_3 = 27,
    KINOKO_HOUSE_4 = 28,
    KINOKO_HOUSE_5 = 29, // @unused
    KINOKO_HOUSE_6 = 30, // @unused
    KINOKO_HOUSE_7 = 31, // @unused
    ENEMY = 32,
    ENEMY_2 = 33,
    ENEMY_3 = 34,
    CANNON = 35,
    DOOMSHIP = 37,

    /**
     * When used, it loads the Toad Rescue level for the corresponding world.
     */
    RESCUE = 38,

    TITLE = 39,
    PEACH_CASTLE = 40,
    STAFFROLL = 41,

    COUNT = 42,
};

#define STAGE_COUNT 42

/**
 * The numbers corresponding to each world.
 */
enum class WORLD_e : u8 {
    WORLD_1 = 0,
    WORLD_2 = 1,
    WORLD_3 = 2,
    WORLD_4 = 3,
    WORLD_5 = 4,
    WORLD_6 = 5,
    WORLD_7 = 6,
    WORLD_8 = 7,
    WORLD_9 = 8,
    WORLD_10 = 9, // @unused
    COUNT = 10,

    LAST_WORLD = WORLD_8,
    LAST_SPECIAL_WORLD = WORLD_9,
    NORMAL_WORLD_COUNT = LAST_WORLD + 1,
    SPECIAL_WORLD_COUNT = LAST_SPECIAL_WORLD - LAST_WORLD,
};

#define WORLD_COUNT 10

#define COLLECTION_COIN_COUNT 3

#define MAX_LIVES 99

#define MAX_SCORE 999999999

#define SAVE_REVISION_MAJOR 14
#define SAVE_REVISION_MINOR 0

enum PATH_DIRECTION_e : s8 {
    NORMAL,
    REVERSE,
    INITIAL,
};

class dSaveMng_c;
class dMj2dJsonHandler_c;
class dScWMap_c;

/**
 * Save slot data holder.
 * The data stored here is temporary, as it is discarded unless the game is saved.
 * Size must be 32-byte aligned.
 */
class alignas(32) dMj2dGame_c
{
    /* ORIGINAL SIZE: 0x980 */

    friend class dSaveMng_c;
    friend class dMj2dJsonHandler_c;
    friend class dScWMap_c;

public:
    // Constants and Types
    // ^^^^^^

    struct Revision_s {
        u8 mMajor;
        u8 mMinor;
    };

    /**
     * The completion status of each level.
     */
    enum class COURSE_COMPLETION_e : u32 {
        /**
         * The first Star Coin was obtained.
         */
        COIN1_COLLECTED = 0_bit,

        /**
         * The second Star Coin was obtained.
         */
        COIN2_COLLECTED = 1_bit,

        /**
         * The third Star Coin was obtained.
         */
        COIN3_COLLECTED = 2_bit,

        COIN_MASK = COIN1_COLLECTED | COIN2_COLLECTED | COIN3_COLLECTED,

        /**
         * The regular exit was cleared.
         */
        GOAL_NORMAL = 4_bit,

        /**
         * The secret exit was cleared.
         */
        GOAL_SECRET = 5_bit,

        GOAL_MASK = GOAL_NORMAL | GOAL_SECRET,

        /**
         * The regular exit was cleared with the Super Guide.
         */
        SUPER_GUIDE_GOAL_NORMAL = 7_bit,

        /**
         * The secret exit was cleared with the Super Guide.
         */
        SUPER_GUIDE_GOAL_SECRET = 8_bit,

        SUPER_GUIDE_GOAL_MASK = SUPER_GUIDE_GOAL_NORMAL | SUPER_GUIDE_GOAL_SECRET,
    };

    /**
     * The completion status of each world.
     */
    enum class WORLD_COMPLETION_e : u8 {
        WORLD_UNLOCKED = 0_bit,
    };

    /**
     * The overall completion status of the save slot.
     */
    enum class GAME_COMPLETION_e : u8 {
        /**
         * The slot is empty.
         */
        SAVE_EMPTY = 0_bit,

        /**
         * The final boss was beaten.
         */
        FINAL_BOSS_BEATEN = 1_bit,

        /**
         * All levels were completed.
         */
        GOAL_ALL = 2_bit,

        /**
         * All the Star Coins in the regular worlds were obtained.
         */
        COIN_ALL = 3_bit,

        /**
         * All the Star Coins in the special worlds were obtained.
         */
        COIN_ALL_SPECIAL = 4_bit,

        /**
         * All the above objectives were completed.
         */
        GAME_COMPLETED = 5_bit,

        /**
         * The player died at least SUPER_GUIDE_DEATH_COUNT times in a single stage.
         */
        SUPER_GUIDE_TRIGGERED = 6_bit,
    };

    /**
     * The Toad House types at the start node of each world.
     * Values marked with R are used for houses that spawn after a successful Toad Rescue mission.
     */
    enum class START_KINOKO_KIND_e : u8 {
        NONE = 0,
        YELLOW = 1,
        RED = 2,
        GREEN = 3,
        YELLOW_R = 4,
        RED_R = 5,
        GREEN_R = 6,
        COUNT,
    };

public:
    /**
     * Constructs the holder.
     */
    dMj2dGame_c();

    /**
     * Deletes the holder.
     */
    constexpr ~dMj2dGame_c() = default;
    /**
     * 0x800CDFC0
     * Initializes the slot data.
     */
    void initialize();

    /**
     * Sets a player's character. See PLAYER_TYPE_e.
     */
    void setPlrID(int player, PLAYER_TYPE_e character);

    /**
     * Gets a player's character. See PLAYER_TYPE_e.
     */
    PLAYER_TYPE_e getPlrID(int player) const;

    /**
     * Sets a player's powerup. See PLAYER_MODE_e.
     */
    void setPlrMode(int player, PLAYER_MODE_e powerup);

    /**
     * Gets a player's powerup. See PLAYER_MODE_e.
     */
    PLAYER_MODE_e getPlrMode(int player) const;

    /**
     * Sets a player's life count.
     */
    void setRest(int player, u8 lives);

    /**
     * Gets a player's life count.
     */
    int getRest(int player) const;

    /**
     * Sets a player's createItem flag. See PLAYER_CREATE_ITEM_e. Flags other than
     * PLAYER_CREATE_ITEM_e::STAR_POWER are ignored.
     */
    void setCreateItem(int player, PLAYER_CREATE_ITEM_e flag);

    /**
     * Gets a player's createItem flag. See PLAYER_CREATE_ITEM_e. Flags other than
     * PLAYER_CREATE_ITEM_e::STAR_POWER are ignored.
     */
    PLAYER_CREATE_ITEM_e getCreateItem(int player) const;

    /**
     * Sets a player's coin count.
     */
    void setCoin(int player, s8 coins);

    /**
     * Gets a player's coin count.
     */
    s8 getCoin(int player) const;

    /**
     * Sets the score.
     */
    void setScore(u32 score);

    /**
     * Gets the score.
     */
    int getScore() const;

    /**
     * Sets the staff credit high score.
     */
    void setStaffCreditHighScore(u16 score);

    /**
     * Gets the staff credit high score.
     */
    int getStaffCreditHighScore();

    /**
     * Sets the given hint movie as bought.
     */
    void onOtehonMenuOpenFlag(int movie);

    /**
     * Checks if the given hint movie was bought.
     */
    bool isOtehonMenuOpenFlag(int movie) const;

    /**
     * 0x800CE270
     * Sets the obtained Star Coin(s) for the given world/level. See COURSE_COMPLETION_e.
     * Other flags are discarded.
     */
    void setCollectCoin(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e coins);

    /**
     * 0x800CE280
     * Gets the obtainable Star Coin count for the given world.
     */
    int getTotalWorldCollectCoin(WORLD_e world);

    /**
     * 0x800CE300
     * Checks if the given Star Coin has been obtained in the given world/level.
     */
    u8 isCollectCoin(WORLD_e world, STAGE_e level, int coin) const;

    /**
     * Sets the starting Toad House type in the given world. See START_KINOKO_KIND_e.
     */
    void setStartKinokoKind(WORLD_e world, START_KINOKO_KIND_e type);

    /**
     * Gets the starting Toad House type in the given world. See START_KINOKO_KIND_e.
     */
    START_KINOKO_KIND_e getStartKinokoKind(WORLD_e world) const;

    /**
     * 0x800CE350
     * Sets the death count in a specific stage.
     * @param world The world.
     * @param level The level.
     * @param isSwitchPressed If the worldmap switch was activated [only used for level 3-4].
     * @param count The death count.
     */
    void setDeathCount(WORLD_e world, STAGE_e level, bool isSwitchPressed, u8 count);

    /**
     * Gets the death count in a specific stage.
     * @param world The world.
     * @param level The level.
     * @param isSwitchPressed If the worldmap switch was activated [only used for level 3-4].
     * @return The death count.
     */
    int getDeathCount(WORLD_e world, STAGE_e level, bool isSwitchPressed) const;

    /**
     * Sets a player 's continue count.
     */
    void setContinue(int player, s8 continues);

    /**
     * Gets a player's continue count.
     */
    s8 getContinue(int player) const;

    /**
     * Sets the inventory amount for the given item.
     */
    void setStockItem(int item, s8 count);

    inline s8 getStockItem(int item)
    {
        return mStockItemCount[item];
    }

    /**
     * 0x800CE440
     * Checks if the completion flag(s) for the given world is set.
     */
    WORLD_COMPLETION_e isWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag) const;

    /**
     * 0x800CE450
     * Sets the specified flag(s) for the given world.
     */
    void onWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag);

    /**
     * 0x800CE470
     * Unsets the specified flag(s) for the given world.
     */
    void offWorldDataFlag(WORLD_e world, WORLD_COMPLETION_e flag);

    /**
     * 0x800CE4B0
     * Checks if the completion flag for the given world/level is set.
     */
    bool isCourseDataFlag(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e flag) const;

    /**
     * 0x800CE4E0
     * Sets the completion flag(s) for the given world/level.
     */
    void onCourseDataFlag(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e flag);

    /**
     * 0x800CE500
     * Unsets the completion flag(s) for the given world/level.
     */
    void offCourseDataFlag(WORLD_e world, STAGE_e level, COURSE_COMPLETION_e flag);

    /**
     * 0x800CE490
     * Gets all the completion flags for the given world/level.
     */
    COURSE_COMPLETION_e getCourseDataFlag(WORLD_e world, STAGE_e level) const;

    /**
     * Sets the revival counter for the given map enemy.
     */
    void setCSEnemyRevivalCnt(WORLD_e world, int enemy, int count);

    /**
     * Gets the revival counter for the given map enemy.
     */
    u8 getCSEnemyRevivalCnt(WORLD_e world, int enemy) const;

    /**
     * Sets the subworld number for the given map enemy.
     */
    void setCSEnemySceneNo(WORLD_e world, int enemy, u8 subworld);

    /**
     * Gets the subworld number for the given map enemy.
     */
    u8 getCSEnemySceneNo(WORLD_e world, int enemy) const;

    /**
     * Sets the path node for the given map enemy.
     */
    void setCSEnemyPosIndex(WORLD_e world, int enemy, u8 node);

    /**
     * Gets the path node for the given map enemy.
     */
    s8 getCSEnemyPosIndex(WORLD_e world, int enemy) const;

    /**
     * Sets the path direction for the given map enemy.
     * @details Values are: 0 (forwards), 1 (backwards) and 2 (initial value).
     * @todo Turn the value list into an enum and move it to the appropriate section once
     * decompiled.
     */
    void setCSEnemyWalkDir(WORLD_e world, int enemy, PATH_DIRECTION_e direction);

    /**
     * Gets the path direction for the given map enemy.
     */
    PATH_DIRECTION_e getCSEnemyWalkDir(WORLD_e world, int enemy) const;

    /**
     * Sets the Toad rescue level for the given world.
     */
    void setKinopioCourseNo(WORLD_e world, STAGE_e level);

    /**
     * Gets the Toad rescue level for the given world.
     */
    STAGE_e getKinopioCourseNo(WORLD_e world) const;

    /**
     * Sets the worldmap vine reshuffle counter.
     */
    void setIbaraNow(int ibaraNow);

    /**
     * Gets the worldmap vine reshuffle counter.
     */
    u8 getIbaraNow() const;

    bool isEmpty() const
    {
        return u8(mGameCompletion) & u8(GAME_COMPLETION_e::SAVE_EMPTY);
    }

    void setEmpty()
    {
        mGameCompletion = GAME_COMPLETION_e::SAVE_EMPTY;
    }

private:
    enum PLAYER_TYPE_u8_e : u8 {
    };

    enum PLAYER_MODE_u8_e : u8 {
    };

    enum PLAYER_CREATE_ITEM_u8_e : u8 {
    };

    /**
     * Checks that the save data version matches the current one and clears the slot if not.
     */
    void versionUpdate();

    /**
     * Sets the death count for World 3-4 for the worldmap switch-enabled variant.
     */
    void setSwitchDeathCount(u8 count);

    /**
     * Gets the death count for World 3-4 for the worldmap switch-enabled variant.
     */
    int getSwitchDeathCount() const;

    // Note: Commented offsets reflect the original layout, and are not updated with changes.

    /**
     * The save data version and subversion.
     */
    /* 0x00 */ Revision_s mRevision;

    /**
     * The overall completion of the save slot. See GAME_COMPLETION_e.
     */
    /* 0x02 */ GAME_COMPLETION_e mGameCompletion;

    /**
     * The world the player is currently in.
     */
    /* 0x03 */ u8 mCurrentWorld;

    /**
     * The subworld the player is currently in.
     */
    /* 0x04 */ u8 mCurrentSubWorld;

    /**
     * The path node the player is currently on.
     */
    /* 0x05 */ u8 mCurrentPathNode;

    /**
     * The worldmap vine reshuffle counter. [Value decreases every time a level is played. If it
     * reaches zero, the vines are moved].
     */
    /* 0x06 */ u8 mIbaraNow;

    /**
     * The status of the worldmap switch.
     */
    /* 0x07 */ bool mSwitchOn;

    /* 0x08 */ // u8 m0x008; // @unused

    /**
     * The inventory amount for each item.
     */
    /* 0x09 */ u8 mStockItemCount[STOCK_ITEM_COUNT];

    /**
     * The starting Toad House type for each world. See START_KINOKO_KIND_e.
     */
    /* 0x10 */ START_KINOKO_KIND_e mStartKinokoType[WORLD_COUNT];

    /**
     * The continue count for each player.
     */
    /* 0x1A */ u8 mPlayerContinue[PLAYER_COUNT];

    /**
     * The coin count for each player.
     */
    /* 0x1E */ s8 mPlayerCoin[PLAYER_COUNT];

    /**
     * The life count for each player.
     */
    /* 0x22 */ u8 mPlayerLife[PLAYER_COUNT];

    /**
     * The Star Power flag for each player. See PLAYER_CREATE_ITEM_e.
     */
    /* 0x26 */ PLAYER_CREATE_ITEM_u8_e mPlayerCreateItem[PLAYER_COUNT];

    /**
     * The character for each player. See PLAYER_TYPE_e.
     */
    /* 0x2A */ PLAYER_TYPE_u8_e mPlayerCharacter[PLAYER_COUNT];

    /**
     * The powerup for each player. See PLAYER_MODE_e.
     */
    /* 0x2E */ PLAYER_MODE_u8_e mPlayerPowerup[PLAYER_COUNT];

    /**
     * The completion flags for each world. See WORLD_COMPLETION_e.
     */
    /* 0x32 */ WORLD_COMPLETION_e mWorldCompletion[WORLD_COUNT];

    /**
     * The revival counter for each map enemy.
     */
    /* 0x3C */ u8 mEnemyRevivalCount[WORLD_COUNT][AMBUSH_ENEMY_COUNT];

    /* 0x64 */ // u16 m0x064; // @unused

    /**
     * The staff credits high score.
     */
    /* 0x66 */ u16 mStaffRollHighScore;

    /**
     * The regular score.
     */
    /* 0x68 */ u32 mScore;

    /**
     * The completion flags for each course.
     */
    /* 0x6C */ COURSE_COMPLETION_e mCourseCompletion[WORLD_COUNT][STAGE_COUNT];

    /**
     * The hint movie bought status for each movie.
     */
    cBitmask_c<HINT_MOVIE_COUNT> mOtehonMenuOpen;
    /* 0x6FC */ // bool mOtehonMenuOpen[HINT_MOVIE_COUNT];

    /**
     * The Toad Rescue level for each world.
     */
    /* 0x742 */ STAGE_e mKinopioCourseNo[WORLD_COUNT];

    /**
     * The subworld number for each map enemy.
     */
    /* 0x74C */ u8 mEnemySceneNo[WORLD_COUNT][AMBUSH_ENEMY_COUNT];

    /**
     * The path node for each map enemy.
     */
    /* 0x774 */ s8 mEnemyPosIndex[WORLD_COUNT][AMBUSH_ENEMY_COUNT];

    /**
     * The movement direction for each map enemy.
     */
    /* 0x79C */ PATH_DIRECTION_e mEnemyWalkDir[WORLD_COUNT][AMBUSH_ENEMY_COUNT];

    /**
     * The death count for each level. The value is cumulative, and not reset after clearing the
     * level.
     */
    /* 0x7C4 */ u8 mDeathCount[WORLD_COUNT][STAGE_COUNT];

    /**
     * The death count for the worldmap switch variant of World 3-4. See mDeathCount.
     */
    /* 0x968 */ u8 mDeathCountSwitch;

    /**
     * Ensures space for the CRC32 checksum.
     */
    // u32 mChecksumSpace;

public:
    /**
     * 0x802F1450
     * The default character for each player. @unofficial
     */
    static const PLAYER_TYPE_e scDefaultPlayerTypes[CHARACTER_COUNT];

    friend class dSaveMng_c;
};

template <typename T>
    requires(sizeof(T) == 1)
constexpr u8 ENUM_UNDERLYING()
{
    return 0;
}

template <typename T>
    requires(sizeof(T) == 2)
constexpr u16 ENUM_UNDERLYING()
{
    return 0;
}

template <typename T>
    requires(sizeof(T) == 4)
constexpr u32 ENUM_UNDERLYING()
{
    return 0;
}

template <typename T>
    requires(sizeof(T) == 8)
constexpr u64 ENUM_UNDERLYING()
{
    return 0;
}

#define ENUM_BITWISE_OPERATORS(_T)                                                                 \
    constexpr _T operator~(_T a)                                                                   \
    {                                                                                              \
        return static_cast<_T>(~static_cast<decltype(ENUM_UNDERLYING<_T>())>(a));                  \
    }                                                                                              \
    constexpr _T operator&(_T a, _T b)                                                             \
    {                                                                                              \
        return static_cast<_T>(                                                                    \
          static_cast<decltype(ENUM_UNDERLYING<_T>())>(a) &                                        \
          static_cast<decltype(ENUM_UNDERLYING<_T>())>(b)                                          \
        );                                                                                         \
    }                                                                                              \
    constexpr _T operator|(_T a, _T b)                                                             \
    {                                                                                              \
        return static_cast<_T>(                                                                    \
          static_cast<decltype(ENUM_UNDERLYING<_T>())>(a) |                                        \
          static_cast<decltype(ENUM_UNDERLYING<_T>())>(b)                                          \
        );                                                                                         \
    }                                                                                              \
    constexpr _T operator^(_T a, _T b)                                                             \
    {                                                                                              \
        return static_cast<_T>(                                                                    \
          static_cast<decltype(ENUM_UNDERLYING<_T>())>(a) ^                                        \
          static_cast<decltype(ENUM_UNDERLYING<_T>())>(b)                                          \
        );                                                                                         \
    }                                                                                              \
    constexpr _T& operator&=(_T& a, _T b)                                                          \
    {                                                                                              \
        return a = a & b;                                                                          \
    }                                                                                              \
    constexpr _T& operator|=(_T& a, _T b)                                                          \
    {                                                                                              \
        return a = a | b;                                                                          \
    }                                                                                              \
    constexpr _T& operator^=(_T& a, _T b)                                                          \
    {                                                                                              \
        return a = a ^ b;                                                                          \
    }                                                                                              \
    constexpr bool operator!(_T a)                                                                 \
    {                                                                                              \
        return !static_cast<decltype(ENUM_UNDERLYING<_T>())>(a);                                   \
    }

ENUM_BITWISE_OPERATORS(PLAYER_CREATE_ITEM_e);
ENUM_BITWISE_OPERATORS(dMj2dGame_c::COURSE_COMPLETION_e);
ENUM_BITWISE_OPERATORS(dMj2dGame_c::WORLD_COMPLETION_e);
ENUM_BITWISE_OPERATORS(dMj2dGame_c::GAME_COMPLETION_e);
