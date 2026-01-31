// d_bg_texture.cpp
// NSMBW .text: 0x80083490 - 0x800872E0

#include "d_bg_texture.h"

[[nsmbw(0x80083490)]]
u16 dBgTexMng_c::getHitBlockType(u16 tile)
{
    // Quick hack to allow dBg_c::BgUnitChange to spawn any tile
    if (tile & 0x8000) {
        return tile & 0x7FFF;
    }

    // Fallback
    return l_hit_block_types[tile];
}

[[nsmbw_data(0x802EFCB8)]]
u16 dBgTexMng_c::l_hit_block_types[664];