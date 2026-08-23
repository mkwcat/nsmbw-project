#pragma once

#include <nw4r/lyt/ResourceAccessor.h>
#include <nw4r/ut/List.h>

namespace nw4r::lyt {
class Group;
};

namespace m2d {

class AnmResV2_c;

class FrameCtrl_c {
    SIZE_ASSERT(0x14);
    /* 0x00 VTABLE 0x80317774 */

public:
    /* VT+0x8 0x800C92E0 */
    virtual ~FrameCtrl_c();

public:
    /* 0x04 */ float m0x04 = 0.0f;
    /* 0x08 */ float m0x08 = 0.0f;
    /* 0x0C */ float m0x0C = 0.0f;
    /* 0x10 */ float m0x10 = 1.0f;
};

class AnmGroupBase_c {
    SIZE_ASSERT(0x10);

public:
    /* 0x0 */ FrameCtrl_c*      mpFrameCtrl;
    /* 0x4 */ AnmResV2_c*       mpAnmRes;
    /* 0x8 */ nw4r::lyt::Group* mpLytGroup;
    /* 0xC */ u8                mFlag;
};

class AnmGroup_c : public AnmGroupBase_c {
    SIZE_ASSERT(0x28);

public:
    /* 0x10 */ FrameCtrl_c mFrameCtrl;
    /* 0x24 */ s32         m0x24;
};

class ResAccIf_c {
    SIZE_ASSERT(0xC);

    /* 0x0 VTABLE */

public:
    /* VT+0x8 */
    virtual ~ResAccIf_c()  = 0;

    /* VT+0xC */
    virtual void creater() = 0;

    /* 0x801637A0 */
    bool attach(void* data, const char* name);

    /* 0x801637D0 */
    void detach();

    /* 0x801637E0 */
    void* getResource(u32 sect, const char* name);

private:
    /* 0x4 */ nw4r::lyt::ResourceAccessor* mpResAccessor;
    /* 0x8 */ void*                        mpResource;
};

class Base_c {
    SIZE_ASSERT(0xD);

public:
    Base_c(
        u8 priority
    )
        : mPriority(priority) {}

    /* 0x0 */ nw4r::ut::Node mLink;

    /* 0x8 VTABLE */

    /* VT+0x8 */
    virtual ~Base_c()   = default;

    /* VT+0xC */
    virtual void draw() = 0;

    [[nsmbw(0x80163990)]]
    void entry();

    /* 0xC */ u8 mPriority;
};

} // namespace m2d
