// d_game_key_core.cpp
// NSMBW .text: 0x800B5B50 - 0x800B64A0

#include "d_game_key_core.h"

#include "d_bases/d_s_stage.h"
#include "d_system/d_remocon_mng.h"
#include "framework/f_feature.h"
#include "machine/m_pad.h"
#include "machine/m_vec.h"
#include "state/s_Lib.h"
#include <cmath>
#include <egg/core/eggController.h>
#include <revolution/pad.h>
#include <utility>

[[nsmbw(0x800B5B50)]]
dGameKeyCore_c::dGameKeyCore_c(mPad::CH_e channel);

[[nsmbw(0x800B5BE0)]]
void dGameKeyCore_c::allclear();

[[nsmbw(0x800B5CB0)]]
void dGameKeyCore_c::read()
{
    // Set data from previous frame
    mPrevRawHeld = mRawHeld;
    mPrevHeld = mHeld;
    mAccelOld = mAccel;
    mAccelVerticalXOld = mAccelVerticalX;
    mAccelVerticalYOld = mAccelVerticalY;
    mAngleOld = mAngle;
    mMoveDistanceOld = mMoveDistance;

    EGG::Controller* controller = getController();

    dReplayPlay_c* replayData = dScStage_c::m_replayPlay_p[mPlayerNo];
    if (replayData == nullptr) {
        // Replay is not active for this channel, sssign controller type
        using Extension_e = dRemoconMng_c::dConnect_c::dExtension_c::Type_e;
        Extension_e devType =
          dRemoconMng_c::m_instance->mpConnect[mPlayerNo]->getExtension()->getType();

        EGG::CoreController* core = nullptr;
        EGG::GCController* dolphin = nullptr;
        EGG::ClassicController* classic = nullptr;
        mType = Type_e::CORE;
        if (devType == Extension_e::NONE) {
            // Sideways Wii Remote
        } else if (devType == Extension_e::FREESTYLE) {
            // Wii Remote + Nunchuk
            mType = Type_e::FREESTYLE;
        } else if (devType == Extension_e::CLASSIC) {
            // Wii Classic Controller
            mType = Type_e::CLASSIC;
        } else if (devType == Extension_e::DOLPHIN) {
            // Gamecube Controller
            mType = Type_e::DOLPHIN;
        }

        if (isCore() || isFreestyle() || isClassic()) {
            core = controller->getCoreController();
            if (core && isClassic()) {
                classic = core->mpClassic;
            }
        } else if (isDolphin()) {
            if (dolphin = controller->getGCController(); dolphin) {
                mRawHeld = dolphin->mDown;
            }
        }

        if (core && !isClassic()) {
            // Raw button data from EGG::CoreController
            mRawHeld = core->mStatus->hold & 0x7fffffff;

            // Accelerometer data from EGG::CoreController
            mAccel.x = core->mAccel.x;
            mAccel.y = core->mAccel.y;
            mAccel.z = core->mAccel.z;

            // Flip accelerometer data for Nunchuk mode
            if (mType == Type_e::FREESTYLE) {
                std::swap(mAccel.x, mAccel.z);
            }

            mPad::CH_e channel = mPad::g_playerChannel[mPlayerNo];
            mAccelVerticalX = mPad::g_PadAdditionalData[channel].mAccVertical[0];
            mAccelVerticalY = mPad::g_PadAdditionalData[channel].mAccVertical[1];
            mAccelVerticalZ = mPad::g_PadAdditionalData[channel].mAccVertical[2];

            // Pointer
            mAngle.x = core->mStatus->horizon.x;
            mAngle.y = core->mStatus->horizon.y;
        } else if (isClassic() && classic) {
            mRawHeld = classic->mDown;

            mAccel = {0.0f, classic->mLTrigger - classic->mRTrigger, 0.0f};

            mVec2_c x = {0.0f, classic->mRTrigger - classic->mLTrigger};
            mVec2_c y = x - mAccelVerticalX;
            mVec2_c z = y - mAccelVerticalY;
            mAccelVerticalX = x;
            mAccelVerticalY = y;
            mAccelVerticalZ = z;
        } else if (isDolphin() && dolphin) {
            mRawHeld = dolphin->mDown;

            mAccel = {0.0f, dolphin->mLTrigger - dolphin->mRTrigger, 0.0f};

            mVec2_c x = {0.0f, dolphin->mRTrigger - dolphin->mLTrigger};
            mVec2_c y = x - mAccelVerticalX;
            mVec2_c z = y - mAccelVerticalY;
            mAccelVerticalX = x;
            mAccelVerticalY = y;
            mAccelVerticalZ = z;
        }
    } else {
        // Replay is active, assign data from current replay
        mType = Type_e::CORE;
        if (replayData->mFrameFlags & 0x10000000) {
            mPrevRawHeld = replayData->mPrevFrameInput;
        }
        mRawHeld = replayData->mFrameInput;
        mAccel = replayData->mFrameAccel;
        mAccelVerticalX = replayData->mFrameAccelVertX;
        mAccelVerticalY = replayData->mFrameAccelVertY;
        mAccelVerticalZ = replayData->mFrameAccelVertZ;
    }

    // "Process" inputs for Nunchuck mode
    mPrevHeld = setConfigKey(mPrevRawHeld);
    mHeld = setConfigKey(mRawHeld);
    mTriggered = mHeld & (mHeld ^ mPrevHeld);

    // Not sure what this does
    int uVar10 = 0;
    for (int i = 0; i < 2; i++) {
        int uVar14 = 1 << (uVar10 & 0x3f);
        if (!(mTriggered & uVar14)) {
            if (mHeld & uVar14) {
                if (m0x24 == 0) {
                    m0x20 |= uVar14;
                    m0x24 = m0x2C;
                } else {
                    m0x24--;
                }
            }
        } else {
            m0x20 |= uVar14;
            m0x24 = m0x28;
        }
        uVar14 = 1 << (uVar10 + 1 & 0x3f);
        if (!(mTriggered & uVar14)) {
            if (mHeld & uVar14) {
                if (m0x24 == 0) {
                    m0x20 |= uVar14;
                    m0x24 = m0x2C;
                } else {
                    m0x24--;
                }
            }
        } else {
            m0x20 |= uVar14;
            m0x24 = m0x28;
        }
        uVar10 += 2;
    }

    handleTilting();
    mMoveDistance = EGG::Math<float>::sqrt(
      static_cast<float>(mAccel.z * mAccel.z + mAccel.x * mAccel.x + mAccel.y * mAccel.y)
    );
    if (mMoveDistance < 1.2) {
        mMoveDistance = 1.0;
    }
    setShakeY();
    if (m0x30) {
        m0x30 = 0;
        mTriggered |= m0x30;
    }
    if (mShakeOld) {
        mShake = mShakeOld;
        mShakeOld = 0;
    }
}

