#pragma once

#include "component/c_json.h"
#include "d_nextgoto_randomizer.h"
#include <vector>

class dNextGotoList_c final : private cJsonParser_c::HandlerIf_c,
                              public std::vector<dNextGotoRndizer_c::Entry_s>
{
public:
    // Type Aliases
    // ^^^^^^

    using Entry_s = dNextGotoRndizer_c::Entry_s;

public:
    // Structors
    // ^^^^^^

    constexpr dNextGotoList_c() = default;

    dNextGotoList_c(const char* data, std::size_t dataSize);

private:
    enum class State_e {
        NONE,
        ROOT,
        STAGE,
        COURSE,
        GROUP,
    } mState = State_e::NONE, mNextState = State_e::NONE;

    Entry_s mEntry = {};
    bool mWrittenInGroup = false;

private:
    // JSON interface
    // ^^^^^^

    bool null() override
    {
        return false;
    }

    bool value(s64 number) override;

    bool value(double number) override
    {
        return false;
    }

    bool rawNumber(const char* str, std::size_t length, bool copy) override
    {
        return false;
    }

    bool string(const char* str, std::size_t length, bool copy) override;

    bool key(const char* str, std::size_t length, bool copy) override;

    bool startObject() override;
    bool endObject() override;
    bool startArray() override;
    bool endArray() override;
};