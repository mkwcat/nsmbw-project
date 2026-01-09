#pragma once

#include "machine/m_3d_mdl.h"
#include "machine/m_allocator.h"
#include "machine/m_mtx.h"

namespace nw4r::lyt
{
class ResAnmChr;
}

class dPyMdlBase_c
{
    SIZE_ASSERT(0x20C);

    /* 0x000 VTABLE 0x80318CB8 */

public:
    // Structors
    // ^^^^^^

    /* 0x800D5420 */
    dPyMdlBase_c(u8 index);

    /* VT+0x08 0x800D55D0 */
    virtual ~dPyMdlBase_c();

public:
    // Constants and Types
    // ^^^^^^

    enum class TexAnmType_e {
    };

    /* @unofficial */
    enum class ChrAnmType_e {
        WAIT = 0,
        WALK = 1,
        RUN = 2,
        B_DASH = 3,
        B_DASH2 = 4,
        JUMP = 5,
        JUMP2 = 6,
        JUMPED = 7,
        _2JMP_C_1 = 8,
        _2JMP_C_2 = 9,
        _2JUMPED = 10,
        ROLL_JUMP = 11,
        _2JUMP2 = 12,
        MAME_JUMP2 = 13,
        TURN = 14,
        TURNED = 15,
        HIPSR = 16,
        HIPAT = 17,
        HIPED = 18,
        HIP_TO_STOOP = 19,
        STOOP = 20,
        STOOP_START = 21,
        SLIP = 22,
        MONKEY_START = 0x2F,
        MONKEY_WAIT_R = 0x30,
        MONKEY_WAIT_L = 0x31,
        MONKEY_R_TO_L = 0x32,
        MONKEY_L_TO_R = 0x33,
        GOAL_PUTON_CAP = 0x5A,
        GOAL_PUTON_CAP2 = 0x5C,
        STAR_ROLL = 0x75,
        SJUMPED = 0x78,
        DEMO_TALK = 0xAB,
        BUSY_WAIT = 0xAC,
        ENDING_WAIT = 0xAF,
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C 0x800D6DA0 */
    virtual int getFaceJointIdx() const;
    /* VT+0x10 0x800D5720 */
    virtual void createModel();
    /* VT+0x14 0x800D5740 */
    virtual void initialize();
    /* VT+0x18 0x800D5750 */
    virtual void play();
    /* VT+0x1C 0x800D5760 */
    virtual void _calc();
    /* VT+0x20 0x800D6D90 */
    virtual void calc2();
    /* VT+0x24 0x800D5C70 */
    virtual void draw();
    /* VT+0x28 0x800D5870 */
    virtual m3d::mdl_c* getBodyMdl();
    /* VT+0x2C 0x800D62D0 */
    virtual const void* getAnmResFile() const;
    /* VT+0x30 0x800D5730 */
    virtual void setPlayerMode(int);
    /* VT+0x34 0x800D5CC0 */
    virtual void setColorType(u8 colorType);
    /* VT+0x38 0x800D6D80 */
    virtual void setDark(int);

    /* VT+0x3C 0x800BD750 */
    virtual void VT_0x3C()
    {
    }

    /* VT+0x40 0x800D6D70 */
    virtual void onStarAnm();
    /* VT+0x44 0x800D6D60 */
    virtual void offStarAnm();

    /* VT+0x48 */
    [[address(0x800BD740) /* d_kinopio_model.o */]]
    virtual void onStarEffect();
    /* VT+0x4C */
    [[address(0x800BD730) /* d_kinopio_model.o */]]
    virtual void offStarEffect();

    /* VT+0x50 0x800D5820 */
    virtual void getJointMtx(mMtx_c*, int);
    /* VT+0x54 0x800D6D50 */
    virtual bool getHeadPropelJointMtx(mMtx_c*);
    /* VT+0x58 0x800D6930 */
    virtual void VT_0x58();
    /* VT+0x5C 0x800D5EC0 */
    virtual void setAnm(int, float, float, float);
    /* VT+0x60 0x800D6920 @unofficial */
    virtual bool prepareBodyAnm(ChrAnmType_e type, nw4r::g3d::ResAnmChr* out, bool noUpdate);
    /* VT+0x64 0x800D62F0 */
    virtual void setBodyAnm(int, float, float, float);
    /* VT+0x68 0x800D63E0 */
    virtual void releaseBodyAnm(float);
    /* VT+0x6C 0x800D62E0 */
    virtual void copyAnm();
    /* VT+0x70 0x800D6690 */
    virtual void VT_0x70();
    /* VT+0x74 0x800D66A0 */
    virtual void VT_0x74();
    /* VT+0x78 0x800D66B0 */
    virtual void setAnmBind();
    /* VT+0x7C 0x800D66C0 */
    virtual void VT_0x7C();
    /* VT+0x80 0x800D6A20 */
    virtual void setTexAnmType(TexAnmType_e);
    /* VT+0x84 0x800D5D00 */
    virtual void setFrame(float);
    /* VT+0x88 0x800D5D70 */
    virtual void setBodyFrame(float);
    /* VT+0x8C 0x800D5D80 */
    virtual void setRate(float);
    /* VT+0x90 0x800D5DF0 */
    virtual void setBodyRate(float);
    /* VT+0x94 0x800D6D40 */
    virtual void setPropelRollSpeed(u16);
    /* VT+0x98 0x800D6D30 */
    virtual s16 getPropelRollSpeed() const;
    /* VT+0x9C 0x800D6D20 */
    virtual void setPropelRollAngle(s16);
    /* VT+0xA0 0x800D6D10 */
    virtual s16 getPropelRollAngle() const;
    /* VT+0xA4 0x800D6D00 */
    virtual void setPropelScale(float);

    /* VT+0xA8 0x800D6CF0 */
    virtual float* getLegLengthP(u8);

    /* VT+0xAC 0x800BD720 */
    virtual void updateBonusCap()
    {
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ mAllocator_c mAllocator;

    FILL(0x020, 0x150);

    /* 0x150 */ u8 mPlayerNo;
    /* 0x151 */ u8 mCharaID;
    /* 0x152 */ u8 mPowerupID;
    /* 0x153 */ u8 mCurColorType;

    FILL(0x154, 0x160);

    /* 0x160 */ u32 mFlags;
    /* 0x164 */ u32 mFlags2;

    FILL(0x168, 0x17C);

    /* 0x17C */ u32 mVisibilityFlags;

    FILL(0x180, 0x20C);
};
