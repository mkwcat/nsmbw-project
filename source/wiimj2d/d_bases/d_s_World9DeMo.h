#pragma once

#include "d_static/d_scene.h"

class dScWorld9DeMo_c : public dScene_c
{
public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x8091D350
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

public:
    // Functions
    // ^^^^^^

    /* 0x8091DEC0 */
    void initLight();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x74, 0xD0);

    /* 0xD0 */ bool mIsWorld9AlreadyOpen;
};
