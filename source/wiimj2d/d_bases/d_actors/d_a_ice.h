#pragma once

#include "d_actor_state.h"
#include "d_profile.h"
#include "s_State.h"

class daIce_c : public dActorState_c, public dProf::Info<daIce_c, dProf::ICE_ACTOR> {
    SIZE_ASSERT(0xE70);
    VTABLE(0x060, fBase_c, 0x80324320);
    // 0x80324288 g_profile_ICE_ACTOR
    // 0x8011B640 daIce_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIce_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8011EFC0 */
    bool checkPlAttach_Head(int*);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xE70);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8011F6E0
     * executeState:    0x8011F710
     * finalizeState:   0x8011F6F0
     */
    sState_Extern(0x803758F8, daIce_c, Freeze);

    /*
     * initializeState: 0x8011FD20
     * executeState:    0x8011FD40
     * finalizeState:   0x8011FD30
     */
    sState_Extern(0x80375938, daIce_c, Cover);

    /*
     * initializeState: 0x8011F770
     * executeState:    0x8011F840
     * finalizeState:   0x8011F810
     */
    sState_Extern(0x80375978, daIce_c, Hop);

    /*
     * initializeState: 0x8011FDE0
     * executeState:    0x8011FE30
     * finalizeState:   0x8011FE20
     */
    sState_Extern(0x803759B8, daIce_c, Sink);

    /*
     * initializeState: 0x80120620
     * executeState:    0x80120660
     * finalizeState:   0x80120650
     */
    sState_Extern(0x803759F8, daIce_c, PushSink);

    /*
     * initializeState: 0x8011FFD0
     * executeState:    0x80120010
     * finalizeState:   0x80120000
     */
    sState_Extern(0x80375A38, daIce_c, Float);

    /*
     * initializeState: 0x801201C0
     * executeState:    0x80120200
     * finalizeState:   0x801201F0
     */
    sState_Extern(0x80375A78, daIce_c, SmallFloat);

    /*
     * initializeState: 0x801203E0
     * executeState:    0x80120450
     * finalizeState:   0x80120440
     */
    sState_Extern(0x80375AB8, daIce_c, FloatWait);

    /*
     * initializeState: 0x80120860
     * executeState:    0x801208C0
     * finalizeState:   0x801208B0
     */
    sState_Extern(0x80375AF8, daIce_c, TogeFloat);

    /*
     * initializeState: 0x80120A50
     * executeState:    0x80120A90
     * finalizeState:   0x80120A80
     */
    sState_Extern(0x80375B38, daIce_c, ShakeFloat);

    /*
     * initializeState: 0x80120C00
     * executeState:    0x80120C80
     * finalizeState:   0x80120C60
     */
    sState_Extern(0x80375B78, daIce_c, Air);

    /*
     * initializeState: 0x80120DB0
     * executeState:    0x80120E70
     * finalizeState:   0x80120E30
     */
    sState_Extern(0x80375BB8, daIce_c, Fall);

    /*
     * initializeState: 0x8011F9B0
     * executeState:    0x8011FA10
     * finalizeState:   0x8011F9F0
     */
    sState_Extern(0x80375BF8, daIce_c, Land);

    /*
     * initializeState: 0x80121110
     * executeState:    0x801211D0
     * finalizeState:   0x801211A0
     */
    sState_Extern(0x80375C38, daIce_c, Dive);

    /*
     * initializeState: 0x80121320
     * executeState:    0x801213C0
     * finalizeState:   0x801213B0
     */
    sState_Extern(0x80375C78, daIce_c, YoganDive);

    /*
     * initializeState: 0x801214D0
     * executeState:    0x801215E0
     * finalizeState:   0x80121580
     */
    sState_Extern(0x80375CB8, daIce_c, Carry);

    /*
     * initializeState: 0x80121AD0
     * executeState:    0x80121C40
     * finalizeState:   0x80121C00
     */
    sState_Extern(0x80375CF8, daIce_c, Throw);

    /*
     * initializeState: 0x80121840
     * executeState:    0x80121900
     * finalizeState:   0x801218A0
     */
    sState_Extern(0x80375D38, daIce_c, Drop);

    /*
     * initializeState: 0x80121E90
     * executeState:    0x80121EE0
     * finalizeState:   0x80121ED0
     */
    sState_Extern(0x80375D78, daIce_c, Melt_Normal);
};
