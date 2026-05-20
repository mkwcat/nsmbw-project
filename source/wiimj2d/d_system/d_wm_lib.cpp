// d_wm_lib.cpp
// NSMBW .text: 0x800F9380 - 0x800FD6A0

#include "d_wm_lib.h"

#include "d_system/d_game_key.h"

namespace dWmLib {

[[nsmbw_data(0x8031D6B4)]]
float sc_0x8031D6B4;

[[nsmbw(0x800F9380)]]
void GetStartPointNameFromRouteName(const char*, char*);

[[nsmbw(0x800F93D0)]]
void GetEndPointNameFromRouteName(const char*, char*);

[[nsmbw(0x800F9420)]]
void MakeRouteName(char*, const char*, const char*);

[[nsmbw(0x800F9480)]]
bool MakePointNameFromCourseNo(WorldNo, CourseNo, char*);

[[nsmbw(0x800F9640)]]
CourseNo GetCourseNoFromPointName(const char*);

[[nsmbw(0x800F9730)]]
void MakeKinokoHouseName(int, char*);

[[nsmbw(0x800F9840)]]
CourseNo GetKinokoHouseCourseNo(const char*);

[[nsmbw(0x800F9950)]]
StageType_e GetCourseTypeFromCourseNo(CourseNo);

[[nsmbw(0x800F9A40)]]
bool IsCourseTypeStageFromCourseNo(CourseNo);

[[nsmbw(0x800F9A80)]]
PointType_e GetPointTypeFromPointName(const char*);

int GetNodeNoFromPointName(
    const char*
) {
}

[[nsmbw(0x800F9B00)]]
dWmActor_c* __searchMapObjFromName(u16, int);

[[nsmbw(0x800F9B70)]]
dWmActor_c* SearchMapObjFromName(const char*);

[[nsmbw(0x800F9CB0)]]
dWmActor_c* SearchMapObjFromCourseNo(WorldNo, CourseNo);

[[nsmbw(0x800F9CF0)]]
dWmActor_c* SearchMapObjFromCsvIndex(u16, int);

[[nsmbw(0x800F9D60)]]
dWmEnemy_c* SearchEnemy(u16, int);

[[nsmbw(0x800F9DE0)]]
bool ProjectScreenPos(nw4r::math::VEC3*, const nw4r::math::VEC3&);

[[nsmbw(0x800F9E40)]]
void ConvertScreenPos(nw4r::math::VEC3*);

[[nsmbw(0x800F9EC0)]]
nw4r::math::VEC3 GetNormalizedScreenPos(const mVec2_c&, const mVec2_c&, const mVec2_c&);

[[nsmbw(0x800F9FB0)]]
nw4r::math::VEC3
GetNormalizedProjectScreenPos(const nw4r::math::VEC3&, const mVec2_c&, const mVec2_c&);

[[nsmbw(0x800FA020)]]
void UNDEF_0x800FA020(mVec2_c*, mVec2_c*);

[[nsmbw(0x800FA0D0)]]
void UNDEF_0x800FA0D0(float, mVec2_c*, mVec2_c*);

[[nsmbw(0x800FA180)]]
bool CheckHalfAreaX(const mVec3_c&);

[[nsmbw(0x800FA1F0)]]
bool CheckHalfAreaY(const mVec3_c&);

[[nsmbw(0x800FA260)]]
bool CheckOnCenterLineX(const mVec3_c&);

[[nsmbw(0x800FA2E0)]]
bool CheckOnCenterLineY(const mVec3_c&);

[[nsmbw(0x800FA360)]]
s32 UNDEF_0x800FA360(...);

[[nsmbw(0x800FA440)]]
SttsOpen_e GetOpenStatus(WorldNo, CourseNo);

[[nsmbw(0x800FA460)]]
SttsOpen_e GetOpenStatusCore(WorldNo, CourseNo, const dCsvData_c&);

[[nsmbw(0x800FA6F0)]]
SttsOpen_e OpenStatOverWrite(SttsOpen_e, SttsOpen_e);

[[nsmbw(0x800FA740)]]
s32 UNDEF_0x800FA740(...);

[[nsmbw(0x800FA7D0)]]
s32 UNDEF_0x800FA7D0(...);

[[nsmbw(0x800FA8F0)]]
RouteType_e GetRouteType(const char*);

[[nsmbw(0x800FA9D0)]]
ClearStatus_e GetClearStatus(WorldNo, CourseNo);

[[nsmbw(0x800FAAD0)]]
PlayResultStatus_e GetCurrentPlayResultStatus(int, int, int);

[[nsmbw(0x800FAC80)]]
PlayResultStatus_e GetCurrentPlayResultStatus();

[[nsmbw(0x800FAE20)]]
bool IsCourseOpened(WorldNo, CourseNo);

[[nsmbw(0x800FAE50)]]
bool IsCourseOpened(SttsOpen_e);

[[nsmbw(0x800FAE70)]]
bool IsCourseOmoteClear(WorldNo, CourseNo);

[[nsmbw(0x800FAEC0)]]
bool IsCourseUraClear(WorldNo, CourseNo);

[[nsmbw(0x800FAF20)]]
bool IsCourseOtasukeClear(WorldNo, CourseNo);

[[nsmbw(0x800FAF50)]]
bool IsCourseClear(WorldNo, CourseNo);

[[nsmbw(0x800FAF90)]]
bool IsCourseFirstOmoteClear(WorldNo, CourseNo, int);

[[nsmbw(0x800FB080)]]
bool IsCourseFirstUraClear(WorldNo, CourseNo, int);

[[nsmbw(0x800FB150)]]
bool IsCourseFirstClear(WorldNo, CourseNo);

[[nsmbw(0x800FB260)]]
bool IsCourseOtasukeClearSimple(WorldNo, CourseNo);

[[nsmbw(0x800FB2B0)]]
bool IsCourseUraOtasukeClearSimple(WorldNo, CourseNo);

[[nsmbw(0x800FB300)]]
bool IsCourseOmoteClearSimple(WorldNo, CourseNo);

[[nsmbw(0x800FB350)]]
bool IsCourseUraClearSimple(WorldNo, CourseNo);

[[nsmbw(0x800FB3A0)]]
bool IsCourseFailed(WorldNo, CourseNo, int);

[[nsmbw(0x800FB3E0)]]
bool IsWorldOpen(WorldNo);

[[nsmbw(0x800FB430)]]
bool IsAirshipCleared(WorldNo);

[[nsmbw(0x800FB440)]]
int getZoromeTime();

[[nsmbw(0x800FB450)]]
void clearZoromeTime();

[[nsmbw(0x800FB460)]]
StartPointKinokoHouseKindNum getStartPointKinokoHouseKindNum();

[[nsmbw(0x800FB490)]]
void setStartPointKinokoHouseKindNum(StartPointKinokoHouseKindNum);

[[nsmbw(0x800FB4D0)]]
bool isStartPointKinokoHouseStar();

[[nsmbw(0x800FB520)]]
bool isStartPointKinokoHouse1up();

[[nsmbw(0x800FB570)]]
bool isStartPointKinokoHouseRed();

[[nsmbw(0x800FB5C0)]]
bool getMaskAnimeMaterial(dWmMapModel_c*, const char*, char*);

[[nsmbw(0x800FB780)]]
void copyRouteName(const char* src, char* dest);

[[nsmbw(0x800FB7D0)]]
void findRouteByMaterial(const char*, int, char*);

[[nsmbw(0x800FB900)]]
void findShortMaterial(const char*, int, char*);

[[nsmbw(0x800FBA10)]]
bool isMaskAnimeFinish(const char*, char, char);

[[nsmbw(0x800FBAA0)]]
bool checkIsAllPlayerWaitDemo();

[[nsmbw(0x800FBAF0)]]
void procCourseClear(bool isSecretExit, bool isSuperGuide, WORLD_e world, STAGE_e stage);

[[nsmbw(0x800FBE40)]]
void procCourseGameOver(bool keepKinokoMessageState);

[[nsmbw(0x800FBEB0)]]
void procRestoreAllKinokoHouse();

[[nsmbw(0x800FBEF0)]]
bool isKinopioHouseUsed();

[[nsmbw(0x800FBF70)]]
void procRestoreKinokoHouse(WorldNo);

[[nsmbw(0x800FBFE0)]]
void procClearCourseDataFlag(WorldNo world, CourseNo stage, int);

[[nsmbw(0x800FC040)]]
int getKoopaShipWorld();

[[nsmbw(0x800FC0C0)]]
bool isKoopaShipOnCurrentWorld();

[[nsmbw(0x800FC100)]]
bool isKoopaShipAnchor();

[[nsmbw(0x800FC150)]]
StartPointType_e getStartPointType();

[[nsmbw(0x800FC1B0)]]
bool hasKoopaShipStop();

[[nsmbw(0x800FC250)]]
int getEnemyRevivalCount(WorldNo world, int enemy);

[[nsmbw(0x800FC2A0)]]
void setEnemyRevivalCount(WorldNo world, int enemy, int count);

[[nsmbw(0x800FC300)]]
Dir_e getPointDir(const mVec3_c&, const mVec3_c&);

[[nsmbw(0x800FC3E0)]]
mVec3_c getDirVector(Dir_e direction);

[[nsmbw(0x800FC480)]]
bool isSpecialWorld();

[[nsmbw(0x800FC4A0)]]
int getMaxCollectionCoinNum(WorldNo world);

[[nsmbw(0x800FC510)]]
int getRestCollectionCoinNum(WorldNo world);

[[nsmbw(0x800FC580)]]
bool isSpecialWorldCourseOpen(WorldNo world);

[[nsmbw(0x800FC590)]]
void UNDEF_0x800FC590(float, mVec3_c*, const mVec3_c&, Dir_e);

[[nsmbw(0x800FC600)]]
bool getModelNodePos(const m3d::bmdl_c*, const char*);

[[nsmbw(0x800FC670)]]
bool getModelNodePos(const m3d::bmdl_c*, int);

[[nsmbw(0x800FC6D0)]]
void UNDEF_0x800FC6D0(...);

[[nsmbw(0x800FC900)]]
bool IsAntlionWorld();

[[nsmbw(0x800FC920)]]
bool IsKillerWorld();

[[nsmbw(0x800FC940)]]
bool IsBubbleWorld();

[[nsmbw(0x800FC960)]]
PLAYER_MODE_e GetPlayerModeForStockItem(
    STOCK_ITEM_e item, PLAYER_MODE_e currentMode, PLAYER_CREATE_ITEM_e& outCreateItem
);

[[nsmbw(0x800FCA50)]]
CourseNo GetFinalCourseNumForWorld(WorldNo world);

[[nsmbw(0x800FCA80)]]
bool IsFinalCourseForWorldCleared(WorldNo world);

[[nsmbw(0x800FCAD0)]]
bool IsSingleEntry();

[[nsmbw(0x800FCB00)]]
bool IsStartKinopioHelpDemo();

[[nsmbw(0x800FCB10)]]
void InitKinopioCourse();

[[nsmbw(0x800FCB30)]]
bool IsRescueCourseCleared(WorldNo world);

[[nsmbw(0x800FCB60)]]
bool IsKinopioHelpStart();

[[nsmbw(0x800FCBF0)]]
bool IsKinopioStartFirst();

[[nsmbw(0x800FCC00)]]
bool IsKinopioOpenCourseClear();

[[nsmbw(0x800FCC60)]]
bool IsKinopioOpenCourseFirstClear();

[[nsmbw(0x800FCCC0)]]
bool UpdateKinopioGame();

[[nsmbw(0x800FCDB0)]]
bool SelectKinopioGameCourse(WorldNo world);

[[nsmbw(0x800FCEB0)]]
bool IsKinopioLifeUpdatable();

[[nsmbw(0x800FCEC0)]]
void ClearKinopioChukan();

[[nsmbw(0x800FCED0)]]
bool SetKinopioChukan(WorldNo world);

[[nsmbw(0x800FCF70)]]
int GetKinopioGameAllowedNum(WorldNo world);

[[nsmbw(0x800FD040)]]
CourseNo GetKinopioGameAllowedCourse(WorldNo world, int index);

[[nsmbw(0x800FD140)]]
bool IsKinopioChukanCourse(WorldNo world, CourseNo stage);

[[nsmbw(0x800FD1B0)]]
bool IsKinopioInChukan();

[[nsmbw(0x800FD1C0)]]
void RestoreKinopioHelpGameInfo();

[[nsmbw(0x800FD230)]]
bool getWorldStageFromCourseNum(
    WorldNo world, CourseNo course, WORLD_e& outWorld, STAGE_e& outStage
);

[[nsmbw(0x800FD240)]]
int getSpecialWorldMessageId(int);

[[nsmbw(0x800FD290)]]
fProfName getWorldBossProfID(WorldNo);

[[nsmbw(0x800FD300)]]
void savePlayerPosInfo();

[[nsmbw(0x800FD3F0)]]
void IsAllComplete();

[[nsmbw(0x800FD420)]]
void IsKoopaJrEvent(int, int);

[[nsmbw(0x800FD4A0)]]
dGameKeyCore_c::Type_e isYokoCon(
    int controllerNo
) {
    // Originally, this function returned true
    // Only if the controller type was sideways Wii Remote
    // Since we need to add Classic + GC support for the only caller of isYokoCon
    // I'm changing how the function works completely
    return dGameKey_c::m_instance->mpCores[controllerNo]->mType;
}

[[nsmbw(0x800FD4C0)]]
void isCourseComplete(int, int);

} // namespace dWmLib
