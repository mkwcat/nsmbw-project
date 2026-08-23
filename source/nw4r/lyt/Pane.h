#pragma once

#include "DrawInfo.h"
#include "Resources.h"
#include "Types.h"
#include <nw4r/lyt/Material.h>
#include <nw4r/math/types.h>
#include <nw4r/ut/Color.h>
#include <nw4r/ut/LinkList.h>
#include <nw4r/ut/RuntimeTypeInfo.h>

namespace nw4r::lyt {

namespace res {

struct Pane {
    static constexpr char      SIGNATURE[4] = {'p', 'a', 'n', '1'};

    /* 0x00 */ DataBlockHeader blockHeader;
    /* 0x08 */ u8              flag;
    /* 0x09 */ u8              basePosition;
    /* 0x0A */ u8              alpha;
    /* 0x0B */ u8              padding = 0;
    /* 0x0C */ char            name[PANE_NAME_SIZE];
    /* 0x1C */ char            userData[PANE_USERDATA_SIZE];
    /* 0x24 */ math::VEC3      translate;
    /* 0x30 */ math::VEC3      rotate;
    /* 0x3C */ math::VEC2      scale;
    /* 0x44 */ Size            size;
};

} // namespace res

namespace detail {

class PaneBase {
public:
    // Structors
    // ^^^^^^

    PaneBase();

    /* VT+0x4 */
    virtual ~PaneBase();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x4 */ ut::LinkListNode mLink;
};

} // namespace detail

class AnimResource;

class Pane : detail::PaneBase {
    SIZE_ASSERT(0xD8);

public:
    // Structors
    // ^^^^^^

    /* VT+0x08 0x802AB7C0 */
    virtual ~Pane();

public:
    // Constants and Types
    // ^^^^^^

    // For use with TestBit<Uc>
    enum PaneBits {
        VISIBLE          = 0,
        INFLUENCED_ALPHA = 1,
        LOCATION_ADJUST  = 2,
    };

public:
    // Inline Functions
    // ^^^^^^

    bool IsVisible() const { return detail::TestBit<u8>(mFlag, VISIBLE); }

    void SetVisible(
        bool bVisible
    ) {
        detail::SetBit(&mFlag, VISIBLE, bVisible);
    }

    bool IsInfluencedAlpha() const { return detail::TestBit<u8>(mFlag, INFLUENCED_ALPHA); }

    bool IsLocationAdjust() const { return detail::TestBit<u8>(mFlag, LOCATION_ADJUST); }

    bool IsUserAllocated() const { return mbUserAllocated; }

    ut::LinkList<Pane, 4>* GetChildList() { return &mChildList; }

    ut::LinkList<AnimationLink, 0>* GetAnimationList() { return &mAnimList; }

    const math::VEC3& GetTranslate() const { return mTranslate; }

    void SetTranslate(
        const nw4r::math::VEC3& value
    ) {
        mTranslate = value;
    }

    const math::MTX34& GetGlobalMtx() const { return mGlbMtx; }

    Pane* GetParent() const { return mpParent; }

    const math::VEC2& GetScale() const { return mScale; }

    void SetScale(
        const math::VEC2& value
    ) {
        mScale = value;
    }

    u8 GetAlpha() const { return mAlpha; }

    void SetAlpha(
        u8 value
    ) {
        mAlpha = value;
    }

    u8 GetGlobalAlpha() const { return mGlbAlpha; }

    const Size& GetSize() const { return mSize; }

    void SetSize(
        const Size& value
    ) {
        mSize = value;
    }

    void SetSRTElement(
        u32 idx, f32 f
    ) {
        (&mTranslate.x)[idx] = f;
    }

    const res::ExtUserDataList* GetExtUserDataList() const { return mpExtUserDataList; }

    void SetExtUserDataList(
        const res::ExtUserDataList* pBlock
    ) {
        mpExtUserDataList = pBlock;
    }

    const char* GetName() const { return mName; }

public:
    // Instance Methods
    // ^^^^^^

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C 0x800073C0 */
    NW4R_UT_RTTI_DECL(Pane);

    /* VT+0x10 0x802ABBA0 */
    virtual void CalculateMtx(const DrawInfo& drawInfo);

