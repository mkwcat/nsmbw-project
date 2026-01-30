#pragma once

#include "egg/core/eggSingleton.h"
#include "egg/math/eggMatrix.h"
#include "egg/math/eggVector.h"
#include "egg/prim/eggBitFlag.h"
#include "egg/prim/eggBuffer.h"
#include <array>
#include <nw4r/ut/List.h>
#include <revolution/kpad.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>
#include <type_traits>

namespace EGG
{

enum eCoreDevType {
    cDEV_CORE = WPAD_DEV_CORE,
    cDEV_FREESTYLE = WPAD_DEV_FREESTYLE,
    cDEV_CLASSIC = WPAD_DEV_CLASSIC,

    cDEV_FUTURE = WPAD_DEV_FUTURE,
    cDEV_NOT_SUPPORTED = WPAD_DEV_NOT_SUPPORTED,
    cDEV_NOT_FOUND = WPAD_DEV_NOT_FOUND,
    cDEV_NULL = WPAD_DEV_NULL,
    cDEV_UNKNOWN = WPAD_DEV_UNKNOWN,
};

enum eCoreButton {
    cCORE_BUTTON_UP = WPAD_BUTTON_UP,
    cCORE_BUTTON_DOWN = WPAD_BUTTON_DOWN,
    cCORE_BUTTON_LEFT = WPAD_BUTTON_LEFT,
    cCORE_BUTTON_RIGHT = WPAD_BUTTON_RIGHT,

    // Sideways Wii Remote
    cCORE_SIDE_BUTTON_UP = WPAD_SIDE_BUTTON_UP,
    cCORE_SIDE_BUTTON_DOWN = WPAD_SIDE_BUTTON_DOWN,
    cCORE_SIDE_BUTTON_LEFT = WPAD_SIDE_BUTTON_LEFT,
    cCORE_SIDE_BUTTON_RIGHT = WPAD_SIDE_BUTTON_RIGHT,

    cCORE_BUTTON_PLUS = WPAD_BUTTON_PLUS,
    cCORE_BUTTON_MINUS = WPAD_BUTTON_MINUS,

    cCORE_BUTTON_1 = WPAD_BUTTON_1,
    cCORE_BUTTON_2 = WPAD_BUTTON_2,

    cCORE_BUTTON_A = WPAD_BUTTON_A,
    cCORE_BUTTON_B = WPAD_BUTTON_B,

    cCORE_BUTTON_HOME = WPAD_BUTTON_HOME,

    cCORE_BUTTON_FS_Z = WPAD_BUTTON_FS_Z,
    cCORE_BUTTON_FS_C = WPAD_BUTTON_FS_C,

    cCORE_FSSTICK_UP = 16_bit,
    cCORE_FSSTICK_DOWN = 17_bit,
    cCORE_FSSTICK_LEFT = 18_bit,
    cCORE_FSSTICK_RIGHT = 19_bit,

    cCORE_FSSTICK_BUTTONS =
      cCORE_FSSTICK_UP | cCORE_FSSTICK_DOWN | cCORE_FSSTICK_LEFT | cCORE_FSSTICK_RIGHT,
};

enum eDolphinButton {
    cDOLPHIN_BUTTON_UP = PAD_BUTTON_UP,
    cDOLPHIN_BUTTON_DOWN = PAD_BUTTON_DOWN,
    cDOLPHIN_BUTTON_LEFT = PAD_BUTTON_LEFT,
    cDOLPHIN_BUTTON_RIGHT = PAD_BUTTON_RIGHT,

    cDOLPHIN_BUTTON_START = PAD_BUTTON_START,

    cDOLPHIN_BUTTON_A = PAD_BUTTON_A,
    cDOLPHIN_BUTTON_B = PAD_BUTTON_B,
    cDOLPHIN_BUTTON_X = PAD_BUTTON_X,
    cDOLPHIN_BUTTON_Y = PAD_BUTTON_Y,

    cDOLPHIN_BUTTON_Z = PAD_TRIGGER_Z,

