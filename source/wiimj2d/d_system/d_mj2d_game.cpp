// d_mj2d_game.cpp
// NSMBW .text: 0x800CDFB0 - 0x800CE660

#include "d_mj2d_game.h"

#include "d_system/d_cyuukan.h"
#include "framework/f_feature.h"

const PLAYER_TYPE_e dMj2dGame_c::scDefaultPlayerTypes[PLAYER_COUNT] = {
    PLAYER_TYPE_e::MARIO,       PLAYER_TYPE_e::LUIGI,     PLAYER_TYPE_e::YELLOW_TOAD,
    PLAYER_TYPE_e::BLUE_TOAD,   PLAYER_TYPE_e::TOADETTE,  PLAYER_TYPE_e::PURPLE_TOADETTE,
    PLAYER_TYPE_e::ORANGE_TOAD, PLAYER_TYPE_e::BLACK_TOAD
};

// REMOVED: 0x800CDFB0 dMj2dGame_c::dMj2dGame_c()

[[nsmbw(0x800CDFC0)]]
void dMj2dGame_c::initialize() {
    *this     = {};

    mRevision = {SAVE_REVISION_MAJOR, SAVE_REVISION_MINOR};
    mGameCompletion |= GAME_COMPLETION_e::SAVE_EMPTY;

    for (int i = 0; i < WORLD_COUNT; i++) {
        onCourseDataFlag(static_cast<WORLD_e>(i), STAGE_e::RESCUE, COURSE_COMPLETION_e::GOAL_MASK);
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        setPlrID(i, scDefaultPlayerTypes[i]);
        setPlrMode(i, PLAYER_MODE_e::NONE);
        setRest(i, 5);
        setCreateItem(i, PLAYER_CREATE_ITEM_e::NONE);
    }

    for (int i = 0; i < WORLD_COUNT; i++) {
        setKinopioCourseNo(static_cast<WORLD_e>(i), STAGE_e::COUNT);
        for (int j = 0; j < 4; j++) {
            setCSEnemyPosIndex(static_cast<WORLD_e>(i), j, -1);
            setCSEnemyWalkDir(static_cast<WORLD_e>(i), j, PATH_DIRECTION_e::INITIAL);
        }
    }

    setIbaraNow(2);
}

[[nsmbw(0x800CE110)]]
void dMj2dGame_c::versionUpdate() {
    if (mRevision.mMajor < SAVE_REVISION_MAJOR) {
        initialize();
    }

    mRevision = {SAVE_REVISION_MAJOR, SAVE_REVISION_MINOR};
}

[[nsmbw(0x800CE150)]]
void dMj2dGame_c::setPlrID(
    int player, PLAYER_TYPE_e character
) {
    mPlayerCharacter[player] = static_cast<PLAYER_TYPE_u8_e>(character);
}

[[nsmbw(0x800CE160)]]
PLAYER_TYPE_e dMj2dGame_c::getPlrID(
    int player
) const {
    return static_cast<PLAYER_TYPE_e>(mPlayerCharacter[player]);
}

[[nsmbw(0x800CE170)]]
void dMj2dGame_c::setPlrMode(
    int player, PLAYER_MODE_e powerup
) {
    mPlayerPowerup[player] = static_cast<PLAYER_MODE_u8_e>(powerup);
}

[[nsmbw(0x800CE180)]]
PLAYER_MODE_e dMj2dGame_c::getPlrMode(
    int player
) const {
    return static_cast<PLAYER_MODE_e>(mPlayerPowerup[player]);
}

[[nsmbw(0x800CE190)]]
void dMj2dGame_c::setRest(
    int player, u8 lives
) {
    mPlayerLife[player] = lives;
}

[[nsmbw(0x800CE1A0)]]
int dMj2dGame_c::getRest(
    int player
) const {
    return mPlayerLife[player];
}

[[nsmbw(0x800CE1B0)]]
void dMj2dGame_c::setCreateItem(
    int player, PLAYER_CREATE_ITEM_e flag
) {
    mPlayerCreateItem[player] =
        static_cast<PLAYER_CREATE_ITEM_u8_e>(flag & PLAYER_CREATE_ITEM_e::STAR_POWER);
}

