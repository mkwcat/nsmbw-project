#pragma once

typedef struct _GXRenderModeObj GXRenderModeObj;

namespace EGG {

class Video {
public:
    struct RenderModeObjSet {};

    Video(
        GXRenderModeObj* renderMode, const RenderModeObjSet* rmSet
    )
        : pRenderMode(nullptr)
        , mFlag(0)
        , m0x08(0) {
        initialize(renderMode, rmSet);
    }

    [[mkw(0x80243D18)]] void initialize(GXRenderModeObj* renderMode, const RenderModeObjSet* rmSet);

    bool isBlack() { return mFlag & 1; }

    static u32 getTickPerVRetrace();
    static u32 getTickPerVRetrace(u32 v);

    const GXRenderModeObj* pRenderMode;
    u8                     mFlag;
    u32                    m0x08;
};

} // namespace EGG
