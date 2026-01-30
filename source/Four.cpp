// Four.cpp
// Patches for various parts of the game for >4 players, that I did not feel like splitting and
// importing whole functions into the project.

#include "Four.h"

#include "d_player/d_s_boot.h"
#include "d_system/d_a_player_manager.h"
#include "mkwcat/AddressMapper.hpp"
#include <cstring>
#include <revolution/os.h>

struct FourPatch {
    consteval FourPatch(u32 address, u8 size, s8 offset = 0)
      : addressP1(address)
      , addressP2(mkwcat::AddressMapperP2.MapAddress(address))
      , addressE1(mkwcat::AddressMapperE1.MapAddress(address))
      , addressE2(mkwcat::AddressMapperE2.MapAddress(address))
      , addressJ1(mkwcat::AddressMapperJ1.MapAddress(address))
      , addressJ2(mkwcat::AddressMapperJ2.MapAddress(address))
      , addressK(mkwcat::AddressMapperK.MapAddress(address))
      , addressW(mkwcat::AddressMapperW.MapAddress(address))
      , addressC(mkwcat::AddressMapperC.MapAddress(address))
      , size(size)
      , offset(offset)
    {
    }

    u32 addressP1;
    u32 addressP2;
    u32 addressE1;
    u32 addressE2;
    u32 addressJ1;
    u32 addressJ2;
    u32 addressK;
    u32 addressW;
    u32 addressC;
    u8 size;
    s8 offset;

    static constexpr s8 NEGATIVE = -64;
};

