#ifndef NW4R_G3D_CAMERA_H
#define NW4R_G3D_CAMERA_H

#include "g3d_rescommon.h"
#include <nw4r/math/types.h>
#include <rvl/MTX.h>


namespace nw4r {
namespace g3d {
struct CameraData {
    math::MTX34 mCamMtx;  // at 0x0
    math::MTX44 mProjMtx; // at 0x30
    u32 mFlags;
    math::VEC3 mPos; // at 0x74
    math::VEC3 VEC3_0x80;
    math::VEC3 VEC3_0x8C;
    math::VEC3 VEC3_0x98;
    f32 FLOAT_0xA4;
    u32 INT_0xA8;
    f32 FLOAT_0xAC;
    f32 FLOAT_0xB0;
    f32 FLOAT_0xB4;
    f32 FLOAT_0xB8;
    f32 FLOAT_0xBC;
    f32 FLOAT_0xC0;
    f32 FLOAT_0xC4;
    f32 FLOAT_0xC8;
    f32 FLOAT_0xCC;
    f32 FLOAT_0xD0;
    f32 FLOAT_0xD4;
    f32 FLOAT_0xD8;
    f32 FLOAT_0xDC;
    f32 FLOAT_0xE0;
    f32 FLOAT_0xE4;
    f32 FLOAT_0xE8;
    f32 FLOAT_0xEC;
    f32 FLOAT_0xF0;
    u32 INT_0xF4;
    u32 INT_0xF8;
    u32 INT_0xFC;
    u32 INT_0x100;
    u32 INT_0x104;
    u32 INT_0x108;
};

struct Camera {
    struct PostureInfo {
        u32 INT_0x0;
        math::VEC3 VEC3_0x04;
        math::VEC3 VEC3_0x10;
        math::VEC3 VEC3_0x1C;
        f32 FLOAT_0x28;
        // . . .
    };

    ResCommon<CameraData> mCamData;

    inline Camera(void *vptr) : mCamData(vptr) {}
    inline void UpdateProjectionMtx() const {
        CameraData &rCamData = mCamData.ref();

        if (rCamData.mFlags & 0x40) {
            C_MTXOrtho(rCamData.mProjMtx, rCamData.FLOAT_0xBC, rCamData.FLOAT_0xC0, rCamData.FLOAT_0xC4,
                    rCamData.FLOAT_0xC8, rCamData.FLOAT_0xB4, rCamData.FLOAT_0xB8);
        } else {
            if (rCamData.mFlags & 0x10) {
                C_MTXFrustum(rCamData.mProjMtx, rCamData.FLOAT_0xBC, rCamData.FLOAT_0xC0, rCamData.FLOAT_0xC4,
                        rCamData.FLOAT_0xC8, rCamData.FLOAT_0xB4, rCamData.FLOAT_0xB8);
            } else {
                C_MTXPerspective(rCamData.mProjMtx, rCamData.FLOAT_0xAC, rCamData.FLOAT_0xB0, rCamData.FLOAT_0xB4,
                        rCamData.FLOAT_0xB8);
            }
        }

        rCamData.mFlags |= 0x80;
    }

    Camera(CameraData *);
    void Init();
    void Init(u16, u16, u16, u16, u16, u16);
    void SetPosition(f32, f32, f32);
    void SetPosition(const math::VEC3 &);
    void SetPosture(const PostureInfo &);
    void SetCameraMtxDirectly(const math::MTX34 &);
    void SetPerspective(f32, f32, f32, f32);
    void SetOrtho(f32, f32, f32, f32, f32, f32);
    void SetProjectionMtxDirectly(const math::MTX44 *);
    void SetScissor(u32, u32, u32, u32);
    void SetScissorBoxOffset(s32, s32);
    void SetViewport(f32, f32, f32, f32);
    void SetViewportZRange(f32, f32);
    void GetViewport(f32 *, f32 *, f32 *, f32 *, f32 *, f32 *) const;
    void GetCameraMtx(math::MTX34 *) const;
    void GetProjectionMtx(math::MTX44 *) const;
    void GetProjectionTexMtx(math::MTX34 *) const;
    void GetEnvironmentTexMtx(math::MTX34 *) const;
    void GXSetViewport() const;
    void GXSetProjection() const;
    void GXSetScissor() const;
    void GXSetScissorBoxOffset() const;
    void UpdateCameraMtx() const;
};
} // namespace g3d
} // namespace nw4r

#endif
