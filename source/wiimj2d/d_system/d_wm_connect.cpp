// d_wm_connect.cpp
// NSMBW .text: 0x800F2C00 - 0x800F3570

#include "d_wm_connect.h"

[[nsmbw(0x800F2C00)]]
void dWmConnect_c::dPnt_c::SetInfo(const char*, nw4r::math::VEC3&, int);

[[nsmbw(0x800F2C70)]]
void dWmConnect_c::dPnt_c::init();

[[nsmbw(0x800F2CD0)]]
void dWmConnect_c::SetInfo(dCsvData_c&, const m3d::mdl_c&);

[[nsmbw(0x800F2E50)]]
void dWmConnect_c::initialize(dCsvData_c&, const m3d::mdl_c&);

[[nsmbw(0x800F2F00)]]
void dWmConnect_c::calcConnect(dCsvData_c&);

[[nsmbw(0x800F2FC0)]]
dWmLib::PointNo dWmConnect_c::GetPointNo(const char* name);

[[nsmbw(0x800F3030)]]
void dWmConnect_c::__connect(dWmLib::PointNo from, dWmLib::PointNo to);

[[nsmbw(0x800F31D0)]]
void dWmConnect_c::initAnimation(dCsvData_c&);

[[nsmbw(0x800F32A0)]]
void dWmConnect_c::SetCourseNo(dWmLib::CourseNo);

[[nsmbw(0x800F32F0)]]
dWmLib::CourseNo dWmConnect_c::GetCourseNoFromName(const char* name);

[[nsmbw(0x800F3380)]]
dWmConnect_c::dPnt_c* dWmConnect_c::GetConnect(const char* name, dWmLib::DirNo direction);

dWmConnect_c::dPnt_c* dWmConnect_c::GetConnect(
    const char* name
) {
    if (dWmLib::PointNo pointNo = GetPointNo(name); pointNo >= 0) {
        return &mPoint[pointNo];
    }
    return nullptr;
}

dWmConnect_c::dPnt_c* dWmConnect_c::GetConnectFromCourseNo(
    dWmLib::CourseNo course
) {
    for (std::size_t pnt = 0; pnt < std::size(mPoint); pnt++) {
        if (mPoint[pnt].mCourseNo == course) {
            return &mPoint[pnt];
        }
    }
    return nullptr;
}

[[nsmbw(0x800F3400)]]
dWmConnect_c::dPnt_c* dWmConnect_c::GetPointFromIndex(int index);

[[nsmbw(0x800F3440)]]
dWmLib::DirNo dWmConnect_c::GetDir(dWmLib::PointNo from, dWmLib::PointNo to);

[[nsmbw(0x800F34D0)]]
void dWmConnect_c::dPnt_c::GetLink(dWmLib::DirNo direction);
