// eggController.cpp
// NSMBW .text: 0x802BC9D0 - 0x802BE710

#include "eggController.h"

#include <bit>
#include <cstring>
#include <iterator>
#include <revolution/kpad.h>
#include <revolution/pad.h>
#include <revolution/wpad.h>

namespace EGG
{

// Variables
// ^^^^^^

[[nsmbw_data(0x8042B150)]]
CoreControllerMgr* CoreControllerMgr::sInstance;

[[nsmbw_data(0x8042B160)]]
bool s_allocatorCreated;

// Functions
// ^^^^^^

namespace
{
u32 getStickButton(const f32& x, const f32& y)
{
    u32 result = 0;

    if (x <= -0.5f) {
        result |= 2_bit;
    } else if (x >= 0.5f) {
        result |= 3_bit;
    }

    if (y <= -0.5f) {
        result |= 1_bit;
    } else if (y >= 0.5f) {
        result |= 0_bit;
    }

    return result;
}
} // namespace

[[nsmbw(0x802BC9E0)]]
u32 CoreStatus::getFSStickButton() const
{
    return getStickButton(getFSStickX(), getFSStickY())
           << std::countr_zero<u32>(cCORE_FSSTICK_BUTTONS);
}

[[nsmbw(0x802BCA90)]]
CoreController::CoreController();

[[nsmbw(0x802BCAF0)]]
void CoreController::sceneReset();

[[nsmbw(0x802BCBB0)]]
Vector2f CoreController::getDpdRawPos();

[[nsmbw(0x802BCBF0)]]
void Controller::startMotor()
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController()) {
        return ::WPADControlMotor(core->mChannel, WPAD_MOTOR_RUMBLE);
    }

    if (auto* gc = getGCController()) {
        return ::PADControlMotor(gc->mChannel, 1);
    }
}

[[nsmbw(0x802BCC00)]]
void Controller::stopMotor()
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController()) {
        return ::WPADControlMotor(core->mChannel, WPAD_MOTOR_STOP);
    }

    if (auto* gc = getGCController()) {
        return ::PADControlMotor(gc->mChannel, 0);
    }
}

[[nsmbw(0x802BCC10)]]
void Controller::createRumbleMgr(u8 overlap_num)
{
    if (getClassicController()) {
        return;
    }

    EGG::ControllerRumbleMgr* mgr = new ControllerRumbleMgr();

    if (auto* core = getCoreController(); core) {
        core->mRumbleMgr = mgr;
    } else if (auto* gc = getGCController(); gc) {
        gc->mRumbleMgr = mgr;
    }

    mgr->createUnit(overlap_num, this);
}

[[nsmbw(0x802BCC70)]]
void Controller::startPatternRumble(const char* pattern, int frame, bool force)
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController(); core && core->mRumbleMgr) {
        return core->mRumbleMgr->startPattern(pattern, frame, force);
    }

    if (auto* gc = getGCController(); gc && gc->mRumbleMgr) {
        return gc->mRumbleMgr->startPattern(pattern, frame, force);
    }
}

[[nsmbw(0x802BCC90)]]
void Controller::startPowerFrameRumble(f32 power, int frame, bool force)
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController(); core && core->mRumbleMgr) {
        return core->mRumbleMgr->startPowerFrame(power, frame, force);
    }

    if (auto* gc = getGCController(); gc && gc->mRumbleMgr) {
        return gc->mRumbleMgr->startPowerFrame(power, frame, force);
    }
}

[[nsmbw(0x802BCCB0)]]
void Controller::stopRumbleMgr()
{
    if (getClassicController()) {
        return;
    }

    if (auto* core = getCoreController(); core && core->mRumbleMgr) {
        return core->mRumbleMgr->stop();
    }

    if (auto* gc = getGCController(); gc && gc->mRumbleMgr) {
        return gc->mRumbleMgr->stop();
    }
}

[[nsmbw(0x802BCCD0)]]
void CoreController::calc_posture_matrix(Matrix34f& posture, bool checkStable);

