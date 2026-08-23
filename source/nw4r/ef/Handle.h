#pragma once

namespace nw4r::ef {

class LinkedObject;

class HandleBase {
    SIZE_ASSERT(0x8);

private:
    /* 0x0 */ u32           mObjectID;
    /* 0x4 */ LinkedObject* mObject;
};

} // namespace nw4r::ef
