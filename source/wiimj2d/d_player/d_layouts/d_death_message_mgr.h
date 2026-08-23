#pragma once

#include "d_static/d_a_player/d_a_player_manager.h"
#include "machine/m_2d.h"
#include <nw4r/lyt/ResourceAccessor.h>
#include <nw4r/lyt/Resources.h>
#include <nw4r/lyt/TextBox.h>

class dDeathMsgMgr_c final : public m2d::Base_c
{
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

    nw4r::lyt::TextBox* mTextBox;
    nw4r::lyt::ResBlockSet mResBlockSet;
    nw4r::lyt::DrawInfo* mpDrawInfo;

    u32 mIndex;
    u32 mCount;
    u32 mTimeToLive[MAX_MESSAGES];
};
