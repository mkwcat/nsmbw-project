// d_nextgoto_list.cpp
// nsmbw-project

#include "d_nextgoto_list.h"

#include "component/c_json.h"
#include <cstdlib>
#include <cstring>

dNextGotoList_c::dNextGotoList_c(const char* data, std::size_t dataSize)
{
    if (!cJsonParser_c::parse(
          this, const_cast<char*>(data), dataSize,
          [](void* buffer, std::size_t size, void* userData) -> int {
        return static_cast<int>(size);
    }, nullptr
        )) {
        clear();
    }
}

bool dNextGotoList_c::value(s64 number)
{
    if (mState != State_e::COURSE && mState != State_e::GROUP) {
        return false;
    }

    mEntry.nextgoto = static_cast<u32>(number);
    push_back(mEntry);
    mEntry.group_start = false;
    mWrittenInGroup = true;
    return true;
}

bool dNextGotoList_c::key(const char* str, std::size_t length, bool copy)
{
    if (mNextState != mState) {
        return false;
    }

    switch (mState) {
    default:
        return false;

    case State_e::ROOT: {
        // Stage Name "%02d-%02d"
        int world = std::atoi(str);
        if (world < 0) {
            return false;
        }
        const char* dash = std::strchr(str, '-');
        if (dash == nullptr) {
            return false;
        }
        int stage = std::atoi(dash + 1);
        if (stage < 0) {
            return false;
        }
        mEntry.world = static_cast<u32>(world);
        mEntry.stage = static_cast<u32>(stage);
        mNextState = State_e::STAGE;
        return true;
    }

    case State_e::STAGE: {
        // Course/Area Name "C%d"
        if (length < 2 || str[0] != 'c' || str[1] < '0' || str[1] > '3') {
            return false;
        }
        int course = str[1] - '0';
        mEntry.course = static_cast<u32>(course);
        mNextState = State_e::COURSE;
        return true;
    }
    }
}

bool dNextGotoList_c::string(const char* str, std::size_t length, bool copy)
{
    int number = std::atoi(str);
    return value(static_cast<s64>(number));
}

bool dNextGotoList_c::startObject()
{
    if (mState == State_e::NONE) {
        mState = mNextState = State_e::ROOT;
        return true;
    }

    if (mNextState <= mState) {
        return false;
    }

    mState = mNextState;
    return true;
}

bool dNextGotoList_c::endObject()
{
    if (mState == State_e::NONE) {
        return false;
    }

    if (mState == State_e::ROOT) {
        mState = mNextState = State_e::NONE;
        return true;
    }

    if (mNextState >= mState) {
        return false;
    }

    mState = mNextState;
    return true;
}

bool dNextGotoList_c::startArray()
{
    if (mState != State_e::COURSE) {
        return false;
    }

    mState = mNextState = State_e::GROUP;
    mEntry.group_start = true;
    mWrittenInGroup = false;
    return true;
}

bool dNextGotoList_c::endArray()
{
    if (mState != State_e::GROUP) {
        return false;
    }

    if (mWrittenInGroup) {
        back().group_end = true;
    }
    mEntry.group_start = false;
    mState = mNextState = State_e::COURSE;
    return true;
}