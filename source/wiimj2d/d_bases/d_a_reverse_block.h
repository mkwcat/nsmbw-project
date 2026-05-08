#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_actor.h"
#include "d_system/d_cc.h"
#include <array>

class dAcPy_c;

class daReverseBlock_c : public dActor_c {
    // Original size: 0x5A8

    /* 0x060 VTABLE 0x809790C4 */

public:
    // Structors
    // ^^^^^^

    daReverseBlock_c() = default;

    /**
     * VT+0x48 0x80898450
     * Destroys the base.
     */
    virtual ~daReverseBlock_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x80897FD0
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x80898230
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x80898190
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80898280 */
    void resetPlayerData();

    /* 0x808983E0 */
    void updatePlayer(dAcPy_c* player, int index);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x394 */ dCc_c mCc0;
    /* 0x438 */ dCc_c mCc1;
    /* 0x4DC */ dCc_c mCc2;

    /* 0x580 */ u32   mDirection;
    OFFSET_ASSERT(0x584);

    /* 0x584 */ std::array<u32, 4 * PLAYER_COUNT> mPlayerData;

    // /* 0x5A4 */ u32 m0x5A4; // Unused
};
