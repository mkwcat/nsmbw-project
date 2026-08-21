#pragma once

#include "machine/m_2d.h"
#include <nw4r/lyt/DrawInfo.h>
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/ResourceAccessor.h>

namespace d2d
{

class ResAccMult_c : public nw4r::lyt::ResourceAccessor
{
    friend class Multi_c;

private:
    SIZE_ASSERT(0xBC);

    FILL(0x00, 0x04);
    /* 0x04 */ nw4r::lyt::ResourceAccessor* mpBase;
    FILL(0x08, 0xBC);
};

class ResAccMultLoader_c : public ResAccMult_c
{
    SIZE_ASSERT(0xD4);

public:
    // Structors
    // ^^^^^^

    /* 0x80006AA0 */
    ResAccMultLoader_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80006BE0 */
    bool request(const char* path);

public:
    FILL(0xBC, 0xD4);
};

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

    inline bool hasAccessor() const
    {
        return mpResAccessor != nullptr;
    }

    inline nw4r::lyt::ResourceAccessor* getResAccessor()
    {
        if (mpResAccessor == nullptr) {
            return nullptr;
        }

        return mpResAccessor->mpBase;
    }

    inline void setResAccessor(ResAccMult_c* obj)
    {
        mpResAccessor = obj;
    }

    inline nw4r::lyt::DrawInfo* getDrawInfo()
    {
        return &mDrawInfo;
    }

private:
    FILL(0x0D, 0x30);

    /* 0x30 */ nw4r::lyt::DrawInfo mDrawInfo;
    /* 0x84 */ ResAccMult_c* mpResAccessor;

    FILL(0x88, 0xAC);
};

} // namespace d2d