    cDOLPHIN_BUTTON_FULL_L = PAD_TRIGGER_L,
    cDOLPHIN_BUTTON_FULL_R = PAD_TRIGGER_R,

    cDOLPHIN_STICK_UP = 16_bit,
    cDOLPHIN_STICK_DOWN = 17_bit,
    cDOLPHIN_STICK_LEFT = 18_bit,
    cDOLPHIN_STICK_RIGHT = 19_bit,
    cDOLPHIN_STICK_BUTTONS =
      cDOLPHIN_STICK_UP | cDOLPHIN_STICK_DOWN | cDOLPHIN_STICK_LEFT | cDOLPHIN_STICK_RIGHT,

    cDOLPHIN_SUBSTICK_UP = 20_bit,
    cDOLPHIN_SUBSTICK_DOWN = 21_bit,
    cDOLPHIN_SUBSTICK_LEFT = 22_bit,
    cDOLPHIN_SUBSTICK_RIGHT = 23_bit,
    cDOLPHIN_SUBSTICK_BUTTONS = cDOLPHIN_SUBSTICK_UP | cDOLPHIN_SUBSTICK_DOWN |
                                cDOLPHIN_SUBSTICK_LEFT | cDOLPHIN_SUBSTICK_RIGHT,
};

enum eClassicButton {
    cCLASSIC_BUTTON_UP = WPAD_BUTTON_CL_UP,
    cCLASSIC_BUTTON_DOWN = WPAD_BUTTON_CL_DOWN,
    cCLASSIC_BUTTON_LEFT = WPAD_BUTTON_CL_LEFT,
    cCLASSIC_BUTTON_RIGHT = WPAD_BUTTON_CL_RIGHT,

    cCLASSIC_BUTTON_PLUS = WPAD_BUTTON_CL_PLUS,
    cCLASSIC_BUTTON_MINUS = WPAD_BUTTON_CL_MINUS,

    cCLASSIC_BUTTON_A = WPAD_BUTTON_CL_A,
    cCLASSIC_BUTTON_B = WPAD_BUTTON_CL_B,
    cCLASSIC_BUTTON_X = WPAD_BUTTON_CL_X,
    cCLASSIC_BUTTON_Y = WPAD_BUTTON_CL_Y,

    cCLASSIC_BUTTON_ZL = WPAD_BUTTON_CL_ZL,
    cCLASSIC_BUTTON_ZR = WPAD_BUTTON_CL_ZR,

    cCLASSIC_BUTTON_FULL_L = WPAD_BUTTON_CL_FULL_L,
    cCLASSIC_BUTTON_FULL_R = WPAD_BUTTON_CL_FULL_R,

    cCLASSIC_BUTTON_HOME = WPAD_BUTTON_CL_HOME,

    cCLASSIC_LSTICK_UP = 16_bit,
    cCLASSIC_LSTICK_DOWN = 17_bit,
    cCLASSIC_LSTICK_LEFT = 18_bit,
    cCLASSIC_LSTICK_RIGHT = 19_bit,
    cCLASSIC_LSTICK_BUTTONS =
      cCLASSIC_LSTICK_UP | cCLASSIC_LSTICK_DOWN | cCLASSIC_LSTICK_LEFT | cCLASSIC_LSTICK_RIGHT,

    cCLASSIC_RSTICK_UP = 20_bit,
    cCLASSIC_RSTICK_DOWN = 21_bit,
    cCLASSIC_RSTICK_LEFT = 22_bit,
    cCLASSIC_RSTICK_RIGHT = 23_bit,
    cCLASSIC_RSTICK_BUTTONS =
      cCLASSIC_RSTICK_UP | cCLASSIC_RSTICK_DOWN | cCLASSIC_RSTICK_LEFT | cCLASSIC_RSTICK_RIGHT,
};

class CoreStatus : public KPADStatus
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x802BC9E0 */
    u32 getFSStickButton() const;

    /* 0x802BC9D0 */
    void init()
    {
        *this = {};
    }