constinit FourPatch FOUR_PATCH_LIST[] = {
  // dCourseSelectGuide_c::CollectionCoinSet
  {0x80010EC8 + 2, 2},

  // dSmallScore_c::DispWait
  {0x80015B04 + 2, 2},

  // TODO: dSmallScore_c::chgColor

  // daBullet_c::hitCallback
  {0x8001DE5C + 2, 2},

  // daEnDpakkunBase_c::hitCallback_Fire
  {0x8002D514 + 2, 2, -1},
  // daEnDpakkunBase_c::hitCallback_YoshiFire
  {0x8002D694 + 2, 2, -1},
  // daEnDpakkunBase_c::hitCallback_Star
  {0x8002D8F0 + 2, 2, -1},
  // daEnDpakkunBase_c::hitCallback_Shell
  {0x8002D9F8 + 2, 2, -1},
  // daEnDpakkunBase_c::kill
  {0x8002DB54 + 2, 2, -1},
  // daEnDpakkunBase_c::initializeState_DieIceBreak
  {0x8002E3D0 + 2, 2, -1},

  // daEnJimenPakkunBase_c::hitCallback_Fire
  {0x8002FB04 + 2, 2, -1},
  // daEnJimenPakkunBase_c::hitCallback_Shell
  {0x8002FC68 + 2, 2, -1},
  // daEnJimenPakkunBase_c::hitCallback_Star
  {0x8002FE04 + 2, 2, -1},
  // daEnJimenPakkunBase_c::hitCallback_YoshiFire
  {0x8002FF20 + 2, 2, -1},
  // daEnJimenPakkunBase_c::initializeState_DieOther
  {0x800304A0 + 2, 2, -1},
  // daEnJimenPakkunBase_c::initializeState_DieIceBreak
  {0x8003074C + 2, 2, -1},

  // daEnShell_c::~daEnShell_c
  {0x800380F0 + 2, 2},
  // daEnShell_c::kickSE
  {0x8003A418 + 2, 2, -1},
  // daEnShell_c::hitCallback_Ice
  {0x8003A84C + 2, 2},

  // daLiftRemoconMain_c::MultiRemoconShockSet
  {0x80043A00 + 2, 2},
  // daLiftRemoconMain_c::PlayerNoRideCheck
  {0x800441B4 + 2, 2},

  // dActor_c::searchNearPlayerNormal
  {0x80064848 + 2, 2},
  // dActor_c::searchNearPlayerLoop
  {0x800649CC + 2, 2},
  // dActor_c::checkAreaNo
  {0x80064B98 + 2, 2},
  // dActor_c::playKameHitSound
  {0x80065C00 + 2, 2, -1},
  // dActor_c::checkCarried
  {0x80066040 + 2, 2},

  // dActorMng_c::soroban_playercheck
  {0x80066D80 + 2, 2},

  // dAttention_c::UNDEF_800693e0
  {0x800694C8 + 2, 2},

  // dAudio::createNonPosSndObjPly
  {0x80069EF4 + 2, 2},
  // dAudio::deleteNonPosSndObjPly
  {0x8006A068 + 2, 2},

  // dBalloonMng_c::execute
  {0x8006C2CC + 2, 2},
  {0x8006C36C + 2, 2},

  // dBg_c::dBg_isFlyPlayer
  {0x800785AC + 2, 2},
  // dBg_c::calcAutoScroll
  {0x8007A5EC + 2, 2},

  // dCyuukan_c::checkEntry
  {0x8008EEE0 + 2, 2},
  // dCyuukan_c::isCyuukanStart
  {0x8008F038 + 2, 2},
  // dCyuukan_c::getPlrNo
  {0x8008F09C + 2, 2},

  // dEn_c::Area_X_check
  {0x80097890 + 2, 2},
  // dEn_c::Area_XY_check
  {0x80097974 + 2, 2},
  // dEn_c::PlayerCarryCheck
  {0x800979F8 + 2, 2},
  // dEn_c::setNicePoint_Death
  {0x80097E34 + 2, 2, -1},

  // dEnBossKoopaJrBase_c::setFireDamage
  {0x8009C0BC + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setFireDead
  {0x8009C1B0 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setStarDamage
  {0x8009C2B0 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setStarDead
  {0x8009C390 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setFumiDamage
  {0x8009C490 + 2, 2, -1},
  // dEnBossKoopaJrBase_c::setFumiDead
  {0x8009C570 + 2, 2, -1},

  // dEn_c::hitCallback_YoshiHipAttk
  {0x800A0344 + 2, 2},
  // dEn_c::hitCallback_Ice
  {0x800A0AC4 + 2, 2},
  // dEn_c::initializeState_DieFumi
  {0x800A14C8 + 2, 2},
  {0x800A1574 + 2, 2, -1},
  // dEn_c::initializeState_DieFall
  {0x800A16F8 + 2, 2},
  {0x800A17A4 + 2, 2, -1},
  // dEn_c::initializeState_DieIceVanish
  {0x800A1A48 + 2, 2, -1},

  // dEnTorideKokoopa_c::setFumiDamage
  {0x800A9204 + 2, 2, -1},
  // dEnTorideKokoopa_c::setFumiDead
  {0x800A9320 + 2, 2, -1},
  // dEnTorideKokoopa_c::setFireDamage
  {0x800A94D8 + 2, 2, -1},
  // dEnTorideKokoopa_c::setFireDead
  {0x800A95CC + 2, 2, -1},
  // dEnTorideKokoopa_c::setStarDamage
  {0x800A9794 + 2, 2, -1},
  // dEnTorideKokoopa_c::setStarDead
  {0x800A98B0 + 2, 2, -1},
  // dEnTorideKokoopa_c::setShellDamage
  {0x800A9C80 + 2, 2, -1},
  // dEnTorideKokoopa_c::setShellDead
  {0x800A9D7C + 2, 2, -1},
  // dEnTorideKokoopa_c::calcAttackTarget
  {0x800AA348 + 2, 2},

  // dMultiMng_c::setCollectionCoin
  {0x800CEC94 + 2, 2},
  {0x800CECB8 + 2, 2},
  {0x800CECDC + 2, 2},

  // PauseManager_c::setPause
  {0x800D152C + 2, 2},
  {0x800D157C + 2, 2},

  // dQuake_c::UNDEF_800d8940
  {0x800D8978 + 2, 2, -1},
  // dQuake_c::UNDEF_800d8a50
  {0x800D8AE8 + 2, 2},
  // dQuake_c::stopQuake
  {0x800D8BC4 + 2, 2},
  // dQuake_c::UNDEF_800d8ca0
  {0x800D8CB0 + 2, 2, -1},
  // dQuake_c::UNDEF_800d8d50
  {0x800D8DB0 + 2, 2},
  // dQuake_c::UNDEF_800d8e20
  {0x800D8EA4 + 2, 2},

  // UNDEF_800e2070 - Not sure what this is for or if it's ever used, player ID 5 will always score
  // a 1-up for everyone in this function fsr
  {0x800E2098 + 2, 2, +1},

  // dWaterWave_c::waveExecute
  {0x800EDDF8 + 2, 2},

  // daIce_c::deleteReady
  {0x8011BF34 + 2, 2},

  // daIce_c::UNDEF_8011d240
  {0x8011D288 + 2, 2, -1},
  // daIce_c::UNDEF_8011d320
  {0x8011D368 + 2, 2, -1},
  // daIce_c::checkUnderBreak
  {0x8011DEF8 + 2, 2, -1},
  // daIce_c::breakReq
  {0x8011EC7C + 2, 2, -1},

  // dAcPy_c::UNDEF_80147840
  {0x80147904 + 2, 2},

  // daYoshi_c::create
  {0x8014B964 + 2, 2},

  // dfukidashiManager_c::FUN_801572F0
  {0x801572FC + 2, 2},

  // dGameDisplay_c::create
  {0x80157EE0 + 2, 2},
  // dGameDisplay_c::AreaCheck
  {0x80158BA4 + 2, 2},
  // dGameDisplay_c::setCollect
  {0x80159D20 + 2, 2},

  // SndObjctPly::startFootSound
  {0x8019A850 + 2, 2},
  {0x8019A8B0 + 2, 2},

  // dStaffCreditScore_c::initializeState_No1PlayerKiMe
  {0x807AE954 + 2, 2},
  // dStaffCreditScore_c::executeState_No1PlayerKiMe
  {0x807AE9EC + 2, 2},

  // UNDEF_807bee40
  {0x807BEE88 + 2, 2},

  // UNDEF_807c3700
  {0x807C3804 + 2, 2},

  // daBombJrC_c::initializeState_DieFall
  {0x807C606C + 2, 2, -1},

  // daBossKameckDemo_c::executeState_BattleStDemo
  {0x807C8180 + 2, 2},

  // daBossKoopaDemo_c::executeState_Ready
  {0x807CB570 + 2, 2},
  {0x807CB624 + 2, 2},
  {0x807CB6C4 + 2, 2},
  // daBossKoopaDemo_c::initializeState_Start
  {0x807CBC88 + 2, 2},
  // daBossKoopaDemo_c::executeState_Start
  {0x807CBE60 + 2, 2},
  // daBossKoopaDemo_c::executeState_Battle
  {0x807CC03C + 2, 2},
  // daBossKoopaDemo_c::executeState_Battle
  {0x807CC100 + 2, 2, -1},
  // daBossKoopaDemo_c::executeState_Fall
  {0x807CC804 + 2, 2},
  {0x807CC854 + 2, 2},
  // TODO: More work needs to be done here
  // daBossKoopaDemo_c::initializeState_Magic
  {0x807CCE8C + 2, 2},
  {0x807CCF50 + 2, 2},
  // daBossKoopaDemo_c::executeState_Magic +TODO
  {0x807CD0B8 + 2, 2},
  {0x807CD238 + 2, 2},
  // daBossKoopaDemo_c::executeState_Escape
  {0x807CDC34 + 2, 2},
  {0x807CDD04 + 2, 2},
  {0x807CDF80 + 2, 2},
  {0x807CE304 + 2, 2},
  {0x807CE3DC + 2, 2, -1},
  // daBossKoopaDemo_c::executeState_End +TODO
  {0x807CE868 + 2, 2},
  {0x807CE8B8 + 2, 2},
  {0x807CEB18 + 2, 2},
  {0x807CED0C + 2, 2},
  {0x807CF028 + 2, 2},
  {0x807CF35C + 2, 2},
  {0x807CF3E4 + 2, 2},

  // daBossKoopaJrDemo_c::UNDEF_807d05c0
  {0x807D0650 + 2, 2},
  // daBossKoopaJrDemo_c::UNDEF_807d06d0
  {0x807D07B0 + 2, 2},
  // daBossKoopaJrDemo_c::UNDEF_807d0a30
  {0x807D0BAC + 2, 2},
  // daBossKoopaJrDemo_c::executeState_BattleEdDemo
  {0x807D1878 + 2, 2},
  {0x807D1944 + 2, 2},
  {0x807D19B0 + 2, 2},
  {0x807D1ABC + 2, 2},
  {0x807D1B74 + 2, 2},
  // daBossKoopaJrDemo_c::executeState_DemoAfterJrCBattle
  {0x807D1E5C + 2, 2},
  {0x807D1F2C + 2, 2},
  {0x807D1FB4 + 2, 2},
  {0x807D20A0 + 2, 2},
  {0x807D2130 + 2, 2},

  // UNDEF_807d68b0
  {0x807D68D0 + 2, 2},

  // UNDEF_807d7440
  {0x807D7488 + 2, 2},

  // daCastleKokoopaDemo1st::checkBattleStDemo +TODO
  {0x807DAD80 + 2, 2},
  // TODO: {0x807DADC0 + 2, 2},

  // TODO UNDEF_807db740

  // UNDEF_807db950
  {0x807DB9A0 + 2, 2},

  // 0x807DBB20: daCastleKokoopaDemo1st_c::executeState_BattleStDemo
  {0x807DBBF8 + 2, 2},
  {0x807DBCBC + 2, 2},
  // 0x807DBF70: daCastleKokoopaDemo1st_c::executeState_BattleEdDemo
  {0x807DC1F0 + 2, 2},
  {0x807DC3D8 + 2, 2},
  {0x807DC4B8 + 2, 2},
  {0x807DC510 + 2, 2},
  {0x807DC560 + 2, 2},

  // TODO:
  // - 0x807dd090, daCastleKokoopaDemo2nd_c::UNDEF_807dd090
  // - 0x807dd430, daCastleKokoopaDemo2nd_c::UNDEF_807dd430
  // - 0x807dd6b0, daCastleKokoopaDemo2nd_c::UNDEF_807dd6b0

  // daChukanPoint_c::FUN_807e2710
  {0x807E27AC + 2, 2},
  {0x807E27C4 + 2, 2, -1},

  // UNDEF_807e2a30
  {0x807E2BC8 + 2, 2},
  {0x807E2BE0 + 2, 2, -1},

  // TODO UNDEF_807e9e40

  // daFlagObj_c::UNDEF_807eb2d0
  {0x807EB33C + 2, 2},
  // daFlagObj_c::executeState_IfSwichMove
  {0x807EBD9C + 2, 2},
  {0x807EBF54 + 2, 2},
  {0x807EBE70 + 2, 2},
  {0x807EC01C + 2, 2},
  // daFlagObj_c::UNDEF_807ec340
  {0x807EC3C0 + 2, 2},

  // TODO daFloorDokanEight_c

  // UNDEF_807f92c0
  {0x807F938C + 2, 2},
  // UNDEF_807f93f0
  {0x807F9508 + 2, 2},

  // UNDEF_80807d60
  {0x80807E10 + 2, 2},

  // daKameckForAirshipDemo_c::executeState_Demo1Begin
  {0x80817D88 + 2, 2},

  // UNDEF_8081dc20
  {0x8081DD0C + 2, 2},

  // UNDEF_80821030
  {0x80821088 + 2, 2},
  {0x808210C0 + 2, 2},
  {0x808210F8 + 2, 2},

  // UNDEF_80826dc0
  {0x80826E40 + 2, 2},

  // UNDEF_8082e970
  {0x8082E9B0 + 2, 2},

  // UNDEF_8082f530
  {0x8082F5CC + 2, 2},

  // UNDEF_808350f0
  {0x8083517C + 2, 2},

  // UNDEF_80836e50
  {0x80836F20 + 2, 2},

  // UNDEF_80838970
  {0x808389C8 + 2, 2},
  {0x80838A00 + 2, 2},
  {0x80838A38 + 2, 2},

  // daRemoconBalance_c::UNDEF_8083d7b0
  {0x8083D870 + 2, 2},

  // UNDEF_80843940
  {0x808439EC + 2, 2},
  {0x80843AB4 + 2, 2},

  // UNDEF_80843fd0
  {0x80844124 + 2, 2},

  // TODO daLiftSpinRotation_c::UNDEF_8084cdf0

  // daLineKinokoBlock_c::UNDEF_808575c0
  {0x80857614 + 2, 2},
  {0x80857664 + 2, 2},

  // daLineTrain_c::checkAllPlayerRide
  {0x8085A838 + 2, 2},
  {0x8085A8A4 + 2, 2},

  // daLineTrain_c::execute
  {0x8085B224 + 2, 2},

  // TODO 0x80868F00, 0x80868F90, 0x80869110 (daMiniGameWireMesh_c::executeState_PlayMove)
  // something related to the powerup house minigame
  // TODO 0x8086AB90, 0x8086AEA0 cursor color or something

  // daMiniGameWireMeshMgrObj_c::executeState_Play
  {0x8086B7AC + 2, 2},
  // daMiniGameWireMeshMgrObj_c::UNDEF_8086b7f0
  {0x8086B850 + 2, 2},
  // daMiniGameWireMeshMgrObj_c::getAvailablePlayerNo
  {0x8086B960 + 2, 2},
  // daMiniGameWireMeshMgrObj_c::UNDEF_8086b990
  {0x8086BA40 + 2, 2},
  // daMiniGameWireMeshMgrObj_c::executeState_AllTurnUp
  {0x8086BC58 + 2, 2},
  // daMiniGameWireMeshMgrObj_c::executeState_ShowResult
  {0x8086BF5C + 2, 2},

  // TODO 0x8086EA10 daNextGotoBlock_c::executeState_Move

  // daNiceBoat_c::FUN_8086F390
  {0x8086F398 + 2, 2},
  {0x8086F3C8 + 2, 2},
  {0x8086F3F8 + 2, 2},

  // daNiceBoat_c::setPlayerEmblem?
  {0x80870990 + 2, 2},
  {0x808709AC + 2, 2},

  // daNiceBoat_c::FUN_80870EC0
  {0x80870F2C + 2, 2},
  {0x80870F84 + 2, 2},

  // daNiceBoat_c::FUN_80870FC0
  {0x80870FD4 + 2, 2},

  // daNiceBoat_c::FUN_80871320
  {0x808713C4 + 2, 2},

  // daObjKameck_c::execute
  {0x8087D2C0 + 2, 2},

  // daObjKinoko_c
  {0x8087F808 + 2, 2},
  {0x8087F850 + 2, 2},

  // UNDEF_8088606c
  {0x8088606C + 2, 2},

  // daPowBlock_c::doDelete
  {0x80891674 + 2, 2},

  // daPowBlock_c::UNDEF_80891a70
  {0x80891A9C + 2, 2},

  // TODO daShipGear_c::UNDEF_808a2180

  // UNDEF_808a5780
  {0x808A57EC + 2, 2},

  // TODO 0x808AF330 daTarzanIvy_c::create

  // UNDEF_808b3a80
  {0x808B3B6C + 2, 2},

  // daWakiFire_c::UNDEF_808b5060
  {0x808B50D4 + 2, 2},

  // daWakiKeronpa_c::UNDEF_808b5d60
  {0x808B5DA4 + 2, 2},

  // daWakiKeronpa_c::UNDEF_808b6040
  {0x808B6090 + 2, 2},

  // daWakiKiller_c::executeState_Move
  {0x808B6424 + 2, 2},

  // daWakiKokoopaFire_c::isAnyPlayerInLocation
  {0x808B6CA4 + 2, 2},

  // TODO 0x808B6DD0 daWakiKokoopaFire_c::calcVulnPlayers

  // daWakiParabom_c::isPlayerInRect
  {0x808B8EDC + 2, 2},

  // UNDEF_808b9870
  {0x808B98C0 + 2, 2},

  // daWakiPukuPuku_c::executeState_NormalWaki
  {0x808BA158 + 2, 2},
  {0x808BA168 + 2, 2},

  // TODO 0x808BA220 daWakiPukuPuku_c::executeState_SearchWaki

  // UNDEF_808bafc0
  {0x808BB010 + 2, 2},

  // daWakiTobiPuku_c::executeState_NormalWaki
  {0x808BB420 + 2, 2},

  // daWarpCannon_c::CanPlrEnter
  {0x808BCB2C + 2, 2},

  // daWarpCannon_c::SetPlrEntered
  {0x808BCBD0 + 2, 2},

  // daWarpCannon_c::UNDEF_808bcc00 - checks number of players in warp cannon
  {0x808BCC54 + 2, 2},

  // daWarpCannon_c::UNDEF_808bcc80
  {0x808BCDE8 + 2, 2},

  // daEnBirikyu_c::initializeState_DieFall
  {0x809BD1CC + 2, 2, -1},

  // daEnFireSnake_c::initializeState_DieFall
  {0x809FB744 + 2, 2, -1},

  // daEnGakeNoko_c::initializeState_DieFumi
  {0x80A035A8 + 2, 2, -1},

  // daEnGlpole_c::checkPlayerCollision
  {0x80A0B298 + 2, 2},
  {0x80A0B3EC + 2, 2},
  {0x80A0AFE4 + 2, 2},
  {0x80A0B0D0 + 2, 2},

  // daEnHanachan_c::initializeState_DieFall
  {0x80A15204 + 2, 2, -1},

  // TODO 80a16d40 daEnHimanBros_c::UNDEF_80a16d40
  // TODO 80a16de0 daEnHimanBros_c::UNDEF_80a16de0

  // TODO 80a1a4c0 daEnHnswich_c::UNDEF_80a1a4c0

  // daEnIcicle_c::UNDEF_80a212e0
  {0x80A21380 + 2, 2},

  // daEnItem_c::UNDEF_80a28770
  {0x80A28814 + 2, 2},

  // daEnJellyFish_c::UNDEF_80a30810
  {0x80A3096C + 2, 2},

  // daEnJugemBody_c::UNDEF_80a36da0
  {0x80A36E28 + 2, 2, -1},

  // UNDEF_80a39660
  {0x80A39728 + 2, 2, -1},
  // UNDEF_80a399b0
  {0x80A39A30 + 2, 2},

  // daEnKeronpa_c::initializeState_DieFall
  {0x80A4792C + 2, 2, -1},

  // daEnKiller::UNDEF_80a4a9d0
  {0x80A4AA60 + 2, 2, -1},

  // daEnLiftRemoconTrampoline_c::execute
  {0x80A5CB84 + 2, 2},
  // daEnLiftRemoconTrampoline_c::UNDEF_80a5cc80
  {0x80A5CCD8 + 2, 2},

  // daEnManholeChoropu_c::UNDEF_80a60c20
  {0x80A60D1C + 2, 2},

  // daEnMechaKoopa_c::doDelete
  {0x80A64F14 + 2, 2},
  // daEnMechaKoopa_c::hitCallback_Ice
  {0x80A65958 + 2, 2},
  {0x80A659D8 + 2, 2},
  // daEnMechaKoopa_c::finalizeState_Carry
  {0x80A65FD8 + 2, 2},

  // daEnMistMan_c::initializeState_Vanish
  {0x80A6CAE4 + 2, 2, -1},
  // daEnMistMan_c::initializeState_IceBreak
  {0x80A6CDA8 + 2, 2, -1},

  // daEnOnewayGate_c::UNDEF_80a7c550
  {0x80A7C728 + 2, 2},

  // daEnPata_c::hitCallback_Ice
  {0x80A84D48 + 2, 2},

  // daEnPolter_c::UNDEF_80a86b70
  {0x80A86CF4 + 2, 2},
  // daEnPolter_c::UNDEF_80a86d20
  {0x80A86E24 + 2, 2},

  // daEnPuku_c::UNDEF_80a89840
  {0x80A898D8 + 2, 2, -1},

  // daEnSanbo_c::initializeState_CriticalDie
  {0x80A9ECBC + 2, 2, -1},

  // TODO: daEnRailPolyChild_c::UNDEF_80a8ee60

  // daEnRemoconCannon_c::UNDEF_80a95990
  // {0x80A95BD8 + 2, 2},

  // daEnRemoconCannon_c::UNDEF_80a95c00
  {0x80A95C6C + 2, 2},

  // daEnRemoconCannon_c::UNDEF_80a95c90
  {0x80A95CD8 + 2, 2},

  // daEnRemoconCannon_c::UNDEF_80a95d00
  {0x80A95D40 + 2, 2},
  // TODO: 80a96c10 daEnRemoconCannon_c::initializeState_Fire

  // TODO: daEnReverse_c::UNDEF_80a97dc0

  // daEnSanboEl_c::initializeState_FreezeFall
  {0x80AA0EE8 + 2, 2, -1},

  // UNDEF_80aa2e70
  {0x80AA2EB8 + 2, 2},
  // UNDEF_80aa33d0
  {0x80AA3404 + 2, 2, -1},

  // daEnStarCoin_c::isCoinCollected
  {0x80AAA050 + 2, 2},
  {0x80AAA054 + 2, 2, FourPatch::NEGATIVE},

  // daEnStarCoin_c::collectedAllCoins
  {0x80AAA1DC + 2, 2},
  {0x80AAA1EC + 2, 2},
  {0x80AAA1FC + 2, 2},

  // daEnStarCoin_c::collectedAllCoinsInSave
  {0x80AAA2AC + 2, 2},

  // daEnTeresa_c::UNDEF_80ab0020
  {0x80AB0118 + 2, 2},

  // daEnTeresa_c::UNDEF_80ab026c
  {0x80AB026C + 2, 2},
  {0x80AB0334 + 2, 2},

  // daEnTogeMet_c::initializeState_DieFall
  {0x80AB4F1C + 2, 2, -1},

  // daEnWakiJugem_c::UNDEF_80abca40
  {0x80ABCA8C + 2, 2},

  // daEnWakiJugem_c::executeState_WakiMove
  {0x80ABCCA4 + 2, 2},

  // daEnWalkPakkun_c::initializeState_DieFall
  {0x80ABE818 + 2, 2, -1},

  // daEnWaterPakkun_c::initializeState_DieFall
  {0x80AC6C4C + 2, 2, -1},

  // daEnWhiteBlock_c::UNDEF_80ac8ac0
  {0x80AC8B2C + 2, 2},

  // TODO: 80ac8d70 daEnWhiteBlock_c::UNDEF_80ac8d70
  // TODO: 80ac8f20 daEnWhiteBlock_c::UNDEF_80ac8f20
  // TODO: 80ac9080 daEnWhiteBlock_c::UNDEF_80ac9080
  // TODO: 80ac9160 daEnWhiteBlock_c::UNDEF_80ac9160

  // TODO: 80acae60 daEnWrturn_c::UNDEF_80acae60
  // TODO: 80acafb0 daEnWrturn_c::UNDEF_80acafb0
  // TODO: 80acb120 daEnWrturn_c::executeState_Move

  // daEnZoom_c::execute - Some 2-5 special zoom thing
  {0x80ACD0F4 + 2, 2},

  // daEnBossKameck_c::executeState_Vanish
  {0x80B3AA8C + 2, 2},

  // daEnBossKoopa_c::UNDEF_80b3f290
  {0x80B3F2CC + 2, 2, -1},
  // daEnBossKoopa_c::UNDEF_80b3f5c0
  {0x80B3F894 + 2, 2},
  // daEnBossKoopa_c::searchNearestPlayer
  {0x80B405A4 + 2, 2},
  // daEnBossKoopa_c::UNDEF_80b405f0
  {0x80B40680 + 2, 2},

  // daEnBossKoopaDemoKameck_c::initializeState_Magic
  {0x80B47668 + 2, 2},
  {0x80B476E8 + 2, 2},
  // daEnBossKoopaDemoKameck_c::executeState_Magic
  {0x80B477F4 + 2, 2},
  {0x80B479A4 + 2, 2},
  {0x80B47D20 + 2, 2},

  // daEnBossKoopaDemoPeach_c::initializeState_Call
  {0x80B49490 + 2, 2},
  {0x80B494D0 + 2, 2},
  // daEnBossKoopaDemoPeach_c::executeState_Thank
  {0x80B49E88 + 2, 2},
  // TODO: 80b49fd4
  {0x80B4A1EC + 2, 2},

  // UNDEF_80b50580
  {0x80B50664 + 2, 2},

  // daPyDemoMng_c::setEnemyStageClearDemo
  {0x8005d71c + 2, 2},

  // Morton stunning players?
  // TODO: 0x80B60180
  // TODO: 0x80B60220

  // Roy stunning players?
  // TODO: 0x80B63C60
  // TODO: 0x80B63D10
};

void Four::Apply()
{
    auto codeRegion = dSys_c::m_codeRegion;

    for (const FourPatch& patch : FOUR_PATCH_LIST) {
        u32 address = (&patch.addressP1)[static_cast<u32>(codeRegion)];
        if (address == 0) {
            OS_REPORT("WARNING: Skipping Four patch at P1 0x%08X\n", patch.addressP1);
            continue;
        }

        u8 size = patch.size;
        s8 offset = patch.offset;
        if (patch.offset <= FourPatch::NEGATIVE) {
            offset = patch.offset - FourPatch::NEGATIVE;
        }

        ASSERT(size <= 4);
        s32 oldValue = 4 + offset;
        s32 newValue = PLAYER_COUNT + offset;

        if (patch.offset <= FourPatch::NEGATIVE) {
            oldValue = -oldValue;
            newValue = -newValue;
        }

        if (std::memcmp(
              reinterpret_cast<void*>(address), reinterpret_cast<u8*>(&oldValue) + (4 - size), size
            ) != 0) {
            u32 realOldValue = 0;
            std::memcpy(
              reinterpret_cast<u8*>(&realOldValue) + (4 - size), reinterpret_cast<void*>(address),
              size
            );
            OS_REPORT(
              "WARNING: Four patch at 0x%08X inconsistent with original value, expected %u, found "
              "%u.\n",
              address, oldValue, realOldValue
            );
        }
        std::memcpy(
          reinterpret_cast<void*>(address), reinterpret_cast<u8*>(&newValue) + (4 - size), size
        );
    }
}
