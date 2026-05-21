#pragma once

#include "d_system/d_game_key_core.h"
#include "d_system/d_mj2d_game.h"
#include "framework/f_profile.h"
#include "machine/m_3d_bmdl.h"
#include "machine/m_vec.h"

class dWmActor_c;
class dWmEnemy_c;
class fBase_c;
class dWmMapModel_c;
class dCsvData_c;

namespace dWmLib {

/* @unofficial */
enum class Dir_e {
    UP    = 0,
    DOWN  = 1,
    SOUTH = 2,
    NORTH = 3,
    WEST  = 4,
    EAST  = 5,
    COUNT = 6,
};

constexpr int DIR_COUNT = static_cast<int>(Dir_e::COUNT);

/* @unofficial */
enum class StageType_e {
    NORMAL   = 0,
    GHOST    = 1,
    TOWER    = 2,
    CASTLE   = 3,
    TOAD     = 4,
    ENEMY    = 5,
    WARP     = 6,
    STAGE_37 = 7, // @unused
    DOOMSHIP = 8,
    HOME     = 9,
    PEACH    = 10,
    INVALID  = 11,
};

/* @unofficial */
enum class PointType_e {
    INTERSECTION = 0, // F...
    PATH         = 1, // K...
    START_NODE   = 2, // W.S.
    STAGE        = 3, // W...
    OTHER        = 4,
};

/* @unofficial */
enum class RouteType_e {};

enum class SttsOpen_e {};

/* @unofficial */
enum class ClearStatus_e {};

/* @unofficial */
enum class PlayResultStatus_e {};

/* @unofficial */
enum class StartPointType_e {};

using WorldNo                      = int;
using CourseNo                     = int;
using PointNo                      = int;
using DirNo                        = int;
using StartPointKinokoHouseKindNum = u8;

/* 0x800F9380 */
void GetStartPointNameFromRouteName(const char*, char*);

/* 0x800F93D0 */
void GetEndPointNameFromRouteName(const char*, char*);

/* 0x800F9420 */
void MakeRouteName(char*, const char*, const char*);

/* 0x800F9480 */
bool MakePointNameFromCourseNo(WorldNo, CourseNo, char*);

/* 0x800F9640 */
CourseNo GetCourseNoFromPointName(const char*);

/* 0x800F9730 */
void MakeKinokoHouseName(int, char*);

/* 0x800F9840 */
CourseNo GetKinokoHouseCourseNo(const char*);

/* 0x800F9950 */
StageType_e GetCourseTypeFromCourseNo(CourseNo);

/* 0x800F9A40 */
bool IsCourseTypeStageFromCourseNo(CourseNo);

/* 0x800F9A80 */
PointType_e GetPointTypeFromPointName(const char*);

/* 0x800F9B00 */
dWmActor_c* __searchMapObjFromName(u16, int);

/* 0x800F9B70 */
dWmActor_c* SearchMapObjFromName(const char*);

/* 0x800F9CB0 */
dWmActor_c* SearchMapObjFromCourseNo(WorldNo, CourseNo);

/* 0x800F9CF0 */
dWmActor_c* SearchMapObjFromCsvIndex(u16, int);

/* 0x800F9D60 */
dWmEnemy_c* SearchEnemy(u16, int);

/* 0x800F9DE0 @unofficial */
bool ProjectScreenPos(nw4r::math::VEC3*, const nw4r::math::VEC3&);

/* 0x800F9E40 */
void ConvertScreenPos(nw4r::math::VEC3*);

/* 0x800F9EC0 */
nw4r::math::VEC3 GetNormalizedScreenPos(const mVec2_c&, const mVec2_c&, const mVec2_c&);

/* 0x800F9FB0 @unofficial */
nw4r::math::VEC3
GetNormalizedProjectScreenPos(const nw4r::math::VEC3&, const mVec2_c&, const mVec2_c&);

/* 0x800FA020 */
void UNDEF_0x800FA020(mVec2_c*, mVec2_c*);

/* 0x800FA0D0 */
void UNDEF_0x800FA0D0(float, mVec2_c*, mVec2_c*);

/* 0x800FA180 */
bool CheckHalfAreaX(const mVec3_c&);

/* 0x800FA1F0 */
bool CheckHalfAreaY(const mVec3_c&);

/* 0x800FA260 */
bool CheckOnCenterLineX(const mVec3_c&);

/* 0x800FA2E0 */
bool CheckOnCenterLineY(const mVec3_c&);

/* 0x800FA360 */
s32 UNDEF_0x800FA360(...);

/* 0x800FA440 */
SttsOpen_e GetOpenStatus(WorldNo, CourseNo);

/* 0x800FA460 */
SttsOpen_e GetOpenStatusCore(WorldNo, CourseNo, const dCsvData_c&);

/* 0x800FA6F0 */
SttsOpen_e OpenStatOverWrite(SttsOpen_e, SttsOpen_e);

/* 0x800FA740 */
s32 UNDEF_0x800FA740(...);

/* 0x800FA7D0 */
s32 UNDEF_0x800FA7D0(...);

/* 0x800FA8F0 */
RouteType_e GetRouteType(const char*);

/* 0x800FA9D0 */
ClearStatus_e GetClearStatus(WorldNo, CourseNo);

/* 0x800FAAD0 */
PlayResultStatus_e GetCurrentPlayResultStatus(int, int, int);

/* 0x800FAC80 */
PlayResultStatus_e GetCurrentPlayResultStatus();

/* 0x800FAE20 */
bool IsCourseOpened(WorldNo, CourseNo);

/* 0x800FAE50 */
bool IsCourseOpened(SttsOpen_e);

/* 0x800FAE70 */
bool IsCourseOmoteClear(WorldNo, CourseNo);

/* 0x800FAEC0 */
bool IsCourseUraClear(WorldNo, CourseNo);

/* 0x800FAF20 */
bool IsCourseOtasukeClear(WorldNo, CourseNo);

/* 0x800FAF50 */
bool IsCourseClear(WorldNo, CourseNo);

/* 0x800FAF90 */
bool IsCourseFirstOmoteClear(WorldNo, CourseNo, int);

/* 0x800FB080 */
bool IsCourseFirstUraClear(WorldNo, CourseNo, int);

/* 0x800FB150 */
bool IsCourseFirstClear(WorldNo, CourseNo);

/* 0x800FB260 */
bool IsCourseOtasukeClearSimple(WorldNo, CourseNo);

/* 0x800FB2B0 */
bool IsCourseUraOtasukeClearSimple(WorldNo, CourseNo);

/* 0x800FB300 */
bool IsCourseOmoteClearSimple(WorldNo, CourseNo);

/* 0x800FB350 */
bool IsCourseUraClearSimple(WorldNo, CourseNo);

/* 0x800FB3A0 */
bool IsCourseFailed(WorldNo, CourseNo, int);

/* 0x800FB3E0 */
bool IsWorldOpen(WorldNo);

/* 0x800FB430 */
bool IsAirshipCleared(WorldNo);

/* 0x800FB440 */
int getZoromeTime();

/* 0x800FB450 */
void clearZoromeTime();

/* 0x800FB460 */
StartPointKinokoHouseKindNum getStartPointKinokoHouseKindNum();

/* 0x800FB490 */
void setStartPointKinokoHouseKindNum(StartPointKinokoHouseKindNum);

/* 0x800FB4D0 */
bool isStartPointKinokoHouseStar();

/* 0x800FB520 */
bool isStartPointKinokoHouse1up();

/* 0x800FB570 */
bool isStartPointKinokoHouseRed();

/* 0x800FB5C0 @unofficial */
bool getMaskAnimeMaterial(dWmMapModel_c*, const char*, char*);

/* 0x800FB780 @unofficial */
void copyRouteName(const char* src, char* dest);

/* 0x800FB7D0 */
void findRouteByMaterial(const char*, int, char*);

/* 0x800FB900 */
void findShortMaterial(const char*, int, char*);

/* 0x800FBA10 @unofficial */
bool isMaskAnimeFinish(const char*, char, char);

/* 0x800FBAA0 */
bool checkIsAllPlayerWaitDemo();

/* 0x800FBAF0 @unofficial */
void procCourseClear(bool isSecretExit, bool isSuperGuide, WORLD_e world, STAGE_e stage);

/* 0x800FBE40 */
void procCourseGameOver(bool keepKinokoMessageState);

/* 0x800FBEB0 */
void procRestoreAllKinokoHouse();

/* 0x800FBEF0 */
bool isKinopioHouseUsed();

/* 0x800FBF70 */
void procRestoreKinokoHouse(WorldNo);

/* 0x800FBFE0 */
void procClearCourseDataFlag(WorldNo world, CourseNo stage, int);

/* 0x800FC040 */
int getKoopaShipWorld();

/* 0x800FC0C0 */
bool isKoopaShipOnCurrentWorld();

/* 0x800FC100 */
bool isKoopaShipAnchor();

/* 0x800FC150 */
StartPointType_e getStartPointType();

/* 0x800FC1B0 */
bool hasKoopaShipStop();

/* 0x800FC250 */
int getEnemyRevivalCount(WorldNo world, int enemy);

/* 0x800FC2A0 */
void setEnemyRevivalCount(WorldNo world, int enemy, int count);

/* 0x800FC300 */
Dir_e getPointDir(const mVec3_c&, const mVec3_c&);

/* 0x800FC3E0 @unofficial */
mVec3_c getDirVector(Dir_e direction);

/* 0x800FC480 */
bool isSpecialWorld();

/* 0x800FC4A0 */
int getMaxCollectionCoinNum(WorldNo world);

/* 0x800FC510 */
int isCollectionCoinPerfect(WorldNo world);

/* 0x800FC580 */
bool isSpecialWorldCourseOpen(WorldNo world);

/* 0x800FC590 */
void UNDEF_0x800FC590(float, mVec3_c*, const mVec3_c&, Dir_e);

/* 0x800FC600 */
bool getModelNodePos(const m3d::bmdl_c*, const char*);

/* 0x800FC670 */
bool getModelNodePos(const m3d::bmdl_c*, int);

/* 0x800FC6D0 */
void UNDEF_0x800FC6D0(...);

/* 0x800FC900 */
bool IsAntlionWorld();

/* 0x800FC920 */
bool IsKillerWorld();

/* 0x800FC940 */
bool IsBubbleWorld();

/* 0x800FC960 @unofficial */
PLAYER_MODE_e GetPlayerModeForStockItem(
    STOCK_ITEM_e item, PLAYER_MODE_e currentMode, PLAYER_CREATE_ITEM_e& outCreateItem
);

/* 0x800FCA50 @unofficial */
CourseNo GetFinalCourseNumForWorld(WorldNo world);

/* 0x800FCA80 @unofficial */
bool IsFinalCourseForWorldCleared(WorldNo world);

/* 0x800FCAD0 */
bool IsSingleEntry();

/* 0x800FCB00 */
bool IsStartKinopioHelpDemo();

/* 0x800FCB10 */
void InitKinopioCourse();

/* 0x800FCB30 @unofficial */
bool IsKinopioCourseCleared(WorldNo world);

/* 0x800FCB60 */
bool IsKinopioHelpStart();

/* 0x800FCBF0 */
bool IsKinopioStartFirst();

/* 0x800FCC00 */
bool IsKinopioOpenCourseClear();

/* 0x800FCC60 */
bool IsKinopioOpenCourseFirstClear();

/* 0x800FCCC0 */
bool UpdateKinopioGame();

/* 0x800FCDB0 @unofficial */
bool SelectKinopioGameCourse(WorldNo world);

/* 0x800FCEB0 */
bool IsKinopioLifeUpdatable();

/* 0x800FCEC0 */
void ClearKinopioChukan();

/* 0x800FCED0 @unofficial */
bool SetKinopioChukan(WorldNo world);

/* 0x800FCF70 @unofficial */
int GetKinopioGameAllowedNum(WorldNo world);

/* 0x800FD040 @unofficial */
CourseNo GetKinopioGameAllowedCourse(WorldNo world, int index);

/* 0x800FD140 @unofficial */
bool IsKinopioChukanCourse(WorldNo world, CourseNo stage);

/* 0x800FD1B0 */
bool IsKinopioInChukan();

/* 0x800FD1C0 */
void RestoreKinopioHelpGameInfo();

/* 0x800FD230 @unofficial */
bool getWorldStageFromCourseNum(
    WorldNo world, CourseNo course, WORLD_e& outWorld, STAGE_e& outStage
);

/* 0x800FD240 */
int getSpecialWorldMessageId(int);

/* 0x800FD290 */
fProfName getWorldBossProfID(WorldNo);

/* 0x800FD300 */
void savePlayerPosInfo();

/* 0x800FD3F0 */
void IsAllComplete();

/* 0x800FD420 */
void IsKoopaJrEvent(int, int);

/* 0x800FD4A0 */
dGameKeyCore_c::Type_e isYokoCon(int controllerNo);

/* 0x800FD4C0 */
void isCourseComplete(int, int);

/* 0x8031D6B4 */ extern float sc_0x8031D6B4;

} // namespace dWmLib