    f32 getFSStickX() const
    {
        return ex_status.fs.stick.x;
    }

    f32 getFSStickY() const
    {
        return ex_status.fs.stick.y;
    }

    bool down(u32 mask) const
    {
        return (mask & hold);
    }

    bool up(u32 mask) const
    {
        return (mask & hold) != mask;
    }

    bool downTrigger(u32 mask) const
    {
        return (mask & trig);
    }

    bool upTrigger(u32 mask) const
    {
        return (mask & release);
    }

    bool downAll(u32 mask) const
    {
        return (mask & hold) == mask;
    }

    bool upAll(u32 mask) const
    {
        return (mask & hold) == 0;
    }

    eCoreDevType getDevType() const
    {
        return static_cast<eCoreDevType>(dev_type);
    }

    bool isCore() const
    {
        return getDevType() == cDEV_CORE;
    }

    bool isFreestyle() const
    {
        return getDevType() == cDEV_FREESTYLE;
    }

    bool isClassic() const
    {
        return getDevType() == cDEV_CLASSIC;
    }

    u32 getHold() const
    {
        return hold;
    }

    s8 getDpdValidFlag() const
    {
        return dpd_valid_fg;
    };

    Vector2f getAccelVertical()
    {
        return Vector2f(acc_vertical.x, acc_vertical.y);
    }

    const Vec& getAccel() const
    {
        return acc;
    }
};

class CoreController;
class GCController;
class ClassicController;

class Controller
{
    VTABLE_NONE(0x0, Controller);

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x08 */
    virtual void setPosParam(f32 v1, f32 v2)
    {
    }

    /* VT+0x0C */
    virtual void setHoriParam(f32 v1, f32 v2)
    {
    }

    /* VT+0x10 */
    virtual void setDistParam(f32 v1, f32 v2)
    {
    }

    /* VT+0x14 */
    virtual void setAccParam(f32 v1, f32 v2)
    {
    }

    /* VT+0x18 */
    virtual bool down(u32 mask) const = 0;

    /* VT+0x1C */
    virtual bool up(u32 mask) const = 0;

    /* VT+0x20 */
    virtual bool downTrigger(u32 mask) const = 0;

    /* VT+0x24 */
    virtual bool upTrigger(u32 mask) const = 0;

    /* VT+0x28 */
    virtual bool downAll(u32 mask) const = 0;

    /* VT+0x2C */
    virtual bool upAll(u32 mask) const = 0;

    /* VT+0x30 */
    virtual void beginFrame(PADStatus*) = 0;

    /* VT+0x34 */
    virtual void endFrame() = 0;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x802BCC10 */
    void createRumbleMgr(u8 overlap_num);

    /* 0x802BCCB0 */
    void stopRumbleMgr();

    /* 0x802BCBF0 */
    void startMotor();

    /* 0x802BCC00 */
    void stopMotor();

    /* 0x802BCC70 */
    void startPatternRumble(const char* pattern, int frame, bool force);

    /* 0x802BCC90 */
    void startPowerFrameRumble(f32 power, int frame, bool force);

public:
    // Inline Methods
    // ^^^^^^

private:
    template <class Self, class T>
    using CastReturnType =
      std::conditional_t<std::is_const_v<std::remove_reference_t<Self>>, const T*, T*>;

public:
    inline constexpr auto getCoreController(this auto& self)
      -> CastReturnType<decltype(self), CoreController>
    {
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(self)>, CoreController>) {
            return &self;
        } else if constexpr (std::is_same_v<
                               std::remove_cvref_t<decltype(self)>, ClassicController>) {
            return self.getCoreController();
        } else {
            auto* core =
              mkwcat::VTable::Cast<CastReturnType<decltype(self), CoreController>>(&self);
            if (core) {
                return core;
            }
            auto* classic =
              mkwcat::VTable::Cast<CastReturnType<decltype(self), ClassicController>>(&self);
            if (classic) {
                return classic->getCoreController();
            }
            return nullptr;
        }
    }

    inline constexpr auto getGCController(this auto& self)
      -> CastReturnType<decltype(self), GCController>
    {
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(self)>, GCController>) {
            return &self;
        } else {
            auto* gc = mkwcat::VTable::Cast<CastReturnType<decltype(self), GCController>>(&self);
            return gc;
        }
    }

    inline constexpr auto getClassicController(this auto& self)
      -> CastReturnType<decltype(self), ClassicController>
    {
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(self)>, ClassicController>) {
            return &self;
        } else {
            auto* classic =
              mkwcat::VTable::Cast<CastReturnType<decltype(self), ClassicController>>(&self);
            return classic;
        }
    }
};

