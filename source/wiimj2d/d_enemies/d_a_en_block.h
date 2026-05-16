#pragma once

#include "d_system/d_a_en_blockmain.h"

class daEnBlock_c : public daEnBlockMain_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x809BF590 */ bool create_items(int param);
    /* 0x809BFB40 */ void create_sub_item();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x800);

    /* 0x800 */ int m_set_item;
    /* 0x804 */ int m_block_type;

    FILL(0x808, 0x81C);

    /* 0x81C */ bool m0x81C;

    FILL(0x81D, 0x823);

    /* 0x823 */ s8 m_player_number;
    /* 0x824 */ s8 m0x824;
};
