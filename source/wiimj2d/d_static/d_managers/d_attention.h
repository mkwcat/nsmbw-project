#pragma once

#include "f_base_id.h"

class dAttention_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800691B0 */ void update();
    /* 0x80069240 */ void entry(fBaseID_e);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A030 */ static dAttention_c* mspInstance;
};
