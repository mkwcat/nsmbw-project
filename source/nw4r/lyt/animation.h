#pragma once

#include <nw4r/ut/LinkList.h>

namespace nw4r::lyt {

class ResourceAccessor;
class Pane;
class Material;

namespace res {
class AnimationBlock;
}

class AnimTransform {
public:
    AnimTransform();

    [[mkw(0x800829D0)]] u16 GetFrameSize() const;
    bool IsLoopData() const;
    virtual ~AnimTransform()                                                                  = 0;
    virtual void SetResource(const res::AnimationBlock* pRes, ResourceAccessor* pResAccessor) = 0;
    virtual void
    SetResource(const res::AnimationBlock* pRes, ResourceAccessor* pResAccessor, u16 animNum) = 0;
    virtual void Bind(Pane* pPane, bool bRecursive, bool bDisable)                            = 0;
    virtual void Bind(Material* pMaterial, bool bDisable)                                     = 0;
    virtual void Animate(u32 idx, Pane* pPane)                                                = 0;
    virtual void Animate(u32 idx, Material* pMaterial)                                        = 0;

    f32 GetFrameMax() const {
        return mFrame; // TOOD
    }

    const res::AnimationBlock* GetAnimResource() const { return mpRes; }

    f32 GetFrame() const { return mFrame; }

    void SetFrame(
        f32 frame
    ) {
        mFrame = frame;
    }

    /* 0x04 */ ut::LinkListNode mLink;

protected:
    /* 0x0C */ const res::AnimationBlock* mpRes;
    /* 0x10 */ f32                        mFrame;
};

} // namespace nw4r::lyt