class ControllerRumbleMgr;

class CoreController final : public Controller
{
    SIZE_ASSERT(0xBD0);

    VTABLE(0x000, Controller, 0x80350370);

    friend class ClassicController;

public:
    // Structors
    // ^^^^^^

    /* 0x802BCA90 */
    CoreController();

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x08 */
    void setPosParam(f32 v1, f32 v2) override;

    /* VT+0x0C */
    void setHoriParam(f32 v1, f32 v2) override;

    /* VT+0x10 */
    void setDistParam(f32 v1, f32 v2) override;

    /* VT+0x14 */
    void setAccParam(f32 v1, f32 v2) override;

    /* VT+0x18 */
    bool down(u32 mask) const override;

    /* VT+0x1C */
    bool up(u32 mask) const override;

    /* VT+0x20 */
    bool downTrigger(u32 mask) const override;

    /* VT+0x24 */
    bool upTrigger(u32 mask) const override;

    /* VT+0x28 */
    bool downAll(u32 mask) const override;

    /* VT+0x2C */
    bool upAll(u32 mask) const override;

    /* VT+0x30 0x802BD0D0 */
    void beginFrame(PADStatus* pPadStatus) override;

    /* VT+0x34 */
    void endFrame() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x802BCAF0 */
    void sceneReset();

    /* 0x802BCBB0 */
    Vector2f getDpdRawPos();

    /* 0x802BCCD0 */
    void calc_posture_matrix(Matrix34f& posture, bool checkStable);

public:
    // Inline Methods
    // ^^^^^^

    const CoreController* getCoreController() const
    {
        return this;
    }

    inline bool connected() const
    {
        return mFlag.on(1);
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ WPADChannel mChannel;
    /* 0x008 */ u32 mHeld;
    /* 0x00C */ u32 mTriggered;
    /* 0x010 */ u32 mReleased;
    /* 0x014 */ EGG::ClassicController* mpClassic; // Reuse unused field
    /* 0x018 */ CoreStatus mStatus[16];
    /* 0xB18 */ int mReadStatusIdx;
    /* 0xB1C */ TBitFlag<u8> mFlag;
    /* 0xB20 */ Vector3f mAccel;
    /* 0xB2C */ Vector2f mDpdPos;
    /* 0xB34 */ u32 mIdleTime;
    /* 0xB38 */ u32 mMotorPattern;
    /* 0xB3C */ bool mEnableMotor;
    /* 0xB40 */ s32 mMotorFrameDuration;
    /* 0xB44 */ u8 mMotorPatternLength;
    /* 0xB45 */ u8 mMotorPatternPos;
    /* 0xB48 */ ControllerRumbleMgr* mRumbleMgr;
    /* 0xB4C */ Matrix34f mPostureMatrix;
    /* 0xB7C */ Matrix34f mPostureMatrixPrev;
    /* 0xBAC */ TBitFlag<u8> mAccelFlags;
    /* 0xBB0 */ s32 mMaxAccelFrameTime;
    /* 0xBB4 */ s32 mAccelFrameTime[3];
    /* 0xBC0 */ f32 mMaxAccelDiff;
    /* 0xBC4 */ Vector3f mPrevAccel;
};

class GCController final : public Controller
{
    VTABLE_SYM(0x00, Controller, "__vt__Q23EGG12GCController");

