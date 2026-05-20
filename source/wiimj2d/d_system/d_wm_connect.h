#pragma once

#include "d_system/d_wm_lib.h"
#include <nw4r/math/vec.h>

class dCsvData_c;

namespace m3d {
class mdl_c;
}

class dWmConnect_c {
    SIZE_ASSERT(0x3F08);

    // Structors, vtable emitted inline in d_a_wm_Map.cpp
    VTABLE(0x00, dWmConnect_c, 0x80984998);

public:
    // Constants
    // ^^^^^^

    static constexpr int MAX_POINTS = 192;

public:
    // Nested Types
    // ^^^^^^

    class dPnt_c {
        friend class dWmConnect_c;

        SIZE_ASSERT(0x54);
        // Structors, vtable emitted inline in d_a_wm_Map.cpp
        VTABLE(0x00, dPnt_c, 0x809849A4);

    public:
        // Structors
        // ^^^^^^

        /* 0x808DEEE0 */
        dPnt_c();

        /* VT+0x8 0x808DEEF0 */
        virtual ~dPnt_c();

    public:
        // Instance Methods
        // ^^^^^^

        /* 0x800F2C00 */
        void SetInfo(const char* name, nw4r::math::VEC3& pos, int index);

        /* 0x800F34D0 */
        void GetLink(dWmLib::DirNo direction);

    public:
        // Instance Inline Methods
        // ++++++

        int GetIndex() const { return mIndex; }

    private:
        /* 0x800F2C70 */
        void init();

    private:
        // Instance Variables
        // ^^^^^^

        /* 0x00 */ char             mName[5];
        /* 0x08 */ nw4r::math::VEC3 mPos;
        /* 0x14 */ dPnt_c*          mLink[dWmLib::DIR_COUNT];
        /* 0x30 */ int              mActionLabel[dWmLib::DIR_COUNT];
        /* 0x48 */ dWmLib::CourseNo mCourseNo;
        /* 0x4C */ int              mIndex;
        /* 0x50 */ int              mNoCourseData; // ?
    };

public:
    // Structors
    // ^^^^^^

    /* 0x808DEE80 */
    dWmConnect_c();

    /* VT+0x8 0x808DEF30 */
    virtual ~dWmConnect_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800F2CD0 */
    void SetInfo(dCsvData_c&, const m3d::mdl_c&);

    /* 0x800F2FC0 */
    dWmLib::PointNo GetPointNo(const char* name);

    /* 0x800F32A0 */
    void SetCourseNo(dWmLib::CourseNo);

    /* 0x800F32F0 */
    dWmLib::CourseNo GetCourseNoFromName(const char* name);

    /* 0x800F3380 */
    dPnt_c* GetConnect(const char* name, dWmLib::DirNo direction);

    /* 0x800F3400 */
    dPnt_c* GetPointFromIndex(int index);

    /* 0x800F3440 */
    dWmLib::DirNo GetDir(dWmLib::PointNo from, dWmLib::PointNo to);

private:
    /* 0x800F2E50 */
    void initialize(dCsvData_c&, const m3d::mdl_c&);

    /* 0x800F2F00 */
    void calcConnect(dCsvData_c&);

    /* 0x800F31D0 */
    void initAnimation(dCsvData_c&);

    /* 0x800F3030 */
    void __connect(dWmLib::PointNo from, dWmLib::PointNo to);

public:
    // Instance Methods
    // ++++++

    dPnt_c* GetConnect(const char* name);

    dPnt_c* GetConnectFromCourseNo(dWmLib::CourseNo course);

private:
    // Instance Variables
    // ^^^^^^

    /* 0x0004 */ dPnt_c          mPoint[MAX_POINTS];
    /* 0x3F04 */ dWmLib::WorldNo mWorldNo;
};
