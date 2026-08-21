#pragma once

#include "d_static/d_game_key/d_game_key_core.h"
#include "d_static/d_mj2d/d_mj2d_game.h"
#include "machine/m_pad.h"
#include <egg/core/eggHeap.h>

class dGameKey_c {
    /* 0x00 VTABLE 0x80315900 */

public:
    // Constants and Types
    // ^^^^^^

    static constexpr int CORE_COUNT = PLAYER_COUNT;

public:
    // Structors
    // ^^^^^^

    /* 0x800B5980 */
    dGameKey_c();

    /**
     * Recreate the dGameKey\_c class to support 8 players.
     */
    dGameKey_c(dGameKey_c* old);

    /* VT+0x8 0x800B5A00 */
    virtual ~dGameKey_c();

public:
    // Functions
    // ^^^^^^

    /* 0x800B5AB0 */
    void allclear();

    /* 0x800B5B00 */
    int read();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dGameKeyCore_c* mpCores[CORE_COUNT];

public:
    // Static Methods
    // ^^^^^^

    /* 0x800B5930 */
    static void createInstance(EGG::Heap* heap);

public:
    // Static Inline Methods
    // ^^^^^^

    static inline dGameKeyCore_c* getCurrentCore() {
        return m_instance->mpCores[static_cast<std::size_t>(mPad::g_currentCoreID)];
    }

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A230 */ static dGameKey_c* m_instance;
};