[[nsmbw(0x800B60D0)]]
u32 dGameKeyCore_c::setConfigKey(u32 input)
{
    u32 processed;
    switch (mType) {
    default:
    case Type_e::CORE:
        processed = input;
        if (fFeat::shake_with_button && (input & EGG::cCORE_BUTTON_B)) {
            processed |= SHAKE;
        }
        break;

    case Type_e::FREESTYLE:
        // Home, Minus, and Plus can stay the same
        processed = input & (HOME | MINUS | PLUS);

        // Clear D-Pad if stick is pushed in any direction
        if (input & EGG::cCORE_FSSTICK_BUTTONS) {
            input &= ~(UP | DOWN | LEFT | RIGHT);
        }

        if (input & (EGG::cCORE_BUTTON_DOWN | EGG::cCORE_FSSTICK_DOWN)) {
            processed |= DOWN;
        } else if (input & (EGG::cCORE_BUTTON_UP | EGG::cCORE_FSSTICK_UP)) {
            processed |= UP;
        }

        if (input & (EGG::cCORE_BUTTON_RIGHT | EGG::cCORE_FSSTICK_RIGHT)) {
            processed |= RIGHT;
        } else if (input & (EGG::cCORE_BUTTON_LEFT | EGG::cCORE_FSSTICK_LEFT)) {
            processed |= LEFT;
        }

        if (fFeat::shake_with_button) {
            // C is replaced with shake
            if (input & EGG::cCORE_BUTTON_FS_C) {
                processed |= SHAKE;
            }

            if (input & (EGG::cCORE_BUTTON_1 | EGG::cCORE_BUTTON_2)) {
                processed |= BTN_A;
            }

        } else if (input & (EGG::cCORE_BUTTON_FS_C | EGG::cCORE_BUTTON_1 | EGG::cCORE_BUTTON_2)) {
            processed |= BTN_A;
        }

        if (input & EGG::cCORE_BUTTON_B) {
            processed |= (BTN_B | BTN_1);
        }

        if (input & EGG::cCORE_BUTTON_FS_Z) {
            processed |= (BTN_Z | BTN_1);
        }

        if (input & EGG::cCORE_BUTTON_A) {
            processed |= BTN_2;
        }
        break;

    case Type_e::CLASSIC:
        processed = 0;

        if (input & (EGG::cCLASSIC_BUTTON_DOWN | EGG::cCLASSIC_LSTICK_DOWN)) {
            processed |= DOWN;
        } else if (input & (EGG::cCLASSIC_BUTTON_UP | EGG::cCLASSIC_LSTICK_UP)) {
            processed |= UP;
        }

        if (input & (EGG::cCLASSIC_BUTTON_RIGHT | EGG::cCLASSIC_LSTICK_RIGHT)) {
            processed |= RIGHT;
        } else if (input & (EGG::cCLASSIC_BUTTON_LEFT | EGG::cCLASSIC_LSTICK_LEFT)) {
            processed |= LEFT;
        }

        if (input & (EGG::cCLASSIC_BUTTON_A | EGG::cCLASSIC_BUTTON_B)) {
            processed |= BTN_2;
        }

        if (input & (EGG::cCLASSIC_BUTTON_X | EGG::cCLASSIC_BUTTON_Y)) {
            processed |= BTN_1;
        }

        if (input & (EGG::cCLASSIC_BUTTON_ZL | EGG::cCLASSIC_BUTTON_ZR)) {
            processed |= SHAKE;
        }

        if (input & EGG::cCLASSIC_BUTTON_MINUS) {
            processed |= (BTN_A | MINUS);
        }

        if (input & EGG::cCLASSIC_BUTTON_PLUS) {
            processed |= PLUS;
        }
        break;

    case Type_e::DOLPHIN:
        processed = 0;

        if (input & (EGG::cDOLPHIN_BUTTON_DOWN | EGG::cDOLPHIN_STICK_DOWN)) {
            processed |= DOWN;
        } else if (input & (EGG::cDOLPHIN_BUTTON_UP | EGG::cDOLPHIN_STICK_UP)) {
            processed |= UP;
        }

        if (input & (EGG::cDOLPHIN_BUTTON_RIGHT | EGG::cDOLPHIN_STICK_RIGHT)) {
            processed |= RIGHT;
        } else if (input & (EGG::cDOLPHIN_BUTTON_LEFT | EGG::cDOLPHIN_STICK_LEFT)) {
            processed |= LEFT;
        }

        if (input & EGG::cDOLPHIN_BUTTON_A) {
            processed |= BTN_2;
        }

        if (input & EGG::cDOLPHIN_BUTTON_B) {
            processed |= (BTN_Z | BTN_1);
        }

        if (input & EGG::cDOLPHIN_BUTTON_Y) {
            processed |= (BTN_B | BTN_1);
        }

        if (input & EGG::cDOLPHIN_BUTTON_Z) {
            processed |= (SHAKE | MINUS);
        }

        if (input & EGG::cDOLPHIN_BUTTON_X) {
            processed |= BTN_A;
        }

        if (input & EGG::cDOLPHIN_BUTTON_START) {
            processed |= PLUS;
        }
        break;
    }
    return processed;
}

