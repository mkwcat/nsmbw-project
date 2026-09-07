#pragma once

#include "d_base.h"

#pragma once

#include "d_base.h"
#include "s_State.h"

class dWarningManager_c : public dBase_c {
    SIZE_ASSERT(0xB94);
    VTABLE(0x060, fBase_c, 0x80322BD0);
    // 0x80429538 g_profile_WARNING_MANAGER
    // 0x8010D270 dWarningManager_c_classInit

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8010E710 */
    void onControllerCut(int player);

public:
    // Static Methods
    // ^^^^^^

    // Normally inline
    [[nsmbw(0x800B3B20)]]
    static bool isWarning();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0xB8D);

    /* 0xB8D */ bool m0xB8D;
    /* 0xB8E */ bool m0xB8E;

    FILL(0xB8F, 0xB94);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A5B8 */ static dWarningManager_c* m_instance;
    /* 0x8042A5C0 */ static s32                m_WarningForbid;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8010DF30
     * executeState:    0x8010DF40
     * finalizeState:   0x8010E0D0
     */
    sState_Extern(0x803751C8, dWarningManager_c, WarningCheck);

    /*
     * initializeState: 0x8010E0E0
     * executeState:    0x8010E0F0
     * finalizeState:   0x8010E190
     */
    sState_Extern(0x80375208, dWarningManager_c, WarningCaution);

    /*
     * initializeState: 0x8010E1A0
     * executeState:    0x8010E1B0
     * finalizeState:   0x8010E220
     */
    sState_Extern(0x80375248, dWarningManager_c, WarningNunchuk);

    /*
     * initializeState: 0x8010E230
     * executeState:    0x8010E240
     * finalizeState:   0x8010E2B0
     */
    sState_Extern(0x80375288, dWarningManager_c, WarningYoKo);

    /*
     * initializeState: 0x8010E2C0
     * executeState:    0x8010E2D0
     * finalizeState:   0x8010E370
     */
    sState_Extern(0x803752C8, dWarningManager_c, WarningExitAnimeEndWait);

    /*
     * initializeState: 0x8010E380
     * executeState:    0x8010E390
     * finalizeState:   0x8010E400
     */
    sState_Extern(0x80375308, dWarningManager_c, WarningBattery);

    /*
     * initializeState: 0x8010E410
     * executeState:    0x8010E420
     * finalizeState:   0x8010E4F0
     */
    sState_Extern(0x80375348, dWarningManager_c, WarningError);

    /*
     * initializeState: 0x8010E500
     * executeState:    0x8010E510
     * finalizeState:   0x8010E590
     */
    sState_Extern(0x80375388, dWarningManager_c, WarningSaveError);
};
