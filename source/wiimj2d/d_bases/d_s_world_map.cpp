// d_s_world_map.cpp
// NSMBW d_bases.text: 0x80926740 - 0x80928840

#include "d_s_world_map.h"

#include "d_bases/d_CharacterChangeIndicator.h"
#include "d_bases/d_CharacterChangeSelectArrow.h"
#include "d_bases/d_CharacterChangeSelectBase.h"
#include "d_bases/d_CharacterChangeSelectContents.h"
#include "d_bases/d_CollectionCoin.h"
#include "d_bases/d_CollectionCoinBase.h"
#include "d_bases/d_CollectionCoinDate.h"
#include "d_bases/d_Continue.h"
#include "d_bases/d_CourseSelectMenu.h"
#include "d_bases/d_EasyPairing.h"
#include "d_bases/d_InfoWindow.h"
#include "d_bases/d_LetterWindow.h"
#include "d_bases/d_MessageWindow.h"
#include "d_bases/d_ModelPlayArrow.h"
#include "d_bases/d_NumberOfPeopleChange.h"
#include "d_bases/d_StockItem.h"
#include "d_bases/d_StockItemShadow.h"
#include "d_bases/d_YesNoWindow.h"
#include "d_bases/d_a_wm_KoopaShip.h"
#include "d_bases/d_a_wm_Map.h"
#include "d_bases/d_wm_WorldSelect.h"
#include "d_bases/d_wm_WorldSelectGuide.h"
#include "d_player/d_SelectCursor.h"
#include "d_profile/d_profile.h"
#include "d_system/d_CourseSelectManager.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_wm_actor.h"
#include <iterator>

[[nsmbw(0x80926E10)]]
bool dScWMap_c::createLayoutPhase() {
#define NEW(_TYPE, _PROFILE, _PARAM)                                                               \
    static_cast<_TYPE>(fBase_c::createChild(dProf::_PROFILE, this, _PARAM, 0))

    mpSelectCursor                       = NEW(dSelectCursor_c*, SELECT_CURSOR, 0);

    dCourseSelectManager_c* crsSelMng    = NEW(dCourseSelectManager_c*, COURSE_SELECT_MANAGER, 0);

    crsSelMng->mpWSelect                 = NEW(dWorldSelect_c*, WORLD_SELECT, 0);
    crsSelMng->mpWSelect->mpWSelectGuide = crsSelMng->mpWSelectGuide =
        NEW(dWorldSelectGuide_c*, WORLD_SELECT_GUIDE, 0);

    dCollectionCoin_c* colCoin = crsSelMng->mpCollectionCoin =
        NEW(dCollectionCoin_c*, COLLECTION_COIN, 0);
    for (std::size_t i = 0; i < std::size(colCoin->mpColCoinBase); i++) {
        colCoin->mpColCoinBase[i] = NEW(dCollectionCoinBase_c*, COLLECTION_COIN_BASE, 0);
    }
    for (std::size_t i = 0; i < std::size(colCoin->mpColCoinDate); i++) {
        colCoin->mpColCoinDate[i] = NEW(dCollectionCoinDate_c*, COLLECTION_COIN_DATE, 0);
    }
    colCoin->mpMdlPlyArrow     = NEW(dModelPlayArrow_c*, MODEL_PLAY_ARROW, 0);

    crsSelMng->mpCrsSelectMenu = NEW(dCourseSelectMenu_c*, COURSE_SELECT_MENU, 0);

    crsSelMng->mpNumPyChg      = NEW(dNumberOfPeopleChange_c*, NUMBER_OF_PEOPLE_CHANGE, 0);
    for (std::size_t cc = 0; cc < crsSelMng->mpNumPyChg->mCcCount; cc++) {
        crsSelMng->mpNumPyChg->mpCcSelBase[cc] =
            NEW(dCharacterChangeSelectBase_c*, CHARACTER_CHANGE_SELECT_BASE, cc);
        crsSelMng->mpNumPyChg->mpCcSelContents[cc] =
            NEW(dCharacterChangeSelectContents_c*, CHARACTER_CHANGE_SELECT_CONTENTS, cc);
        crsSelMng->mpNumPyChg->mpCcSelArrow[cc] =
            NEW(dCharacterChangeSelectArrow_c*, CHARACTER_CHANGE_SELECT_ARROW, cc);
        crsSelMng->mpNumPyChg->mpCcIndicator[cc] =
            NEW(dCharacterChangeIndicator_c*, CHARACTER_CHANGE_INDICATOR, cc);
    }

    crsSelMng->mpStockItem           = NEW(dStockItem_c*, STOCK_ITEM, 0);
    crsSelMng->mpStockItem->mpShadow = crsSelMng->mpStockItemSha =
        NEW(dStockItemShadow_c*, STOCK_ITEM_SHADOW, 0);

    crsSelMng->mpEasyPairing   = NEW(dEasyPairing_c*, EASY_PAIRING, 0);
    crsSelMng->mpContinue      = NEW(dContinue_c*, CONTINUE, 0);
    crsSelMng->mpYesNoWindow   = NEW(dYesNoWindow_c*, YES_NO_WINDOW, 0);
    crsSelMng->mpMessageWindow = NEW(dMessageWindow_c*, MESSAGE_WINDOW, 0);
    crsSelMng->mpLetterWindow  = NEW(dLetterWindow_c*, LETTER_WINDOW, 0);

    return true;
#undef NEW
}

