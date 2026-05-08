#pragma once

#include "d_system/d_enemy.h"
#include "state/s_State.h"

class daEnBomhei_c : public dEn_c {
public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0xEC 0x809CA8D0 */
    virtual bool hitCallback_HipAttk(dCc_c* main, dCc_c* other) override;

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80B12B08, daEnBomhei_c, Slide);
};
