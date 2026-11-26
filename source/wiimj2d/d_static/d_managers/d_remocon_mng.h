#pragma once

#include "d_mj2d_game.h"
#include "m_pad.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"
#include "slu/enum.hpp"
#include <egg/core/eggHeap.h>

class dRemoconMng_c {
public:
    // Constants and Types
    // ^^^^^^

    static constexpr int CONNECT_COUNT = mPad::CHAN_COUNT;

    class dConnect_c;

public:
    // Structors
    // ^^^^^^

    /* 0x800DC040 */
    dRemoconMng_c();

    dRemoconMng_c(dRemoconMng_c* old);

    /* 0x800DC0D0 */
    virtual ~dRemoconMng_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dConnect_c*                   mpConnect[PLAYER_COUNT];
    slu::enum_array<dConnect_c*, mPad::CH_e> mpConnectAll;
    dConnect_c&                              mDummyConnect;
    int                                      mFirstConnect = 0;

public:
    // Static Methods
    // ^^^^^^

    /* 0x800DC570 */
    static void execute();

public:
    // Instance Methods
    // ^^^^^^

    /**
     * Move player 1's controller to the specified slot, and push all the other controllers up by
     * that much too.
     */
    void setFirstConnect(int first);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A308 */
    static dRemoconMng_c* m_instance;
};

class dRemoconMng_c::dConnect_c {
    SIZE_ASSERT(0x98);

    VTABLE(0x00, dConnect_c, 0x803191A4);

    friend class dRemoconMng_c;

public:
    // Nested Classes
    // ^^^^^^

    class dExtension_c {
        SIZE_ASSERT(0x48);

        VTABLE(0x00, dExtension_c, 0x80319240);

        friend class dConnect_c;

    public:
        // Structors
        // ^^^^^^

        dExtension_c(
            mPad::CH_e channel
        )
            : mChannel(channel)
            , mType(Type_e::WAIT)
            , mStateMgr(*this, !isDolphinChannel() ? StateID_Wait : StateID_Dolphin) {}

        /* 0x800DC360 */
        virtual ~dExtension_c();

    public:
        // Constants
        // ^^^^^^

        enum class Type_e {
            NONE      = 0,
            FREESTYLE = 1,
            OTHER     = 2,
            WAIT      = 3,
            CLASSIC   = 4,
            DOLPHIN   = 5,
        };

    public:
        // Instance Methods
        // ^^^^^^

        /* 0x800DCFD0 */
        void shutdown();

        /* 0x800DCFF0 */
        void execute();

        [[nodiscard]] mPad::CH_e getChannel() const {
            if (mType == Type_e::CLASSIC && !isSplitChannel()) {
                return mPad::getClassicChannel(mChannel);
            }
            return mChannel;
        }

        [[nodiscard]] Type_e getType() const { return mType; }

        [[nodiscard]] bool isDolphinChannel() const {
            return mChannel >= mPad::CH_e::CHAN_GC_0 && mChannel <= mPad::CH_e::CHAN_GC_LAST;
        }

        [[nodiscard]] bool isSplitChannel() const {
            return mChannel >= mPad::CH_e::CHAN_CL_0 && mChannel <= mPad::CH_e::CHAN_CL_LAST;
        }

    private:
        void checkState();

    private:
        // Instance Variables
        // ^^^^^^

        /* 0x04 */ mPad::CH_e                       mChannel;
        /* 0x08 */ Type_e                           mType;
        /* 0x0C */ sStateMgrDefault_c<dExtension_c> mStateMgr;

    private:
        // State IDs
        // ^^^^^^

        sState_Extern(0x80371BB0, dRemoconMng_c::dConnect_c::dExtension_c, Wait);
        sState_Extern(0x80371BF0, dRemoconMng_c::dConnect_c::dExtension_c, None);
        sState_Extern(0x80371C30, dRemoconMng_c::dConnect_c::dExtension_c, Freestyle);
        sState_Extern(0x80371C70, dRemoconMng_c::dConnect_c::dExtension_c, Other);
        sState(dRemoconMng_c::dConnect_c::dExtension_c, Split);
        sState(dRemoconMng_c::dConnect_c::dExtension_c, Classic);
        sState(dRemoconMng_c::dConnect_c::dExtension_c, Dolphin);
    };

public:
    // Structors
    // ^^^^^^

    /* 0x800DC660 */
    dConnect_c(mPad::CH_e channel);

    /* 0x800DC180 */
    virtual ~dConnect_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800DCA60 */
    void execute();

    /* 0x800DCA80 */
    void onRumbleEnable();

    void registerOrder();
    void deregisterOrder();
    bool splitExtension();

    [[nodiscard]] int getPlayerNo() const { return mPadID; }

    [[nodiscard]] bool isSetup() const { return mStateMgr.getStateID()->isEqual(StateID_Setup); }

    [[nodiscard]] mPad::CH_e getChannel() const { return mExtension.getChannel(); }

    [[nodiscard]] mPad::CH_e getCoreChannel() const { return mPad::CH_e(mChannel); }

    [[nodiscard]] dExtension_c* getExtension() { return &mExtension; }

    [[nodiscard]] int getBattery() const { return mBattery; }

    [[nodiscard]] bool getAllowConnect() const { return mAllowConnect; }

    bool setAllowConnect(
        bool set
    ) {
        return mAllowConnect = set;
    }

private:
    // Instance Variables
    // ^^^^^^

    /* 0x04 @renamed */ mPad::PadID            mPadID;
    /* 0x08 */ dExtension_c                    mExtension;
    /* 0x50 */ int                             mBattery;
    /* 0x54 */ bool                            mAllowConnect;
    /* 0x55 */ bool                            mEnableMotor;
    /* 0x56 */ slu::enum_value<s8, mPad::CH_e> mChannel;
    /* 0x58 */ int                             m0x58;
    /* 0x5C */ sStateMgrDefault_c<dConnect_c>  mStateMgr;

public:
    // Static Variables
    // ^^^^^^

    /* 0x80428280 */ static bool m_isBoot;

private:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80371B30, dRemoconMng_c::dConnect_c, Shutdown);
    sState_Extern(0x80371B70, dRemoconMng_c::dConnect_c, Setup);
};
