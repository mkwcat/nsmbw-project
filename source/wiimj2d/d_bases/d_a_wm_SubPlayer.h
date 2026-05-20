#pragma once

#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_manager.h"
#include "d_system/d_wm_lib.h"
#include "d_system/d_wm_player_base.h"

class daWmSubPlayer_c : public dWmPlayerBase_c {
public:
    // Constants and Types
    // ^^^^^^

    /* @unofficial */
    class NodeTrailBase_c {
        SIZE_ASSERT(0xC);

        /* 0x0 VTABLE 0x80985C3C */

    public:
        NodeTrailBase_c()
            : mAllocCount(0)
            , mpNodes(nullptr) {}

        /* VT+0x08 0x808EB060 */
        virtual ~NodeTrailBase_c();

        struct Node_s {
            SIZE_ASSERT(0x8);
            /* 0x0 */ int m0x0;
            /* 0x4 */ int m0x4;
        };

        /* VT+0x0C 0x808EF730 */
        virtual void alloc(int count);

        /* VT+0x10 0x808EF780 */
        virtual void alloc(int count, EGG::Heap* heap);

        /**
         * VT+0x14 0x808EF800
         * Empty.
         */
        virtual void setHeap(EGG::Heap* heap);

        /**
         * VT+0x18 0x808EF810
         * Empty.
         */
        virtual void VT_0x18();

        /* 0x4 */ u32     mAllocCount;
        /* 0x8 */ Node_s* mpNodes;
    };

    /* @unofficial */
    class NodeTrail_c : public NodeTrailBase_c {
        SIZE_ASSERT(0x14);

        /* 0x00 VTABLE 0x80985C20 */

    public:
        NodeTrail_c()
            : NodeTrailBase_c()
            , mUsedCount(0)
            , mFirstNode(0) {}

        /* VT+0x8 0x808EB060 */
        virtual ~NodeTrail_c();

        /* 0x808EF680 */
        Node_s* pushNext();

        /* 0x808EF6D0 */
        Node_s* popFirst();

        Node_s* peekFirst() const {
            if (mUsedCount < 1) {
                return nullptr;
            }

            return &mpNodes[mFirstNode];
        }

        /* 0x0C */ u32 mUsedCount;
        /* 0x10 */ u32 mFirstNode;
    };

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x808EB220
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /**
     * 0x808EB220
     * Copy of create.
     */
    PACK_RESULT_e createSubPlayer();

    /* 0x808EB7D0 */
    void loadModel();

    /* 0x808EDC40 */
    void setWalkSpeed(f32 multiplier);

    /* 0x808EE0C0 */
    s32 getPlayerOrder();

    /* 0x808EE110 */
    f32 getDistanceToAheadPlayer();

    bool isPastAheadPlayer(float& distToNextNode);

    /* 0x808EE200 */
    dWmPlayerBase_c* getAheadPlayer();

    /* 0x808EE620 */
    void calcWalkSpeed();

    /* 0x808EE960 */
    f32 getPlayerOrderDistance();

    /* 0x808EE9B0 */
    s16 getPlayerOrderAngle();

    /* 0x808EEA00 */
    s32 getPlayerOrderTableIndex(int playerOrder);

    /* 0x808EEF00 */
    bool isWrongDirection(dWmLib::Dir_e dir1, dWmLib::Dir_e dir2);

    /* 0x808EEF70 */
    bool isSubPlayerStopPoint();

    /* 0x808EF2B0 */
    bool isPlayerType(PLAYER_TYPE_e playerType);

    /* 0x808EF2D0 */
    bool isPlayerStar();

public:
    // Static Methods
    // ^^^^^^

    /* 0x808EE950 */
    static int getSubPlayerNum();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x1CC */ dPyMdlMng_c* mModelManager;

    FILL(0x1D0, 0x1F4);

    /* 0x1F4 */ int mFromNode;
    /* 0x1F8 */ int mToNode;
    FILL(0x1FC, 0x200);
    /* 0x200 */ dWmLib::Dir_e mMoveDir;
    FILL(0x204, 0x208);
    /* 0x208 */ int mSubPlayerNo;

    FILL(0x20C, 0x214);

    /* 0x214 */ NodeTrail_c             mNodeTrail;
    /* 0x228 */ NodeTrailBase_c::Node_s maNodes[8];

    FILL(0x268, 0x294);

    /* 0x294 */ float* mp0x294;

    FILL(0x298, 0x2A8);

    /* 0x2A8 */ s32 mPrevSpeedMultiply;

    OFFSET_ASSERT(0x2AC);
};
