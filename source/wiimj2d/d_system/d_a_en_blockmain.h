#pragma once

#include "d_system/d_enemy.h"
#include <revolution/types.h>

class daEnBlockMain_c : public dEn_c {
    SIZE_ASSERT(0x698);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80021AB0 */
    bool isYossyColor(u16 yoshiColor);

    /* 0x80021B30 */
    s16 yossy_color_search();

    /* 0x80022180 */
    bool player_bigmario_check(s8 player);

    /* 0x800221E0 @unofficial */
    void player_item_set(int item);

    void player_item_set(int item, int* player_item, int count);

    /* 0x80022390 */
    int playernumber_set();

    /* 0x80022490 */
    void item_sound_set(mVec3_c& pos, int item, s8 player, u8, u8);

    /* 0x80022810 */
    void FUN_80022810();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x648);

    /* 0x648 */ BOOL m_item_created;

    FILL(0x64C, 0x650);

    /* 0x64C */ int REMOVED(m_player_item[4]);

    FILL(0x660, 0x698);
};