[[nsmbw(0x800B61F0)]]
void dGameKeyCore_c::handleTilting()
{
    if (dScStage_c::m_replayPlay_p[mPlayerNo] != nullptr) {
        mTilt = dScStage_c::m_replayPlay_p[mPlayerNo]->mFrameTilt;
        return;
    }

    if (mType != Type_e::FREESTYLE) {
        mTilt = static_cast<short>(mAccelVerticalX.y * 16384.0);
    } else {
        sLib::addCalcAngle(&mTilt, static_cast<short>(-mAccel.z * 16384.0), 10, 0x1000, 0);
    }
}

[[nsmbw(0x800B62A0)]]
void dGameKeyCore_c::setShakeY()
{
    if (dScStage_c::m_replayPlay_p[mPlayerNo] != nullptr) {
        mShake = dScStage_c::m_replayPlay_p[mPlayerNo]->mFrameFlags & (1 << 29);
        return;
    }

    if (mShakeTimer3 != 0) {
        mShakeTimer3--;
        mShake = false;
        return;
    }

    // Check shake with button
    if (isTrig(SHAKE)) {
        mShake = true;
        return;
    }

    if (!isCore() && !isFreestyle()) {
        // Motion shaking only applies to Wii Remote
        mShake = false;
        return;
    }

    float accXDiff = fabsf(mAccel.x - mAccelOld.x);
    float accYDiff = fabsf(mAccel.y - mAccelOld.y);
    float accZDiff = fabsf(mAccel.z - mAccelOld.z);

    if (accYDiff >= 0.28) {
        mShakeTimer1++;
        if (mShakeTimer1 >= 4 && (accZDiff <= accYDiff || accZDiff <= accXDiff)) {
            mShakeTimer3 = 5;
            mShakeTimer1 = 0;
            mShake = true;
        } else {
            mShake = false;
        }
        return;
    }

    if (mShakeTimer1 != 0 && mShakeTimer2++ >= 2) {
        mShakeTimer1 = 0;
        mShakeTimer2 = 0;
    }

    mShake = false;
}
