#pragma once

class dBgTexMng_c
{
public:
    // Static Methods
    // ^^^^^^

    /* 0x80083490 */
    static u16 getHitBlockType(u16 tile);

public:
    // Static Variables
    // ^^^^^^

    /* 0x802EFCB8 */
    static u16 l_hit_block_types[664];
};