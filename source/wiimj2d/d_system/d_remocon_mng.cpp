// d_remocon_mng.cpp
// NSMBW .text: 0x800DBFD0 - 0x800DDA40

#include "d_remocon_mng.h"

#include "d_system/d_mj2d_game.h"
#include "machine/m_pad.h"
#include <egg/core/eggController.h>
#include <revolution/os.h>
#include <revolution/wpad.h>

[[nsmbw_data(0x80428280)]]
bool dRemoconMng_c::dConnect_c::m_isBoot;

[[nsmbw_data(0x8042A308)]]
dRemoconMng_c* dRemoconMng_c::m_instance;

[[nsmbw(0x800DC000)]]
void ClearDeviceCallback(s32);

[[nsmbw(0x800DC040)]]
dRemoconMng_c::dRemoconMng_c();

dRemoconMng_c::dRemoconMng_c(dRemoconMng_c* old)
  : mDummyConnect(*new dConnect_c(mPad::CH_e::COUNT))
{
    for (std::size_t connect = 0; connect < 4; connect++) {
        dConnect_c* pConnect = mpConnectAll[connect] = old->mpConnect[connect];
        pConnect->mChannel = connect;
        pConnect->mPlayerNo = -1;
    }
    u8* pAllConnect = new (alignof(dConnect_c)) u8[sizeof(dConnect_c) * (CONNECT_COUNT - 4)];
    for (std::size_t connect = 4; connect < CONNECT_COUNT; connect++) {
        mpConnectAll[connect] = new (pAllConnect + sizeof(dConnect_c) * (connect - 4))
          dConnect_c(static_cast<mPad::CH_e>(connect));
    }

    operator delete(old);

    std::size_t connect = 0, player = 0;
    for (; connect < 4 && player < 4; connect++) {
        if (!mpConnectAll[connect]->isSetup()) {
            continue;
        }

        dConnect_c* pConnect = mpConnectAll[connect];
        pConnect->mPlayerNo = player;
        mpConnect[player] = pConnect;
        mPad::setPlayerOrder(player++, pConnect->getChannel());
    }

    for (; player < PLAYER_COUNT; player++) {
        mpConnect[player] = &mDummyConnect;
    }
}

[[nsmbw(0x800DC0D0)]]
dRemoconMng_c::~dRemoconMng_c()
{
    for (std::size_t connect = 0; connect < CONNECT_COUNT; connect++) {
        dConnect_c* pConnect = mpConnectAll[connect];
        mpConnect[connect] = nullptr;
        delete pConnect;
    }
}

[[nsmbw(0x800DC180)]]
dRemoconMng_c::dConnect_c::~dConnect_c()
{
#ifndef __has_macintosh_dt_fix
    mExtension.~dExtension_c();
#endif // !__has_macintosh_dt_fix
}

[[nsmbw(0x800DC360)]]
dRemoconMng_c::dConnect_c::dExtension_c::~dExtension_c()
{
}

[[nsmbw(0x800DC570)]]
void dRemoconMng_c::execute()
{
    for (int i = 0; i < CONNECT_COUNT; i++) {
        m_instance->mpConnectAll[i]->execute();
    }

    bool allowConnect = false;

    // Only the first 4 matter because the rest are GameCube controllers
    for (int i = mPad::CH_e::CHAN_0; i <= mPad::CH_e::CHAN_LAST; i++) {
        dConnect_c* connect = m_instance->mpConnectAll[i];

        if (!connect->mAllowConnect) {
            continue;
        }

        if (!connect->mStateMgr.getStateID()->isEqual(connect->StateID_Setup)) {
            allowConnect = true;
            break;
        }
    }

    WPADSetAcceptConnection(allowConnect);
}

void dRemoconMng_c::setFirstConnect(int first)
{
    int base = mFirstConnect;
    int target = first;

    if (base == target) {
        return;
    }

    mFirstConnect = target;

    if (target < base) {
        for (; base < PLAYER_COUNT; base++, target++) {
            mpConnect[target] = mpConnect[base];
            mPad::setPlayerOrder(target, mpConnect[base]->getChannel());
        }
        for (; target < PLAYER_COUNT; target++) {
            mpConnect[target] = &mDummyConnect;
        }
    } else {
        int count = PLAYER_COUNT - target;
        target = PLAYER_COUNT - 1;
        base = base + count - 1;
        for (; count > 0; count--, base--, target--) {
            mpConnect[target] = mpConnect[base];
            mPad::setPlayerOrder(target, mpConnect[base]->getChannel());
        }
        for (; target >= 0; target--) {
            mpConnect[target] = &mDummyConnect;
        }
    }
}

[[nsmbw(0x800DC660)]]
dRemoconMng_c::dConnect_c::dConnect_c(mPad::CH_e channel)
  : mPlayerNo(-1)
  , mExtension(channel)
  , mBattery(-1)
  , mAllowConnect(true)
  , mEnableMotor(false)
  , mChannel(channel)
  , mStateMgr(*this, StateID_Shutdown)
{
    if (channel != mPad::CH_e::COUNT) {
        mPad::g_core[channel]->createRumbleMgr(8);
    }
}