[[nsmbw(0x800CE1C0)]]
PLAYER_CREATE_ITEM_e dMj2dGame_c::getCreateItem(
    int player
) const {
    return static_cast<PLAYER_CREATE_ITEM_e>(mPlayerCreateItem[player]) &
           PLAYER_CREATE_ITEM_e::STAR_POWER;
}

[[nsmbw(0x800CE1D0)]]
void dMj2dGame_c::setCoin(
    int player, s8 coins
) {
    mPlayerCoin[player] = coins;
}

[[nsmbw(0x800CE1E0)]]
s8 dMj2dGame_c::getCoin(
    int player
) const {
    return mPlayerCoin[player];
}

[[nsmbw(0x800CE1F0)]]
void dMj2dGame_c::setScore(
    u32 score
) {
    mScore = score;
}

[[nsmbw(0x800CE200)]]
int dMj2dGame_c::getScore() const {
    return mScore;
}

[[nsmbw(0x800CE210)]]
void dMj2dGame_c::setStaffCreditHighScore(
    u16 score
) {
    if (mStaffRollHighScore < score) {
        mStaffRollHighScore = score;
    }
}

[[nsmbw(0x800CE230)]]
int dMj2dGame_c::getStaffCreditHighScore() {
    return mStaffRollHighScore;
}

[[nsmbw(0x800CE240)]]
void dMj2dGame_c::onOtehonMenuOpenFlag(
    int movie
) {
    mOtehonMenuOpen[movie] = true;
}

[[nsmbw(0x800CE250)]]
bool dMj2dGame_c::isOtehonMenuOpenFlag(
    int movie
) const {
    return mOtehonMenuOpen[movie];
}

[[nsmbw(0x800CE270)]]
void dMj2dGame_c::setCollectCoin(WORLD_e world, STAGE_e stage, COURSE_COMPLETION_e coins);

[[nsmbw(0x800CE280)]]
int dMj2dGame_c::getTotalWorldCollectCoin(
    WORLD_e world
) {
    int coinCount = 0;
    for (int stage = 0; stage < STAGE_COUNT; stage++) {
        for (u32 coin = 0; coin < STAR_COIN_COUNT; coin++) {
            if (isCollectCoin(world, static_cast<STAGE_e>(stage), coin) & 0xFF) {
                coinCount++;
            }
        }
    }
    return coinCount;
}

[[nsmbw(0x800CE300)]]
u8 dMj2dGame_c::isCollectCoin(
    WORLD_e world, STAGE_e stage, int coin
) const {
    return 1 << coin & static_cast<u32>(mCourseCompletion[+world][+stage]);
}

[[nsmbw(0x800CE330)]]
void dMj2dGame_c::setStartKinokoKind(
    WORLD_e world, START_KINOKO_KIND_e kind
) {
    mStartKinokoType[+world] = kind;
}

[[nsmbw(0x800CE340)]]
dMj2dGame_c::START_KINOKO_KIND_e dMj2dGame_c::getStartKinokoKind(
    WORLD_e world
) const {
    return static_cast<START_KINOKO_KIND_e>(mStartKinokoType[+world]);
}

[[nsmbw(0x800CE350)]]
void dMj2dGame_c::setDeathCount(
    WORLD_e world, STAGE_e stage, bool isSwitchPressed, u8 count
) {
    {
        if (count >= SUPER_GUIDE_DEATH_COUNT && world < WORLD_e::NORMAL_WORLD_COUNT &&
            (stage <= STAGE_e::CASTLE || stage == STAGE_e::DOOMSHIP)) {
            mGameCompletion |= GAME_COMPLETION_e::SUPER_GUIDE_TRIGGERED;
        }

        // Hardcoded check for World 3-4
        if (isSwitchPressed && world == WORLD_e::WORLD_3 && stage == STAGE_e::STAGE_4) {
            setSwitchDeathCount(count);
        } else {
            mDeathCount[+world][+stage] = count;
        }
    }
}