    friend class GCControllerMgr;
    friend class Controller;

public:
    // Structors
    // ^^^^^^

    GCController(int channel)
      : mChannel(channel)
    {
    }

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x18 */
    bool down(u32 mask) const override
    {
        return mDown & gcMask(mask);
    }

    /* VT+0x1C */
    bool up(u32 mask) const override
    {
        return (mDown & gcMask(mask)) != gcMask(mask);
    }

    /* VT+0x20 */
    bool downTrigger(u32 mask) const override
    {
        return mTrig & gcMask(mask);
    }

    /* VT+0x24 */
    bool upTrigger(u32 mask) const override
    {
        return mUp & gcMask(mask);
    }

    /* VT+0x28 */
    bool downAll(u32 mask) const override
    {
        return (mDown & gcMask(mask)) == gcMask(mask);
    }

    /* VT+0x2C */
    bool upAll(u32 mask) const override
    {
        return (mDown & gcMask(mask)) == 0;
    }

    /* VT+0x30 0x802BD0D0 */
    void beginFrame(PADStatus* pPadStatus) override;

    /* VT+0x34 */
    void endFrame() override;

public:
    // Instance Methods
    // ^^^^^^

    inline bool connected() const
    {
        return mFlag.on(1);
    }

public:
    // Instance Variables
    // ^^^^^^

    u32 mDown = 0, mTrig = 0, mUp = 0;
    Vector2f mStick = {};
    Vector2f mSubstick = {};
    float mLTrigger = 0.0f, mRTrigger = 0.0f;

private:
    // Private Instance Variables
    // ^^^^^^
    int mChannel;
    PADStatus* mpStatus = nullptr;
    TBitFlag<u8> mFlag;

    u32 mMotorPattern = 0;
    bool mEnableMotor = false;
    s32 mMotorFrameDuration = 0;
    u8 mMotorPatternLength = 0;
    u8 mMotorPatternPos = 0;
    ControllerRumbleMgr* mRumbleMgr = nullptr;

    u32 mIdleTime = 0;

public:
    // Static Inline Methods
    // ^^^^^^
    static constexpr u32 gcMask(u32 mask)
    {
        u32 gc_mask = 0;
        if (mask & cCORE_BUTTON_A) {
            gc_mask |= cDOLPHIN_BUTTON_A;
        }
        if (mask & cCORE_BUTTON_B) {
            gc_mask |= cDOLPHIN_BUTTON_B;
        }
        if (mask & cCORE_BUTTON_PLUS) {
            gc_mask |= cDOLPHIN_BUTTON_START;
        }
        if (mask & cCORE_BUTTON_MINUS) {
            gc_mask |= cDOLPHIN_BUTTON_Z;
        }
        return gc_mask;
    }
};

class ClassicController final : public Controller
{
    VTABLE_SYM(0x00, Controller, "__vt__Q23EGG17ClassicController");

    friend class CoreController;

public:
    // Structors
    // ^^^^^^

    ClassicController(EGG::CoreController* core)
      : mpCore(core)
    {
        mChannel = core->mChannel;
    }

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x18 */
    bool down(u32 mask) const override
    {
        return mDown & clMask(mask);
    }

    /* VT+0x1C */
    bool up(u32 mask) const override
    {
        return (mDown & clMask(mask)) != clMask(mask);
    }

    /* VT+0x20 */
    bool downTrigger(u32 mask) const override
    {
        return mTrig & clMask(mask);
    }

    /* VT+0x24 */
    bool upTrigger(u32 mask) const override
    {
        return mUp & clMask(mask);
    }

    /* VT+0x28 */
    bool downAll(u32 mask) const override
    {
        return (mDown & clMask(mask)) == clMask(mask);
    }

    /* VT+0x2C */
    bool upAll(u32 mask) const override
    {
        return (mDown & clMask(mask)) == 0;
    }

    /* VT+0x30 0x802BD0D0 */
    void beginFrame(PADStatus* pPadStatus) override;