void dRemoconMng_c::dConnect_c::registerOrder()
{
    if (mPlayerNo >= 0) {
        return;
    }

    auto* mng = dRemoconMng_c::m_instance;
    for (std::size_t player = mng->mFirstConnect; player < PLAYER_COUNT; player++) {
        if (mng->mpConnect[player] == &mng->mDummyConnect) {
            mng->mpConnect[player] = this;
            mPad::setPlayerOrder(player, mPad::CH_e(mChannel));
            mPlayerNo = player;
            break;
        }
    }
}

void dRemoconMng_c::dConnect_c::deregisterOrder()
{
    if (mPlayerNo < 0) {
        return;
    }

    auto* mng = dRemoconMng_c::m_instance;
    mng->mpConnect[mPlayerNo] = &mng->mDummyConnect;
    mPlayerNo = -1;
}

bool dRemoconMng_c::dConnect_c::splitExtension()
{
    if (mPlayerNo < 0 || mExtension.getType() != dExtension_c::Type_e::CLASSIC ||
        (mChannel >= mPad::CH_e::CHAN_CL_0 && mChannel <= mPad::CH_e::CHAN_CL_LAST)) {
        return false;
    }

    int classic = mChannel + (mPad::CH_e::CHAN_CL_0 - mPad::CH_e::CHAN_0);

    auto* mng = dRemoconMng_c::m_instance;

    std::size_t classicPlayer = mng->mFirstConnect;
    for (; classicPlayer < PLAYER_COUNT; classicPlayer++) {
        if (mng->mpConnect[classicPlayer] == &mng->mDummyConnect) {
            break;
        }
    }
    if (classicPlayer == PLAYER_COUNT) {
        return false;
    }

    dConnect_c* classicConnect = mng->mpConnectAll[classic];
    classicConnect->mPlayerNo = classicPlayer;
    classicConnect->mStateMgr.changeState(StateID_Setup);
    classicConnect->mExtension.mStateMgr.changeState(*mExtension.mStateMgr.getStateID());

    mPad::setPlayerOrder(mPlayerNo, mPad::CH_e(mChannel));
    mPad::setPlayerOrder(classicPlayer, mPad::CH_e(classic));

    mExtension.mStateMgr.changeState(dExtension_c::StateID_Split);

    return true;
}

[[nsmbw(0x800DC7E0)]]
void dRemoconMng_c::dConnect_c::executeState_Shutdown()
{
    EGG::Controller* controller = mPad::g_core[mChannel];
    if (controller->getClassicController()) {
        return;
    }

    if (EGG::CoreController* core = controller->getCoreController()) {
        if (!core->connected()) {
            return;
        }
        if (mChannel >= mPad::CH_e::CHAN_0 && mChannel <= mPad::CH_e::CHAN_LAST) {
            if (core->mStatus->getDevType() != mPad::g_padMg->mDevTypes(mChannel)) {
                return;
            }
            if (!mAllowConnect) {
                WPADDisconnect(static_cast<WPADChannel>(mChannel));
                return;
            }
        } else if (!mAllowConnect) {
            return;
        }
    } else if (EGG::GCController* dolphin = controller->getGCController()) {
        if (!dolphin->connected()) {
            return;
        }
        if (!mAllowConnect) {
            // No WPADDisconnect for GameCube controllers
            return;
        }
    } else {
        return;
    }

    if (m0x58 == 0) {
        m0x58 = 1;
        return;
    }

    mStateMgr.changeState(StateID_Setup);
}

[[nsmbw(0x800DC910)]]
void dRemoconMng_c::dConnect_c::initializeState_Setup()
{
    // Call to dRemoconMng_c::dConnect_c::dExtension_c::setup removed because it's just a blr

    OS_REPORT("SETUP CONTROLLER %d\n", static_cast<int>(mChannel));

    mBattery = mPad::getBatteryLevel_ch(mPad::CH_e(mChannel));

    if (mChannel >= mPad::CH_e::CHAN_0 && mChannel <= mPad::CH_e::CHAN_LAST) {
        // Some Wii Remote speaker thing
        void UNDEF_802d6d50(mPad::CH_e channel, int param2);
        UNDEF_802d6d50(mPad::CH_e(mChannel), 0);

        // The rumble when you connect a Wii Remote. I don't want this to play for GameCube
        // controllers preferably.
        if (!m_isBoot) {
            mPad::g_core[mChannel]->startPowerFrameRumble(1.0f, 10, false);
        }
    }

    registerOrder();
}

[[nsmbw(0x800DC990)]]
void dRemoconMng_c::dConnect_c::finalizeState_Setup()
{
    deregisterOrder();

    mExtension.shutdown();

    if (mChannel < mPad::CH_e::CHAN_GC_0) {
        // Some Wii Remote speaker thing
        void UNDEF_802d6db0(mPad::CH_e channel, int param2);
        UNDEF_802d6db0(mPad::CH_e(mChannel), 0);
    }
}

