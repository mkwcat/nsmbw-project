#pragma once

#include "d_scene.h"
#include "s_State.h"

class dScGameOver_c : public dScene_c {
    SIZE_ASSERT(0xCC);
    VTABLE(0x60, fBase_c, 0x8098C9B0);
    // 0x8098C990 g_profile_GAMEOVER
    // 0x80921060 dScGameOver_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x809212F0 */
    dScGameOver_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x74, 0xCC);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80921700
     * executeState:    0x80921710
     * finalizeState:   0x80921760
     */
    sState_Extern(0x809A1E28, dScGameOver_c, LoGoStartWait);

    /*
     * initializeState: 0x80921770
     * executeState:    0x80921780
     * finalizeState:   0x809217B0
     */
    sState_Extern(0x809A1E68, dScGameOver_c, DrawDispEndWait);

    /*
     * initializeState: 0x809217C0
     * executeState:    0x809217D0
     * finalizeState:   0x809217E0
     */
    sState_Extern(0x809A1EA8, dScGameOver_c, MultiCourseSelectSceneWait);

    /*
     * initializeState: 0x809217F0
     * executeState:    0x80921800
     * finalizeState:   0x80921830
     */
    sState_Extern(0x809A1EE8, dScGameOver_c, GameOverDispEndWait);

    /*
     * initializeState: 0x80921840
     * executeState:    0x80921860
     * finalizeState:   0x80921890
     */
    sState_Extern(0x809A1F28, dScGameOver_c, ContinueEndWait);

    /*
     * initializeState: 0x809218A0
     * executeState:    0x809218B0
     * finalizeState:   0x809218E0
     */
    sState_Extern(0x809A1F68, dScGameOver_c, SaveEndWait);
};
