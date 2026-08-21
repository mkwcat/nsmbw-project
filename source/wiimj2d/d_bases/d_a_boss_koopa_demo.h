#pragma once

#include "d_static/d_actor/d_a_boss_demo.h"
#include "d_static/d_ef/d_ef.h"
#include "d_static/d_util.h"
#include <nw4r/ut/Color.h>

class daBossKoopaDemo_c : public daBossDemo_c {
    SIZE_ASSERT(0x9CE8);
    VTABLE(0x0000, fBase_c, 0x80954A90);

public:
    // Static Methods
    // ++++++

    static constexpr float getWalkTargetX(int index);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03DC, 0x03E0);

    /* 0x03E0 */ int m0x03E0;

    FILL(0x03E4, 0x99E4);

    /* 0x99E4 */ dEf::followEffect_c m_followEffect[1];
    /* 0x9AF8 */ dEf::dLevelEffect_c m_levelEffect[1];
    /* 0x9C20 */ Util::dDisp_c       m_utilDisp;

    /* 0x9C2C */ float               m_curSizeY;
    /* 0x9C30 */ float               m_targetSizeY;
    /* 0x9C34 */ float               m_curBaseX;
    /* 0x9C38 */ float               m_targetBaseX;
    /* 0x9C2C */ float               m_curSizeX;
    /* 0x9C30 */ float               m_targetSizeX;
    /* 0x9C44 */ float               m_curBaseY;
    /* 0x9C48 */ float               m_targetBaseY;

    FILL(0x9C4C, 0x9C54);

    /* 0x9C54 */ nw4r::ut::Color m_color[8];
    /* 0x9C74 */ float           m0x9C74[5];

    FILL(0x9C88, 0x9CC4);

    /* 0x9CC4 */ float m0x9CC4;
    /* 0x9CC8 */ float m0x9CC8;
    /* 0x9CCC */ u32   m0x9CCC;
    /* 0x9CD0 */ int   m0x9CD0;
    /* 0x9CD4 */ int   m0x9CD4[4];
    /* 0x9CE4 */ bool  m0x9CE4;

    FILL(0x9CE5, 0x9CE8);

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x0E0 0x807CB350
     * executeState:    VT+0x0E4 0x807CB3D0
     * finalizeState:   VT+0x0E8 0x807CBC20
     */
    sState_ExternVirtual(0x80996C1C, daBossKoopaDemo_c, Ready);

    /**
     * initializeState: VT+0x13C 0x807CBC30
     * executeState:    VT+0x140 0x807CBCF0
     * finalizeState:   VT+0x144 0x807CBF30
     */
    sState_ExternVirtual(0x80996C5C, daBossKoopaDemo_c, Start);

    /**
     * initializeState: VT+0x148 0x807CBF40
     * executeState:    VT+0x14C 0x807CBFA0
     * finalizeState:   VT+0x150 0x807CC3D0
     */
    sState_ExternVirtual(0x80996C9C, daBossKoopaDemo_c, Battle);

    /**
     * initializeState: VT+0x154 0x807CC3E0
     * executeState:    VT+0x158 0x807CC710
     * finalizeState:   VT+0x15C 0x807CCE00
     */
    sState_ExternVirtual(0x80996CDC, daBossKoopaDemo_c, Fall);

    /**
     * initializeState: VT+0x160 0x807CCE10
     * executeState:    VT+0x164 0x807CCF90
     * finalizeState:   VT+0x168 0x807CD940
     */
    sState_ExternVirtual(0x80996D1C, daBossKoopaDemo_c, Magic);

    /**
     * initializeState: VT+0x16C 0x807CD950
     * executeState:    VT+0x170 0x807CD9D0
     * finalizeState:   VT+0x174 0x807CE520
     */
    sState_ExternVirtual(0x80996D5C, daBossKoopaDemo_c, Escape);

    /**
     * initializeState: VT+0x178 0x807CE530
     * executeState:    VT+0x17C 0x807CE6F0
     * finalizeState:   VT+0x180 0x807CF460
     */
    sState_ExternVirtual(0x80996D9C, daBossKoopaDemo_c, End);
};
