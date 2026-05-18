#pragma once

#include "d_system/d_mj2d_game.h"
#include "d_system/d_scene.h"

class dSelectCursor_c;

class dScWMap_c : public dScene_c {
    SIZE_ASSERT(0xEC);

public:
    // Static Methods
    // ^^^^^^

    /* 0x801027A0 */
    static void setNextWorldScene(u8 world, u8 node, u8 = 0);

    /* 0x80102B50 */
    static u32 CreateBootParam();

    /* 0x80102B70 @unofficial */
    static u32 AssembleBootParam(WORLD_e, u32, int);

    /* 0x80102B90 */
    static void initLoadGame();

    /* 0x800105B0, 0x808DEB70 */
    static WORLD_e getWorldNo() { return m_WorldNo; }

public:
    // Static Methods
    // ++++++

    static void returnToWorldScene();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80926E10 */
    bool createLayoutPhase();

    /* 0x809271C0 */
    bool createActorsPhase();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x74, 0x7C);

    /* 0x7C */ dSelectCursor_c* mpSelectCursor;

    FILL(0x80, 0xEC);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A52D */ static WORLD_e m_WorldNo;
    /* 0x8042A52E */ static u8      m_SceneNo;
    /* 0x80429355 */ static WORLD_e m_PrevWorldNo;
    /* 0x80429356 */ static u8      m_PrevSceneNo;

    /* 0x8042A538 */ static bool    m_GameOver;
};
