#pragma once

#include <nw4r/lyt/ResourceAccessor.h>
#include <nw4r/ut/List.h>

namespace m2d
{

class ResAccIf_c
{
    SIZE_ASSERT(0xC);

    /* 0x0 VTABLE */

public:
    /* VT+0x8 */
    virtual ~ResAccIf_c() = 0;

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
    /* 0x8 */ void* mpResource;
};

class Base_c
{
    SIZE_ASSERT(0xD);

public:
    Base_c(u8 priority)
      : mPriority(priority)
    {
    }

    /* 0x0 */ nw4r::ut::Node mLink;

    /* 0x8 VTABLE */

    /* VT+0x8 */
    virtual ~Base_c() = default;

    /* VT+0xC */
    virtual void draw() = 0;

    [[address(0x80163990)]]
    void entry();

    /* 0xC */ u8 mPriority;
};

} // namespace m2d