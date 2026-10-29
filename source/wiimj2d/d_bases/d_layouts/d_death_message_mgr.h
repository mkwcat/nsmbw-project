#pragma once

#include "m_2d.h"
#include <d_mj2d_game.h>
#include <nw4r/lyt/resourceAccessor.h>
#include <nw4r/lyt/resources.h>
#include <nw4r/lyt/textBox.h>

class dDeathMsgMgr_c : public m2d::Base_c {
public:
    // Constants and Types
    // ^^^^^^

    static constexpr u32 MAX_MESSAGES = 12;

public:
    // Structors
    // ^^^^^^

    dDeathMsgMgr_c();
    ~dDeathMsgMgr_c() override;

public:
    // Instance Methods
    // ^^^^^^

    void newMessage(const wchar_t* message, PLAYER_TYPE_e player);
    void deleteFront();

    void build(nw4r::lyt::ResourceAccessor* resAcc, nw4r::lyt::DrawInfo* drawInfo);

public:
    // Virtual Functions
    // ^^^^^^

    virtual void draw() override;

private:
    // Instance Variables
    // ^^^^^^

    nw4r::lyt::TextBox*    mTextBox;
    nw4r::lyt::ResBlockSet mResBlockSet;
    nw4r::lyt::DrawInfo*   mpDrawInfo;

    u32                    mIndex;
    u32                    mCount;
    u32                    mTimeToLive[MAX_MESSAGES];
};
