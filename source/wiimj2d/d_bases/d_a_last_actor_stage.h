#pragma once

#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_base.h"

class daLastActorStage_c : public dBase_c
{
public:
    // Structors
    // ^^^^^^

    daLastActorStage_c() = default;

    virtual ~daLastActorStage_c() override = default;

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x808306E0
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x80830710
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x80830720
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

    /**
     * VT+0x2C 0x80830BB0
     * do method for the draw operation.
     */
    PACK_RESULT_e draw() override;

public:
    // Instance Variables
    // ^^^^^^

    // Original class
    // /* 0x70 */ u32 mBtnPressed[4];
    // /* 0x80 */ bool mIsShaking[4];
    // OFFSET_ASSERT(0x84);

    u32 mBtnPressed[PLAYER_COUNT];
    bool mIsShaking[PLAYER_COUNT];
};