[[nsmbw(0x809271C0)]]
bool dScWMap_c::createActorsPhase() {
    dWmActor_c::construct(dProf::WM_MAP, this, 0, nullptr, nullptr);

    daWmMap_c* wmMap = daWmMap_c::m_instance;
    wmMap->setNodeRndizer();

    dWmActor_c::construct(dProf::WM_CS_SEQ_MNG, this, 0, nullptr, nullptr);
    dWmActor_c::construct(dProf::WM_PLAYER, this, 0, nullptr, nullptr);
    dWmActor_c::construct(dProf::WORLD_CAMERA, this, 0, nullptr, nullptr);

    wmMap->createMapActors();
    wmMap->createEnemyActors();

    daWmKoopaShip_c::setup();

    dCourseSelectManager_c*  crsSelMng = dCourseSelectManager_c::m_instance;
    dNumberOfPeopleChange_c* numPyChg  = crsSelMng->mpNumPyChg;
    dStockItem_c*            stockItem = crsSelMng->mpStockItem;

    for (int type = 0; type < CHARACTER_COUNT; type++) {
        crsSelMng->mpa2DPlayer[type] = reinterpret_cast<da2DPlayer_c*>(
            dBaseActor_c::construct(dProf::WM_2D_PLAYER, this, type, nullptr, nullptr)
        );

        if (numPyChg != nullptr) {
            numPyChg->setPlayer(static_cast<PLAYER_TYPE_e>(type), crsSelMng->mpa2DPlayer[type]);
        }
        if (stockItem != nullptr) {
            stockItem->mpa2DPlayer[type] = crsSelMng->mpa2DPlayer[type];
            if (type < 4) {
                stockItem->REMOVED(mpa2DPlayer)[type] = crsSelMng->mpa2DPlayer[type];
            }
        }
    }

    if (stockItem != nullptr) {
        for (int i = 0; i < std::size(stockItem->mpaItem); i++) {
            stockItem->mpaItem[i] = reinterpret_cast<daWmItem_c*>(
                dBaseActor_c::construct(dProf::WM_ITEM, this, i, nullptr, nullptr)
            );
        }
    }

    dWorldSelect_c* wSelect = crsSelMng->mpWSelect;
    if (wSelect != nullptr) {
        for (int i = 0; i < std::size(wSelect->mpaIsland); i++) {
            wSelect->mpaIsland[i] = reinterpret_cast<daWmIsland_c*>(
                dBaseActor_c::construct(dProf::WM_ISLAND, this, i, nullptr, nullptr)
            );
        }
    }

    return true;
}