[[nsmbw(0x800DC9D0)]]
void dRemoconMng_c::dConnect_c::executeState_Setup()
{
    EGG::Controller* controller = mPad::g_core[mChannel];
    if (controller->getClassicController()) {
        auto type = mExtension.getType();
        if (type != dExtension_c::Type_e::CLASSIC && type != dExtension_c::Type_e::WAIT) {
            return mStateMgr.changeState(StateID_Shutdown);
        }
    } else if (EGG::CoreController* core = controller->getCoreController()) {
        if (!core->connected()) {
            return mStateMgr.changeState(StateID_Shutdown);
        }
        if (!mAllowConnect && mChannel >= mPad::CH_e::CHAN_0 && mChannel <= mPad::CH_e::CHAN_LAST) {
            WPADDisconnect(static_cast<WPADChannel>(mChannel));
            return mStateMgr.changeState(StateID_Shutdown);
        }
    } else if (EGG::GCController* gc = controller->getGCController()) {
        if (!gc->connected()) {
            return mStateMgr.changeState(StateID_Shutdown);
        }
    }

    mExtension.execute();

    mBattery = mPad::getBatteryLevel_ch(mPad::CH_e(mChannel));
}

[[nsmbw(0x800DCA60)]]
void dRemoconMng_c::dConnect_c::execute();

[[nsmbw(0x800DCA80)]]
void dRemoconMng_c::dConnect_c::onRumbleEnable();

void dRemoconMng_c::dConnect_c::dExtension_c::checkState()
{
    EGG::CoreController* core = mPad::g_core[mChannel]->getCoreController();
    if (!core) {
        return;
    }

    if (mPad::g_padMg->mDevTypes(core->mChannel) != core->mStatus->getDevType()) {
        return;
    }

    switch (core->mStatus->getDevType()) {
    case EGG::cDEV_CORE:
        if (mType != Type_e::NONE) {
            mStateMgr.changeState(StateID_None);
        }
        break;
    case EGG::cDEV_FREESTYLE:
        if (mType != Type_e::FREESTYLE) {
            mStateMgr.changeState(StateID_Freestyle);
        }
        break;
    case EGG::cDEV_CLASSIC:
        if (mType != Type_e::CLASSIC) {
            mStateMgr.changeState(StateID_Classic);
        }
        break;

    case EGG::cDEV_FUTURE:
    case EGG::cDEV_NOT_SUPPORTED:
        if (mType != Type_e::OTHER) {
            mStateMgr.changeState(StateID_Other);
        }
        break;

    default:
        break;
    }
}

[[nsmbw(0x800DCAF0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Wait()
{
    mType = Type_e::WAIT;
}

// Empty
[[nsmbw(0x800DCB00)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Wait();

[[nsmbw(0x800DCB10)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Wait()
{
    checkState();
}

[[nsmbw(0x800DCC40)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_None()
{
    mType = Type_e::NONE;
}

// Empty
[[nsmbw(0x800DCC50)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_None();

[[nsmbw(0x800DCC60)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_None()
{
    checkState();
}

[[nsmbw(0x800DCD70)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Freestyle()
{
    mType = Type_e::FREESTYLE;
}

// Empty
[[nsmbw(0x800DCC80)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Freestyle();

[[nsmbw(0x800DCCA0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Freestyle()
{
    checkState();
}

[[nsmbw(0x800DCEA0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Other()
{
    mType = Type_e::OTHER;
}

// Empty
[[nsmbw(0x800DCEB0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Other();

[[nsmbw(0x800DCEC0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Other()
{
    checkState();
}

void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Split()
{
    mType = Type_e::NONE;
}

void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Split()
{
    int classic = mChannel + (mPad::CH_e::CHAN_CL_0 - mPad::CH_e::CHAN_0);
    if (!dRemoconMng_c::m_instance->mpConnectAll[classic]->isSetup()) {
        mType = Type_e::WAIT;
        checkState();
    }
}

void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Split()
{
}

void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Classic()
{
    mType = Type_e::CLASSIC;

    mPad::setPlayerOrder(
      dRemoconMng_c::m_instance->mpConnectAll[mChannel]->mPlayerNo, getChannel()
    );
}

void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Classic()
{
    mPad::setPlayerOrder(dRemoconMng_c::m_instance->mpConnectAll[mChannel]->mPlayerNo, mChannel);
}

void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Classic()
{
    checkState();
}

void dRemoconMng_c::dConnect_c::dExtension_c::initializeState_Dolphin()
{
    mType = Type_e::DOLPHIN;
}

void dRemoconMng_c::dConnect_c::dExtension_c::finalizeState_Dolphin()
{
}

void dRemoconMng_c::dConnect_c::dExtension_c::executeState_Dolphin()
{
}

[[nsmbw(0x800DCFD0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::shutdown();

[[nsmbw(0x800DCFF0)]]
void dRemoconMng_c::dConnect_c::dExtension_c::execute();
