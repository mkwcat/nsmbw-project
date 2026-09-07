#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFlagObj_c : public dActorState_c {
    SIZE_ASSERT(0x3F8);
    VTABLE(0x060, fBase_c, 0x80959EB0);

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFlagObj_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807EB470
     * executeState:    0x807EB490
     * finalizeState:   0x807EB480
     */
    sState_Extern(0x80998468, daFlagObj_c, NonMove);

    /*
     * initializeState: 0x807EB4A0
     * executeState:    0x807EB4C0
     * finalizeState:   0x807EB4B0
     */
    sState_Extern(0x809984A8, daFlagObj_c, Swich4andMove);

    /*
     * initializeState: 0x807EB630
     * executeState:    0x807EB650
     * finalizeState:   0x807EB640
     */
    sState_Extern(0x809984E8, daFlagObj_c, Swich4orMove);

    /*
     * initializeState: 0x807EB7C0
     * executeState:    0x807EB7E0
     * finalizeState:   0x807EB7D0
     */
    sState_Extern(0x80998528, daFlagObj_c, RandSwichMove);

    /*
     * initializeState: 0x807EB980
     * executeState:    0x807EB9A0
     * finalizeState:   0x807EB990
     */
    sState_Extern(0x80998568, daFlagObj_c, ChngeSwichMove);

    /*
     * initializeState: 0x807EBCA0
     * executeState:    0x807EBCC0
     * finalizeState:   0x807EBCB0
     */
    sState_Extern(0x809985A8, daFlagObj_c, IfSwichMove);

    /*
     * initializeState: 0x807EC150
     * executeState:    0x807EC170
     * finalizeState:   0x807EC160
     */
    sState_Extern(0x809985E8, daFlagObj_c, RenzokuOnMove);
};

class daFlagOn_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959E58 g_profile_AC_FLAGON
    // 0x807EAB70 daFlagOn_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFlagOn_c() {}
};

class da4SwichAnd_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959E64 g_profile_AC_4SWICHAND
    // 0x807EABC0 da4SwichAnd_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    da4SwichAnd_c();
};

class da4SwichOr_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959E70 g_profile_AC_4SWICHOR
    // 0x807EAC10 da4SwichOr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    da4SwichOr_c() {}
};

class daRandSwich_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959E7C g_profile_AC_RANDSWICH
    // 0x807EAC60 daRandSwich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRandSwich_c() {}
};

class daChngeSwich_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959E88 g_profile_AC_CHNGESWICH
    // 0x807EACB0 daChngeSwich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daChngeSwich_c() {}
};

class daIfSwich_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959E94 g_profile_AC_IFSWICH
    // 0x807EAD00 daIfSwich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIfSwich_c() {}
};

class daRnSwich_c : public daFlagObj_c {
    SIZE_ASSERT(0x3F8);
    // 0x80959EA0 g_profile_AC_RNSWICH
    // 0x807EAD50 daRnSwich_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRnSwich_c() {}
};