    /* VT+0x34 */
    void endFrame() override;

public:
    // Inline Methods
    // ^^^^^^

    inline CoreController* getCoreController() const
    {
        return mpCore;
    }

    inline bool connected() const
    {
        return mpCore->connected() && mpCore->mStatus->isClassic();
    }

public:
    // Instance Variables
    // ^^^^^^

    u32 mDown = 0, mTrig = 0, mUp = 0;
    Vector2f mLStick = {}, mRStick = {};
    float mLTrigger = 0.0f, mRTrigger = 0.0f;

private:
    // Private Instance Variables
    // ^^^^^^
    WPADChannel mChannel;
    EGG::CoreController* mpCore;
    TBitFlag<u8> mFlag;

    u32 mIdleTime = 0;

public:
    // Static Inline Variables
    // ^^^^^^
    static constexpr u32 clMask(u32 mask)
    {
        u32 cl_mask = 0;
        if (mask & cCORE_BUTTON_A) {
            cl_mask |= cCLASSIC_BUTTON_A;
        }
        if (mask & cCORE_BUTTON_B) {
            cl_mask |= cCLASSIC_BUTTON_B;
        }
        if (mask & cCORE_BUTTON_PLUS) {
            cl_mask |= cCLASSIC_BUTTON_PLUS;
        }
        if (mask & cCORE_BUTTON_MINUS) {
            cl_mask |= cCLASSIC_BUTTON_MINUS;
        }
        if (mask & cCORE_BUTTON_HOME) {
            cl_mask |= cCLASSIC_BUTTON_HOME;
        }
        return cl_mask;
    }
};

class CoreControllerMgr
{
    SIZE_ASSERT(0xE60);

    VTABLE(0x010, CoreControllerMgr, 0x80350318);

    EGG_SINGLETON_DECL(CoreControllerMgr);

public:
    // Structors
    // ^^^^^^

    /* 0x802BD790 */
    CoreControllerMgr();

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x08 0x802BDBB0 */
    virtual void beginFrame();

    /* VT+0x0C 0x802BDC60 */
    virtual void endFrame();

public:
    // Instance Methods
    // ^^^^^^

    void initClassic();

    /* 0x802BD660 */
    CoreController* getNthController(int n);

    inline ClassicController* getNthClassic(int n)
    {
        return getNthController(n)->mpClassic;
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x014 */ TBuffer<CoreController*> mControllers;
    FILL(0x020, 0xE24);
    /* 0xE24 */ TBuffer<eCoreDevType> mDevTypes;
    FILL(0xE30, 0xE60);
};

class GCControllerMgr
{
    EGG_SINGLETON_DECL(GCControllerMgr);

public:
    // Structors
    // ^^^^^^

    GCControllerMgr();

private:
    // Instance Variables
    // ^^^^^^

    /* 0x010 */ TBuffer<GCController*> mControllers;
    /* 0x01C */ std::array<PADStatus, 4> mPadStatus;

public:
    // Instance Methods
    // ^^^^^^

    GCController* getNthController(int n);
    void beginFrame();
    void endFrame();
};

class ControllerRumbleMgr
{
    SIZE_ASSERT(0x20);

    VTABLE(0x00, ControllerRumbleMgr, 0x803502C8);

public:
    // Structors
    // ^^^^^^

    /* 0x802BDFF0 */
    ControllerRumbleMgr();

    /* VT+0x8 0x802BE3B0 */
    virtual ~ControllerRumbleMgr();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x802BE050 */
    void createUnit(u8 overlap_num, Controller* pController);

    /* 0x802BE0E0 */
    void stop();

    /* 0x802BE150 */
    void calc();

    /* 0x802BE260 */
    void startPattern(const char* pPattern, int frame, bool force);

    /* 0x802BE2B0 */
    void startPowerFrame(f32 power, int frame, bool force);

private:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ nw4r::ut::List mActiveUnitList;
    /* 0x10 */ nw4r::ut::List mStoppedUnitList;
    /* 0x1C */ Controller* mpController;
};

} // namespace EGG
