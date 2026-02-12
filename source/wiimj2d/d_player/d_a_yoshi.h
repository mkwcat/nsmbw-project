#pragma once

#include "d_profile/d_profile.h"
#include "d_system/d_a_player_base.h"
#include "d_system/d_player_model_manager.h"

class daYoshi_c : public daPlBase_c, public dProf::Info<daYoshi_c, dProf::YOSHI>
{
public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0DC 0x80150E10 */
    virtual void executeLastAll() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80150420 */
    void setHitTongueReserve();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x14D4 */ dPyMdlMng_c mModelMng;

    FILL(0x14E0, 0x1524);

    /* 0x1524 */ int mEatStage;

    FILL(0x1528, 0x1564);

    /* 0x1564 */ int m_eatCount;

    OFFSET_ASSERT(0x1568);
};
