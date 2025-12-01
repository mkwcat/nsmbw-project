#pragma once

#include "d_system/d_enemy.h"

class daEnBlockMain_c : public dEn_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80021AB0 */
    bool isYossyColor(u16 yoshiColor);

    /* 0x80021B30 */
    s16 yossy_color_search();

    /* 0x80022810 */
    void FUN_80022810();
};