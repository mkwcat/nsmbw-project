#pragma once

#include "d_static/d_a_player/d_a_player_hio_ADJ.h"
#include "d_static/d_player_model/d_player_model_base.h"
#include "machine/m_angle.h"
#include "machine/m_mtx.h"
#include "machine/m_vec.h"

class dPyMdlMng_c {
    SIZE_ASSERT(0xC);

    /* 0x0 VTABLE 0x80318D98 */

public:
    // Constants and Types
    // ^^^^^^

    enum class ModelType_e {
        MODEL_NONE            = -1,
        MODEL_MARIO           = 0,
        MODEL_LUIGI           = 1,
        MODEL_TOAD_BLUE       = 2,
        MODEL_TOAD_YELLOW     = 3,
        MODEL_TOAD_RED        = 4,
        MODEL_YOSHI           = 5,

        // Added
        MODEL_TOADETTE        = 6,
        MODEL_TOADETTE_PURPLE = 7,
        MODEL_TOAD_BLACK      = 8,
        MODEL_TOAD_ORANGE     = 9,

        COUNT,
    };

    enum class SceneType_c {
        SCENE_TYPE_2 = 2,
    };

public:
    // Structors
    // ^^^^^^

    /* 0x800D6DB0 */
    dPyMdlMng_c(ModelType_e modelType);

    /**
     * VT+0x08 0x800D6EF0
     * Destroys the player model manager.
     */
    virtual ~dPyMdlMng_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D6E00 */
    void construct(u8 index);

    /* 0x800D6EE0 */
    void create(u8 index, u8 playerMode, SceneType_c sceneType);

    /* 0x800D6F80 */
    void play();

    /* 0x800D6FA0 */
    void calc(mMtx_c& mtx);

    /* 0x800D7030 */
    void calc(mVec3_c vec, mAng3_c angle, mVec3_c vec2);

    /* 0x800D70F0 */
    void calc2();

    /* 0x800D7110 */
    void draw();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x4 */ dPyMdlBase_c* mModel;
    /* 0x8 */ u32           mDrawReady;

public:
    // Static Variables
    // ^^^^^^

    /* 0x803710A0 */ static dPyMdlBase_HIO_c m_hio;
};