[[nsmbw(0x800CE3B0)]]
int dMj2dGame_c::getDeathCount(
    WORLD_e world, STAGE_e stage, bool isSwitchPressed
) const {
    // [Hardcoded check for World 3-4]
    if (isSwitchPressed && world == WORLD_e::WORLD_3 && stage == STAGE_e::STAGE_4) {
        return getSwitchDeathCount();
    }
    return mDeathCount[+world][int(stage)];
}

[[nsmbw(0x800CE3E0)]]
void dMj2dGame_c::setSwitchDeathCount(
    u8 count
) {
    mDeathCountSwitch = count;
}

[[nsmbw(0x800CE3F0)]]
int dMj2dGame_c::getSwitchDeathCount() const {
    return mDeathCountSwitch;
}

[[nsmbw(0x800CE400)]]
void dMj2dGame_c::setContinue(
    int player, s8 continues
) {
    mPlayerContinue[player] = continues;
}

[[nsmbw(0x800CE410)]]
s8 dMj2dGame_c::getContinue(
    int player
) const {
    return mPlayerContinue[player];
}

[[nsmbw(0x800CE420)]]
void dMj2dGame_c::setStockItem(
    int item, s8 count
) {
    if (count > MAX_STOCK_ITEM) {
        count = MAX_STOCK_ITEM;
    }
    mStockItemCount[item] = count;
}

[[nsmbw(0x800CE440)]]
dMj2dGame_c::WORLD_COMPLETION_e dMj2dGame_c::isWorldDataFlag(
    WORLD_e world, WORLD_COMPLETION_e flag
) const {
    return flag & mWorldCompletion[+world];
}

[[nsmbw(0x800CE450)]]
void dMj2dGame_c::onWorldDataFlag(
    WORLD_e world, WORLD_COMPLETION_e flag
) {
    mWorldCompletion[+world] |= flag;
}

[[nsmbw(0x800CE470)]]
void dMj2dGame_c::offWorldDataFlag(
    WORLD_e world, WORLD_COMPLETION_e flag
) {
    mWorldCompletion[+world] &= ~flag;
}

[[nsmbw(0x800CE490)]]
dMj2dGame_c::COURSE_COMPLETION_e dMj2dGame_c::getCourseDataFlag(
    WORLD_e world, STAGE_e stage
) const {
    u8                  worldIndex = +world;
    u8                  levelIndex = +stage;
    COURSE_COMPLETION_e completion = mCourseCompletion[worldIndex][levelIndex];

    if (fFeat::completed_all_levels) {
        completion |= COURSE_COMPLETION_e::GOAL_MASK;
    }
    return completion;
}

[[nsmbw(0x800CE4B0)]]
bool dMj2dGame_c::isCourseDataFlag(
    WORLD_e world, STAGE_e stage, COURSE_COMPLETION_e flag
) const {
    if (fFeat::completed_all_levels) {
        return true;
    }
    return !!(flag & mCourseCompletion[+world][+stage]);
}

[[nsmbw(0x800CE4E0)]]
void dMj2dGame_c::onCourseDataFlag(
    WORLD_e world, STAGE_e stage, COURSE_COMPLETION_e flag
) {
    mCourseCompletion[+world][+stage] |= flag;
}

[[nsmbw(0x800CE500)]]
void dMj2dGame_c::offCourseDataFlag(
    WORLD_e world, STAGE_e stage, COURSE_COMPLETION_e flag
) {
    mCourseCompletion[+world][+stage] &= ~flag;
}

[[nsmbw(0x800CE520)]]
void dMj2dGame_c::setCSEnemyRevivalCnt(
    WORLD_e world, int enemy, int count
) {
    mEnemyRevivalCount[+world][enemy] = count;
}

[[nsmbw(0x800CE540)]]
u8 dMj2dGame_c::getCSEnemyRevivalCnt(
    WORLD_e world, int enemy
) const {
    return mEnemyRevivalCount[+world][enemy];
}

[[nsmbw(0x800CE560)]]
void dMj2dGame_c::setCSEnemySceneNo(
    WORLD_e world, int enemy, u8 subworld
) {
    mEnemySceneNo[+world][enemy] = subworld;
}

