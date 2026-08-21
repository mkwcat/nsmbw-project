// d_player_model_manager.cpp
// NSMBW .text: 0x800D6DB0 - 0x800D7190

#include "d_player_model_manager.h"

#include "d_static/d_player_model/d_kinopico_model.h"
#include "d_static/d_player_model/d_kinopio_model.h"
#include "d_static/d_player_model/d_mario_model.h"
#include "d_static/d_player_model/d_yoshi_model.h"
#include "machine/m_heap.h"
#include <mkwcat/NoInitialize.hpp>

[[nsmbw_data(0x803710A0)]]
dPyMdlBase_HIO_c dPyMdlMng_c::m_hio = mkwcat::NoInitialize<dPyMdlBase_HIO_c>();

[[nsmbw(0x800D6DB0)]]
dPyMdlMng_c::dPyMdlMng_c(dPyMdlMng_c::ModelType_e modelType);

[[nsmbw(0x800D6E00)]]
void dPyMdlMng_c::construct(
    u8 index
) {
    switch (static_cast<ModelType_e>(index)) {
    case ModelType_e::MODEL_MARIO:
    case ModelType_e::MODEL_LUIGI:
        mModel = new (mHeap::g_gameHeaps[0], 4) dMarioMdl_c(index);
        break;

    case ModelType_e::MODEL_TOAD_BLUE:
    case ModelType_e::MODEL_TOAD_YELLOW:
    case ModelType_e::MODEL_TOAD_RED:
    case ModelType_e::MODEL_TOAD_BLACK:
    case ModelType_e::MODEL_TOAD_ORANGE:
        mModel = new (mHeap::g_gameHeaps[0], 4) dKinopioMdl_c(index);
        break;

    case ModelType_e::MODEL_YOSHI:
        mModel = new (mHeap::g_gameHeaps[0], 4) dYoshiMdl_c(index);
        break;

    case ModelType_e::MODEL_TOADETTE:
    case ModelType_e::MODEL_TOADETTE_PURPLE:
        mModel = new (mHeap::g_gameHeaps[0], 4) dKinopicoMdl_c(index);
        break;

    default:
        mModel = nullptr;
        break;
    }
}

[[nsmbw(0x800D6EE0)]]
void dPyMdlMng_c::create(u8 param1, u8 param2, SceneType_c sceneType);

[[nsmbw(0x800D6EF0)]]
dPyMdlMng_c::~dPyMdlMng_c();

[[nsmbw(0x800D6F80)]]
void dPyMdlMng_c::play();

[[nsmbw(0x800D6FA0)]]
void dPyMdlMng_c::calc(mMtx_c& mtx);

[[nsmbw(0x800D7030)]]
void dPyMdlMng_c::calc(mVec3_c vec, mAng3_c angle, mVec3_c vec2);

[[nsmbw(0x800D70F0)]]
void dPyMdlMng_c::calc2();

[[nsmbw(0x800D7110)]]
void dPyMdlMng_c::draw();

// 0x800D7140: __sinit_\d_player_model_manager_cpp
