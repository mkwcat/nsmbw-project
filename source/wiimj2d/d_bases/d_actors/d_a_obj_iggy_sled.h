#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjIggySled_c : public dEn_c {
    SIZE_ASSERT(0x828);
    VTABLE(0x060, fBase_c, 0x80972890);
    // 0x80972820 g_profile_OBJ_IGGY_SLED
    // 0x80877510 daObjIggySled_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80877540 */
    daObjIggySled_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x828);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80877DC0
     * executeState:    0x80877E40
     * finalizeState:   0x80877E30
     */
    sState_Extern(0x8099D3E8, daObjIggySled_c, Move);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80878130
     * executeState:    VT+0x17C 0x808781B0
     * finalizeState:   VT+0x180 0x808781A0
     */
    sState_ExternVirtual(0x8099D428, daObjIggySled_c, DieFall);
};
