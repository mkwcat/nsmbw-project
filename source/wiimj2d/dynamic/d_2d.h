#pragma once

#include <machine/m_2d.h>
#include <nw4r/lyt/Pane.h>

namespace d2d
{

class ResAccMult_c;

class Multi_c : public m2d::Base_c
{
    SIZE_ASSERT(0xAC);

public:
    /* 0x80006CD0 */
    Multi_c();

    /* VT+0x08 0x80006E30 */
    virtual ~Multi_c() override;

    /* VT+0x0C 0x80007010 */
    virtual void draw() override;

    /* VT+0x10 0x80006EB0 */
    virtual void calc();

    /* VT+0x14 0x80007230 */
    virtual bool build(const char* lytName, ResAccMult_c* resAcc);

    /* 0x80006EA0 */
    void entry();

    /* 0x80007220 */
    nw4r::lyt::Pane* getRootPane();

    bool hasAccessor() const
    {
        return mpResAccessor != nullptr;
    }

private:
    FILL(0x10, 0x84);

    /* 0x84 */ ResAccMult_c* mpResAccessor;

    FILL(0x88, 0xAC);
};

} // namespace d2d