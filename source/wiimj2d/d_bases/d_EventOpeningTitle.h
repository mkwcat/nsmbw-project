#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"

class dEventOpeningTitle_c : public dBase_c {
public:
    // State ID Methods
    // ^^^^^^

    /* 0x80782340 */
    void executeState_PressButtonExitAnimeEndWait();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c m_layout;
};
