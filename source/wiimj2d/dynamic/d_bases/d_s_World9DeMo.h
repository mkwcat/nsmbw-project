#pragma once

#include <dynamic/d_scene.h>

class dScWorld9DeMo_c : public dScene_c
{
public:
    // -----------------
    // Virtual Functions
    // -----------------

    /* 0x8091D350 */
    int create() override;

public:
    // ---------
    // Functions
    // ---------

    /* 0x8091DEC0 */
    void initLight();

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x74, 0xD0);

    /* 0xD0 */ bool mIsWorld9AlreadyOpen;
};