[[nsmbw(0x800CE580)]]
u8 dMj2dGame_c::getCSEnemySceneNo(
    WORLD_e world, int enemy
) const {
    return mEnemySceneNo[+world][enemy];
}

[[nsmbw(0x800CE5A0)]]
void dMj2dGame_c::setCSEnemyPosIndex(
    WORLD_e world, int enemy, u8 node
) {
    mEnemyPosIndex[+world][enemy] = node;
}

[[nsmbw(0x800CE5C0)]]
s8 dMj2dGame_c::getCSEnemyPosIndex(
    WORLD_e world, int enemy
) const {
    return mEnemyPosIndex[+world][enemy];
}

[[nsmbw(0x800CE5E0)]]
void dMj2dGame_c::setCSEnemyWalkDir(
    WORLD_e world, int enemy, PATH_DIRECTION_e direction
) {
    mEnemyWalkDir[+world][enemy] = direction;
}

[[nsmbw(0x800CE600)]]
PATH_DIRECTION_e dMj2dGame_c::getCSEnemyWalkDir(
    WORLD_e world, int enemy
) const {
    return mEnemyWalkDir[+world][enemy];
}

[[nsmbw(0x800CE620)]]
void dMj2dGame_c::setKinopioCourseNo(
    WORLD_e world, STAGE_e stage
) {
    mKinopioCourseNo[+world] = stage;
}

[[nsmbw(0x800CE630)]]
STAGE_e dMj2dGame_c::getKinopioCourseNo(
    WORLD_e world
) const {
    return mKinopioCourseNo[+world];
}

[[nsmbw(0x800CE640)]]
void dMj2dGame_c::setIbaraNow(
    int ibaraNow
) {
    mIbaraNow = ibaraNow;
}

[[nsmbw(0x800CE650)]]
u8 dMj2dGame_c::getIbaraNow() const {
    return mIbaraNow;
}

void dMj2dGame_c::getCheckpoint(
    dCyuukan_c* checkpoint
) {
    if (mCheckpoint.index < 0 || mCheckpoint.index > 1) {
        return;
    }
    if (!mCheckpoint.stage.isValid() || mCheckpoint.area > 3 || mCheckpoint.entrance == 0xFF) {
        return;
    }

    checkpoint->clear();
    checkpoint->mWorld             = mCheckpoint.stage.world;
    checkpoint->mStage             = mCheckpoint.stage.stage;
    checkpoint->mCourse            = mCheckpoint.area;
    checkpoint->mNextGoto          = mCheckpoint.entrance;
    checkpoint->mIndex             = mCheckpoint.index > 1 ? 0 : mCheckpoint.index;
    checkpoint->mCollectionCoin[0] = mCheckpoint.coin[0];
    checkpoint->mCollectionCoin[1] = mCheckpoint.coin[1];
    checkpoint->mCollectionCoin[2] = mCheckpoint.coin[2];
    checkpoint->mOwner[0]          = mCheckpoint.flag[0];
    checkpoint->mOwner[1]          = mCheckpoint.flag[1];
    checkpoint->mFlags             = mCheckpoint.face_left ? dCyuukan_c::FLAG_FACE_LEFT : 0;
}

void dMj2dGame_c::setCheckpoint(
    const dCyuukan_c* checkpoint
) {
    mCheckpoint = {
        .stage    = {checkpoint->mWorld, checkpoint->mStage},
        .area     = checkpoint->mCourse,
        .entrance = checkpoint->mNextGoto,
        .index    = static_cast<u8>(checkpoint->mIndex),
        .flag     = {checkpoint->mOwner[0], checkpoint->mOwner[1]},
        .coin =
            {checkpoint->mCollectionCoin[0], checkpoint->mCollectionCoin[1],
             checkpoint->mCollectionCoin[2]},
        .face_left = !!(checkpoint->mFlags & dCyuukan_c::FLAG_FACE_LEFT),
    };
}

void dMj2dGame_c::clearCheckpoint() {
    mCheckpoint = {};
}
