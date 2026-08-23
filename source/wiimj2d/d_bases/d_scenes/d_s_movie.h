#pragma once

#include "d_static/d_scene.h"

class dScMovie_c : public dScene_c
{
public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x20 0x80922910
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;
};