    /* VT+0x14 0x802ABEA0 */
    virtual void Draw(const DrawInfo& drawInfo);

    /* VT+0x18 0x802ABF30 */
    virtual void DrawSelf(const DrawInfo& drawInfo);

    /* VT+0x1C 0x802ABF40 */
    virtual void Animate(u32);

    /* VT+0x20 0x802ABFD0 */
    virtual void AnimateSelf(u32);

    /* VT+0x24 0x802AB990 */
    virtual ut::Color GetVtxColor(u32 idx) const;

    /* VT+0x28 0x802AB9A0 */
    virtual void SetVtxColor(u32, ut::Color);

    /* VT+0x2C 0x802AB9B0 */
    virtual u8 GetColorElement(u32 idx) const;

    /* VT+0x30 0x802AB9E0 */
    virtual void SetColorElement(u32 idx, u8 value);

    /* VT+0x34 0x802ABA10 */
    virtual u8 GetVtxColorElement(u32 idx) const;

    /* VT+0x38 0x802ABA20 */
    virtual void SetVtxColorElement(u32 idx, u8 value);

    /* VT+0x3C 0x802ABA30 */
    virtual Pane* FindPaneByName(const char* findName, bool bRecursive);

    /* VT+0x40 0x802ABAE0 */
    virtual Material* FindMaterialByName(const char* findName, bool bRecursive);

    /* VT+0x44 0x802AC090 */
    virtual void BindAnimation(AnimTransform* pAnimTrans, bool bRecursive, bool bDisable);

    /* VT+0x48 0x802AC0B0 */
    virtual void UnbindAnimation(AnimTransform* pAnimTrans, bool bRecusive);

    /* VT+0x4C 0x802AC140 */
    virtual void UnbindAllAnimation(bool bRecursive);

    /* VT+0x50 0x802AC160 */
    virtual void UnbindAnimationSelf(AnimTransform* pAnimTrans);

    /* VT+0x54 0x802AC200 */
    virtual AnimationLink* FindAnimationLinkSelf(AnimTransform* pAnimTrans);

    /* VT+0x58 0x802AC210 */
    virtual AnimationLink* FindAnimationLinkSelf(const AnimResource& animRes);

    /* VT+0x5C 0x802AC220 */
    virtual void SetAnimationEnable(AnimTransform* pAnimTrans, bool bEnable, bool bRecursive);

    /* VT+0x60 0x802AC320 */
    virtual void SetAnimationEnable(const AnimResource& animRes, bool bEnable, bool bRecursive);

    /* VT+0x64 0x802AC550 */
    virtual u8 GetMaterialNum() const;

    /* VT+0x68 0x802AC570 */
    virtual Material* GetMaterial() const;

    /* VT+0x6C 0x802AC580 */
    virtual Material* GetMaterial(u32 idx) const;

    /* VT+0x70 0x802AC420 */
    virtual void LoadMtx(const DrawInfo& drawInfo);

protected:
    // Instance Variables
    // ^^^^^^

    /* 0x0C */ Pane*                          mpParent;
    /* 0x10 */ ut::LinkList<Pane, 4>          mChildList;
    /* 0x1C */ ut::LinkList<AnimationLink, 0> mAnimList;
    /* 0x28 */ Material*                      mpMaterial;
    /* 0x2C */ math::VEC3                     mTranslate;
    /* 0x38 */ math::VEC3                     mRotate;
    /* 0x44 */ math::VEC2                     mScale;
    /* 0x4C */ Size                           mSize;
    /* 0x54 */ math::MTX34                    mMtx;
    /* 0x84 */ math::MTX34                    mGlbMtx;
    /* 0xB4 */ const res::ExtUserDataList*    mpExtUserDataList;
    /* 0xB8 */ u8                             mAlpha;
    /* 0xB9 */ u8                             mGlbAlpha;
    /* 0xBA */ u8                             mBasePosition;
    /* 0xBB */ u8                             mFlag;
    /* 0xBC */ char                           mName[res::PANE_NAME_SIZE + 1];
    /* 0xCD */ char                           mUserData[res::PANE_USERDATA_SIZE + 1];
    /* 0xD6 */ bool                           mbUserAllocated;
    /* 0xD7 */ u8                             mPadding;
};

}; // namespace nw4r::lyt
