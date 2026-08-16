#pragma once

#include "d_system/d_enemy_jr_clown_base.h"

class daJrClownForPlayer_c : public dEnJrClownBase_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80810D80 */
    bool PlayerEnter(dAcPy_c* py);

public:
    // Static Methods
    // ++++++

    static const char* getStepOnEffectName(const dAcPy_c* py);

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x3B4 0x808116B0 */
    void setPlayerEmblem(int playerNo);
};