[[nsmbw(0x802BD0D0)]]
void CoreController::beginFrame(PADStatus*)
{
    s32 kpad_result;
    mReadStatusIdx = KPADReadEx(mChannel, mStatus, std::size(mStatus), &kpad_result);
    if (mReadStatusIdx == 0 && kpad_result == -1) {
        mReadStatusIdx = 1;
    }

    u32 dev_type;
    switch (WPADProbe(mChannel, &dev_type)) {
    case WPADResult::WPAD_ERR_OK: {
        if (dev_type == cDEV_NULL) {
            mFlag.resetBit(0);
        } else {
            mFlag.setBit(0);
        }
    } break;

    case WPADResult::WPAD_ERR_NO_CONTROLLER: {
        mFlag.resetBit(0);
    } break;

    default:
    }

    if (mReadStatusIdx > 0) {
        CoreStatus* pStatus = mStatus;
        u32 prev_held = mHeld;
        mHeld = 0;
        if (pStatus->isFreestyle()) {
            mHeld = pStatus->getFSStickButton();
        }

        if (mpClassic) {
            if (pStatus->isClassic()) {
                mpClassic->mFlag.setBit(0);
                mpClassic->beginFrame(nullptr);
            } else {
                mpClassic->mFlag.resetBit(0);
            }
        }

        mTriggered = mHeld & ~prev_held;
        mReleased = prev_held & ~mHeld;
        pStatus->hold &= ~cCORE_FSSTICK_BUTTONS;
        pStatus->trig &= ~cCORE_FSSTICK_BUTTONS;
        pStatus->release &= ~cCORE_FSSTICK_BUTTONS;
        pStatus->hold |= (mHeld & cCORE_FSSTICK_BUTTONS);
        pStatus->trig |= (mTriggered & cCORE_FSSTICK_BUTTONS);
        pStatus->release |= (mReleased & cCORE_FSSTICK_BUTTONS);
    }

    mPostureMatrixPrev.copyFrom(mPostureMatrix);
    mAccelFlags.makeAllZero();
    Vector3f acc = mStatus->getAccel();

    for (int i = 0; i < 3; i++) {
        if (acc(i) - mAccel(i) < mMaxAccelDiff) {
            if (mMaxAccelFrameTime <= ++mAccelFrameTime[i]) {
                mAccelFrameTime[i] = mMaxAccelFrameTime;
                mAccelFlags.set(1 << i);
                mPrevAccel(i) = acc(i);
            }
        } else {
            mAccelFlags.value &= ~(1 << i); // ?
            mAccelFrameTime[i] = 0;
        }
    }

    calc_posture_matrix(mPostureMatrix, true);

    if (mEnableMotor) {
        if (mMotorPattern & (1 << mMotorPatternPos)) {
            startMotor();
        } else {
            stopMotor();
        }

        if (mMotorPatternPos == 0) {
            mMotorPatternPos = mMotorPatternLength - 1;
        } else {
            mMotorPatternPos = mMotorPatternPos - 1;
        }

        if (--mMotorFrameDuration == 0) {
            stopMotor();
            mEnableMotor = false;
        }
    }

    if (mRumbleMgr) {
        mRumbleMgr->calc();
    }
    bool increment = true;

    if (mStatus->getHold() != 0) {
        increment = false;
    }

    if (increment) {
        Vector3f diff = (mAccel - mStatus->getAccel());
        if (diff.squaredLength() > 0.01f) {
            increment = false;
        }
    }
    if (increment) {
        Vector2f diff = (mDpdPos - getDpdRawPos());
        if (diff.squaredLength() > 0.05f) {
            increment = false;
        }
    }

    if (increment) {
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

[[nsmbw(0x802BD660)]]
CoreController* CoreControllerMgr::getNthController(int n);

[[nsmbw(0x802BD790)]]
CoreControllerMgr::CoreControllerMgr();

void CoreControllerMgr::initClassic()
{
    u8* classicCtrl =
      new (alignof(ClassicController)) u8[sizeof(ClassicController) * mControllers.mSize];

    for (int i = 0; i < mControllers.mSize; i++) {
        CoreController* core = mControllers(i);
        if (core->mpClassic == nullptr) {
            core->mpClassic =
              new (classicCtrl + sizeof(ClassicController) * i) ClassicController(core);
        }
    }
}

[[nsmbw(0x802BDBB0)]]
void CoreControllerMgr::beginFrame();

[[nsmbw(0x802BDC60)]]
void CoreControllerMgr::endFrame();

void GCController::beginFrame(PADStatus* status)
{
    mpStatus = status;
    if (status->err < 0) {
        mFlag.resetBit(0);
        return;
    }
    mFlag.setBit(0);

    // Triggers
    // OEM controllers never report a full analog value
    // So we report a full press if the digital input is being pressed
    mLTrigger = mDown & PADButton::PAD_TRIGGER_L ? 1.0f : float(status->triggerL) / 255.0f;
    mRTrigger = mDown & PADButton::PAD_TRIGGER_R ? 1.0f : float(status->triggerR) / 255.0f;

    // Sticks
    mStick.x = float(status->stickX) / 110.0f;
    mStick.y = float(status->stickY) / 110.0f;
    mSubstick.x = float(status->substickX) / 110.0f;
    mSubstick.y = float(status->substickY) / 110.0f;

    // Buttons
    u32 prev_down = mDown;
    mDown = status->button;
    mDown |= getStickButton(mStick.x, mStick.y) << std::countr_zero<u32>(cDOLPHIN_STICK_BUTTONS);
    mDown |= getStickButton(mSubstick.x, mSubstick.y)
             << std::countr_zero<u32>(cDOLPHIN_SUBSTICK_BUTTONS);
    mTrig = mDown & ~prev_down;
    mUp = ~mDown & prev_down;

    if (mRumbleMgr) {
        mRumbleMgr->calc();
    }

    if (mEnableMotor) {
        if (mMotorPattern & (1 << mMotorPatternPos)) {
            startMotor();
        } else {
            stopMotor();
        }

        if (mMotorPatternPos == 0) {
            mMotorPatternPos = mMotorPatternLength - 1;
        } else {
            mMotorPatternPos = mMotorPatternPos - 1;
        }

        if (--mMotorFrameDuration == 0) {
            stopMotor();
            mEnableMotor = false;
        }
    }

    if (mDown) {
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

void GCController::endFrame()
{
}

EGG_SINGLETON_IMPL(GCControllerMgr);

GCController* GCControllerMgr::getNthController(int n)
{
    return mControllers(n);
}

GCControllerMgr::GCControllerMgr()
{
    mControllers.allocate(4);
    GCController* gcCtrl = new GCController[4]{0, 1, 2, 3};
    for (int i = 0; i < mControllers.mSize; i++) {
        mControllers(i) = gcCtrl + i;
    }
}

void GCControllerMgr::beginFrame()
{
    std::memset(mPadStatus.data(), 0, sizeof(mPadStatus));
    ::PADRead(mPadStatus.data());

    // OEM controllers have imperfections in their analog values
    // PADClamp is designed to remove these imperfections
    ::PADClamp(mPadStatus.data());

    for (int i = 0; i < mControllers.mSize; i++) {
        mControllers(i)->beginFrame(&mPadStatus[i]);
    }
}

void GCControllerMgr::endFrame()
{
    u32 mask = 0;

    for (int i = 0; i < mControllers.mSize; i++) {
        mControllers(i)->endFrame();

        if (mControllers(i)->mFlag.off(1)) {
            // Bit mask starting from the left
            mask |= 1u << (31 - i);
        }
    }

    PADReset(mask);
}

void ClassicController::beginFrame(PADStatus*)
{
    KPADEXStatus::Classic& cl = mpCore->mStatus->ex_status.cl;

    u32 prev_stick_btn = mDown & (cCLASSIC_LSTICK_BUTTONS | cCLASSIC_RSTICK_BUTTONS);

    mDown = cl.hold;
    mTrig = cl.trig;
    mUp = cl.release;

    // Triggers
    mLTrigger = mDown & cCLASSIC_BUTTON_FULL_L ? 1.0f : cl.ltrigger;
    mRTrigger = mDown & cCLASSIC_BUTTON_FULL_R ? 1.0f : cl.rtrigger;

    // Sticks
    mLStick.x = cl.lstick.x;
    mLStick.y = cl.lstick.y;
    mRStick.x = cl.rstick.x;
    mRStick.y = cl.rstick.y;

    mDown |= getStickButton(mLStick.x, mLStick.y) << std::countr_zero<u32>(cCLASSIC_LSTICK_BUTTONS);
    mDown |= getStickButton(mRStick.x, mRStick.y) << std::countr_zero<u32>(cCLASSIC_RSTICK_BUTTONS);

    mTrig |= (mDown & (cCLASSIC_LSTICK_BUTTONS | cCLASSIC_RSTICK_BUTTONS)) & ~prev_stick_btn;
    mUp |= (~mDown & (cCLASSIC_LSTICK_BUTTONS | cCLASSIC_RSTICK_BUTTONS)) & prev_stick_btn;

    if (mDown) {
        if (mIdleTime < 216000) {
            mIdleTime++;
        }
    } else {
        mIdleTime = 0;
    }
}

void ClassicController::endFrame()
{
}

[[nsmbw(0x802BDFF0)]]
ControllerRumbleMgr::ControllerRumbleMgr();

[[nsmbw(0x802BE3B0)]]
ControllerRumbleMgr::~ControllerRumbleMgr();

[[nsmbw(0x802BE050)]]
void ControllerRumbleMgr::createUnit(u8 overlap_num, Controller* pController);

[[nsmbw(0x802BE0E0)]]
void ControllerRumbleMgr::stop();

[[nsmbw(0x802BE150)]]
void ControllerRumbleMgr::calc();

[[nsmbw(0x802BE260)]]
void ControllerRumbleMgr::startPattern(const char* pPattern, int frame, bool force);

[[nsmbw(0x802BE2B0)]]
void ControllerRumbleMgr::startPowerFrame(f32 power, int frame, bool force);

} // namespace EGG
