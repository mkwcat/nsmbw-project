// d_a_line_kinoko_block.cpp
// NSMBW d_bases.text: 0x80857490 - 0x808581A0

#include "d_static/d_a_player_manager.h"

[[nsmbw(0x80857770)]]
int daLineKinokoBlock_c_numPlayersInMask(u32 mask)
{
    int count = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mask & (1 << i)) {
            count++;
        }
    }
    return count;
}
